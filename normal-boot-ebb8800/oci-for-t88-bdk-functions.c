
#include <bdk.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//################################################|#################################################
/*                                   oci-for-t88-bdk-functions.c
                      BDK Work-Around for 10G CCPI Lanes Hung in KR Training
    #############################################|##################################################
    
    When running on a dual-node, cn8800 pass-1.0 system with 10G CCPI links, this BDK-based
    software detects when 10G CCPI links have come up after cold booting with one or more
    lanes hung in 10G-KR training.  Running on the master node, this code will soft-reset both
    nodes until the CCPI link(s) are up with all their lanes operational.  In any case, a
    report of the status of the CCPI link(s) is printed on the master-node to aid in
    diagnosing CCPI problems.
    
    The corrective action to be taken if there are CCPI lane(s) hung in KR training requires
    that the CCPI links have come up so that remote CSR accesses are operating across the CCPI
    link(s).  With cn8800 pass-1.0 devices, this is the normal situation even if some lanes
    did not complete KR training.
    
    This code runs in the BDK's boot-stub.c's main function where it can take corrective
    action before the system is fully initialized and operational.  Even at this very early
    stage of the software boot process, the 10G CCPI system has long since finished KR
    training, so this code is reacting to training issues, it is not monitoring or controlling
    the KR training process as it happens.  Once this code finishes execution, it does not
    execute again until the next system boot; it does not correct issues with CCPI that occur
    after booting.
    
    Normal operating environment:
        * Dual-node systems of cn8800 pass-1.0 devices running 10G CCPI links
        * EBB8800 or EBB8804 boards
        * Dual 12 lane and dual 8 lane CCPI configurations
        * One or two CCPI links connected up.
        * A master node and a remotely booted "slave" node
    
    This code is compatible with:
        * Single-node systems
        * CCPI data rates that don't do 10G-KR training
        * Unused CCPI links
        * This code running on both nodes
        * Systems that fail to come up fully after a limited number of soft reset cycles
    
    This program determines the CCPI link configuration and data rate from local CSRs.  It
    detects unused links by checking that there are no "ready" lanes among those configured
    for the link.  This code takes action to correct CCPI hung lanes only if it is running on
    the master node, as determined by the BDK's bdk_numa_master() (normally Node-0).  This
    code needs no interaction with the user of the system.  This code uses
    soft-reset-persistent state (GSER module) to limit the number of corrective soft-reset
    cycles.  It checks the cause of booting (RST module) to differentiate its soft resets from
    cold boots.  The master node uses remote CSR accesses to soft reset the remote node.
    
    If both nodes are running BDKs incorporating this software, only software on the master
    node will take corrective action to fix problems it detects at its end of the link.  The
    slave node will merely report the condition of the CCPI links from its point of view.
    
    Prerequisits:
        * CN8800 pass 1.0 devices
        * EBB8800 or EBB8804 boards
        * A BDK with this code is running on the master node, normally Node-0.
    
        * CCPI is properly configured on both nodes: 
              * OCI_SPD baud rate straps not set for SW mode
              * LNK straps match on both nodes
              * Appropriate node ID strappings
    
        * The CCPI link(s) work well enough that the link(s) are up by the time the BDK is
          running.  The links may not have all their lanes, but remote CSR accesses must work.
    
    
    Cases Handled:
        * CCPI on both nodes is configured via the device pin-straps for 12-lanes. 
            * [ OCI2_LNK, OCI3_LNK ] = [0, 0]
            * Either one or both of the CCPI links are connected between the two Thunder
              devices.
    
        * CCPI on both nodes is configured via the device pin-straps for 8-lane links.
            * [ OCI2_LNK, OCI3_LNK ] = [1, 1]
            * Any one or two of the CCPI links are connected between the two Thunder devices.
            * If three links are wired between the cn8800s, Link-1 will be disregarded.  
    
        * CCPI strap-selected baud rate is set for any baud rate, not SW_MODE.  
    
        * Single-node systems where no CCPI lanes are wired up.  
        * Single CCPI link systems
    
        * BDK with this CCPI code is running on the master node (typically Node-0), and the
          other node is configured for remote booting.  
    
        * BDK with this CCPI code is running on both nodes.  Only the master node will take
          any actions to fix the CCPI links.  
    
    
    Cases NOT Handled:
        * Non-simultaneous cold booting of the two nodes - beyond ~0.5 sec apart.
        * Cold booting of one node, while the other node remains running.  
        * Reversed CCPI lanes.
    
    
    ##########################################################################################
    The entry point is the function:  run_boot_stub_ccpi()
  
    if  DISABLE_CCPI_TRN_WORKAROUND  is defined,
        run_boot_stub_ccpi() will exit immediately without doing anything.  


    CCPI Link States:
        Inactive:     Has zero QLM(s) assigned to the link.
        Down:         The link has QLMs but the QLMs have zero ready lanes.
        Active:       Has one or more QLM(s) assigned to the link.
        Up:           Has Interlaken 67-bit words, metaframes, CRC32.
        Operational:  Will support OCI traffic on all VCs.
  
*/
//################################################|#################################################

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//################################################|#################################################
//                                      CONSTANTS & DEFINES
//################################################|#################################################
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// #include "/nfs/dvps/jwise/OctValidate/ocx/includes/oci-definitions-for-t88-bdk.h"

//================================================|=================================================
//                                         OCX_Global_Info
//
typedef  struct OCX_Global_Info {
    uint     num_active_links ;
    int      active_links_array[  4 ];

    uint     num_lanes_for_link[  4 ];
    int      first_lane_for_link[ 4 ];

    uint     num_qlms_for_link[   4 ];
    int      first_qlm_for_link[  4 ];

    uint     num_gsers_for_link[  4 ];
    int      first_gser_for_link[ 4 ];

    uint     num_links_up ;
    int      up_links_array[ 4 ];
    bool     link_is_up[     4 ];

    uint     num_links_operational ;
    int      operational_links_array[ 4 ];    // [ num_links_operational ]
    bool     link_is_operational[     4 ];    // [ link_num ]

    int      num_operational_lanes_for_link[ 4 ];

    int      far_node_id;
    uint     link_baud_rate_kbaud;
    bool     oci_links_are_doing_training;

    int      dual_sort_mode ;

}  ocx_global_info_t ;



//================================================|=================================================
static const uint   GSER_Num_For_OCX_Lane[ 24 ] = {  8, 8, 8, 8
                                                  ,  9, 9, 9, 9
                                                  , 10,10,10,10
                                                  , 11,11,11,11
                                                  , 12,12,12,12
                                                  , 13,13,13,13
                                                  };


static const uint   GSER_Lane_Num_For_OCX_Lane[ 24 ] = {  0, 1, 2, 3
                                                       ,  0, 1, 2, 3
                                                       ,  0, 1, 2, 3
                                                       ,  0, 1, 2, 3
                                                       ,  0, 1, 2, 3
                                                       ,  0, 1, 2, 3
                                                       };



//================================================|=================================================
//                                          GSER DTX REGISTERS

//------------------------------------------------------------------------------
//                                rxtrain_sml
//
#define GSER_RX_TRAIN_SML_REG_DTX_ADR( gser_lane_num )   (0x30000 +( gser_lane_num *0x10))

#define EXTRACT_GSER_RXTRAIN_CU_PRE(  rxtrain_sml_csr_value )  ((rxtrain_sml_csr_value >> 34) & 0x03)
#define EXTRACT_GSER_RXTRAIN_CU_MAIN( rxtrain_sml_csr_value )  ((rxtrain_sml_csr_value >> 32) & 0x03)
#define EXTRACT_GSER_RXTRAIN_CU_POST( rxtrain_sml_csr_value )  ((rxtrain_sml_csr_value >> 30) & 0x03)

#define EXTRACT_GSER_RXTRAIN_SM(      rxtrain_sml_csr_value )  ((rxtrain_sml_csr_value >> 26) & 0x0F)
#define EXTRACT_GSER_RXTRAIN_SR_PRE(  rxtrain_sml_csr_value )  ((rxtrain_sml_csr_value >> 21) & 0x03)
#define EXTRACT_GSER_RXTRAIN_SR_MAIN( rxtrain_sml_csr_value )  ((rxtrain_sml_csr_value >> 19) & 0x03)
#define EXTRACT_GSER_RXTRAIN_SR_POST( rxtrain_sml_csr_value )  ((rxtrain_sml_csr_value >> 17) & 0x03)


typedef union
{
    uint64_t u;
    uint64_t u64;
    struct
    {
#if __BYTE_ORDER == __BIG_ENDIAN
        uint64_t  reserved_36_63 : 28;
        uint64_t  cu_pre         :  2;
        uint64_t  cu_main        :  2;
        uint64_t  cu_post        :  2;
        uint64_t  rxtrain_sm     :  4;
        uint64_t  lp_sr_sop      :  1;
        uint64_t  lp_sr_data     :  1;
        uint64_t  cu_send        :  1;
        uint64_t  sr_pre         :  2;
        uint64_t  sr_main        :  2;
        uint64_t  sr_post        :  2;
        uint64_t  sr_data        :  6;
        uint64_t  sr_sm          :  1;
        uint64_t  cu_data        :  9;
        uint64_t  cu_sm          :  1;
#else
        uint64_t  cu_sm          :  1;
        uint64_t  cu_data        :  9;
        uint64_t  sr_sm          :  1;
        uint64_t  sr_data        :  6;
        uint64_t  sr_post        :  2;
        uint64_t  sr_main        :  2;
        uint64_t  sr_pre         :  2;
        uint64_t  cu_send        :  1;
        uint64_t  lp_sr_data     :  1;
        uint64_t  lp_sr_sop      :  1;
        uint64_t  rxtrain_sm     :  4;
        uint64_t  cu_post        :  2;
        uint64_t  cu_main        :  2;
        uint64_t  cu_pre         :  2;
        uint64_t  reserved_36_63 : 28;
#endif
     } s ;
} gserx_lanex_rxtrain_sml_t ;


//------------------------------------------------------------------------------
//                                 rxtrain_smh

//$DBGNAME = GSER(0..13)_RXTRAIN_SMH(0..3)
//$DBGSEL = 0x3_0001 + (b)*0x10
// -------------------------------------------------------------------------
// Bit     Signal Name             Signal Path                     Module    
// -------------------------------------------------------------------------
// <35:18> 0x0                     NS                              NONE     
// <17>    csr_rxtrain_swmode_s    rx(b)                   gser_pnr_rxtrain 
// <16>    train_enable            rx(b)                   gser_pnr_rxtrain 
// <15>    preset                  rx(b)                   gser_pnr_rxtrain 
// <14>    initialize              rx(b)                   gser_pnr_rxtrain 
// <13>    cs_all_updated          rx(b)                   gser_pnr_rxtrain 
// <12>    cs_all_not_updated      rx(b)                   gser_pnr_rxtrain 
// <11>    cs_none_not_updated     rx(b)                   gser_pnr_rxtrain 
// <10>    taps_equalized          rx(b)                   gser_pnr_rxtrain 
// <9>     receiver_rdy            rx(b)                   gser_pnr_rxtrain 
// <8:7>   ld_pre_dir_s[1:0]       rx(b)                   gser_pnr_rxtrain 
// <6:5>   ld_main_dir_s[1:0]      rx(b)                   gser_pnr_rxtrain 
// <4:3>   ld_post_dir_s[1:0]      rx(b)                   gser_pnr_rxtrain 
// <2>     rx_req_eq_status        rx(b)                   gser_pnr_rxtrain 
// <1>     rx_eq_status_ack        rx(b)                   gser_pnr_rxtrain 
// <0>     cu_send                 rx(b)                   gser_pnr_rxtrain 
// -------------------------------------------------------------------------

#define GSER_RX_TRAIN_SMH_REG_DTX_ADR( gser_lane_num )   (0x30001 +( gser_lane_num *0x10))

#define EXTRACT_GSER_RXTRAIN_ENABLE(         rxtrain_smh_csr_value )  ((rxtrain_smh_csr_value >> 16) & 1)
#define EXTRACT_GSER_RXTRAIN_TAPS_EQUALIZED( rxtrain_smh_csr_value )  ((rxtrain_smh_csr_value >> 10) & 1)
#define EXTRACT_GSER_RXTRAIN_RECEIVER_RDY(   rxtrain_smh_csr_value )  ((rxtrain_smh_csr_value >>  9) & 1)

typedef union
{
    uint64_t u;
    uint64_t u64;
    struct
    {
#if __BYTE_ORDER == __BIG_ENDIAN
        uint64_t  reserved_18_63          : 46;
        uint64_t  csr_rxtrain_swmode_s    :  1;
        uint64_t  train_enable            :  1;
        uint64_t  preset                  :  1;
        uint64_t  initialize              :  1;
        uint64_t  cs_all_updated          :  1;
        uint64_t  cs_all_not_updated      :  1;
        uint64_t  cs_none_not_updated     :  1;
        uint64_t  taps_equalized          :  1;
        uint64_t  receiver_rdy            :  1;
        uint64_t  ld_pre_dir_s            :  2;
        uint64_t  ld_main_dir_s           :  2;
        uint64_t  ld_post_dir_s           :  2;
        uint64_t  rx_req_eq_status        :  1;
        uint64_t  rx_eq_status_ack        :  1;
        uint64_t  cu_send                 :  1;
#else
        uint64_t  cu_send                 :  1;
        uint64_t  rx_eq_status_ack        :  1;
        uint64_t  rx_req_eq_status        :  1;
        uint64_t  ld_post_dir_s           :  2;
        uint64_t  ld_main_dir_s           :  2;
        uint64_t  ld_pre_dir_s            :  2;
        uint64_t  receiver_rdy            :  1;
        uint64_t  taps_equalized          :  1;
        uint64_t  cs_none_not_updated     :  1;
        uint64_t  cs_all_not_updated      :  1;
        uint64_t  cs_all_updated          :  1;
        uint64_t  initialize              :  1;
        uint64_t  preset                  :  1;
        uint64_t  train_enable            :  1;
        uint64_t  csr_rxtrain_swmode_s    :  1;
        uint64_t  reserved_18_63          : 46;
#endif
     } s ;
} gserx_lanex_rxtrain_smh_t ;



//------------------------------------------------------------------------------
//                         gserx_lanex_txtrain_sm

//--------------------------------
// Bit      Signal Name           
//--------------------------------
// <35:27>  0x0                   
// <26>     csr_txtrain_swmode_s  
// <25>     dbg_train_enable      
// <24>     dbg_first_init        
// <23>     sr_ack                
// <22>     txtrain_sr_vld        
// <21:16>  sr_data[5:0]          
// <15>     sr_sm                 
// <14>     txtrain_cu_ack_s      
// <13>     cu_tx_update          
// <12>     dbg_lp_cu_data        
// <11>     dbg_lp_cu_sop         
// <10:2>   cu_data[8:0]          
// <1:0>    cu_sm[1:0]            

#define GSER_TX_TRAIN_SM_REG_DTX_ADR( gser_lane_num )   (0x20000 +( gser_lane_num *0x10))
#define EXTRACT_GSER_TXTRAIN_ENABLE( txtrain_sm_csr_value )  ((txtrain_sm_csr_value >> 25) & 1)

typedef union
{
    uint64_t u;
    uint64_t u64;
    struct
    {
#if __BYTE_ORDER == __BIG_ENDIAN
        uint64_t  reserved_27_63        : 37;
        uint64_t  csr_txtrain_swmode_s  :  1;
        uint64_t  dbg_train_enable      :  1;
        uint64_t  dbg_first_init        :  1;
        uint64_t  sr_ack                :  1;
        uint64_t  txtrain_sr_vld        :  1;
        uint64_t  sr_data               :  6;
        uint64_t  sr_sm                 :  1;
        uint64_t  txtrain_cu_ack_s      :  1;
        uint64_t  cu_tx_update          :  1;
        uint64_t  dbg_lp_cu_data        :  1;
        uint64_t  dbg_lp_cu_sop         :  1;
        uint64_t  cu_data               :  9;
        uint64_t  cu_sm                 :  2;
#else
        uint64_t  cu_sm                 :  2;
        uint64_t  cu_data               :  9;
        uint64_t  dbg_lp_cu_sop         :  1;
        uint64_t  dbg_lp_cu_data        :  1;
        uint64_t  cu_tx_update          :  1;
        uint64_t  txtrain_cu_ack_s      :  1;
        uint64_t  sr_sm                 :  1;
        uint64_t  sr_data               :  6;
        uint64_t  txtrain_sr_vld        :  1;
        uint64_t  sr_ack                :  1;
        uint64_t  dbg_first_init        :  1;
        uint64_t  dbg_train_enable      :  1;
        uint64_t  csr_txtrain_swmode_s  :  1;
        uint64_t  reserved_27_63        : 37;
#endif
     } s ;
} gserx_lanex_txtrain_sm_t ;



//------------------------------------------------------------------------------
//                       gserx_lanex_txtrain_dbg
//
// ------------------------------
// Bit      Signal Name          
// ------------------------------
// <35:34>  dbg_pre_state[1:0]   
// <33:32>  dbg_swing_state[1:0] 
// <31:30>  dbg_post_state[1:0]  
// <29:21>  dbg_tx_cu_data[8:0]  
// <20:17>  dbg_tx_pre[3:0]      
// <16:12>  dbg_tx_swing[4:0]    
// <11:7>   dbg_tx_post[4:0]     
// <6>      dbg_tx_coeff_req     
// <5>      dbg_phy_coeff_ack    
// <4>      dbg_tap_updated      
// <3:0>    dbg_txtrain_sm[3:0]  
// ------------------------------

#define GSER_TX_TRAIN_DBG_REG_DTX_ADR( gser_lane_num )   (0x20002 +( gser_lane_num *0x10))

#define EXTRACT_GSER_TXTRAIN_PRE_STATE(   txtrain_dbg_csr_value )  ((txtrain_dbg_csr_value >> 34) & 0x03)
#define EXTRACT_GSER_TXTRAIN_SWING_STATE( txtrain_dbg_csr_value )  ((txtrain_dbg_csr_value >> 32) & 0x03)
#define EXTRACT_GSER_TXTRAIN_POST_STATE(  txtrain_dbg_csr_value )  ((txtrain_dbg_csr_value >> 30) & 0x03)

#define EXTRACT_GSER_TXTRAIN_TX_CU_DATA(  txtrain_dbg_csr_value )  ((txtrain_dbg_csr_value >> 21) & 0x01FF)
#define EXTRACT_GSER_TXTRAIN_TX_PRE(      txtrain_dbg_csr_value )  ((txtrain_dbg_csr_value >> 17) & 0x0F)
#define EXTRACT_GSER_TXTRAIN_TX_SWING(    txtrain_dbg_csr_value )  ((txtrain_dbg_csr_value >> 12) & 0x1F)
#define EXTRACT_GSER_TXTRAIN_TX_POST(     txtrain_dbg_csr_value )  ((txtrain_dbg_csr_value >>  7) & 0x1F)
#define EXTRACT_GSER_TXTRAIN_SM(          txtrain_dbg_csr_value )  ((txtrain_dbg_csr_value      ) & 0x0F)

typedef union
{
    uint64_t u;
    uint64_t u64;
    struct
    {
#if __BYTE_ORDER == __BIG_ENDIAN
        uint64_t  reserved_36_63      : 28;
        uint64_t  dbg_pre_state       :  2;
        uint64_t  dbg_swing_state     :  2;
        uint64_t  dbg_post_state      :  2;
        uint64_t  dbg_tx_cu_data      :  9;
        uint64_t  dbg_tx_pre          :  4;
        uint64_t  dbg_tx_swing        :  5;
        uint64_t  dbg_tx_post         :  5;
        uint64_t  dbg_tx_coeff_req    :  1;
        uint64_t  dbg_phy_coeff_ack   :  1;
        uint64_t  dbg_tap_updated     :  1;
        uint64_t  dbg_txtrain_sm      :  4;
#else
        uint64_t  dbg_txtrain_sm      :  4;
        uint64_t  dbg_tap_updated     :  1;
        uint64_t  dbg_phy_coeff_ack   :  1;
        uint64_t  dbg_tx_coeff_req    :  1;
        uint64_t  dbg_tx_post         :  5;
        uint64_t  dbg_tx_swing        :  5;
        uint64_t  dbg_tx_pre          :  4;
        uint64_t  dbg_tx_cu_data      :  9;
        uint64_t  dbg_post_state      :  2;
        uint64_t  dbg_swing_state     :  2;
        uint64_t  dbg_pre_state       :  2;
        uint64_t  reserved_36_63      : 28;
#endif
     } s ;
} gserx_lanex_txtrain_dbg_t ;



//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//################################################|#################################################
//                                    FUNCTIONS IN THIS MODULE
//################################################|#################################################
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// <_function_prototypes_start_>

uint      count_ones(                                            uint num_bits,  uint bit_vector  );
int       find_least_signif_one(                                 uint num_bits,  uint bit_vector  );
uint64_t  get_3_ls_decimal_digits(                               uint64_t number );
uint      get_ocx_gser_baud_rate_in_kbaud(                       void );
bool      am_doing_link_training(                                void );
void      initialize_ocx_global_info(                            ocx_global_info_t * global_info_ptr );
uint      configure_global_info_for_oci_qlms(                    ocx_global_info_t * global_info_ptr );
void      display_ocx_global_info(                               ocx_global_info_t * global_info_ptr );
bool      oci_link_is_up(                                        int link_num );
int       remote_csr_read_on_t88(                                bdk_node_t target_node_id,  uint64_t address,  uint64_t * rd_data_wd_ptr,  int verbosity );

bool      reset_reason_was_soft_reset(                           void );
bool      reset_reason_was_warm_chip_reset(                      void );
bool      reset_reason_was_cold_chip_reset(                      void );
bool      reset_reason_was_oci_link_down(                        void );
void      display_reason_for_booting(                            void );

uint      read_local_gser_scratch_reg_16b(                       uint  gser_num );
int       write_local_gser_scratch_reg_16b(                      uint  gser_num,  uint  value );
uint      get_local_rdy_lane_flags_for_link(                     uint link_num,  ocx_global_info_t * global_info_ptr );
uint      find_num_of_unstuck_lanes_for_link(                    uint  link_num,  ocx_global_info_t * global_info_ptr  );
uint      update_globals_with_link_state(                        ocx_global_info_t * global_info_ptr  );
uint      find_number_of_up_links(                               ocx_global_info_t * global_info_ptr  );
uint      find_num_of_operational_lanes_for_link(                uint  link_num,  ocx_global_info_t * global_info_ptr  );
int       find_routing_node_id_of_lowest_num_link(               ocx_global_info_t * global_info_ptr  );
int       soft_reset_the_far_node(                               bdk_node_t  routing_node_id  );
void      soft_reset_the_local_node(                             void  );
void      display_oci_config_summary(                            ocx_global_info_t * global_info_ptr );
void      display_global_link_status(                            ocx_global_info_t * global_info_ptr );
void      display_operational_link_status(                       ocx_global_info_t * global_info_ptr );
uint64_t  convert_clk_cnt_to_usec(                               uint64_t interval_clks, uint64_t clk_freq_mhz );
void      disable_all_local_ocx_bad_lane_timeouts(               void  );
void      setup_stats_on_all_ocx_lanes(                          void );
void      enable_stats_on_all_ocx_lanes(                         void );
void      disable_then_clr_local_ocx_tlk_statistics(             uint  link_num  );
void      enable_local_ocx_tlk_statistics(                       uint  link_num  );
void      init_local_ocx_modes_intrs_stats(                      uint dual_sort_mode  );
int       init_local_oci_gser_dtx(                               uint  gser_num,  uint  gser_lane_num );
uint      read_crc32_errors_in_all_lanes_of_t88_link(            uint link_num,  ocx_global_info_t * global_info_ptr );
uint      read_crc32_errors_across_all_active_t88_links(         ocx_global_info_t * global_info_ptr  );
uint      manage_t88_links_coming_up(                            ocx_global_info_t * global_info_ptr );
uint64_t  get_t88_gser_rxtrain_sml_reg(                          uint gser_num,  uint gser_lane_num );
uint64_t  get_t88_gser_rxtrain_smh_reg(                          uint gser_num,  uint gser_lane_num );
uint64_t  get_t88_gser_txtrain_dbg_reg(                          uint gser_num,  uint gser_lane_num );
uint      find_local_t88_lanes_stuck_in_training(                int stuck_ocx_lane_nums_array[ 24 ],  bool ocx_lane_is_stuck_array[ 24 ]  );
bool      check_status_of_t88_link_lanes_qlms(                   bdk_node_t target_node_id,  uint  link_num,  ocx_global_info_t * global_info_ptr );
void      display_local_ocx_status_of_link_hdr(                  unsigned int link_num );
int       display_local_ocx_status_of_link(                      unsigned int link_num );

int       get_local_gser_rx_equal_figure_of_merit(               uint gser_num,  uint gser_lane_num  );
void      display_local_gser_rx_equal_figure_of_merits(          uint link_num,  ocx_global_info_t * global_info_ptr );

int       get_local_credits_for_vc(                              uint link_num,  uint vc_num,  uint * credits_avail,  uint * credits_to_rtn );
int       check_local_vc_credits_on_link(                        uint link_num  );
int       display_local_vc_credits_on_link(                      int link_num  );
bool      check_local_vc_credits_on_active_links(                ocx_global_info_t * global_info_ptr  );

int       check_for_bad_initial_ocx_state_on_link(               uint link_num  );
bool      check_local_t88_link_lane_qlm_status_of_active_links(  ocx_global_info_t * global_info_ptr  );
bool      check_local_t88_ocx_state_of_active_links(             ocx_global_info_t * global_info_ptr  );
bool      oci_link_is_operational(                               int link_num );
uint      find_number_of_operational_links(                      ocx_global_info_t * global_info_ptr  );
uint64_t  capture_local_t88_training_gser_activity(              uint ocx_lane_num );
void      display_t88_training_gser_activity_hdr_lane(           uint ocx_lane_num );
void      display_t88_training_gser_activity_hdr(                void  );
void      display_t88_training_gser_activity(                    uint64_t  capture_wd  );
int       log_2x12_t88_links_coming_up(                          void  );

int       run_boot_stub_ccpi(                                    void  );


// <_function_prototypes_end_>


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//################################################|#################################################
//                                            FUNCTIONS
//################################################|#################################################
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



//################################################|#################################################  // <_function_hdr_>
//                                            count_ones
//################################################|#################################################
uint      count_ones(               uint num_bits,  uint bit_vector  )         // <_function_>
{
    uint  ones_count  =  0 ;
    uint  shft_cnt ;
    uint  shifted_vector ;

    shifted_vector  =  bit_vector ;

    for( shft_cnt = 0;  shft_cnt < num_bits;  shft_cnt ++ )
    {
        if( (shifted_vector & 0x000001) == 1 )   ones_count ++ ;
        shifted_vector  =  shifted_vector >> 1 ;
    }
    return  ones_count ;
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                       find_least_signif_one
//################################################|#################################################
/*
    Arguments:
        num_bits:  how many bits of the  bit_vectore to scan, starting from bit 0.

    Returns:  -1 if no bits are set.
              or bit number of ls bit set.
 */
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int       find_least_signif_one(    uint num_bits,  uint bit_vector  )         // <_function_>
{
    uint  shft_cnt ;
    uint  shifted_vector ;
    int   ls_bit_set  =  -1 ;

    shifted_vector  =  bit_vector ;

    for( shft_cnt = 0;  shft_cnt < num_bits;  shft_cnt ++ )
    {
        if( (shifted_vector & 0x000001) == 1 )
        {
            ls_bit_set  =  shft_cnt ;
            break ;
        }
        shifted_vector  =  shifted_vector >> 1 ;
    }
    return  ls_bit_set ;
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                    
//################################################|#################################################
uint64_t  get_3_ls_decimal_digits(  uint64_t number )                          // <_function_>
{
    uint64_t thousands ;
    uint64_t units ;

    thousands  =  number / 1000 ;
    units      =  number - ( thousands * 1000 );

    return  units ;
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                 get_ocx_gser_baud_rate_in_kbaud
//################################################|#################################################
/*
        Reads the SPD of the first of the OCI GSERs.
 */
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
uint      get_ocx_gser_baud_rate_in_kbaud(            void )                     // <_function_>
{
    const bdk_node_t   loc_node_id  =  bdk_numa_local();

    uint               gser_num ;
    bdk_gserx_spd_t    gserx_spd_csr ;
    uint               gser_spd_code ;
    uint               gser_spd_kbaud ;

    // KBd:                                1,250,000 KBd
    //                                    10,312,500 KBd
    uint   gser_baud_rate_code_table[]  =  {  1250000
                                           ,  2500000
                                           ,  5000000
                                           ,  8000000
                                           ,  1250000
                                           ,  2500000
                                           ,  3125000
                                           ,  5000000
                                           ,  6250000
                                           ,  8000000
                                           ,  2500000
                                           ,  3125000
                                           ,  5000000
                                           ,  6250000
                                           , 10312500
                                           ,  0000000 
                                           };

    //==============================================================================================
    gser_num  =  8 ;    // the first of the OCI GSERs.

    gserx_spd_csr.u  =  BDK_CSR_READ( loc_node_id, BDK_GSERX_SPD( gser_num ) );
    gser_spd_code    =  gserx_spd_csr.s.spd ;

    gser_spd_code   =  gser_spd_code  &  0x0F ;
    gser_spd_kbaud  =  gser_baud_rate_code_table[ gser_spd_code ];

    return  gser_spd_kbaud ;
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                      am_doing_link_training
//################################################|#################################################
bool      am_doing_link_training(                     void )                       // <_function_>
{
    bool   oci_links_are_doing_training ;
    uint   oci_baud_rate_kbd ;
    uint   highest_baud_rate_not_training ;

    highest_baud_rate_not_training  =  8000000 ;  // kbaud  - for t88

    //----------------------------------------------------------------------------------------------
    oci_baud_rate_kbd  =  get_ocx_gser_baud_rate_in_kbaud();

    if( oci_baud_rate_kbd > highest_baud_rate_not_training )   oci_links_are_doing_training  =  true ;
    else                                                       oci_links_are_doing_training  =  false ;

    return  oci_links_are_doing_training ;
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                   initialize_ocx_global_info
//################################################|#################################################
void      initialize_ocx_global_info(      ocx_global_info_t * global_info_ptr )     // <_function_>
{
    global_info_ptr-> num_active_links       =  0 ;
    global_info_ptr-> num_links_up           =  0 ;
    global_info_ptr-> num_links_operational  =  0 ;

    global_info_ptr-> far_node_id           =  -1 ;
    global_info_ptr-> link_baud_rate_kbaud  =   0 ;

    global_info_ptr-> oci_links_are_doing_training  =  false ;

    for( int index = 0;  index < 4;  index ++ )
    {
        global_info_ptr-> active_links_array[      index ]  =  -1 ;
        global_info_ptr-> operational_links_array[ index ]  =  -1 ;
        global_info_ptr-> link_is_operational[     index ]  =  -1 ;

        global_info_ptr-> num_lanes_for_link[  index ]  =   0 ;
        global_info_ptr-> first_lane_for_link[ index ]  =   0 ;
        global_info_ptr-> num_qlms_for_link[   index ]  =   0 ;
        global_info_ptr-> first_qlm_for_link[  index ]  =   0 ;
        global_info_ptr-> num_gsers_for_link[  index ]  =   0 ;
        global_info_ptr-> first_gser_for_link[ index ]  =   0 ;

        global_info_ptr-> up_links_array[      index ]  =  -1 ;
        global_info_ptr-> link_is_up[          index ]  =  false ;

        global_info_ptr-> num_operational_lanes_for_link[ index ]  =  0 ;
    }
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                               configure_global_info_for_oci_qlms
//################################################|#################################################
/*

Configurations with EBB Cables for lanes for two active links:

                           Link-0                        Link-1                    Link-2
              ---------------------------------                       ---------------------------------
 Config 0:    OCI-QLM-0 + OCI-QLM-1 + OCI-QLM-2                       OCI-QLM-3 + OCI-QLM-4 + OCI-QLM-5
  1st Lane:       0          4           8                               12           16         20

  EBB Cables  ---------------------   -----------------------------------------   ---------------------
                                                                        
                           
                           Link-0                        Link-1                           Link-2
              ---------------------------------         ---------                 ---------------------
 Config 1:    OCI-QLM-0 + OCI-QLM-1 + OCI-QLM-2         OCI-QLM-3                 OCI-QLM-4 + OCI-QLM-5
  1st Lane:       0           4           8                12                        16          20

  EBB Cables  ---------------------   ---------------------------                 .....................


                      Link-0                              Link-1                          Link-2
              ---------------------               ---------------------           ---------------------
 Config 2:    OCI-QLM-0 + OCI-QLM-1               OCI-QLM-2 + OCI-QLM-3           OCI-QLM-4 + OCI-QLM-5
  1st Lane:       0          4                        8          12                   16          20

  EBB Cables  .....................               .....................           .....................
  EBB Cables  ---------------------               ---------------------
  EBB Cables  ---------------------                                               ---------------------
  EBB Cables                                      ---------------------           ---------------------


 */
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
uint      configure_global_info_for_oci_qlms(         ocx_global_info_t * global_info_ptr )     // <_function_>
{
    uint  num_links_with_qlms ;
    uint  qlm_select_bit_vector ;

    uint  link_num ;
    uint  num_qlms ;
    int   first_qlm ;
    const uint  num_bits  =  6 ;

    uint  num_lanes ;
    int   first_lane ;

    int   first_gser ;
    uint  num_gsers ;

    uint  links_with_qlms[ 4 ];
    uint  link_index ;

    uint  rdy_lane_flags ;
    uint  num_rdy_lanes ;

    const int  loc_node_id  =  bdk_numa_local();

    // OCX_LNK(0..2)_CFG:  QLM_SELECT, etc.
    bdk_ocx_lnkx_cfg_t   ocx_lnkx_cfg_csr ;


    uint  link_to_drop  =  1 ;
    uint  num_active_links  =  0 ;

    uint  oci_link_baud_rate_kbaud ;


    //==============================================================================================
    num_links_with_qlms  =  0 ;

    for( link_num = 0;  link_num < 3;  link_num ++ )
    {
//        printf("> configure_global_info_for_oci_qlms:  link_num = %u \n", link_num );

        // QLMs for link
        ocx_lnkx_cfg_csr.u     =  BDK_CSR_READ( loc_node_id, BDK_OCX_LNKX_CFG( link_num ));
        qlm_select_bit_vector  =  ocx_lnkx_cfg_csr.s.qlm_select ;

        qlm_select_bit_vector  &=  0x03F ;
//        printf("> configure_global_info_for_oci_qlms:      qlm_select_bit_vector  = 0x%02X \n", qlm_select_bit_vector );

        num_qlms    =  count_ones(  num_bits, qlm_select_bit_vector  );
//        printf("> configure_global_info_for_oci_qlms:      num_qlms   = %2u \n", num_qlms );

        if( num_qlms == 0 )
        {
            // There are NO  QLMs for this link!
            //
            first_qlm   =  -1 ;

            first_lane  =  -1 ;
            num_lanes   =   0 ;

            first_gser  =  -1 ;
            num_gsers   =   0 ;
        }
        else
        {
            // There is at least one QLM for this link!
            //
            first_qlm   =  find_least_signif_one(  num_bits, qlm_select_bit_vector  );

            first_lane  =  first_qlm * 4 ;
            num_lanes   =  4 * num_qlms ;

            first_gser  =  first_qlm + 8 ;
            num_gsers   =  num_qlms ;
        }

//        printf("> configure_global_info_for_oci_qlms:      first_qlm  = %2d \n", first_qlm );
//        printf("> configure_global_info_for_oci_qlms:      first_lane = %2d \n", first_lane );
//        printf("> configure_global_info_for_oci_qlms:      num_lanes  = %2u  \n", num_lanes );
//        printf("> configure_global_info_for_oci_qlms:      first_gser = %2d \n", first_gser );
//        printf("> configure_global_info_for_oci_qlms:      num_gsers  = %2u  \n", num_gsers );


        //------------------------------------------------------------------------------------------
        if( num_qlms > 0 )
        {
            // This Link has QLMs!
            //
            links_with_qlms[ num_links_with_qlms ]  =  link_num ;
            num_links_with_qlms ++ ;

            global_info_ptr-> num_lanes_for_link[  link_num ]  =  num_lanes ;
            global_info_ptr-> first_lane_for_link[ link_num ]  =  first_lane ;

            global_info_ptr-> num_qlms_for_link[   link_num ]  =  num_qlms ;
            global_info_ptr-> first_qlm_for_link[  link_num ]  =  first_qlm ;

            global_info_ptr-> num_gsers_for_link[  link_num ]  =  num_gsers ;
            global_info_ptr-> first_gser_for_link[ link_num ]  =  first_gser ;
        }
        // else  - No QLMs!  -  use defaults

    } // for loop

//    printf("> \n");


    //----------------------------------------------------------------------------------------------
    //                                  Find the Active Links
    //
    //                         Active links have at least one ready lane!
    //                Inactive links are not wired to the other t88, so have ZERO ready lanes!
    //
    num_active_links  =  0 ;

    for( link_index = 0;  link_index < num_links_with_qlms ;  link_index ++ )
    {
        link_num  =  links_with_qlms[ link_index ];

        // See if this link has any RDY lanes, if there are NONE, it is not active!
        rdy_lane_flags  =  get_local_rdy_lane_flags_for_link(  link_num,  global_info_ptr );
        num_rdy_lanes   =  count_ones( 16, rdy_lane_flags );

        if( num_rdy_lanes > 0 )
        {
            global_info_ptr-> active_links_array[ num_active_links ]  =  link_num ;
            num_active_links ++ ;
        }

    } // for

    global_info_ptr-> num_active_links  =  num_active_links ;


    //----------------------------------------------------------------------------------------------
    //              If there are three Active Links...  At most two links can be active
    //
    if( num_active_links >= 3 )
    {
        // Go back through the links with QLMs, dropping one link

        num_active_links  =  0 ;
        //
        for( link_index = 0;  link_index < num_links_with_qlms ;  link_index ++ )
        {
            link_num  =  links_with_qlms[ link_index ];

            if( link_num != link_to_drop )
            {
                // Keep this link!
                global_info_ptr-> active_links_array[ num_active_links ]  =  link_num ;
                num_active_links ++ ;
            }
            // else  -  Drop this Link

        }

        global_info_ptr-> num_active_links  =  num_active_links ;
    }


//    //----------------------------------------------------------------------------------------------
////    printf("> configure_global_info_for_oci_qlms:  num_links_with_qlms = %u \n", num_links_with_qlms );
//    num_active_links  =  0 ;
//
//    if( num_links_with_qlms >= 3)
//    {
//        // Too many links have QLMs!  There can be at most 2 active links:  Link-0 and Lnik-2.
//        //
//        for( link_index = 0;  link_index < num_links_with_qlms ;  link_index ++ )
//        {
//            link_num  =  links_with_qlms[ link_index ];
//
//            // Drop a Link:
//            if( link_num != link_to_drop )
//            {
//                // Not the Link to Drop:
//                global_info_ptr-> active_links_array[ num_active_links ]  =  link_num ;
//                num_active_links ++ ;
//            }
//            // else  -  Drop this Link
//
//        } // for
//    }
//    //----------------------------------------------------------------------------------------------
//    else
//    {
//        // There are NOT too many links - copy all the info to the global vars:
//        //
//        for( link_index = 0;  link_index < num_links_with_qlms ;  link_index ++ )
//        {
//            link_num  =  links_with_qlms[ link_index ];
//
//            global_info_ptr-> active_links_array[ num_active_links ]  =  link_num ;
//            num_active_links ++ ;
//        } // for
//    }
//
//    //----------------------------------------------------------------------------------------------
//    global_info_ptr-> num_active_links  =  num_active_links ;


    //----------------------------------------------------------------------------------------------
    //                                      Doing Link Training ?
    //
    if(  am_doing_link_training()  )   global_info_ptr-> oci_links_are_doing_training  =  true ;
    else                               global_info_ptr-> oci_links_are_doing_training  =  false ;


    //----------------------------------------------------------------------------------------------
    //                                      Link Baud Rate
    //
    oci_link_baud_rate_kbaud  =  get_ocx_gser_baud_rate_in_kbaud();
    global_info_ptr-> link_baud_rate_kbaud  =  oci_link_baud_rate_kbaud ;


    //==============================================================================================
    return  num_active_links ;

} // configure_global_info_for_oci_qlms              // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                     display_ocx_global_info
//################################################|#################################################
void      display_ocx_global_info(  ocx_global_info_t * global_info_ptr )        // <_function_>
{
    printf(" ocx_global_info: \n");
    printf("     num_active_links:  %u \n", global_info_ptr-> num_active_links );

    for( int index = 0;  index < 3;  index ++ )
    {
        printf("     Index-%d: \n", index );
        printf("         active_links_array:   %2d \n", global_info_ptr-> active_links_array[  index ] );
    }
    printf(" \n");

    printf("     far_node_id:   %d   ( -1:  unconfigured) \n", global_info_ptr-> far_node_id );
    printf("     link_baud_rate:   %d  KBaud \n", global_info_ptr-> link_baud_rate_kbaud );
    printf("     oci_links_are_doing_training:  %d  (0= false, 1= true) \n", global_info_ptr-> oci_links_are_doing_training );
    printf(" \n");

    printf("     num_links_up:      %u \n", global_info_ptr-> num_links_up );
    for( int index = 0;  index < 3;  index ++ )
    {
        printf("         up_links_array[ %d ]:   %2d \n", index, global_info_ptr-> up_links_array[      index ] );
    }
    printf(" \n");

    for( int index = 0;  index < 3;  index ++ )
    {
        printf("         link_is_up[ %d ]:       %2d  (0= false, 1= true) \n", index, global_info_ptr-> link_is_up[          index ] );
    }
    printf(" \n");


    for( int index = 0;  index < 3;  index ++ )
    {
        printf("     Link-%d: \n", index );
        printf("         first_lane_for_link:  %2d \n", global_info_ptr-> first_lane_for_link[ index ] );
        printf("         num_lanes_for_link:   %2u \n", global_info_ptr-> num_lanes_for_link[  index ] );
        printf("         first_qlm_for_link:   %2d \n", global_info_ptr-> first_qlm_for_link[  index ] );
        printf("         num_qlms_for_link:    %2u \n", global_info_ptr-> num_qlms_for_link[   index ] );
        printf("         first_gser_for_link:  %2d \n", global_info_ptr-> first_gser_for_link[ index ] );
        printf("         num_gsers_for_link:   %2u \n", global_info_ptr-> num_gsers_for_link[  index ] );
        printf(" \n");
    }
} // display_ocx_global_info                         // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                     oci_link_is_up
//################################################|#################################################
/*
    The link has QLMs and it is UP at the Interlacken level  per OCX_COM_LINK(0..2)_CTL
 */
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
bool      oci_link_is_up(                             int link_num )       // <_function_>
{
    const bdk_node_t         loc_node_id  =  bdk_numa_local();
    bdk_ocx_com_linkx_ctl_t  com_link_ctl_csr ;

    com_link_ctl_csr.u  =  BDK_CSR_READ(  loc_node_id, BDK_OCX_COM_LINKX_CTL( link_num ));
 
    if( (com_link_ctl_csr.s.valid == 1)  &&  (com_link_ctl_csr.s.up == 1) )  return  true ;
    else                                                                     return  false ;
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                     remote_csr_read_on_t88
//################################################|#################################################
/* 
    Based on the BDK's ocx_pp_read() function, but with a success result returned, and the read 
    value written onto an argument

    Returns:  -1 if there was an error reading the remote CSR.
*/          
//================================================|=================================================
int       remote_csr_read_on_t88( bdk_node_t target_node_id,  uint64_t address,  uint64_t * rd_data_wd_ptr,  int verbosity )  // <_function_>
{
    int  result  =  0 ;

    //----------------------------------------------------------------------------------------------
    target_node_id  =  target_node_id & 0x03 ;    // Limit to two bits.

    if( address & (1ull << 47))   address |= ( uint64_t )target_node_id << 44;
    else                          address |= ( uint64_t )target_node_id << 40;

    //----------------------------------------------------------------------------------------------
    BDK_CSR_DEFINE( pp_cmd, BDK_OCX_PP_CMD );
    pp_cmd.u = 0;

    pp_cmd.s.ld_cmd = 3 ;    // 8 byte load
    pp_cmd.s.ld_op  = 1 ;    // 1= load = rd, 0= store = write
    pp_cmd.s.addr   = address;

    BDK_CSR_WRITE( bdk_numa_local(), BDK_OCX_PP_RD_DATA, -1   );
    BDK_CSR_WRITE( bdk_numa_local(), BDK_OCX_PP_CMD, pp_cmd.u );

    /* Wait for 1ms for read ot complete */
    if( BDK_CSR_WAIT_FOR_FIELD( bdk_numa_local(), BDK_OCX_PP_RD_DATA, data, !=, 0xffffffffffffffffull, 1000 ))
    {
        printf("> *** Error in  remote_csr_read_on_t88:  Node-%d:  Timeout reading CSR on Node-%d   at address:  0x%016lu \n", bdk_numa_local(), target_node_id, address );
        * rd_data_wd_ptr  =  0xffffffffffffffffull ;
        result  =  -1 ;
    }
    else
    {
        * rd_data_wd_ptr  =  BDK_CSR_READ( bdk_numa_local(), BDK_OCX_PP_RD_DATA );
        result  =  0 ;
    }

    //----------------------------------------------------------------------------------------------
    return  result ;

} // remote_csr_read_on_t88                          // <_function_end_>




//################################################|#################################################  // <_function_hdr_>
//                                     remote_csr_write_on_t88
//################################################|#################################################
/* 
    Based on the BDK's ocx_pp_read() function, but with a success result returned, and the read 
    value written onto an argument

    Returns:  -1 if there was an error reading the remote CSR.
*/          
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int       remote_csr_write_on_t88( bdk_node_t target_node_id,  uint64_t address,  uint64_t data, int verbosity )   // <_function_>
{
    int  result  =  0 ;

    //----------------------------------------------------------------------------------------------
    target_node_id  =  target_node_id & 0x03 ;    // Limit to two bits.

    if( address & (1ull << 47))   address |= ( uint64_t )target_node_id << 44;
    else                          address |= ( uint64_t )target_node_id << 40;

    //----------------------------------------------------------------------------------------------
    BDK_CSR_DEFINE( pp_cmd, BDK_OCX_PP_CMD );
    pp_cmd.u = 0;
    pp_cmd.s.wr_mask = 0xff;
    pp_cmd.s.addr = address;

    BDK_CSR_WRITE( bdk_numa_local(), BDK_OCX_PP_WR_DATA, data );
    BDK_CSR_WRITE( bdk_numa_local(), BDK_OCX_PP_CMD, pp_cmd.u );

    //----------------------------------------------------------------------------------------------
    return  result ;

} // remote_csr_write_on_t88                          // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                         reset_was_soft
//################################################|#################################################
bool      reset_reason_was_soft_reset(              void )                         // <_function_>
{
    const bdk_node_t   loc_node_id  =  bdk_numa_local();    // 0 or 1
    bdk_rst_boot_t     rst_boot_csr ;
    unsigned int       reset_bit ;
    
    rst_boot_csr.u  =  BDK_CSR_READ( loc_node_id, BDK_RST_BOOT );
    reset_bit       =  ( rst_boot_csr.s.lboot >> 8 )  &  0x0001 ;

    if( reset_bit == 1 )  return  true ;
    else                             return  false ;
}                                                    // <_function_end_>


//################################################|#################################################  // <_function_hdr_>
//                                     reset_was_warm_chip_reset
//################################################|#################################################
bool      reset_reason_was_warm_chip_reset(   void )                               // <_function_>
{
    const bdk_node_t   loc_node_id  =  bdk_numa_local();    // 0 or 1
    bdk_rst_boot_t     rst_boot_csr ;
    unsigned int       reset_bit ;

    rst_boot_csr.u  =  BDK_CSR_READ( loc_node_id, BDK_RST_BOOT );
    reset_bit       =  ( rst_boot_csr.s.lboot >> 1 )  &  0x0001 ;

    if( reset_bit == 1 )  return  true ;
    else                  return  false ;
}                                                    // <_function_end_>


//################################################|#################################################  // <_function_hdr_>
//                                     reset_was_cold_chip_reset
//################################################|#################################################
bool      reset_reason_was_cold_chip_reset(   void )                               // <_function_>
{
    const bdk_node_t   loc_node_id  =  bdk_numa_local();    // 0 or 1
    bdk_rst_boot_t     rst_boot_csr ;
    unsigned int       reset_bit ;

    rst_boot_csr.u  =  BDK_CSR_READ( loc_node_id, BDK_RST_BOOT );
    reset_bit       =  rst_boot_csr.s.lboot  &  0x0001 ;

    if( reset_bit == 1 )  return  true ;
    else                  return  false ;
}                                                    // <_function_end_>


//################################################|#################################################  // <_function_hdr_>
//                                     reset_was_oci_link_down
//################################################|#################################################
bool      reset_reason_was_oci_link_down(     void )                               // <_function_>
{
    const bdk_node_t   loc_node_id  =  bdk_numa_local();    // 0 or 1
    bdk_rst_boot_t     rst_boot_csr ;
    unsigned int       reset_bits ;

    rst_boot_csr.u  =  BDK_CSR_READ( loc_node_id, BDK_RST_BOOT );
    reset_bits      =  rst_boot_csr.s.lboot_oci  &  0x0007 ;

    if( reset_bits > 0 )  return  true ;
    else                  return  false ;
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                     display_reason_for_booting
//################################################|#################################################
void      display_reason_for_booting(  void  )               // <_function_>
{
//    const bdk_node_t  loc_node_id  =  bdk_numa_local();

    bool  found_restart_cause ;


    //==============================================================================================
    found_restart_cause   =  false ;

    if( reset_reason_was_cold_chip_reset() )   
    {
        printf(" Booting after a cold chip reset. \n");
        found_restart_cause  =  true ;
    }
    if( reset_reason_was_warm_chip_reset() )   
    {
        printf(" Booting after a warm chip reset. \n");
        found_restart_cause  =  true ;
    }
    if( reset_reason_was_soft_reset() )              
    {
        printf(" Booting after a soft reset. \n");
        found_restart_cause  =  true ;
    }
    if( reset_reason_was_oci_link_down() )              
    {
        printf(" Booting after an OCI Link went down. \n");
        found_restart_cause   =  true ;
    }


    //--------------------------------------------------------------------------
    if( ! found_restart_cause )
    {
        printf(" *** Found no reason for Booting. \n");
    }

    //--------------------------------------------------------------------------

} // display_reason_for_booting                      // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                     clear_reasons_for_booting
//################################################|#################################################
void      clear_reasons_for_booting(  void  )               // <_function_>
{
    const bdk_node_t  loc_node_id  =  bdk_numa_local();

//    bool  found_restart_cause ;


    //==============================================================================================
    //                     Clear the "cause-of-boot" bits:  W1C
    //
    BDK_CSR_MODIFY( csr, loc_node_id, BDK_RST_BOOT,
                    csr.s.lboot_oci = -1;

                    csr.s.lboot_ext45 = -1;
                    csr.s.lboot_ext23 = -1;

                    csr.s.lboot = -1
                  );

} // clear_reasons_for_booting                      // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                   read_local_gser_scratch_reg_16b
//################################################|#################################################
uint      read_local_gser_scratch_reg_16b(   uint  gser_num )                          // <_function_>
{
    const bdk_node_t     loc_node_id    =  bdk_numa_local();

    // GSER(0..13)_SCRATCH:   BDK_GSERX_SCRATCH
    bdk_gserx_scratch_t   gserx_scratch_csr ;
    uint                  scratch ;
//    int                   result     =  0 ;

    //==============================================================================================
    gserx_scratch_csr.u  =  BDK_CSR_READ(  loc_node_id, BDK_GSERX_SCRATCH( gser_num )  );

    scratch  =  gserx_scratch_csr.s.scratch  &  0x0FFFF ;
    return  scratch ;
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                   write_local_gser_scratch_reg_16b
//################################################|#################################################
int       write_local_gser_scratch_reg_16b(   uint  gser_num,  uint  value )            // <_function_>
{
    const bdk_node_t     loc_node_id    =  bdk_numa_local();

    // GSER(0..13)_SCRATCH:   BDK_GSERX_SCRATCH
    bdk_gserx_scratch_t   gserx_scratch_csr ;

    int                   result     =  0 ;

    //==============================================================================================
    gserx_scratch_csr.u          =  0 ;
    gserx_scratch_csr.s.scratch  =  value  &  0x0FFFF;  // limit to 16 bits

    BDK_CSR_WRITE( loc_node_id, BDK_GSERX_SCRATCH( gser_num ), gserx_scratch_csr.u );

    BDK_WMB ;

    //==============================================================================================
    return  result ;
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                     get_local_rdy_lane_flags
//################################################|#################################################
/*                               
    - Returns the ready-lane flags of all QLMs of the link.  From the highest-numbered lane
      down to lowest-numbered

    - target_node_id:  can be the local node ID or a remote node ID
 */
//==================================================================================================
uint      get_local_rdy_lane_flags_for_link(   uint link_num,  ocx_global_info_t * global_info_ptr )    // <_function_>
{
    const bdk_node_t     loc_node_id    =  bdk_numa_local();
    bdk_ocx_qlmx_cfg_t   ocx_qlmx_cfg_csr ;

    uint   qlm_num ;
    uint   iter_num ;
    uint   rdy_lane_flags    =  0 ;

    const uint   num_qlms       =  global_info_ptr-> num_qlms_for_link[  link_num ];
    const uint   first_qlm_num  =  global_info_ptr-> first_qlm_for_link[ link_num ]; 


    //==============================================================================================
    //             For Each OCI QLM in the Link, starting with the most significant
    //                From the highest-numbered lane down to lowest-numbered
    //
    qlm_num  =  first_qlm_num + num_qlms ;
    rdy_lane_flags   =  0 ;

    for( iter_num = 0;  iter_num < num_qlms;  iter_num++ )
    {
        qlm_num -- ;

        ocx_qlmx_cfg_csr.u  =  BDK_CSR_READ( loc_node_id, BDK_OCX_QLMX_CFG( qlm_num ));

        rdy_lane_flags   =  rdy_lane_flags << 4 ;
        rdy_lane_flags  |=  ocx_qlmx_cfg_csr.s.ser_lane_ready ;
    }

    return  rdy_lane_flags ;
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                               find_num_of_unstuck_lanes_for_link
//################################################|#################################################
uint      find_num_of_unstuck_lanes_for_link(    uint  link_num,  ocx_global_info_t * global_info_ptr  )    // <_function_>
{
    const bdk_node_t  loc_node_id  =  bdk_numa_local();

    uint  num_operational_lanes ;
    uint  lane_cnt ;
    uint  ocx_lane_num ;
    uint  first_lane ;
    uint  num_lanes ;

    bdk_ocx_lnex_trn_ctl_t    ocx_lnex_trn_ctl_csr ;
    uint    ocx_trn_lock ;
    uint    ocx_trn_done ;

    bool    lane_is_stuck ;

    //==============================================|===============================================
    first_lane  =  global_info_ptr-> first_lane_for_link[ link_num ];
    num_lanes   =  global_info_ptr-> num_lanes_for_link[  link_num ];


    //----------------------------------------------|-----------------------------------------------
    num_operational_lanes  =  0 ;
    ocx_lane_num  =  first_lane ;

    for( lane_cnt = 0;  lane_cnt < num_lanes;  lane_cnt ++ )
    {
        ocx_lnex_trn_ctl_csr.u  =  BDK_CSR_READ(  loc_node_id, BDK_OCX_LNEX_TRN_CTL( ocx_lane_num ) );
        ocx_trn_lock  =  ocx_lnex_trn_ctl_csr.s.lock ;
        ocx_trn_done  =  ocx_lnex_trn_ctl_csr.s.done ;

        lane_is_stuck  =  (ocx_trn_lock == 1)  &&  (ocx_trn_done == 0);

        if( ! lane_is_stuck )
        {
            num_operational_lanes ++ ;
        }

        ocx_lane_num ++ ;

    } // ocx_lane_num


    //==============================================|===============================================
    return  num_operational_lanes ;
}                                                    // <_function_end_>




//################################################|#################################################  // <_function_hdr_>
//                                 update_globals_with_link_state
//################################################|#################################################
uint      update_globals_with_link_state(    ocx_global_info_t * global_info_ptr  )    // <_function_>
{
    uint  link_num ;
    uint  num_links_up ;
    uint  num_operational_lanes ;
    uint  rdy_lane_flags ;
    uint  index ;
    uint  num_active_links ;

    uint  num_links_operational ;

    //==============================================|===============================================
    //                                    Links Up (Interlaken)
    num_links_up  =  0 ;

    for( link_num = 0;  link_num < 3;  link_num++ )
    {
        if( oci_link_is_up( link_num ) )
        {
            global_info_ptr-> link_is_up[ link_num ]  =  true ;

            global_info_ptr-> up_links_array[ num_links_up ]  =  link_num ;
            num_links_up ++ ;
        }
        else
        {
            global_info_ptr-> link_is_up[ link_num ]  =  false ;
        }
    }
    global_info_ptr-> num_links_up  =  num_links_up ;


    //----------------------------------------------|-----------------------------------------------
    //                                  Operational Links (OCX layer)
    //
    num_links_operational  =  0 ;
    num_active_links       =  global_info_ptr-> num_active_links ;

    for( index = 0;  index < num_active_links;  index ++ )
    {
        link_num  =  global_info_ptr-> active_links_array[ index ];

        if( oci_link_is_operational( link_num ) )
        {
            global_info_ptr-> link_is_operational[ link_num ]  =  true ;

            global_info_ptr-> operational_links_array[ num_links_operational ]  =  link_num ;
            num_links_operational ++ ;
        }
        else
        {
            global_info_ptr-> link_is_operational[ link_num ]  =  false ;
        }

    } // for

    global_info_ptr-> num_links_operational  =  num_links_operational ;


//    num_links_operational  =  0 ;
//
//    for( link_num = 0;  link_num < 3;  link_num++ )
//    {
//        if( link_num == 1 )
//        {
//            global_info_ptr-> link_is_operational[ link_num ]  =  false ;
//        }
//        else
//        {
//            if( oci_link_is_operational( link_num ) )
//            {
//                global_info_ptr-> link_is_operational[ link_num ]  =  true ;
//    
//                global_info_ptr-> operational_links_array[ num_links_operational ]  =  link_num ;
//                num_links_operational ++ ;
//            }
//            else
//            {
//                global_info_ptr-> link_is_operational[ link_num ]  =  false ;
//            }
//        }
//    }
//
//    global_info_ptr-> num_links_operational  =  num_links_operational ;



    //----------------------------------------------|-----------------------------------------------
    //                           Operational Lanes for Each Link  (QLM's RDY Flags)
    //
    for( index = 0;  index < num_links_up;  index ++ )
    {
        link_num  =  global_info_ptr-> up_links_array[ index ];

        rdy_lane_flags         =  get_local_rdy_lane_flags_for_link(  link_num, global_info_ptr  );
        num_operational_lanes  =  count_ones( 16, rdy_lane_flags );

        global_info_ptr-> num_operational_lanes_for_link[ link_num ]  =  num_operational_lanes ;
    }

    //==============================================|===============================================
    return  num_links_up ;
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                     find_number_of_up_links
//################################################|#################################################
uint      find_number_of_up_links(    ocx_global_info_t * global_info_ptr  )    // <_function_>
{
    uint  link_num ;
    uint  num_links_up ;

    //==============================================|===============================================
    num_links_up  =  0 ;

    for( link_num = 0;  link_num < 3;  link_num++ )
    {
        if( oci_link_is_up( link_num ) )
        {
            global_info_ptr-> up_links_array[ num_links_up ]  =  link_num ;
            global_info_ptr-> link_is_up[ link_num ]  =  true ;

            num_links_up ++ ;
        }
        else
        {
            global_info_ptr-> link_is_up[ link_num ]  =  false ;
        }
    } // for

    global_info_ptr-> num_links_up  =  num_links_up ;


    //==============================================|===============================================
    return  num_links_up ;
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                             find_num_of_operational_lanes_for_link
//################################################|#################################################
uint      find_num_of_operational_lanes_for_link(    uint  link_num,  ocx_global_info_t * global_info_ptr  )    // <_function_>
{
    uint  rdy_lane_flags ;
    uint  num_rdy_lanes ;

    //==============================================|===============================================
    rdy_lane_flags  =  get_local_rdy_lane_flags_for_link(  link_num, global_info_ptr  );
    num_rdy_lanes   =  count_ones( 16, rdy_lane_flags );

    //==============================================|===============================================
    return  num_rdy_lanes ;
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                              find_routing_node_id_of_lowest_num_link
//################################################|#################################################
int       find_routing_node_id_of_lowest_num_link(  ocx_global_info_t * global_info_ptr  )     // <_function_>
{
    const bdk_node_t         loc_node_id  =  bdk_numa_local();
    bdk_ocx_com_linkx_ctl_t  com_link_ctl_csr ;

    int    first_link_num ;
    int    first_link_routing_node_id ;

    //==============================================================================================
    first_link_num              =  global_info_ptr-> active_links_array[ 0 ];
    com_link_ctl_csr.u          =  BDK_CSR_READ( loc_node_id, BDK_OCX_COM_LINKX_CTL( first_link_num ) );
    first_link_routing_node_id  =  com_link_ctl_csr.s.id ;

    //===============================================================================================
    return  first_link_routing_node_id ;
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                   soft_reset_the_far_node
//################################################|#################################################
int       soft_reset_the_far_node(  bdk_node_t  routing_node_id  )     // <_function_>
{
    bdk_rst_soft_rst_t   rst_soft_rst_csr ;
    int                  result ;
    unsigned int         verbosity  =  0 ;

    rst_soft_rst_csr.u          = 0 ;
    rst_soft_rst_csr.s.soft_rst = 1 ;

    result  =  remote_csr_write_on_t88( routing_node_id, BDK_RST_SOFT_RST, rst_soft_rst_csr.u, verbosity );
    return  result ;
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                   soft_reset_the_local_node
//################################################|#################################################
void      soft_reset_the_local_node(  void  )                               // <_function_>
{
    bdk_reset_chip( bdk_numa_local() );
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                    display_oci_config_summary
//################################################|#################################################
void      display_oci_config_summary(  ocx_global_info_t * global_info_ptr )            // <_function_>
{
    uint  link_num ;
//    uint  num_links_up ;
//    uint  num_operational_lanes ;
    uint  index ;
//    uint  rdy_lane_flags ;

    uint  num_active_links  =  global_info_ptr-> num_active_links ;
//    uint  num_qlms ;

//    bool  doing_link_training  =  false ;

    //==============================================================================================
    printf(" OCI link baud rate:   %d  KBaud \n", global_info_ptr-> link_baud_rate_kbaud );

    if( global_info_ptr-> oci_links_are_doing_training == 1 )
    {
        printf(" Doing link training! \n");
    }
    else if( global_info_ptr-> oci_links_are_doing_training == 0 )
    {
        printf(" Not doing link training. \n");
    }
    else
    {
        printf(" *** Illegal value:  global_info_ptr-> oci_links_are_doing_training  =  %u *** \n", global_info_ptr-> oci_links_are_doing_training );

    }

    printf(" \n");

    //----------------------------------------------------------------------------------------------
    printf(" Number of active links:   %u \n", num_active_links );

    for( index = 0;  index < num_active_links;  index ++ )
    {
        link_num  =  global_info_ptr-> active_links_array[ index ];

        printf("     Link-%d:   %2u lanes \n", link_num, global_info_ptr-> num_lanes_for_link[ link_num ] );
    }
    printf(" \n");


//    //----------------------------------------------------------------------------------------------
//    num_links_up  =  global_info_ptr-> num_links_up ;
//    printf(" Number of links up:   %u (Interlaken OK) \n", num_links_up );
//
//    for( index = 0;  index < num_links_up;  index ++ )
//    {
//        link_num  =  global_info_ptr-> up_links_array[ index ];
//
//        num_operational_lanes  =  global_info_ptr-> num_operational_lanes_for_link[ link_num ];
//        num_qlms               =  global_info_ptr-> num_qlms_for_link[  link_num ];
//        rdy_lane_flags         =  get_local_rdy_lane_flags_for_link(  link_num,  global_info_ptr  );
//
//        if(      num_qlms == 1 )    printf("     Link-%d:   %2u lanes:  0x%X \n",   link_num, num_operational_lanes, rdy_lane_flags );
//        else if( num_qlms == 2 )    printf("     Link-%d:   %2u lanes:  0x%02X \n", link_num, num_operational_lanes, rdy_lane_flags );
//        else if( num_qlms == 3 )    printf("     Link-%d:   %2u lanes:  0x%03X \n", link_num, num_operational_lanes, rdy_lane_flags );
//    }
//    printf(" \n");


//    //----------------------------------------------------------------------------------------------
//    if( global_info_ptr-> far_node_id > 0 )
//    {
//        printf(" far_node_id:   %d   ( -1:  Unknown) \n", global_info_ptr-> far_node_id );
//        printf(" \n");
//    }

} // display_oci_config_summary                      // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                      display_global_link_status
//################################################|#################################################
void      display_global_link_status(  ocx_global_info_t * global_info_ptr )            // <_function_>
{
    uint  link_num ;
    uint  num_links_up ;
    uint  num_operational_lanes ;
    uint  index ;
    uint  rdy_lane_flags ;
    uint  num_qlms ;

    //==============================================================================================
    num_links_up  =  global_info_ptr-> num_links_up ;

    printf(" Number of links up:   %u (Interlaken OK) \n", num_links_up );

    for( index = 0;  index < num_links_up;  index ++ )
    {
        link_num  =  global_info_ptr-> up_links_array[ index ];

        num_operational_lanes  =  global_info_ptr-> num_operational_lanes_for_link[ link_num ];
        num_qlms               =  global_info_ptr-> num_qlms_for_link[  link_num ];
        rdy_lane_flags         =  get_local_rdy_lane_flags_for_link(  link_num,  global_info_ptr  );

        if(      num_qlms == 1 )    printf("     Link-%d:   %2u lanes:  0x%X \n",   link_num, num_operational_lanes, rdy_lane_flags );
        else if( num_qlms == 2 )    printf("     Link-%d:   %2u lanes:  0x%02X \n", link_num, num_operational_lanes, rdy_lane_flags );
        else if( num_qlms == 3 )    printf("     Link-%d:   %2u lanes:  0x%03X \n", link_num, num_operational_lanes, rdy_lane_flags );
    }
    printf(" \n");


    //----------------------------------------------------------------------------------------------
    if( global_info_ptr-> far_node_id > 0 )
    {
        printf(" far_node_id:   %d   ( -1:  Unknown) \n", global_info_ptr-> far_node_id );
        printf(" \n");
    }

} // display_global_link_status                      // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                 display_operational_link_status
//################################################|#################################################
void      display_operational_link_status(  ocx_global_info_t * global_info_ptr )            // <_function_>
{
    uint  link_num ;
    uint  num_links_operational ;
    uint  num_operational_lanes ;
    uint  index ;
    uint  rdy_lane_flags ;
    uint  num_qlms ;

    uint  num_configured_lanes ;

    //==============================================================================================
    num_links_operational  =  global_info_ptr-> num_links_operational ;

    printf(" Number of operational links:   %u \n", num_links_operational );

    for( index = 0;  index < num_links_operational;  index ++ )
    {
        link_num  =  global_info_ptr-> operational_links_array[ index ];

        num_configured_lanes   =  global_info_ptr-> num_lanes_for_link[             link_num ];
        num_operational_lanes  =  global_info_ptr-> num_operational_lanes_for_link[ link_num ];
        num_qlms               =  global_info_ptr-> num_qlms_for_link[              link_num ];
        rdy_lane_flags         =  get_local_rdy_lane_flags_for_link(                link_num,  global_info_ptr  );

        if(      num_qlms == 1 )    printf("     Link-%d:   %2u lanes:  0x%X  - %2u out of  %2u lanes \n",   link_num, num_operational_lanes, rdy_lane_flags, num_operational_lanes, num_configured_lanes );
        else if( num_qlms == 2 )    printf("     Link-%d:   %2u lanes:  0x%02X  - %2u out of  %2u lanes \n", link_num, num_operational_lanes, rdy_lane_flags, num_operational_lanes, num_configured_lanes );
        else if( num_qlms == 3 )    printf("     Link-%d:   %2u lanes:  0x%03X  - %2u out of  %2u lanes \n", link_num, num_operational_lanes, rdy_lane_flags, num_operational_lanes, num_configured_lanes );
    }
    printf(" \n");

} // display_operational_link_status                 // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                     convert_clk_cnt_to_usec
//################################################|#################################################
uint64_t  convert_clk_cnt_to_usec(          uint64_t interval_clks, uint64_t clk_freq_mhz )   // <_function_>
{
    uint64_t  cycle_time_psec ;
    uint64_t  interval_psec ;
    uint64_t  interval_nsec ;
    uint64_t  interval_usec ;

    if(      clk_freq_mhz <=  500 )    cycle_time_psec  =  2000 ; // psec
    else if( clk_freq_mhz <=  550 )    cycle_time_psec  =  1818 ; // psec
    else if( clk_freq_mhz <=  600 )    cycle_time_psec  =  1667 ; // psec
    else if( clk_freq_mhz <=  650 )    cycle_time_psec  =  1538 ; // psec
    else if( clk_freq_mhz <=  700 )    cycle_time_psec  =  1429 ; // psec
    else if( clk_freq_mhz <=  750 )    cycle_time_psec  =  1333 ; // psec
    else if( clk_freq_mhz <=  800 )    cycle_time_psec  =  1250 ; // psec
    else if( clk_freq_mhz <=  850 )    cycle_time_psec  =  1176 ; // psec
    else if( clk_freq_mhz <=  900 )    cycle_time_psec  =  1111 ; // psec
    else if( clk_freq_mhz <=  950 )    cycle_time_psec  =  1053 ; // psec
    else if( clk_freq_mhz <= 1000 )    cycle_time_psec  =  1000 ; // psec
    else if( clk_freq_mhz <= 1050 )    cycle_time_psec  =   952 ; // psec
    else if( clk_freq_mhz <= 1100 )    cycle_time_psec  =   909 ; // psec
    else if( clk_freq_mhz <= 1150 )    cycle_time_psec  =   870 ; // psec
    else if( clk_freq_mhz <= 1200 )    cycle_time_psec  =   833 ; // psec
    else if( clk_freq_mhz <= 1250 )    cycle_time_psec  =   800 ;
    else if( clk_freq_mhz <= 1300 )    cycle_time_psec  =   769 ;
    else if( clk_freq_mhz <= 1350 )    cycle_time_psec  =   740 ;
    else if( clk_freq_mhz <= 1400 )    cycle_time_psec  =   714 ;
    else if( clk_freq_mhz <= 1450 )    cycle_time_psec  =   689 ;
    else if( clk_freq_mhz <= 1500 )    cycle_time_psec  =   666 ;
    else if( clk_freq_mhz <= 1550 )    cycle_time_psec  =   645 ;
    else if( clk_freq_mhz <= 1600 )    cycle_time_psec  =   625 ;
    else if( clk_freq_mhz <= 1650 )    cycle_time_psec  =   606 ;
    else if( clk_freq_mhz <= 1700 )    cycle_time_psec  =   588 ;
    else if( clk_freq_mhz <= 1750 )    cycle_time_psec  =   571 ;
    else if( clk_freq_mhz <= 1800 )    cycle_time_psec  =   555 ;
    else if( clk_freq_mhz <= 1850 )    cycle_time_psec  =   540 ;
    else if( clk_freq_mhz <= 1900 )    cycle_time_psec  =   526 ;
    else if( clk_freq_mhz <= 1950 )    cycle_time_psec  =   512 ;
    else if( clk_freq_mhz <= 2000 )    cycle_time_psec  =   500 ;
    else if( clk_freq_mhz <= 2050 )    cycle_time_psec  =   487 ;
    else if( clk_freq_mhz <= 2100 )    cycle_time_psec  =   476 ;
    else if( clk_freq_mhz <= 2150 )    cycle_time_psec  =   465 ;
    else if( clk_freq_mhz <= 2200 )    cycle_time_psec  =   454 ;
    else if( clk_freq_mhz <= 2250 )    cycle_time_psec  =   444 ;
    else if( clk_freq_mhz <= 2300 )    cycle_time_psec  =   434 ;
    else if( clk_freq_mhz <= 2350 )    cycle_time_psec  =   425 ;
    else                               cycle_time_psec  =   416 ;  // 2400 MHz

    interval_psec  =  interval_clks * cycle_time_psec ;
    interval_nsec  =  interval_psec / 1000 ;
    interval_usec  =  interval_nsec / 1000 ;

    return  interval_usec ;
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                              disable_all_local_ocx_bad_lane_timeouts
//################################################|#################################################
void      disable_all_local_ocx_bad_lane_timeouts(    void  )                       // <_function_>
{
    uint                 ocx_qlm_num ;
    bdk_ocx_qlmx_cfg_t   ocx_qlmx_cfg_csr ;

    const bdk_node_t     loc_node_id    =  bdk_numa_local();


    //----------------------------------------------------------------------------------------------
//    printf(" Disabling the OCX QLM 'bad lane' timeouts on all OCX-QLMs: \n");
    
    for( ocx_qlm_num = 0;  ocx_qlm_num < 6;  ocx_qlm_num ++ )
    {
//        printf("     OCX-QLM-%d... \n", ocx_qlm_num );

        ocx_qlmx_cfg_csr.u  =  BDK_CSR_READ( loc_node_id, BDK_OCX_QLMX_CFG( ocx_qlm_num  ));
        ocx_qlmx_cfg_csr.s.timer_dis  =  1 ;
        BDK_CSR_WRITE( loc_node_id, BDK_OCX_QLMX_CFG( ocx_qlm_num ), ocx_qlmx_cfg_csr.u );
    }
//    printf(" \n");
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                  setup_stats_on_all_ocx_lanes
//################################################|#################################################
/*                                    
    Leaves the stat counters disabled!

    Enables clearing of the counters upon reading their value.
    Disables wrapping of the counters upon overflow.
 */
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void      setup_stats_on_all_ocx_lanes(               void )                        // <_function_>
{
    unsigned int  lane_num ;

    // OCX_LNE(0..23)_CFG:  RX_STAT_WRAP_DIS, RX_STAT_RDCLR, RX_STAT_ENA
    bdk_ocx_lnex_cfg_t   ocx_lnex_cfg_csr ;

    const bdk_node_t   loc_node_id  =  bdk_numa_local();

    //----------------------------------------------------------------------------------------------
    for( lane_num = 0;  lane_num < 24;  lane_num ++ )
    {
//        printf("         Lane-%d: \n", lane_num );

        //................................................................................
        //               Disable the Stat Counters  -  While setting them up:
        // 
        ocx_lnex_cfg_csr.u  =  0 ;
        ocx_lnex_cfg_csr.s.rx_stat_ena  =  0 ;

        BDK_CSR_WRITE( loc_node_id, BDK_OCX_LNEX_CFG( lane_num ), ocx_lnex_cfg_csr.u );

        //................................................................................
        //      Assert CLEAR-When-Reading  &  No Wrapping  &  No bdry lock disable
        // 
        ocx_lnex_cfg_csr.u  =  0 ;
        ocx_lnex_cfg_csr.s.rx_bdry_lock_dis  =  0 ;
        ocx_lnex_cfg_csr.s.rx_stat_wrap_dis  =  1 ;
        ocx_lnex_cfg_csr.s.rx_stat_rdclr     =  1 ;
        ocx_lnex_cfg_csr.s.rx_stat_ena       =  0 ;

        BDK_CSR_WRITE( loc_node_id, BDK_OCX_LNEX_CFG( lane_num ), ocx_lnex_cfg_csr.u );
    }

    //----------------------------------------------------------------------------------------------
} // setup_stats_on_all_ocx_lanes                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                 enable_stats_on_all_ocx_lanes
//################################################|#################################################
/*                                    
 */
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void      enable_stats_on_all_ocx_lanes(              void )                        // <_function_>
{
    uint  lane_num ;

    // OCX_LNE(0..23)_CFG:  RX_STAT_WRAP_DIS, RX_STAT_RDCLR, RX_STAT_ENA
    bdk_ocx_lnex_cfg_t   ocx_lnex_cfg_csr ;

    const bdk_node_t   loc_node_id  =  bdk_numa_local();


    //----------------------------------------------------------------------------------------------
    for( lane_num = 0;  lane_num < 24;  lane_num ++ )
    {
        ocx_lnex_cfg_csr.u  =  0 ;

        ocx_lnex_cfg_csr.u  =  BDK_CSR_READ( loc_node_id, BDK_OCX_LNEX_CFG( lane_num ));
        //
        ocx_lnex_cfg_csr.s.rx_stat_ena  =  1 ;
        //
        BDK_CSR_WRITE( loc_node_id, BDK_OCX_LNEX_CFG( lane_num ), ocx_lnex_cfg_csr.u );
        
        // Read back to be sure write has finished...
        ocx_lnex_cfg_csr.u = BDK_CSR_READ( loc_node_id, BDK_OCX_LNEX_CFG( lane_num ));
    }

    //----------------------------------------------------------------------------------------------
} // enable_stats_on_all_ocx_lanes                   // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                            disable_then_clr_local_ocx_tlk_statistics
//################################################|#################################################
/*                                    
    Disables the statistics before clearing them to be sure all are cleared before any can
    start counting again.

    Clears TLK Link CSRs:
        OCX_TLK(0..2)_STAT_IDLE_CNT
        OCX_TLK(0..2)_STAT_DATA_CNT
        OCX_TLK(0..2)_STAT_SYNC_CNT
        OCX_TLK(0..2)_STAT_RETRY_CNT
        OCX_TLK(0..2)_STAT_ERR_CNT

        OCX_TLK(0..2)_STAT_VC(0..5)_CMD
        OCX_TLK(0..2)_STAT_VC(0..13)_PKT
        OCX_TLK(0..2)_STAT_VC(0..13)_CON

    Use:  enable_local_ocx_tlk_statistics()  to start counting again.  
 */
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void      disable_then_clr_local_ocx_tlk_statistics(  uint  link_num  )             // <_function_>
{
    const bdk_node_t   loc_node_id   =  bdk_numa_local();    // 0 or 1

    bdk_ocx_tlkx_stat_ctl_t  ocx_tlkx_stat_ctl_csr ;

    //----------------------------------------------------------------------------------------------
    //                                 Disable the Statistics Counters
    //
    ocx_tlkx_stat_ctl_csr.u         =  0 ;
    ocx_tlkx_stat_ctl_csr.s.clear   =  0 ;
    ocx_tlkx_stat_ctl_csr.s.enable  =  0 ;
    //
    BDK_CSR_WRITE( loc_node_id, BDK_OCX_TLKX_STAT_CTL( link_num ), ocx_tlkx_stat_ctl_csr.u );

    // Read back to make sure write finished:
    ocx_tlkx_stat_ctl_csr.u = BDK_CSR_READ( loc_node_id, BDK_OCX_TLKX_STAT_CTL( link_num ));


    //----------------------------------------------------------------------------------------------
    //                                 Clear the Statistics Counters
    //
    ocx_tlkx_stat_ctl_csr.u         =  0 ;
    ocx_tlkx_stat_ctl_csr.s.clear   =  1 ;
    ocx_tlkx_stat_ctl_csr.s.enable  =  0 ;
    //
    BDK_CSR_WRITE( loc_node_id, BDK_OCX_TLKX_STAT_CTL( link_num ), ocx_tlkx_stat_ctl_csr.u );

    // Read back to make sure write finished:
    ocx_tlkx_stat_ctl_csr.u = BDK_CSR_READ( loc_node_id, BDK_OCX_TLKX_STAT_CTL( link_num ));

    //----------------------------------------------------------------------------------------------
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                 enable_local_ocx_tlk_statistics
//################################################|#################################################
/*                                    
    Used after:  disable_then_clr_local_ocx_tlk_statistics

    Returns success/error:  error = < 0, success >= 0
 */
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void      enable_local_ocx_tlk_statistics(            uint  link_num  )               // <_function_>
{
    const bdk_node_t         loc_node_id  =  bdk_numa_local();    // 0 or 1
    bdk_ocx_tlkx_stat_ctl_t  ocx_tlkx_stat_ctl_csr ;

    //----------------------------------------------------------------------------------------------
    ocx_tlkx_stat_ctl_csr.u         =  0 ;
    ocx_tlkx_stat_ctl_csr.s.enable  =  1 ;

    BDK_CSR_WRITE( loc_node_id, BDK_OCX_TLKX_STAT_CTL( link_num ), ocx_tlkx_stat_ctl_csr.u );

    // Read back to make sure write finished:
    ocx_tlkx_stat_ctl_csr.u = BDK_CSR_READ( loc_node_id, BDK_OCX_TLKX_STAT_CTL( link_num ));

    //----------------------------------------------------------------------------------------------
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                 init_local_ocx_modes_intrs_stats
//################################################|#################################################
/*
    Operations:
        Set Dual-Sort-Mode
        Clear interrupts
        Activate_all_stat_cntrs_on_all_links
 */
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void      init_local_ocx_modes_intrs_stats(           uint dual_sort_mode  )            // <_function_>
{
    const bdk_node_t          loc_node_id  =  bdk_numa_local();
    bdk_ocx_com_linkx_int_t   ocx_com_linkx_int_csr ;
    uint                      link_num ;

    //==============================================================================================


    //------------------------------------------------------------------------------------
    //                          Multi-Link Traffic Dual Sorting:
    //
    BDK_CSR_MODIFY( c, bdk_numa_local(), BDK_OCX_COM_DUAL_SORT,  c.s.sort = dual_sort_mode );


    //------------------------------------------------------------------------------------
    //                              Check and Clear Interrupts:
    //
    for( link_num = 0;  link_num < 3;  link_num++ )
    {
        if( oci_link_is_up( link_num ) )
        {
            ocx_com_linkx_int_csr.u  =  BDK_CSR_READ( loc_node_id, BDK_OCX_COM_LINKX_INT( link_num ));
            BDK_CSR_WRITE( loc_node_id, BDK_OCX_COM_LINKX_INT( link_num ), ocx_com_linkx_int_csr.u );

            // Read back the interrupt reg to be sure the write finished:
            ocx_com_linkx_int_csr.u  =  BDK_CSR_READ( loc_node_id, BDK_OCX_COM_LINKX_INT( link_num ));
        }
    }

    //------------------------------------------------------------------------------------
    //              Activate Cleared Stat Counters on all Lanes of all Links
    //
    setup_stats_on_all_ocx_lanes();
    enable_stats_on_all_ocx_lanes();

    for( link_num = 0;  link_num < 3;  link_num ++ )
    {
        disable_then_clr_local_ocx_tlk_statistics( link_num );
        enable_local_ocx_tlk_statistics( link_num );
    }

    //==============================================================================================
} // initialize_local_node                           // <_function_end_>




//################################################|#################################################  // <_function_hdr_>
//                                    init_local_oci_gser_dtx
//################################################|#################################################
/*
 */
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int       init_local_oci_gser_dtx(          uint  gser_num,  uint  gser_lane_num )    // <_function_>
{
    bdk_oclax_gen_ctl_t     oclax_gen_ctl_csr ;
    bdk_dtx_gserx_selx_t    dtx_gserx_selx_csr ;
//    bdk_oclax_fifo_limit_t  oclax_fifo_limit_csr ;

    const bdk_node_t   loc_node_id  =  bdk_numa_local();

    const uint   gser_sel    =  0 ;  //  0..1
    const uint   ocla_num    =  4 ;
    const uint   dbgsel_sml  =  0x30000 + ( gser_lane_num * 0x10 );

    //==============================================|===============================================

    // Soft Reset OCLA
    BDK_CSR_WRITE(  loc_node_id, BDK_OCLAX_SFT_RST( ocla_num ), 0x1 );    // Reset
    BDK_CSR_WRITE(  loc_node_id, BDK_OCLAX_SFT_RST( ocla_num ), 0x0 );    // release reset


    // Enable data bus and counter clocking:
    oclax_gen_ctl_csr.u      =  0 ;
    oclax_gen_ctl_csr.s.den  =  1 ;
    //
    BDK_CSR_WRITE(  loc_node_id, BDK_OCLAX_GEN_CTL( ocla_num ), oclax_gen_ctl_csr.u );
    //
    // Read it back to be sure it got done!
    oclax_gen_ctl_csr.u  =  BDK_CSR_READ(  loc_node_id, BDK_OCLAX_GEN_CTL( ocla_num ) );

    // Set the FIFO Limit:
    //                                                               111111
    //                                                               5432109876543210
    BDK_CSR_WRITE(  loc_node_id, BDK_OCLAX_FIFO_LIMIT( ocla_num ), 0x3fffffffffffffff );  // 62 bits
    //
    // Read it back to be sure it got done!
    /* oclax_fifo_limit_csr.u  =*/  BDK_CSR_READ(  loc_node_id, BDK_OCLAX_FIFO_LIMIT( ocla_num ) );


    // Set up for RXTRAIN_SML:
    dtx_gserx_selx_csr.u  =  0 ;
    dtx_gserx_selx_csr.s.value  =  dbgsel_sml ;  // 24 bits - GSER(0..13)_RXTRAIN_SML(0..3)
    //
    BDK_CSR_WRITE(  loc_node_id, BDK_DTX_GSERX_SELX( gser_num, gser_sel ), dtx_gserx_selx_csr.u );
    //
    // Read it back to be sure it got done!
    dtx_gserx_selx_csr.u  =  BDK_CSR_READ(  loc_node_id, BDK_DTX_GSERX_SELX( gser_num, gser_sel ) );


    //==============================================|===============================================
    return  0 ;
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                            read_crc32_errors_in_all_lanes_of_t88_link
//################################################|#################################################
/*                            
    The error count clears upon reading.
 */
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
uint      read_crc32_errors_in_all_lanes_of_t88_link(  uint link_num,  ocx_global_info_t * global_info_ptr )      // <_function_>
{
    const bdk_node_t   loc_node_id   =  bdk_numa_local();

    // OCX_LNE(0..23)_STAT11:  CRC32_ERR_CNT
    bdk_ocx_lnex_stat11_t    ocx_lnex_stat11_csr ;

    uint   num_link_lanes ;
    uint   ocx_lane_num ;    // 0..23
    uint   lane_cnt ;
    int    num_lane_crc32_errors ;
    int    num_crc32_errors  =  0 ;
       
//    int    result     =  0 ;
//    int    verbosity  =  0 ;

    //==============================================================================================
//    printf("> read_crc32_errors_in_all_lanes_of_link:  Node-%d   Link-%d\n", loc_node_id, link_num );

    //----------------------------------------------------------------------------------------------
    //                                Iterate Over the Lanes of the Link
    //
    num_link_lanes  =  global_info_ptr-> num_lanes_for_link[  link_num ];
    ocx_lane_num    =  global_info_ptr-> first_lane_for_link[ link_num ];

    for( lane_cnt = 0;  lane_cnt < num_link_lanes;  lane_cnt ++ )
    {
        ocx_lnex_stat11_csr.u  =  BDK_CSR_READ( loc_node_id, BDK_OCX_LNEX_STAT11( ocx_lane_num ));

//        printf("> read_crc32_errors_in_all_lanes_of_link:      ocx_lnex_stat11_csr:  0x%016lX \n", ocx_lnex_stat11_csr.u );

        num_lane_crc32_errors  =  ocx_lnex_stat11_csr.s.crc32_err_cnt ;
//        printf("> read_crc32_errors_in_all_lanes_of_link:      OCX-Lane-%d   Errors:  %d  \n", ocx_lane_num, num_crc32_errors );

        num_crc32_errors  +=  num_lane_crc32_errors ;

        ocx_lane_num ++ ;
    }
    
    //==============================================================================================
//    printf("> read_crc32_errors_in_all_lanes_of_link:      num_crc32_errors  =  %d \n", num_crc32_errors );

    return  num_crc32_errors ;

} // read_crc32_errors_in_all_lanes_of_t88_link      // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                          read_crc32_errors_across_all_active_t88_links
//################################################|#################################################
/*                            
    The error counts clear upon reading.
 */
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
uint      read_crc32_errors_across_all_active_t88_links(  ocx_global_info_t * global_info_ptr  )      // <_function_>
{
//    const bdk_node_t   loc_node_id   =  bdk_numa_local();

    uint  num_active_links ;
    uint  link_index ;
    uint  link_num ;
    uint  num_crc32_errors ;

    //==============================================================================================
    num_active_links  =  global_info_ptr-> num_active_links ;

    num_crc32_errors  =  0 ;
    //
    for( link_index = 0;  link_index < num_active_links;  link_index ++ )
    {
        link_num          =  global_info_ptr-> active_links_array[ link_index ];
        num_crc32_errors  =  read_crc32_errors_in_all_lanes_of_t88_link(  link_num, global_info_ptr  );
    }

    //==============================================================================================
    return  num_crc32_errors ;
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                   manage_t88_links_coming_up
//################################################|#################################################
/*
        Not started - waiting for work-around algorithm(s).
 */
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
uint      manage_t88_links_coming_up(       ocx_global_info_t * global_info_ptr )        // <_function_>
{
//    const bdk_node_t   loc_node_id  =  bdk_numa_local();

    uint       num_links_are_up  =  0 ;    // index into  up_links_array[ 4 ].
//    uint       num_active_links ;

    //==============================================|===============================================
    //             Initialize the variables that will used whether or not doing training

//    num_active_links  =  global_info_ptr-> num_active_links ;


    //==============================================|===============================================
    return  num_links_are_up ;

} // manage_t88_links_coming_up                      // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                    get_t88_gser_rxtrain_sml_reg
//################################################|#################################################
/*                               
        Requires that the GSER DTX has already been set up!
 */
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
uint64_t  get_t88_gser_rxtrain_sml_reg(     uint gser_num,  uint gser_lane_num )     // <_function_>
{
    const bdk_node_t     loc_node_id  =  bdk_numa_local();
    const uint   dtx_data_num  =  0 ;

    bdk_dtx_gserx_selx_t        dtx_gserx_selx_for_sml_csr ;
    gserx_lanex_rxtrain_sml_t   rxtrain_sml_csr ;

    //==============================================================================================
    dtx_gserx_selx_for_sml_csr.u  =  0 ;
    dtx_gserx_selx_for_sml_csr.s.value  =  GSER_RX_TRAIN_SML_REG_DTX_ADR( gser_lane_num );    // 24 bits
    //
    BDK_CSR_WRITE(  loc_node_id, BDK_DTX_GSERX_SELX( gser_num, dtx_data_num ), dtx_gserx_selx_for_sml_csr.u );
    BDK_WMB ;

    rxtrain_sml_csr.u  =  BDK_CSR_READ(  loc_node_id, BDK_DTX_GSERX_DATX( gser_num, dtx_data_num ));

//    printf("> get_gser_rxtrain_sml_reg_on_node:      Node-%d  GSER-%02u  Lane-%u:   rxtrain_sml_csr =  0x%016lX \n", 
//                                              loc_node_id, gser_num, gser_lane_num, rxtrain_sml_csr.u
//    );

    //==============================================================================================
    return  rxtrain_sml_csr.u ;
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                  get_t88_gser_rxtrain_smh_reg
//################################################|#################################################
/*                               
        Requires that the GSER DTX has already been set up!
 */
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
uint64_t  get_t88_gser_rxtrain_smh_reg(     uint gser_num,  uint gser_lane_num )     // <_function_>
{
    const bdk_node_t     loc_node_id  =  bdk_numa_local();
    const uint   dtx_data_num  =  0 ;

    bdk_dtx_gserx_selx_t        dtx_gserx_selx_for_smh_csr ;
    gserx_lanex_rxtrain_smh_t   rxtrain_smh_csr ;

    //==============================================================================================
    dtx_gserx_selx_for_smh_csr.u  =  0 ;
    dtx_gserx_selx_for_smh_csr.s.value  =  GSER_RX_TRAIN_SMH_REG_DTX_ADR( gser_lane_num );    // 24 bits
    //
    BDK_CSR_WRITE(  loc_node_id, BDK_DTX_GSERX_SELX( gser_num, dtx_data_num ), dtx_gserx_selx_for_smh_csr.u );
    BDK_WMB ;

    rxtrain_smh_csr.u  =  BDK_CSR_READ(  loc_node_id, BDK_DTX_GSERX_DATX( gser_num, dtx_data_num ));

//    printf("> get_gser_rxtrain_sml_reg_on_node:      Node-%d  GSER-%02u  Lane-%u:   rxtrain_smh_csr =  0x%016lX \n", 
//                                                 loc_node_id, gser_num, gser_lane_num, rxtrain_smh_csr.u
//    );

    //==============================================================================================
    return  rxtrain_smh_csr.u ;
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                 get_t88_gser_txtrain_dbg_reg
//################################################|#################################################
/*                               
        Requires that the GSER DTX has already been set up!
 */
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
uint64_t  get_t88_gser_txtrain_dbg_reg(     uint gser_num,  uint gser_lane_num )     // <_function_>
{
    const bdk_node_t   loc_node_id   =  bdk_numa_local();
    const uint         dtx_data_num  =  0 ;

    bdk_dtx_gserx_selx_t        dtx_gserx_selx_csr ;
    gserx_lanex_txtrain_dbg_t   gserx_lanex_txtrain_dbg_csr ;

    //==============================================================================================
    dtx_gserx_selx_csr.u  =  0 ;
    dtx_gserx_selx_csr.s.value  =  GSER_TX_TRAIN_DBG_REG_DTX_ADR( gser_lane_num );    // 24 bits

    BDK_CSR_WRITE(  loc_node_id, BDK_DTX_GSERX_SELX( gser_num, dtx_data_num ), dtx_gserx_selx_csr.u );
    BDK_WMB ;

    gserx_lanex_txtrain_dbg_csr.u  =  BDK_CSR_READ(  loc_node_id, BDK_DTX_GSERX_DATX( gser_num, dtx_data_num ));

//    printf(" \n");
//    printf("> get_gser_txtrain_dbg_csr_on_node:      Node-%d  GSER-%02u  Lane-%02u:   txtrain_dbg_csr =  0x%016lX \n", 
//                                                 loc_node_id, gser_num, gser_lane_num, gserx_lanex_txtrain_dbg_csr.u
//    );

    //==============================================================================================
    return  gserx_lanex_txtrain_dbg_csr.u ;
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                             find_local_t88_lanes_stuck_in_training
//################################################|#################################################
uint      find_local_t88_lanes_stuck_in_training(       int stuck_ocx_lane_nums_array[ 24 ],  bool ocx_lane_is_stuck_array[ 24 ]  )    // <_function_>
{
    const bdk_node_t  loc_node_id  =  bdk_numa_local();

    uint    array_index ;
    uint    ocx_lane_num ;
    uint    num_stuck_lanes ;

    bdk_ocx_lnex_trn_ctl_t    ocx_lnex_trn_ctl_csr ;
    uint    ocx_trn_lock ;
    uint    ocx_trn_done ;

    //==============================================|===============================================
    //                                 Initialize Variables & Arrays
    //
    for( array_index = 0;  array_index < 24;  array_index ++ )
    {
        stuck_ocx_lane_nums_array[ array_index ]  =  -1 ;
        ocx_lane_is_stuck_array[   array_index ]  =  false ;
    }

    num_stuck_lanes  =  0 ;

    //----------------------------------------------|-----------------------------------------------
    for( ocx_lane_num = 0;  ocx_lane_num < 24;  ocx_lane_num ++ )
    {
        ocx_lnex_trn_ctl_csr.u  =  BDK_CSR_READ(  loc_node_id, BDK_OCX_LNEX_TRN_CTL( ocx_lane_num ) );
        ocx_trn_lock  =  ocx_lnex_trn_ctl_csr.s.lock ;
        ocx_trn_done  =  ocx_lnex_trn_ctl_csr.s.done ;

        if( (ocx_trn_lock == 1)  &&  (ocx_trn_done == 0) )
        {
//            printf(">         *** Local Node-%d:   Lane-%d  is stuck in training! \n", loc_node_id, ocx_lane_num );
            stuck_ocx_lane_nums_array[ num_stuck_lanes ]  =  ocx_lane_num ;
            num_stuck_lanes ++ ;

            ocx_lane_is_stuck_array[  ocx_lane_num  ]  =  true ;
        }
    } // ocx_lane_num


    //==============================================|===============================================
    return  num_stuck_lanes ;
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                 check_status_of_t88_link_lanes_qlms
//################################################|#################################################
/*
    Reads global variables to determine the appropriate display functions to call:  4, 8, or 12 lanes.

    Checks the status of various CSRs and reports all descripencies via printfs.
 */
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
bool      check_status_of_t88_link_lanes_qlms(  bdk_node_t target_node_id,  uint  link_num,  ocx_global_info_t * global_info_ptr )   // <_function_>
{
    const bdk_node_t   loc_node_id  =  bdk_numa_local();

    uint   iter_num ;

    uint   first_lane_num ;
    uint   num_lanes ;
    uint   lane_num ;

    uint   first_qlm_num  ;
    uint   num_qlms ;
    uint   qlm_num ;

    uint   rdy_lane_flags  =  0 ;
    uint   bad_lane_flags  =  0 ;
    uint   all_lane_flags_ones  =  0 ;    // goal

    bool  oci_links_are_doing_training ;

    bdk_ocx_com_linkx_ctl_t    ocx_com_linkx_ctl_csr ;         // REINIT, UP, VALID, ID
    bdk_ocx_com_linkx_int_t    ocx_com_linkx_int_csr ;         // BAD_WORD, ALIGN_FAIL, ALIGN_DONE, UP, STOP, BLK_ERR

    bdk_ocx_lnex_status_t      ocx_lnex_status_csr ;     // RX_TRN_VAL, RX_SCRM_SYNC, RX_BDRY_SYNC
    bdk_ocx_lnex_trn_ctl_t     ocx_lnex_trn_ctl_csr ;    // LOCK, DONE, ENA, EIE_DETECT
    bdk_ocx_qlmx_cfg_t         ocx_qlmx_cfg_csr ;        // TRN_ENA, SER_LANE_READY, SER_LANE_BAD

    // Lane and QLM Arrays:
//    bdk_ocx_lnex_status_t      ocx_lnex_status_csrs[  16 ];    // RX_TRN_VAL, RX_SCRM_SYNC, RX_BDRY_SYNC
//    bdk_ocx_lnex_trn_ctl_t     ocx_lnex_trn_ctl_csrs[ 16 ];    // LOCK, DONE, ENA, EIE_DETECT
    bdk_ocx_qlmx_cfg_t         ocx_qlmx_cfg_csrs[      4 ];    // TRN_ENA, SER_LANE_READY, SER_LANE_BAD

    int        result       =  0 ;
    uint       verbosity    =  0 ;
    bool       found_error  =  false ;

    //==============================================================================================
//    printf("> check_status_of_t88_link_lanes_qlms:  \n");

    // Read Global vars
    first_lane_num  =  global_info_ptr-> first_lane_for_link[ link_num ];
    num_lanes       =  global_info_ptr-> num_lanes_for_link[  link_num ];

    first_qlm_num   =  global_info_ptr-> first_qlm_for_link[  link_num ];
    num_qlms        =  global_info_ptr-> num_qlms_for_link[   link_num ];

    oci_links_are_doing_training  =  global_info_ptr-> oci_links_are_doing_training ;

//    printf("> check_status_of_t88_link_lanes_qlms:   Link-%u   num_lanes =  %u   num_qlms =  %u \n", link_num, num_lanes, num_qlms );


    //----------------------------------------------|-----------------------------------------------
    //                                          OCX Link

    //.........................................|..........................................
    //                                 Read the LINK CSRs
    if( target_node_id == loc_node_id )   
    {
        ocx_com_linkx_ctl_csr.u  =  BDK_CSR_READ( target_node_id, BDK_OCX_COM_LINKX_CTL( link_num ));
        ocx_com_linkx_int_csr.u  =  BDK_CSR_READ( target_node_id, BDK_OCX_COM_LINKX_INT( link_num ));
    }
    else                                 
    {     
        result  =  remote_csr_read_on_t88( target_node_id, BDK_OCX_COM_LINKX_CTL( link_num ), & ocx_com_linkx_ctl_csr.u, verbosity );
        //
        if( result < 0)   
        {
            printf(" *** \n");
            printf(" *** Error in  check_status_of_t88_link_lanes_qlms:  *** Failed read of remote Node-%d  OCX_COM_LINKX_CTL( %d ) \n", target_node_id, link_num );
            printf(" *** \n");

            found_error  =  true ;
            return  found_error ;
        }

        result  =  remote_csr_read_on_t88( target_node_id, BDK_OCX_COM_LINKX_INT( link_num ), & ocx_com_linkx_int_csr.u, verbosity );
        //
        if( result < 0)   
        {
            printf(" *** \n");
            printf(" *** Error in  check_status_of_t88_link_lanes_qlms:  *** Failed read of remote Node-%d  OCX_COM_LINKX_INT( %d ) \n", target_node_id, link_num );
            printf(" *** \n");

            found_error  =  true ;
            return  found_error ;
        }
    } // if - else


    //.........................................|..........................................
    //                                Check the LINK CSRs
    //
    if( (ocx_com_linkx_ctl_csr.s.reinit &  0x0000000000000001) == 1 )
    {
        found_error  =  true ;
        printf(" *** Error:  Node-%d  Link-%u:            REINIT bit is SET! \n", target_node_id, link_num );
    }

    if( (ocx_com_linkx_ctl_csr.s.drop   &  0x0000000000000001) == 1 )
    {
        found_error  =  true ;
        printf(" *** Error:  Node-%d  Link-%u:            DROP bit is SET! \n", target_node_id, link_num );
    }

    if( (ocx_com_linkx_ctl_csr.s.up     &  0x0000000000000001) == 0 )
    {
        found_error  =  true ;
        printf(" *** Error:  Node-%d  Link-%u:            UP bit is NOT SET! \n", target_node_id, link_num );
    }

    if( (ocx_com_linkx_ctl_csr.s.valid  &  0x0000000000000001) == 0 )
    {
        found_error  =  true ;
        printf(" *** Error:  Node-%d  Link-%u:            VALID bit is NOT SET! \n", target_node_id, link_num );
    }


    //----------------------------------------------|-----------------------------------------------
    //                                          OCX Lanes

    // From MS lane to LS lane, e.g.: 11 to 0
    lane_num  =  first_lane_num + num_lanes ;

    for( iter_num = 0;  iter_num < num_lanes;  iter_num++ )
    {
        lane_num -- ;

        //............................................|.............................................
        //                                    Read the Lane CSRs
        if( target_node_id == loc_node_id )   
        {
            ocx_lnex_status_csr.u   =  BDK_CSR_READ( target_node_id, BDK_OCX_LNEX_STATUS( lane_num ));
            ocx_lnex_trn_ctl_csr.u  =  BDK_CSR_READ( target_node_id, BDK_OCX_LNEX_TRN_CTL( lane_num ));
        }
        else                                 
        {
            result  =  remote_csr_read_on_t88( target_node_id, BDK_OCX_LNEX_STATUS( lane_num ),  & ocx_lnex_status_csr.u, verbosity );
            //
            if( result < 0 )   
            {
                printf(" *** \n");
                printf(" *** Error in  check_status_of_t88_link_lanes_qlms:  *** Failed read of remote Node-%d  OCX_LNEX_STATUS( %d ) \n", target_node_id, lane_num );
                printf(" *** \n");

                found_error  =  true ;
                return  found_error ;
            }

            result  =  remote_csr_read_on_t88( target_node_id, BDK_OCX_LNEX_TRN_CTL( lane_num ), & ocx_lnex_trn_ctl_csr.u, verbosity );
            //
            if( result < 0 )   
            {
                printf(" *** \n");
                printf(" *** Error in  check_status_of_t88_link_lanes_qlms:  *** Failed read of remote Node-%d  OCX_LNEX_TRN_CTL( %d ) \n", target_node_id, lane_num );
                printf(" *** \n");

                found_error  =  true ;
                return  found_error ;
            }
        }

//        ocx_lnex_status_csrs[  iter_num ].u  =  ocx_lnex_status_csr.u ;
//        ocx_lnex_trn_ctl_csrs[ iter_num ].u  =  ocx_lnex_trn_ctl_csr.u ;


        //............................................|.............................................
        //                                   Check the Lane CSRs
        //
        if( oci_links_are_doing_training  &&  ((ocx_lnex_status_csr.s.rx_trn_val    &  0x0000000000000001) == 0) )
        {
            found_error  =  true ;
            printf(" *** Error:  Node-%d  Link-%u  Lane-%02u:   RX_TRN_VAL bit is NOT SET! \n", target_node_id, link_num, lane_num );
        }

        if( (ocx_lnex_status_csr.s.rx_scrm_sync  &  0x0000000000000001) == 0 )
        {
            found_error  =  true ;
            printf(" *** Error:  Node-%d  Link-%u  Lane-%02u:   RX_SCRM_SYNC bit is NOT SET! \n", target_node_id, link_num, lane_num );
        }

        if( (ocx_lnex_status_csr.s.rx_bdry_sync  &  0x0000000000000001) == 0 )
        {
            found_error  =  true ;
            printf(" *** Error:  Node-%d  Link-%u  Lane-%02u:   RX_BDRY_SYNC bit is NOT SET! \n", target_node_id, link_num, lane_num );
        }


        // trn_lock = 0   trn_done = 1   trn_enabled = 0   eie_detect = 1
        if( oci_links_are_doing_training )
        {
            if( (ocx_lnex_trn_ctl_csr.s.lock         &  0x0000000000000001) == 1 )
            {
                found_error  =  true ;
                printf(" *** Error:  Node-%d  Link-%u  Lane-%02u:   TRN_LOCK bit is SET! \n", target_node_id, link_num, lane_num );
            }

            if( (ocx_lnex_trn_ctl_csr.s.done         &  0x0000000000000001) == 0 )
            {
                found_error  =  true ;
                printf(" *** Error:  Node-%d  Link-%u  Lane-%02u:   TRN_DONE bit is NOT SET! \n", target_node_id, link_num, lane_num );
            }

            if( (ocx_lnex_trn_ctl_csr.s.ena          &  0x0000000000000001) == 1 )
            {
                found_error  =  true ;
                printf(" *** Error:  Node-%d  Link-%u  Lane-%02u:   TRN_ENA bit is SET! \n", target_node_id, link_num, lane_num );
            }
        }

        if( (ocx_lnex_trn_ctl_csr.s.eie_detect   &  0x0000000000000001) == 0 )
        {
            found_error  =  true ;
            printf(" *** Error:  Node-%d  Link-%u  Lane-%02u:   EIE_DETECT bit is NOT SET! \n", target_node_id, link_num, lane_num );
        }

    } // lane loop


    //----------------------------------------------|-----------------------------------------------
    //                                          OCX QLMs

    // From MS QLM to LS QLM, e.g.: 5 to 4
    qlm_num  =  first_qlm_num + num_qlms ;
    //
    for( iter_num = 0;  iter_num < num_qlms;  iter_num++ )
    {
        qlm_num -- ;

        //............................................|.............................................
        //                                     Read the QLM CSR
        if( target_node_id == loc_node_id )   
        {
            ocx_qlmx_cfg_csr.u  =  BDK_CSR_READ( target_node_id, BDK_OCX_QLMX_CFG( qlm_num ));
        }
        else                                 
        {
            result  =  remote_csr_read_on_t88( target_node_id, BDK_OCX_QLMX_CFG( qlm_num ), & ocx_qlmx_cfg_csr.u, verbosity );
            //
            if( result < 0)   
            {
                printf(" *** \n");
                printf(" *** Error in  check_status_of_t88_link_lanes_qlms:  *** Failed read of remote Node-%d  OCX_QLMX_CFG( %d ) \n", target_node_id, qlm_num );
                printf(" *** \n");

                found_error  =  true ;
                return  found_error ;
            }
        }

        ocx_qlmx_cfg_csrs[ iter_num ].u  =  ocx_qlmx_cfg_csr.u ;


        //..........................................|...........................................
        //                                  Check the QLM CSR
        //
        if( oci_links_are_doing_training  &&  ((ocx_qlmx_cfg_csr.s.trn_ena & 0x01) == 0) )
        {
            found_error  =  true ;
            printf(" *** Error:  Node-%d  Link-%u  QLM-%u:      TRN_ENA bit is NOT SET! \n", target_node_id, link_num, qlm_num );
        }

//        if( (ocx_qlmx_cfg_csr.s.timer_dis & 0x01) == 1 )
//        {
//            found_error  =  true ;
//            printf("     Warn:   Node-%d  Link-%u  QLM-%u:   BAD_LANE Timeouts are disabled! \n", target_node_id, link_num, qlm_num );
//        }

    } // QLM loop

    
    //............................................|.............................................
    //                                    Check the QLM CSR

    // Ready Lanes:
    //
    rdy_lane_flags       =  0 ;
    all_lane_flags_ones  =  0 ;
    //
    for( iter_num = 0;  iter_num < num_qlms;  iter_num++ )
    {
        rdy_lane_flags   =  rdy_lane_flags << 4 ;  //  Make room for next field.
        rdy_lane_flags  |=  ocx_qlmx_cfg_csrs[ iter_num ].s.ser_lane_ready  &  0x000000000000000F ;

        all_lane_flags_ones   =  all_lane_flags_ones << 4 ;
        all_lane_flags_ones  |=  0xF ;
    }

    if( rdy_lane_flags != all_lane_flags_ones )
    {
        found_error  =  true ;
        if(       num_lanes ==  8 )   printf(" *** Error:  Node-%d  Link-%u:            Lanes RDY = 0x%02X  !=  0x%02X \n", target_node_id, link_num, rdy_lane_flags, all_lane_flags_ones );
        else if ( num_lanes == 12 )   printf(" *** Error:  Node-%d  Link-%u:            Lanes RDY = 0x%03X  !=  0x%03X \n", target_node_id, link_num, rdy_lane_flags, all_lane_flags_ones );
        else                          printf(" *** Error:  Node-%d  Link-%u:            Lanes RDY = 0x%03X  !=  0x%03X \n", target_node_id, link_num, rdy_lane_flags, all_lane_flags_ones );
    }


    // Bad Lanes:
    //
    bad_lane_flags  =  0 ;
    //
    for( iter_num = 0;  iter_num < num_qlms;  iter_num++ )
    {
        bad_lane_flags   =  bad_lane_flags << 4 ;  //  Make room for next field.
        bad_lane_flags  |=  ocx_qlmx_cfg_csrs[ iter_num ].s.ser_lane_bad  &  0x000000000000000F ;
    }

    if( bad_lane_flags != 0 )
    {
        found_error  =  true ;
        if(       num_lanes ==  8 )   printf(" *** Error:  Node-%d  Link-%u:            Lanes BAD = 0x%02X  !=  0x00 \n",   target_node_id, link_num, bad_lane_flags);
        else if ( num_lanes == 12 )   printf(" *** Error:  Node-%d  Link-%u:            Lanes BAD = 0x%03X  !=  0x000 \n", target_node_id, link_num, bad_lane_flags);
        else                          printf(" *** Error:  Node-%d  Link-%u:            Lanes BAD = 0x%03X  !=  0x000 \n", target_node_id, link_num, bad_lane_flags);
    }


    //==============================================================================================
    if( ! found_error )   printf("     Found no problems on Link-%d \n", link_num );
    else                  printf(" \n");

    return  found_error ;

} // check_status_of_t88_link_lanes_qlms             // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                   display_local_ocx_status_of_link
//################################################|#################################################
/*                                    
 */
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void      display_local_ocx_status_of_link_hdr(   unsigned int link_num )     // <_function_>
{
    const bdk_node_t   loc_node_id   =  bdk_numa_local();    // 0 or 1

    printf("> display_link_ocx_status:   Node-%d   Link-%d \n", loc_node_id, link_num );
    printf(">     ------------------------------------------------------------------------------------- \n");
    printf(">     |          TLK Tx Link Status          |                 TLK Statistics             | \n");
    printf(">     |                                      |                                            | \n");
    printf(">     |                     D                |                                            | \n");
    printf(">     |                     R            BLK |                                            | \n");
    printf(">     |RPLY   Tx   RX  ACK  O  Block     SUB |                                            | \n");
    printf(">     |FPTR  SEQ  SEQ  CNT  P  StateM    CNT |      Data Blks Xferd    Data Blks Repeated | \n");
    printf(">     |                                      |                                            | \n");

//  printf(">     | 255  255  255  127  1  ssssssss   3  | xxxxxxxxxxxxxxxxxxxx  xxxxxxxxxxxxxxxxxxxx | \n");
}                                                    // <_function_end_>


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int       display_local_ocx_status_of_link(    unsigned int link_num )     // <_function_>
{
    const bdk_node_t   loc_node_id   =  bdk_numa_local();    // 0 or 1

    bdk_ocx_tlkx_status_t           ocx_tlkx_status_csr ;
//    bdk_ocx_tlkx_stat_idle_cnt_t    ocx_tlkx_stat_idle_cnt_csr ;
    bdk_ocx_tlkx_stat_data_cnt_t    ocx_tlkx_stat_data_cnt_csr ;
//    bdk_ocx_tlkx_stat_sync_cnt_t    ocx_tlkx_stat_sync_cnt_csr ;
    bdk_ocx_tlkx_stat_retry_cnt_t   ocx_tlkx_stat_retry_cnt_csr ;
//    bdk_ocx_tlkx_stat_err_cnt_t     ocx_tlkx_stat_err_cnt_csr ;

    int  result    =  0 ;

    //==============================================|===============================================
    //                                     Read the Link CSRs

//    if( target_node_id == loc_node_id )   
//    {
        ocx_tlkx_status_csr.u          =  BDK_CSR_READ( loc_node_id, BDK_OCX_TLKX_STATUS(         link_num ));
//        ocx_tlkx_stat_idle_cnt_csr.u   =  BDK_CSR_READ( loc_node_id, BDK_OCX_TLKX_STAT_IDLE_CNT(  link_num ));
        ocx_tlkx_stat_data_cnt_csr.u   =  BDK_CSR_READ( loc_node_id, BDK_OCX_TLKX_STAT_DATA_CNT(  link_num ));
//        ocx_tlkx_stat_sync_cnt_csr.u   =  BDK_CSR_READ( loc_node_id, BDK_OCX_TLKX_STAT_SYNC_CNT(  link_num ));
        ocx_tlkx_stat_retry_cnt_csr.u  =  BDK_CSR_READ( loc_node_id, BDK_OCX_TLKX_STAT_RETRY_CNT( link_num ));
//        ocx_tlkx_stat_err_cnt_csr.u    =  BDK_CSR_READ( loc_node_id, BDK_OCX_TLKX_STAT_ERR_CNT(   link_num ));
//    }
//    else                                 
//    {
//        result  =  remote_csr_read_on_t88( target_node_id, BDK_OCX_TLKX_STATUS(         link_num ),  & ocx_tlkx_status_csr.u,         verbosity );
//        result  =  remote_csr_read_on_t88( target_node_id, BDK_OCX_TLKX_STAT_IDLE_CNT(  link_num ),  & ocx_tlkx_stat_idle_cnt_csr.u,  verbosity );
//        result  =  remote_csr_read_on_t88( target_node_id, BDK_OCX_TLKX_STAT_DATA_CNT(  link_num ),  & ocx_tlkx_stat_data_cnt_csr.u,  verbosity );
//        result  =  remote_csr_read_on_t88( target_node_id, BDK_OCX_TLKX_STAT_SYNC_CNT(  link_num ),  & ocx_tlkx_stat_sync_cnt_csr.u,  verbosity );
//        result  =  remote_csr_read_on_t88( target_node_id, BDK_OCX_TLKX_STAT_RETRY_CNT( link_num ),  & ocx_tlkx_stat_retry_cnt_csr.u, verbosity );
//        result  =  remote_csr_read_on_t88( target_node_id, BDK_OCX_TLKX_STAT_ERR_CNT(   link_num ),  & ocx_tlkx_stat_err_cnt_csr.u,   verbosity );
//    }

    //------------------------------------------|-----------------------------------------
    //                              Block State Machine Decoding
    //
    char  sm_state_str[ 16 ];
    //                           12345678         54 3210
    char  sm_state_02_str[]  =  "I_ACK   ";    // 00 0010
    char  sm_state_03_str[]  =  "I_REQ   ";    // 00 0011
    char  sm_state_04_str[]  =  "Run     ";    // 00 0100
    char  sm_state_24_str[]  =  "Run_RP  ";    // 10 0100
    char  sm_state_08_str[]  =  "R_ACK   ";    // 00 1000
    char  sm_state_28_str[]  =  "R_ACK_RP";    // 10 1000
    char  sm_state_09_str[]  =  "R_REQ   ";    // 00 1001
    char  sm_state_29_str[]  =  "R_REQ_RP";    // 10 1001
    char  sm_state_10_str[]  =  "Replay  ";    // 01 0000
    char  sm_state_30_str[]  =  "Reply_RP";    // 11 0000

    if(      ocx_tlkx_status_csr.s.sm == 0x02 )   strcpy(  sm_state_str, sm_state_02_str );
    else if( ocx_tlkx_status_csr.s.sm == 0x03 )   strcpy(  sm_state_str, sm_state_03_str );
    else if( ocx_tlkx_status_csr.s.sm == 0x04 )   strcpy(  sm_state_str, sm_state_04_str );
    else if( ocx_tlkx_status_csr.s.sm == 0x24 )   strcpy(  sm_state_str, sm_state_24_str );
    else if( ocx_tlkx_status_csr.s.sm == 0x08 )   strcpy(  sm_state_str, sm_state_08_str );
    else if( ocx_tlkx_status_csr.s.sm == 0x28 )   strcpy(  sm_state_str, sm_state_28_str );
    else if( ocx_tlkx_status_csr.s.sm == 0x09 )   strcpy(  sm_state_str, sm_state_09_str );
    else if( ocx_tlkx_status_csr.s.sm == 0x29 )   strcpy(  sm_state_str, sm_state_29_str );
    else if( ocx_tlkx_status_csr.s.sm == 0x10 )   strcpy(  sm_state_str, sm_state_10_str );
    else if( ocx_tlkx_status_csr.s.sm == 0x30 )   strcpy(  sm_state_str, sm_state_30_str );
    else                                          sprintf( sm_state_str, "*** 0x%02X", ocx_tlkx_status_csr.s.sm );

    //------------------------------------------|-----------------------------------------
    //                              Display the Status Fields
    //
    printf(">     | %3d  %3d  %3d  %3d  %d  %8s   %d  | %20lu  %20lu | \n"
                  , ocx_tlkx_status_csr.s.rply_fptr
                       , ocx_tlkx_status_csr.s.tx_seq
                            , ocx_tlkx_status_csr.s.rx_seq
                                 , ocx_tlkx_status_csr.s.ackcnt
                                     , ocx_tlkx_status_csr.s.drop

                                            , sm_state_str
                                                   , ocx_tlkx_status_csr.s.cnt

                                                              , ocx_tlkx_stat_data_cnt_csr.s.count
                                                                            , ocx_tlkx_stat_retry_cnt_csr.s.count
    );

    //==============================================|===============================================
    return  result ;

} // display_local_ocx_status_of_link                // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                              get_local_gser_rx_equal_figure_of_merit
//################################################|#################################################
int       get_local_gser_rx_equal_figure_of_merit(  uint gser_num,  uint gser_lane_num  )    // <_function_>
{
    bdk_gserx_br_rxx_eer_t    gserx_br_rxx_eer_csr ;  // RXT_ERR (1b), RXT_ESV (1b), RXT_ESM (14b)
    //
    // RXT_ESM:
    //     13:6:  Rx Equalization Figure-of-Merit - 8 bits - higher value means better equalization settings
    //      5:4:  Recommended TxPOST change (0= hold, 1= incr, 2= decr, 3= hold)
    //      3:2:  Recommended TxMain change
    //      1:0:  Recommended TxPre  change

    uint      equal_status_valid ;
    int       figure_of_merit ;

    uint64_t  curr_clk_count ;
    uint64_t  timeout_clk_count ;
    uint64_t  timeout_usec ;

//    uint      verbosity    =  0 ;
//    int       call_result  =  0 ;

    //============================================|=================================================
    //                                         Set Up
    //
    const bdk_node_t  loc_node_id   =  bdk_numa_local();
    const uint64_t    clk_freq_mhz  =  bdk_clock_get_rate( loc_node_id, BDK_CLOCK_RCLK ) / 1000000 ;

    //                                    +--- sec
    //                                    |
    //                                    |  +--- msec
    //                                    |  |
    //                                    |  |  +--- usec
    //                                    |  |  |
    //                                    |  |  |  +--- nsec
    //                                    |  |  |  |
    const uint64_t    timeout_clk_cycs  =   10000000 ;  // At 1000 MHz:  1 nsec/cycle.  At 2000 MHz:  0.5 nsec/cycle

    curr_clk_count     =  bdk_clock_get_count( BDK_CLOCK_RCLK );
    timeout_clk_count  =  curr_clk_count + timeout_clk_cycs ;

    //--------------------------------------------------------------------------------------
    //                                Wait for Valid Status
    //
    gserx_br_rxx_eer_csr.u  =  BDK_CSR_READ(    loc_node_id, BDK_GSERX_BR_RXX_EER( gser_num, gser_lane_num ));
    equal_status_valid      =  gserx_br_rxx_eer_csr.s.rxt_esv  & 1 ;

    while( equal_status_valid == 0 )
    {
        curr_clk_count  =  bdk_clock_get_count( BDK_CLOCK_RCLK );
        //
        if( curr_clk_count >= timeout_clk_count )
        {
            printf(" *** \n");
            printf(" *** Error in  'get_gser_rx_equal_fig_of_merit_for_lane':  Timed out waiting for RXT_ESV to set. \n");

            timeout_usec  =  convert_clk_cnt_to_usec( timeout_clk_cycs, clk_freq_mhz );
            //
            printf(" ***     Timed out after waiting:  %6lu.%03lu msec \n",
                                timeout_usec/1000, get_3_ls_decimal_digits( timeout_usec )
                  );
            printf(" *** \n");
            return  -2 ;
        }

        gserx_br_rxx_eer_csr.u  =  BDK_CSR_READ(    loc_node_id, BDK_GSERX_BR_RXX_EER( gser_num, gser_lane_num ));
        equal_status_valid  =  gserx_br_rxx_eer_csr.s.rxt_esv  & 1 ;
    }


    //--------------------------------------------------------------------------------------
    //                          Get RX Equalization Figure of Merit
    //
    figure_of_merit  =  (gserx_br_rxx_eer_csr.s.rxt_esm >> 6) & 0x0FF ;  // = 8 bits starting at bit 6.  

    return  figure_of_merit ;

}  // get_local_gser_rx_equal_figure_of_merit        // <_function_end_>



//################################################|#################################################
//                   Display GSER RX Equalization Figure-of-Merits for Link Header  - t88
//################################################|#################################################
void       display_gser_rx_equal_fig_of_merits_hdr(  uint link_num,  ocx_global_info_t * global_info_ptr )   // <_function_>
{
    uint   num_ocx_lanes ;
    uint   link_lane_num ;

    //============================================|=================================================
    num_ocx_lanes  =  global_info_ptr-> num_lanes_for_link[  link_num ];

    //----------------------------------------------------------------------------------------------
    printf(" GSER Rx Figures-of-Merit:                 Link Lane Numbers \n");
    fflush( stdout );

    //----------------------------------------------------------------------------------------------
    printf("                       ");
    for( link_lane_num = 0;  link_lane_num < num_ocx_lanes;  link_lane_num ++ )
    {
        printf("  %3d", link_lane_num );
    }
    printf(" \n");  // Finish off the line.  
    fflush( stdout );

    //============================================|=================================================
}


//################################################|#################################################  // <_function_hdr_>
//                      Display GSER RX Equalization Figure-of-Merits for Link  - t88
//################################################|#################################################
/*                               
 */
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void      display_local_gser_rx_equal_figure_of_merits(  uint link_num,  ocx_global_info_t * global_info_ptr )    // <_function_>
{
    uint   first_gser_num ;
    uint   num_gsers ;
    uint   gser_num ;
    uint   gser_lane_num ;
    uint   gser_cnt ;

    uint   first_ocx_lane_num ;
    uint   num_ocx_lanes ;
    uint   ocx_lane_num ;
    uint   link_lane_num ;
//    uint   link_cnt ;

    int    figure_of_merit ;
    int    fig_of_merit_lanes_array[ 16 ];

//    int    func_result ;

    //============================================|=================================================
    const bdk_node_t  loc_node_id  =  bdk_numa_local();

    num_gsers           =  global_info_ptr-> num_gsers_for_link[  link_num ];
    first_gser_num      =  global_info_ptr-> first_gser_for_link[ link_num ];

    first_ocx_lane_num  =  global_info_ptr-> first_lane_for_link[ link_num ];
    num_ocx_lanes       =  global_info_ptr-> num_lanes_for_link[  link_num ];

    gser_num            =  first_gser_num ;
    ocx_lane_num        =  first_ocx_lane_num ;
    link_lane_num       =  0 ;

    //----------------------------------------------------------------------------------------------
//    printf(" GSER Rx Figures-of-Merit for Node-%d  Link-%d:\n", loc_node_id, link_num );
//    fflush( stdout );

    for( gser_cnt = 0;  gser_cnt < num_gsers;  gser_cnt ++ )
    {
        // For each gser in the link:
        //
        for( gser_lane_num = 0;  gser_lane_num < 4;  gser_lane_num ++ )
        {
            // For each lane in the gser:
            //
            figure_of_merit  =  get_local_gser_rx_equal_figure_of_merit(  gser_num, gser_lane_num  );
            //
            if( figure_of_merit < 0 )
            {
                printf(" *** \n");
                printf(" *** Error in  'display_gser_rx_equal_fig_of_merits_for_link':  getting  figure-of-merit  failed - with exit code = %d  \n", figure_of_merit );
                printf(" *** \n");
                fflush( stdout );
                return ;
            }

            fig_of_merit_lanes_array[ link_lane_num ]  =  figure_of_merit ;

//            printf("     Node_%d  Link-%d  Lane-%02d  (OCX Lane-%02d):  %3u \n", loc_node_id, link_num, link_lane_num, ocx_lane_num, figure_of_merit );
//            fflush( stdout );

            link_lane_num ++ ;
            ocx_lane_num ++ ;
        }

        gser_num ++ ;
    }
//    printf(" \n");


    //----------------------------------------------------------------------------------------------
    printf("       Node-%d  Link-%d: ", loc_node_id, link_num );

    for( link_lane_num = 0;  link_lane_num < num_ocx_lanes;  link_lane_num ++ )
    {
        // For each Lane in the link:
        //
        figure_of_merit  =  fig_of_merit_lanes_array[ link_lane_num ];
        printf("  %3d", figure_of_merit );
    }
    printf(" \n");  // Finish off the line.  
    fflush( stdout );


    //============================================|=================================================

} // display_local_gser_rx_equal_figure_of_merits    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                     get_local_credits_for_vc
//################################################|#################################################
/*
    Reads the credits available and the credits to return of the VC.
 */
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int       get_local_credits_for_vc(  uint link_num,  uint vc_num,  uint * credits_avail,  uint * credits_to_rtn )       // <_function_>
{
    const bdk_node_t   loc_node_id  =  bdk_numa_local();

    // OCX_TLK(0..2)_LNK_VC(0..13)_CNT:  COUNT (16b)
    bdk_ocx_tlkx_lnk_vcx_cnt_t   ocx_tlkx_lnk_vcx_cnt_csr ;    // COUNT (16b)

    // OCX_TLK(0..2)_RTN_VC(0..13)_CNT:  COUNT (16b)
    bdk_ocx_tlkx_rtn_vcx_cnt_t   ocx_tlkx_rtn_vcx_cnt_csr ;    // COUNT (16b)

    uint   num_credits_avail ;
    uint   num_credits_to_rtn ;

//    int    result ;
    int    func_result  =  0 ;
//    int    verbosity    =  0 ;

    //------------------------------------------------------------------------------------
    ocx_tlkx_lnk_vcx_cnt_csr.u  =  BDK_CSR_READ( loc_node_id, BDK_OCX_TLKX_LNK_VCX_CNT( link_num, vc_num ));
    ocx_tlkx_rtn_vcx_cnt_csr.u  =  BDK_CSR_READ( loc_node_id, BDK_OCX_TLKX_RTN_VCX_CNT( link_num, vc_num ));

    num_credits_avail   =  ocx_tlkx_lnk_vcx_cnt_csr.s.count ;
    num_credits_to_rtn  =  ocx_tlkx_rtn_vcx_cnt_csr.s.count ;

    //------------------------------------------------------------------------------------
    * credits_avail   =  num_credits_avail ;
    * credits_to_rtn  =  num_credits_to_rtn ;

    return  func_result ;

} // get_local_credits_for_vc                        // <_function_end_>




//################################################|#################################################  // <_function_hdr_>
//                                 check_local_vc_credits_on_link
//################################################|#################################################
/*                             
    Check the credits available  and the credits to return on each VC of the link.

 */
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int       check_local_vc_credits_on_link(  uint link_num  )    // <_function_>
{
//    const bdk_node_t  loc_node_id    =  bdk_numa_local();

    // OCX_TLK(0..2)_LNK_VC(0..13)_CNT:  COUNT (16b)
//    bdk_ocx_tlkx_lnk_vcx_cnt_t   ocx_tlkx_lnk_vcx_cnt_csr ;

    // OCX_TLK(0..2)_RTN_VC(0..13)_CNT:  COUNT (16b)
//    bdk_ocx_tlkx_rtn_vcx_cnt_t   ocx_tlkx_rtn_vcx_cnt_csr ;

    uint   vc_num ;
    uint   num_credits_avail ;
    uint   num_credits_to_rtn ;

    uint   ok_vc_credits ;


    const uint  ok_vc_credits_array[ 16 ]  = { 250    // VC-0
                                             , 250    // VC-1
                                             , 250    // VC-2
                                             , 250    // VC-3
                                             , 250    // VC-4
                                             , 250    // VC-5
                                             , 120    // VC-6
                                             , 120    // VC-7
                                             , 120    // VC-8
                                             , 120    // VC-9
                                             , 120    // VC-10
                                             , 120    // VC-11
                                             ,  28    // VC-12
                                             ,   1    // VC-13
                                             ,   0    // (14)
                                             ,   0    // (15)
                                             };

    // Error Conditions:
    bool   all_vcs_have_zero_credits_avail    =  true ;    // It only takes one VC to invalidate this condition
    bool   all_vcs_have_credits_to_rtn        =  true ;    // It only takes one VC to invalidate this condition
    bool   at_least_1_vc_not_have_ok_credits  =  false ;    // It only takes one VC to validate this condition

    int    result ;
    bool   credits_are_ok  =  true ;

    //----------------------------------------------------------------------------------------------
    for( vc_num = 0;  vc_num < 12;  vc_num ++ )    // Ignore VC-13
    {
        result  =  get_local_credits_for_vc(  link_num, vc_num,  & num_credits_avail,  & num_credits_to_rtn  );
        //
        if( result < 0 )
        {
            printf(" *** \n");
            printf(" *** Error in 'check_local_vc_credits_on_link':  failure reading credits! *** \n");
            printf(" *** \n");
            fflush( stdout );

            return  -1 ;
        }
        
        ok_vc_credits  =  ok_vc_credits_array[ vc_num ];

        if( num_credits_avail < ok_vc_credits )
        {
            printf(" *** \n");
            printf(" *** Error in  'check_local_vc_credits_on_link':  Link-%u  VC-%d has %u credits avail, but needs  %u credits to be OK. \n", link_num, vc_num, num_credits_avail, ok_vc_credits );
            printf(" *** \n");
            fflush( stdout );
            
            at_least_1_vc_not_have_ok_credits  =  true ;
        }

        if( num_credits_avail  >  0 )   all_vcs_have_zero_credits_avail  =  false ;
        if( num_credits_to_rtn == 0 )   all_vcs_have_credits_to_rtn      =  false ;
    }

    //----------------------------------------------------------------------------------------------
    if( at_least_1_vc_not_have_ok_credits )                                  credits_are_ok  =  false ;
    if( all_vcs_have_zero_credits_avail  &&  all_vcs_have_credits_to_rtn )   credits_are_ok  =  false ;

    //----------------------------------------------------------------------------------------------
    return  credits_are_ok ;

} // check_local_vc_credits_on_link                  // <_function_end_>




//################################################|#################################################  // <_function_hdr_>
//                               display_local_vc_credits_on_link
//################################################|#################################################
/*                             
 */
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int       display_local_vc_credits_on_link(  int link_num  )    // <_function_>
{
    const bdk_node_t  loc_node_id    =  bdk_numa_local();

    // OCX_TLK(0..2)_LNK_VC(0..13)_CNT:  COUNT (16b)
//    bdk_ocx_tlkx_lnk_vcx_cnt_t   ocx_tlkx_lnk_vcx_cnt_csr ;

    // OCX_TLK(0..2)_RTN_VC(0..13)_CNT:  COUNT (16b)
//    bdk_ocx_tlkx_rtn_vcx_cnt_t   ocx_tlkx_rtn_vcx_cnt_csr ;

    uint   vc_num ;
    uint   num_credits_avail ;
    uint   num_credits_to_rtn ;

    uint   initial_vc_credits ;
    const uint  initial_vc_credits_array[ 16 ]  = { 256    // VC-0
                                                  , 256    // VC-1
                                                  , 256    // VC-2
                                                  , 256    // VC-3
                                                  , 256    // VC-4
                                                  , 256    // VC-5
                                                  , 128    // VC-6
                                                  , 128    // VC-7
                                                  , 128    // VC-8
                                                  , 128    // VC-9
                                                  , 128    // VC-10
                                                  , 128    // VC-11
                                                  ,  32    // VC-12
                                                  ,   1    // VC-13
                                                  ,   0    // (14)
                                                  ,   0    // (15)
                                                  };

    int    result     =  0 ;

    //------------------------------------------------------------------------------------
    printf(" VC Credits on  Node-%d  Link-%d:\n", loc_node_id, link_num );
    fflush( stdout );

    for( vc_num = 0;  vc_num < 13;  vc_num ++ )
    {
        result  =  get_local_credits_for_vc( link_num, vc_num,  & num_credits_avail,  & num_credits_to_rtn );
        //
        if( result < 0 )
        {
            printf(" *** \n");
            printf(" *** Error in 'display_vc_credits_avail_and_rtn_for_link':  failure reading credits! *** \n");
            printf(" *** \n");
        }

        initial_vc_credits  =  initial_vc_credits_array[ vc_num ];

        printf("     Node-%d  Link-%u   VC-%02u:  %5u credits avail    %5u  credits to rtn   (Initially:  %3u credits )\n", loc_node_id, link_num, vc_num, num_credits_avail, num_credits_to_rtn, initial_vc_credits );
    }

    printf(" \n");
    fflush( stdout );

    //------------------------------------------------------------------------------------
    return  result ;

} // display_local_vc_credits_on_link                // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                               check_local_vc_credits_on_active_links
//################################################|#################################################
/*                             
    Check the credits available  and the credits to return on each VC of the link.

 */
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
bool      check_local_vc_credits_on_active_links(  ocx_global_info_t * global_info_ptr  )    // <_function_>
{
    const bdk_node_t  loc_node_id    =  bdk_numa_local();

    uint  num_active_links  =  global_info_ptr-> num_active_links ;
    uint  index ;
    uint  link_num ;

    bool  credits_are_ok ;
    bool  found_error  =  false ;


    //==============================================================================================
    printf(" Checking OCI VC Credits  of the Active Links  on  Local Node-%d: \n", loc_node_id );
    fflush( stdout );

    for( index = 0;  index < num_active_links;  index ++ )
    {
        link_num  =  global_info_ptr-> active_links_array[ index ];

        credits_are_ok  =  check_local_vc_credits_on_link(  link_num  );
        if( credits_are_ok == false )
        {
            printf(" *** \n");
            printf(" *** ERROR:  OCX Credits Error on  Local Node-%d  Link-%d ! *** \n", loc_node_id, link_num );
            printf(" *** \n");

            display_local_vc_credits_on_link(  link_num  );

            printf(" *** \n");
            printf(" \n");
            fflush( stdout );

            found_error  =  true ;
        }
        else
        {
            printf("     VC Credits are OK on  Local Node-%d  Link-%d \n", loc_node_id, link_num );
            fflush( stdout );
        }

    } // for
//    printf(" \n");
    fflush( stdout );


    //==============================================================================================
    return  found_error ;
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                             check_for_bad_initial_ocx_state_on_link
//################################################|#################################################
/*                             
    Checks for these bad conditions:  
        RPLY_FPTR, TX_SEQ, RX_SEQ  == 255
        SM != 'run'
        repeated blocks cnt > 0
        DROP != 0

     Problem Vector:  
         -1:  Error reading the CSRs

          0:  No problems!

         >0:  Bits   5  4  3  2  1  0
                     |  |  |  |  |  |
                     |  |  |  |  |  |___ OCX State Machine State is not 'run'
                     |  |  |  |  |
                     |  |  |  |  |______ OCX Retry count > 0
                     |  |  |  |
                     |  |  |  |_________ OCX RPLY FPTR == 255
                     |  |  |
                     |  |  |____________ OCX TX Sequence number == 255
                     |  |
                     |  |_______________ OCX RX Sequence number == 255
                     |
                     |__________________ OCX DROP != 0

 */
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int       check_for_bad_initial_ocx_state_on_link(  uint link_num  )    // <_function_>
{
    const bdk_node_t  loc_node_id    =  bdk_numa_local();

    bdk_ocx_tlkx_status_t           ocx_tlkx_status_csr ;    // RPLY_FPTR, TX_SEQ, RX_SEQ, ACKCNT, DROP, SM, CNT
//    bdk_ocx_tlkx_stat_data_cnt_t    ocx_tlkx_stat_data_cnt_csr ;
    bdk_ocx_tlkx_stat_retry_cnt_t   ocx_tlkx_stat_retry_cnt_csr ;

    // Problem flags vector:
    int  ocx_problem_vector  =  0 ;    // any problem found turns this > 0.


    //==============================================================================================
    //                                       Read the CSRs
    //
    ocx_tlkx_status_csr.u          =  BDK_CSR_READ( loc_node_id, BDK_OCX_TLKX_STATUS( link_num ));
//    ocx_tlkx_stat_data_cnt_csr.u   =  BDK_CSR_READ( loc_node_id, BDK_OCX_TLKX_STAT_DATA_CNT(  link_num ));
    ocx_tlkx_stat_retry_cnt_csr.u  =  BDK_CSR_READ( loc_node_id, BDK_OCX_TLKX_STAT_RETRY_CNT( link_num ));

    //----------------------------------------------------------------------------------------------
    //                                     Checking the CSRs

    // Assert:  OCX Block SM == Run
    if( ocx_tlkx_status_csr.s.sm != 0x04 )
    {
        printf("> check_for_bad_ocx_state:  Node-%d  Link-%d:  ocx_tlkx_status_csr.s.sm = %d  instead of 4 \n", loc_node_id, link_num, ocx_tlkx_status_csr.s.sm );
        ocx_problem_vector  |=  0x0001 ;  // OCX Problem
    }

    // Assert:  Data_Blocks_repeated == 0
    if( ocx_tlkx_stat_retry_cnt_csr.s.count > 0 )
    {
        printf("> check_for_bad_ocx_state:  Node-%d  Link-%d:  ocx_tlkx_stat_retry_cnt_csr.s.count = %lu > 0 \n", loc_node_id, link_num, ocx_tlkx_stat_retry_cnt_csr.s.count );
        ocx_problem_vector  |=  (0x0001 << 1);  // OCX Problem
    }

    // Assert:  rply_fptr != 255
    if( ocx_tlkx_status_csr.s.rply_fptr == 255 )
    {
        printf("> check_for_bad_ocx_state:  Node-%d  Link-%d:  ocx_tlkx_status_csr.s.rply_fptr == 255 \n", loc_node_id, link_num );
        ocx_problem_vector  |=  (0x0001 << 2);  // OCX Problem
    }

    // Assert:  tx_seq != 255
    if( ocx_tlkx_status_csr.s.tx_seq == 255 )
    {
        printf("> check_for_bad_ocx_state:  Node-%d  Link-%d:  ocx_tlkx_status_csr.s.tx_seq == 255 \n", loc_node_id, link_num );
        ocx_problem_vector  |=  (0x0001 << 3);  // OCX Problem
    }

    // Assert:  rx_seq != 255
    if( ocx_tlkx_status_csr.s.rx_seq == 255 )
    {
        printf("> check_for_bad_ocx_state:  Node-%d  Link-%d:  ocx_tlkx_status_csr.s.rx_seq == 255 \n", loc_node_id, link_num );
        ocx_problem_vector  |=  (0x0001 << 4);  // OCX Problem
    }

    // Assert:  DROP == 0
    if( ocx_tlkx_status_csr.s.drop != 0 )
    {
        printf("> check_for_bad_ocx_state:  Node-%d  Link-%d:  ocx_tlkx_status_csr.s.drop == 255 \n", loc_node_id, link_num );
        ocx_problem_vector  |=  (0x0001 << 5);  // OCX Problem
    }

    //==============================================================================================
    return  ocx_problem_vector ;

} // check_for_bad_initial_ocx_state_on_link         // <_function_end_>




//################################################|#################################################  // <_function_hdr_>
//                                check_local_ocx_state_of_active_links
//################################################|#################################################
bool      check_local_t88_link_lane_qlm_status_of_active_links(  ocx_global_info_t * global_info_ptr  )    // <_function_>
{
    const bdk_node_t  loc_node_id    =  bdk_numa_local();

    uint  num_active_links  =  global_info_ptr-> num_active_links ;
    uint  index ;
    uint  link_num ;

    bool  found_error  =  false ;

    //==============================================================================================
    printf(" Checking Link/Lane/QLM Status  of Active Links  on  Local Node-%d: \n", loc_node_id );
//    printf(" \n");

    for( index = 0;  index < num_active_links;  index ++ )
    {
        link_num  =  global_info_ptr-> active_links_array[ index ];

        found_error  =  check_status_of_t88_link_lanes_qlms(  loc_node_id, link_num, global_info_ptr  );
    }

    //==============================================================================================
    return  found_error ;
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                check_local_ocx_state_of_active_links
//################################################|#################################################
bool      check_local_t88_ocx_state_of_active_links(  ocx_global_info_t * global_info_ptr  )    // <_function_>
{
    const bdk_node_t  loc_node_id    =  bdk_numa_local();

    uint  num_active_links  =  global_info_ptr-> num_active_links ;
    uint  index ;
    uint  link_num ;

    bool  found_error  =  false ;
    int   ocx_problem_flags_vector ;


    //==============================================================================================
    printf(" Checking OCX State  of Active Links  on  Local Node-%d: \n", loc_node_id );
//    printf(" \n");

    for( index = 0;  index < num_active_links;  index ++ )
    {
        link_num  =  global_info_ptr-> active_links_array[ index ];
//        printf("     Link-%d: \n", link_num );

        // Check OCX State:
        ocx_problem_flags_vector  =  check_for_bad_initial_ocx_state_on_link( link_num );

        if( ocx_problem_flags_vector > 0 )
        {
            found_error  =  true ;

            printf(" *** \n");
            printf(" *** Node-%d   Link-%d:  Found problem(s) with OCX state! \n", loc_node_id, link_num );
            printf(" ***               ocx_problem_flags_vector:  0x%x\n", ocx_problem_flags_vector );
            printf(" *** \n");

            display_local_ocx_status_of_link_hdr( link_num );
            display_local_ocx_status_of_link(     link_num );
            printf(" \n");
        }
        else
        {
            printf("     OCX state is GOOD  on Node-%d  Link-%d. \n", loc_node_id, link_num );
        }
    } // for

    //==============================================================================================
    return  found_error ;
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                      oci_link_is_operational
//################################################|#################################################
/*
    Checks Interlaken state, OCX credits, OCX sequence numbers, and OCX run state
*/
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
bool      oci_link_is_operational(            int link_num )               // <_function_>
{
//    const bdk_node_t   loc_node_id  =  bdk_numa_local();

    bool   link_is_up  =  true ;
    bool   interlaken_is_up ;
    int    ocx_problem_flags_vector ;
    bool   credits_are_ok ;
    bool   found_error  =  false ;

    //==============================================================================================


    //----------------------------------------------------------------------------------------------
    //                                  Check Interlaken State:
    //
    interlaken_is_up  =  oci_link_is_up(  link_num  );    // Checks UP & VALID bits
    //
    if( ! interlaken_is_up )   found_error  =  true ;


    //----------------------------------------------------------------------------------------------
    //                                  Check OCX State:
    //
    ocx_problem_flags_vector  =  check_for_bad_initial_ocx_state_on_link( link_num );
    //
    if( ocx_problem_flags_vector > 0 )
    {
//        printf(" *** \n");
//        printf(" *** Node-%d   Link-%d:  Found problem(s) with OCX state! \n", loc_node_id, link_num );
//        printf(" *** \n");
//
//        display_local_ocx_status_of_link_hdr( link_num );
//        display_local_ocx_status_of_link(     link_num );
//        printf(" \n");
//        fflush( stdout );

        found_error  =  true ;
    }

    //----------------------------------------------------------------------------------------------
    //                                     Check Credits
    //
    credits_are_ok  =  check_local_vc_credits_on_link(  link_num  );
    //
    if( credits_are_ok == false )
    {
//        printf(" *** \n");
//        printf(" *** ERROR:  OCX Credits Error on  Local Node-%d  Link-%d ! *** \n", loc_node_id, link_num );
//        printf(" *** \n");
//
//        display_local_vc_credits_on_link(  link_num  );
//
//        printf(" *** \n");
//        printf(" \n");
//        fflush( stdout );
        
        found_error  =  true ;
    }

    //----------------------------------------------------------------------------------------------
    //                                     Final Result
    //
    if( found_error )   link_is_up  =  false ;
    else                link_is_up  =  true ;

    //==============================================================================================
    return  link_is_up ;
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                 find_number_of_operational_links
//################################################|#################################################
uint      find_number_of_operational_links(    ocx_global_info_t * global_info_ptr  )    // <_function_>
{
    uint  link_num ;
    uint  num_links_up ;

    //==============================================|===============================================
    num_links_up  =  0 ;

    for( link_num = 0;  link_num < 3;  link_num++ )
    {
        if( oci_link_is_operational( link_num ) )
        {
            global_info_ptr-> up_links_array[ num_links_up ]  =  link_num ;
            global_info_ptr-> link_is_up[ link_num ]  =  true ;

            num_links_up ++ ;
        }
        else
        {
            global_info_ptr-> link_is_up[ link_num ]  =  false ;
        }
    } // for

    global_info_ptr-> num_links_up  =  num_links_up ;


    //==============================================|===============================================
    return  num_links_up ;
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                capture_local_training_gser_activity
//################################################|#################################################
/*
                            |2 2 2 2 2 1 1 1 1 1 1 1 1 1 1                    |
                            |4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0|
                            |       |       |                 |   |   |   | | |
                            |       |       |                 |   |   |   | | |
GSER_TXTRAIN_DBG:           |       |       |                 |   |   |   | | |
    gser_tx_train_sm        |3 2 1 0|       |                 |   |   |   | | |
                                    |       |                 |   |   |   | | |
GSER_RXTRAIN_SML:                   |       |                 |   |   |   | | |
    gser_rx_train_sm                |3 2 1 0|                 |   |   |   | | |
                                            |                 |   |   |   | | |
GSER_TXTRAIN_DBG:                           |                 |   |   |   | | |
    dbg_tx_cu_data                          |8 7 6 5 4 3 2 1 0|   |   |   | | |
                                                              |   |   |   | | |
GSER_RXTRAIN_SML:                                             |   |   |   | | |
    cu_pre                                                    |1 0|   |   | | |
    cu_main                                                       |1 0|   | | |
    cu_post                                                           |1 0| | |
                                                                          | | |
GSER_RXTRAIN_SMH:                                                         | | |
    taps_equalized                                                        |0| |
    receiver_rdy                                                            |0|
                                                                               
 */
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
uint64_t  capture_local_t88_training_gser_activity(     uint ocx_lane_num )        // <_function_>
{
//    const bdk_node_t  loc_node_id    =  bdk_numa_local();

    // GSER_RXTRAIN_SML
    uint64_t   gser_rxtrain_sml_reg ;
    uint  rx_train_sm ;
    uint  rx_cu_pre ;
    uint  rx_cu_main ;
    uint  rx_cu_post ;

    // GSER_RXTRAIN_SMH
    uint64_t   gser_rxtrain_smh_reg ;
    uint  rx_taps_equalized ;
    uint  receiver_rdy ;

    // GSER_TXTRAIN_LANE_DBG
    uint64_t   gser_txtrain_dbg_reg ;
    uint  tx_train_sm ;
    uint  tx_cu_data ;

    uint64_t  capture_wd  =  0 ;

    //==============================================|===============================================
    const uint   gser_num       =  GSER_Num_For_OCX_Lane[      ocx_lane_num ];
    const uint   gser_lane_num  =  GSER_Lane_Num_For_OCX_Lane[ ocx_lane_num ];

    gser_rxtrain_sml_reg  =  get_t88_gser_rxtrain_sml_reg(  gser_num, gser_lane_num  );
    rx_train_sm     =  EXTRACT_GSER_RXTRAIN_SM(      gser_rxtrain_sml_reg );
    rx_cu_pre       =  EXTRACT_GSER_RXTRAIN_CU_PRE(  gser_rxtrain_sml_reg );
    rx_cu_main      =  EXTRACT_GSER_RXTRAIN_CU_MAIN( gser_rxtrain_sml_reg );
    rx_cu_post      =  EXTRACT_GSER_RXTRAIN_CU_POST( gser_rxtrain_sml_reg );

    gser_rxtrain_smh_reg  =  get_t88_gser_rxtrain_smh_reg(  gser_num, gser_lane_num  );
    rx_taps_equalized  =  EXTRACT_GSER_RXTRAIN_TAPS_EQUALIZED( gser_rxtrain_smh_reg );
    receiver_rdy       =  EXTRACT_GSER_RXTRAIN_RECEIVER_RDY(   gser_rxtrain_smh_reg );

    gser_txtrain_dbg_reg  =  get_t88_gser_txtrain_dbg_reg(  gser_num, gser_lane_num  );
    tx_train_sm  =  EXTRACT_GSER_TXTRAIN_SM(         gser_txtrain_dbg_reg );
    tx_cu_data   =  EXTRACT_GSER_TXTRAIN_TX_CU_DATA( gser_txtrain_dbg_reg );


    //----------------------------------------------------------------------------------------------
    capture_wd   =  0 ;
    capture_wd  |=  tx_train_sm & 0x0F ;

    capture_wd   =  capture_wd << 4 ;
    capture_wd  |=  rx_train_sm & 0x0F ;

    capture_wd   =  capture_wd << 9 ;
    capture_wd  |=  tx_cu_data & 0x01FF ;

    capture_wd   =  capture_wd << 2 ;
    capture_wd  |=  rx_cu_pre & 0x03 ;

    capture_wd   =  capture_wd << 2 ;
    capture_wd  |=  rx_cu_main & 0x03 ;

    capture_wd   =  capture_wd << 2 ;
    capture_wd  |=  rx_cu_post & 0x03 ;

    capture_wd   =  capture_wd << 1 ;
    capture_wd  |=  rx_taps_equalized & 0x01 ;

    capture_wd   =  capture_wd << 1 ;
    capture_wd  |=  receiver_rdy & 0x01 ;

    //==============================================|===============================================
    return  capture_wd ;
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                display_t88_training_gser_activity_hdr
//################################################|#################################################
void      display_t88_training_gser_activity_hdr_lane(  uint ocx_lane_num )        // <_function_>
{
    const bdk_node_t  loc_node_id    =  bdk_numa_local();

    printf(">                                         Local Node-%d    OCX Lane-%02d \n", loc_node_id, ocx_lane_num );
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                display_training_sm_activity_hdr
//################################################|#################################################
/*                               
                                Node-0
--------------------------------------------------------------------
                                                    rx_trn    rx_trn
tx_trn  rx_trn  tx_trn   rx_trn  rx_trn   rx_trn     taps      rcv
  sm      sm    cu_data  cu_pre  cu_main  cu_post  equalized   rdy
------  ------  -------  ------  -------  -------  ---------  ------
  15      15     0x1FF      3       3        3         1         1

    
"> xxx @ xxxxxx.xxx  "
">                   "

 */
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void      display_t88_training_gser_activity_hdr(       void  )                 // <_function_>
{
    printf(">                     -------------------------------------------------------------------- \n");
    printf(">                                                                         rx_trn    rx_trn \n");
    printf(">                     tx_trn  rx_trn  tx_trn   rx_trn  rx_trn   rx_trn     taps       rcv  \n");
    printf("> Samp       msec       sm      sm    cu_data  cu_pre  cu_main  cu_post  equalized    rdy  \n");
    printf("> ----    ---------   ------  ------  -------  ------  -------  -------  ---------  ------ \n");

//    printf(">                       15      15     0x1FF      3       3        3         1         1   \n");

}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                display_t88_training_gser_activity
//################################################|#################################################
void      display_t88_training_gser_activity(           uint64_t  capture_wd  )   // <_function_>
{
    uint  tx_train_sm        =  ( capture_wd >> 21) & 0x0F ;
    uint  rx_train_sm        =  ( capture_wd >> 17) & 0x0F ;
    uint  tx_cu_data         =  ( capture_wd >>  8) & 0x01FF ;
    uint  rx_cu_pre          =  ( capture_wd >>  6) & 0x03 ;
    uint  rx_cu_main         =  ( capture_wd >>  4) & 0x03 ;
    uint  rx_cu_post         =  ( capture_wd >>  2) & 0x03 ;
    uint  rx_taps_equalized  =  ( capture_wd >>  1) & 0x01 ;
    uint  receiver_rdy       =  ( capture_wd      ) & 0x01 ;

    printf("   %2u      %2u     0x%03X      %u       %u        %u         %u         %u   \n", 
           tx_train_sm, rx_train_sm, tx_cu_data, rx_cu_pre, rx_cu_main, rx_cu_post, rx_taps_equalized, receiver_rdy
    );
}                                                    // <_function_end_>



//################################################|#################################################  // <_function_hdr_>
//                                   log_2x12_t88_links_coming_up
//################################################|#################################################
/*
 */
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int       log_2x12_t88_links_coming_up(                 void  )                     // <_function_>
{
    uint        link_num ;
    uint        link_cnt ;
    uint        starting_num_links_are_up  =  0 ;
    uint        num_links_are_up  =  0 ;

    uint64_t *  captured_lane_wds_arrays[ 24 ];
    uint64_t *  capture_timestamp_arrays[ 24 ];

    uint        num_captures_on_lane[ 24 ];
    uint        num_captures ;

    uint64_t    curr_clk_cnt_on_lane[ 24 ];

    uint        ocx_lane_num ;

    uint64_t    prev_curr_wd_on_lane[ 24 ];
    uint64_t    curr_wd_on_lane[ 24 ];

    uint64_t    prev_capture_wd ;
    uint64_t    capture_wd ;

    uint64_t    starting_clk_cnt ;
    uint64_t    ending_clk_cnt ;
    uint64_t    elapsed_clk_cnt ;
    uint64_t    curr_clk_cnt ;        // since the start of the test...
//    uint64_t    capture_timeout_clk_cnt ;
    uint        capture_num ;

    bool        did_time_out ;
//    bool        did_fill_arrays ;
    bool        all_links_are_up ;

    uint64_t    timestamp_usec ;
    uint64_t    timestamp_msec ;
    uint64_t    timestamp_clk_cnt ;

    uint        index ;

    bool        all_lanes_are_full  =  true ;

    int         exit_code  =  0 ;
    //     -1:  error
    //      0:  unspecified success
    //      1:  filled capture arrays
    //      2:  timed out
    //      3:  All links are UP


    //==============================================|===============================================
    const bdk_node_t  loc_node_id        =  bdk_numa_local();
    const uint        num_capture_slots  =  256 ;

    const uint64_t    clk_freq_mhz  =  bdk_clock_get_rate( loc_node_id, BDK_CLOCK_RCLK ) / 1000000 ;

    //                                             +--- sec
    //                                             |
    //                                             |  +--- msec
    //                                             |  |
    //                                             |  |  +--- usec
    //                                             |  |  |
    //                                             |  |  |  +--- nsec
    //                                             |  |  |  |
    const uint64_t    capture_timeout_clk_cycs  =  9000000000 ;  // at 1200 MHz:  0.8 nsec/cycle


    //==============================================|===============================================
    //                                 Initialize Variables & Arrays
    //
    for( ocx_lane_num = 0;  ocx_lane_num < 24;  ocx_lane_num ++ )
    {
        captured_lane_wds_arrays[ ocx_lane_num ]  =  (uint64_t *) calloc( num_capture_slots, sizeof( uint64_t ));
        capture_timestamp_arrays[ ocx_lane_num ]  =  (uint64_t *) calloc( num_capture_slots, sizeof( uint64_t ));

        num_captures_on_lane[     ocx_lane_num ]  =  0 ;
    }

    starting_clk_cnt         =  bdk_clock_get_count( BDK_CLOCK_RCLK );
//    capture_timeout_clk_cnt  =  starting_clk_cnt + capture_timeout_clk_cycs ;


    //==============================================|===============================================
    //         Count the Number of Links that are UP - out of two possible links:  0 & 2
    //
    starting_num_links_are_up  =  0 ;
    //
    for( link_cnt = 0;  link_cnt < 2;  link_cnt ++ )
    {
        link_num  =  2 * link_cnt ;
        if( oci_link_is_up( link_num ) )   starting_num_links_are_up ++ ;
    }

//    printf("> %d Links were UP at the start of the program! \n", starting_num_links_are_up );
//
//    if( starting_num_links_are_up >= 2 )
//    {
//        all_links_are_up  =  true ;
//        exit_code  =  -2 ;
//
//        printf("> \n");
//        printf("> *** Both Links are UP at the start of the program! *** \n");
//        printf("> \n");
//    }


    //==============================================|===============================================
    //                      Read the Initial Values of the CSRs - On all Lanes
    //
    for( ocx_lane_num = 0;  ocx_lane_num < 24;  ocx_lane_num ++ )
    {
        curr_clk_cnt   =  bdk_clock_get_count( BDK_CLOCK_RCLK )  -  starting_clk_cnt ;
        curr_clk_cnt_on_lane[ ocx_lane_num ]  =  curr_clk_cnt ;

        capture_wd  =  capture_local_t88_training_gser_activity(  ocx_lane_num  );
        curr_wd_on_lane[ ocx_lane_num ]  =  capture_wd ;

        // Make sure the first reading is captured:
        prev_curr_wd_on_lane[ ocx_lane_num ]  =  ~ capture_wd ;
    }


    //==============================================|===============================================
    //                                     Capture While-Loop
    //
    all_lanes_are_full  =  true ;
//    did_fill_arrays     =  false ;
    did_time_out        =  false ;
    all_links_are_up    =  false ;

    while( 1 )
    {
        for( ocx_lane_num = 0;  ocx_lane_num < 24;  ocx_lane_num ++ )
        {
            //------------------------------------------|-------------------------------------------
            //                             Is the capture array full?
            //
            num_captures  =  num_captures_on_lane[ ocx_lane_num ];

            if( num_captures >= num_capture_slots )
            {
                // Skip this lane - it's already full!
                continue ;
            }
            else
            {
                // At least this lane is NOT full!
                all_lanes_are_full  =  false ;
            }

            //------------------------------------------|-------------------------------------------
            //                          Has There Been a Change in the CSRs?
            //
            capture_wd       =  curr_wd_on_lane[      ocx_lane_num ];
            prev_capture_wd  =  prev_curr_wd_on_lane[ ocx_lane_num ];
            //
            if( capture_wd != prev_capture_wd )
            {
                // Record the new reading in the capture memory:
                captured_lane_wds_arrays[ ocx_lane_num ][ num_captures ]  =  capture_wd ;
                capture_timestamp_arrays[ ocx_lane_num ][ num_captures ]  =  curr_clk_cnt_on_lane[ ocx_lane_num ] ;
                num_captures_on_lane[     ocx_lane_num ] ++ ;

                prev_curr_wd_on_lane[ ocx_lane_num ]  =  capture_wd ;
            }
        } // ocx_lane_num loop


        //------------------------------------------|-----------------------------------------------
        //                                  Is all the Capture Memory Full?
        //
        if( all_lanes_are_full )
        {
//            did_fill_arrays  =  false ;
            exit_code        =  1 ;
            break ;
        }

        //------------------------------------------|-----------------------------------------------
        //                                Did Capture Time Out ?
        //
        if( curr_clk_cnt >= capture_timeout_clk_cycs )
        {
            did_time_out  =  true ;
            exit_code     =  2 ;
            break ;
        }

        //------------------------------------------|-----------------------------------------------
        //         Count the Number of Links that are UP - out of two possible links:  0 & 2
        //
        num_links_are_up  =  0 ;
        //
        for( link_cnt = 0;  link_cnt < 2;  link_cnt ++ )
        {
            link_num  =  2 * link_cnt ;
            if( oci_link_is_up( link_num ) )   num_links_are_up ++ ;
        }

        if( num_links_are_up >= 2 )
        {
            all_links_are_up  =  true ;
            exit_code  =  3 ;
            break ;
        }

        //------------------------------------------|-----------------------------------------------
        //                              Get the Next CSR Values - for each lane
        //
        for( ocx_lane_num = 0;  ocx_lane_num < 24;  ocx_lane_num ++ )
        {
            curr_clk_cnt   =  bdk_clock_get_count( BDK_CLOCK_RCLK )  -  starting_clk_cnt ;
            curr_clk_cnt_on_lane[ ocx_lane_num ]  =  curr_clk_cnt ;
    
            capture_wd  =  capture_local_t88_training_gser_activity(  ocx_lane_num  );
            curr_wd_on_lane[ ocx_lane_num ]  =  capture_wd ;
        }

    } // while

    //==============================================|===============================================
    //                  Capture the last reading - if there is room in the arrays
    //
    if( did_time_out  ||  all_links_are_up )
    {
        for( ocx_lane_num = 0;  ocx_lane_num < 24;  ocx_lane_num ++ )
        {
            capture_wd    =  curr_wd_on_lane[      ocx_lane_num ];
            curr_clk_cnt  =  curr_clk_cnt_on_lane[ ocx_lane_num ];
            num_captures  =  num_captures_on_lane[ ocx_lane_num ];

            captured_lane_wds_arrays[ ocx_lane_num ][ num_captures ]  =  capture_wd ;
            capture_timestamp_arrays[ ocx_lane_num ][ num_captures ]  =  curr_clk_cnt ;
            num_captures_on_lane[     ocx_lane_num ] ++ ;
        }
    }


    //==============================================|===============================================
    //                                  Display the Run Information
    //==============================================|===============================================
    printf("> \n");
    printf(">========================================================================================= \n");
    printf(">                               log_2x12_t88_links_coming_up \n");
    printf("> \n");

    //----------------------------------------------------------------------------------------------
    if(      exit_code ==  1 )    printf("> Capture ended when:  Filled the capture memory! \n");
    else if( exit_code ==  2 )    printf("> Capture ended when:  The Capture timed out! \n");
    else if( exit_code ==  3 )    printf("> Capture ended when:  the links are UP! \n");
//    else if( exit_code == -2 )    printf("> Both links are UP at the start of the program! \n");
    else                          printf("> Capture ended when:  Unknown reason for stopping!  exit_code = %d \n", exit_code );
    printf("> \n");

    //----------------------------------------------------------------------------------------------
    printf("> Core Clock Frequency:   %lu MHz \n", clk_freq_mhz );
    printf("> \n");

    //----------------------------------------------------------------------------------------------
    timestamp_usec   =  convert_clk_cnt_to_usec( starting_clk_cnt, clk_freq_mhz );
    timestamp_msec   =  timestamp_usec / 1000 ;

    printf("> Starting time:  %6lu.%03lu msec - since the end of reset. \n", timestamp_msec, get_3_ls_decimal_digits( timestamp_usec )  );

    //----------------------------------------------------------------------------------------------
    ending_clk_cnt   =  bdk_clock_get_count( BDK_CLOCK_RCLK );
    elapsed_clk_cnt  =  ending_clk_cnt - starting_clk_cnt ;

    timestamp_usec   =  convert_clk_cnt_to_usec( elapsed_clk_cnt, clk_freq_mhz );
    timestamp_msec   =  timestamp_usec / 1000 ;

    printf("> Elapsed time:   %6lu.%03lu msec - since start of this test. \n", timestamp_msec, get_3_ls_decimal_digits( timestamp_usec )  );
    printf("> \n");

    printf("> %d Links were UP at the start of the program! \n", starting_num_links_are_up );
    printf("> \n");


    //==============================================|===============================================
    //         Count the Number of Links that are UP - out of two possible links:  0 & 2
    //
    num_links_are_up  =  0 ;
    //
    for( link_cnt = 0;  link_cnt < 2;  link_cnt ++ )
    {
        link_num  =  2 * link_cnt ;
        if( oci_link_is_up( link_num ) )   num_links_are_up ++ ;
    }

    printf("> %d  Links are UP after capture! \n", num_links_are_up );
    //
    for( link_cnt = 0;  link_cnt < 2;  link_cnt ++ )
    {
        link_num  =  2 * link_cnt ;
        if( oci_link_is_up( link_num ) )   printf(">     Link-%d  is UP. \n", link_num );
        else                                           printf("> *** Link-%d  is DWN. \n", link_num );
    }
    printf("> \n");


    //==============================================|===============================================
    //                               Find the Lanes Stuck in Training

    uint  num_stuck_lanes ;
    int   stuck_ocx_lane_nums_array[ 24 ];

    bool  ocx_lane_is_stuck_array[ 24 ];

    printf("> Checking for Lanes stuck in Training... \n");
    num_stuck_lanes  =  find_local_t88_lanes_stuck_in_training(  stuck_ocx_lane_nums_array, ocx_lane_is_stuck_array  );

    printf("> ... Found  %d  Lanes stuck in Training. \n", num_stuck_lanes );
    printf("> \n");


    //==============================================|===============================================
    //                 Display the Captured Data for the Lane(s) Stuck in Training
    //
    for( ocx_lane_num = 0;  ocx_lane_num < 24;  ocx_lane_num ++ )
    {
        if( ocx_lane_is_stuck_array[ ocx_lane_num ] == true )
        {
            printf("> \n");
            printf("> *** The following lane is stuck:  Lane-%02d \n", ocx_lane_num );
        }

        // Display the header:
        display_t88_training_gser_activity_hdr_lane(  ocx_lane_num  );
        display_t88_training_gser_activity_hdr();
        fflush( stdout );
    
        num_captures  =  num_captures_on_lane[ ocx_lane_num ];
        //
        for( index = 0;  index < num_captures;  index ++ )
        {
            capture_num  =  index + 1 ;
            capture_wd         =  captured_lane_wds_arrays[ ocx_lane_num ][ index ];
            timestamp_clk_cnt  =  capture_timestamp_arrays[ ocx_lane_num ][ index ];
    
            timestamp_usec  =  convert_clk_cnt_to_usec( timestamp_clk_cnt, clk_freq_mhz );
            timestamp_msec  =  timestamp_usec / 1000 ;
    
            //     "> xxx @ xxxxxx.xxx  "
            printf("> %4d @ %6lu.%03lu  ", capture_num, timestamp_msec, get_3_ls_decimal_digits( timestamp_usec ) );  // start the listing line
    
            display_t88_training_gser_activity(  capture_wd  );
            fflush( stdout );
      
            if( capture_num % 50 == 0 )
            {
                // Display the header again:
                printf("> \n");
                display_t88_training_gser_activity_hdr_lane(  ocx_lane_num  );
                display_t88_training_gser_activity_hdr();
                fflush( stdout );
            }

        } // num_captures  for-loop

        printf("> \n");
        fflush( stdout );

    } // ocx_lane_num  for-loop.


    //==============================================|===============================================
    //                                          Finish UP
    //
    for( ocx_lane_num = 0;  ocx_lane_num < 24;  ocx_lane_num ++ )
    {
        free( captured_lane_wds_arrays[ ocx_lane_num ] );
        free( capture_timestamp_arrays[ ocx_lane_num ] );
    }


    //==============================================|===============================================
    return  exit_code ;

} // log_2x12_t88_links_coming_up                    // <_function_end_>



//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  // <_function_hdr_>
//################################################|#################################################
//                                       run_boot_stub_ccpi
//################################################|#################################################
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/*

    This program runs in the BDK boot stub on PP-0 of the master node of a dual-node t88
    system.  It runs soon after the end of reset, before the majority of the system
    initialization software has run; this program will do soft resets of the system to fix
    lanes that hang during 10G training.  The other node is presumed to be in
    "remote-boot" mode, with its PPs are held in reset.  This program only supports system
    boots where the two nodes are powered up in close time proximity (i.e., < ~0.5 second
    apart).

    The system's CCPI configuration is determined from the CCPI QLM assignments as found
    in the OCX_LNK(0..2)_CFG csr.  The program assumes that the CCPI links are fully
    configured.  If the OCI straps are set for configuration 0, then two 12-lane links are
    connected between the two t88s (Link-0 and Link-2).  If the OCI straps are set for
    configuration 3, then two 8-lane links are connected between the two t88s (Link-0 and
    Link-2) (Link-1 has QLMs, but they are not connected).  Strap configuration 1 is not
    supported.

    The program waits a while for both CCPI links to come up.  If both links are not up
    when the timeout interval expires, the program will notify the user and proceed
    with the CCPI link that is up.  If no links are up, the program will exit.  

    If a link that is configured for 12 lanes is only wired up with 8 lanes, the program
    will attempt to bring up the last four lanes, but will eventually give up (a
    programmed limit to the number of retrys).

    If the CCPI links are doing training (e.g., 10G links), then if either of the links
    has lane(s) that are stuck in training when the program starts up, the program will
    soft reset both nodes until all the lanes come up.  The program assumes that lanes
    that hung in training are actually trained approriately, and can be used as is without
    further training activity.  The program displays the CCPI SerDes Rx figures-of-merit
    for the link(s), allowing the user to confirm the quality of the tuning on all the
    lanes.  It also displays any CCPI link CRC32 errors.

    This program checks the state of the links, as reported in the OCX_COM_LINK(0..2)_CTL
    csrs, and it also checks the state of the OCX reliable transport layer (credits & OXC
    block sequence numbers).  Problems in these areas trigger the program to do soft
    resets of both nodes.


    Assumptions:
        * 2 links to one other node
        * All configured lanes of each node are wired up, and should come up.

        * The program can deal with two 12-lane links or two 8-lane links when checking
        * and fixing.

        * The program assumes that once both links are UP and OCX credits are available,
          the OCI facility is operational for remote CSR access, even if there are fewer
          lanes operating than there should be.


    Link States:
        Inactive:     Has zero QLM(s) assigned to the link.
        Active:       Has one or more QLM(s) assigned to the link.
        Up:           Has Interlaken 67-bit word lock, metaframes, good CRC32s.
        Operational:  Will support OCI traffic on all VCs.

 */
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int       run_boot_stub_ccpi(  void  )                     // <_function_>
{
    ocx_global_info_t  ocx_global_info ;

    uint64_t   starting_clk_cnt ;
    uint64_t   links_up_clk_cnt ;
    uint64_t   timestamp_usec ;
    uint64_t   timestamp_msec ;

    uint       num_active_links ;

    uint       link_num ;
    uint       num_links_up ;
//    uint       num_operational_links ;
    uint       index ;

    uint       waits_cnt ;
    uint       ocx_lane_num ;
    uint       num_stuck_lanes ;
    int        stuck_ocx_lane_nums_array[ 24 ];
    bool       ocx_lane_is_stuck_array[   24 ];
    uint       stuck_lane_index ;
               
    int        qlm_num ;
    int        refclk_freq_hz ;

    int        routing_node_id ;


//    bool       timed_out_waiting_for_links_up  =  false ;
    uint       num_lanes_stuck_in_training   =  0 ;
    uint       num_crc32_errors  =  0 ;
//    bool       found_link_lane_qlm_errors  =  false ;
    bool       found_ocx_state_error  =  false ;
    bool       found_ocx_credit_error  =  false ;

    bool       this_is_the_master_node  =  false ;

//    bool       found_error  =  false ;
    bool       need_to_reboot_system      =  false ;
//    bool       need_to_reset_the_system   =  false ;

    uint         soft_reset_count ;
    const uint   soft_reset_count_gser   =  8 ;

    const uint   soft_reset_count_limit  =  8 ;
//    const uint   soft_reset_count_limit  =  5 ;
//    const uint   soft_reset_count_limit  =  1 ;

    const uint64_t  resets_separation_usec  =  100 ;


    //==============================================================================================
    const bdk_node_t   loc_node_id   =  bdk_numa_local();
    const uint64_t     clk_freq_mhz  =  bdk_clock_get_rate( loc_node_id, BDK_CLOCK_RCLK ) / 1000000 ;


    //----------------------------------------------------------------------------------------------
    //                  Abort Execution if This Module is Disabled

#ifdef DISABLE_CCPI_TRN_WORKAROUND
    return 0 ;
#endif


    //----------------------------------------------------------------------------------------------
    printf(" \n");
    printf("======================== CCPI ======================== \n");
    fflush( stdout );

    starting_clk_cnt  =  bdk_clock_get_count( BDK_CLOCK_RCLK );

    timestamp_usec    =  convert_clk_cnt_to_usec( starting_clk_cnt, clk_freq_mhz );
    timestamp_msec    =  timestamp_usec / 1000 ;

    printf(" Started at:  %6lu.%03lu msec - since the end of reset. \n", timestamp_msec, get_3_ls_decimal_digits( timestamp_usec )  );
    printf(" Core Clock Frequency:   %lu MHz \n", clk_freq_mhz );

    qlm_num  =  8 ;    // the first CCPI QLM.
    refclk_freq_hz  =  bdk_qlm_measure_clock( loc_node_id, qlm_num );
    printf(" CCPI Ref Clock Freq:  %9d Hz \n", refclk_freq_hz );


    // Master Node?
    if( bdk_numa_master() == bdk_numa_local() )
    {
        this_is_the_master_node  =  true ;
        printf(" This is the master node:  Node-%d \n", loc_node_id );
    }
    else
    {
        this_is_the_master_node  =  false ;
        printf(" This is the slave node:  Node-%d \n", loc_node_id );
    }
    printf(" \n");
    fflush( stdout );


    //------------------------------------------------------------------------------------
    //                                 Cause of Booting
    //
    display_reason_for_booting();    // This state is persistent across soft resets
    printf(" \n");
    fflush( stdout );

    if( reset_reason_was_soft_reset()  )
    {
        // This was a soft-reset boot, check the number of soft-resets so far...
        //
        soft_reset_count  =  read_local_gser_scratch_reg_16b(  soft_reset_count_gser  );

        if( soft_reset_count >= soft_reset_count_limit )
        {
            // It's not working!  Bail out!
            //
            printf(" \n");
            printf(" *** Too many soft resets!  Aborting... \n");
            printf(" \n");
            fflush( stdout );
            return  -1 ;
        }
    }
    else
    {
        // Not a soft reset:

        // Clear the GSER soft reset count.
        soft_reset_count  =  0 ;
        write_local_gser_scratch_reg_16b(  soft_reset_count_gser, soft_reset_count  );
    }

    clear_reasons_for_booting();


    //------------------------------------------------------------------------------------
    printf(" Disabling the OCX bad_lane timeouts... \n");

    disable_all_local_ocx_bad_lane_timeouts();
    printf(" \n");


    //-----------------------------------------|------------------------------------------
    //                            Determine the OCI Configuration
    //
    initialize_ocx_global_info(  & ocx_global_info  );
    num_active_links  =  configure_global_info_for_oci_qlms(  & ocx_global_info  );


    //-----------------------------------------|------------------------------------------
    display_oci_config_summary(  & ocx_global_info  );


    //-----------------------------------------|------------------------------------------
    //                    Wait for Links to come UP - At Interlaken Layer
    //
    waits_cnt  =  0 ;

    num_links_up      =  find_number_of_up_links(  & ocx_global_info  );
    links_up_clk_cnt  =  bdk_clock_get_count( BDK_CLOCK_RCLK );
    //
    while( num_links_up < num_active_links )
    {
        waits_cnt ++ ;
        if( waits_cnt > 500 )
        {
            // Timeout
//            timed_out_waiting_for_links_up  =  true ;

            printf(" *** \n");
            printf(" *** Timed-out waiting for all links to come UP! \n");
            printf(" ***     Only  %d links are UP  out of  %d active links! \n", num_links_up, num_active_links );
            printf(" *** \n");

            break ;
        }
        bdk_wait_usec( 10000 );    // 10 msec

        // Check again how many links are UP:
        num_links_up      =  find_number_of_up_links(  & ocx_global_info  );
        links_up_clk_cnt  =  bdk_clock_get_count( BDK_CLOCK_RCLK );

    } // while

    timestamp_usec    =  convert_clk_cnt_to_usec( links_up_clk_cnt, clk_freq_mhz );
    timestamp_msec    =  timestamp_usec / 1000 ;
    //
    printf(" %u Links are UP (Interlaken layer) at:  %lu.%03lu msec - since the end of reset. \n", num_links_up, timestamp_msec, get_3_ls_decimal_digits( timestamp_usec )  );
    printf(" \n");

//    num_links_up  =  update_globals_with_link_state(  & ocx_global_info  );
//    display_operational_link_status(  & ocx_global_info  );


    // Update and Display  Global Info with latest state:
    num_links_up  =  update_globals_with_link_state(  & ocx_global_info  );

    display_operational_link_status(  & ocx_global_info  );


    //-----------------------------------------|------------------------------------------
    //                                 No links are up!
    //
    if( num_links_up == 0 )
    {
        printf(" \n");
        printf(" *** No OCI links came UP  (Interlaken)  OCI is NOT functional *** \n");
        printf(" \n");
        fflush( stdout );

        return  -1 ;
    }


    //-----------------------------------------|------------------------------------------
    //                        Find Any Stuck Lanes - if doing training
    //
    if( am_doing_link_training() )
    {
        num_stuck_lanes  =  find_local_t88_lanes_stuck_in_training(  stuck_ocx_lane_nums_array, ocx_lane_is_stuck_array  );
        //
        if( num_stuck_lanes > 0 )
        {
            printf(" *** OCI-Lane(s) FAILING to complete GSER link training: *** \n");
            //
            for( stuck_lane_index = 0;  stuck_lane_index < num_stuck_lanes;  stuck_lane_index ++ )
            {
                ocx_lane_num  =  stuck_ocx_lane_nums_array[ stuck_lane_index ];
                printf("     *** Lane-%02d \n", ocx_lane_num );

                num_lanes_stuck_in_training ++ ;
//                need_to_reboot_system  =  true ;
            }
        }
        else   printf(" All OCI lanes have trained successfully! \n");
    }
    else   printf(" (The OCI links are not doing link training.) \n");

    printf(" \n");
    fflush( stdout );


    //-----------------------------------------|------------------------------------------
    //                    Display the GSER Rx Equalization figure-of-merit
    //
    num_active_links  =  ocx_global_info.num_active_links ;

    link_num  =  0 ;    
    display_gser_rx_equal_fig_of_merits_hdr(  link_num,  & ocx_global_info );
    fflush( stdout );

    for( index = 0;  index < num_active_links;  index ++ )
    {
        link_num  =  ocx_global_info.active_links_array[ index ];

        display_local_gser_rx_equal_figure_of_merits(  link_num,  & ocx_global_info );
        fflush( stdout );
    }
    printf(" \n");
    fflush( stdout );


    //-----------------------------------------|------------------------------------------
    //                         Check CRC32 Errors of the Active Links
    //
    num_crc32_errors  =  read_crc32_errors_across_all_active_t88_links(  & ocx_global_info  );
        
    if( num_crc32_errors > 0 )
    {
        printf(" *** Found CRC32 errors on the active links:  %u  (Note:  error counts are cleared upon reading.) \n", num_crc32_errors );
    }
    else
    {
        printf(" Found no CRC32 errors on the active links! \n");
    }
    printf(" \n");
    fflush( stdout );

    // Need to reboot because of this ???   Warning because of this???


    //-----------------------------------------|------------------------------------------
    //               Check Local Link/Lane/QLM OCX Status of the Active Links
    //
//    found_link_lane_qlm_errors  =  check_local_t88_link_lane_qlm_status_of_active_links(  & ocx_global_info  );
    printf(" \n");

    // Need to reboot because of this ???


    //-----------------------------------------|------------------------------------------
    //                          Check OCX State of the Active Links
    //
    found_ocx_state_error  =  check_local_t88_ocx_state_of_active_links(  & ocx_global_info  );
    printf(" \n");

//    if( found_ocx_state_error )   need_to_reboot_system  =  true ;


    //-----------------------------------------|------------------------------------------
    //                          Check OCI VC Credits of the Active Links
    //
    found_ocx_credit_error  =  check_local_vc_credits_on_active_links(  & ocx_global_info  );
    printf(" \n");

//    if( found_ocx_credit_error )   need_to_reboot_system  =  true ;


    //-----------------------------------------|------------------------------------------
    //                  Decide if  Soft Resetting the System is Necessary
    //
    need_to_reboot_system  =  false ;

    if( num_links_up < num_active_links )   need_to_reboot_system  =  true ;
    if( num_lanes_stuck_in_training > 0 )   need_to_reboot_system  =  true ;
    if( found_ocx_state_error )             need_to_reboot_system  =  true ;
    if( found_ocx_credit_error )            need_to_reboot_system  =  true ;


    //-----------------------------------------|------------------------------------------
    //       Notify Operator of the Need to Reboot and of Warnings - if Master Node
    //
    if( this_is_the_master_node )
    {
        if( need_to_reboot_system )
        {
            // Increment the soft-reset count in the GSER scratch reg.
            soft_reset_count  =  read_local_gser_scratch_reg_16b(  soft_reset_count_gser  );
            soft_reset_count ++ ;
            write_local_gser_scratch_reg_16b(  soft_reset_count_gser, soft_reset_count  );
    
            printf(" ***                                          *** \n");
            printf(" *** Rebooting the system!   Reboot count:  %u *** \n", soft_reset_count );
            printf(" ***                                          *** \n");
            printf(" \n");
            fflush( stdout );
            bdk_wait_usec( 50000 );    // give the printing time to happen...
    
            // Reset the Remote node:
            routing_node_id  =  find_routing_node_id_of_lowest_num_link(  & ocx_global_info  );
            soft_reset_the_far_node(  routing_node_id  );
    
            // Stagger the resets:
            bdk_wait_usec( resets_separation_usec );
    
            // Reset the Local node:
            soft_reset_the_local_node();
    
            bdk_wait_usec( 10000 );    // wait here until the local reset hits...
        }
        else
        {
            printf(" The system is good to GO! \n");
            printf(" \n");
            fflush( stdout );
    
            // Make sure the GSER Scratch count is zero:
            soft_reset_count  =  0 ;
            write_local_gser_scratch_reg_16b(  soft_reset_count_gser, soft_reset_count  );

        } // if( need_to_reboot_system )
    } // if( this_is_the_master_node )

    else
    {
        // This is the slave node

        // Make sure the GSER Scratch count is zero:
        soft_reset_count  =  0 ;
        write_local_gser_scratch_reg_16b(  soft_reset_count_gser, soft_reset_count  );
    }



    //==============================================|===============================================
    //                                      End of CCPI Code
    //
    printf("^^^^^^^^^^^^^^^^^^^^^^^^ CCPI ^^^^^^^^^^^^^^^^^^^^^^^^ \n");
    printf(" \n");
    fflush( stdout );

    bdk_wait_usec( 50000 );    // give the printing time to happen...


    //-----------------------------------------|------------------------------------------
//    if( num_stuck_lanes > 0 )

//    if( num_links_up < num_active_links )
//    {
//        //-----------------------------------------|------------------------------------------
//        //                         Initialize DTX on All 24 OCX lanes:
//        //
//        for( ocx_lane_num = 0;  ocx_lane_num < 24;  ocx_lane_num ++ )
//        {
//            gser_num       =  GSER_Num_For_OCX_Lane[      ocx_lane_num ];
//            gser_lane_num  =  GSER_Lane_Num_For_OCX_Lane[ ocx_lane_num ];
//            init_local_oci_gser_dtx(  gser_num,  gser_lane_num );
//        }
//    
//        //-----------------------------------------|------------------------------------------
//        //                              Log the Links Coming UP
//        //
//        exit_code  =  log_2x12_t88_links_coming_up();
//    }


    //==============================================================================================
    return  0 ;

} // run_boot_stub_ccpi                              // <_function_end_>



//################################################|#################################################
//                                   oci-for-t88-bdk-functions.c
//################################################|#################################################
