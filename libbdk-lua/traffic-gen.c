#include <bdk.h>
#include <stdbool.h>
#include <stdio.h>
#include "traffic-gen.i"

typedef enum {
    PACKET_FREE,
    PACKET_DONT_FREE,
    PACKET_DONT_FREE_WQE
} packet_free_t;


static const int ETHERNET_CRC = 4;       /* Gigabit ethernet CRC in bytes */
static const int BRIDGE_OFF = 40;
static const int MAC_ADDR_LEN = 6;
static const int IP_ADDR_LEN = 4;
static const int CYCLE_SHIFT = 12;
static const int PIP_IP_OFFSET = 4;       /* Number of dwords to reserve before IP packets */
  /* Define the output packet contents following IEEE 802.3ae Clause 45
   * definition for the continous jitter test pattern (CJPAT). Since the OCTEON
   * automatically generates some portions of the specified pattern, the packet
   * does not include the first 8 bytes and the last 12 bytes of the pattern.
   */
static const char CJPAT_Packet[1508] = {
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

static trafficgen_port_set_t tg_all_set;

static trafficgen_port_info_t *tg_get_pinfo(int ipd_port)
{
    static trafficgen_port_info_t *pinfo[BDK_PIP_NUM_INPUT_PORTS];
    if (ipd_port < BDK_PIP_NUM_INPUT_PORTS)
    {
        if (pinfo[ipd_port] == NULL)
            pinfo[ipd_port] = malloc(sizeof(trafficgen_port_info_t));
        return pinfo[ipd_port];
    }
    else
        return NULL;
}

static void tg_init_port(trafficgen_port_info_t *pinfo)
{
    int interface = bdk_helper_get_interface_num(pinfo->port);
    int index = bdk_helper_get_interface_index_num(pinfo->port);

    /* Set Jabber and max frame length */
    switch (pinfo->setup.imode)
    {
        case BDK_HELPER_INTERFACE_MODE_SGMII:
        case BDK_HELPER_INTERFACE_MODE_XAUI:
            BDK_CSR_WRITE(BDK_GMXX_RXX_JABBER(index,interface), 65535);
            if (index == 0)
                BDK_CSR_MODIFY(pip_frm_len_chkx, BDK_PIP_FRM_LEN_CHKX(interface),
                    pip_frm_len_chkx.s.minlen = 64;
                    pip_frm_len_chkx.s.maxlen = -1);
            break;

        default:
            break;
    }

    /* Enable storing short packets only in the WQE */
    BDK_CSR_MODIFY(port_cfg, BDK_PIP_PRT_CFGX(pinfo->port),
        port_cfg.s.dyn_rs = 1);

    /* Only the first two interfaces and four ports are used for
        backpressure. Interfaces with more than 4 ports, like SPI4, use
        only port 0 */
    if ((interface < 2) && (index < 4))
    {
        /* Set if incomming backpressure is respected by PKO */
        BDK_CSR_MODIFY(frm_ctl, BDK_GMXX_RXX_FRM_CTL(index, interface),
            frm_ctl.s.ctl_bck = pinfo->setup.respect_backpressure);
    }

    switch (pinfo->setup.imode)
    {
        case BDK_HELPER_INTERFACE_MODE_XAUI:
            /* HiGig headers always start with 0xfb */
            pinfo->setup.higig_header.dw0.s.start = 0xfb;
            break;

        case BDK_HELPER_INTERFACE_MODE_SRIO:
            pinfo->setup.srio.s.prio = 0;
            pinfo->setup.srio.s.tt = 1;
            pinfo->setup.srio.s.sis = 0;
            pinfo->setup.srio.s.ssize = 0xe;
            pinfo->setup.srio.s.did = 0xffff;
            pinfo->setup.srio.s.xmbox = 0;
            pinfo->setup.srio.s.mbox = index&3;
            pinfo->setup.srio.s.letter = 0;
            pinfo->setup.srio.s.lns = 0;
            pinfo->setup.srio.s.intr = 0;
            break;
        default:
            break;
    }
}

/**
 */
static void tg_init(void)
{
    /* Set the number of packet and WQE entries to be 16 less than the
        number of SSO entries. This way we never spill to ram */
    int num_packet_buffers = bdk_sso_get_num_entries() - 16;
    bdk_fpa_enable();
    bdk_fpa_fill_pool(BDK_FPA_PACKET_POOL, num_packet_buffers);
    bdk_fpa_fill_pool(BDK_FPA_WQE_POOL, num_packet_buffers);
    bdk_fpa_fill_pool(BDK_FPA_OUTPUT_BUFFER_POOL, BDK_PKO_MAX_OUTPUT_QUEUES*2);

    if (bdk_helper_interface_get_mode(4) == BDK_HELPER_INTERFACE_MODE_SRIO)
        bdk_srio_initialize(0, 0);
    if (bdk_helper_interface_get_mode(5) == BDK_HELPER_INTERFACE_MODE_SRIO)
        bdk_srio_initialize(1, 0);

    if (bdk_helper_initialize_packet_io_global())
        printf("bdk_helper_initialize_packet_io_global() failed\n");

    /* Enable RED so we drop if the RX path can't keep up */
    if (!bdk_is_simulation())
        bdk_helper_setup_red(num_packet_buffers/4, num_packet_buffers/8);

    BDK_CSR_WRITE(BDK_PIP_IP_OFFSET, PIP_IP_OFFSET);

    /* Change the IPD buffering mode to buffer all packets into L2. This
        yields better performance with high speed interface at the expense
        of our code/data getting flushed from L2. Luckily traffic-gen
        doesn't have much code or data in the fastpath */
    bdk_ipd_ctl_status_t ipd_ctl_reg;
    ipd_ctl_reg.u64 = BDK_CSR_READ(BDK_IPD_CTL_STATUS);
    ipd_ctl_reg.s.opc_mode = BDK_IPD_OPC_MODE_STF;
    BDK_CSR_WRITE(BDK_IPD_CTL_STATUS, ipd_ctl_reg.u64);

    int count = 0;
    int num_interfaces = bdk_helper_get_number_of_interfaces();
    for (int interface=0; interface < num_interfaces; interface++)
    {
        bdk_helper_interface_mode_t imode = bdk_helper_interface_get_mode(interface);
        int num_ports = bdk_helper_ports_on_interface(interface);
        for (int port=0; port<num_ports; port++)
        {
            int ipd_port = bdk_helper_get_ipd_port(interface, port);
            trafficgen_port_info_t *pinfo = tg_get_pinfo(ipd_port);
            if (pinfo)
            {
                memset(pinfo, 0, sizeof(*pinfo));
                pinfo->port = ipd_port;
                pinfo->setup.imode = imode;
                tg_init_port(pinfo);
                tg_all_set.list[count++] = pinfo;
            }
        }
    }

    tg_all_set.list[count] = NULL;
    trafficgen_do_reset(&tg_all_set);
}


/**
 *
 * @param pinfo
 *
 * @return
 */
static int get_size_wire_overhead(const trafficgen_port_info_t *pinfo)
{
    if (pinfo->setup.higig)
        return 8 /*INTERFRAME_GAP*/ + pinfo->setup.higig + ETHERNET_CRC;
    else if (pinfo->setup.srio.u64)
        return 0;
    else
        return 12 /*INTERFRAME_GAP*/ + 8 /*MAC_PREAMBLE*/ + ETHERNET_CRC;
}

/**
 *
 * @param pinfo
 *
 * @return
 */
static int get_size_pre_l2(const trafficgen_port_info_t *pinfo)
{
    if (pinfo->setup.srio.u64)
    {
        /* TX needs to add SRIO header */
        return sizeof(pinfo->setup.srio);
    }
    else
    {
        /* The preamble is created by hardware, so the length is zero for SW. In
            the higig case, the higig header replaces the preamble and we need
            to include it */
        return pinfo->setup.higig;
    }
}

/**
 *
 * @param pinfo
 *
 * @return
 */
static int get_size_l2(const trafficgen_port_info_t *pinfo)
{
    /* L2 header is two MAC addresses, optional VLAN stuff, and a L2 size/type */
    return MAC_ADDR_LEN*2 + pinfo->setup.vlan_size + 2;
}

/**
 *
 * @param pinfo
 *
 * @return
 */
static int get_size_ip_header(const trafficgen_port_info_t *pinfo)
{
    /* We don't support options, so the size of the IP header is fixed for
        IPv4 or IPv6 */
    switch (pinfo->setup.output_packet_type)
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

/**
 *
 * @param pinfo
 *
 * @return
 */
static int get_size_payload(const trafficgen_port_info_t *pinfo)
{
    /* The payload area is whatever is left after the previous headers. Note
        that this does not include any UDP or TCP header */
    return pinfo->setup.output_packet_size - get_size_ip_header(pinfo) - get_size_l2(pinfo);
}

/**
 *
 * @param pinfo
 *
 * @return
 */
static int get_end_pre_l2(const trafficgen_port_info_t *pinfo)
{
    return get_size_pre_l2(pinfo);
}

/**
 *
 * @param pinfo
 *
 * @return
 */
static int get_end_l2(const trafficgen_port_info_t *pinfo)
{
    return get_end_pre_l2(pinfo) + get_size_l2(pinfo);
}

/**
 *
 * @param pinfo
 *
 * @return
 */
static int get_end_ip_header(const trafficgen_port_info_t *pinfo)
{
    return get_end_l2(pinfo) + get_size_ip_header(pinfo);
}

/**
 *
 * @param pinfo
 *
 * @return
 */
static int get_end_payload(const trafficgen_port_info_t *pinfo)
{
    return get_end_ip_header(pinfo) + get_size_payload(pinfo);
}

/**
 * Update the packet cycle gap for the current tx percentage
 *
 * @param port
 */
static void update_cycle_gap(trafficgen_port_info_t *pinfo)
{
    uint64_t packet_rate = pinfo->setup.output_percent_x1000 * 1250 /
        (pinfo->setup.output_packet_size + get_size_wire_overhead(pinfo));
    if (packet_rate)
        pinfo->setup.output_cycle_gap = (bdk_clock_get_rate(BDK_CLOCK_CORE) << CYCLE_SHIFT) / packet_rate;
    else
        pinfo->setup.output_cycle_gap = (bdk_clock_get_rate(BDK_CLOCK_CORE) << CYCLE_SHIFT);
}

/**
 *
 * @param index
 *
 * @return
 */
trafficgen_port_info_t *trafficgen_port_get(int index)
{
    if (tg_all_set.list[0] == NULL)
        tg_init();
    return tg_all_set.list[index];
}

/**
 *
 * @param set
 * @param pinfo
 */
void trafficgen_port_add(trafficgen_port_set_t *set, trafficgen_port_info_t *pinfo)
{
    int i;
    int max = sizeof(set->list) / sizeof(set->list[0]);
    for (i=0; i<max; i++)
    {
        if (set->list[i] == pinfo)
            break;
        else if (set->list[i] == NULL)
        {
            set->list[i] = pinfo;
            break;
        }
    }
}

/**
 *
 * @param range
 *
 * @return
 */
int trafficgen_do_clear(const trafficgen_port_set_t *range)
{
    for (int i=0; range->list[i] != NULL; i++)
    {
        trafficgen_port_info_t *pinfo = range->list[i];
        memset(&pinfo->stats, 0, sizeof(pinfo->stats));
    }
    return 0;
}

/**
 *
 * @param range
 *
 * @return
 */
int trafficgen_do_reset(const trafficgen_port_set_t *range)
{
    uint64_t mac_addr_base = bdk_config_get(BDK_CONFIG_MAC_ADDRESS);

    for (int i=0; range->list[i] != NULL; i++)
    {
        trafficgen_port_info_t *pinfo = range->list[i];
        int connect_to_port = pinfo->port + 1;
        int interface = bdk_helper_get_interface_num(pinfo->port);
        if ((pinfo->port != bdk_helper_get_first_ipd_port(interface)) &&
            (connect_to_port > bdk_helper_get_last_ipd_port(interface)))
            connect_to_port = bdk_helper_get_first_ipd_port(interface);

        pinfo->setup.output_enable              = 0;
        pinfo->setup.output_packet_type         = PACKET_TYPE_IPV4_UDP;
        pinfo->setup.output_packet_payload      = DATA_TYPE_ABC;
        pinfo->setup.input_arp_reply_enable     = 1;
        pinfo->setup.input_arp_request_enable   = 1;
        pinfo->setup.output_packet_size         = 64 - ETHERNET_CRC;
        pinfo->setup.output_count               = 0;
        pinfo->setup.output_percent_x1000       = 100000;
        pinfo->setup.src_mac                    = mac_addr_base + pinfo->port;
        pinfo->setup.src_mac_inc		    =0;
        pinfo->setup.src_mac_min		    = mac_addr_base + (pinfo->port << 16);
        pinfo->setup.src_mac_max		    = mac_addr_base + 64 + (pinfo->port << 16);
        pinfo->setup.dest_mac                   = mac_addr_base + connect_to_port;
        pinfo->setup.dest_mac_inc               = 0;
        pinfo->setup.dest_mac_min               = mac_addr_base + (connect_to_port << 16);
        pinfo->setup.dest_mac_max               = mac_addr_base + 64 + (connect_to_port << 16);
        pinfo->setup.vlan_size                  = 0;
        pinfo->setup.src_ip                     = 0x0a000063 | (pinfo->port<<16);        /* 10.port.0.99 */
        pinfo->setup.src_ip_min                 = 0x0a000000 | (pinfo->port<<16);        /* 10.port.0.0 */;
        pinfo->setup.src_ip_max                 = 0x0a000063 | (pinfo->port<<16);        /* 10.port.0.99 */;
        pinfo->setup.src_ip_inc                 = 0;
        pinfo->setup.dest_ip                    = 0x0a000063 | (connect_to_port<<16);   /* 10.connect_to_port.0.99 */
        pinfo->setup.dest_ip_min                = 0x0a000000 | (connect_to_port<<16);   /* 10.connect_to_port.0.0 */;
        pinfo->setup.dest_ip_max                = 0x0a000063 | (connect_to_port<<16);   /* 10.connect_to_port.0.99 */;
        pinfo->setup.dest_ip_inc                = 0;
        pinfo->setup.src_port                   = 4096;
        pinfo->setup.src_port_min               = 0;
        pinfo->setup.src_port_max               = 65535;
        pinfo->setup.src_port_inc               = 0;
        pinfo->setup.dest_port                  = 4097;
        pinfo->setup.dest_port_min              = 0;
        pinfo->setup.dest_port_max              = 65535;
        pinfo->setup.dest_port_inc              = 0;
        pinfo->setup.output_arp_reply_enable    = 1;
        pinfo->setup.ip_tos                     = 0;
        pinfo->setup.do_checksum                = 0;
        pinfo->setup.bridge_port                = BRIDGE_OFF;
        pinfo->setup.display_packet             = 0;
        pinfo->setup.promisc                    = 1;
        update_cycle_gap(pinfo);
    }
    return trafficgen_do_clear(range);
}

/**
 *
 * @param stat
 * @param last
 *
 * @return
 */
static uint64_t get_delta(uint32_t stat, uint32_t last)
{
    if (stat >= last)
        return stat - last;
    else
        return (uint64_t)last + (1ull<<32) - (uint64_t)stat;
}

/**
 *
 * @return
 */
int trafficgen_do_update(void)
{
    /* Get the statistics for displayed ports */
    for (int i=0; tg_all_set.list[i] != NULL; i++)
    {
        trafficgen_port_info_t *pinfo = tg_all_set.list[i];

        bdk_pko_port_status_t pko_stats;
        bdk_pko_get_port_status(pinfo->port, 0, &pko_stats);
        uint32_t tx_delta_packets = get_delta(pko_stats.packets, pinfo->priv.pko_stats.packets);
        pinfo->stats.tx_packets += tx_delta_packets;
        pinfo->stats.tx_octets += get_delta(pko_stats.octets, pinfo->priv.pko_stats.octets);
        pinfo->priv.pko_stats = pko_stats;

        /* Tx octets at the hardware level does not include ETHERNET_CRC but
            does include the pre L2 header. This is not what the user expects */
        int64_t bytes_off_per_packet = ETHERNET_CRC - get_size_pre_l2(pinfo);
        pinfo->stats.tx_octets += bytes_off_per_packet * tx_delta_packets;

        bdk_pip_port_status_t pip_stats;
        bdk_pip_get_port_status(pinfo->port, 0, &pip_stats);
        pinfo->stats.rx_dropped_octets += get_delta(pip_stats.dropped_octets, pinfo->priv.pip_stats.dropped_octets);
        pinfo->stats.rx_dropped_packets += get_delta(pip_stats.dropped_packets, pinfo->priv.pip_stats.dropped_packets);
        pinfo->stats.rx_octets += get_delta(pip_stats.octets, pinfo->priv.pip_stats.octets);
        uint32_t rx_delta_packets = get_delta(pip_stats.packets, pinfo->priv.pip_stats.packets);
        pinfo->stats.rx_packets += rx_delta_packets;
        pinfo->stats.rx_multicast += get_delta(pip_stats.multicast_packets, pinfo->priv.pip_stats.multicast_packets);
        pinfo->stats.rx_broadcast += get_delta(pip_stats.broadcast_packets, pinfo->priv.pip_stats.broadcast_packets);
        pinfo->stats.rx_len_64 += get_delta(pip_stats.len_64_packets, pinfo->priv.pip_stats.len_64_packets);
        pinfo->stats.rx_len_65_127 += get_delta(pip_stats.len_65_127_packets, pinfo->priv.pip_stats.len_65_127_packets);
        pinfo->stats.rx_len_128_255 += get_delta(pip_stats.len_128_255_packets, pinfo->priv.pip_stats.len_128_255_packets);
        pinfo->stats.rx_len_256_511 += get_delta(pip_stats.len_256_511_packets, pinfo->priv.pip_stats.len_256_511_packets);
        pinfo->stats.rx_len_512_1023 += get_delta(pip_stats.len_512_1023_packets, pinfo->priv.pip_stats.len_512_1023_packets);
        pinfo->stats.rx_len_1024_1518 += get_delta(pip_stats.len_1024_1518_packets, pinfo->priv.pip_stats.len_1024_1518_packets);
        pinfo->stats.rx_len_1519_max += get_delta(pip_stats.len_1519_max_packets, pinfo->priv.pip_stats.len_1519_max_packets);
        pinfo->stats.rx_fcs_align_err += get_delta(pip_stats.fcs_align_err_packets, pinfo->priv.pip_stats.fcs_align_err_packets);
        pinfo->stats.rx_runt += get_delta(pip_stats.runt_packets, pinfo->priv.pip_stats.runt_packets);
        pinfo->stats.rx_runt_crc += get_delta(pip_stats.runt_crc_packets, pinfo->priv.pip_stats.runt_crc_packets);
        pinfo->stats.rx_oversize += get_delta(pip_stats.oversize_packets, pinfo->priv.pip_stats.oversize_packets);
        pinfo->stats.rx_oversize_crc += get_delta(pip_stats.oversize_crc_packets, pinfo->priv.pip_stats.oversize_crc_packets);
        pinfo->stats.rx_errors += get_delta(pip_stats.inb_errors, pinfo->priv.pip_stats.inb_errors);
        pinfo->priv.pip_stats = pip_stats;

        /* RX octets count ETHERNET_CRC for ports less than 32 and not for 32 and higher. For all ports
            it counts the pre L2, which the user probably doesn't expect */
        switch (pinfo->setup.imode)
        {
            case BDK_HELPER_INTERFACE_MODE_SRIO:
                bytes_off_per_packet = -sizeof(bdk_srio_rx_message_header_t) + ETHERNET_CRC;
                break;
            case BDK_HELPER_INTERFACE_MODE_LOOP:
                bytes_off_per_packet = ETHERNET_CRC - get_size_pre_l2(pinfo);
                break;
            default:
                bytes_off_per_packet = -get_size_pre_l2(pinfo);
                break;
        }
        pinfo->stats.rx_octets += bytes_off_per_packet * rx_delta_packets;

        /* Calculate the RX bits. By convention this include all packet
            overhead on the wire. We've already accounted for ETHERNET_CRC but
            not the preamble and IFG */
        bytes_off_per_packet = get_size_wire_overhead(pinfo);
        switch (pinfo->setup.imode)
        {
            case BDK_HELPER_INTERFACE_MODE_SRIO:
                bytes_off_per_packet = 0;
                break;
            default:
                bytes_off_per_packet = get_size_wire_overhead(pinfo) - ETHERNET_CRC;
                break;
        }
        pinfo->stats.rx_bits = (pinfo->stats.rx_packets * bytes_off_per_packet + pinfo->stats.rx_octets) * 8;

        /* Calculate the TX bits */
        pinfo->stats.tx_bits = (pinfo->stats.tx_packets * bytes_off_per_packet + pinfo->stats.tx_octets) * 8;

        /* Get the backpressure counters */
        bdk_gmxx_txx_pause_togo_t txx_pause_togo;
        txx_pause_togo.u64 = 0;
        switch (bdk_helper_interface_get_mode(bdk_helper_get_interface_num(pinfo->port)))
        {
            case BDK_HELPER_INTERFACE_MODE_DISABLED:
            case BDK_HELPER_INTERFACE_MODE_PCIE:
            case BDK_HELPER_INTERFACE_MODE_NPI:
            case BDK_HELPER_INTERFACE_MODE_LOOP:
            case BDK_HELPER_INTERFACE_MODE_SRIO:
                break;
            case BDK_HELPER_INTERFACE_MODE_XAUI:
                txx_pause_togo.u64 = BDK_CSR_READ(BDK_GMXX_TXX_PAUSE_TOGO(0, bdk_helper_get_interface_num(pinfo->port)));
                if (txx_pause_togo.s.time == 0)
                {
                    bdk_gmxx_rx_hg2_status_t gmxx_rx_hg2_status;
                    gmxx_rx_hg2_status.u64 = BDK_CSR_READ(BDK_GMXX_RX_HG2_STATUS(bdk_helper_get_interface_num(pinfo->port)));
                    txx_pause_togo.s.time = gmxx_rx_hg2_status.s.lgtim2go;
                }
                break;
            case BDK_HELPER_INTERFACE_MODE_SGMII:
            case BDK_HELPER_INTERFACE_MODE_PICMG:
                txx_pause_togo.u64 = BDK_CSR_READ(BDK_GMXX_TXX_PAUSE_TOGO(bdk_helper_get_interface_index_num(pinfo->port), bdk_helper_get_interface_num(pinfo->port)));
                break;
        }
        pinfo->stats.rx_backpressure += txx_pause_togo.s.time;
    }
    return 0;
}



/*
 *      Fold a partial checksum without adding pseudo headers
 */
static unsigned short int csum_fold(unsigned int sum)
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
static unsigned short ip_fast_csum(char *iph, unsigned int ihl)
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


static char *build_packet_mac_and_vlan_only(char *packet, trafficgen_port_info_t *pinfo)
{
    int i;
    char *ptr = packet;

    /* Add the SRIO header before L2 if needed */
    if (pinfo->setup.srio.u64)
    {
        memcpy(ptr, &pinfo->setup.srio, sizeof(pinfo->setup.srio));
        ptr += sizeof(pinfo->setup.srio);
    }

    /* Add the HiGig header before L2 if needed */
    if (pinfo->setup.higig)
    {
        memcpy(ptr, &pinfo->setup.higig_header, pinfo->setup.higig);
        ptr += pinfo->setup.higig;
    }

    /* Ethernet dest address */
    for (i=0; i<6; i++)
        *ptr++ = (pinfo->setup.dest_mac>>(40-i*8)) & 0xff;

    /* Ethernet source address */
    for (i=0; i<6; i++)
        *ptr++ = (pinfo->setup.src_mac>>(40-i*8)) & 0xff;

    /* VLAN */
    for (i=0; i<(int)pinfo->setup.vlan_size; i++)
        *ptr++ = (pinfo->setup.vlan[i]);

    return ptr;
}

/**
 * Generate a valid UDP packet
 *
 * @param port   Output port to build for
 */
static char *build_packet(trafficgen_port_info_t *pinfo)
{
    int i;
    char *packet = malloc(pinfo->setup.output_packet_size);
    if (!packet)
    {
        bdk_error("Failed to allocate TX packet for port %d\n", pinfo->port);
        return NULL;
    }
    char *end_ptr = packet + get_end_payload(pinfo);
    char *ptr = build_packet_mac_and_vlan_only(packet, pinfo);
    int ip_length;

    switch (pinfo->setup.output_packet_type)
    {
        uint16_t *ip_checksum_ptr;
        case PACKET_TYPE_HELP:
        case PACKET_TYPE_IPV4_UDP:
        case PACKET_TYPE_IPV4_TCP:
            *ptr++ = 0x08;                  /* Ethernet Protocol */
            *ptr++ = 0x00;
            *ptr++ = 0x45;                  /* IP version, ihl */
            *ptr++ = (pinfo->setup.ip_tos) & 0xff;    /* IP TOS */
            ip_length = get_size_ip_header(pinfo) + get_size_payload(pinfo);
            *ptr++ = ip_length>>8;        /* IP length */
            *ptr++ = ip_length&0xff;
            *ptr++ = 0x00;                  /* IP id */
            *ptr++ = 0x00;
            *ptr++ = 0x00;                  /* IP frag_off */
            *ptr++ = 0x00;
            *ptr++ = 0x04;                  /* IP ttl */
            *ptr++ = (pinfo->setup.output_packet_type == PACKET_TYPE_IPV4_TCP) ? 0x6 : 0x11; /* IP protocol */
            ip_checksum_ptr = (uint16_t *)ptr;    /* remember for later */
            *ptr++ = 0x00;                  /* IP check */
            *ptr++ = 0x00;
            *ptr++ = (pinfo->setup.src_ip>>24) & 0xff;    /* IP saddr */
            *ptr++ = (pinfo->setup.src_ip>>16) & 0xff;
            *ptr++ = (pinfo->setup.src_ip>>8) & 0xff;
            *ptr++ = (pinfo->setup.src_ip>>0) & 0xff;
            *ptr++ = (pinfo->setup.dest_ip>>24) & 0xff;    /* IP daddr */
            *ptr++ = (pinfo->setup.dest_ip>>16) & 0xff;
            *ptr++ = (pinfo->setup.dest_ip>>8) & 0xff;
            *ptr++ = (pinfo->setup.dest_ip>>0) & 0xff;
            *ip_checksum_ptr = ip_fast_csum(packet+get_end_l2(pinfo), 5);
            break;
        case PACKET_TYPE_IPV6_UDP:
        case PACKET_TYPE_IPV6_TCP:
            if (pinfo->setup.output_packet_size < 62)
                printf("Warning: Port %2d Packet size too small for UDP payload. Minimum is 62\n", pinfo->port);
            if (!pinfo->setup.do_checksum)
                printf("Warning: Port %2d UDP checksum is off. Linux will drop IPv6 UDP packets without a checksum\n", pinfo->port);
            if ((pinfo->setup.output_packet_size < 66) && pinfo->setup.validate)
                printf("Warning: Port %2d Packet size too small for validation. Minimum is 66\n", pinfo->port);
            *(uint16_t*)ptr = 0x86dd; ptr+=2;                           /* Ethernet Protocol = ETH_P_IPV6 0x86DD */
            *ptr++ = 0x60 | ((pinfo->setup.ip_tos>>4) & 0xf); /* IP version 6, 4 bits of DS byte */
            *ptr++ = (((pinfo->setup.ip_tos) & 0xf) << 4) | 0;/* 4 bits of DS byte + 4 bits of Flow label (0) */
            *(uint16_t*)ptr = 0; ptr+=2;                                /* Flow label */
            ip_length = get_size_payload(pinfo);
            *(uint16_t*)ptr = ip_length; ptr+=2;    /* Payload length */
            *ptr++ = (pinfo->setup.output_packet_type == PACKET_TYPE_IPV6_TCP) ? 0x6 : 0x11; /* IP protocol */
            *ptr++ = 0x04;                                              /* IP ttl */
            *(uint64_t*)ptr = 0; ptr+=8;                                /* IP saddr */
            *(uint64_t*)ptr = pinfo->setup.src_ip; ptr+=8;
            *(uint64_t*)ptr = 0; ptr+=8;                                /* IP daddr */
            *(uint64_t*)ptr = pinfo->setup.dest_ip; ptr+=8;
            break;
        case PACKET_TYPE_802_3_PAUSE:
            pinfo->setup.output_packet_size = 60;
            ptr = packet + get_end_pre_l2(pinfo);
            end_ptr = packet + get_end_payload(pinfo);
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
            goto skip; /* Bail out before we get to the TCP/UDP stuff below */
        case PACKET_TYPE_CBFC_PAUSE:
            pinfo->setup.output_packet_size = 60;
            ptr = packet + get_end_pre_l2(pinfo);
            end_ptr = packet + get_end_payload(pinfo);
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
            goto skip; /* Bail out before we get to the TCP/UDP stuff below */
        case PACKET_TYPE_CJPAT:
            pinfo->setup.output_packet_size = sizeof(CJPAT_Packet);
            memcpy(packet, CJPAT_Packet, sizeof(CJPAT_Packet));
              /* Turn off the deficit counter and turn on unidirection mode. This forces
               * the XAUI interface into half-plex mode. (However, the executive startup
               * code usually wants to be in duplex-mode. I have to compile without
               * USE_DUPLEX in my modified version of bdk-helper-xaui.c!)
               */
            int interface = bdk_helper_get_interface_num(pinfo->port);
            int index = bdk_helper_get_interface_index_num(pinfo->port);
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
            goto skip; /* Bail out before we get to the TCP/UDP stuff below */
    }
    *ptr++ = pinfo->setup.src_port >> 8;  /* UDP source port */
    *ptr++ = pinfo->setup.src_port & 0xff;
    *ptr++ = pinfo->setup.dest_port >> 8; /* UDP destination port */
    *ptr++ = pinfo->setup.dest_port & 0xff;
    switch (pinfo->setup.output_packet_type)
    {
        case PACKET_TYPE_HELP:
        case PACKET_TYPE_802_3_PAUSE:
        case PACKET_TYPE_CBFC_PAUSE:
        case PACKET_TYPE_CJPAT:
            break;
        case PACKET_TYPE_IPV4_UDP:
        case PACKET_TYPE_IPV6_UDP:
        {
            int udp_length = get_size_payload(pinfo);
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

    switch (pinfo->setup.output_packet_payload) {
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
    if (pinfo->setup.validate)
    {
        int end_l2 = get_end_l2(pinfo);
        ptr = packet + end_l2;
        *(uint32_t*)(end_ptr-4) = crc32c(ptr, end_ptr - ptr - 4, 0xffffffff);
    }
skip:
    return packet;
}

/**
 * Called every packet to increment parts of the packet as necessary.
 *
 * @param port
 * @param data
 */
static void packet_incrementer(trafficgen_port_info_t *pinfo, char *data)
{
    switch (pinfo->setup.output_packet_type)
    {
        case PACKET_TYPE_HELP:
        case PACKET_TYPE_IPV4_UDP:
        case PACKET_TYPE_IPV4_TCP:
        {
            int begin_ip = get_end_l2(pinfo);
            if (bdk_unlikely(pinfo->setup.src_port_inc))
            {
                int p = *(uint16_t*)(data + begin_ip + 20);
                p += pinfo->setup.src_port_inc;
                if (p < pinfo->setup.src_port_min)
                    p = pinfo->setup.src_port_max;
                else if (p > pinfo->setup.src_port_max)
                    p = pinfo->setup.src_port_min;
                *(uint16_t*)(data + begin_ip + 20) = p;
            }

            if (bdk_unlikely(pinfo->setup.dest_port_inc))
            {
                int p = *(uint16_t*)(data + begin_ip + 22);
                p += pinfo->setup.dest_port_inc;
                if (p < pinfo->setup.dest_port_min)
                    p = pinfo->setup.dest_port_max;
                else if (p > pinfo->setup.dest_port_max)
                    p = pinfo->setup.dest_port_min;
                *(uint16_t*)(data + begin_ip + 22) = p;
            }

            if (bdk_unlikely(pinfo->setup.src_ip_inc))
            {
                int64_t p = *(uint32_t*)(data + begin_ip + 12);
                p += pinfo->setup.src_ip_inc;
                if (p < pinfo->setup.src_ip_min)
                    p = pinfo->setup.src_ip_max;
                else if (p > pinfo->setup.src_ip_max)
                    p = pinfo->setup.src_ip_min;
                *(uint32_t*)(data + begin_ip + 12) = p;
            }

            if (bdk_unlikely(pinfo->setup.dest_ip_inc))
            {
                int64_t p = *(uint32_t*)(data + begin_ip + 16);
                p += pinfo->setup.dest_ip_inc;
                if (p < pinfo->setup.dest_ip_min)
                    p = pinfo->setup.dest_ip_max;
                else if (p > pinfo->setup.dest_ip_max)
                    p = pinfo->setup.dest_ip_min;
                *(uint32_t*)(data + begin_ip + 16) = p;
            }

            if ((bdk_unlikely(pinfo->setup.src_ip_inc)) ||
                (bdk_unlikely(pinfo->setup.dest_ip_inc)))
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
            int begin_ip = get_end_l2(pinfo);
            if (bdk_unlikely(pinfo->setup.src_port_inc))
            {
                int p = *(uint16_t*)(data + begin_ip + 40);
                p += pinfo->setup.src_port_inc;
                if (p < pinfo->setup.src_port_min)
                    p = pinfo->setup.src_port_max;
                else if (p > pinfo->setup.src_port_max)
                    p = pinfo->setup.src_port_min;
                *(uint16_t*)(data + begin_ip + 40) = p;
            }

            if (bdk_unlikely(pinfo->setup.dest_port_inc))
            {
                int p = *(uint16_t*)(data + begin_ip + 40 + 2);
                p += pinfo->setup.dest_port_inc;
                if (p < pinfo->setup.dest_port_min)
                    p = pinfo->setup.dest_port_max;
                else if (p > pinfo->setup.dest_port_max)
                    p = pinfo->setup.dest_port_min;
                *(uint16_t*)(data + begin_ip + 40 + 2) = p;
            }

            if (bdk_unlikely(pinfo->setup.src_ip_inc))
            {
                int64_t p = *(uint64_t*)(data+begin_ip+8+8);
                p += pinfo->setup.src_ip_inc;
                if (p < pinfo->setup.src_ip_min)
                    p = pinfo->setup.src_ip_max;
                else if (p > pinfo->setup.src_ip_max)
                    p = pinfo->setup.src_ip_min;
                *(uint64_t*)(data+begin_ip+8+8) = p;
            }

            if (bdk_unlikely(pinfo->setup.dest_ip_inc))
            {
                int64_t p = *(uint64_t*)(data+begin_ip+8+24);
                p += pinfo->setup.dest_ip_inc;
                if (p < pinfo->setup.dest_ip_min)
                    p = pinfo->setup.dest_ip_max;
                else if (p > pinfo->setup.dest_ip_max)
                    p = pinfo->setup.dest_ip_min;
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

   if (bdk_unlikely(pinfo->setup.dest_mac_inc))
   {
        char* mac = data + get_end_pre_l2(pinfo);
        uint64_t m = *(uint64_t*)mac >> 16;

        m += pinfo->setup.dest_mac_inc;
        if ((m < pinfo->setup.dest_mac_min) || (m > pinfo->setup.dest_mac_max))
            m = pinfo->setup.dest_mac_min;

        *(uint32_t*)mac = m >> 16;
        *(uint16_t*)(mac+4) = m;
    }

   if (bdk_unlikely(pinfo->setup.src_mac_inc))
   {
        char* mac = data + get_end_pre_l2(pinfo) + MAC_ADDR_LEN;
        uint64_t m = *(uint64_t*)mac >> 16;

        m += pinfo->setup.src_mac_inc;
        if ((m < pinfo->setup.src_mac_min) || (m > pinfo->setup.src_mac_max))
            m = pinfo->setup.src_mac_min;

        *(uint32_t*)mac = m >> 16;
        *(uint16_t*)(mac+4) = m;
    }
}

static void packet_transmitter(int unused, trafficgen_port_info_t *pinfo)
{
    char *packet = build_packet(pinfo);
    if (!packet)
        return;

    bdk_pko_command_word0_t    pko_command;
    bdk_buf_ptr_t              hw_buffer;
    uint64_t                   output_cycle;
    uint64_t                   count = 0;
    const uint64_t             queue = bdk_pko_get_base_queue(pinfo->port);
    trafficgen_port_setup_t *  port_tx = &pinfo->setup;

    /* Build the PKO buffer pointer */
    hw_buffer.u64 = 0;
    hw_buffer.s.pool = BDK_FPA_PACKET_POOL;
    hw_buffer.s.size = 0xffff;
    hw_buffer.s.back = 0;
    hw_buffer.s.addr = bdk_ptr_to_phys(packet);

    /* Build the PKO command */
    pko_command.u64 = 0;
    pko_command.s.dontfree =1;
    pko_command.s.segs = 1;

    output_cycle = bdk_clock_get_count(BDK_CLOCK_CORE) << CYCLE_SHIFT;

    while (port_tx->output_enable)
    {
        uint64_t cycle = bdk_clock_get_count(BDK_CLOCK_CORE) << CYCLE_SHIFT;
        if (bdk_likely(cycle >= output_cycle))
        {
            bdk_pko_send_packet_prepare(pinfo->port, queue, BDK_PKO_LOCK_NONE);
            packet_incrementer(pinfo, packet);
            output_cycle += port_tx->output_cycle_gap;
            pko_command.s.total_bytes = port_tx->output_packet_size + get_size_pre_l2(pinfo);
            if (port_tx->do_checksum)
                pko_command.s.ipoffp1 = get_end_l2(pinfo) + 1;
            else
                pko_command.s.ipoffp1 = 0;
            /* We don't care if the send fails */
            bdk_pko_send_packet_finish(pinfo->port, queue, pko_command, hw_buffer, BDK_PKO_LOCK_NONE);

            /* If we aren't keeping up, start send 4 more packets per iteration */
            if (bdk_unlikely(cycle > output_cycle + 500) && (count>4))
            {
                uint64_t words[8] = {pko_command.u64, hw_buffer.u64, pko_command.u64, hw_buffer.u64, pko_command.u64, hw_buffer.u64, pko_command.u64, hw_buffer.u64};
                output_cycle += port_tx->output_cycle_gap*4;
                count -= 4;
                if (bdk_likely(bdk_cmd_queue_write(BDK_CMD_QUEUE_PKO(queue), 0, 8, words) == BDK_CMD_QUEUE_SUCCESS))
                    bdk_pko_doorbell(pinfo->port, queue, 8);
            }

            if (bdk_unlikely(--count == 0))
            {
                port_tx->output_enable = 0;
                BDK_SYNCW;
            }
        }
        else
            bdk_thread_yield();
    }
    free(packet);
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
static bdk_buf_ptr_t get_packet_buffer_ptr(const bdk_wqe_t *work)
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
 * Check the CRC on an incomming packet and return non zero if it
 * doesn't match the calculated value.
 *
 * @param work   Packet to process. We handle dynamic short.
 *
 * @return Non zero on CRC error
 */
static int is_packet_crc32c_wrong(trafficgen_port_info_t *pinfo, bdk_wqe_t *work)
{
    uint32_t crc = 0xffffffff;
    bdk_buf_ptr_t buffer_ptr = get_packet_buffer_ptr(work);

    /* Get a pointer to the beginning of the packet */
    void *ptr = bdk_phys_to_ptr(buffer_ptr.s.addr);
    int remaining_bytes = work->len;

    /* Skip the L2 header in the CRC calculation */
    int skip = get_end_l2(pinfo);
    if (pinfo->setup.imode == BDK_HELPER_INTERFACE_MODE_SRIO)
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
                udp_checksum_offset = get_size_ip_header(pinfo) + 6;
        }
        else
        {
            if (*(uint8_t*)(ptr + 9) == 0x11)
                udp_checksum_offset = get_size_ip_header(pinfo) + 6;
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
static packet_free_t fastpath_receive(trafficgen_port_info_t *pinfo, bdk_wqe_t *work)
{
#if 0 // FIXME
    if (bdk_unlikely(pinfo->setup.display_packet == 1))
        dump_packet(work);
#endif
    if (bdk_unlikely(work->word2.s.rcv_error))
    {
        bdk_atomic_add64((int64_t*)&pinfo->stats.rx_wqe_errors[work->word2.s.err_code], 1);
#if 0 // FIXME
        if (bdk_unlikely(pinfo->setup.display_packet == 2))
            dump_packet(work);
#endif
        return PACKET_FREE;
    }

    if (bdk_unlikely(pinfo->setup.validate))
    {
        if (bdk_unlikely(is_packet_crc32c_wrong(pinfo, work)))
            bdk_atomic_add64((int64_t*)&pinfo->stats.rx_validation_errors, 1);
    }
#if 0 // FIXME
    if (bdk_unlikely(pinfo->setup.bridge_port != BRIDGE_OFF))
    {
        int output_port = pinfo->setup.bridge_port;
        trafficgen_port_info_t *pout = tg_get_pinfo(output_port);
        uint64_t queue = bdk_pko_get_base_queue(output_port) + 1;  /* NOTE: use a different queue than normal*/
        bdk_spinlock_lock(&pout->priv.lock);
        bdk_pko_send_packet_prepare(output_port, queue, BDK_PKO_LOCK_NONE);

        /* Build the PKO command */
        bdk_pko_command_word0_t pko_command;
        pko_command.u64 = 0;
        pko_command.s.dontfree = 0;
        pko_command.s.segs = (work->word2.s.bufs) ? work->word2.s.bufs : 1;
        pko_command.s.total_bytes = work->len;

        bdk_buf_ptr_t buffer_ptr = get_packet_buffer_ptr(work);
        bdk_pko_status_t status = bdk_pko_send_packet_finish(output_port, queue, pko_command, buffer_ptr, BDK_PKO_LOCK_NONE);
        bdk_spinlock_unlock(&pout->priv.lock);
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
#endif
        return PACKET_FREE;
}

/**
 * Called by cores when they get work and need to process it.
 *
 * @param work   Work to be processed. Ideally it should already be prefetched
 *               into memory.
 */
static void process_work(bdk_wqe_t *work)
{
    trafficgen_port_info_t *pinfo = tg_get_pinfo(work->ipprt);
    packet_free_t status = fastpath_receive(pinfo, work);
    if (bdk_likely(status == PACKET_FREE))
        bdk_helper_free_packet_data(work);
    if (bdk_likely(status != PACKET_DONT_FREE_WQE))
        bdk_fpa_free(work, BDK_FPA_WQE_POOL, 0);
}

static void packet_receiver(int unused, void *unused2)
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
 *
 * @param range
 *
 * @return
 */
int trafficgen_do_transmit(const trafficgen_port_set_t *range)
{
    bdk_thread_create(0, packet_receiver, 0, NULL);
    for (int i=0; range->list[i] != NULL; i++)
    {
        trafficgen_port_info_t *pinfo = range->list[i];
        pinfo->setup.output_enable = 1;
        bdk_thread_create(0, (bdk_thread_func_t)packet_transmitter, i, pinfo);
    }
    return 0;
}

/**
 *
 * @param range
 *
 * @return
 */
int trafficgen_is_transmitting(const trafficgen_port_set_t *range)
{
    for (int i=0; range->list[i] != NULL; i++)
    {
        trafficgen_port_info_t *pinfo = range->list[i];
        if (pinfo->setup.output_enable)
            return 1;
    }
    return 0;
}

