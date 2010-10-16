/***********************license start***************
 * Copyright (c) 2003-2010  Cavium Networks (support@cavium.com). All rights
 * reserved.
 *
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.

 *   * Neither the name of Cavium Networks nor the names of
 *     its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written
 *     permission.

 * This Software, including technical data, may be subject to U.S. export  control
 * laws, including the U.S. Export Administration Act and its  associated
 * regulations, and may be subject to export or import  regulations in other
 * countries.

 * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
 * AND WITH ALL FAULTS AND CAVIUM  NETWORKS MAKES NO PROMISES, REPRESENTATIONS OR
 * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO
 * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR
 * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM
 * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,
 * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF
 * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR
 * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR
 * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.
 ***********************license end**************************************/


/*
 * File version info: $Id: traffic-gen.c 50044 2010-06-14 17:25:18Z kreese $
 *
 */

#include <bdk.h>
#include <stdio.h>
#include <ctype.h>
#include <malloc.h>

#define CACHE_LINE_ALIGN __attribute__ ((aligned(128)))
#define CYCLE_SHIFT         12
#define ETHERNET_CRC        4       /* Gigabit ethernet CRC in bytes */
#define ULL                 unsigned long long
#define LL                  long long
#define BRIDGE_OFF          40
#define PIP_IP_OFFSET       4       /* Number of dwords to reserve before IP packets */

#define MAX_INSERT 8

#define GOTO_TOP  "\033[1;1H"   /* ESC[1;1H begins output at the top of the terminal (line 1) */
#define GOTO_BOTTOM "\033[100;1H"   /* ESC[1;1H begins output at the bottom of the terminal (actually line 100) */
#define GOTO_BOL  "\033[100D"   /* Go to beginning of line */
#define ERASE_EOL "\033[0K"     /* Erase to end of line */
#define ERASE_EOS "\033[0J"     /* Erase to end screen */
#define ERASE_WIN "\033[2J"     /* Erase the window */
#define REVERSE   "\033[7m"     /* Reverse the display */
#define NORMAL    "\033[0m"     /* Normal display */
#define NONZEROHI "\033[33m"    /* Yellow used for non zero rows */
#define ZEROHI    "\033[32m"    /* Green used for zero rows */
#define SCROLL_FULL "\033[1;r"  /* Normal full-screen scrolling for statistics region */
#define SET_SCROLL_REGION(row) printf("\033[%d;r",row)   /* for command region */
#define CURSOR_ON  "\033[?25h"  /* Turn on cursor */
#define CURSOR_OFF "\033[?25l"  /* Turn off cursor */
#define GOTO_BOTTOM_x "\033[100;%dH" /* go to the bottom of the screen and posion x (supply to printf) */

#define ARP_REQUEST       0x1
#define ARP_REPLY         0x2

#define MAC_ADDR_LEN 6
#define IP_ADDR_LEN 4

struct arp_t /* assumes IPv4 */
{
   uint16_t hw_type;
   uint16_t proto;
   uint8_t  hw_addr_len;
   uint8_t  proto_addr_len;
   uint16_t opcode;
   uint8_t  src_mac[6];
   uint8_t  src_ip[4];
   uint8_t  dest_mac[6];
   uint8_t  dest_ip[4];
};


typedef struct
{
    bdk_pip_port_status_t  input_statistics;
    uint64_t                input_cumulative_packets;
    uint64_t                input_cumulative_octets;
    uint64_t                input_cumulative_errors;
    uint64_t                backpressure;
    uint64_t                input_percent; /* Actually percent*10 */
    uint64_t                input_Mbps;
    int64_t                 input_arp_requests;
    int64_t                 input_arp_replies;
    bdk_pko_port_status_t  output_statistics;
    bdk_pko_port_status_t  output_statistics_old;
    uint64_t                output_cumulative_packets;
    uint64_t                output_cumulative_octets;
    uint64_t                output_percent; /* Actually percent*10 */
    uint64_t                output_Mbps;
    int64_t                 output_arp_requests;
    int64_t                 output_arp_replies;
    bdk_helper_interface_mode_t imode;
    int                     display;
    uint64_t                link_state;
    int64_t                 input_validation_errors;
    int32_t                 wqe_receive_errors[256];
} port_state_t;

typedef enum {
    PACKET_FREE,
    PACKET_DONT_FREE,
    PACKET_DONT_FREE_WQE
} packet_free_t;

typedef enum {
    PACKET_TYPE_IPV4_UDP,
    PACKET_TYPE_IPV6_UDP,
    PACKET_TYPE_IPV4_TCP,
    PACKET_TYPE_IPV6_TCP,
    PACKET_TYPE_802_3_PAUSE,
    PACKET_TYPE_CBFC_PAUSE,
    PACKET_TYPE_CJPAT,
    PACKET_TYPE_HELP    /* best to keep this last */
} packet_type_t;

char *tx_packet_type_lut[] = {
    "IPv4+UDP",
    "IPv6+UDP",
    "IPv4+TCP",
    "IPv6+TCP",
    "pause-8023",
    "pause-CBFC",
    "cjpat",
    "help",     /* best to keep this last */
    0
};

typedef enum {
    DATA_TYPE_ABC=0,
    DATA_TYPE_ZERO,
    DATA_TYPE_ONE,
    DATA_TYPE_INC,
    DATA_TYPE_DEC,
    DATA_TYPE_RAND,
    DATA_TYPE_HELP      /* best to keep this last */
} payload_t;

char *tx_payload_lut[] = {
    "abc",
    "zero",
    "one",
    "inc",
    "dec",
    "rand",
    "help",     /* best to keep this last */
    0
};

char *row_lut[] = {
    "min",
    "on",
    "off",
    0
};

char *on_off_lut[] = {
    "off",
    "on",
    0
};

char *on_off_show_lut[] = {
    "off",
    "on",
    "show",
    0
};

char *on_off_error_lut[] = {
    "off",
    "on",
    "error",
    0
};

char *port_off_lut[] = {
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "10",
    "11",
    "12",
    "13",
    "14",
    "15",
    "16",
    "17",
    "18",
    "19",
    "20",
    "21",
    "22",
    "23",
    "24",
    "25",
    "26",
    "27",
    "28",
    "29",
    "30",
    "31",
    "32",
    "33",
    "34",
    "35",
    "36",
    "37",
    "38",
    "39",
    "off",
    0
};

char *loopback_lut[] = {
    "off",
    "internal",
    "external",
    "internal+external",
    0
};


char *function_key_commands[] = {
    "F1",       /* F1 */
    "F2",       /* F2 */
    "F3",       /* F3 */
    "F4",       /* F4 */
    "F5",       /* F5 */
    "F6",       /* F6 */
    "F7",       /* F7 */
    "F8",       /* F8 */
    "F9",       /* F9 */
    "F10",      /* F10 */
    "",         /* N/A */
    "F11",      /* F11 */
    "F12",      /* F12 */
    "Shift-F1", /* Shift-F1 */
    "Shift-F2", /* Shift-F2 */
    "",         /* N/A */
    "Shift-F3", /* Shift-F3 */
    "Shift-F4", /* Shift-F4 */
    "",         /* N/A */
    "Shift-F5", /* Shift-F5 */
    "Shift-F6", /* Shift-F6 */
    "Shift-F7", /* Shift-F7 */
    "Shift-F8", /* Shift-F8 */
    0
};

char **numeric = NULL;  /* for displaying numeric types in PRINTTRANS */
char **numeric_signed = (char**)-1;  /* for displaying signed numeric types in PRINTTRANS */

typedef struct {
    char *command;
    char **lut;
} secondary_lut_lut_t;

secondary_lut_lut_t secondary_lut_lut[] = {
    {"tx.type ", tx_packet_type_lut},
    {"tx.payload ", tx_payload_lut},
    {"row", row_lut},
    {"hli", on_off_lut},
    {"freeze", on_off_lut},
    {"tx.arp.reply", on_off_show_lut},
    {"rx.arp.reply", on_off_show_lut},
    {"rx.arp.request", on_off_show_lut},
    {"alias", function_key_commands},
    {"unalias", function_key_commands},
    {"tx.checksum", on_off_show_lut},
    {"rx.display", on_off_error_lut},
    {"validate", on_off_show_lut},
    {"loopback", loopback_lut},
    {"backpressure", on_off_lut},
    {"packetio", on_off_lut},
    {0,0}
};

#define MAX_ALIAS_NAME 31
#define MAX_ALIAS_COMMAND (255-32)
#define MAX_ALIAS 256

typedef struct {
    char name[MAX_ALIAS_NAME+1];
    char command[MAX_ALIAS_COMMAND+1];
} alias_t;

int num_aliases=9;

alias_t alias[MAX_ALIAS] = {
    {"F1","help"},
    {"F5","type tx.count "},
    {"F6","type tx.rate "},
    {"F9","echo <starting all>;start all"},
    {"F10","echo <stopping all>;stop all"},
    {"F11","echo <starting default>;start"},
    {"F12","echo <stopping default>;stop"},
    {"PageUp","echo <clearing all>;clearall"},
    {"PageDown","echo <clearing default>;clear"},
};

/* NOTE:  This array is used for command completion!!! */
char *help_commands[] = {
    "default [<first port> [<last port>]]      Set or display the default port range\n",
    "start [<port range>] | all                Start transmitting on these ports\n",
    "stop [<port range>] | all                 Stop transmitting on these ports\n",
    "show [<port range>] | all                 Display the statistics for these ports (i.e. show columns)\n",
    "hide [<port range>] | all                 Hide the statisitcs for these ports (i.e. hide columns)\n",
    "clear [<port range>] | all                Clear statistics counters for these ports\n",
    "clearall                                  Clear statistics counters for all ports\n",
    "reset [<port range>] | all                Reset ports to traffic-gen startup defaults\n",
    "tx.size [[<port range>] <size>]           Size of the packet transmitted, excluding the frame CRC (60..65524)\n",
    "tx.percent [[<port range>] <%>]           Set transmit rate as a % of gigabit\n",
    "tx.rate [[<port range] <packets/s>]       Set transmit rate in packets per second\n",
    "tx.count [[<port range>] <number>]        Automatically stop after this many packets\n",
    "tx.data[<index>] [[<port range>] <data>]  Set or read the data in the packet in 64bit words, index=0..size/8\n",
    "tx.payload [<port range> [<type> | help]] Set the data type for the payload (help to see choices)\n",
    "tx.type [<port range> [<type> | help]]    Set the type for the packet (help to see choices)\n",
    "tx.checksum [<port range>] [on|off|show]  Turn on/off UDP payload checksum\n",
    "csr address [<new value>]                 Read or write a CSR by exact address\n",
    "row [<first row> [<last row>]] [on|off|min]  Toggle or set the row range on or off or to min\n",
    "hli [<first row> [<last row>]] [on|off]   Toggle or set highlighting of a row range on or off\n",
    "freeze [on|off]                           Toggle or set the display updates on or off\n",
    "history [<first line> [<last line>]]      Show a command history range\n",
    "debug [<value>]                           Set or show the debug value\n",
    "cls                                       Clear the screen\n",
    "reboot                                    Reboot the Octeon\n",
    "mii.read <dev> <reg>                      Read from the MDIO bus, device <dev>, register <reg> (bit 7 in dev specifies MDIO bus)\n",
    "mii.write <dev> <mmd> <reg> <value>       Write to the MDIO bus, device <dev>, register <reg> (bit 7 in dev specifies MDIO bus)\n",
    "mii45.read <dev> <mmd> <reg>              Read from the MDIO bus (clause 45), device <dev>, mmd <mmd>, register <reg> (bit 7 in dev specifies MDIO bus)\n",
    "mii45.write <dev> <mmd> <reg> <value>     Write to the MDIO bus (clause 45), device <dev>, mmd <mmd>, register <reg>, value <val> (bit 7 in dev specifies MDIO bus)\n",
    "phy.speed [[<port range>] [auto] [full/half] [10/100/1000] [pause/nopause]]    Program the PHY negotiation speed and options\n",
    "src.mac [[<port range>] <address>]        Set or show the source MAC address. Set using xx:xx:xx:xx:xx:xx.\n",
    "src.mac.inc [[<port range>] <increment>]  Set or show the source MAC address increment\n",
    "src.mac.min [[<port range>] <address>]    Set or show the source MAC minimum. Once the address reaches this value it will wrap to max\n",
    "src.mac.max [[<port range>] <address>]    Set or show the source MAC maximum. Once the address reaches this value it will wrap to min\n",
    "dest.mac [[<port range>] <address>]       Set or show the destination MAC address. Set using xx:xx:xx:xx:xx:xx.\n",
    "dest.mac.inc [[<port range>] <increment>]  Set or show the destination MAC address increment\n",
    "dest.mac.min [[<port range>] <address>]    Set or show the destination MAC minimum. Once the address reaches this value it will wrap to max\n",
    "dest.mac.max [[<port range>] <address>]    Set or show the destination MAC maximum. Once the address reaches this value it will wrap to min\n",
    "tx.vlan [[<port range>] <vlan bytes>|off] Set or show the bytes to be inserted into the L2 header--eg. use '81000ffd' for VLAN 4093.\n",
    "src.ip [[<port range>] <address>]         Set or show the source IP address. Set using xxx.xxx.xxx.xxx.\n",
    "src.ip.inc [[<port range>] <increment>]   Set or show the source IP address increment\n",
    "src.ip.min [[<port range>] <L4 ip>]       Set or show the source IP address minimum. Once the IP reaches this value it will wrap to max\n",
    "src.ip.max [[<port range>] <L4 ip>]       Set or show the source IP address maximum. Once the IP reaches this value it will wrap to min\n",
    "dest.ip [[<port range>] <address>]        Set or show the destination IP address. Set using xxx.xxx.xxx.xxx.\n",
    "dest.ip.inc [[<port range>] <increment>]  Set or show the destination IP address increment\n",
    "dest.ip.min [[<port range>] <L4 ip>]      Set or show the destination IP address minimum. Once the IP reaches this value it will wrap to max\n",
    "dest.ip.max [[<port range>] <L4 ip>]      Set or show the destination IP address maximum. Once the IP reaches this value it will wrap to min\n",
    "ip.tos [[<port range>] <value>]           Set or show the IP TOS field.\n",
    "src.port [[<port range>] <L4 port>]       Set or show the source UDP(L4) port\n",
    "src.port.inc [[<port range>] <increment>] Set or show the source UDP(L4) port increment\n",
    "src.port.min [[<port range>] <L4 port>]   Set or show the source UDP(L4) port minimum. Once the port reaches this value it will wrap to max\n",
    "src.port.max [[<port range>] <L4 port>]   Set or show the source UDP(L4) port maximum. Once the port reaches this value it will wrap to min\n",
    "dest.port [[<port range>] <L4 port>]      Set or show the destination UDP(L4) port\n",
    "dest.port.inc [[<port range>] <inc>]      Set or show the destination UDP(L4) port increment\n",
    "dest.port.min [[<port range>] <L4 port>]  Set or show the destination UDP(L4) port minimum. Once the port reaches this value it will wrap to max\n",
    "dest.port.max [[<port range>] <L4 port>]  Set or show the destination UDP(L4) port maximum. Once the port reaches this value it will wrap to min\n",
    "arp.request <port> <ip address>           Send an ARP request to <ip address> on <port>\n",
    "tx.arp.reply [<port range>] [on|off|show] Controls sending of ARP replies when receiving ARP reqests with matching IP addr\n",
    "rx.arp.request [<port range>] [on|off|show] Controls setting of dest MAC address when receiving ARP requests\n",
    "rx.arp.reply [<port range>] [on|off|show] Controls setting of dest MAC address when receiving ARP replies\n",
    "find.max [<tx port> <rx port>|default]    Perform a binary search to find the max TX rate where all packets are received\n",
    "scan.sizes <tx port> <rx port>|default [min_size [max_size [size_increment [count]]]]   Send count (default 100) packets at each size from min (default 60) to max (default 65524) bytes, stopping if any bytes are lost\n",
    "bridge [[<port range>] <port>|off]        Bridge incomming packets for a port out another port\n",
    "rx.packets [<port range>] | all           Show RX packets for a range of ports\n",
    "rx.octets [<port range>] | all            Show RX octets for a range of ports\n",
    "rx.mbps [<port range>] | all              Show RX Mbps for a range of ports\n",
    "rx.total_packets [<port range>] | all     Show total RX packets for a range of ports\n",
    "rx.total_octets [<port range>] | all      Show total RX octets for a range of ports\n",
    "rx.total_errors [<port range>] | all      Show total RX errors for a range of ports\n",
    "rx.validation_errors [<port range>] | all Show total validation errors for a range of ports\n",
    "rx.promisc [<port range>] [on|off|show]   Set promiscuous mode for port. (on by default)\n",
    "rx.display [<port range>] [on|off|error]  Control display of received packets. off=none, on=all, error=only error packets\n",
    "tx.packets [<port range>] | all           Show TX packets for a range of ports\n",
    "tx.octets [<port range>] | all            Show TX octets for a range of ports\n",
    "tx.mbps [<port range>] | all              Show TX Mbps for a range of ports\n",
    "tx.total_packets [<port range>] | all     Show total TX packets for a range of ports\n",
    "tx.total_octets [<port range>] | all      Show total TX octets for a range of ports\n",
    "higig [[<port range>] <header size>]      Size of HiGig header to prepend to the packets. Must be 0, 12, or 16\n",
    "validate [<port range>] [on|off|show]     Turn on/off of packet validation using CRC32C.\n",
    "loopback [<port range>] [off|internal|external|internal&external] Control the loopback state of a port.\n",
    "backpressure [<port range>] [on|off]      Set if incomming backpressure packets should slow down transmit\n",
    "packetio on | off                         Start or stop all packet IO hardware. Warning, debug use only\n",
    "ixf.read <reg_addr>                       Read 16 bit register from IXF18201 (EBT5810 board only)\n",
    "ixf.write <reg_addr> <value>              Write 16 bit register from IXF18201 (EBT5810 board only)\n",
    "ixf.read32 <reg_addr>                     Read 32 bit register from IXF18201 (EBT5810 board only)\n",
    "ixf.write32 <reg_addr> <value>            Write 32 bit register from IXF18201 (EBT5810 board only)\n",
    "ixf.miiread <dev> <mmd> <reg>             MII clause 45 read using IXF18201 (EBT5810 board only)\n",
    "ixf.miiwrite <dev> <mmd> <reg> <value>    MII clause 45 read using IXF18201 (EBT5810 board only)\n",
    "editing                                   Show help for editing\n",
    "alias [<prefix>] | <[name> <command>      Show or set an alias for a name or function key (F1..F12, Shift-F1..Shift-F8)\n",
    "unalias <name>                            Remove alias <name>.\n" /* NOTE: comma intentionally missing before Pause/Break */
    "<Pause/Break key>                         Toggle transmit on/off for default ports (if only using default ports).\n" /*same*/
    "<Function Keys>/<Shift-Function Keys>     Can be mapped to various functions (see alias).\n",
    "echo <message>                            Print <message>.\n",
    "type <text>                               Assume <text> was typed, useful for function key mapping.\n",
    "help [<prefix>] [<lines>]                 Show help for commands starting with <prefix> in pages of <lines>\n",
    0
};

  /* Define the output packet contents following IEEE 802.3ae Clause 45
   * definition for the continous jitter test pattern (CJPAT). Since the OCTEON
   * automatically generates some portions of the specified pattern, the packet
   * does not include the first 8 bytes and the last 12 bytes of the pattern.
   */
const char CJPAT_Packet[1508] = {
						 // Packet Start, 1st data bytes
	                                         // Byte  Starting
	                                         // Time  Offset
	                                         // ----  --------
  0x0B, 0x7E, 0x7E, 0x7E,			 // 000
  0x7E, 0x7E, 0x7E, 0x7E,                        // 001

                                                 // Low-Density transitions
  0x7E, 0x7E, 0x7E, 0x7E,                        // 002   000
  0x7E, 0x7E, 0x7E, 0x7E,                        // 003   004
  0x7E, 0x7E, 0x7E, 0x7E,                        // 004   008
  0x7E, 0x7E, 0x7E, 0x7E,                        // 005   012
  0x7E, 0x7E, 0x7E, 0x7E,                        // 006   016
  0x7E, 0x7E, 0x7E, 0x7E,                        // 007   020
  0x7E, 0x7E, 0x7E, 0x7E,                        // 008   024
  0x7E, 0x7E, 0x7E, 0x7E,                        // 009   028
  0x7E, 0x7E, 0x7E, 0x7E,                        // 010   032
  0x7E, 0x7E, 0x7E, 0x7E,                        // 011   036
  0x7E, 0x7E, 0x7E, 0x7E,                        // 012   040
  0x7E, 0x7E, 0x7E, 0x7E,                        // 013   044
  0x7E, 0x7E, 0x7E, 0x7E,                        // 014   048
  0x7E, 0x7E, 0x7E, 0x7E,                        // 015   052
  0x7E, 0x7E, 0x7E, 0x7E,                        // 016   056
  0x7E, 0x7E, 0x7E, 0x7E,                        // 017   060..063

  0x7E, 0x7E, 0x7E, 0x7E,                        // 018   064
  0x7E, 0x7E, 0x7E, 0x7E,                        // 019   068
  0x7E, 0x7E, 0x7E, 0x7E,                        // 020   072
  0x7E, 0x7E, 0x7E, 0x7E,                        // 021   076
  0x7E, 0x7E, 0x7E, 0x7E,                        // 022   080
  0x7E, 0x7E, 0x7E, 0x7E,                        // 023   084
  0x7E, 0x7E, 0x7E, 0x7E,                        // 024   088
  0x7E, 0x7E, 0x7E, 0x7E,                        // 025   092
  0x7E, 0x7E, 0x7E, 0x7E,                        // 026   096
  0x7E, 0x7E, 0x7E, 0x7E,                        // 027   100
  0x7E, 0x7E, 0x7E, 0x7E,                        // 028   104
  0x7E, 0x7E, 0x7E, 0x7E,                        // 029   108
  0x7E, 0x7E, 0x7E, 0x7E,                        // 030   112
  0x7E, 0x7E, 0x7E, 0x7E,                        // 031   116
  0x7E, 0x7E, 0x7E, 0x7E,                        // 032   120
  0x7E, 0x7E, 0x7E, 0x7E,                        // 033   124..127


  0x7E, 0x7E, 0x7E, 0x7E,                        // 034   128
  0x7E, 0x7E, 0x7E, 0x7E,                        // 035   132
  0x7E, 0x7E, 0x7E, 0x7E,                        // 036   136
  0x7E, 0x7E, 0x7E, 0x7E,                        // 037   140
  0x7E, 0x7E, 0x7E, 0x7E,                        // 038   144
  0x7E, 0x7E, 0x7E, 0x7E,                        // 039   148
  0x7E, 0x7E, 0x7E, 0x7E,                        // 040   152
  0x7E, 0x7E, 0x7E, 0x7E,                        // 041   156
  0x7E, 0x7E, 0x7E, 0x7E,                        // 042   160
  0x7E, 0x7E, 0x7E, 0x7E,                        // 043   164
  0x7E, 0x7E, 0x7E, 0x7E,                        // 044   168
  0x7E, 0x7E, 0x7E, 0x7E,                        // 045   172
  0x7E, 0x7E, 0x7E, 0x7E,                        // 046   176
  0x7E, 0x7E, 0x7E, 0x7E,                        // 047   180
  0x7E, 0x7E, 0x7E, 0x7E,                        // 048   184
  0x7E, 0x7E, 0x7E, 0x7E,                        // 049   188..191

  0x7E, 0x7E, 0x7E, 0x7E,                        // 050   192
  0x7E, 0x7E, 0x7E, 0x7E,                        // 051   166
  0x7E, 0x7E, 0x7E, 0x7E,                        // 052   200
  0x7E, 0x7E, 0x7E, 0x7E,                        // 053   204
  0x7E, 0x7E, 0x7E, 0x7E,                        // 054   208
  0x7E, 0x7E, 0x7E, 0x7E,                        // 055   212
  0x7E, 0x7E, 0x7E, 0x7E,                        // 056   216
  0x7E, 0x7E, 0x7E, 0x7E,                        // 057   220
  0x7E, 0x7E, 0x7E, 0x7E,                        // 058   224
  0x7E, 0x7E, 0x7E, 0x7E,                        // 059   228
  0x7E, 0x7E, 0x7E, 0x7E,                        // 060   232
  0x7E, 0x7E, 0x7E, 0x7E,                        // 061   236
  0x7E, 0x7E, 0x7E, 0x7E,                        // 062   240
  0x7E, 0x7E, 0x7E, 0x7E,                        // 063   244
  0x7E, 0x7E, 0x7E, 0x7E,                        // 064   248
  0x7E, 0x7E, 0x7E, 0x7E,                        // 065   252..255


  0x7E, 0x7E, 0x7E, 0x7E,                        // 066   256
  0x7E, 0x7E, 0x7E, 0x7E,                        // 067   260
  0x7E, 0x7E, 0x7E, 0x7E,                        // 068   264
  0x7E, 0x7E, 0x7E, 0x7E,                        // 069   268
  0x7E, 0x7E, 0x7E, 0x7E,                        // 070   272
  0x7E, 0x7E, 0x7E, 0x7E,                        // 071   276
  0x7E, 0x7E, 0x7E, 0x7E,                        // 072   280
  0x7E, 0x7E, 0x7E, 0x7E,                        // 073   284
  0x7E, 0x7E, 0x7E, 0x7E,                        // 074   288
  0x7E, 0x7E, 0x7E, 0x7E,                        // 075   292
  0x7E, 0x7E, 0x7E, 0x7E,                        // 076   296
  0x7E, 0x7E, 0x7E, 0x7E,                        // 077   300
  0x7E, 0x7E, 0x7E, 0x7E,                        // 078   304
  0x7E, 0x7E, 0x7E, 0x7E,                        // 079   308
  0x7E, 0x7E, 0x7E, 0x7E,                        // 080   312
  0x7E, 0x7E, 0x7E, 0x7E,                        // 081   316..319

  0x7E, 0x7E, 0x7E, 0x7E,                        // 082   320
  0x7E, 0x7E, 0x7E, 0x7E,                        // 083   324
  0x7E, 0x7E, 0x7E, 0x7E,                        // 084   328
  0x7E, 0x7E, 0x7E, 0x7E,                        // 085   332
  0x7E, 0x7E, 0x7E, 0x7E,                        // 086   336
  0x7E, 0x7E, 0x7E, 0x7E,                        // 087   340
  0x7E, 0x7E, 0x7E, 0x7E,                        // 088   344
  0x7E, 0x7E, 0x7E, 0x7E,                        // 089   348
  0x7E, 0x7E, 0x7E, 0x7E,                        // 090   352
  0x7E, 0x7E, 0x7E, 0x7E,                        // 091   356
  0x7E, 0x7E, 0x7E, 0x7E,                        // 092   360
  0x7E, 0x7E, 0x7E, 0x7E,                        // 093   364
  0x7E, 0x7E, 0x7E, 0x7E,                        // 094   368
  0x7E, 0x7E, 0x7E, 0x7E,                        // 095   372
  0x7E, 0x7E, 0x7E, 0x7E,                        // 096   376
  0x7E, 0x7E, 0x7E, 0x7E,                        // 097   380..383


  0x7E, 0x7E, 0x7E, 0x7E,                        // 098   384
  0x7E, 0x7E, 0x7E, 0x7E,                        // 099   388
  0x7E, 0x7E, 0x7E, 0x7E,                        // 100   392
  0x7E, 0x7E, 0x7E, 0x7E,                        // 101   396
  0x7E, 0x7E, 0x7E, 0x7E,                        // 102   400
  0x7E, 0x7E, 0x7E, 0x7E,                        // 103   404
  0x7E, 0x7E, 0x7E, 0x7E,                        // 104   408
  0x7E, 0x7E, 0x7E, 0x7E,                        // 105   412
  0x7E, 0x7E, 0x7E, 0x7E,                        // 106   416
  0x7E, 0x7E, 0x7E, 0x7E,                        // 107   420
  0x7E, 0x7E, 0x7E, 0x7E,                        // 108   424
  0x7E, 0x7E, 0x7E, 0x7E,                        // 109   428
  0x7E, 0x7E, 0x7E, 0x7E,                        // 110   432
  0x7E, 0x7E, 0x7E, 0x7E,                        // 111   436
  0x7E, 0x7E, 0x7E, 0x7E,                        // 112   440
  0x7E, 0x7E, 0x7E, 0x7E,                        // 113   444..447

  0x7E, 0x7E, 0x7E, 0x7E,                        // 114   448
  0x7E, 0x7E, 0x7E, 0x7E,                        // 115   452
  0x7E, 0x7E, 0x7E, 0x7E,                        // 116   456
  0x7E, 0x7E, 0x7E, 0x7E,                        // 117   460
  0x7E, 0x7E, 0x7E, 0x7E,                        // 118   464
  0x7E, 0x7E, 0x7E, 0x7E,                        // 119   468
  0x7E, 0x7E, 0x7E, 0x7E,                        // 120   472
  0x7E, 0x7E, 0x7E, 0x7E,                        // 121   476
  0x7E, 0x7E, 0x7E, 0x7E,                        // 122   480
  0x7E, 0x7E, 0x7E, 0x7E,                        // 123   484
  0x7E, 0x7E, 0x7E, 0x7E,                        // 124   488
  0x7E, 0x7E, 0x7E, 0x7E,                        // 125   492
  0x7E, 0x7E, 0x7E, 0x7E,                        // 126   496
  0x7E, 0x7E, 0x7E, 0x7E,                        // 127   560
  0x7E, 0x7E, 0x7E, 0x7E,                        // 128   504
  0x7E, 0x7E, 0x7E, 0x7E,                        // 129   508..511

  0x7E, 0x7E, 0x7E, 0x7E,                        // 130   512
  0x7E, 0x7E, 0x7E, 0x7E,                        // 131   516..519


                                                 // Phase jumps
  0xF4, 0xF4, 0xF4, 0xF4,                        // 132
  0xEB, 0xEB, 0xEB, 0xEB,                        // 133

  0xF4, 0xF4, 0xF4, 0xF4,                        // 134
  0xEB, 0xEB, 0xEB, 0xEB,                        // 135

  0xF4, 0xF4, 0xF4, 0xF4,                        // 136
  0xEB, 0xEB, 0xEB, 0xEB,                        // 137

  0xF4, 0xF4, 0xF4, 0xF4,                        // 138
  0xAB, 0xAB, 0xAB, 0xAB,                        // 139

	                                         // High-Density transitions
  0xB5, 0xB5, 0xB5, 0xB5,                        // 140   000
  0xB5, 0xB5, 0xB5, 0xB5,                        // 141   004
  0xB5, 0xB5, 0xB5, 0xB5,                        // 142   008
  0xB5, 0xB5, 0xB5, 0xB5,                        // 143   012
  0xB5, 0xB5, 0xB5, 0xB5,                        // 144   016
  0xB5, 0xB5, 0xB5, 0xB5,                        // 145   020
  0xB5, 0xB5, 0xB5, 0xB5,                        // 146   024
  0xB5, 0xB5, 0xB5, 0xB5,                        // 147   028
  0xB5, 0xB5, 0xB5, 0xB5,                        // 148   032
  0xB5, 0xB5, 0xB5, 0xB5,                        // 149   036
  0xB5, 0xB5, 0xB5, 0xB5,                        // 150   040
  0xB5, 0xB5, 0xB5, 0xB5,                        // 151   044
  0xB5, 0xB5, 0xB5, 0xB5,                        // 152   048
  0xB5, 0xB5, 0xB5, 0xB5,                        // 153   052
  0xB5, 0xB5, 0xB5, 0xB5,                        // 154   056
  0xB5, 0xB5, 0xB5, 0xB5,                        // 155   060..063

  0xB5, 0xB5, 0xB5, 0xB5,                        // 156   064
  0xB5, 0xB5, 0xB5, 0xB5,                        // 157   068
  0xB5, 0xB5, 0xB5, 0xB5,                        // 158   072
  0xB5, 0xB5, 0xB5, 0xB5,                        // 159   076
  0xB5, 0xB5, 0xB5, 0xB5,                        // 160   080
  0xB5, 0xB5, 0xB5, 0xB5,                        // 161   084
  0xB5, 0xB5, 0xB5, 0xB5,                        // 162   088
  0xB5, 0xB5, 0xB5, 0xB5,                        // 163   092
  0xB5, 0xB5, 0xB5, 0xB5,                        // 164   096
  0xB5, 0xB5, 0xB5, 0xB5,                        // 165   100
  0xB5, 0xB5, 0xB5, 0xB5,                        // 166   104
  0xB5, 0xB5, 0xB5, 0xB5,                        // 167   108
  0xB5, 0xB5, 0xB5, 0xB5,                        // 168   112
  0xB5, 0xB5, 0xB5, 0xB5,                        // 169   116
  0xB5, 0xB5, 0xB5, 0xB5,                        // 170   120
  0xB5, 0xB5, 0xB5, 0xB5,                        // 171   124..127

  0xB5, 0xB5, 0xB5, 0xB5,                        // 172   128
  0xB5, 0xB5, 0xB5, 0xB5,                        // 173   132
  0xB5, 0xB5, 0xB5, 0xB5,                        // 174   136
  0xB5, 0xB5, 0xB5, 0xB5,                        // 175   140
  0xB5, 0xB5, 0xB5, 0xB5,                        // 176   144
  0xB5, 0xB5, 0xB5, 0xB5,                        // 177   148
  0xB5, 0xB5, 0xB5, 0xB5,                        // 178   152
  0xB5, 0xB5, 0xB5, 0xB5,                        // 179   156..159


			                         // Phase jumps
  0xEB, 0xEB, 0xEB, 0xEB,                        // 180
  0xF4, 0xF4, 0xF4, 0xF4,                        // 181

  0xEB, 0xEB, 0xEB, 0xEB,                        // 182
  0xF4, 0xF4, 0xF4, 0xF4,                        // 183

  0xEB, 0xEB, 0xEB, 0xEB,                        // 184
  0xF4, 0xF4, 0xF4, 0xF4,                        // 185

  0xEB, 0xEB, 0xEB, 0xEB,                        // 186
  0xF4, 0xF4, 0xF4, 0xF4,                        // 187

                                                 // Low-Density transitions
  0x7E, 0x7E, 0x7E, 0x7E,                        // 188   000
  0x7E, 0x7E, 0x7E, 0x7E,                        // 189   004
  0x7E, 0x7E, 0x7E, 0x7E,                        // 190   008
  0x7E, 0x7E, 0x7E, 0x7E,                        // 191   012
  0x7E, 0x7E, 0x7E, 0x7E,                        // 192   016
  0x7E, 0x7E, 0x7E, 0x7E,                        // 193   020
  0x7E, 0x7E, 0x7E, 0x7E,                        // 194   024
  0x7E, 0x7E, 0x7E, 0x7E,                        // 195   028
  0x7E, 0x7E, 0x7E, 0x7E,                        // 196   032
  0x7E, 0x7E, 0x7E, 0x7E,                        // 197   036
  0x7E, 0x7E, 0x7E, 0x7E,                        // 198   040
  0x7E, 0x7E, 0x7E, 0x7E,                        // 199   044
  0x7E, 0x7E, 0x7E, 0x7E,                        // 200   048
  0x7E, 0x7E, 0x7E, 0x7E,                        // 201   052
  0x7E, 0x7E, 0x7E, 0x7E,                        // 202   056
  0x7E, 0x7E, 0x7E, 0x7E,                        // 203   060..063

  0x7E, 0x7E, 0x7E, 0x7E,                        // 204   064
  0x7E, 0x7E, 0x7E, 0x7E,                        // 205   068
  0x7E, 0x7E, 0x7E, 0x7E,                        // 206   072
  0x7E, 0x7E, 0x7E, 0x7E,                        // 207   076
  0x7E, 0x7E, 0x7E, 0x7E,                        // 208   080
  0x7E, 0x7E, 0x7E, 0x7E,                        // 209   084
  0x7E, 0x7E, 0x7E, 0x7E,                        // 210   088
  0x7E, 0x7E, 0x7E, 0x7E,                        // 211   092
  0x7E, 0x7E, 0x7E, 0x7E,                        // 212   096
  0x7E, 0x7E, 0x7E, 0x7E,                        // 213   100
  0x7E, 0x7E, 0x7E, 0x7E,                        // 214   104
  0x7E, 0x7E, 0x7E, 0x7E,                        // 215   108
  0x7E, 0x7E, 0x7E, 0x7E,                        // 216   112
  0x7E, 0x7E, 0x7E, 0x7E,                        // 217   116
  0x7E, 0x7E, 0x7E, 0x7E,                        // 218   120
  0x7E, 0x7E, 0x7E, 0x7E,                        // 219   124..127


  0x7E, 0x7E, 0x7E, 0x7E,                        // 220   128
  0x7E, 0x7E, 0x7E, 0x7E,                        // 221   132
  0x7E, 0x7E, 0x7E, 0x7E,                        // 222   136
  0x7E, 0x7E, 0x7E, 0x7E,                        // 223   140
  0x7E, 0x7E, 0x7E, 0x7E,                        // 224   144
  0x7E, 0x7E, 0x7E, 0x7E,                        // 225   148
  0x7E, 0x7E, 0x7E, 0x7E,                        // 226   152
  0x7E, 0x7E, 0x7E, 0x7E,                        // 227   156
  0x7E, 0x7E, 0x7E, 0x7E,                        // 228   160
  0x7E, 0x7E, 0x7E, 0x7E,                        // 229   164
  0x7E, 0x7E, 0x7E, 0x7E,                        // 230   168
  0x7E, 0x7E, 0x7E, 0x7E,                        // 231   172
  0x7E, 0x7E, 0x7E, 0x7E,                        // 232   176
  0x7E, 0x7E, 0x7E, 0x7E,                        // 233   180
  0x7E, 0x7E, 0x7E, 0x7E,                        // 234   184
  0x7E, 0x7E, 0x7E, 0x7E,                        // 235   188..191

  0x7E, 0x7E, 0x7E, 0x7E,                        // 236   192
  0x7E, 0x7E, 0x7E, 0x7E,                        // 237   166
  0x7E, 0x7E, 0x7E, 0x7E,                        // 238   200
  0x7E, 0x7E, 0x7E, 0x7E,                        // 239   204
  0x7E, 0x7E, 0x7E, 0x7E,                        // 240   208
  0x7E, 0x7E, 0x7E, 0x7E,                        // 241   212
  0x7E, 0x7E, 0x7E, 0x7E,                        // 242   216
  0x7E, 0x7E, 0x7E, 0x7E,                        // 243   220
  0x7E, 0x7E, 0x7E, 0x7E,                        // 244   224
  0x7E, 0x7E, 0x7E, 0x7E,                        // 245   228
  0x7E, 0x7E, 0x7E, 0x7E,                        // 246   232
  0x7E, 0x7E, 0x7E, 0x7E,                        // 247   236
  0x7E, 0x7E, 0x7E, 0x7E,                        // 248   240
  0x7E, 0x7E, 0x7E, 0x7E,                        // 249   244
  0x7E, 0x7E, 0x7E, 0x7E,                        // 250   248
  0x7E, 0x7E, 0x7E, 0x7E,                        // 251   252..255


  0x7E, 0x7E, 0x7E, 0x7E,                        // 252   256
  0x7E, 0x7E, 0x7E, 0x7E,                        // 253   260
  0x7E, 0x7E, 0x7E, 0x7E,                        // 254   264
  0x7E, 0x7E, 0x7E, 0x7E,                        // 255   268
  0x7E, 0x7E, 0x7E, 0x7E,                        // 256   272
  0x7E, 0x7E, 0x7E, 0x7E,                        // 257   276
  0x7E, 0x7E, 0x7E, 0x7E,                        // 258   280
  0x7E, 0x7E, 0x7E, 0x7E,                        // 259   284
  0x7E, 0x7E, 0x7E, 0x7E,                        // 260   288
  0x7E, 0x7E, 0x7E, 0x7E,                        // 261   292
  0x7E, 0x7E, 0x7E, 0x7E,                        // 262   296
  0x7E, 0x7E, 0x7E, 0x7E,                        // 263   300
  0x7E, 0x7E, 0x7E, 0x7E,                        // 264   304
  0x7E, 0x7E, 0x7E, 0x7E,                        // 265   308
  0x7E, 0x7E, 0x7E, 0x7E,                        // 266   312
  0x7E, 0x7E, 0x7E, 0x7E,                        // 267   316..319

  0x7E, 0x7E, 0x7E, 0x7E,                        // 268   320
  0x7E, 0x7E, 0x7E, 0x7E,                        // 269   324
  0x7E, 0x7E, 0x7E, 0x7E,                        // 270   328
  0x7E, 0x7E, 0x7E, 0x7E,                        // 271   332
  0x7E, 0x7E, 0x7E, 0x7E,                        // 272   336
  0x7E, 0x7E, 0x7E, 0x7E,                        // 273   340
  0x7E, 0x7E, 0x7E, 0x7E,                        // 274   344
  0x7E, 0x7E, 0x7E, 0x7E,                        // 275   348
  0x7E, 0x7E, 0x7E, 0x7E,                        // 276   352
  0x7E, 0x7E, 0x7E, 0x7E,                        // 277   356
  0x7E, 0x7E, 0x7E, 0x7E,                        // 278   360
  0x7E, 0x7E, 0x7E, 0x7E,                        // 279   364
  0x7E, 0x7E, 0x7E, 0x7E,                        // 280   368
  0x7E, 0x7E, 0x7E, 0x7E,                        // 281   372
  0x7E, 0x7E, 0x7E, 0x7E,                        // 282   376
  0x7E, 0x7E, 0x7E, 0x7E,                        // 283   380..383


  0x7E, 0x7E, 0x7E, 0x7E,                        // 284   384
  0x7E, 0x7E, 0x7E, 0x7E,                        // 285   388
  0x7E, 0x7E, 0x7E, 0x7E,                        // 286   392
  0x7E, 0x7E, 0x7E, 0x7E,                        // 287   396
  0x7E, 0x7E, 0x7E, 0x7E,                        // 288   400
  0x7E, 0x7E, 0x7E, 0x7E,                        // 289   404
  0x7E, 0x7E, 0x7E, 0x7E,                        // 290   408
  0x7E, 0x7E, 0x7E, 0x7E,                        // 291   412
  0x7E, 0x7E, 0x7E, 0x7E,                        // 292   416
  0x7E, 0x7E, 0x7E, 0x7E,                        // 293   420
  0x7E, 0x7E, 0x7E, 0x7E,                        // 294   424
  0x7E, 0x7E, 0x7E, 0x7E,                        // 295   428
  0x7E, 0x7E, 0x7E, 0x7E,                        // 296   432
  0x7E, 0x7E, 0x7E, 0x7E,                        // 297   436
  0x7E, 0x7E, 0x7E, 0x7E,                        // 298   440
  0x7E, 0x7E, 0x7E, 0x7E,                        // 299   444..447

  0x7E, 0x7E, 0x7E, 0x7E,                        // 300   448
  0x7E, 0x7E, 0x7E, 0x7E,                        // 301   452
  0x7E, 0x7E, 0x7E, 0x7E,                        // 302   456
  0x7E, 0x7E, 0x7E, 0x7E,                        // 303   460
  0x7E, 0x7E, 0x7E, 0x7E,                        // 304   464
  0x7E, 0x7E, 0x7E, 0x7E,                        // 305   468
  0x7E, 0x7E, 0x7E, 0x7E,                        // 306   472
  0x7E, 0x7E, 0x7E, 0x7E,                        // 307   476
  0x7E, 0x7E, 0x7E, 0x7E,                        // 308   480
  0x7E, 0x7E, 0x7E, 0x7E,                        // 309   484
  0x7E, 0x7E, 0x7E, 0x7E,                        // 310   488
  0x7E, 0x7E, 0x7E, 0x7E,                        // 311   492
  0x7E, 0x7E, 0x7E, 0x7E,                        // 312   496
  0x7E, 0x7E, 0x7E, 0x7E,                        // 313   560
  0x7E, 0x7E, 0x7E, 0x7E,                        // 314   504
  0x7E, 0x7E, 0x7E, 0x7E,                        // 315   508..511

  0x7E, 0x7E, 0x7E, 0x7E,                        // 316   512
  0x7E, 0x7E, 0x7E, 0x7E,                        // 317   516
  0x7E, 0x7E, 0x7E, 0x7E,                        // 318   520
  0x7E, 0x7E, 0x7E, 0x7E,                        // 319   524..527

  		                                 // Phase jumps
  0xF4, 0xF4, 0xF4, 0xF4,                        // 320
  0xEB, 0xEB, 0xEB, 0xEB,                        // 321

  0xF4, 0xF4, 0xF4, 0xF4,                        // 322
  0xEB, 0xEB, 0xEB, 0xEB,                        // 323

  0xF4, 0xF4, 0xF4, 0xF4,                        // 324
  0xEB, 0xEB, 0xEB, 0xEB,                        // 325

  0xF4, 0xF4, 0xF4, 0xF4,                        // 326
  0xAB, 0xAB, 0xAB, 0xAB,                        // 327

	                                         // High-Density transitions
  0xB5, 0xB5, 0xB5, 0xB5,                        // 328   000
  0xB5, 0xB5, 0xB5, 0xB5,                        // 329   004
  0xB5, 0xB5, 0xB5, 0xB5,                        // 330   008
  0xB5, 0xB5, 0xB5, 0xB5,                        // 331   012
  0xB5, 0xB5, 0xB5, 0xB5,                        // 332   016
  0xB5, 0xB5, 0xB5, 0xB5,                        // 333   020
  0xB5, 0xB5, 0xB5, 0xB5,                        // 334   024
  0xB5, 0xB5, 0xB5, 0xB5,                        // 335   028
  0xB5, 0xB5, 0xB5, 0xB5,                        // 336   032
  0xB5, 0xB5, 0xB5, 0xB5,                        // 337   036
  0xB5, 0xB5, 0xB5, 0xB5,                        // 338   040
  0xB5, 0xB5, 0xB5, 0xB5,                        // 339   044
  0xB5, 0xB5, 0xB5, 0xB5,                        // 340   048
  0xB5, 0xB5, 0xB5, 0xB5,                        // 341   052
  0xB5, 0xB5, 0xB5, 0xB5,                        // 342   056
  0xB5, 0xB5, 0xB5, 0xB5,                        // 343   060..063

  0xB5, 0xB5, 0xB5, 0xB5,                        // 344   064
  0xB5, 0xB5, 0xB5, 0xB5,                        // 345   068
  0xB5, 0xB5, 0xB5, 0xB5,                        // 346   072
  0xB5, 0xB5, 0xB5, 0xB5,                        // 347   076
  0xB5, 0xB5, 0xB5, 0xB5,                        // 348   080
  0xB5, 0xB5, 0xB5, 0xB5,                        // 349   084
  0xB5, 0xB5, 0xB5, 0xB5,                        // 350   088
  0xB5, 0xB5, 0xB5, 0xB5,                        // 351   092
  0xB5, 0xB5, 0xB5, 0xB5,                        // 352   096
  0xB5, 0xB5, 0xB5, 0xB5,                        // 353   100
  0xB5, 0xB5, 0xB5, 0xB5,                        // 354   104
  0xB5, 0xB5, 0xB5, 0xB5,                        // 355   108
  0xB5, 0xB5, 0xB5, 0xB5,                        // 356   112
  0xB5, 0xB5, 0xB5, 0xB5,                        // 357   116
  0xB5, 0xB5, 0xB5, 0xB5,                        // 358   120
  0xB5, 0xB5, 0xB5, 0xB5,                        // 359   124..127

  0xB5, 0xB5, 0xB5, 0xB5,                        // 360   128
  0xB5, 0xB5, 0xB5, 0xB5,                        // 361   132
  0xB5, 0xB5, 0xB5, 0xB5,                        // 362   136
  0xB5, 0xB5, 0xB5, 0xB5,                        // 363   140
  0xB5, 0xB5, 0xB5, 0xB5,                        // 364   144
  0xB5, 0xB5, 0xB5, 0xB5,                        // 365   148
  0xB5, 0xB5, 0xB5, 0xB5,                        // 366   152
  0xB5, 0xB5, 0xB5, 0xB5,                        // 367   156..159

                                                 // Phase Jumps
  0xEB, 0xEB, 0xEB, 0xEB,                        // 368
  0xF4, 0xF4, 0xF4, 0xF4,                        // 369

  0xEB, 0xEB, 0xEB, 0xEB,                        // 370
  0xF4, 0xF4, 0xF4, 0xF4,                        // 371

  0xEB, 0xEB, 0xEB, 0xEB,                        // 372
  0xF4, 0xF4, 0xF4, 0xF4,                        // 373

  0xEB, 0xEB, 0xEB, 0xEB,                        // 374
  0xF4, 0xF4, 0xF4, 0xF4,                        // 375

			                         // Packet FCS (CRC)
  0xBD, 0x9F, 0x1E, 0xAB			 // 376
};

typedef struct
{
    uint64_t                output_percent_x1000;   /* percent*1000 */
    uint64_t                output_cycle_gap;
    uint64_t                output_packet_size;
    uint64_t                output_enable;
    uint64_t                output_count;
    packet_type_t           output_packet_type;
    payload_t               output_packet_payload;
    uint64_t                output_arp_reply_enable;
    uint64_t                src_mac;    /* MACs are stored so a printf in hex will show them */
    int32_t                 src_mac_inc;
    uint64_t                src_mac_min;
    uint64_t                src_mac_max;
    uint64_t                dest_mac;
    int32_t                 dest_mac_inc;
    uint64_t                dest_mac_min;
    uint64_t                dest_mac_max;
    uint64_t                vlan_size;
    uint8_t                 vlan[MAX_INSERT];
    uint32_t                src_ip;
    int32_t                 src_ip_inc;
    uint32_t                src_ip_min;
    uint32_t                src_ip_max;
    uint32_t                dest_ip;
    int32_t                 dest_ip_inc;
    uint32_t                dest_ip_min;
    uint32_t                dest_ip_max;
    uint32_t                ip_tos;
    uint16_t                src_port;
    int16_t                 src_port_inc;
    uint16_t                src_port_min;
    uint16_t                src_port_max;
    uint16_t                dest_port;
    int16_t                 dest_port_inc;
    uint16_t                dest_port_min;
    uint16_t                dest_port_max;
    int                     do_checksum;
    int                     bridge_port;
    int                     display_packet;
    int                     input_arp_reply_enable;
    int                     input_arp_request_enable;
    char *                  output_data;
    int                     promisc;  /* Promiscuous mode (default to 1) */
    int                     validate;
    int                     respect_backpressure;
    int                     higig; /* Number of HiGig bytes to include before L2 */
    bdk_higig_header_t      higig_header; /* The HiGig header included if "higig" is set */
    bdk_srio_tx_message_header_t srio;
} port_setup_t;

port_state_t    port_state[BDK_PIP_NUM_INPUT_PORTS];
port_setup_t    port_setup[BDK_PIP_NUM_INPUT_PORTS];
CACHE_LINE_ALIGN bdk_spinlock_t    port_lock[BDK_PIP_NUM_INPUT_PORTS];
uint64_t        cpu_clock_hz;
int                         default_start_port = 0;
int                         default_stop_port = BDK_PIP_NUM_INPUT_PORTS-1;
int                         frozen = 0;        /* set to stop display updates */
int                         help_frozen = 0;   /* set to stop display updates */
int                         max_displayed_row = 1;
int                         force_min = 1;

#define TIMESTAMP_INVALID ((uint64_t)-1)
uint64_t total_display_updates=0;
uint64_t last_start_total_display_updates=TIMESTAMP_INVALID;
uint64_t sending_time = 0;

struct {
    char **help_string_p;
    char *help_prefix;
    int help_prefix_length;
    int max_help_lines;
} leftover_help = {NULL,NULL,0,0};

static void process_input_type(char *text);
static void periodic_update(int show_command_line);
static packet_free_t fastpath_receive(bdk_wqe_t *work);

#define MAX_ROW 400

typedef struct
{
    uint8_t hidden;
    uint8_t highlight;
    uint8_t hide_delay;
} row_state_t;

static row_state_t row_state[MAX_ROW] = {{0,0,0},};


/**
 * Get a single byte from serial port.
 *
 * @param uart_index Uart to read from (0 or 1)
 * @return The byte read
 */
static inline uint8_t uart_read_byte(int uart_index)
{
    /* Read and return the data. Zero will be returned if there is
        no data */
    bdk_mio_uartx_lsr_t lsrval;

    fflush(NULL);

    lsrval.u64 = BDK_CSR_READ(BDK_MIO_UARTX_LSR(uart_index));
    if (lsrval.s.dr)
        return BDK_CSR_READ(BDK_MIO_UARTX_RBR(uart_index));
    else
    {
        bdk_thread_yield();
        return 0;
    }
}

static inline int get_size_wire_overhead(int port)
{
    if (port_setup[port].higig)
        return 8 /*INTERFRAME_GAP*/ + port_setup[port].higig + ETHERNET_CRC;
    else if (port_setup[port].srio.u64)
        return 0;
    else
        return 12 /*INTERFRAME_GAP*/ + 8 /*MAC_PREAMBLE*/ + ETHERNET_CRC;
}

static inline int get_size_pre_l2(int port)
{
    if (port_setup[port].srio.u64)
    {
        /* TX needs to add SRIO header */
        return sizeof(port_setup[port].srio);
    }
    else
    {
        /* The preamble is created by hardware, so the length is zero for SW. In
            the higig case, the higig header replaces the preamble and we need
            to include it */
        return port_setup[port].higig;
    }
}

static inline int get_size_l2(int port)
{
    /* L2 header is two MAC addresses, optional VLAN stuff, and a L2 size/type */
    return MAC_ADDR_LEN*2 + port_setup[port].vlan_size + 2;
}

static inline int get_size_ip_header(int port)
{
    /* We don't support options, so the size of the IP header is fixed for
        IPv4 or IPv6 */
    switch (port_setup[port].output_packet_type)
    {
        case PACKET_TYPE_IPV6_UDP:
        case PACKET_TYPE_IPV6_TCP:
            return 40;
        case PACKET_TYPE_802_3_PAUSE:
        case PACKET_TYPE_CBFC_PAUSE:
        case PACKET_TYPE_CJPAT:
            return 0;
        default:
            return 20;
    }
}

static inline int get_size_payload(int port)
{
    /* The payload area is whatever is left after the previous headers. Note
        that this does not include any UDP or TCP header */
    return port_setup[port].output_packet_size - get_size_ip_header(port) - get_size_l2(port);
}

static inline int get_end_pre_l2(int port)
{
    return get_size_pre_l2(port);
}

static inline int get_end_l2(int port)
{
    return get_end_pre_l2(port) + get_size_l2(port);
}

static inline int get_end_ip_header(int port)
{
    return get_end_l2(port) + get_size_ip_header(port);
}

static inline int get_end_payload(int port)
{
    return get_end_ip_header(port) + get_size_payload(port);
}


/**
 * Given a WQE, return an Octeon packet pointer for the beginning
 * of the packet data. This is trivially the pakcet pointer in the
 * WQE for packets with buffers. For packets where bufs is zero this
 * is non trival.
 *
 * @param work   Work queue entry for packet
 *
 * @return An Octeon packet buffer pointer. This is not a
 *         C pointer.
 */
static inline bdk_buf_ptr_t get_packet_buffer_ptr(const bdk_wqe_t *work)
{
    bdk_buf_ptr_t buffer_ptr;
    if (bdk_likely(work->word2.s.bufs == 0))
    {
        buffer_ptr.u64 = 0;
        buffer_ptr.s.pool = BDK_FPA_WQE_POOL;
        buffer_ptr.s.size = bdk_fpa_get_block_size(BDK_FPA_WQE_POOL);
        buffer_ptr.s.addr = bdk_ptr_to_phys((void*)work->packet_data);
        /* WARNING: This code assume that PIP_GBL_CFG[RAW_SHF]=0 and
            PIP_GBL_CFG[NIP_SHF]=0. If this was not the case we'd
            need to add these offsets depending on if the packet was
            in RAW mode or not.
            addr += PIP_GBL_CFG[RAW_SHF] for the RAW case.
            addr += PIP_GBL_CFG[NIP_SHF]; for the non-IP case */
        if (bdk_likely(!work->word2.s.not_IP))
        {
            buffer_ptr.s.addr += PIP_IP_OFFSET*8 - work->word2.s.ip_offset;
            buffer_ptr.s.addr += (work->word2.s.is_v6^1)*4;
        }
    }
    else
        buffer_ptr = work->packet_ptr;
    return buffer_ptr;
}


/**
 * Set the hardware MAC address for a device
 *
 * @param interface    interface of port to set
 * @param index    index of port to set MAC address for
 * @param addr   Address structure to change it too.
 * @return Zero on success
 */
static int cvm_oct_set_mac_address(int interface, int index, uint64_t *addr)
{
    bdk_gmxx_prtx_cfg_t gmx_cfg;
    uint64_t mac = 0;
    uint8_t *ptr = (void *)&mac;

    /* NULL (or zero) addr disables MAC filtering */
    if (addr)
        mac = *addr;

    ptr += 2;  /* Skip upper 2 bytes of uint64 */

    /* Disable interface */
    gmx_cfg.u64 = BDK_CSR_READ(BDK_GMXX_PRTX_CFG(index, interface));
    BDK_CSR_WRITE(BDK_GMXX_PRTX_CFG(index, interface), gmx_cfg.u64 & ~1ull);

    BDK_CSR_WRITE(BDK_GMXX_SMACX(index, interface), mac);
    BDK_CSR_WRITE(BDK_GMXX_RXX_ADR_CAM0(index, interface), ptr[0]);
    BDK_CSR_WRITE(BDK_GMXX_RXX_ADR_CAM1(index, interface), ptr[1]);
    BDK_CSR_WRITE(BDK_GMXX_RXX_ADR_CAM2(index, interface), ptr[2]);
    BDK_CSR_WRITE(BDK_GMXX_RXX_ADR_CAM3(index, interface), ptr[3]);
    BDK_CSR_WRITE(BDK_GMXX_RXX_ADR_CAM4(index, interface), ptr[4]);
    BDK_CSR_WRITE(BDK_GMXX_RXX_ADR_CAM5(index, interface), ptr[5]);


    bdk_gmxx_rxx_adr_ctl_t control;
    control.u64 = 0;
    control.s.bcst = 1;     /* Allow broadcast MAC addresses */
    control.s.mcst = !!mac; /* Force reject multicat packets if filtering enabled */
    control.s.cam_mode = !!mac; /* Filter packets based on the CAM (if no filtering, set CAM to 0x0, reject based on CAM */
    BDK_CSR_WRITE(BDK_GMXX_RXX_ADR_CTL(index, interface), control.u64);

    BDK_CSR_WRITE(BDK_GMXX_RXX_ADR_CAM_EN(index, interface), 1);


    /* Return interface to previous enable state */
    BDK_CSR_WRITE(BDK_GMXX_PRTX_CFG(index, interface), gmx_cfg.u64);

    return 0;
}

/**
 * Update the packet cycle gap for the current tx percentage
 *
 * @param port
 */
static inline void update_cycle_gap(int port)
{
    uint64_t packet_rate = port_setup[port].output_percent_x1000 * 1250 /
        (port_setup[port].output_packet_size + get_size_wire_overhead(port));
    if (packet_rate)
        port_setup[port].output_cycle_gap = (cpu_clock_hz << CYCLE_SHIFT) / packet_rate;
    else
        port_setup[port].output_cycle_gap = (cpu_clock_hz << CYCLE_SHIFT);
}

/*
 *      Fold a partial checksum without adding pseudo headers
 */
static inline unsigned short int csum_fold(unsigned int sum)
{
        __asm__(
        "       .set    push            # csum_fold\n"
        "       .set    noat            \n"
        "       sll     $1, %0, 16      \n"
        "       addu    %0, $1          \n"
        "       sltu    $1, %0, $1      \n"
        "       srl     %0, %0, 16      \n"
        "       addu    %0, $1          \n"
        "       xori    %0, 0xffff      \n"
        "       .set    pop"
        : "=r" (sum)
        : "0" (sum));

        return sum;
}


/*
 *      This is a version of ip_compute_csum() optimized for IP headers,
 *      which always checksum on 4 octet boundaries.
 *
 *      By Jorge Cwik <jorge@laser.satlink.net>, adapted for linux by
 *      Arnt Gulbrandsen.
 */
static inline unsigned short ip_fast_csum(char *iph, unsigned int ihl)
{
        unsigned int *word = (unsigned int *) iph;
        unsigned int *stop = word + ihl;
        unsigned int csum;
        int carry;

        csum = word[0];
        csum += word[1];
        carry = (csum < word[1]);
        csum += carry;

        csum += word[2];
        carry = (csum < word[2]);
        csum += carry;

        csum += word[3];
        carry = (csum < word[3]);
        csum += carry;

        word += 4;
        do {
                csum += *word;
                carry = (csum < *word);
                csum += carry;
                word++;
        } while (word != stop);

        return csum_fold(csum);
}


static uint32_t crc32c(void *ptr, int len, uint32_t iv)
{
    uint32_t crc32;
    /* (crc-32c) */
    BDK_MT_CRC_POLYNOMIAL(0x1edc6f41);
    BDK_MT_CRC_IV(iv);
    while (len>=64)
    {
        uint64_t *p = ptr;
        BDK_MT_CRC_DWORD(p[0]);
        BDK_MT_CRC_DWORD(p[1]);
        BDK_MT_CRC_DWORD(p[2]);
        BDK_MT_CRC_DWORD(p[3]);
        BDK_MT_CRC_DWORD(p[4]);
        BDK_MT_CRC_DWORD(p[5]);
        BDK_MT_CRC_DWORD(p[6]);
        BDK_MT_CRC_DWORD(p[7]);
        ptr += 64;
        len -= 64;
    }
    while (len>=8)
    {
        BDK_MT_CRC_DWORD(*(uint64_t*)ptr);
        ptr += 8;
        len -= 8;
    }
    if (len>=4)
    {
        BDK_MT_CRC_WORD(*(uint32_t*)ptr);
        ptr += 4;
        len -= 4;
    }
    if (len>=2)
    {
        BDK_MT_CRC_HALF(*(uint16_t*)ptr);
        ptr += 2;
        len -= 2;
    }
    if (len)
        BDK_MT_CRC_BYTE(*(uint8_t*)ptr);
    BDK_MF_CRC_IV(crc32);
    return crc32;
}


static inline char *build_packet_mac_and_vlan_only(char *packet, int port)
{
    int i;
    char *ptr = packet;

    /* Add the SRIO header before L2 if needed */
    if (port_setup[port].srio.u64)
    {
        memcpy(ptr, &port_setup[port].srio, sizeof(port_setup[port].srio));
        ptr += sizeof(port_setup[port].srio);
    }

    /* Add the HiGig header before L2 if needed */
    if (port_setup[port].higig)
    {
        memcpy(ptr, &port_setup[port].higig_header, port_setup[port].higig);
        ptr += port_setup[port].higig;
    }

    /* Ethernet dest address */
    for (i=0; i<6; i++)
        *ptr++ = (port_setup[port].dest_mac>>(40-i*8)) & 0xff;

    /* Ethernet source address */
    for (i=0; i<6; i++)
        *ptr++ = (port_setup[port].src_mac>>(40-i*8)) & 0xff;

    /* VLAN */
    for (i=0; i<(int)port_setup[port].vlan_size; i++)
        *ptr++ = (port_setup[port].vlan[i]);

    return ptr;
}

/**
 * Generate a valid UDP packet
 *
 * @param port   Output port to build for
 */
static void build_packet(int port)
{
    int i;
    char *packet = port_setup[port].output_data;
    char *end_ptr = packet + get_end_payload(port);
    char *ptr = build_packet_mac_and_vlan_only(packet, port);
    int ip_length;

    switch (port_setup[port].output_packet_type)
    {
        uint16_t *ip_checksum_ptr;
        case PACKET_TYPE_HELP:
        case PACKET_TYPE_IPV4_UDP:
        case PACKET_TYPE_IPV4_TCP:
            *ptr++ = 0x08;                  /* Ethernet Protocol */
            *ptr++ = 0x00;
            *ptr++ = 0x45;                  /* IP version, ihl */
            *ptr++ = (port_setup[port].ip_tos) & 0xff;    /* IP TOS */
            ip_length = get_size_ip_header(port) + get_size_payload(port);
            *ptr++ = ip_length>>8;        /* IP length */
            *ptr++ = ip_length&0xff;
            *ptr++ = 0x00;                  /* IP id */
            *ptr++ = 0x00;
            *ptr++ = 0x00;                  /* IP frag_off */
            *ptr++ = 0x00;
            *ptr++ = 0x04;                  /* IP ttl */
            *ptr++ = (port_setup[port].output_packet_type == PACKET_TYPE_IPV4_TCP) ? 0x6 : 0x11; /* IP protocol */
            ip_checksum_ptr = (uint16_t *)ptr;    /* remember for later */
            *ptr++ = 0x00;                  /* IP check */
            *ptr++ = 0x00;
            *ptr++ = (port_setup[port].src_ip>>24) & 0xff;    /* IP saddr */
            *ptr++ = (port_setup[port].src_ip>>16) & 0xff;
            *ptr++ = (port_setup[port].src_ip>>8) & 0xff;
            *ptr++ = (port_setup[port].src_ip>>0) & 0xff;
            *ptr++ = (port_setup[port].dest_ip>>24) & 0xff;    /* IP daddr */
            *ptr++ = (port_setup[port].dest_ip>>16) & 0xff;
            *ptr++ = (port_setup[port].dest_ip>>8) & 0xff;
            *ptr++ = (port_setup[port].dest_ip>>0) & 0xff;
            *ip_checksum_ptr = ip_fast_csum(packet+get_end_l2(port), 5);
            break;
        case PACKET_TYPE_IPV6_UDP:
        case PACKET_TYPE_IPV6_TCP:
            if (port_setup[port].output_packet_size < 62)
                printf("Warning: Port %2llu Packet size too small for UDP payload. Minimum is 62\n", (ULL)port);
            if (!port_setup[port].do_checksum)
                printf("Warning: Port %2llu UDP checksum is off. Linux will drop IPv6 UDP packets without a checksum\n", (ULL)port);
            if ((port_setup[port].output_packet_size < 66) && port_setup[port].validate)
                printf("Warning: Port %2llu Packet size too small for validation. Minimum is 66\n", (ULL)port);
            *(uint16_t*)ptr = 0x86dd; ptr+=2;                           /* Ethernet Protocol = ETH_P_IPV6 0x86DD */
            *ptr++ = 0x60 | ((port_setup[port].ip_tos>>4) & 0xf); /* IP version 6, 4 bits of DS byte */
            *ptr++ = (((port_setup[port].ip_tos) & 0xf) << 4) | 0;/* 4 bits of DS byte + 4 bits of Flow label (0) */
            *(uint16_t*)ptr = 0; ptr+=2;                                /* Flow label */
            ip_length = get_size_payload(port);
            *(uint16_t*)ptr = ip_length; ptr+=2;    /* Payload length */
            *ptr++ = (port_setup[port].output_packet_type == PACKET_TYPE_IPV6_TCP) ? 0x6 : 0x11; /* IP protocol */
            *ptr++ = 0x04;                                              /* IP ttl */
            *(uint64_t*)ptr = 0; ptr+=8;                                /* IP saddr */
            *(uint64_t*)ptr = port_setup[port].src_ip; ptr+=8;
            *(uint64_t*)ptr = 0; ptr+=8;                                /* IP daddr */
            *(uint64_t*)ptr = port_setup[port].dest_ip; ptr+=8;
            break;
        case PACKET_TYPE_802_3_PAUSE:
            port_setup[port].output_packet_size = 60;
            ptr = packet + get_end_pre_l2(port);
            end_ptr = packet + get_end_payload(port);
            *ptr++ = 0x01; /* Force DMAC = 0x0180C2000001 */
            *ptr++ = 0x80;
            *ptr++ = 0xC2;
            *ptr++ = 0x00;
            *ptr++ = 0x00;
            *ptr++ = 0x01;
            ptr += 6; /* Don't change SMAC */
            /* VLAN is not added */
            *(uint16_t*)ptr = 0x8808; ptr+=2; /* Ethernet Protocol = Pause frame */
            *(uint16_t*)ptr = 0x0001; ptr+=2; /* MAC CTL */
            *(uint16_t*)ptr = 60; ptr+=2; /* Pause timer FIXME */
            memset(ptr,  0,  end_ptr - ptr);
            return; /* Bail out before we get to the TCP/UDP stuff below */
        case PACKET_TYPE_CBFC_PAUSE:
            port_setup[port].output_packet_size = 60;
            ptr = packet + get_end_pre_l2(port);
            end_ptr = packet + get_end_payload(port);
            *ptr++ = 0x01; /* Force DMAC = 0x0180C2000001 */
            *ptr++ = 0x80;
            *ptr++ = 0xC2;
            *ptr++ = 0x00;
            *ptr++ = 0x00;
            *ptr++ = 0x01;
            ptr += 6; /* Don't change SMAC */
            /* VLAN is not added */
            *(uint16_t*)ptr = 0x8808; ptr+=2; /* Ethernet Protocol = Pause frame */
            *(uint16_t*)ptr = 0x0101; ptr+=2; /* MAC CTL */
            *(uint16_t*)ptr = 0xffff; ptr+=2; /* CEV - Each enabled bit says that a time below is valid */
            for (i=0; i<16;i++)
            {
                *(uint16_t*)ptr = 60; /* 16 timers FIXME */
                ptr+=2;
            }
            memset(ptr,  0,  end_ptr - ptr);
            return; /* Bail out before we get to the TCP/UDP stuff below */
        case PACKET_TYPE_CJPAT:
            port_setup[port].output_packet_size = sizeof(CJPAT_Packet);
            memcpy(packet, CJPAT_Packet, sizeof(CJPAT_Packet));
              /* Turn off the deficit counter and turn on unidirection mode. This forces
               * the XAUI interface into half-plex mode. (However, the executive startup
               * code usually wants to be in duplex-mode. I have to compile without
               * USE_DUPLEX in my modified version of bdk-helper-xaui.c!)
               */
            int interface = bdk_helper_get_interface_num(port);
            int index = bdk_helper_get_interface_index_num(port);
            bdk_gmxx_tx_xaui_ctl_t gmxx_tx_xaui_ctl;
            gmxx_tx_xaui_ctl.u64 = BDK_CSR_READ(BDK_GMXX_TX_XAUI_CTL(interface));
            gmxx_tx_xaui_ctl.s.dic_en = 0;
            gmxx_tx_xaui_ctl.s.uni_en = 1;
            BDK_CSR_WRITE (BDK_GMXX_TX_XAUI_CTL(interface), gmxx_tx_xaui_ctl.u64);

              /* Turn off FCS (CRC) generation. The pattern packet already contains the
               * appropriate CRC.
               */
            bdk_gmxx_txx_append_t gmxx_txx_append;
            gmxx_txx_append.u64 = BDK_CSR_READ(BDK_GMXX_TXX_APPEND(index, interface));
            gmxx_txx_append.s.force_fcs = 0;
            gmxx_txx_append.s.fcs       = 0;
            gmxx_txx_append.s.pad       = 0;
            gmxx_txx_append.s.preamble  = 0;
            BDK_CSR_WRITE (BDK_GMXX_TXX_APPEND(index, interface), gmxx_txx_append.u64);
            return; /* Bail out before we get to the TCP/UDP stuff below */
    }
    *ptr++ = port_setup[port].src_port >> 8;  /* UDP source port */
    *ptr++ = port_setup[port].src_port & 0xff;
    *ptr++ = port_setup[port].dest_port >> 8; /* UDP destination port */
    *ptr++ = port_setup[port].dest_port & 0xff;
    switch (port_setup[port].output_packet_type)
    {
        case PACKET_TYPE_HELP:
        case PACKET_TYPE_802_3_PAUSE:
        case PACKET_TYPE_CBFC_PAUSE:
        case PACKET_TYPE_CJPAT:
            break;
        case PACKET_TYPE_IPV4_UDP:
        case PACKET_TYPE_IPV6_UDP:
        {
            int udp_length = get_size_payload(port);
            *ptr++ = udp_length>>8;     /* UDP length */
            *ptr++ = udp_length&0xff;
            *ptr++ = 0x00;                  /* UDP checksum */
            *ptr++ = 0x00;
            break;
        }
        case PACKET_TYPE_IPV4_TCP:
        case PACKET_TYPE_IPV6_TCP:
            *(uint32_t*)ptr = 123456; ptr+=4;   /* TCP Sequence Number */
            *(uint32_t*)ptr = 234567; ptr+=4;   /* TCP Ack Number */
            *ptr++ = 5<<4;                      /* TCP Header length */
            *ptr++ = 0x10;                      /* TCP Flags */
            *(uint16_t*)ptr = 4096; ptr+=2;     /* TCP Window */
            *(uint16_t*)ptr = 0; ptr+=2;        /* TCP Checksum */
            *(uint16_t*)ptr = 0; ptr+=2;        /* TCP Urgent Pointer */
            break;
    }

    switch (port_setup[port].output_packet_payload) {
        case DATA_TYPE_ABC:
            /* Fill the rest of the packet with the ABCs */
            i = 0;
            while (ptr < end_ptr)
            {
                *ptr++ = 'a' + (i++);
                if (i>25)
                    i=0;
            }
            break;
        case DATA_TYPE_ZERO:
            /* Fill the rest of the packet with zeros */
            while (ptr < end_ptr) *ptr++ = 0;
            break;
        case DATA_TYPE_ONE:
            /* Fill the rest of the packet with ones */
            while (ptr < end_ptr) *ptr++ = 1;
            break;
        default:
        case DATA_TYPE_INC:
            /* Fill the rest of the packet with incrementing bytes */
            i = 0;
            while (ptr < end_ptr) *ptr++ = i++ & 0xff;
            break;
        case DATA_TYPE_DEC:
            /* Fill the rest of the packet with decrementing bytes */
            i = 0;
            while (ptr < end_ptr) *ptr++ = --i & 0xff;
            break;
        case DATA_TYPE_RAND:
            /* Fill the rest of the packet with random bytes */
            while (ptr < end_ptr) *ptr++ = rand();
            break;
    }
    if (port_setup[port].validate)
    {
        int end_l2 = get_end_l2(port);
        ptr = packet + end_l2;
        *(uint32_t*)(end_ptr-4) = crc32c(ptr, end_ptr - ptr - 4, 0xffffffff);
    }
}

#define MAX_COMMAND 256
#define MAX_ARGUMENTS 8

#define MAX_HISTORY_LOG2 (8)
#define MAX_HISTORY (1<<MAX_HISTORY_LOG2)
#define MAX_HISTORY_MASK (MAX_HISTORY-1)
#define DEBUG_ESCAPE 0

static char command_history[MAX_HISTORY][MAX_COMMAND] = {{0,},};
static int history_index = 0;
static int history_lookup_index = 0;
static unsigned int cmd_len = 0;
static unsigned int cmd_pos = 0;
static char *cmd;
static int escape_saw_char=0;
static int escape_mode = 0;
static int find_mode = 0;
static int find_orig_cmd_pos = 0;
static int search_mode = 0;
static int was_lookup = 0;
static int debug_value = 0;
#define BIT_POS_SHOW_LOOKUP 0
#define BIT_MASK_SHOW_LOOKUP (1<<BIT_POS_SHOW_LOOKUP)
static int insert_mode = 0;
static int delete_mode = 0;
static int overwrite_once = 0;
static char **saved_avail_p = NULL;
static int saved_suffix_size = 0;
static int tab_mode = 0;
static char pattern[MAX_COMMAND] = {0,};
static int pattern_dir_delta=-1;
static int pattern_dir_reverse=0;
typedef struct {
    char cmd[MAX_COMMAND];
    unsigned int cmd_len;
    unsigned int cmd_pos;
} undo_t;
static undo_t undo = {{0,},0,0};

typedef struct
{
    char        str[MAX_COMMAND];
    uint64_t    number;
    float       number_float;
} argument_info_t;


/**
 * Parse a command into a its arguments
 *
 * @param cmd    Command to parse
 * @param args   Output of the arguments
 * @return Number of arguments
 */
static int parse_command(const char *cmd, argument_info_t args[MAX_ARGUMENTS])
{
    int num_args = 0;

    args[num_args].str[0] = 0;
    args[num_args].number = 0;
    args[num_args].number_float = 0;

    while (*cmd)
    {
        if (*cmd != ' ')
        {
            int len = strlen(args[num_args].str);
            args[num_args].str[len] = *cmd;
            args[num_args].str[len+1] = 0;
            cmd++;
        }

        if ((*cmd == ' ') || (*cmd == 0))
        {
            uint64_t number = 0;
            float number_float = 0;

            if ((args[num_args].str[0] == '0') && (args[num_args].str[1] == 'x'))
            {
                /* Starts with 0x, so assume argument is a hex number */
#ifdef BDK_ABI_N32
                if (sscanf(args[num_args].str+2, "%llx", &number) != 1)
                    printf("Parse error on argument: %s\n", args[num_args].str);
#else
                if (sscanf(args[num_args].str+2, "%lx", &number) != 1)
                    printf("Parse error on argument: %s\n", args[num_args].str);
#endif
            }
            else if (strchr(args[num_args].str, '.'))
            {
                /* There are periods in it. Assume it is an IP address or floating point number. */
                unsigned int p1, p2, p3, p4;
                float f1;
                if (sscanf(args[num_args].str, "%u.%u.%u.%u", &p1, &p2, &p3, &p4) == 4)
                    number = (p1<<24) | (p2<<16) | (p3<<8) | p4;
                else if (sscanf(args[num_args].str, "%f", &f1) == 1)
                    number_float = f1;
            }
            else if (strchr(args[num_args].str, ':'))
            {
                /* Colons, assume it is hex bytes */
                unsigned int b;
                unsigned int count;
                const char *ptr = args[num_args].str;
                while (*ptr && sscanf(ptr, "%x%n", &b, &count))
                {
                    number = (number<<8) | b;
                    ptr += count;
                    if (*ptr == ':')
                        ptr++;
                }
            }
            else
            {
                /* Don't have any idea, so try the automatic conversion */
#ifdef BDK_ABI_N32
                sscanf(args[num_args].str, "%lli", &number);
#else
                sscanf(args[num_args].str, "%li", &number);
#endif
            }

            args[num_args].number = number;
            args[num_args].number_float = number_float;
            num_args++;
            args[num_args].str[0] = 0;

            while (*cmd == ' ')
                cmd++;
        }
    }

    return num_args;
}

void show_editing_help()
{
    printf(SCROLL_FULL);
    printf(GOTO_TOP ERASE_EOS);
    printf("\nMany vi style modes are available for command and history navigation.\n");
    printf("Use ARROW KEYS, HOME, END or ESC-h,ESC-j,ESC-k,ESC-l,ESC-0,ESC-$,ESC-w,ESC-b, or ESC-fx for navigation.\n");
    printf("Use TAB for commmand completion, multiple to cycle, or CTRL-D for a list of possible commands.\n");
    printf("Use ESC-i,ESC-A,ESC-a,ESC-c for insert mode, ESC-R,ESC-r for overwrite mode (behavior like vi).\n");
    printf("Use INSERT to toggle insert/overwrite mode, DELETE to delete, F1 for help.\n");
    printf("Use !!, !<num> or !<string> to repeat previous commands in the history.\n");
    printf("Use ::, :<num> or :<string> to recall previous commands in the history to current.\n");
    printf("Use ?<string>, /<string>, ESC-?<string>,ESC-/<string>,ESC-n,ESC-N to also recall to current.\n");
    printf("Use CTRL-l erase the screen, ESC-D to clear the rest of the current line.\n");
    printf("Use ESC-d<movement> to delete, ESC-~ to change case, ESC-u to undo (one level).\n");
    printf("See the vi man page for more info on the operation of various commands.\n");
    printf("\nNote: If you don't see any statistics, you may have hidden or frozen them.\n");
    printf("\nNote: This program works best with a very wide and tall terminal window.\n");
}

void show_next_leftover_help_page()
{
    int help_lines;

    if (leftover_help.help_string_p==NULL) return;

    printf(SCROLL_FULL);
    printf(GOTO_TOP ERASE_EOS);
    if (leftover_help.help_prefix_length>0)
        printf("Available Commands starting with '%s'", leftover_help.help_prefix);
    else
        printf("Available Commands");
    printf(": (case insensitive) -- continued.\n  Note: [<port range>] means [<first port> [<last port>]]\n\n");

    for (help_lines=0; *leftover_help.help_string_p; leftover_help.help_string_p++) {
        if (strncasecmp(*leftover_help.help_string_p, leftover_help.help_prefix, leftover_help.help_prefix_length)==0) {
            if (++help_lines > leftover_help.max_help_lines) {
                break;
            }
            printf("%s",*leftover_help.help_string_p);
        }
    }
    if (*leftover_help.help_string_p == NULL) {
        printf("\nType <enter> or any command to continue.\n");
        leftover_help.help_string_p = NULL;
    }
}


/**
 * Interruptable wait and perform periodic updates
 *
 * @param ms     Wait time in ms
 */
static int wait(uint64_t ms)
{
    uint64_t finish = cpu_clock_hz * ms / 1000 + bdk_clock_get_count(BDK_CLOCK_CORE);
    while (bdk_clock_get_count(BDK_CLOCK_CORE) < finish)
    {
        periodic_update(0);
        int c = uart_read_byte(0);
        if (c == '\003')
            return -1;
    }
    return 0;
}


/**
 * Transmit packets and see if all of them are received again
 *
 * @param tx_port
 * @param rx_port
 * @param rate
 * @param test_time
 * @return
 */
static int test_forward(int tx_port, int rx_port, int rate, int test_time)
{
    const uint64_t SETTLE_TIME = 1100;  /* ms */
    int result = -2;
    int tx_port1;
    int tx_port2;
    int rx_port1;
    int rx_port2;
    int port;
    uint64_t original_count[BDK_PIP_NUM_INPUT_PORTS];
    uint64_t start_count;
    uint64_t stop_count;
    uint64_t start_arps;
    uint64_t stop_arps;

    /* Figure out the range of ports to transmit on */
    if (tx_port == -1)
    {
        tx_port1 = default_start_port;
        tx_port2 = default_stop_port;
    }
    else
    {
        tx_port1 = tx_port;
        tx_port2 = tx_port;
    }

    /* Figure out the range of ports to receive on */
    if (rx_port == -1)
    {
        rx_port1 = default_start_port;
        rx_port2 = default_stop_port;
    }
    else
    {
        rx_port1 = rx_port;
        rx_port2 = rx_port;
    }

    for (port=tx_port1; port<=tx_port2; port++)
    {
        /* Save the original output counts so we don't bother the users */
        original_count[port] = port_setup[port].output_count;
        /* Setup the transmitter rate */
        port_setup[port].output_count = rate * test_time;
        port_setup[port].output_cycle_gap = (cpu_clock_hz << CYCLE_SHIFT) / rate;
    }

    BDK_SYNCW;

    for (port=rx_port1; port<=rx_port2; port++)
    {
        /* Wait for RX to be idle */
        do
        {
            start_count = port_state[port].input_cumulative_packets;

            if (wait(100))
                goto cleanup;

            stop_count = port_state[port].input_cumulative_packets;
        } while (start_count != stop_count);
    }

    /* Get the sum of packets for all rx ports */
    start_count = 0;
    start_arps = 0;
    for (port=rx_port1; port<=rx_port2; port++)
    {
        start_count += port_state[port].input_cumulative_packets;
        start_arps += port_state[port].input_arp_requests;
    }

    /* Start the TX */
    for (port=tx_port1; port<=tx_port2; port++)
        port_setup[port].output_enable = 1;
    BDK_SYNCW;

    /* Wait for TX to be complete */
    while (port_setup[tx_port1].output_enable)
    {
        periodic_update(0);
        int c = uart_read_byte(0);
        if (c == '\003')
            goto cleanup;
    }

    /* Extra delay to let counters settle */
    if (wait(SETTLE_TIME))
        goto cleanup;

    /* Get the RX stats */
    stop_count = 0;
    stop_arps = 0;
    for (port=rx_port1; port<=rx_port2; port++)
    {
        stop_count += port_state[port].input_cumulative_packets;
        stop_arps += port_state[port].input_arp_requests;
    }

    /* Check the RX stats */
    if (stop_count - start_count == (ULL)rate * test_time * (tx_port2-tx_port1+1) + (stop_arps - start_arps))
        result = 0;
    else
        result = -1;

cleanup:
    for (port=tx_port1; port<=tx_port2; port++)
    {
        port_setup[port].output_enable = 0;
        port_setup[port].output_count = original_count[port];
    }
    BDK_SYNCW;

    return result;
}

/**
 * Find the max packet rate where all packets transmitted are received.
 *
 * @param tx_port Transmit port
 * @param rx_port Receive port
 */
static uint64_t process_cmd_find_max(int tx_port, int rx_port)
{
    const uint64_t TEST_TIME = 10;      /* seconds */
    uint64_t granularity;  /* packet/s */

    int config_port = tx_port;
    if (config_port == -1)
        config_port = default_start_port;
    int interface = bdk_helper_get_interface_num(config_port);
    uint64_t max_mbps = 0;

    switch (bdk_helper_interface_get_mode(interface))
    {
        case BDK_HELPER_INTERFACE_MODE_DISABLED:
        case BDK_HELPER_INTERFACE_MODE_PCIE:
            /* Something is wrong */
            max_mbps = 0;
            break;
        case BDK_HELPER_INTERFACE_MODE_LOOP:
        case BDK_HELPER_INTERFACE_MODE_NPI:
        case BDK_HELPER_INTERFACE_MODE_SRIO:
        case BDK_HELPER_INTERFACE_MODE_XAUI:
            /* Try and do 10Gbps on these ports */
            max_mbps = 10000;
            break;
        case BDK_HELPER_INTERFACE_MODE_SGMII:
        case BDK_HELPER_INTERFACE_MODE_PICMG:
            /* Try and do 1Gbps on these ports */
            max_mbps = 1000;
            break;
    }

    if (max_mbps == 0)
    {
        printf("Unable to determine max speed\n");
        return -1;
    }

    uint64_t high = max_mbps * 125000 / (port_setup[config_port].output_packet_size + get_size_wire_overhead(config_port));
    uint64_t low = 0;
    uint64_t rate = high;

    printf("Performing binary search to find max packet rate\n"
           "Hit Control-C to interrupt\n");

    do
    {
        if (tx_port != -1)
            printf("Trying %llu packets/s\n", (ULL)rate);
        else
            printf("Trying %llu packets/s, total %llu packets/s\n", (ULL)rate, (ULL)rate * (default_stop_port-default_start_port+1));

        /* Do a short 1sec test for quick failure checking */
        int result = test_forward(tx_port, rx_port, rate, 1);
        if (result == -2)
            return -1;

        /* Do longer test if short test passed */
        if (result == 0)
        {
            result = test_forward(tx_port, rx_port, rate, TEST_TIME);
            if (result == -2)
                return -1;
        }

        /* Figure out the next speed */
        if (result == 0)
        {
            /* Passed, need more data */
            low = rate;
            rate = (high + rate) / 2;
        }
        else
        {
            /* Failed, need less data */
            /* Don't do a true binary search, only reduce top by half. This
                way we can recover from false failures caused by glitches */
            high = (high + rate) / 2;
            rate = (rate + low) / 2;
        }

        /* At low rates, be more accurate */
        if (rate > 10000)
            granularity = 1000;  /* packet/s */
        else
            granularity = 100;  /* packet/s */

        rate = (rate / granularity) * granularity;
        if (rate == low)
            break;
    } while (high > low);

    uint64_t mbps = (((low * (port_setup[config_port].output_packet_size + get_size_wire_overhead(config_port))) << 3) + 500000) / 1000000;

    if (tx_port != -1)
        printf("Find max return %llu packets/s (%llu Mbps)\n", (ULL)low, (ULL)mbps);
    else
        printf("Find max return %llu packets/s (%llu Mbps), total %llu packet/s (%llu Mbps)\n", (ULL)low, (ULL)mbps, (ULL)low * (default_stop_port-default_start_port+1), (ULL)mbps * (default_stop_port-default_start_port+1));
    return low;
}


static void update_statistics(void);
#define SS_MAX_SIZE 65524
#define SS_MIN_SIZE 60
static uint64_t process_cmd_scan_packet_sizes(int tx_port, int rx_port, int min_size, int max_size, int inc_size, int packet_count)
{
    int size = 0;
    int port;
    int tx_port1;
    int tx_port2;
    int rx_port1;
    int rx_port2;
    uint64_t original_count[BDK_PIP_NUM_INPUT_PORTS];
    uint64_t start_count;
    uint64_t stop_count;
    uint64_t old_stop_count;
    uint64_t start_bytes;
    uint64_t stop_bytes;

    /* Figure out the range of ports to transmit on */
    if (tx_port == -1)
    {
        tx_port1 = default_start_port;
        tx_port2 = default_stop_port;
    }
    else
    {
        tx_port1 = tx_port;
        tx_port2 = tx_port;
    }

    /* Figure out the range of ports to receive on */
    if (rx_port == -1)
    {
        rx_port1 = default_start_port;
        rx_port2 = default_stop_port;
    }
    else
    {
        rx_port1 = rx_port;
        rx_port2 = rx_port;
    }
    /* Set defaults for sizes */
    if (min_size == -1)
        min_size = SS_MIN_SIZE;
    if (max_size == -1)
        max_size = SS_MAX_SIZE;
    if (inc_size == -1)
        inc_size = 1;

    if (packet_count < 1)
        packet_count = 100;

    if (min_size < SS_MIN_SIZE)
    {
        min_size = SS_MIN_SIZE;
        printf("Forcing minimum packet size to be at least %d bytes\n", min_size);
    }
    if (max_size > SS_MAX_SIZE)
    {
        max_size = SS_MAX_SIZE;
        printf("Limiting maximum packet size to be %d bytes\n", max_size);
    }
    if (max_size < min_size)
    {
        printf("Minimum packet size must be smaller than maximum size\n");
        return 0;
    }


    printf("Scanning all packet sizes from %d to %d\n"
           "Hit Control-C to interrupt\n", min_size, max_size);

    /* Save the original output counts so we don't bother the users */
    for (port=tx_port1; port<=tx_port2; port++)
        original_count[port] = port_setup[port].output_count;

    for (size=min_size; size<=max_size; size += inc_size)
    {
        /* Setup the TX */
        for (port=tx_port1; port<=tx_port2; port++)
        {
            /* Setup the transmitter count */
            port_setup[port].output_count = packet_count;
            port_setup[port].output_packet_size = size;
            port_setup[port].output_enable = 0;
            /* If the speed was set as a percentage we need to update the rate */
            if (port_setup[port].output_percent_x1000)
                update_cycle_gap(port);
            build_packet(port);
        }
        BDK_SYNCW;

        /* Get the sum of packets for all rx ports */
        start_count = 0;
        start_bytes = 0;
        for (port=rx_port1; port<=rx_port2; port++)
        {
            start_count += port_state[port].input_cumulative_packets;
            start_bytes += port_state[port].input_cumulative_octets;
        }

        /* We need to wait here due to a race condition between the packet
            count being updated and TX enable. Without this wait the last port
            may mistakenly use a count of zero and get stuck transmitting */
        bdk_wait_usec(1);

        /* Start the TX */
        for (port=tx_port1; port<=tx_port2; port++)
            port_setup[port].output_enable = 1;
        BDK_SYNCW;

        /* Wait for TX to be complete */
        while (port_setup[tx_port1].output_enable)
        {
            periodic_update(0);
            int c = uart_read_byte(0);
            if (c == '\003')
                goto cleanup;
        }

        /* Wait for RX counters to stabalize */
        stop_count = 0;
        do
        {
            if (wait(1))
                goto cleanup;
            update_statistics();
            /* Get the RX stats */
            old_stop_count = stop_count;
            stop_count = 0;
            stop_bytes = 0;
            for (port=rx_port1; port<=rx_port2; port++)
            {
                stop_count += port_state[port].input_cumulative_packets;
                stop_bytes += port_state[port].input_cumulative_octets;
            }
        } while (stop_count != old_stop_count);

        printf("size=%u, count=%llu, bytes=%llu\n", size, (ULL)stop_count - start_count, (ULL)stop_bytes - start_bytes);

        uint64_t expected_packets = (unsigned long long)packet_count * (tx_port2-tx_port1+1);
        uint64_t expected_bytes = expected_packets * (size+ETHERNET_CRC);

        /* Check the RX stats */
        if ((stop_count - start_count == expected_packets) && (stop_bytes - start_bytes == expected_bytes))
        {
            //printf("Packet size scan succeeded at %u\n", size);
        }
        else
        {
            printf("Packet size scan failed at %u\n", size);
            goto cleanup;
        }
    }
cleanup:
    for (port=tx_port1; port<=tx_port2; port++)
    {
        port_setup[port].output_enable = 0;
        port_setup[port].output_count = original_count[port];
    }
    BDK_SYNCW;
    return size;
}


/**
 * Clear the statistics for a port range
 *
 * @param start_port first port
 * @param stop_port  last port
 */
static void process_cmd_clear(int start_port, int stop_port)
{
    int port;
    int i;

    for (port=start_port; port<=stop_port; port++)
    {
        port_state[port].input_cumulative_packets = 0;
        port_state[port].input_cumulative_octets = 0;
        port_state[port].input_cumulative_errors = 0;
        port_state[port].output_cumulative_octets = 0;
        port_state[port].output_cumulative_packets = 0;
        port_state[port].output_arp_requests = 0;
        port_state[port].output_arp_replies = 0;
        port_state[port].input_arp_requests = 0;
        port_state[port].input_arp_replies = 0;
        port_state[port].input_validation_errors = 0;
        for (i=0; i<256;i++)
            port_state[port].wqe_receive_errors[i] = 0;
    }
}


/**
 * Reset a port range to the startup setting
 *
 * @param start_port first port
 * @param stop_port  last port
 */
static void process_cmd_reset(int start_port, int stop_port)
{
    int port;
    uint64_t mac_addr_base = bdk_config_get(BDK_CONFIG_MAC_ADDRESS, 0xdeadbeef00);

    for (port=start_port; port<=stop_port; port++)
    {
        int connect_to_port = port + 1;
        int interface = bdk_helper_get_interface_num(port);
        if ((port != bdk_helper_get_first_ipd_port(interface)) &&
            (connect_to_port > bdk_helper_get_last_ipd_port(interface)))
            connect_to_port = bdk_helper_get_first_ipd_port(interface);

        port_setup[port].output_enable              = 0;
        port_setup[port].output_packet_type         = PACKET_TYPE_IPV4_UDP;
        port_setup[port].output_packet_payload      = DATA_TYPE_ABC;
        port_setup[port].input_arp_reply_enable     = 1;
        port_setup[port].input_arp_request_enable   = 1;
        port_setup[port].output_packet_size         = 64 - ETHERNET_CRC;
        port_setup[port].output_count               = 0;
        port_setup[port].output_percent_x1000       = 100000;
        port_setup[port].src_mac                    = mac_addr_base + port;
	port_setup[port].src_mac_inc		    =0;
	port_setup[port].src_mac_min		    = mac_addr_base + (port << 16);
	port_setup[port].src_mac_max		    = mac_addr_base + 64 + (port << 16);
        port_setup[port].dest_mac                   = mac_addr_base + connect_to_port;
        port_setup[port].dest_mac_inc               = 0;
        port_setup[port].dest_mac_min               = mac_addr_base + (connect_to_port << 16);
        port_setup[port].dest_mac_max               = mac_addr_base + 64 + (connect_to_port << 16);
        port_setup[port].vlan_size                  = 0;
        port_setup[port].src_ip                     = 0x0a000063 | (port<<16);        /* 10.port.0.99 */
        port_setup[port].src_ip_min                 = 0x0a000000 | (port<<16);        /* 10.port.0.0 */;
        port_setup[port].src_ip_max                 = 0x0a000063 | (port<<16);        /* 10.port.0.99 */;
        port_setup[port].src_ip_inc                 = 0;
        port_setup[port].dest_ip                    = 0x0a000063 | (connect_to_port<<16);   /* 10.connect_to_port.0.99 */
        port_setup[port].dest_ip_min                = 0x0a000000 | (connect_to_port<<16);   /* 10.connect_to_port.0.0 */;
        port_setup[port].dest_ip_max                = 0x0a000063 | (connect_to_port<<16);   /* 10.connect_to_port.0.99 */;
        port_setup[port].dest_ip_inc                = 0;
        port_setup[port].src_port                   = 4096;
        port_setup[port].src_port_min               = 0;
        port_setup[port].src_port_max               = 65535;
        port_setup[port].src_port_inc               = 0;
        port_setup[port].dest_port                  = 4097;
        port_setup[port].dest_port_min              = 0;
        port_setup[port].dest_port_max              = 65535;
        port_setup[port].dest_port_inc              = 0;
        port_setup[port].output_arp_reply_enable    = 1;
        port_setup[port].ip_tos                     = 0;
        port_setup[port].do_checksum                = 0;
        port_setup[port].bridge_port                = BRIDGE_OFF;
        port_setup[port].display_packet             = 0;
        port_setup[port].promisc                    = 1;
        update_cycle_gap(port);
        build_packet(port);
    }
    process_cmd_clear(start_port, stop_port);
}

static void process_cmd_packetio(int enable)
{
    if (!enable)
    {
        if (bdk_helper_shutdown_packet_io_global())
            printf("bdk_helper_shutdown_packet_io_global() failed\n");
        return;
    }

    if (bdk_helper_initialize_packet_io_global())
        printf("bdk_helper_initialize_packet_io_global() failed\n");

    /* Enable RED so we drop if the RX path can't keep up */
    if (!bdk_is_simulation())
    {
        uint64_t num_packet_buffers = BDK_CSR_READ(BDK_IPD_QUE0_FREE_PAGE_CNT);
        bdk_helper_setup_red(num_packet_buffers/4, num_packet_buffers/8);
    }

    BDK_CSR_WRITE(BDK_PIP_IP_OFFSET, PIP_IP_OFFSET);

    /* Change the IPD buffering mode to buffer all packets into L2. This
        yields better performance with high speed interface at the expense
        of our code/data getting flushed from L2. Luckily traffic-gen
        doesn't have much code or data in the fastpath */
    bdk_ipd_ctl_status_t ipd_ctl_reg;
    ipd_ctl_reg.u64 = BDK_CSR_READ(BDK_IPD_CTL_STATUS);
    ipd_ctl_reg.s.opc_mode = BDK_IPD_OPC_MODE_STF;
    BDK_CSR_WRITE(BDK_IPD_CTL_STATUS, ipd_ctl_reg.u64);

    int num_interfaces = bdk_helper_get_number_of_interfaces();
    int interface;
    for (interface=0; interface < num_interfaces; interface++)
    {
        int port;
        int num_ports = bdk_helper_ports_on_interface(interface);
        bdk_helper_interface_mode_t imode = bdk_helper_interface_get_mode(interface);
        /* Skip interfaces with no ports */
        if (num_ports <= 0)
            continue;
        switch (imode)
        {
            /* These types don't support ports to IPD/PKO */
            case BDK_HELPER_INTERFACE_MODE_DISABLED:
            case BDK_HELPER_INTERFACE_MODE_PCIE:
            case BDK_HELPER_INTERFACE_MODE_PICMG:
            case BDK_HELPER_INTERFACE_MODE_NPI:
            case BDK_HELPER_INTERFACE_MODE_LOOP:
            case BDK_HELPER_INTERFACE_MODE_SRIO:
                break;
            case BDK_HELPER_INTERFACE_MODE_SGMII:
            case BDK_HELPER_INTERFACE_MODE_XAUI:
                for (port=0; port<num_ports; port++)
                    BDK_CSR_WRITE(BDK_GMXX_RXX_JABBER(port,interface), 65535);
                BDK_CSR_MODIFY(pip_frm_len_chkx, BDK_PIP_FRM_LEN_CHKX(interface),
                    pip_frm_len_chkx.s.minlen = 64;
                    pip_frm_len_chkx.s.maxlen = -1);
                break;
        }

        for (port=0; port<num_ports; port++)
        {
            int ipd_port = bdk_helper_get_ipd_port(interface, port);

            /* Enable storing short packets only in the WQE */
            bdk_pip_prt_cfgx_t port_cfg;
            port_cfg.u64 = BDK_CSR_READ(BDK_PIP_PRT_CFGX(ipd_port));
            port_cfg.s.dyn_rs = 1;
            BDK_CSR_WRITE(BDK_PIP_PRT_CFGX(ipd_port), port_cfg.u64);
            /* Only the first two interfaces and four ports are used for
                backpressure. Interfaces with more than 4 ports, like SPI4, use
                only port 0 */
            if ((interface < 2) && (port < 4))
            {
                /* Set if incomming backpressure is respected by PKO */
                bdk_gmxx_rxx_frm_ctl_t frm_ctl;
                frm_ctl.u64 = BDK_CSR_READ(BDK_GMXX_RXX_FRM_CTL(port, interface));
                frm_ctl.s.ctl_bck = port_setup[ipd_port].respect_backpressure;
                BDK_CSR_WRITE(BDK_GMXX_RXX_FRM_CTL(port,interface), frm_ctl.u64);
            }
        }
    }
}
#if 0 // FIXME
static void process_cmd_csr(const char *name, int is_write, uint64_t write_value)
{
    const BDK_CSR_DB_ADDRESS_TYPE *csr = bdk_csr_db_get(bdk_get_proc_id(), name);
    if (!csr)
    {
        printf("CSR Not found\n");
        return;
    }

    /* We don't support CSRs that aren't in IO space (bit 48 set) */
    if (((csr->address & (1ull<<48)) == 0) &&
        (csr->type != BDK_CSR_DB_TYPE_PCICONFIGEP) &&
        (csr->type != BDK_CSR_DB_TYPE_PCICONFIGRC) &&
        (csr->type != BDK_CSR_DB_TYPE_SRIOMAINT))
    {
        printf("CSR %s: This utility can't access CSRs of this type\n", csr->name);
        return;
    }

    /* Determine if we're doing a read or a write */
    if (is_write)
    {
        if ((csr->type == BDK_CSR_DB_TYPE_PCICONFIGEP) || (csr->type == BDK_CSR_DB_TYPE_PCICONFIGRC))
        {
            /* Names are of the format "PCIE??#_CFG???". The # is the pcie port number */
            int pcie_port = (csr->name[6] - '0');
            if (octeon_has_feature(OCTEON_FEATURE_NPEI))
            {
                bdk_pescx_cfg_wr_t pescx_cfg_wr;
                pescx_cfg_wr.u64 = 0;
                pescx_cfg_wr.s.addr = csr->address;
                pescx_cfg_wr.s.data = write_value;
                BDK_CSR_WRITE(BDK_PESCX_CFG_WR(pcie_port), pescx_cfg_wr.u64);
            }
            else
            {
                bdk_pemx_cfg_wr_t pemx_cfg_wr;
                pemx_cfg_wr.u64 = 0;
                pemx_cfg_wr.s.addr = csr->address;
                pemx_cfg_wr.s.data = write_value;
                BDK_CSR_WRITE(BDK_PEMX_CFG_WR(pcie_port), pemx_cfg_wr.u64);
            }
        }
        else if (csr->type == BDK_CSR_DB_TYPE_SRIOMAINT)
        {
            /* Names are of the format "SRIOMAINT#_*". The # is the srio port number */
            int srio_port = (csr->name[9] - '0');
            if (bdk_srio_config_write32(srio_port, 0, -1, 0, 0, csr->address, write_value))
                printf("SRIO access failed\n");
        }
        else if (csr->widthbits == 32)
            bdk_write64_uint32((csr->address | (1ull<<63)) ^ 4, write_value);
        else
            BDK_CSR_WRITE(csr->address | (1ull<<63), write_value);
    }
    else
    {
        uint64_t value;
        if ((csr->type == BDK_CSR_DB_TYPE_PCICONFIGEP) || (csr->type == BDK_CSR_DB_TYPE_PCICONFIGRC))
        {
            /* Names are of the format "PCIE??#_CFG???". The # is the pcie port number */
            int pcie_port = (csr->name[6] - '0');
            if (octeon_has_feature(OCTEON_FEATURE_NPEI))
            {
                bdk_pescx_cfg_rd_t pescx_cfg_rd;
                pescx_cfg_rd.u64 = 0;
                pescx_cfg_rd.s.addr = csr->address;
                BDK_CSR_WRITE(BDK_PESCX_CFG_RD(pcie_port), pescx_cfg_rd.u64);
                pescx_cfg_rd.u64 = BDK_CSR_READ(BDK_PESCX_CFG_RD(pcie_port));
                value = 0xffffffffull & pescx_cfg_rd.s.data;
            }
            else
            {
                bdk_pemx_cfg_rd_t pemx_cfg_rd;
                pemx_cfg_rd.u64 = 0;
                pemx_cfg_rd.s.addr = csr->address;
                BDK_CSR_WRITE(BDK_PEMX_CFG_RD(pcie_port), pemx_cfg_rd.u64);
                pemx_cfg_rd.u64 = BDK_CSR_READ(BDK_PEMX_CFG_RD(pcie_port));
                value = 0xffffffffull & pemx_cfg_rd.s.data;
            }
        }
        else if (csr->type == BDK_CSR_DB_TYPE_SRIOMAINT)
        {
            /* Names are of the format "SRIOMAINT#_*". The # is the srio port number */
            int srio_port = (csr->name[9] - '0');
            uint32_t result;
            if (bdk_srio_config_read32(srio_port, 0, -1, 0, 0, csr->address, &result))
            {
                printf("SRIO access failed\n");
                return;
            }
            value = result;
        }
        else if (csr->widthbits == 32)
            value = bdk_read64_uint32((csr->address | (1ull<<63)) ^ 4);
        else
            value = BDK_CSR_READ(csr->address | (1ull<<63));
        bdk_csr_db_decode_by_name(bdk_get_proc_id(), csr->name, value);
    }
}
#endif
/**
 * Process a command from the user
 *
 * @param cmd     Command to process
 * @param newline Print a newline if set
 */
static uint64_t process_command(const char *cmd, int newline)
{
    argument_info_t args[MAX_ARGUMENTS];
    char *command;
    uint64_t port;
    uint64_t value;
    float value_float = 0;
    uint64_t start_port;
    uint64_t stop_port;
    char *next_command=0;
    uint64_t command_result = 0;


    SET_SCROLL_REGION(max_displayed_row);
    printf(GOTO_BOTTOM);

    do {
        if (next_command) {
            next_command[0] = ';';      /* replace ';' in command */
            cmd = next_command+1;
        }
        next_command = strchr(cmd,';');
        while (next_command && (next_command[-1] == '\\')) {
            next_command = strchr(next_command+1,';'); /* ignore quoted semicolons */
        }
        if (next_command) next_command[0] = '\0';       /* terminate command at ';' */

        while (*cmd == ' ') cmd++;      /* skip leading spaces */

        int argc = parse_command(cmd, args);
        command = args[0].str;

        switch (argc)
        {
            case 0:
                continue;
            case 1:
                start_port = default_start_port;
                stop_port = default_stop_port;
                value = 0;
                value_float = 0;
                break;
            case 2:
                start_port = default_start_port;
                stop_port = default_stop_port;
                value = args[1].number;
                value_float = args[1].number_float;
                break;
            case 3:
                start_port = args[1].number;
                stop_port = args[1].number;
                value = args[2].number;
                value_float = args[2].number_float;
                break;
            case 4:
                start_port = args[1].number;
                stop_port = args[2].number;
                value = args[3].number;
                value_float = args[3].number_float;
                break;
            default:
#if 0
                if (strcasecmp(command, "alias") != 0) return;  /* for now only alias has >4 params */
#endif
                start_port = args[1].number;
                stop_port = args[2].number;
                value = args[3].number;
        }

        if (newline) printf("\n");

#define CHECK_ALIASES_FIRST
#ifdef CHECK_ALIASES_FIRST
        {
            /* check alias list */
            int remaining_aliases = num_aliases;
            int i;

            for (i=0; remaining_aliases>0 && i<MAX_ALIAS; i++) {
                char *aname=alias[i].name;
                if (aname[0] != 0) {
                    if (strcasecmp(aname,command)==0) { /* found a match */
                        if (argc>1) {
                            char my_command[MAX_COMMAND*2];
                            char *p = strchr(cmd,' ');
                            /* process the rest of the commands in the new context. */
                            if (next_command) {
                                *next_command = ';';
                                next_command = 0;
                            }
                            sprintf(my_command,"%s %s",alias[i].command, p);
                            process_command(my_command,0);
                        }
                        else {
                            process_command(alias[i].command,0);
                        }
                        break;
                    }
                    remaining_aliases--;
                }
            }
            if (remaining_aliases > 0) continue;
        }
#endif

    #define PORT_LIMIT(PORT)                                        \
        if ((PORT) >= BDK_PIP_NUM_INPUT_PORTS) {                   \
            printf("Invalid port %llu, assuming %d\n",              \
                   (ULL)(PORT), BDK_PIP_NUM_INPUT_PORTS-1);        \
            PORT = BDK_PIP_NUM_INPUT_PORTS-1;                      \
        }
    #define PORT_RANGE_COMMAND(NAME, FIELD, VALUE)                  \
        else if (strcasecmp(command, NAME) == 0)                    \
        {                                                           \
            if (argc == 2)                                          \
                stop_port = start_port = value;                     \
            if (argc >= 3)                                          \
                stop_port = value;                                  \
            if (strstr(cmd,"all")) {                                \
                start_port=0;                                       \
                stop_port=BDK_PIP_NUM_INPUT_PORTS-1;               \
            }                                                       \
            PORT_LIMIT(start_port);                                 \
            PORT_LIMIT(stop_port);                                  \
            for (port=start_port; port<=stop_port; port++)          \
                FIELD = VALUE;                                      \
        }
    #define PORT_VALUE_COMMAND(NAME, FIELD)                         \
        else if (strcasecmp(command, NAME) == 0)                    \
        {                                                           \
            PORT_LIMIT(start_port);                                 \
            PORT_LIMIT(stop_port);                                  \
            for (port=start_port; port<=stop_port; port++)          \
                if (argc >= 2)                                      \
                {                                                   \
                    FIELD = value;                                  \
                    build_packet(port);                             \
                }                                                   \
                else if (port_state[port].display) {                \
                    printf("Port %2llu %s: %22llu 0x%016llx\n",     \
                           (ULL)port, NAME, (ULL)FIELD, (ULL)FIELD);\
                    command_result = FIELD;                         \
                }                                                   \
        }

    #define PORT_INSERT_COMMAND(NAME, FIELD)                        \
        else if (strcasecmp(command, NAME) == 0)                    \
        {                                                           \
            PORT_LIMIT(start_port);                                 \
            PORT_LIMIT(stop_port);                                  \
            for (port=start_port; port<=stop_port; port++) {        \
                if (argc >= 2)                                      \
                {                                                   \
                    char *p = strrchr(cmd,' ');                     \
                    if ((p == NULL) || (strcasecmp(p," off")==0)) { \
                        FIELD##_size = 0;                           \
                    }                                               \
                    else {                                          \
                        int nybbles = strlen(cmd) - (++p-cmd);      \
                        int bytes = (nybbles+1)/2;                  \
                        if (bytes > MAX_INSERT)                     \
                            printf("Too many bytes in '%s' for %s (%d>%d)\n",\
                                    p,NAME,bytes,MAX_INSERT);       \
                        else {                                      \
                            char input_nybbles[MAX_INSERT*2+1],*vp; \
                            int vi,byte;                            \
                            FIELD##_size = bytes;                   \
                            input_nybbles[0] = '0';                 \
                            input_nybbles[MAX_INSERT*2] = '\0';     \
                            strncpy(input_nybbles + (nybbles&1), p, MAX_INSERT*2);\
                            vp = input_nybbles;                     \
                            for (vi=0; vi<bytes; vi++) {            \
                                sscanf(vp,"%02x",&byte);            \
                                vp += 2;                            \
                                FIELD[vi] = byte;                   \
                            }                                       \
                        }                                           \
                    }                                               \
                    build_packet(port);                             \
                }                                                   \
                else if (port_state[port].display) {                \
                    int vi;                                         \
                    printf("Port %2llu %s: ",(ULL)port, NAME);      \
                    for (vi=0; vi<(int)FIELD##_size; vi++)          \
                        printf("%02x", FIELD[vi]);                  \
                    printf(" (size = %llu bytes)\n", (ULL)FIELD##_size);  \
                }                                                   \
            }                                                       \
        }


    #define PORT_STATISTIC_COMMAND(NAME, FIELD)                     \
        else if (strcasecmp(command, NAME) == 0)                    \
        {                                                           \
            if (argc == 2)                                          \
                stop_port = start_port = value;                     \
            if (argc >= 3)                                          \
                stop_port = value;                                  \
            if (strstr(cmd,"all")) {                                \
                start_port=0;                                       \
                stop_port=BDK_PIP_NUM_INPUT_PORTS-1;               \
            }                                                       \
            PORT_LIMIT(start_port);                                 \
            PORT_LIMIT(stop_port);                                  \
            for (port=start_port; port<=stop_port; port++)          \
                if (port_state[port].display) {                     \
                    printf("Port %2llu %s: %22llu\n", (ULL)port,    \
                           NAME, (ULL)port_state[port].FIELD);      \
                    command_result = port_state[port].FIELD;        \
                }                                                   \
        }

    #define PORT_IP_COMMAND(NAME, FIELD)                            \
        else if (strcasecmp(command, NAME) == 0)                    \
        {                                                           \
            PORT_LIMIT(start_port);                                 \
            PORT_LIMIT(stop_port);                                  \
            for (port=start_port; port<=stop_port; port++) {        \
                if (argc >= 2)                                      \
                {                                                   \
                    FIELD = value;                                  \
                    build_packet(port);                             \
                }                                                   \
                if (port_state[port].display) {                     \
                    printf("Port %2llu %s: 0x%08llx %d.%d.%d.%d\n", \
                           (ULL)port, NAME, (ULL)FIELD,             \
                           (uint8_t)(FIELD>>24),                    \
                           (uint8_t)(FIELD>>16),                    \
                           (uint8_t)(FIELD>>8),                     \
                           (uint8_t)(FIELD));                       \
                    command_result = FIELD;                         \
                }                                                   \
            }                                                       \
        }

    #define PORT_RANGE_LUT_COMMAND(NAME, FIELD, LUT)                            \
        else if (strcasecmp(command, NAME) == 0)                                \
        {                                                                       \
            int type=0;                                                         \
            char *p = strrchr(cmd,' ');                                         \
            if (p) {                                                            \
                p++;                                                            \
                if (isalpha(*p)) argc--;                                        \
                                                                                \
                switch (argc)                                                   \
                {                                                               \
                    case 1:                                                     \
                        start_port = default_start_port;                        \
                        stop_port = default_stop_port;                          \
                        break;                                                  \
                    case 2:                                                     \
                        start_port = args[1].number;                            \
                        stop_port = args[1].number;                             \
                        break;                                                  \
                    case 3:                                                     \
                    default:                                                    \
                        start_port = args[1].number;                            \
                        stop_port = args[2].number;                             \
                        break;                                                  \
                }                                                               \
                while (LUT[type]) {                                             \
                    if (strcasecmp(p, LUT[type]) == 0) {                        \
                        if (strcasecmp(p,"help") == 0)                          \
                            while (LUT[type]) type++;                           \
                        break;                                                  \
                    }                                                           \
                    type++;                                                     \
                }                                                               \
                PORT_LIMIT(start_port);                                         \
                PORT_LIMIT(stop_port);                                          \
                if (LUT[type]) {                                                \
                    for (port=start_port; port<=stop_port; port++)              \
                    {                                                           \
                        FIELD = type;                                           \
                        build_packet(port);                                     \
                    }                                                           \
                }                                                               \
                else {                                                          \
                    if (strcasecmp(p,"show") == 0) {                            \
                        for (port=start_port; port<=stop_port; port++)          \
                            printf("Port %2llu " NAME ": %s\n",(ULL)port,LUT[FIELD]); \
                        printf("\n");                                           \
                    }                                                           \
                    else {                                                      \
                        printf(NAME " types:");                                 \
                        for(type=0;  LUT[type]; type++) printf(" %s",LUT[type]);\
                        printf(" (show)\n");                                    \
                    }                                                           \
                }                                                               \
            }                                                                   \
            else {                                                              \
                printf("Missing space before " NAME " type.\n");                \
            }                                                                   \
        }

    #define ROW_RANGE_COMMAND(NAME, FIELD, INVERT)                             \
        else if (strcasecmp(command, NAME) == 0)                               \
        {                                                                      \
            unsigned int start_row=0, end_row=0, row, row_and=1, row_or=0;     \
            char *p = strrchr(cmd,' ');                                        \
            if (p)                                                             \
            {                                                                  \
                p++;                                                           \
                if (!isalpha(*p)) p=NULL;                                      \
            }                                                                  \
            printf(GOTO_TOP ERASE_EOS);                                        \
            switch (argc) {                                                    \
                case 1:                                                        \
                    start_row = 1;                                             \
                    end_row = MAX_ROW;                                         \
                    break;                                                     \
                case 2:                                                        \
                    if (p) { start_row = 1; end_row = MAX_ROW; break; }        \
                    start_row = args[1].number;                                \
                    end_row = args[1].number+1;                                \
                    break;                                                     \
                case 3:                                                        \
                    if (p) {                                                   \
                        start_row = args[1].number;                            \
                        end_row = args[1].number+1;                            \
                        break;                                                 \
                    }                                                          \
                    /* else fall through */                                    \
                case 4:                                                        \
                    start_row = args[1].number;                                \
                    end_row = args[2].number+1;                                \
                    break;                                                     \
                default:                                                       \
                    start_row = 0;                                             \
                    end_row = 0;                                               \
                    printf("Too many arguments");                              \
                    break;                                                     \
            }                                                                  \
            if (start_row > MAX_ROW) start_row = MAX_ROW;                      \
            if (end_row > MAX_ROW) end_row = MAX_ROW;                          \
            if (p && strcasecmp(p, "off") == 0) {                              \
               if (INVERT) row_or=1;                                           \
               else row_and=0;                                                 \
            }                                                                  \
            else if (p && strcasecmp(p, "on") == 0) {                          \
                if (INVERT) row_and=0;                                         \
                else row_or=1;                                                 \
            }                                                                  \
            if (p && strcasecmp(p,"min")==0 && strcasecmp(command,"row")==0) { \
                force_min=1;                                                   \
            }                                                                  \
            else for (row=start_row; row<end_row; row++) {                     \
                FIELD ^= 1;                                                    \
                FIELD &= row_and;                                              \
                FIELD |= row_or;                                               \
            }                                                                  \
        }

        if (strcasecmp(command, "clear") == 0)
        {
            if (argc == 2)
                stop_port = start_port = value;
            if (argc >= 3)
                stop_port = value;
            if (strstr(cmd,"all")) {
                start_port=0;
                stop_port=BDK_PIP_NUM_INPUT_PORTS-1;
            }
            PORT_LIMIT(start_port);
            PORT_LIMIT(stop_port);
            process_cmd_clear(start_port, stop_port);
        }
        else if (strcasecmp(command, "clearall") == 0)
        {
            process_cmd_clear(0, BDK_PIP_NUM_INPUT_PORTS-1);
            if (last_start_total_display_updates != TIMESTAMP_INVALID) {
                last_start_total_display_updates = total_display_updates;
            }
            sending_time = 0;
        }
        else if (strcasecmp(command, "reset") == 0)
        {
            if (argc == 2)
                stop_port = start_port = value;
            if (argc >= 3)
                stop_port = value;
            if (strstr(cmd,"all")) {
                start_port=0;
                stop_port=BDK_PIP_NUM_INPUT_PORTS-1;
            }
            PORT_LIMIT(start_port);
            PORT_LIMIT(stop_port);
            process_cmd_reset(start_port, stop_port);
        }
        ROW_RANGE_COMMAND("row", row_state[row].hidden, 1)
        ROW_RANGE_COMMAND("hli", row_state[row].highlight, 0)
        else if (strcasecmp(command, "freeze") == 0) {
            char *p = strrchr(cmd,' ');
            frozen ^= 1;
            if (p) {
                if (strcasecmp(p, " on") == 0) frozen=1;
                else if (strcasecmp(p, " off") == 0) frozen=0;
            }
        }
        else if (strcasecmp(command, "default") == 0)
        {
            if (argc >= 2) {
                default_start_port = args[1].number;
                default_stop_port = args[1].number;
            }
            if (argc >= 3) {
                default_stop_port = args[2].number;
            }
            PORT_LIMIT(default_start_port);
            PORT_LIMIT(default_stop_port);
            printf("Default ports %u .. %u\n", default_start_port, default_stop_port);
        }
        else if (strcasecmp(command, "tx.rate") == 0)
        {
            PORT_LIMIT(start_port);
            PORT_LIMIT(stop_port);
            for (port=start_port; port<=stop_port; port++)
            {
                if (argc >= 2)
                {
                    if (value)
                        port_setup[port].output_cycle_gap = (cpu_clock_hz << CYCLE_SHIFT) / value;
                    else
                        port_setup[port].output_cycle_gap = 0;
                    port_setup[port].output_percent_x1000 = 0;
                }
                else if (port_state[port].display)
                {
                    uint64_t packet_rate;
                    if (port_setup[port].output_cycle_gap)
                        packet_rate = (cpu_clock_hz << CYCLE_SHIFT) / port_setup[port].output_cycle_gap;
                    else
                        packet_rate = 0;
                    printf("Port %2llu %s: %9llu\n", (ULL)port, "tx.rate", (ULL)packet_rate);
                    command_result = packet_rate;
                }
            }
        }
        else if (strcasecmp(command, "tx.percent") == 0)
        {
            PORT_LIMIT(start_port);
            PORT_LIMIT(stop_port);
            for (port=start_port; port<=stop_port; port++)
            {
                if (argc >= 2)
                {
                    if (value_float)
                        port_setup[port].output_percent_x1000 = value_float * 1000;
                    else
                        port_setup[port].output_percent_x1000 = value * 1000;
                    update_cycle_gap(port);
                }
                else if (port_state[port].display)
                {
                    uint64_t packet_rate;
                    if (port_setup[port].output_cycle_gap)
                        packet_rate = (cpu_clock_hz << CYCLE_SHIFT) / port_setup[port].output_cycle_gap;
                    else
                        packet_rate = 0;
                    uint64_t percent = packet_rate * (port_setup[port].output_packet_size + get_size_wire_overhead(port)) / 1250000;
                    printf("Port %2llu %s: %3llu\n", (ULL)port, "tx.percent", (ULL)percent);
                    command_result = percent;
                }
            }
        }
        else if (strcasecmp(command, "tx.size") == 0)
        {
            /* Octeon will TX packets up to 65528 (65532 with CRC) but can't
                receive them. 65524 + 4 is the large we can receive */
            if (value > 65524)
            {
                value = 65524;
                printf("Max size supported is %d bytes (%d with CRC)\n", (int)value, (int)value+4);
            }
            PORT_LIMIT(start_port);
            PORT_LIMIT(stop_port);
            for (port=start_port; port<=stop_port; port++)
                if (argc >= 2)
                {
                    if (value + get_size_pre_l2(port) > 65524)
                    {
                        port_setup[port].output_packet_size = 65524 - get_size_pre_l2(port);
                        printf("Limiting port %d to %d of payload due to Higig header\n",
                            (int)port, (int)port_setup[port].output_packet_size);
                    }
                    else
                        port_setup[port].output_packet_size = value;
                    if (port_setup[port].output_percent_x1000)
                        update_cycle_gap(port);
                    build_packet(port);
                }
                else if (port_state[port].display)
                {
                    printf("Port %2llu %s: %8llu 0x%04llx\n",
                            (ULL)port, "tx.size", (ULL)port_setup[port].output_packet_size, (ULL)port_setup[port].output_packet_size);
                    command_result = port_setup[port].output_packet_size;
                }
        }
        else if (strncasecmp(command, "tx.data[", 8) == 0)
        {
            int index = 0;
            sscanf(command, "tx.data[%i]", &index);
            PORT_LIMIT(start_port);
            PORT_LIMIT(stop_port);
            for (port=start_port; port<=stop_port; port++)
            {
                if (argc >= 2)
                    ((uint64_t *)port_setup[port].output_data)[index] = value;
                else if (port_state[port].display)
                    printf("Port %2llu tx.data[%7d]: %22llu 0x%016llx\n", (ULL)port, index,
                            (ULL)((uint64_t *)port_setup[port].output_data)[index],
                            (ULL)((uint64_t *)port_setup[port].output_data)[index]);
            }
        }
        else if (strcasecmp(command, "find.max") == 0)
        {
            if (argc == 3)
                command_result = process_cmd_find_max(start_port, value);
            else if ((argc == 2) && (strcmp(args[1].str,"default") == 0))
                command_result = process_cmd_find_max(-1, -1);
            else
                printf("Requires two arguments, the TX and RX ports or \"default\"\n");
        }
        else if (strcasecmp(command, "scan.sizes") == 0)
        {
            /* Initialize all arguments to use the defaults */
            int ss_start_port = -1;
            int ss_end_port = -1;
            int max_size = -1;
            int min_size = -1;
            int inc_size = -1;
            int count = -1;

            if (argc > 6 + !!strcmp(args[1].str,"default") || argc < 2)
            {
                printf("Requires two arguments (6 max), the TX and RX ports or \"default\", optional min_size, max_size, size increment, and packet count.\n");
            }
            else
            {
                int size_arg_index = 2;  /* Arg index at which size arguments start */
                if (strcmp(args[1].str,"default"))
                {
                    /* We have port arguments */
                    ss_start_port = args[1].number;
                    ss_end_port = args[2].number;
                    PORT_LIMIT(ss_start_port);
                    PORT_LIMIT(ss_end_port);
                    size_arg_index++;
                }

                if (argc - 1 >= size_arg_index)
                    min_size = args[size_arg_index++].number;
                if (argc - 1 >= size_arg_index)
                    max_size = args[size_arg_index++].number;
                if (argc - 1 >= size_arg_index)
                    inc_size = args[size_arg_index++].number;
                if (argc - 1 >= size_arg_index)
                    count = args[size_arg_index++].number;

                command_result = process_cmd_scan_packet_sizes(ss_start_port, ss_end_port, min_size, max_size, inc_size, count);
            }
        }
        PORT_RANGE_LUT_COMMAND("tx.payload",   port_setup[port].output_packet_payload, tx_payload_lut)
        PORT_RANGE_LUT_COMMAND("tx.type",      port_setup[port].output_packet_type, tx_packet_type_lut)
        PORT_RANGE_COMMAND("stop",      port_setup[port].output_enable, 0)
        PORT_RANGE_COMMAND("start",     port_setup[port].output_enable, 1)
        PORT_RANGE_COMMAND("show",      port_state[port].display, 1)
        PORT_RANGE_COMMAND("hide",      port_state[port].display, 0)
        PORT_VALUE_COMMAND("tx.count",  port_setup[port].output_count)
        PORT_VALUE_COMMAND("dest.mac",  port_setup[port].dest_mac)
 	PORT_VALUE_COMMAND("dest.mac.inc",port_setup[port].dest_mac_inc)
        PORT_VALUE_COMMAND("dest.mac.min",port_setup[port].dest_mac_min)
        PORT_VALUE_COMMAND("dest.mac.max",port_setup[port].dest_mac_max)
    	PORT_VALUE_COMMAND("src.mac.inc",port_setup[port].src_mac_inc)
        PORT_VALUE_COMMAND("src.mac.min",port_setup[port].src_mac_min)
        PORT_VALUE_COMMAND("src.mac.max",port_setup[port].src_mac_max)

        PORT_INSERT_COMMAND("tx.vlan",  port_setup[port].vlan)
        PORT_VALUE_COMMAND("ip.tos",    port_setup[port].ip_tos)
        PORT_IP_COMMAND("src.ip",       port_setup[port].src_ip)
        PORT_VALUE_COMMAND("src.ip.inc",port_setup[port].src_ip_inc)
        PORT_IP_COMMAND("src.ip.min",   port_setup[port].src_ip_min)
        PORT_IP_COMMAND("src.ip.max",   port_setup[port].src_ip_max)
        PORT_IP_COMMAND("dest.ip",      port_setup[port].dest_ip)
        PORT_VALUE_COMMAND("dest.ip.inc",port_setup[port].dest_ip_inc)
        PORT_IP_COMMAND("dest.ip.min",   port_setup[port].dest_ip_min)
        PORT_IP_COMMAND("dest.ip.max",   port_setup[port].dest_ip_max)
        PORT_VALUE_COMMAND("src.port",  port_setup[port].src_port)
        PORT_VALUE_COMMAND("src.port.inc",  port_setup[port].src_port_inc)
        PORT_VALUE_COMMAND("src.port.min",  port_setup[port].src_port_min)
        PORT_VALUE_COMMAND("src.port.max",  port_setup[port].src_port_max)
        PORT_VALUE_COMMAND("dest.port", port_setup[port].dest_port)
        PORT_VALUE_COMMAND("dest.port.inc", port_setup[port].dest_port_inc)
        PORT_VALUE_COMMAND("dest.port.min", port_setup[port].dest_port_min)
        PORT_VALUE_COMMAND("dest.port.max", port_setup[port].dest_port_max)
        PORT_STATISTIC_COMMAND("tx.packets", output_statistics.packets)
        PORT_STATISTIC_COMMAND("tx.octets", output_statistics.octets)
        PORT_STATISTIC_COMMAND("tx.mbps", output_Mbps)
        PORT_STATISTIC_COMMAND("tx.total_packets", output_cumulative_packets)
        PORT_STATISTIC_COMMAND("tx.total_octets", output_cumulative_octets)
        PORT_STATISTIC_COMMAND("rx.packets", input_statistics.inb_packets)
        PORT_STATISTIC_COMMAND("rx.octets", input_statistics.inb_octets)
        PORT_STATISTIC_COMMAND("rx.mbps", input_Mbps)
        PORT_STATISTIC_COMMAND("rx.total_packets", input_cumulative_packets)
        PORT_STATISTIC_COMMAND("rx.total_octets", input_cumulative_octets)
        PORT_STATISTIC_COMMAND("rx.total_errors", input_cumulative_errors)
        PORT_STATISTIC_COMMAND("rx.validation_errors", input_validation_errors)
        else if (strcasecmp(command, "higig") == 0)
        {
            PORT_LIMIT(start_port);
            PORT_LIMIT(stop_port);
            if ((argc >= 2) && (value!=12) && (value!=16))
                printf("higig must be 12 (higig), or 16 (higig2)\n");
            else
            {
                for (port=start_port; port<=stop_port; port++)
                {
                    if (argc >= 2)
                    {
                        port_setup[port].higig = value;
                        bdk_higig_initialize(port>>4, (port_setup[port].higig == 16));
                        build_packet(port);
                    }
                    else if (port_state[port].display) {
                        printf("Port %2llu %s: %22llu 0x%016llx\n",
                               (ULL)port, "higig", (ULL)port_setup[port].higig, (ULL)port_setup[port].higig);
                        command_result = port_setup[port].higig;
                    }
                }
            }
        }
        else if (strcasecmp(command, "src.mac") == 0)
        {
            int interface;
            PORT_LIMIT(start_port);
            PORT_LIMIT(stop_port);
            for (port=start_port; port<=stop_port; port++)
                if (argc >= 2)
                {
                    interface = 0;
                    if (port >= 16)
                        interface = 1;
                    port_setup[port].src_mac = value;
                    if (!port_setup[port].promisc)
                        cvm_oct_set_mac_address(interface, port - interface*16, &(port_setup[port].src_mac));
                    build_packet(port);
                }
                else if (port_state[port].display) {
                    printf("Port %2llu %s: %22llu 0x%016llx\n",
                           (ULL)port, "src.mac", (ULL)port_setup[port].src_mac, (ULL)port_setup[port].src_mac);
                    command_result = port_setup[port].src_mac;
                }
        }
        else if (strcasecmp(command, "rx.promisc") == 0)
        {
            int interface;
            PORT_LIMIT(start_port);
            PORT_LIMIT(stop_port);
            for (port=start_port; port<=stop_port; port++)
                if (argc >= 2 && strcmp(args[argc-1].str, "show"))
                {
                    interface = 0;
                    if (port >= 16)
                        interface = 1;

                    if (strcmp(args[argc-1].str, "off") == 0)
                        port_setup[port].promisc = 0;
                    else if (strcmp(args[argc-1].str, "on") == 0)
                        port_setup[port].promisc = 1;
                    else
                        port_setup[port].promisc = value;

                    if (port_setup[port].promisc)
                        cvm_oct_set_mac_address(interface, port - interface*16, NULL);
                    else
                        cvm_oct_set_mac_address(interface, port - interface*16, &(port_setup[port].src_mac));
                }
                else if (port_state[port].display || !strcmp(args[argc-1].str, "show")) {
                    printf("Port %2llu %s: %22llu 0x%016llx\n",
                           (ULL)port, "rx.promisc", (ULL)port_setup[port].promisc, (ULL)port_setup[port].promisc);
                    command_result = port_setup[port].promisc;
                }
        }
        else if (strcasecmp(command, "bridge") == 0)
        {
            PORT_LIMIT(start_port);
            PORT_LIMIT(stop_port);
            for (port=start_port; port<=stop_port; port++)
            {
                if (argc >= 2)
                {
                    PORT_LIMIT(value);
                    if (strcmp(args[argc-1].str, "off") == 0)
                        port_setup[port].bridge_port = BRIDGE_OFF;
                    else
                        port_setup[port].bridge_port = value;
                }
                else if (port_state[port].display)
                {
                    if (port_setup[port].bridge_port != BRIDGE_OFF)
                        printf("Port %2llu %s: %d\n", (ULL)port, "bridge", port_setup[port].bridge_port);
                    else
                        printf("Port %2llu %s: off\n", (ULL)port, "bridge");
                }
            }
        }
        else if (strcasecmp(command, "debug") == 0) {
            if (argc>=2) debug_value = value;
            printf("Debug = 0x%08x\n", debug_value);
        }
        else if (strcasecmp(command, "csr") == 0)
        {
#if 0 // FIXME
            process_cmd_csr(args[1].str, (argc == 3), args[2].number);
#endif
        }
        else if (strcasecmp(command, "cls") == 0) {
            printf(GOTO_TOP ERASE_EOS);
        }
        else if (strcasecmp(command, "reboot") == 0) {
            /* Turn off the scrolling region so the full terminal is used after the reboot */
            printf(CURSOR_OFF SCROLL_FULL GOTO_BOTTOM CURSOR_ON);
            /* Perform a chip wide soft reset */
            bdk_reset_octeon();
        }
        else if (strcasecmp(command, "history") == 0) {
            int start_line, end_line;
            switch (argc) {
                case 1:
                    start_line = 0;
                    end_line = MAX_HISTORY;
                    break;
                case 2:
                    start_line = args[1].number;
                    end_line = args[1].number+1;
                    break;
                case 3:
                    start_line = args[1].number;
                    end_line = args[2].number+1;
                    break;
                default:
                    start_line = 0;
                    end_line = 0;
                    printf("Too many arguments\n");
                    break;
            }
            while ((start_line != end_line) && (command_history[start_line][0] != 0)) {
                printf("Command%4d: %s\n", start_line, command_history[start_line]);
                start_line++;
            }
        }
#if 0 // FIXME
        else if (strcasecmp(command, "ixf.miiread") == 0) {
            if (bdk_sysinfo_get()->board_type == BDK_BOARD_TYPE_EBT5810)
            {
                if (argc == 4) {
                    int val = bdk_ixf18201_mii_read(args[1].number, args[2].number, args[3].number);
                    printf("MII addr %d, mmd %d, reg 0x%04x: 0x%04x\n", (int)args[1].number, (int)args[2].number, (int)args[3].number, val);
                }
                else {
                    printf("Incorrect number of arguments.\n");
                }
            }
            else
                printf("ERROR: this command only supported on the ebt5810 board\n");
        }
        else if (strcasecmp(command, "ixf.miiwrite") == 0) {
            if (bdk_sysinfo_get()->board_type == BDK_BOARD_TYPE_EBT5810)
            {
                if (argc == 5) {
                    bdk_ixf18201_mii_write(args[1].number, args[2].number, args[3].number, args[4].number);
                }
                else {
                    printf("Incorrect number of arguments.\n");
                }
            }
            else
                printf("ERROR: this command only supported on the ebt5810 board\n");
        }
        else if (strcasecmp(command, "ixf.read") == 0) {
            if (bdk_sysinfo_get()->board_type == BDK_BOARD_TYPE_EBT5810)
            {
                if (argc == 2) {
                    uint16_t val = bdk_ixf18201_read16(args[1].number);
                    printf("IXF reg 0x%04x: 0x%04x\n", (uint32_t)args[1].number, val);
                }
                else {
                    printf("Incorrect number of arguments.\n");
                }
            }
            else
                printf("ERROR: this command only supported on the ebt5810 board\n");
        }
        else if (strcasecmp(command, "ixf.write") == 0) {
            if (bdk_sysinfo_get()->board_type == BDK_BOARD_TYPE_EBT5810)
            {
                if (argc == 3) {

                    bdk_ixf18201_write16(args[1].number, args[2].number);
                    printf("Writing 0x%04x to ixf reg 0x%04x\n", (uint32_t)args[2].number, (uint32_t)args[1].number);

                }
                else {
                    printf("Incorrect number of arguments.\n");
                }
            }
            else
                printf("ERROR: this command only supported on the ebt5810 board\n");
        }
        else if (strcasecmp(command, "ixf.read32") == 0) {
            if (bdk_sysinfo_get()->board_type == BDK_BOARD_TYPE_EBT5810)
            {
                if (argc == 2) {
                    uint32_t val = bdk_ixf18201_read32(args[1].number);
                    printf("IXF reg 0x%04x: 0x%08x\n", (uint32_t)args[1].number, val);
                }
                else {
                    printf("Incorrect number of arguments.\n");
                }
            }
            else
                printf("ERROR: this command only supported on the ebt5810 board\n");
        }
        else if (strcasecmp(command, "ixf.write32") == 0) {
            if (bdk_sysinfo_get()->board_type == BDK_BOARD_TYPE_EBT5810)
            {
                if (argc == 3) {
                    bdk_ixf18201_write32(args[1].number, args[2].number);
                    printf("Writing 0x%04x to ixf reg 0x%04x\n", (uint32_t)args[2].number, (uint32_t)args[1].number);

                }
                else {
                    printf("Incorrect number of arguments.\n");
                }
            }
            else
                printf("ERROR: this command only supported on the ebt5810 board\n");
        }
#endif
        else if (strcasecmp(command, "mii.read") == 0) {
            int mii_value;

            if (argc == 3) {
                int bus_id = !!(args[1].number & 0x80);
                mii_value = bdk_mdio_read(bus_id, args[1].number, args[2].number);
                if (mii_value < 0) {
                    printf("Read error from device %u(0x%x)\n", (int)args[1].number, (int)args[1].number);
                }
                else {
                    printf("Device %d(0x%x) reg %d(0x%x) = 0x%04x\n", (int)args[1].number, (int)args[1].number, (int)args[2].number, (int)args[2].number, mii_value);
                }
            }
            else {
                printf("Incorrect number of arguments.\n");
            }
        }
        else if (strcasecmp(command, "mii.write") == 0) {
            int status;

            if (argc == 4) {
                int bus_id = !!(args[1].number & 0x80);
                status = bdk_mdio_write(bus_id, args[1].number, args[2].number, args[3].number);
                if (status < 0) {
                    printf("Write error to device %d(0x%x)\n", (int)args[1].number, (int)args[1].number);
                }
                else {
                    printf("Device %d(0x%x) reg %d(0x%x) <- 0x%04x\n", (int)args[1].number, (int)args[1].number, (int)args[2].number, (int)args[2].number, (int)args[3].number);
                }
            }
            else {
                printf("Incorrect number of arguments.\n");
            }
        }
        else if (strcasecmp(command, "mii45.read") == 0) {
            int mii_value;

            if (argc == 4) {
                int bus_id = !!(args[1].number & 0x80);
                mii_value = bdk_mdio_45_read(bus_id, args[1].number, args[2].number, args[3].number);
                if (mii_value < 0) {
                    printf("Read error from device %u(0x%x) mmd %d(0x%x)\n", (int)args[1].number, (int)args[1].number, (int)args[2].number, (int)args[2].number);
                }
                else {
                    printf("Device %d(0x%x) mmd %d(0x%x) reg %d(0x%x) = 0x%04x\n", (int)args[1].number, (int)args[1].number, (int)args[2].number, (int)args[2].number, (int)args[3].number, (int)args[3].number, mii_value);
                }
            }
            else {
                printf("Incorrect number of arguments.\n");
            }
        }
        else if (strcasecmp(command, "mii45.write") == 0) {
            int status;

            if (argc == 5) {
                int bus_id = !!(args[1].number & 0x80);
                status = bdk_mdio_45_write(bus_id, args[1].number, args[2].number, args[3].number, args[4].number);
                if (status < 0) {
                    printf("Write error to device %u(0x%x) mmd %d(0x%x)\n", (int)args[1].number, (int)args[1].number, (int)args[2].number, (int)args[2].number);
                }
                else {
                    printf("Device %d(0x%x) mmd %d(0x%x) reg %d(0x%x) <- 0x%04x\n", (int)args[1].number, (int)args[1].number, (int)args[2].number, (int)args[2].number, (int)args[3].number, (int)args[3].number, (int)args[4].number);
                }
            }
            else {
                printf("Incorrect number of arguments.\n");
            }
        }
        else if (strcasecmp(command, "phy.speed") == 0) {
            int i;
            bdk_helper_link_info_t link_info;
            bdk_helper_board_set_phy_link_flags_types_t link_flags = 0;
            link_info.u64 = 0;
            link_info.s.link_up = 1;
            for (i=1; i<argc; i++)
            {
                if ((args[i].number == 10) || (args[i].number == 100) || (args[i].number == 1000))
                    link_info.s.speed = args[i].number;
                else if (!strcasecmp(args[i].str, "auto"))
                    link_flags |= set_phy_link_flags_autoneg;
                else if (!strcasecmp(args[i].str, "full"))
                    link_info.s.full_duplex = 1;
                else if (!strcasecmp(args[i].str, "half"))
                    link_info.s.full_duplex = 0;
                else if (!strcasecmp(args[i].str, "pause"))
                     link_flags |= set_phy_link_flags_flow_control_enable;
                else if (!strcasecmp(args[i].str, "nopause"))
                     link_flags |= set_phy_link_flags_flow_control_disable;
            }
            PORT_LIMIT(start_port);
            PORT_LIMIT(stop_port);
            for (port=start_port; port<=stop_port; port++)
            {
                if (argc >= 2)
                {
                    int phy_addr = 0; // FIXME bdk_helper_board_get_mii_address(port);
                    if (phy_addr >= 0)
                    {
                        printf("Port %2llu: enable_autoneg=%d, speed=%d, duplex=%d\n", (ULL)port, !!(link_flags & set_phy_link_flags_autoneg), link_info.s.speed, link_info.s.full_duplex);
                        bdk_helper_board_link_set_phy(phy_addr, link_flags, link_info);
                    }
                    else
                        printf("Port %2llu doesn't have a PHY address\n", (ULL)port);
                }
                else if (port_state[port].display)
                {
                    bdk_helper_link_info_t link_info;
                    link_info = bdk_helper_link_get(port);
                    printf("Port %2llu: %dMbps %s duplex\n", (ULL)port,
                           link_info.s.speed, (link_info.s.full_duplex) ? "full" : "half");
                    command_result = link_info.s.speed;
                }
            }
        }
        PORT_RANGE_LUT_COMMAND("tx.arp.reply",   port_setup[port].output_arp_reply_enable, on_off_lut)
        PORT_RANGE_LUT_COMMAND("rx.arp.request", port_setup[port].input_arp_request_enable, on_off_lut)
        PORT_RANGE_LUT_COMMAND("rx.arp.reply",   port_setup[port].input_arp_reply_enable, on_off_lut)
        PORT_RANGE_LUT_COMMAND("tx.checksum",    port_setup[port].do_checksum, on_off_lut)
        PORT_RANGE_LUT_COMMAND("rx.display",     port_setup[port].display_packet, on_off_error_lut)
        PORT_RANGE_LUT_COMMAND("validate",       port_setup[port].validate, on_off_lut)
        else if (strcasecmp(command, "loopback") == 0) {
            if (argc >= 2)
            {
                PORT_LIMIT(start_port);
                PORT_LIMIT(stop_port);
                for (port=start_port; port<=stop_port; port++)
                {
                    int internal = args[argc-1].str[0] == 'i';
                    int external = (args[argc-1].str[0] == 'e') || (args[argc-1].str[9] == 'e');
                    if (bdk_helper_configure_loopback(port, internal, external))
                        printf("Setting loopback for port %llu failed\n", (ULL)port);
                }
            }
            else
                printf("Loopback can only be set, not displayed\n");
        }
        else if (strcasecmp(command, "backpressure") == 0)
        {
            PORT_LIMIT(start_port);
            PORT_LIMIT(stop_port);
            for (port=start_port; port<=stop_port; port++)
            {
                if (argc >= 2)
                {
                    PORT_LIMIT(value);
                    if (strcmp(args[argc-1].str, "off") == 0)
                        port_setup[port].respect_backpressure = 0;
                    else
                        port_setup[port].respect_backpressure = 1;
                    int interface = bdk_helper_get_interface_num(port);
                    if (interface < 2)
                    {
                        int index = bdk_helper_get_interface_index_num(port);
                        bdk_gmxx_rxx_frm_ctl_t frm_ctl;
                        frm_ctl.u64 = BDK_CSR_READ(BDK_GMXX_RXX_FRM_CTL(index, interface));
                        frm_ctl.s.ctl_bck = port_setup[port].respect_backpressure;
                        BDK_CSR_WRITE(BDK_GMXX_RXX_FRM_CTL(index, interface), frm_ctl.u64);
                    }
                }
                else if (port_state[port].display)
                    printf("Port %2llu %s: %s\n", (ULL)port, "backpressure", (port_setup[port].respect_backpressure) ? "on" : "off");
            }
        }
        else if (strcasecmp(command, "packetio") == 0)
        {
            if (argc == 2)
            {
                if (strcmp(args[1].str, "on") == 0)
                    process_cmd_packetio(1);
                else if (strcmp(args[1].str, "off") == 0)
                    process_cmd_packetio(0);
                else
                    printf("packetio requires a single argument, either \"on\" or \"off\"\n");
            }
            else
                printf("packetio requires a single argument, either \"on\" or \"off\"\n");
        }
        else if (strcasecmp(command, "arp.request") == 0) {
            uint8_t *buf;
            uint8_t *ptr_src_mac;
            struct arp_t *arp;
            bdk_buf_ptr_t hw_buffer;
            uint16_t ipprt = args[1].number;
            uint32_t ip_addr = args[2].number;
            bdk_pko_command_word0_t pko_command;

            if ((argc != 3) || isalpha(args[2].str[0])) {
                printf("ERROR:  require %s <port> <ip address>\n",command);
                goto arp_request_done;
            }
            if (ipprt > BDK_PIP_NUM_INPUT_PORTS)
            {
                printf("ERROR:  Invalid port (%d)\n",ipprt);
                goto arp_request_done;
            }

            /* get a buffer for output */
            buf = (uint8_t *) bdk_fpa_alloc(BDK_FPA_PACKET_POOL);
            uint8_t *pbuf = buf;

            memset(pbuf, 0xff, MAC_ADDR_LEN);
            pbuf += MAC_ADDR_LEN;

            ptr_src_mac = ((uint8_t *)(&port_setup[ipprt].src_mac)) + 2;  /* assumes big endian and stored in uint64_t */
            memcpy(pbuf, ptr_src_mac, MAC_ADDR_LEN);
            pbuf += MAC_ADDR_LEN;

            memcpy(pbuf,port_setup[ipprt].vlan,port_setup[ipprt].vlan_size);
            pbuf += port_setup[ipprt].vlan_size;

            *pbuf++ = 0x08;
            *pbuf++ = 0x06;
            arp = (struct arp_t *) pbuf;
            arp->hw_type = 0x0001;
            arp->proto = 0x0800;
            arp->hw_addr_len = MAC_ADDR_LEN;
            arp->proto_addr_len = IP_ADDR_LEN;
            arp->opcode = ARP_REQUEST;

            /* this code assumes big endian and uint32_t for ip, and uint64_t for mac's */
            memcpy(arp->src_mac, ptr_src_mac, MAC_ADDR_LEN);
            memcpy(arp->src_ip, &port_setup[ipprt].src_ip, IP_ADDR_LEN);
            memset(arp->dest_mac, 0xff, MAC_ADDR_LEN);
            memcpy(arp->dest_ip, &ip_addr, IP_ADDR_LEN);
            pbuf += sizeof(struct arp_t);

            pko_command.u64 = 0;
            /* pko_command.s.dontfree = 0;      -- already true, but just for emphasis */
            pko_command.s.segs = 1;

            uint64_t queue = bdk_pko_get_base_queue(ipprt) + 1;  /* NOTE: use a different queue than normal */
            bdk_spinlock_lock(&port_lock[ipprt]);
            bdk_pko_send_packet_prepare(ipprt, queue, BDK_PKO_LOCK_NONE);
            hw_buffer.s.addr = bdk_ptr_to_phys(buf);
            hw_buffer.s.pool = BDK_FPA_PACKET_POOL;
            hw_buffer.s.i = 0;
            hw_buffer.s.size = pbuf-buf;
            pko_command.s.total_bytes = pbuf-buf;
            bdk_pko_status_t status = bdk_pko_send_packet_finish(ipprt, queue, pko_command, hw_buffer, BDK_PKO_LOCK_NONE);
            bdk_spinlock_unlock(&port_lock[ipprt]);
            if (status == BDK_PKO_SUCCESS)
                bdk_atomic_add64(&port_state[ipprt].output_arp_requests, 1);
            else
                bdk_fpa_free(buf, BDK_FPA_PACKET_POOL, 0);
arp_request_done: ;
        }
        else if (strcasecmp(command, "editing") == 0) {
            show_editing_help();
        }
        else if (strcasecmp(command, "type") == 0) {
            char *p = strchr(cmd,' ');
            if (p) process_input_type(p+1);
        }
        else if (strcasecmp(command, "alias") == 0) {
            if (argc > 2) {
                if (++num_aliases == MAX_ALIAS) {
                    printf("Too many aliases already, replacing last\n");
                    num_aliases--;
                }
                else {
                    int i, remaining_aliases=num_aliases, hole=num_aliases;

                    for (i=0; remaining_aliases>0 && i<MAX_ALIAS; i++) {
                        char *aname=alias[i].name;

                        if (aname[0] != 0) {
                            if (strcasecmp(aname,args[1].str)==0) { /* found a match */
                                hole=i; /* reuse this entry */
                                num_aliases--;
                                break;
                            }
                            remaining_aliases--;
                        }
                        else {
                            if (hole==num_aliases) hole=i;      /* use smallest hole */
                        }
                    }

                    /* skip first two tokens. */
                    char *p = strchr(cmd,' ');
                    while (p && *p==' ') p++;
                    p = strchr(p,' ');
                    while (p && *p==' ') p++;
                    if (p) {
                        char *q=p;

                        if (*p == '\'') {       /* quoted alias stuff */
                            p++;        /* skip the qoute */
                            if (next_command) {
                                *next_command = ';';
                                q=strchr(p,'\'');
                                if (q > next_command)
                                    next_command = strchr(q,';');       /* look for more commands later */
                                else
                                    *next_command = 0;  /* this was a valid next command */
                            }
                            else {
                                q=strchr(p,'\'');
                            }
                            if ((q==NULL) || ((p-q)>MAX_ALIAS_COMMAND)) q = p + MAX_ALIAS_COMMAND;
                            strncpy(alias[hole].name, args[1].str, MAX_ALIAS_NAME);
                            strncpy(alias[hole].command, p, q-p);
                            alias[hole].command[q-p]=0;
                        }
                        else {
                            /* replace "\;" with " ;" */
                            while ((q=strstr(q,"\\;"))) {
                                *q = ' ';
                            }
                            strncpy(alias[hole].name, args[1].str, MAX_ALIAS_NAME);
                            strncpy(alias[hole].command, p, MAX_ALIAS_COMMAND);
                        }
                        /* make sure they are terminated */
                        alias[hole].name[MAX_ALIAS_NAME]=0;
                        alias[hole].command[MAX_ALIAS_COMMAND]=0;
                    }
                }
            }
            else {
                /* print alias list */
                int remaining_aliases = num_aliases;
                int i;
                char *prefix=args[1].str;

                for (i=0; remaining_aliases>0 && i<MAX_ALIAS; i++) {
                    char *aname=alias[i].name;

                    if (aname[0] != 0) {
                        if (strncasecmp(aname,prefix,strlen(prefix))==0) { /* found a match */
                            printf("%s %s\n",aname,alias[i].command);
                        }
                        remaining_aliases--;
                    }
                }
            }
        }
        else if (strcasecmp(command, "unalias") == 0) {
            /* remove matching aliases */
            int remaining_aliases = num_aliases;
            int i;
            char *name=args[1].str;

            for (i=0; remaining_aliases>0 && i<MAX_ALIAS; i++) {
                char *aname=alias[i].name;

                if (aname[0] != 0) {
                    if (strcasecmp(aname,name)==0) { /* found a match */
                        printf("Removing: %s %s\n",aname,alias[i].command);
                        num_aliases--;
                        aname[0]=0;
                        break;  /* for exact match, only 1 can be removed */
                    }
                    remaining_aliases--;
                }
            }
        }
        else if (strcasecmp(command, "echo") == 0) {
            char *p = strchr(cmd,' ');
            /* need quoted support */
            if (p) {
                printf("%s\n",p+1);
            }
        }
        else
        {
            if (strcasecmp(command, "help") == 0) {
                char **help_string_p;
                char *help_prefix;
                int help_prefix_length=0;
                int max_help_lines=18;

                int help_lines=0;

                printf(SCROLL_FULL);
                printf(GOTO_TOP ERASE_EOS);

                help_prefix = args[argc-1].str; /* assume last argument is prefix */
                if (argc > 2) {
                    max_help_lines = args[1].number;    /* assume first argument is lines */

                    if (isdigit(help_prefix[0])) {      /* if last argument is numeric */
                        max_help_lines = args[argc-1].number;   /* assume last argument is lines */
                        help_prefix = args[1].str;      /* assume first argument is prefix */
                    }
                }
                else if (argc == 2) {
                    if (isdigit(help_prefix[0])) {      /* if first (only) argument is numeric */
                        max_help_lines = args[1].number;        /* assume first argument is lines */
                        help_prefix="";                 /* assume only lines given */
                    }
                }
                if (max_help_lines==0) max_help_lines = 1;

                if (argc > 1) {
                    help_prefix_length = strlen(help_prefix);
                }
                if (leftover_help.help_prefix_length>0)
                    printf("Available Commands starting with '%s': (case insensitive)", leftover_help.help_prefix);
                else
                    printf("Available Commands: (case insensitive)");
                if (help_prefix_length>0) printf("  (starting with '%s')",help_prefix);
                printf("\n  Note: [<port range>] means [<first port> [<last port>]]\n\n");
                for (help_string_p=help_commands; *help_string_p; help_string_p++) {
                    if (strncasecmp(*help_string_p, help_prefix, help_prefix_length)==0) {
                        if (++help_lines > max_help_lines) {
                            leftover_help.help_string_p = help_string_p;
                            leftover_help.max_help_lines = max_help_lines;
                            leftover_help.help_prefix = help_prefix;
                            leftover_help.help_prefix_length = help_prefix_length;
                            break;
                        }
                        printf("%s",*help_string_p);
                    }
                }
                if (strcasecmp("editing", help_prefix)==0) {
                    show_editing_help();
                }
                else {
                    if (argc <= 1) printf("\nNote: use 'help editing' for information on editing commands available.\n");
                }
                if (!help_lines) {
                    printf("No commands were found starting with '%s'.  Try <CTRL-D> to show list.\n",help_prefix);
                }
            }
            else {
#ifndef CHECK_ALIASES_FIRST
                /* check alias list */
                int remaining_aliases = num_aliases;
                int i;

                for (i=0; remaining_aliases>0 && i<MAX_ALIAS; i++) {
                    char *aname=alias[i].name;
                    if (aname[0] != 0) {
                        if (strcasecmp(aname,command)==0) { /* found a match */
                            if (argc>1) {
                                char my_command[MAX_COMMAND*2];
                                char *p = strchr(cmd,' ');
                                /* process the rest of the commands in the new context. */
                                if (next_command) {
                                    *next_command = ';';
                                    next_command = 0;
                                }
                                sprintf(my_command,"%s %s",alias[i].command, p);
                                process_command(my_command,0);
                            }
                            else {
                                process_command(alias[i].command,0);
                            }
                            break;
                        }
                        remaining_aliases--;
                    }
                }
                if (remaining_aliases <= 0)
                    printf("\nUnknown Command '%s'\nUse 'help' or 'alias' to show the available commands.\n",cmd);
#else
                printf("\nUnknown Command '%s'\nUse 'help' or 'alias' to show the available commands.\n",cmd);
#endif
            }
        }
        BDK_SYNCW;

        /* check for enabled ports to perform special sending timestamping */
        if (last_start_total_display_updates == TIMESTAMP_INVALID) { /* currently off, check if someone is now transmitting */
            for (port=0; port<BDK_PIP_NUM_INPUT_PORTS; port++) {
                if (port_setup[port].output_enable) {
                    last_start_total_display_updates = total_display_updates;
                    break;
                }
            }
        }

        if ((strcasecmp(command, "help") == 0) || (strcasecmp(command, "editing") == 0)) {
            if (leftover_help.help_string_p == NULL) {
                printf("\nType <enter> or any command to continue.\n");
            }

            help_frozen = 1;
        }

    } while (next_command);

    printf(CURSOR_OFF SCROLL_FULL GOTO_BOTTOM CURSOR_ON);
    return command_result;
}

static void process_function_key(int function) {
    escape_mode=0;
    escape_saw_char=0;
    if ((function < 1) || (function > 22)) {
        printf ("function key error %d\n",function);
        return;
    }
    printf("<%s>",function_key_commands[function-1]);
    process_command(function_key_commands[function-1],1);
}

void process_input_draw_current()
{
    command_history[history_index][cmd_len] = 0;
    if (leftover_help.help_string_p != NULL) {
        printf(CURSOR_OFF GOTO_BOTTOM "-- Press <space> for next page or <enter> to exit help --");
        return;
    }
    if (debug_value & BIT_MASK_SHOW_LOOKUP) {
        printf(CURSOR_OFF GOTO_BOTTOM "Cmd%4d%4d(%s)> ", history_lookup_index, history_index,
                delete_mode ? "DEL" : find_mode ? "FND" : escape_mode ? "ESC" : insert_mode ? "INS":"OVR");
    }
    else {
        printf(CURSOR_OFF GOTO_BOTTOM "Command%4d(%s)> ", history_index,
                delete_mode ? "DEL" : find_mode ? "FND" : escape_mode ? "ESC" : insert_mode ? "INS":"OVR");
    }

    printf(command_history[history_index]);
    /* Erase to end of line, put cursor at correct pos */
    printf(ERASE_EOL GOTO_BOTTOM_x CURSOR_ON, (int)(cmd_pos + sizeof("Command1234(OVR)> ")));
    return;
}

char *find_token_end(char *token)
{
    char *b;
    char *p=strchr(token,' ');
    if ((b=strchr(token,'[')) && (b<p)) p=b;    /* for 'tx.data[' style case */
    if (p==NULL)
        return (token + strlen(token));
    return (p+1);
}

void process_input_commit_character(char ch) {
    if (insert_mode) {
        if (cmd_len < MAX_COMMAND-1) {
            if (cmd_len > cmd_pos) {
                memmove(&cmd[cmd_pos+1], &cmd[cmd_pos], cmd_len-cmd_pos+1);
            }
            cmd[cmd_pos++] = ch;
            cmd_len++;
            putchar(ch);
        }
    }
    else {      /* overwrite mode */
        if (cmd_pos < MAX_COMMAND-1) {
            cmd[cmd_pos++] = ch;
            if (cmd_pos > cmd_len) cmd_len = cmd_pos;
            putchar(ch);
        }
    }
}

char **next_avail_p(char **avail_p, char **lut)
{
    if (avail_p == NULL) return lut;
    if (*++avail_p == 0) return lut;
    return avail_p;
}

void tab_complete(char *token_start, char **lut)
{       /* find longest common suffix, of those with matching prefixes */
    char **avail_p;
    char *p;
    int suffix_size=-1;
    char *suffix = NULL;
    int offset = cmd_pos - (token_start - cmd);
    int delta_pos=0;
    int printed=0;

    if (tab_mode==1) {
        if (saved_avail_p == NULL) {
            for (saved_avail_p = lut; *saved_avail_p; saved_avail_p++);
            saved_avail_p--;    /* initialize to the one before the end */
        }
        for (avail_p = next_avail_p(saved_avail_p,lut); avail_p != saved_avail_p; avail_p = next_avail_p(avail_p,lut)) {
            if (strncasecmp(token_start, *avail_p, offset)==0) {        /* prefix matches */
                suffix = *avail_p+offset;
                p=find_token_end(suffix);
                suffix_size = p - suffix;
                saved_avail_p = avail_p;
                delta_pos = suffix_size;
                if ((cmd_pos + saved_suffix_size) > MAX_COMMAND-1) {
                    saved_suffix_size=0;        /* this should never happen, but just in case... */
                }
                if ((cmd_pos + saved_suffix_size) > cmd_len) {
                    cmd_len = (cmd_pos + saved_suffix_size);
                }
                if (insert_mode) {
                    memmove(&cmd[cmd_pos], &cmd[cmd_pos+saved_suffix_size], saved_suffix_size);
                    cmd_len -= saved_suffix_size;
                }
                else {  /* in overwrite mode, at least cover leftover junk that we created with spaces */
                    memset(&cmd[cmd_pos], ' ', saved_suffix_size);
                }
                cmd[cmd_len]=0;
                saved_suffix_size = suffix_size;
                break;
            }
        }
    }
    else {
        if (tab_mode==2) printf ("\n");
        for (avail_p = lut; *avail_p && suffix_size; avail_p++) {
            if (strncasecmp(token_start, *avail_p, offset)==0) {        /* prefix matches */
                if (tab_mode==2) {      /* list all */
                    char save;
                    p = find_token_end(*avail_p);
                    save = *p;
                    *p = 0;
                    printf("%s ",*avail_p);
                    *p = save;
                    printed += p - *avail_p;
                    if (printed > 70) {
                        printf("\n");
                        printed = 0;
                    }
                }
                else {
                    if (suffix==NULL) { /* first match */
                        suffix = *avail_p+offset;
                        p=find_token_end(suffix);
                        suffix_size = p - suffix;
                    }
                    else {      /* not first match */
                        while ((suffix_size>0) && (strncasecmp(suffix,*avail_p+offset, suffix_size)!=0)) {
                            suffix_size--;
                        }
                    }
                }
            }
        }
    }
    while (suffix_size > 0) {   /* copy suffix to buffer and echo to output (unless too big) */
        process_input_commit_character(*suffix);
        suffix++;
        suffix_size--;
    }
    cmd_pos -= delta_pos;

    if ((tab_mode==2) && printed) printf ("\n");
    process_input_draw_current();
}

void process_input_change_index(int delta)
{
    int new_index = (history_lookup_index+delta) & MAX_HISTORY_MASK;
    int new_cmd_len = strlen(command_history[new_index]);

    if (new_cmd_len == 0) return;       /* ignore if uncharted */
    history_lookup_index = new_index;
    cmd_len = new_cmd_len;
    cmd_pos = cmd_len;

    strcpy(command_history[history_index], command_history[history_lookup_index]);      /* copy to current command */
    process_input_draw_current();
}

static inline void process_input_change_index_to(int line)
{
    process_input_change_index(line - history_lookup_index);
}

static inline void process_input_change_pos(int delta)
{
    cmd_pos += delta;

    if ((signed)cmd_pos < 0) cmd_pos=0;
    if (cmd_pos > cmd_len) cmd_pos=cmd_len;

    process_input_draw_current();
}

static inline void process_input_up()
{
    process_input_change_index(-1);
}

static inline void process_input_down()
{
    process_input_change_index(+1);
}

static inline void process_input_left()
{
    process_input_change_pos(-1);
}

static inline void process_input_right()
{
    process_input_change_pos(+1);
}

static inline void process_input_save_undo()
{
#if DEBUG_ESCAPE
    printf("\nsave_undo: %d, %d, '%s'\n",cmd_len,cmd_pos,cmd);
#endif
    undo.cmd_len = cmd_len;
    undo.cmd_pos = cmd_pos;
    strncpy(undo.cmd, cmd, MAX_COMMAND);
}

static inline void process_input_undo()
{
    undo_t temp;

#if DEBUG_ESCAPE
    printf("\nundo before: %d, %d, '%s'\n",cmd_len,cmd_pos,cmd);
#endif
    temp.cmd_len = undo.cmd_len;
    temp.cmd_pos = undo.cmd_pos;
    strncpy(temp.cmd, undo.cmd, MAX_COMMAND);

    process_input_save_undo();

    cmd_len = temp.cmd_len;
    cmd_pos = temp.cmd_pos;
    strncpy(cmd, temp.cmd, MAX_COMMAND);

#if DEBUG_ESCAPE
    printf("undo after: %d, %d, '%s'\n",cmd_len,cmd_pos,cmd);
#endif
}

static inline void process_input_beginning_of_word()
{
    cmd_pos--;
    while (((signed)cmd_pos >= 0) && (cmd[cmd_pos] == ' ')) {
        cmd_pos--;
    }
    while (((signed)cmd_pos >= 0) && (cmd[cmd_pos] != ' ')) {
        cmd_pos--;
    }
    cmd_pos++;
}

static inline void process_input_next_word()
{
    cmd_pos++;
    while ((cmd_pos < cmd_len) && (cmd[cmd_pos] != ' ')) {
        cmd_pos++;
    }
    while ((cmd_pos < cmd_len) && (cmd[cmd_pos] == ' ')) {
        cmd_pos++;
    }
}

static inline void process_input_clear_line()
{
    printf(ERASE_EOL);
    cmd_len=cmd_pos;
    cmd[cmd_len] = 0;
}

static inline void process_input_delete(unsigned int orig_cmd_pos)
{
    int delta = cmd_pos - orig_cmd_pos;
    int len = cmd_len - cmd_pos + 1;
#if DEBUG_ESCAPE
    printf("<delete: orig %d, new %d, delta %d, len %d>\n",orig_cmd_pos,cmd_pos,delta,len);
#endif
    if (delta < 0) {
        memmove(&cmd[cmd_pos], &cmd[orig_cmd_pos], len);
        cmd_len += delta;
    }
    else if (delta > 0) {
        memmove(&cmd[orig_cmd_pos], &cmd[cmd_pos], len);
        cmd_len -= delta;
        cmd_pos = orig_cmd_pos;
    }
    delete_mode=0;
}

static inline int remove_leading_spaces()
{
    unsigned int num_leading_spaces;
    char *curr_cmd = command_history[history_index];

    curr_cmd[cmd_len] = 0;      /* make sure the command is terminated */
    /* first find leading spaces */
    for (num_leading_spaces=0; curr_cmd[num_leading_spaces] == ' '; num_leading_spaces++) { /* loop */ }
    if (num_leading_spaces != 0) {      /* found leading spaces, remove them */
        cmd_len -= num_leading_spaces;
        if (cmd_pos < num_leading_spaces) cmd_pos=0;
        else cmd_pos -= num_leading_spaces;
        memmove(&curr_cmd[0], &curr_cmd[num_leading_spaces], cmd_len+1);
        return 1;
    }
    return 0;
}

static void process_input(int c)
{
    cmd = command_history[history_index];
    cmd[cmd_len] = 0;

    if (c == 0)         /* no new input */
    {
        process_input_draw_current();
        goto process_input_done;
    }

    if (leftover_help.help_string_p != NULL) {
        if (c == ' ') {
            show_next_leftover_help_page();
        }

        if ((c == '\r') || (c == '\n')) {        /* CR/LF */
            leftover_help.help_string_p = NULL;         /* terminate paging */
        }
        else {
            /* Note: ignore other characters */
            goto process_input_done;
        }
    }

    if (! (escape_mode && !escape_saw_char && !find_mode && (c=='u')) )
        process_input_save_undo();

    if (escape_mode) {  /* process escape sequences */
        if (escape_saw_char == '[') {
            switch (c) {
                case 'A':
                    process_input_up();
                    escape_mode=0;
                    escape_saw_char=0;
                    break;
                case 'B':
                    process_input_down();
                    escape_mode=0;
                    escape_saw_char=0;
                    break;
                case 'C':
                    process_input_right();
                    escape_mode=0;
                    escape_saw_char=0;
                    break;
                case 'D':
                    process_input_left();
                    escape_mode=0;
                    escape_saw_char=0;
                    break;
                case 'P':       /* Pause/Break key, toggle start/stop */
                    escape_mode=0;
                    escape_saw_char=0;
                    if (last_start_total_display_updates == TIMESTAMP_INVALID) { /* currently off */
                        printf("<starting default>");
                        process_command("start",1);
                    }
                    else {
                        printf("<stopping default>");
                        process_command("stop",1);
                    }
                    break;
                case '\r':
                case '\n':
                    escape_mode=0;
                    escape_saw_char=0;
                    goto parse_input;   /* parse this as a normal character */
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    escape_saw_char=c;  /* really should handle more than one character here */
                    break;
                default:
#if DEBUG_ESCAPE
                    printf("<1:%d,%d(%c)>\n",escape_mode,escape_saw_char,escape_saw_char);
#endif
                    escape_mode=0;
                    escape_saw_char=0;
                    goto parse_input;   /* parse this as a normal character */
            }
        }
        else if (escape_saw_char == 'O') {
            switch (c) {
                case 'H':       /* Home */
                    cmd_pos=0;
                    escape_mode=0;
                    escape_saw_char=0;
                    break;
                case 'F':       /* End */
                    cmd_pos=cmd_len;
                    escape_mode=0;
                    escape_saw_char=0;
                    break;
                case 'P':       /* F1 */
                case 'Q':       /* F2 */
                case 'R':       /* F3 */
                case 'S':       /* F4 */
                    process_function_key(c-'P'+1);
                    break;
                default:
#if DEBUG_ESCAPE
                    printf("<2:%d,%d(%c)>\n",escape_mode,escape_saw_char,escape_saw_char);
#endif
                    escape_mode=0;
                    escape_saw_char=0;
                    goto parse_input;   /* parse this as a normal character */
            }
        }
        else if (isdigit(escape_saw_char) && isdigit(c)) {
#define TWO_DIGIT_ESC_CODE(first,second) (0x200 + ((first) - '0')*10 + (second) - '0')
            escape_saw_char = TWO_DIGIT_ESC_CODE(escape_saw_char,c);
        }
        else if (escape_saw_char != 0) {
            if (c == '~') {
                if (escape_saw_char & 0x200) {
                    int func = escape_saw_char-0x200-16+5;
                    if ((func >= 5) && (func <= 22))    /* F5..F12 and shift-F1..shift-F8 are 5..22 (with some holes) */
                        process_function_key(func);
#if DEBUG_ESCAPE
                    else
                        printf("<4:%d,'%d'>\n",escape_mode,escape_saw_char-0x200);
#endif
                    escape_mode=0;
                    escape_saw_char=0;
                }
                else switch (escape_saw_char) {
                    case '2':   /* Insert */
                        insert_mode ^= 1;       /* toggle insert mode */
                        escape_mode=0;
                        escape_saw_char=0;
                        break;
                    case '3':   /* Delete*/
                        process_input_right();  /* translate ESC-x to move right then backspace */
                        c = '\b';
                        escape_mode=0;
                        escape_saw_char=0;
                        goto parse_input;       /* parse this as a normal character */
                    case '1':   /* Home */
                        cmd_pos=0;              /* goto the beginning of the line */
                        escape_mode=0;
                        escape_saw_char=0;
                        break;
                    case '4':   /* End */
                        cmd_pos=cmd_len;        /* goto the end of the line */
                        escape_mode=0;
                        escape_saw_char=0;
                        break;
                    case '5':   /* PageUp */
                        escape_mode=0;
                        escape_saw_char=0;
                        process_command("PageUp",1);
                        break;
                    case '6':   /* PageDown */
                        escape_mode=0;  /* ignore for now */
                        escape_saw_char=0;
                        process_command("PageDown",1);
                        break;
                    default:
#if DEBUG_ESCAPE
                        printf("<3:%d,%d(%c)>\n",escape_mode,escape_saw_char,escape_saw_char);
#endif
                        escape_mode=0;
                        escape_saw_char=0;
                        goto parse_input;       /* parse this as a normal character */
                }
            }
        }
        else {
            unsigned int orig_cmd_pos = cmd_pos;
            switch (c) {        /* parse some vi style escape sequences and arrow keys */
                case 'h':
                    process_input_left();
                    break;
                case 'j':
                    process_input_down();
                    break;
                case 'k':
                    process_input_up();
                    break;
                case '$':
                    cmd_pos=cmd_len;
                    break;
                case '0':
                    cmd_pos=0;
                    break;
                case 'l':
                    process_input_right();
                    break;
                case 'D':
                    process_input_clear_line();
                    break;
                case 'A':
                    cmd_pos=cmd_len;
                    insert_mode=1;
                    escape_mode=0;
                    break;
                case 'a':
                    process_input_right();
                    /* NOTE: fall through */
                case 'i':
                    insert_mode=1;
                    escape_mode=0;
                    break;
                case 'f':
                    find_orig_cmd_pos = cmd_pos;
                    find_mode=1;
                    escape_mode=0;
                    goto process_input_done;    /* skip delete_mode check */
                case 'R':
                    insert_mode=0;
                    escape_mode=0;
                    break;
                case 'b':
                    process_input_beginning_of_word();
                    break;
                case 'w':
                    process_input_next_word();
                    break;
                case 'r':
                    insert_mode=0;
                    escape_mode=0;
                    overwrite_once=1;
                    break;
                case '?':
                case ':':
                case '/':
                    escape_mode=0;
                    cmd_len=0;
                    cmd_pos=0;
                    goto parse_input;   /* parse this as a normal character */
                case '~':
                    if (islower(cmd[cmd_pos])) cmd[cmd_pos] = toupper(cmd[cmd_pos]);
                    else if (isupper(cmd[cmd_pos])) cmd[cmd_pos] = tolower(cmd[cmd_pos]);
                    process_input_right();
                    break;
                case 'c':
                    delete_mode=2;
                    goto process_input_done;    /* skip delete_mode check */
                case 'u':
                    process_input_undo();
                    break;
                case 'd':
                    if (delete_mode==1) {       /* dd is delete line */
                        cmd_len=0;
                        cmd_pos=0;
                        delete_mode=0;
                        break;
                    }
                    delete_mode=1;
                    goto process_input_done;    /* skip delete_mode check */
                case 'x':               /* translate ESC-x to move right then backspace */
                    process_input_right();
                    c = '\b';
                    goto parse_input;   /* parse this as a normal character */
                case 'n':
                    search_mode=1;
                    was_lookup = 0;
                    pattern_dir_reverse = 0;
                    goto search_pattern;
                case 'N':
                    search_mode=1;
                    was_lookup = 0;
                    pattern_dir_reverse = 1;
                    goto search_pattern;
                case '[':
                case 'O':
                    escape_saw_char=c;
                    break;
                case '\r':
                case '\n':
                    escape_mode=0;
                    goto parse_input;   /* parse this as a normal character */
                default:
#if DEBUG_ESCAPE
                    printf("<0:%d,%d(%c)>\n",escape_mode,escape_saw_char,escape_saw_char);
#endif
                    escape_mode=0;
                    escape_saw_char=0;
                    goto parse_input;   /* parse this as a normal character */
            }
            if (delete_mode) {
                if (delete_mode==2) {   /* change mode (delete then insert) */
                    insert_mode=1;
                    escape_mode=0;
                }
                process_input_delete(orig_cmd_pos);
            }
        }
        goto process_input_done;
    }

    if (find_mode) {    /* find a character */
        char *p = strchr(&cmd[cmd_pos],c);
        if ((p!=NULL) && ((p-cmd+1) <= (int)cmd_len)) { /* ignore, not found or beyond range */
            cmd_pos = p-cmd;            /* move to next c */
        }
        find_mode=0;
        escape_mode=1;  /* "stay" in escape mode after find */
        if (delete_mode) {
            cmd_pos++;  /* also delete found character in find mode */
            if (cmd_pos > cmd_len) cmd_pos=cmd_len;
            process_input_delete(find_orig_cmd_pos);
        }
        goto process_input_done;
    }

parse_input:
    if (overwrite_once) {
        escape_mode=1;
        overwrite_once=0;
    }
    if ((c == '\t') || (c == '\x04'))   /* tab completion, scan help strings for completion possibilities */
    {
        char *token_start;

        remove_leading_spaces();

        SET_SCROLL_REGION(max_displayed_row);
        process_input_draw_current();

        if (c == '\x04') tab_mode=2;    /* list all possibilities */
        if (tab_mode==0) {
            saved_avail_p=NULL;         /* start over */
            saved_suffix_size=0;        /* start over */
        }
        cmd[cmd_len] = 0;
        token_start = &cmd[cmd_pos] - (cmd_pos != 0);
        while ((token_start > cmd) && (*token_start != ' ')) token_start--;
        if (token_start==cmd) {         /* first token of command */
            tab_complete(cmd, help_commands);
        }
        else {
            token_start++;      /* skip space */
            secondary_lut_lut_t *second;
            if (strncasecmp(cmd, "help", strlen("help")) == 0) {        /* for help <command> secondary lookup is help_commands */
                tab_complete(token_start, help_commands);
            }
            else {
                for (second = secondary_lut_lut; second->command; second++) {
                    if (strncasecmp(cmd,second->command,strlen(second->command))==0) {
                        tab_complete(token_start, second->lut);
                        break;
                    }
                }
            }
        }
        if (tab_mode==2)
            tab_mode=0;
        else
            tab_mode=1;
    }
    else if ((tab_mode==1) && (c==' ')) {       /* space after multi-tab selects and moves to next space or end */
        char *p = strchr(&cmd[cmd_pos],' ');
        if ((p==NULL) || ((p-cmd+1) > (int)cmd_len)) {
            cmd_pos = cmd_len;          /* move to end of command */
        }
        else {
            cmd_pos = p-cmd+1;          /* move to just after next space */
        }
    }
    else if ((tab_mode=0)) {    /* NOTE: always false, but used to clear tab mode and keep "else if" strucure clean */
        /* never happens */
    }
    else if (c=='\033') {       /* escape character */
        escape_mode=1;
    }
    else if ((c>=32) && (c<=126))       /* normal character */
    {
        process_input_commit_character(c);
    }
    else if (c == '\x0c')       /* control-l erases/redraws sreeen */
    {
        printf(GOTO_TOP ERASE_EOS);
    }
    else if (c == '\b')         /* backspace */
    {
        if (cmd_pos)
        {
            cmd_len--;
            cmd_pos--;
            if (cmd_pos < cmd_len) {
                memmove(&cmd[cmd_pos], &cmd[cmd_pos+1], cmd_len-cmd_pos+1);
            }
        }
    }
    else if ((c == '\r') || (c == '\n'))        /* CR/LF */
    {
        was_lookup = (cmd[0] == '/') || (cmd[0] == '?') || (cmd[0] == ':');
        search_mode = (cmd[0] == '/') || (cmd[0] == '?');
        if (help_frozen) {
            printf(GOTO_TOP ERASE_EOS);
            help_frozen = 0;
            leftover_help.help_string_p = NULL;         /* kill help paging */
        }
        cmd[cmd_len] = 0;
        cmd_pos = cmd_len;
        if ((cmd[0] == '!') || was_lookup) {
            int new_line;
            if ((cmd[1] == '!') || (cmd[1] == ':')) {
                process_input_change_index_to(history_index-1);
            }
            else if ((!search_mode) && (sscanf(cmd+1,"%d",&new_line)==1)) {
                process_input_change_index_to(new_line);
            }
            else {      /* search for first line starting with !pat */
                int len;
                int delta;
                strcpy(pattern,cmd+1);
                pattern_dir_delta = (cmd[0] == '/') ? 1 : -1;
                pattern_dir_reverse=0;
search_pattern:
                delta = pattern_dir_delta;
                if (pattern_dir_reverse) {
                    if (pattern_dir_delta == 1) delta= -1;
                    else delta = 1;
                }
                else if (delta == 0) delta = -1;        /* just in case.... */

                len=strlen(pattern);
#define PREV_HIST(x) ( ((x)+delta) & MAX_HISTORY_MASK )
                for (new_line=PREV_HIST(history_lookup_index);
                        (command_history[new_line][0]) && (new_line!=history_lookup_index);
                        new_line=PREV_HIST(new_line)) {
                    if (search_mode) {  /* search anywhere, NOTE case sensitive */
                        if (strstr(command_history[new_line],pattern)!=0) {
                            process_input_change_index_to(new_line);
                            break;
                        }
                    }
                    else {      /* only search from beginning, case insensitive */
                        if (strncasecmp(pattern,command_history[new_line],len)==0) {
                            process_input_change_index_to(new_line);
                            break;
                        }
                    }
                }
            }
        }
        process_input_draw_current();
        if (!(was_lookup || search_mode)) {     /* don't execute if only a lookup */
            if (remove_leading_spaces()) process_input_draw_current();
            if (cmd_len != 0) history_index = (history_index + 1) & MAX_HISTORY_MASK;
            history_lookup_index = history_index;
            process_command(cmd,1);
            cmd_len = 0;
            cmd_pos = 0;
        }
        else {
            escape_mode=1;      /* "stay" in escape mode after search */
            search_mode=0;
        }
    }
process_input_done:
    printf(CURSOR_OFF SCROLL_FULL GOTO_BOTTOM CURSOR_ON);       /* in case we stop here */
    process_input_draw_current();
}

static void process_input_type(char *text) {
    while (*text) {
        if (*text == '\\') {
            char new_ch = *++text;
            switch (new_ch) {
                /* allow some C-style escape sequences */
                case 'a': new_ch = '\a'; break;
                case 'b': new_ch = '\b'; break;
                case 't': new_ch = '\t'; break;
                case 'n': new_ch = '\n'; break;
                case 'v': new_ch = '\v'; break;
                case 'f': new_ch = '\f'; break;
                case 'r': new_ch = '\r'; break;
            }
            text++;
            process_input(new_ch);
        }
        else process_input(*text++);
    }
}

/**
 * Display port statistics to the terminal
 */
static void display_statistics(void)
{
    static int last_max_displayed_row = 0;
    int port;
    uint64_t total;
    int current_row=0;
    max_displayed_row=2;

    /* Return immediately if all stats are shut off */
    total = 0;
    for (port=0; port<BDK_PIP_NUM_INPUT_PORTS; port++)
        total += port_state[port].display;
    if (total == 0)
        return;

    /* Display the port titles */
    total_display_updates++;
    if (last_start_total_display_updates != TIMESTAMP_INVALID) {
        /* currently on, see if all are now off */
        for (port=0; port<BDK_PIP_NUM_INPUT_PORTS; port++) {
            if (port_setup[port].output_enable) {
                /* someone is still on */
                sending_time = total_display_updates - last_start_total_display_updates;
                goto someone_on;
            }
        }
        last_start_total_display_updates = TIMESTAMP_INVALID;
someone_on: ;
    }

    char time_str[16];
    snprintf(time_str, sizeof(time_str), "%4llu:%02llu:%02llu",
             (ULL)sending_time/(60*60), (ULL)((sending_time/(60))%60), (ULL)(sending_time%60));
#if 0 // FIXME
    if (!bdk_is_simulation())
    {
        if (sending_time)
            ebt3000_str_write(time_str+2);
        else
            ebt3000_str_write("");
    }
#endif

    printf(CURSOR_OFF GOTO_TOP "%s %10llu ", time_str, (ULL)total_display_updates);
    for (port=0; port<BDK_PIP_NUM_INPUT_PORTS; port++)
    {
        if (port_state[port].display)
            printf("|%8s%2d", ((port>=default_start_port) && (port<=default_stop_port)) ? "*Port ":"Port ", port);
    }
    printf("|%8s", "Totals");
    printf(ERASE_EOL);
    printf("\n");

    /* Macro to generate all the port output for a specific statistic */
    /*  n = Name of the statistic the user sees */
    /*  s = Structure member containing the statistic */
    #define PRINTSTAT(n, s)                                                                 \
        printf("%-19s", n);                                                                 \
        total = 0;                                                                          \
        for (port=0; port<BDK_PIP_NUM_INPUT_PORTS; port++)                                 \
        {                                                                                   \
            if (port_state[port].display)                                                   \
            {                                                                               \
                total += port_state[port].s;                                                \
                printf("|%10llu", (unsigned long long)port_state[port].s);                  \
            }                                                                               \
        }                                                                                   \
        printf("|%10llu", (unsigned long long)total);                                       \
        printf(ERASE_EOL);    /* Erase to end of line */                                    \
        printf("\n");

    /* Macro to generate all the port output for a specific percent statistic */
    /*  n = Name of the statistic the user sees */
    /*  s = Structure member containing the statistic */
    #define PRINTPERCENT(n, s)                                                              \
        printf("%-19s", n);                                                                 \
        total = 0;                                                                          \
        for (port=0; port<BDK_PIP_NUM_INPUT_PORTS; port++)                                 \
        {                                                                                   \
            if (port_state[port].display)                                                   \
            {                                                                               \
                total += port_state[port].s;                                                \
                printf("|%8llu.%llu", (unsigned long long)port_state[port].s/10,            \
                        (unsigned long long)port_state[port].s%10);                         \
            }                                                                               \
        }                                                                                   \
        printf("|%8llu.%llu", (unsigned long long)total/10, (unsigned long long)total%10);  \
        printf(ERASE_EOL);    /* Erase to end of line */                                    \
        printf("\n");

    /* Macro to generate all the port output for a specific transmitter settings */
    /*  n = Name of the statistic the user sees */
    /*  s = Structure member containing the statistic */
    /*  b = Base of lookup table if ascii type or numeric if an integer type */
    #define PRINTTRANS(n, s, b)                                                             \
        printf("%-19s", n);                                                                 \
        for (port=0; port<BDK_PIP_NUM_INPUT_PORTS; port++)                                 \
        {                                                                                   \
            if (port_state[port].display)                                                   \
            {                                                                               \
                if (b==numeric) printf("|%10llu", (ULL)port_setup[port].s);           \
                else if (b==numeric_signed) printf("|%10lld", (LL)port_setup[port].s);\
                else printf("|%10s", b[port_setup[port].s]);                          \
            }                                                                               \
        }                                                                                   \
        printf(ERASE_EOL);    /* Erase to end of line */                                    \
        printf("|\n");

    /* Macro to generate a MAC addresses */
    /*  n = Name of the statistic the user sees */
    /*  s = Structure member containing the statistic */
    #define PRINTMAC(n, s)                                                                  \
        printf("%-19s", n);                                                                 \
        for (port=0; port<BDK_PIP_NUM_INPUT_PORTS; port++)                                 \
        {                                                                                   \
            if (port_state[port].display)                                                   \
            {                                                                               \
                printf("|%10llx", (unsigned long long)port_setup[port].s);            \
            }                                                                               \
        }                                                                                   \
        printf(ERASE_EOL);    /* Erase to end of line */                                    \
        printf("|\n");

    /* Macro to generate a VLAN */
    /*  n = Name of the statistic the user sees */
    /*  s = Structure member containing the statistic */
    #define PRINTVLAN(n, s)                                                                 \
        printf("%-19s", n);                                                                 \
        for (port=0; port<BDK_PIP_NUM_INPUT_PORTS; port++)                                 \
        {                                                                                   \
            if (port_state[port].display)                                                   \
            {                                                                               \
                int vi;                                                                     \
                printf("| ");                                                               \
                for (vi=0; vi<(int)port_setup[port].s##_size; vi++)                         \
                    printf("%02x", port_setup[port].s[vi]);                                 \
                for (; vi<4; vi++)                                                          \
                    printf("  ");                                                           \
                printf(" ");                                                                \
            }                                                                               \
        }                                                                                   \
        printf(ERASE_EOL);    /* Erase to end of line */                                    \
        printf("|\n");

    /* Macro to generate IP addresses */
    /*  n = Name of the statistic the user sees */
    /*  s = Structure member containing the statistic */
    #define PRINTIP(n, s)                                                                   \
        printf("%-19s", n);                                                                 \
        for (port=0; port<BDK_PIP_NUM_INPUT_PORTS; port++)                                 \
        {                                                                                   \
            if (port_state[port].display)                                                   \
            {                                                                               \
                char ip_string[128];                                                        \
                sprintf(ip_string,"%d.%d.%d.%d",                                            \
                        (uint8_t)(port_setup[port].s>>24),                            \
                        (uint8_t)(port_setup[port].s>>16),                            \
                        (uint8_t)(port_setup[port].s>>8),                             \
                        (uint8_t)(port_setup[port].s>>0));                            \
                printf("|%10s", ip_string);                                                 \
            }                                                                               \
        }                                                                                   \
        printf(ERASE_EOL);    /* Erase to end of line */                                    \
        printf("|\n");

    /* Macro to display or hide a row.  Note that braces should be used for safty and readability. */
    /* The IS_MIN parameter should be 1 if this row is important enough to be in the "minimal" set */
    /* set of useful rows, or 0 if not.  The minimal rows should be kept to allow 80x24 terminals. */
    #define ROW(IS_MIN)                                                                     \
        if (++current_row >= MAX_ROW) {                                                     \
            current_row = MAX_ROW;                                                          \
            printf("WARNING:  MAX_ROW too small.\n");                                       \
        }                                                                                   \
        if (force_min) row_state[current_row].hidden=!IS_MIN;                               \
        if (!row_state[current_row].hidden) {                                               \
            printf("%s%s%2d:", NORMAL, row_state[current_row].highlight?REVERSE:"", current_row);\
            max_displayed_row++;                                                            \
        }                                                                                   \
        if (!row_state[current_row].hidden)     /* duplicated for the block that follows */

    /* This macro returns non zero if any field in a row is non zero. This is used by ROWNZ */
    #define NONZEROSTAT(s)                                                                  \
        {total = 0;                                                                         \
        for (port=0; port<BDK_PIP_NUM_INPUT_PORTS; port++)                                 \
        {                                                                                   \
            if (port_state[port].display)                                                   \
                total |= port_state[port].s;                                                \
        }                                                                                   \
        total;}

    /* Macro to display or hide a row based on if the row has non zero values.  Note that braces
        should be used for safty and readability. The "s" parameter should be the field in
        port_state that should be checked for zero. The row will be displayed in yellow when any
        of its values are non zero. It will display green and hide after 5 seconds when zero. The
        normal row hiding can be used to make the row not disappear when idle */
    #define ROWNZ(s)                                                                        \
        if (++current_row >= MAX_ROW) {                                                     \
            current_row = MAX_ROW;                                                          \
            printf("WARNING:  MAX_ROW too small.\n");                                       \
        }                                                                                   \
        if (force_min) row_state[current_row].hidden=1;                                     \
        total = (NONZEROSTAT(s));                                                           \
        if (total)                                                                          \
            row_state[current_row].hide_delay = 5;                                          \
        else if (row_state[current_row].hide_delay)                                         \
            row_state[current_row].hide_delay--;                                            \
        if (!row_state[current_row].hidden || row_state[current_row].hide_delay) {          \
            printf("%s%2d:", (total)?NONZEROHI:ZEROHI, current_row);                        \
            max_displayed_row++;                                                            \
        }                                                                                   \
        if (!row_state[current_row].hidden || row_state[current_row].hide_delay) /* duplicated for the block that follows */

    /* These statistics seem to be broken right now */
    ROW(0){PRINTSTAT("PCI raw packets", input_statistics.pci_raw_packets);}
    ROW(0){PRINTSTAT("Packets", input_statistics.packets);}
    ROW(0){PRINTSTAT("Octets", input_statistics.octets);}
    ROWNZ(input_statistics.dropped_packets){PRINTSTAT("Dropped packets", input_statistics.dropped_packets);}
    ROWNZ(input_statistics.dropped_octets){PRINTSTAT("Dropped octets", input_statistics.dropped_octets);}
    ROWNZ(input_statistics.runt_packets){PRINTSTAT("Runt packets", input_statistics.runt_packets);}
    ROWNZ(input_statistics.runt_crc_packets){PRINTSTAT("Runt CRC errors", input_statistics.runt_crc_packets);}
    ROWNZ(input_statistics.oversize_packets){PRINTSTAT("Oversize packets", input_statistics.oversize_packets);}
    ROWNZ(input_statistics.oversize_crc_packets){PRINTSTAT("Oversize CRC errors", input_statistics.oversize_crc_packets);}
    ROW(0){PRINTSTAT("Multicast packets", input_statistics.multicast_packets);}
    ROW(0){PRINTSTAT("Broadcast packets", input_statistics.broadcast_packets);}
    ROW(0){PRINTSTAT("64B packets", input_statistics.len_64_packets);}
    ROW(0){PRINTSTAT("65B-127B packets", input_statistics.len_65_127_packets);}
    ROW(0){PRINTSTAT("128B-255B packets", input_statistics.len_128_255_packets);}
    ROW(0){PRINTSTAT("256B-511B packets", input_statistics.len_256_511_packets);}
    ROW(0){PRINTSTAT("512B-1023B packets", input_statistics.len_512_1023_packets);}
    ROW(0){PRINTSTAT("1024B-1518B packets", input_statistics.len_1024_1518_packets);}
    ROW(0){PRINTSTAT(">=1519B packets", input_statistics.len_1519_max_packets);}
    ROWNZ(input_validation_errors){PRINTSTAT("Validation errors", input_validation_errors);}
    ROWNZ(input_statistics.fcs_align_err_packets){PRINTSTAT("FCS align errors", input_statistics.fcs_align_err_packets);}
    ROWNZ(input_statistics.inb_errors){PRINTSTAT("RX errors", input_statistics.inb_errors);}
    ROWNZ(backpressure){PRINTSTAT("Backpressure", backpressure);}
    ROW(1){PRINTSTAT("RX packets", input_statistics.inb_packets);}
    ROW(1){PRINTSTAT("RX octets", input_statistics.inb_octets);}
    ROW(0){PRINTPERCENT("RX percent", input_percent);}
    ROW(1){PRINTSTAT("RX Mbps", input_Mbps);}
    ROW(1){PRINTTRANS("tx.size", output_packet_size, numeric);}
    ROW(1){PRINTTRANS("tx.type", output_packet_type, tx_packet_type_lut);}
    ROW(1){PRINTTRANS("tx.payload", output_packet_payload, tx_payload_lut);}
    ROW(1){PRINTSTAT("TX packets", output_statistics.packets);}
    ROW(1){PRINTSTAT("TX octets", output_statistics.octets);}
    ROW(0){PRINTPERCENT("TX percent", output_percent);}
    ROW(1){PRINTSTAT("TX Mbps", output_Mbps);}
    ROW(0){PRINTSTAT("PKO Doorbell", output_statistics.doorbell);}
    ROW(1){PRINTSTAT("Total RX packets", input_cumulative_packets);}
    ROW(0){PRINTSTAT("Total RX octets", input_cumulative_octets);}
    ROWNZ(input_cumulative_errors){PRINTSTAT("Total RX errors", input_cumulative_errors);}
    ROW(1){PRINTSTAT("Total TX packets", output_cumulative_packets);}
    ROW(0){PRINTSTAT("Total TX octets", output_cumulative_octets);}
    ROW(0){PRINTSTAT("Total RX ARP rqst", input_arp_requests);}
    ROW(0){PRINTSTAT("Total RX ARP rply", input_arp_replies);}
    ROW(0){PRINTSTAT("Total TX ARP rqst", output_arp_requests);}
    ROW(0){PRINTSTAT("Total TX ARP rply", output_arp_replies);}
    ROW(0){PRINTTRANS("tx.arp.reply", output_arp_reply_enable, on_off_lut);}
    ROW(0){PRINTTRANS("rx.arp.request", input_arp_request_enable, on_off_lut);}
    ROW(0){PRINTTRANS("rx.arp.reply", input_arp_reply_enable, on_off_lut);}
    ROW(1){PRINTMAC("dest.mac", dest_mac);}
    ROW(0){PRINTMAC("dest.mac.inc", dest_mac_inc);}
    ROW(0){PRINTMAC("dest.mac.min", dest_mac_min);}
    ROW(0){PRINTMAC("dest.mac.max", dest_mac_max);}
    ROW(1){PRINTMAC("src.mac", src_mac);}
    ROW(0){PRINTMAC("src.mac.inc", src_mac_inc);}
    ROW(0){PRINTMAC("src.mac.min", src_mac_min);}
    ROW(0){PRINTMAC("src.mac.max", src_mac_max);}
    ROW(1){PRINTIP("dest.ip", dest_ip);}
    ROW(0){PRINTIP("dest.ip.inc", dest_ip_inc);}
    ROW(0){PRINTIP("dest.ip.min", dest_ip_min);}
    ROW(0){PRINTIP("dest.ip.max", dest_ip_max);}
    ROW(1){PRINTIP("src.ip", src_ip);}
    ROW(0){PRINTIP("src.ip.inc", src_ip_inc);}
    ROW(0){PRINTIP("src.ip.min", src_ip_min);}
    ROW(0){PRINTIP("src.ip.max", src_ip_max);}
    ROW(0){PRINTTRANS("ip.tos", ip_tos, numeric);}
    ROW(0){PRINTTRANS("src.port", src_port, numeric);}
    ROW(0){PRINTTRANS("src.port.inc", src_port_inc, numeric_signed);}
    ROW(0){PRINTTRANS("src.port.min", src_port_min, numeric);}
    ROW(0){PRINTTRANS("src.port.max", src_port_max, numeric);}
    ROW(0){PRINTTRANS("dest.port", dest_port, numeric);}
    ROW(0){PRINTTRANS("dest.port.inc", dest_port_inc, numeric_signed);}
    ROW(0){PRINTTRANS("dest.port.min", dest_port_min, numeric);}
    ROW(0){PRINTTRANS("dest.port.max", dest_port_max, numeric);}
    ROW(0){PRINTTRANS("tx.checksum", do_checksum, on_off_lut);}
    ROW(1){PRINTTRANS("bridge", bridge_port, port_off_lut);}
    ROW(0){PRINTVLAN("tx.vlan", vlan);}
    ROW(0){PRINTTRANS("rx.display", display_packet, on_off_error_lut);}
    ROW(0){PRINTTRANS("higig", higig, numeric);}
    ROW(1){PRINTTRANS("validate packets", validate, on_off_lut);}
    ROW(0){PRINTTRANS("RespectBackpressure", respect_backpressure, on_off_lut);}
    ROW(0){printf("Packet buffers:  %7llu ", (ULL)BDK_CSR_READ(BDK_IPD_QUE0_FREE_PAGE_CNT));
        printf("Command buffers: %7llu ", (ULL)BDK_CSR_READ(BDK_FPA_QUEX_AVAILABLE(BDK_FPA_OUTPUT_BUFFER_POOL)));
        printf("Work buffers:    %7llu" ERASE_EOL "\n", (ULL)BDK_CSR_READ(BDK_FPA_QUEX_AVAILABLE(BDK_FPA_WQE_POOL)));}
#if 0 // FIXME
    ROW(0){
        /* Compute DRAM utilization */
        static uint64_t prev_ops_cnt;
        static uint64_t prev_dclk_cnt;
        uint64_t ops_cnt = OCTEON_IS_MODEL(OCTEON_CN6XXX) ? BDK_CSR_READ(BDK_LMCX_OPS_CNT(0)) :
                            ((BDK_CSR_READ(BDK_LMC_OPS_CNT_HI) << 32) | BDK_CSR_READ(BDK_LMC_OPS_CNT_LO));
        uint64_t dclk_cnt = bdk_clock_get_count(BDK_CLOCK_DDR);
        uint64_t delta_ops = ops_cnt - prev_ops_cnt;
        uint64_t delta_cycles = dclk_cnt - prev_dclk_cnt;
        int percent_x100 = delta_ops * 10000 / delta_cycles;
        prev_ops_cnt = ops_cnt;
        prev_dclk_cnt = dclk_cnt;
        printf("DRAM utilization: %3d.%02d%% count: %9lld dclk: %lld" ERASE_EOL "\n",
            percent_x100/100, percent_x100%100,
            (unsigned long long)delta_ops, (unsigned long long)delta_cycles);
    }
    if (OCTEON_IS_MODEL(OCTEON_CN3XXX) || OCTEON_IS_MODEL(OCTEON_CN5XXX))
    {
        ROW(0){
            /* L2 performance counters */
            bdk_l2c_pfctl_t l2perf;
            l2perf.u64 = 0;
            l2perf.s.cnt3ena = 1;
            l2perf.s.cnt3clr = 1;
            l2perf.s.cnt3sel = BDK_L2C_EVENT_DATA_MISS;
            l2perf.s.cnt2ena = 1;
            l2perf.s.cnt2clr = 1;
            l2perf.s.cnt2sel = BDK_L2C_EVENT_DATA_HIT;
            l2perf.s.cnt1ena = 1;
            l2perf.s.cnt1clr = 1;
            l2perf.s.cnt1sel = BDK_L2C_EVENT_INSTRUCTION_MISS;
            l2perf.s.cnt0ena = 1;
            l2perf.s.cnt0clr = 1;
            l2perf.s.cnt0sel = BDK_L2C_EVENT_INSTRUCTION_HIT;
            printf("L2 cache Ihit: %9llu Imiss: %9llu Dhit: %9llu Dmiss: %9llu" ERASE_EOL "\n",
                   (unsigned long long)BDK_CSR_READ(BDK_L2C_PFC0),
                   (unsigned long long)BDK_CSR_READ(BDK_L2C_PFC1),
                   (unsigned long long)BDK_CSR_READ(BDK_L2C_PFC2),
                   (unsigned long long)BDK_CSR_READ(BDK_L2C_PFC3));
            BDK_CSR_WRITE(BDK_L2C_PFCTL, l2perf.u64);
        }
    }
#endif

    int i;
    for (i=0; i<256;i++)
    {
        char label[32];
        sprintf(label, "WQE RX error %d", i);
        row_state[current_row+1].hidden = 1;
        ROWNZ(wqe_receive_errors[i]){PRINTSTAT(label, wqe_receive_errors[i]);}
    }


    if (force_min) {
        printf("\n" NORMAL "NOTE: Only a minimal set of rows are shown, use 'row' to see what is missing,\n   or 'row on' to see all rows (or 'help row' for more info)");
        force_min=0;
    }

    printf(NORMAL);
    for (i=max_displayed_row; i<last_max_displayed_row;i++)
        printf(ERASE_EOL "\n");
    last_max_displayed_row = max_displayed_row;
    printf(GOTO_BOTTOM CURSOR_ON);
}


/**
 * This function updates the port statistics. It must be
 * called once per second. It is called by periodic_update().
 */
static void update_statistics(void)
{
    int port;

    /* Get the statistics for displayed ports */
    for (port=0; port<BDK_PIP_NUM_INPUT_PORTS; port++)
    {
        if (port_state[port].display)
        {
            int64_t bytes_off_per_packet;
            bdk_pip_get_port_status(port, 1, &port_state[port].input_statistics);

            /* Getting and zeroing the PKO statistics isn't atomic. To make up
                for this we need to do the deltas manually. */
            bdk_pko_port_status_t newstats;
            bdk_pko_get_port_status(port, 0, &newstats);
            if (newstats.packets >= port_state[port].output_statistics_old.packets)
                port_state[port].output_statistics.packets = newstats.packets - port_state[port].output_statistics_old.packets;
            else
                port_state[port].output_statistics.packets = (uint64_t)newstats.packets + (1ull<<32) - (uint64_t)port_state[port].output_statistics_old.packets;
            port_state[port].output_statistics_old.packets = newstats.packets;

            if (newstats.octets >= port_state[port].output_statistics_old.octets)
                port_state[port].output_statistics.octets = newstats.octets - port_state[port].output_statistics_old.octets;
            else
                port_state[port].output_statistics.octets = (uint64_t)newstats.octets + (1ull<<48) - (uint64_t)port_state[port].output_statistics_old.octets;
            port_state[port].output_statistics_old.octets = newstats.octets;
            port_state[port].output_statistics.doorbell = newstats.doorbell;

            /* Tx octets at the hardware level does not include ETHERNET_CRC but
                does include the pre L2 header. This is not what the user expects */
            bytes_off_per_packet = ETHERNET_CRC - get_size_pre_l2(port);
            port_state[port].output_statistics.octets += port_state[port].output_statistics.packets*bytes_off_per_packet;

            /* RX octets count ETHERNET_CRC for ports less than 32 and not for 32 and higher. For all ports
                it counts the pre L2, which the user probably doesn't expect */
            bytes_off_per_packet = -get_size_pre_l2(port);
            if(port_setup[port].srio.u64)
                bytes_off_per_packet = -sizeof(bdk_srio_rx_message_header_t) + ETHERNET_CRC;
            else if(port >= 32)
                bytes_off_per_packet += ETHERNET_CRC;
            port_state[port].input_statistics.inb_octets += port_state[port].input_statistics.inb_packets * bytes_off_per_packet;

            /* Now that the RX and TX counters are correct, add them to the totals */
            port_state[port].input_cumulative_packets += port_state[port].input_statistics.inb_packets;
            port_state[port].input_cumulative_octets += port_state[port].input_statistics.inb_octets;
            port_state[port].input_cumulative_errors += port_state[port].input_statistics.inb_errors;
            port_state[port].output_cumulative_packets += port_state[port].output_statistics.packets;
            port_state[port].output_cumulative_octets += port_state[port].output_statistics.octets;

            /* Calculate the RX rate in Mbps. By convention this include all packet
                overhead on the wire. We've already accounted for ETHERNET_CRC but
                not the preamble and IFG */
            bytes_off_per_packet = get_size_wire_overhead(port);
            if(port_setup[port].srio.u64)
                bytes_off_per_packet = 0;
            else
                bytes_off_per_packet -= ETHERNET_CRC;
            port_state[port].input_Mbps = (((port_state[port].input_statistics.inb_packets * bytes_off_per_packet + port_state[port].input_statistics.inb_octets) << 3) + 500000) / 1000000;
            port_state[port].input_percent = port_state[port].input_Mbps; /* Percent * 10 */

            /* Calculate the TX rate in Mbps */
            port_state[port].output_Mbps = (((port_state[port].output_statistics.packets * bytes_off_per_packet + port_state[port].output_statistics.octets) << 3) + 500000) / 1000000;
            port_state[port].output_percent = port_state[port].output_Mbps; /* Percent * 10 */

            bdk_gmxx_txx_pause_togo_t txx_pause_togo;
            txx_pause_togo.u64 = 0;
            switch (bdk_helper_interface_get_mode(bdk_helper_get_interface_num(port)))
            {
                case BDK_HELPER_INTERFACE_MODE_DISABLED:
                case BDK_HELPER_INTERFACE_MODE_PCIE:
                case BDK_HELPER_INTERFACE_MODE_NPI:
                case BDK_HELPER_INTERFACE_MODE_LOOP:
                case BDK_HELPER_INTERFACE_MODE_SRIO:
                    break;
                case BDK_HELPER_INTERFACE_MODE_XAUI:
                    txx_pause_togo.u64 = BDK_CSR_READ(BDK_GMXX_TXX_PAUSE_TOGO(0, bdk_helper_get_interface_num(port)));
                    if (txx_pause_togo.s.time == 0)
                    {
                        bdk_gmxx_rx_hg2_status_t gmxx_rx_hg2_status;
                        gmxx_rx_hg2_status.u64 = BDK_CSR_READ(BDK_GMXX_RX_HG2_STATUS(bdk_helper_get_interface_num(port)));
                        txx_pause_togo.s.time = gmxx_rx_hg2_status.s.lgtim2go;
                    }
                    break;
                case BDK_HELPER_INTERFACE_MODE_SGMII:
                case BDK_HELPER_INTERFACE_MODE_PICMG:
                    txx_pause_togo.u64 = BDK_CSR_READ(BDK_GMXX_TXX_PAUSE_TOGO(bdk_helper_get_interface_index_num(port), bdk_helper_get_interface_num(port)));
                    break;
            }
            port_state[port].backpressure = txx_pause_togo.s.time;
        }
    }
}


/**
 * This function updates the speed for all RGMII ports. It
 * should be called once in a while to make sure the ports
 * are negotiated to the correct speed. It is called by
 * periodic_update(). It only checks two ports per call
 * since the SPI4000 is really slow.
 */
static void update_rgmii_speed(void)
{
    static int interface = 0;
    static int index = 0;
    int loop;
    int num_ports;

    num_ports = bdk_helper_ports_on_interface(interface);
    if (index >= num_ports)
    {
        interface++;
        if (interface >= bdk_helper_get_number_of_interfaces())
            interface = 0;
        num_ports = bdk_helper_ports_on_interface(interface);
        index = 0;
    }

    for (loop=0; loop<2; loop++)
    {
        if (index >= num_ports)
            break;
        int port = bdk_helper_get_ipd_port(interface, index);
        bdk_helper_link_info_t link_info = bdk_helper_link_autoconf(port);
        if (link_info.u64 != port_state[port].link_state)
        {
            if (link_info.s.link_up)
                printf("Port %d: %u Mbps, %s duplex\n", port, link_info.s.speed,
                       (link_info.s.full_duplex) ? "Full" : "Half");
            else
                printf("Port %d: Link down\n", port);
            port_state[port].link_state = link_info.u64;
        }
        index++;
    }
}


/**
 * This is the main reptitive update function. It must be
 * called at least once per second for stuff to work. It can
 * be called more often without any ill effects. The more
 * often, the better.
 */
static uint64_t next_update = 0;
static void periodic_update(int show_command_line)
{
    uint64_t cycle = bdk_clock_get_count(BDK_CLOCK_CORE);

    if (cycle >= next_update)
    {
        if (next_update == 0)
            next_update = cycle;
        next_update += cpu_clock_hz;
        if (next_update < cycle)
            next_update = cycle + cpu_clock_hz;

        update_statistics();
        update_rgmii_speed();

        /* Display the results to the user */
        if (!frozen && !help_frozen)
        {
            display_statistics();
            if (show_command_line)
                process_input(0);
        }
    }
}


/**
 * Called by cores when they get work and need to process it.
 *
 * @param work   Work to be processed. Ideally it should already be prefetched
 *               into memory.
 */
static inline void process_work(bdk_wqe_t *work)
{
    packet_free_t status = fastpath_receive(work);
    if (bdk_likely(status == PACKET_FREE))
        bdk_helper_free_packet_data(work);
    if (bdk_likely(status != PACKET_DONT_FREE_WQE))
        bdk_fpa_free(work, BDK_FPA_WQE_POOL, 0);
}


/**
 * Gatherer thread for init core. Handles all statistics
 * and display.
 */
static void statistics_gatherer(void)
{
    int freeze_state = frozen;  /* Save freeze state in case frozen at start */

    /* Clear all stats on startup, and don't show anything until they are cleared */
    frozen = 1;  /* prevent stats from being displayed */
    periodic_update(0);
    next_update = 0;  /* Force another updated to happen immediately */
    periodic_update(0);
    process_cmd_clear(0, BDK_PIP_NUM_INPUT_PORTS-1);
    frozen = freeze_state;

    while (1)
    {
        {
            /* Check for a character over the serial port */
            int c = uart_read_byte(0);
            if (c)
                process_input(c);
            else
            {
                bdk_wqe_t *work = bdk_sso_work_request_sync(BDK_SSO_NO_WAIT);
                if (work)
                    process_work(work);
            }
        }

        periodic_update(1);
    }
}


/**
 * Convert a pointer to a MAC address into a 64bit number
 * containing the MAC address. Handle unaligned cases.
 *
 * @param mac    MAC address to read
 *
 * @return MAC address as a 64bit number
 */
static inline uint64_t mac_to_uint64(char *mac)
{
    uint64_t m;
    BDK_LOADUNA_INT64(m, mac, 0);
    return m>>16;
}


/**
 * Store a 64bit number into a MAC address pointer. Handler the
 * unaligned case.
 *
 * @param m      Mac address
 * @param mac    Place to store it
 */
static inline void uint64_to_mac(uint64_t m, char *mac)
{
    BDK_STOREUNA_INT32(m>>16, mac, 0);
    BDK_STOREUNA_INT16(m&0xffff, mac, 4);
}


/**
 * Called every packet to increment parts of the packet as necessary.
 *
 * @param port
 * @param data
 */
static inline void packet_incrementer(int port, char *data)
{
    switch (port_setup[port].output_packet_type)
    {
        case PACKET_TYPE_HELP:
        case PACKET_TYPE_IPV4_UDP:
        case PACKET_TYPE_IPV4_TCP:
        {
            int begin_ip = get_end_l2(port);
            if (bdk_unlikely(port_setup[port].src_port_inc))
            {
                int p = *(uint16_t*)(data + begin_ip + 20);
                p += port_setup[port].src_port_inc;
                if (p < port_setup[port].src_port_min)
                    p = port_setup[port].src_port_max;
                else if (p > port_setup[port].src_port_max)
                    p = port_setup[port].src_port_min;
                *(uint16_t*)(data + begin_ip + 20) = p;
            }

            if (bdk_unlikely(port_setup[port].dest_port_inc))
            {
                int p = *(uint16_t*)(data + begin_ip + 22);
                p += port_setup[port].dest_port_inc;
                if (p < port_setup[port].dest_port_min)
                    p = port_setup[port].dest_port_max;
                else if (p > port_setup[port].dest_port_max)
                    p = port_setup[port].dest_port_min;
                *(uint16_t*)(data + begin_ip + 22) = p;
            }

            if (bdk_unlikely(port_setup[port].src_ip_inc))
            {
                int64_t p = *(uint32_t*)(data + begin_ip + 12);
                p += port_setup[port].src_ip_inc;
                if (p < port_setup[port].src_ip_min)
                    p = port_setup[port].src_ip_max;
                else if (p > port_setup[port].src_ip_max)
                    p = port_setup[port].src_ip_min;
                *(uint32_t*)(data + begin_ip + 12) = p;
            }

            if (bdk_unlikely(port_setup[port].dest_ip_inc))
            {
                int64_t p = *(uint32_t*)(data + begin_ip + 16);
                p += port_setup[port].dest_ip_inc;
                if (p < port_setup[port].dest_ip_min)
                    p = port_setup[port].dest_ip_max;
                else if (p > port_setup[port].dest_ip_max)
                    p = port_setup[port].dest_ip_min;
                *(uint32_t*)(data + begin_ip + 16) = p;
            }

            if ((bdk_unlikely(port_setup[port].src_ip_inc)) ||
                (bdk_unlikely(port_setup[port].dest_ip_inc)))
            {
                /* IP checksum */
                data[begin_ip + 10] = 0;
                data[begin_ip + 11] = 0;
                *(uint16_t*)(data+begin_ip+10) = ip_fast_csum(data+begin_ip, 5);
            }
            break;
        }
        case PACKET_TYPE_IPV6_UDP:
        case PACKET_TYPE_IPV6_TCP:
        {
            int begin_ip = get_end_l2(port);
            if (bdk_unlikely(port_setup[port].src_port_inc))
            {
                int p = *(uint16_t*)(data + begin_ip + 40);
                p += port_setup[port].src_port_inc;
                if (p < port_setup[port].src_port_min)
                    p = port_setup[port].src_port_max;
                else if (p > port_setup[port].src_port_max)
                    p = port_setup[port].src_port_min;
                *(uint16_t*)(data + begin_ip + 40) = p;
            }

            if (bdk_unlikely(port_setup[port].dest_port_inc))
            {
                int p = *(uint16_t*)(data + begin_ip + 40 + 2);
                p += port_setup[port].dest_port_inc;
                if (p < port_setup[port].dest_port_min)
                    p = port_setup[port].dest_port_max;
                else if (p > port_setup[port].dest_port_max)
                    p = port_setup[port].dest_port_min;
                *(uint16_t*)(data + begin_ip + 40 + 2) = p;
            }

            if (bdk_unlikely(port_setup[port].src_ip_inc))
            {
                int64_t p = *(uint64_t*)(data+begin_ip+8+8);
                p += port_setup[port].src_ip_inc;
                if (p < port_setup[port].src_ip_min)
                    p = port_setup[port].src_ip_max;
                else if (p > port_setup[port].src_ip_max)
                    p = port_setup[port].src_ip_min;
                *(uint64_t*)(data+begin_ip+8+8) = p;
            }

            if (bdk_unlikely(port_setup[port].dest_ip_inc))
            {
                int64_t p = *(uint64_t*)(data+begin_ip+8+24);
                p += port_setup[port].dest_ip_inc;
                if (p < port_setup[port].dest_ip_min)
                    p = port_setup[port].dest_ip_max;
                else if (p > port_setup[port].dest_ip_max)
                    p = port_setup[port].dest_ip_min;
                *(uint64_t*)(data+begin_ip+8+24) = p;
            }
            break;
        }
        case PACKET_TYPE_802_3_PAUSE:
        case PACKET_TYPE_CBFC_PAUSE:
        case PACKET_TYPE_CJPAT:
            break;
    }

   /* Change MAC addresses */

   if (bdk_unlikely(port_setup[port].dest_mac_inc))
   {
        uint64_t m;
        char* mac = data + get_end_pre_l2(port);

        m = mac_to_uint64(mac);

        m += port_setup[port].dest_mac_inc;
        if ((m < port_setup[port].dest_mac_min) || (m > port_setup[port].dest_mac_max))
            m = port_setup[port].dest_mac_min;

        uint64_to_mac(m, mac);
    }

   if (bdk_unlikely(port_setup[port].src_mac_inc))
   {
        uint64_t m;
        char* mac = data + get_end_pre_l2(port) + MAC_ADDR_LEN;

        m = mac_to_uint64(mac);
        m += port_setup[port].src_mac_inc;
        if ((m < port_setup[port].src_mac_min) || (m > port_setup[port].src_mac_max))
            m = port_setup[port].src_mac_min;

        uint64_to_mac(m, mac);
    }
}

/**
 * Process an incomming ARP packet
 *
 * @param work   Work that was received. The is_arp fields has already been
 *               checked.
 * @return Zero if the caller should not free the packet data. Non
 *         zero if the caller should free the packet.
 */
static packet_free_t process_incomming_arp_packet(bdk_wqe_t *work)
{
    struct  arp_t *arp;
    uint8_t *ptr8;
    bdk_pko_command_word0_t pko_command;
    bdk_buf_ptr_t buffer_ptr = get_packet_buffer_ptr(work);

    arp = (struct arp_t *)bdk_phys_to_ptr(buffer_ptr.s.addr + get_end_l2(work->ipprt));

    /* Drop invalid ARP entries without processing */
    if ((arp->hw_addr_len != MAC_ADDR_LEN) || (arp->proto_addr_len != IP_ADDR_LEN))
        return PACKET_FREE;

    if (arp->opcode == ARP_REQUEST)
    {
        uint32_t dest_ip = *(uint32_t*)arp->dest_ip;

        bdk_atomic_add64(&port_state[work->ipprt].input_arp_requests, 1);

        /* Only respond to ARPs destine to the source IP or source IP range */
        if ((dest_ip == port_setup[work->ipprt].src_ip) ||
            ((dest_ip >= port_setup[work->ipprt].src_ip_min) &&
             (dest_ip <= port_setup[work->ipprt].src_ip_max)))
        {
            /* Check if we should auotmatically update our dest MAC to go the ARP requester */
            if (port_setup[work->ipprt].input_arp_request_enable)
            {
                port_setup[work->ipprt].dest_mac = *(uint64_t*)arp->src_mac >> 16;
                build_packet(work->ipprt);
            }

            /* Check if we should reply to the ARP */
            if (port_setup[work->ipprt].output_arp_reply_enable)
            {
                /* first swap outer MAC addresses for the packet */
                /* Note that we are currently not checking the our MAC address */
                ptr8 = bdk_phys_to_ptr(buffer_ptr.s.addr);
                memcpy(ptr8, (ptr8 + 6), 6);
                memcpy((ptr8 + 6), (uint8_t *)(&port_setup[work->ipprt].src_mac)+2, 6); /* assumes big endian*/

                /* set the opcode */
                arp->opcode = ARP_REPLY;

                /* next swap arp MAC and IP adddresses */
                memcpy(arp->dest_ip, arp->src_ip, IP_ADDR_LEN);
                memcpy(arp->dest_mac, arp->src_mac, MAC_ADDR_LEN);
                /* this code assumes big endian and uint32_t for ip, and uint64_t for mac's */
                memcpy(arp->src_mac, (uint8_t *)&port_setup[work->ipprt].src_mac + 2, MAC_ADDR_LEN);
                memcpy(arp->src_ip, &dest_ip, IP_ADDR_LEN);

                uint64_t queue = bdk_pko_get_base_queue(work->ipprt) + 1;  /* NOTE: use a different queue than normal*/
                bdk_spinlock_lock(&port_lock[work->ipprt]);
                bdk_pko_send_packet_prepare(work->ipprt, queue, BDK_PKO_LOCK_NONE);

                /* Build the PKO command */
                pko_command.u64 = 0;
                pko_command.s.dontfree =0;
                pko_command.s.segs = 1;
                pko_command.s.total_bytes = get_end_l2(work->ipprt) + 8 + 2*MAC_ADDR_LEN + 2*IP_ADDR_LEN;

                bdk_pko_status_t status = bdk_pko_send_packet_finish(work->ipprt, queue, pko_command, buffer_ptr, BDK_PKO_LOCK_NONE);
                bdk_spinlock_unlock(&port_lock[work->ipprt]);
                if (status == BDK_PKO_SUCCESS)
                {
                    bdk_atomic_add64(&port_state[work->ipprt].output_arp_replies, 1);
                    return (bdk_likely(work->word2.s.bufs == 0)) ? PACKET_DONT_FREE_WQE : PACKET_DONT_FREE;
                }
                else
                    return PACKET_FREE;
            }
        }
    }
    else if (arp->opcode == ARP_REPLY)
    {
        bdk_atomic_add64(&port_state[work->ipprt].input_arp_replies, 1);

        if (port_setup[work->ipprt].input_arp_reply_enable &&
            (*(uint32_t*)arp->dest_ip == port_setup[work->ipprt].src_ip))
        {   /* this controls dest mac updates for replys */
            port_setup[work->ipprt].dest_mac = *(uint64_t*)arp->src_mac >> 16;
            build_packet(work->ipprt);
        }
    }
    return PACKET_FREE;
}


static void dump_packet(bdk_wqe_t *work)
{
    uint64_t        count;
    uint64_t        remaining_bytes;
    bdk_buf_ptr_t  buffer_ptr;
    uint64_t        start_of_buffer;
    uint8_t *       data_address;
    uint8_t *       end_of_data;

    printf(GOTO_BOTTOM);
    printf("Packet Length:   %u\n", work->len);
    printf("    Input Port:  %u\n", work->ipprt);
    printf("    QoS:         %u\n", work->qos);
    printf("    Buffers:     %u\n", work->word2.s.bufs);
    if (work->word2.s.rcv_error)
        printf("    Error code:  %u\n", work->word2.s.err_code);

    buffer_ptr = get_packet_buffer_ptr(work);
    remaining_bytes = work->len;

    while (remaining_bytes)
    {
        start_of_buffer = ((buffer_ptr.s.addr >> 7) - buffer_ptr.s.back) << 7;
        printf("    Pool:        %u\n", buffer_ptr.s.pool);
        printf("    Address:     0x%llx\n", (ULL)buffer_ptr.s.addr);
        printf("                 ");
        data_address = (uint8_t *)bdk_phys_to_ptr(buffer_ptr.s.addr);
        end_of_data = data_address + buffer_ptr.s.size;
        count = 0;
        while (data_address < end_of_data)
        {
            if (remaining_bytes == 0)
                break;
            else
                remaining_bytes--;
            printf("%02x", (unsigned int)*data_address);
            data_address++;
            if (remaining_bytes && (count == 7))
            {
                printf("\n                 ");
                count = 0;
            }
            else
                count++;
        }
        printf("\n");

        if (remaining_bytes)
            buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.s.addr - 8);
    }
}


/**
 * Check the CRC on an incomming packet and return non zero if it
 * doesn't match the calculated value.
 *
 * @param work   Packet to process. We handle dynamic short.
 *
 * @return Non zero on CRC error
 */
static int is_packet_crc32c_wrong(bdk_wqe_t *work)
{
    uint32_t crc = 0xffffffff;
    bdk_buf_ptr_t buffer_ptr = get_packet_buffer_ptr(work);

    /* Get a pointer to the beginning of the packet */
    void *ptr = bdk_phys_to_ptr(buffer_ptr.s.addr);
    int remaining_bytes = work->len;

    /* Skip the L2 header in the CRC calculation */
    int skip = get_end_l2(work->ipprt);
    if (work->ipprt >= 40)
        skip += 8;
    ptr += skip;
    remaining_bytes -= skip;

    /* Reduce the length by 4, the length of the CRC at the end */
    remaining_bytes -= 4;

    /* Force the UDP checksum to zero for CRC calculation */
    if (!work->word2.s.not_IP && work->word2.s.tcp_or_udp)
    {
        int udp_checksum_offset = 0;
        if (work->word2.s.is_v6)
        {
            if (*(uint8_t*)(ptr + 6) == 0x11)
                udp_checksum_offset = get_size_ip_header(work->ipprt) + 6;
        }
        else
        {
            if (*(uint8_t*)(ptr + 9) == 0x11)
                udp_checksum_offset = get_size_ip_header(work->ipprt) + 6;
        }

        if (udp_checksum_offset)
        {
            uint16_t zero = 0;
            crc = crc32c(ptr,  udp_checksum_offset,  crc);
            crc = crc32c(&zero,  2,  crc);
            ptr += udp_checksum_offset + 2;
            remaining_bytes -= udp_checksum_offset + 2;
        }
    }

    while (remaining_bytes)
    {
        /* Figure out the maximum bytes this buffer could hold for us */
        void *start_of_buffer = bdk_phys_to_ptr(((buffer_ptr.s.addr >> 7) - buffer_ptr.s.back) << 7);
        int buffer_bytes = bdk_fpa_get_block_size(BDK_FPA_PACKET_POOL) - (ptr - start_of_buffer);
        if (bdk_likely(remaining_bytes <= buffer_bytes))
        {
            /* The rest of the crc data fits in this single buffer */
            crc = crc32c(ptr,  remaining_bytes,  crc);
            buffer_bytes -= remaining_bytes;
            /* Most of the time the CRC fits right after the data in the
                buffer. If it doesn't we need the next buffer too */
            if (bdk_likely(buffer_bytes >= 4))
                return (crc != *(uint32_t*)(ptr + remaining_bytes));
            else
            {
                if (bdk_likely(buffer_bytes))
                {
                    /* Read 4 bytes from right after the data */
                    uint32_t packet_crc1 = *(uint32_t*)(ptr + remaining_bytes);
                    /* AND off the lower bits that are actually in the next buffer */
                    packet_crc1 &= ~bdk_build_mask(8*(4-buffer_bytes));
                    /* Get a pointer to the next buffer. The rest of the CRC should
                    be at the beginning */
                    buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.s.addr - 8);
                    /* Read the rest of the CRC */
                    uint32_t packet_crc2 = *(uint32_t*)bdk_phys_to_ptr(buffer_ptr.s.addr);
                    /* Shift off extra bytes read since some bytes are stored in part 1*/
                    packet_crc2 >>= 32 - 8*(4-buffer_bytes);
                    /* Compare the final CRC with both parts put together */
                    return (crc != (packet_crc1|packet_crc2));
                }
                else
                {
                    /* Get a pointer to the next buffer. The CRC should be at the beginning */
                    buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.s.addr - 8);
                    /* Read the CRC */
                    uint32_t packet_crc = *(uint32_t*)bdk_phys_to_ptr(buffer_ptr.s.addr);
                    /* Compare the final CRC with both parts put together */
                    return (crc != packet_crc);
                }
            }
        }
        else
        {
            /* This buffer only contains part of our crc data */
            crc = crc32c(ptr, buffer_bytes,  crc);
            remaining_bytes -= buffer_bytes;
            /* Get a pointer to the next buffer */
            buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.s.addr - 8);
            ptr = bdk_phys_to_ptr(buffer_ptr.s.addr);
        }
    }
    return 0;
}


/**
 * Called from cores to perform processing on work received. This is called in the
 * transmit fastpath loop.
 *
 * @param work   Work to process
 * @return If the packet and work should be freed
 */
static packet_free_t fastpath_receive(bdk_wqe_t *work)
{
    if (bdk_unlikely(port_setup[work->ipprt].display_packet == 1))
        dump_packet(work);

    if (bdk_unlikely(work->word2.s.rcv_error))
    {
        bdk_atomic_add32(&port_state[work->ipprt].wqe_receive_errors[work->word2.s.err_code], 1);
        if (bdk_unlikely(port_setup[work->ipprt].display_packet == 2))
            dump_packet(work);
        return PACKET_FREE;
    }

    if (bdk_unlikely(port_setup[work->ipprt].validate))
    {
        if (bdk_unlikely(is_packet_crc32c_wrong(work)))
            bdk_atomic_add64(&port_state[work->ipprt].input_validation_errors, 1);
    }

    if (bdk_unlikely(port_setup[work->ipprt].bridge_port != BRIDGE_OFF))
    {
        int output_port = port_setup[work->ipprt].bridge_port;
        uint64_t queue = bdk_pko_get_base_queue(output_port) + 1;  /* NOTE: use a different queue than normal*/
        bdk_spinlock_lock(&port_lock[output_port]);
        bdk_pko_send_packet_prepare(output_port, queue, BDK_PKO_LOCK_NONE);

        /* Build the PKO command */
        bdk_pko_command_word0_t pko_command;
        pko_command.u64 = 0;
        pko_command.s.dontfree = 0;
        pko_command.s.segs = (work->word2.s.bufs) ? work->word2.s.bufs : 1;
        pko_command.s.total_bytes = work->len;

        bdk_buf_ptr_t buffer_ptr = get_packet_buffer_ptr(work);
        bdk_pko_status_t status = bdk_pko_send_packet_finish(output_port, queue, pko_command, buffer_ptr, BDK_PKO_LOCK_NONE);
        bdk_spinlock_unlock(&port_lock[output_port]);
        if (status == BDK_PKO_SUCCESS)
            return (bdk_likely(work->word2.s.bufs == 0)) ? PACKET_DONT_FREE_WQE : PACKET_DONT_FREE;
        else
            return PACKET_FREE;
    }
    else if (bdk_unlikely(work->word2.s.not_IP))
    {
        if (bdk_likely(work->word2.snoip.is_arp))
            return process_incomming_arp_packet(work);
        else
            return PACKET_FREE;
    }
    else
        return PACKET_FREE;
}


/**
 * Thread body for processing the output oftwo ports per
 * core. Transmit rate is controlled by the global structure
 * port_setup.
 *
 * @param port Port under control by this thread.
 */
static void packet_transmitter(int port)
{
    bdk_pko_command_word0_t    pko_command;
    bdk_buf_ptr_t              hw_buffer;
    uint64_t                   output_cycle;
    uint64_t                   count = 0;
    const uint64_t             queue = bdk_pko_get_base_queue(port);
    port_setup_t *             port_tx = port_setup + port;

    /* Build the PKO buffer pointer */
    hw_buffer.u64 = 0;
    hw_buffer.s.pool = BDK_FPA_PACKET_POOL;
    hw_buffer.s.size = 0xffff;
    hw_buffer.s.back = 0;
    hw_buffer.s.addr = bdk_ptr_to_phys(port_tx->output_data);

    /* Build the PKO command */
    pko_command.u64 = 0;
    pko_command.s.dontfree =1;
    pko_command.s.segs = 1;

    output_cycle = bdk_clock_get_count(BDK_CLOCK_CORE) << CYCLE_SHIFT;
    while (1)
    {
        if (bdk_likely(port_tx->output_enable && port_tx->output_cycle_gap))
        {
            uint64_t cycle = bdk_clock_get_count(BDK_CLOCK_CORE) << CYCLE_SHIFT;
            if (bdk_likely(cycle >= output_cycle))
            {
                bdk_pko_send_packet_prepare(port, queue, BDK_PKO_LOCK_NONE);
                packet_incrementer(port, port_tx->output_data);
                output_cycle += port_tx->output_cycle_gap;
                pko_command.s.total_bytes = port_tx->output_packet_size + get_size_pre_l2(port);
                if (port_tx->do_checksum)
                    pko_command.s.ipoffp1 = get_end_l2(port) + 1;
                else
                    pko_command.s.ipoffp1 = 0;
                /* We don't care if the send fails */
                bdk_pko_send_packet_finish(port, queue, pko_command, hw_buffer, BDK_PKO_LOCK_NONE);

                /* If we aren't keeping up, start send 4 more packets per iteration */
                if (bdk_unlikely(cycle > output_cycle + 500) && (count>4))
                {
                    uint64_t words[8] = {pko_command.u64, hw_buffer.u64, pko_command.u64, hw_buffer.u64, pko_command.u64, hw_buffer.u64, pko_command.u64, hw_buffer.u64};
                    output_cycle += port_tx->output_cycle_gap*4;
                    count -= 4;
                    if (bdk_likely(bdk_cmd_queue_write(BDK_CMD_QUEUE_PKO(queue), 0, 8, words) == BDK_CMD_QUEUE_SUCCESS))
                        bdk_pko_doorbell(port, queue, 8);
                }

                if (bdk_unlikely(--count == 0))
                {
                    port_tx->output_enable = 0;
                    count = port_tx->output_count;
                    BDK_SYNCW;
                }
            }
        }
        else
        {
            output_cycle = bdk_clock_get_count(BDK_CLOCK_CORE) << CYCLE_SHIFT;
            count = port_tx->output_count;
        }
        bdk_thread_yield();
    }
}


/**
 * Loops forever reading input packets
 */
static void packet_receiver(void)
{
    bdk_wqe_t *work;
    while (1)
    {
        work = bdk_sso_work_request_sync(BDK_SSO_NO_WAIT);
        if (work)
            process_work(work);
        else
            bdk_thread_yield();
    }
}


/**
 * Main entry point
 *
 * @return exit code
 */
int main(void)
{
    int port;

    {
        printf("\n\nOcteon Traffic Generator\n");
#if 0 // FIXME
        if (!bdk_is_simulation())
            ebt3000_str_write("Traffic");
#endif
        if (1)
        {
            printf("About to enable flow control.\nThis may hang if the terminal program is configured incorrectly\n");
            printf("Enabling UART flow control...\n");
            BDK_CSR_MODIFY(mcr, BDK_MIO_UARTX_MCR(0),
                mcr.s.afce = 1);
        }
        else
        {
            printf("Serial port flow control not supported, command pasting likely won't work.\n");
            printf("Screen updates may not be reliable.\n");
        }

        cpu_clock_hz = bdk_clock_get_rate(BDK_CLOCK_CORE);
        if (bdk_is_simulation())
            cpu_clock_hz = 1000000;

        printf(ERASE_WIN GOTO_BOTTOM);
        periodic_update(0);

        printf("Initializing...\n");

#if 0 // FIXME
        int chip = bdk_db_get_chipindex(bdk_get_proc_id());
        int csr_count = 0;
        while (bdk_csr_db_addresses[chip][csr_count].name)
        {
            csr_name_lut[csr_count] = (char*)bdk_csr_db_addresses[chip][csr_count].name;
            csr_count++;
        }
        csr_name_lut[csr_count] = NULL;
#endif
        memset(&port_state, 0, sizeof(port_state));
        memset(&port_setup, 0, sizeof(port_setup));
        /* Set the number of packet and WQE entries to be 16 less than the
            number of SSO entries. This way we never spill to ram */
        int num_packet_buffers = bdk_sso_get_num_entries() - 16;
        bdk_fpa_enable();
        bdk_fpa_fill_pool(BDK_FPA_PACKET_POOL, num_packet_buffers);
        bdk_fpa_fill_pool(BDK_FPA_WQE_POOL, num_packet_buffers);
        bdk_fpa_fill_pool(BDK_FPA_OUTPUT_BUFFER_POOL, BDK_PKO_MAX_OUTPUT_QUEUES*2);

        for (port=0; port<BDK_PIP_NUM_INPUT_PORTS; port++)
        {
            port_state[port].imode = BDK_HELPER_INTERFACE_MODE_DISABLED;
            /* Allocate a TX buffer for this port */
            port_setup[port].output_data = memalign(128, 65536);
            if (port_setup[port].output_data == NULL)
            {
                printf("Failed to allocate packet buffer for port %d\n", port);
                return -1;
            }
            /* Align the packet on the IP header */
            port_setup[port].output_data += 2;
            /* HiGig headers always start with 0xfb */
            port_setup[port].higig_header.dw0.s.start = 0xfb;
        }

        if (bdk_helper_interface_get_mode(4) == BDK_HELPER_INTERFACE_MODE_SRIO)
            bdk_srio_initialize(0, 0);
        if (bdk_helper_interface_get_mode(5) == BDK_HELPER_INTERFACE_MODE_SRIO)
            bdk_srio_initialize(1, 0);

        process_cmd_packetio(1);

        int num_interfaces = bdk_helper_get_number_of_interfaces();
        int interface;
        for (interface=0; interface < num_interfaces; interface++)
        {
            int do_display = 0;
            int num_ports = bdk_helper_ports_on_interface(interface);
            bdk_helper_interface_mode_t imode = bdk_helper_interface_get_mode(interface);
            switch (imode)
            {
                case BDK_HELPER_INTERFACE_MODE_DISABLED:
                case BDK_HELPER_INTERFACE_MODE_PCIE:
                case BDK_HELPER_INTERFACE_MODE_PICMG:
                case BDK_HELPER_INTERFACE_MODE_NPI:
                case BDK_HELPER_INTERFACE_MODE_LOOP:
                case BDK_HELPER_INTERFACE_MODE_SRIO:
                    break;
                case BDK_HELPER_INTERFACE_MODE_SGMII:
                case BDK_HELPER_INTERFACE_MODE_XAUI:
                    do_display = 1;
                    if (num_ports)
                    {
                        default_start_port = bdk_helper_get_ipd_port(interface, 0);
                        default_stop_port = bdk_helper_get_ipd_port(interface, num_ports-1);
                    }
                    break;
            }

            for (port=0; port<num_ports; port++)
            {
                int ipd_port = bdk_helper_get_ipd_port(interface, port);
                port_state[ipd_port].imode = imode;
                port_state[ipd_port].display = do_display;
                if (imode == BDK_HELPER_INTERFACE_MODE_SRIO)
                {
                    port_setup[ipd_port].srio.s.prio = 0;
                    port_setup[ipd_port].srio.s.tt = 1;
                    port_setup[ipd_port].srio.s.sis = 0;
                    port_setup[ipd_port].srio.s.ssize = 0xe;
                    port_setup[ipd_port].srio.s.did = 0xffff;
                    port_setup[ipd_port].srio.s.xmbox = 0;
                    port_setup[ipd_port].srio.s.mbox = port&3;
                    port_setup[ipd_port].srio.s.letter = 0;
                    port_setup[ipd_port].srio.s.lns = 0;
                    port_setup[ipd_port].srio.s.intr = 0;
                }
                if (port_state[ipd_port].imode != BDK_HELPER_INTERFACE_MODE_DISABLED)
                    bdk_thread_create(0, (bdk_thread_func_t)packet_transmitter, ipd_port, NULL);
            }
        }
        process_cmd_reset(0, BDK_PIP_NUM_INPUT_PORTS-1);
        bdk_thread_create(0, (bdk_thread_func_t)packet_receiver, 0, NULL);
        printf("Initialization Complete\n");
    }

    statistics_gatherer();

    return 0;
}
