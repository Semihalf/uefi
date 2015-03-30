#include <bdk.h>
#include "../dram-internal.h"
#include "common-spd-tables.h"

#define USE_INTERNAL_SPD 0 /* Change to 1 for compiled in SPDs */

#define DEFAULT_INTERNAL_SPD MT18ASF1G72AZ_2G1AYESZG_SPD

#define DEFAULT_NAME   "cn88xx-crb-2s"
//#define DEFAULT_SPEED  1066666666
//#define DEFAULT_SPEED  933333333
#define DEFAULT_SPEED  800000000

#define DEFAULT_LMC_MASK   TWO_LMC_MASK
#define DEFAULT_DIMM_MASK  ONE_DIMM_MASK

static rlevel_table_t rlevel_rank_values_node0[] =    {
    {
        .part = "36ASF2G72PZ-2G1A2",
        .speed = 1600,
        .rlevel_rank = {
            /*
              A recommended set of experimental hard-coded settings from David L.

              CRB12
              LMC0
              Rank(0) Rlevel Rank   0x1, 0x004A34C30B2CC30E :    10    13    12    12    11    11    12    12    14
              Rank(1) Rlevel Rank   0x1, 0x004A34C30B2CC34E :    10    13    12    12    11    11    12    13    14

              LMC1
              Rank(0) Rlevel Rank   0x1, 0x004B34B2CB2CC34E :    11    13    11    11    10    11    12    13    14
              Rank(1) Rlevel Rank   0x1, 0x004B34B2CB2CC34F :    11    13    11    11    10    11    12    13    14

              LMC2
              Rank(0) Rlevel Rank   0x1, 0x004B3CD34B30C34F :    11    15    13    12    11    12    12    13    15
              Rank(1) Rlevel Rank   0x1, 0x004B3CE34B30C34F :    11    15    14    13    11    12    12    13    15

              LMC3
              Rank(0) Rlevel Rank   0x1, 0x004C38D30B38E3D0 :    12    14    13    12    11    13    14    15    16
              Rank(1) Rlevel Rank   0x1, 0x004B38D30B34E410 :    11    14    13    12    11    13    14    15    16

              --------------------------------------------------------------
              CRB13
              LMC0
              Rank(0) Rlevel Rank   0x1, 0x004A34C30B2CC38E :    10    13    12    12    11    11    12    13    14
              Rank(1) Rlevel Rank   0x1, 0x004A34C30A2CC38E :    10    13    12    12    10    11    12    12    14

              LMC1
              Rank(0) Rlevel Rank   0x1, 0x004A30B2CA2CC34E :    10    12    11    11    10    11    12    13    14
              Rank(1) Rlevel Rank   0x1, 0x004B30B2CA2CC34E :    11    12    11    11    10    11    12    13    14

              LMC2
              Rank(0) Rlevel Rank   0x1, 0x004B38E30B30C34F :    11    14    14    12    11    12    12    13    15
              Rank(1) Rlevel Rank   0x1, 0x004B38D34B30C34F :    11    14    13    13    11    12    12    13    15

              LMC3
              Rank(0) Rlevel Rank   0x1, 0x004C38D30B34E3D0 :    12    14    13    12    11    13    14    15    16
              Rank(1) Rlevel Rank   0x1, 0x004C38D30B34E3D0 :    12    14    13    12    11    13    14    15    16
              ----------------------------------------------------------------
              Final
              LMC0
              Rank(0) Rlevel Rank   0x1, 0x004A34C30B2CC38E :    10    13    12    12    11    11    12    12    14
              Rank(1) Rlevel Rank   0x1, 0x004A34C30A2CC38E :    10    13    12    12    10    11    12    12    14

              LMC1
              Rank(0) Rlevel Rank   0x1, 0x004A30B2CA2CC34E :    10    12    11    11    10    11    12    13    14
              Rank(1) Rlevel Rank   0x1, 0x004B30B2CA2CC34E :    11    12    11    11    10    11    12    13    14

              LMC2
              Rank(0) Rlevel Rank   0x1, 0x004B38E30B30C34F :    11    14    13    12    11    12    12    13    15
              Rank(1) Rlevel Rank   0x1, 0x004B38D34B30C34F :    11    14    13    13    11    12    12    13    15

              LMC3
              Rank(0) Rlevel Rank   0x1, 0x004C38D30B34E3D0 :    12    14    13    12    11    13    14    15    16
              Rank(1) Rlevel Rank   0x1, 0x004C38D30B34E3D0 :    12    14    13    12    11    13    14    15    16

              33 lines matching "Rlevel Rank   0x1\\|Node 0: DRAM: .* MB, .* MHz\\|Initializing node . DDR interface\\|DIMM .: DDR4\\|fail\\|======== Fail\\|All tests passed" in buffer minicom-S9-26Mar1207.log.
              58:Initializing node 0 DDR interface 0, DDR Clock 933332010, DDR Reference Clock 50000000
              61:DIMM 0: DDR4 RDIMM, ECC  36ASF2G72PZ-2G1A2  s/n 237508068 1.2V
              199:Rank(0) Rlevel Rank   0x1, 0x004A34C30B2CC30E :    10    13    12    12    11    11    12    12    14
              209:Rank(1) Rlevel Rank   0x1, 0x004A34C30A2CC30E :    10    13    12    12    10    11    12    12    14
              246:Initializing node 0 DDR interface 1, DDR Clock 933332010, DDR Reference Clock 50000000
              249:DIMM 0: DDR4 RDIMM, ECC  36ASF2G72PZ-2G1A2  s/n 223344208 1.2V
              386:Rank(0) Rlevel Rank   0x1, 0x004A30B2CA2CC34E :    10    12    11    11    10    11    12    13    14
              396:Rank(1) Rlevel Rank   0x1, 0x004B30B2CA2CC34E :    11    12    11    11    10    11    12    13    14
              433:Initializing node 0 DDR interface 2, DDR Clock 933332010, DDR Reference Clock 50000000
              436:DIMM 0: DDR4 RDIMM, ECC  36ASF2G72PZ-2G1A2  s/n 223344210 1.2V
              574:Rank(0) Rlevel Rank   0x1, 0x004B38D30B30C34F :    11    14    13    12    11    12    12    13    15
              584:Rank(1) Rlevel Rank   0x1, 0x004B38D34B30C34F :    11    14    13    13    11    12    12    13    15
              621:Initializing node 0 DDR interface 3, DDR Clock 933332010, DDR Reference Clock 50000000
              624:DIMM 0: DDR4 RDIMM, ECC  36ASF2G72PZ-2G1A2  s/n 223344122 1.2V
              762:Rank(0) Rlevel Rank   0x1, 0x004C38D30B34E3D0 :    12    14    13    12    11    13    14    15    16
              772:Rank(1) Rlevel Rank   0x1, 0x004C38D30B34E3D0 :    12    14    13    12    11    13    14    15    16
              808:Node 0: DRAM: 65536 MB, 933 MHz
            */
            { 0x004A34C30B2CC30E, 0x004A34C30A2CC30E, 0, 0 },
            { 0x004A30B2CA2CC34E, 0x004B30B2CA2CC34E, 0, 0 },
            { 0x004B38D30B30C34F, 0x004B38D34B30C34F, 0, 0 },
            { 0x004C38D30B34E3D0, 0x004C38D30B34E3D0, 0, 0 } 
        }
    },

    {
        .part = "HMA42GR7MFR4N-TF",
        .speed = 1600,
        .rlevel_rank = {
            /*
              359 lines matching "Rlevel Rank   0x1\\|Node 0: DRAM: .* MB, .* MHz\\|Initializing node . DDR interface\\|DIMM .: DDR4" in buffer 0007-0-2x4x16GM.txt.
              3186:Initializing node 0 DDR interface 0, DDR Clock 799998940, DDR Reference Clock 50000000
              3189:DIMM 0: DDR4 RDIMM, ECC  HMA42GR7MFR4N-TF     s/n 588684673 1.2V
              3578:Rank(0) Rlevel Rank   0x1, 0x004A30B2CA28B2CC :    10    12    11    11    10    10    11    11    12 (0)
              3579:Rank(1) Rlevel Rank   0x1, 0x004A30B2CA28B2CC :    10    12    11    11    10    10    11    11    12 (0)
              3615:Initializing node 0 DDR interface 1, DDR Clock 799998940, DDR Reference Clock 50000000
              3618:DIMM 0: DDR4 RDIMM, ECC  HMA42GR7MFR4N-TF     s/n 588684933 1.2V
              4006:Rank(0) Rlevel Rank   0x1, 0x004B30B2C92CC30C :    11    12    11    11     9    11    12    12    12 (50)
              4007:Rank(1) Rlevel Rank   0x1, 0x004A30B2CA2CB30D :    10    12    11    11    10    11    11    12    13 (16)
              4043:Initializing node 0 DDR interface 2, DDR Clock 799998940, DDR Reference Clock 50000000
              4046:DIMM 0: DDR4 RDIMM, ECC  HMA42GR7MFR4N-TF     s/n 588684983 1.2V
              4435:Rank(0) Rlevel Rank   0x1, 0x004C34D34B2CB30D :    12    13    13    13    11    11    11    12    13 (117)
              4436:Rank(1) Rlevel Rank   0x1, 0x004B34D30B30B30D :    11    13    13    12    11    12    11    12    13 (116)
              4472:Initializing node 0 DDR interface 3, DDR Clock 799998940, DDR Reference Clock 50000000
              4475:DIMM 0: DDR4 RDIMM, ECC  HMA42GR7MFR4N-TF     s/n 588684474 1.2V
              4864:Rank(0) Rlevel Rank   0x1, 0x004B30C2CB30D38E :    11    12    12    11    11    12    13    14    14 (4)
              4865:Rank(1) Rlevel Rank   0x1, 0x004B34C2CB30D38E :    11    13    12    11    11    12    13    14    14 (0)
              4900:Node 0: DRAM: 65536 MB, 800 MHz
            */
            { 0x004A30B2CA28B2CC, 0x004A30B2CA28B2CC, 0, 0 },
            { 0x004B30B2C92CC30C, 0x004A30B2CA2CB30D, 0, 0 },
            { 0x004C34D34B2CB30D, 0x004B34D30B30B30D, 0, 0 },
            { 0x004B30C2CB30D38E, 0x004B34C2CB30D38E, 0, 0 }
        }
    },

    {0}                             /* Terminator */
};

static rlevel_table_t rlevel_rank_values_node1[] =    {
    {
        .part = "36ASF2G72PZ-2G1A2",
        .speed = 1600,
        .rlevel_rank = {
            /*
              68 lines matching "Rlevel Rank   0x1\\|Node 0: DRAM: .* MB, .* MHz\\|Initializing node . DDR interface\\|DIMM .: DDR4" in buffer 0004-1-2x4x16GM.txt.
              67:Initializing node 0 DDR interface 0, DDR Clock 799998960, DDR Reference Clock 50000000
              70:DIMM 0: DDR4 RDIMM, ECC  36ASF2G72PZ-2G1A2    s/n 223344170 1.2V
              459:Rank(0) Rlevel Rank   0x1, 0x004B38C30B2CC34E :    11    14    12    12    11    11    12    13    14 (0)
              460:Rank(1) Rlevel Rank   0x1, 0x004B38C30B2CC34E :    11    14    12    12    11    11    12    13    14 (0)
              496:Initializing node 0 DDR interface 1, DDR Clock 799998960, DDR Reference Clock 50000000
              499:DIMM 0: DDR4 RDIMM, ECC  36ASF2G72PZ-2G1A2    s/n 223344152 1.2V
              887:Rank(0) Rlevel Rank   0x1, 0x004B34C2CA30C34E :    11    13    12    11    10    12    12    13    14 (50)
              888:Rank(1) Rlevel Rank   0x1, 0x004B34C2CA30D34E :    11    13    12    11    10    12    13    13    14 (50)
              924:Initializing node 0 DDR interface 2, DDR Clock 799998960, DDR Reference Clock 50000000
              927:DIMM 0: DDR4 RDIMM, ECC  36ASF2G72PZ-2G1A2    s/n 237508037 1.2V
              1316:Rank(0) Rlevel Rank   0x1, 0x004B38D34B30C34F :    11    14    13    13    11    12    12    13    15 (0)
              1317:Rank(1) Rlevel Rank   0x1, 0x004B38D34B30C34F :    11    14    13    13    11    12    12    13    15 (0)
              1353:Initializing node 0 DDR interface 3, DDR Clock 799998960, DDR Reference Clock 50000000
              1356:DIMM 0: DDR4 RDIMM, ECC  36ASF2G72PZ-2G1A2    s/n 237507838 1.2V
              1745:Rank(0) Rlevel Rank   0x1, 0x004C38D30B34E3D0 :    12    14    13    12    11    13    14    15    16 (54)
              1746:Rank(1) Rlevel Rank   0x1, 0x004B38D30B34E3D0 :    11    14    13    12    11    13    14    15    16 (4)
              1781:Node 0: DRAM: 65536 MB, 800 MHz
            */
            { 0x004B38C30B2CC34E, 0x004B38C30B2CC34E, 0, 0 },
            { 0x004B34C2CA30C34E, 0x004B34C2CA30D34E, 0, 0 },
            { 0x004B38D34B30C34F, 0x004B38D34B30C34F, 0, 0 },
            { 0x004C38D30B34E3D0, 0x004B38D30B34E3D0, 0, 0 }
        }
    },

    {
        .part = "HMA42GR7MFR4N-TF",
        .speed = 1600,
        .rlevel_rank = {
            /*
              237 lines matching "Rlevel Rank   0x1\\|Node 0: DRAM: .* MB, .* MHz\\|Initializing node . DDR interface\\|DIMM .: DDR4" in buffer 0007-1-2x4x16GM.txt.
              24938:Initializing node 0 DDR interface 0, DDR Clock 799998950, DDR Reference Clock 50000000
              24941:DIMM 0: DDR4 RDIMM, ECC  HMA42GR7MFR4N-TF     s/n 588746878 1.2V
              25330:Rank(0) Rlevel Rank   0x1, 0x004930B2CA28B2CC :     9    12    11    11    10    10    11    11    12 (0)
              25331:Rank(1) Rlevel Rank   0x1, 0x004A30B2CA28B30C :    10    12    11    11    10    10    11    12    12 (4)
              25367:Initializing node 0 DDR interface 1, DDR Clock 799998950, DDR Reference Clock 50000000
              25370:DIMM 0: DDR4 RDIMM, ECC  HMA42GR7MFR4N-TF     s/n 588684821 1.2V
              25758:Rank(0) Rlevel Rank   0x1, 0x004A2CB2C92CB30D :    10    11    11    11     9    11    11    12    13 (50)
              25759:Rank(1) Rlevel Rank   0x1, 0x004A2CB2892CB30D :    10    11    11    10     9    11    11    12    13 (50)
              25795:Initializing node 0 DDR interface 2, DDR Clock 799998950, DDR Reference Clock 50000000
              25798:DIMM 0: DDR4 RDIMM, ECC  HMA42GR7MFR4N-TF     s/n 588684611 1.2V
              26187:Rank(0) Rlevel Rank   0x1, 0x004A34C34B2CB30D :    10    13    12    13    11    11    11    12    13 (104)
              26188:Rank(1) Rlevel Rank   0x1, 0x004A34D34B28D30D :    10    13    13    13    11    10    13    12    13 (166)
              26224:Initializing node 0 DDR interface 3, DDR Clock 799998950, DDR Reference Clock 50000000
              26227:DIMM 0: DDR4 RDIMM, ECC  HMA42GR7MFR4N-TF     s/n 588658086 1.2V
              26616:Rank(0) Rlevel Rank   0x1, 0x004B34C2CA30C38E :    11    13    12    11    10    12    12    14    14 (50)
              26617:Rank(1) Rlevel Rank   0x1, 0x004B34C2CA30C38E :    11    13    12    11    10    12    12    14    14 (50)
              26652:Node 0: DRAM: 65536 MB, 800 MHz
            */
            { 0x004930B2CA28B2CC, 0x004A30B2CA28B30C, 0, 0 },
            { 0x004A2CB2C92CB30D, 0x004A2CB2892CB30D, 0, 0 },
            { 0x004A34C34B2CB30D, 0x004A34D34B28D30D, 0, 0 },
            { 0x004B34C2CA30C38E, 0x004B34C2CA30C38E, 0, 0 }
        }
    },

    {0}                             /* Terminator */
};

static void setup_modereg_params1_1rank_1slot(bdk_lmcx_modereg_params1_t *modereg)
{
    modereg->u = 0;
    modereg->s.pasr_00      = 0;
    modereg->s.asr_00       = 0;
    modereg->s.srt_00       = 0;
    modereg->s.rtt_wr_00    = 0;
    modereg->s.dic_00       = ddr4_dic_34ohm;
    modereg->s.rtt_nom_00   = 0;
    modereg->s.pasr_01      = 0;
    modereg->s.asr_01       = 0;
    modereg->s.srt_01       = 0;
    modereg->s.rtt_wr_01    = 0;
    modereg->s.dic_01       = ddr4_dic_34ohm;
    modereg->s.rtt_nom_01   = 0;
    modereg->s.pasr_10      = 0;
    modereg->s.asr_10       = 0;
    modereg->s.srt_10       = 0;
    modereg->s.rtt_wr_10    = 0;
    modereg->s.dic_10       = ddr4_dic_34ohm;
    modereg->s.rtt_nom_10   = 0;
    modereg->s.pasr_11      = 0;
    modereg->s.asr_11       = 0;
    modereg->s.srt_11       = 0;
    modereg->s.rtt_wr_11    = 0;
    modereg->s.dic_11       = ddr4_dic_34ohm;
    modereg->s.rtt_nom_11   = 0;
}

static void setup_modereg_params1_1rank_2slot(bdk_lmcx_modereg_params1_t *modereg)
{
    modereg->u = 0;
    modereg->s.pasr_00      = 0;
    modereg->s.asr_00       = 0;
    modereg->s.srt_00       = 0;
    modereg->s.rtt_wr_00    = ddr4_rttwr_120ohm;
    modereg->s.dic_00       = ddr4_dic_34ohm;
    modereg->s.rtt_nom_00   = 0;
    modereg->s.pasr_01      = 0;
    modereg->s.asr_01       = 0;
    modereg->s.srt_01       = 0;
    modereg->s.rtt_wr_01    = 0;
    modereg->s.dic_01       = ddr4_dic_34ohm;
    modereg->s.rtt_nom_01   = 0;
    modereg->s.pasr_10      = 0;
    modereg->s.asr_10       = 0;
    modereg->s.srt_10       = 0;
    modereg->s.rtt_wr_10    = ddr4_rttwr_120ohm;
    modereg->s.dic_10       = ddr4_dic_34ohm;
    modereg->s.rtt_nom_10   = 0;
    modereg->s.pasr_11      = 0;
    modereg->s.asr_11       = 0;
    modereg->s.srt_11       = 0;
    modereg->s.rtt_wr_11    = 0;
    modereg->s.dic_11       = ddr4_dic_34ohm;
    modereg->s.rtt_nom_11   = 0;
}

static void setup_modereg_params1_2rank_1slot(bdk_lmcx_modereg_params1_t *modereg)
{
    modereg->u = 0;
    modereg->s.pasr_00      = 0;
    modereg->s.asr_00       = 0;
    modereg->s.srt_00       = 0;
    modereg->s.rtt_wr_00    = ddr4_rttwr_240ohm;
    modereg->s.dic_00       = ddr4_dic_34ohm;
    modereg->s.rtt_nom_00   = 0;
    modereg->s.pasr_01      = 0;
    modereg->s.asr_01       = 0;
    modereg->s.srt_01       = 0;
    modereg->s.rtt_wr_01    = ddr4_rttwr_240ohm;
    modereg->s.dic_01       = ddr4_dic_34ohm;
    modereg->s.rtt_nom_01   = 0;
    modereg->s.pasr_10      = 0;
    modereg->s.asr_10       = 0;
    modereg->s.srt_10       = 0;
    modereg->s.rtt_wr_10    = 0;
    modereg->s.dic_10       = ddr4_dic_34ohm;
    modereg->s.rtt_nom_10   = 0;
    modereg->s.pasr_11      = 0;
    modereg->s.asr_11       = 0;
    modereg->s.srt_11       = 0;
    modereg->s.rtt_wr_11    = 0;
    modereg->s.dic_11       = ddr4_dic_34ohm;
    modereg->s.rtt_nom_11   = 0;
}

static void setup_modereg_params1_2rank_2slot(bdk_lmcx_modereg_params1_t *modereg)
{
    modereg->u = 0;
    modereg->s.pasr_00      = 0;
    modereg->s.asr_00       = 0;
    modereg->s.srt_00       = 0;
    modereg->s.rtt_wr_00    = ddr4_rttwr_240ohm;
    modereg->s.dic_00       = ddr4_dic_34ohm;
    modereg->s.rtt_nom_00   = ddr4_rttnom_120ohm;
    modereg->s.pasr_01      = 0;
    modereg->s.asr_01       = 0;
    modereg->s.srt_01       = 0;
    modereg->s.rtt_wr_01    = ddr4_rttwr_240ohm;
    modereg->s.dic_01       = ddr4_dic_34ohm;
    modereg->s.rtt_nom_01   = ddr4_rttnom_120ohm;
    modereg->s.pasr_10      = 0;
    modereg->s.asr_10       = 0;
    modereg->s.srt_10       = 0;
    modereg->s.rtt_wr_10    = ddr4_rttwr_240ohm;
    modereg->s.dic_10       = ddr4_dic_34ohm;
    modereg->s.rtt_nom_10   = ddr4_rttnom_120ohm;
    modereg->s.pasr_11      = 0;
    modereg->s.asr_11       = 0;
    modereg->s.srt_11       = 0;
    modereg->s.rtt_wr_11    = ddr4_rttwr_240ohm;
    modereg->s.dic_11       = ddr4_dic_34ohm;
    modereg->s.rtt_nom_11   = ddr4_rttnom_120ohm;
}

static void setup_modereg_params1_4rank_1slot(bdk_lmcx_modereg_params1_t *modereg)
{
    modereg->u = 0;
    modereg->s.pasr_00      = 0;
    modereg->s.asr_00       = 0;
    modereg->s.srt_00       = 0;
    modereg->s.rtt_wr_00    = rttwr_60ohm;
    modereg->s.dic_00       = dic_34ohm;
    modereg->s.rtt_nom_00   = rttnom_20ohm;
    modereg->s.pasr_01      = 0;
    modereg->s.asr_01       = 0;
    modereg->s.srt_01       = 0;
    modereg->s.rtt_wr_01    = rttwr_60ohm;
    modereg->s.dic_01       = dic_34ohm;
    modereg->s.rtt_nom_01   = rttnom_none;
    modereg->s.pasr_10      = 0;
    modereg->s.asr_10       = 0;
    modereg->s.srt_10       = 0;
    modereg->s.rtt_wr_10    = rttwr_60ohm;
    modereg->s.dic_10       = dic_34ohm;
    modereg->s.rtt_nom_10   = rttnom_20ohm;
    modereg->s.pasr_11      = 0;
    modereg->s.asr_11       = 0;
    modereg->s.srt_11       = 0;
    modereg->s.rtt_wr_11    = rttwr_60ohm;
    modereg->s.dic_11       = dic_34ohm;
    modereg->s.rtt_nom_11   = rttnom_none;
}

static void setup_modereg_params2_1rank_1slot(bdk_lmcx_modereg_params2_t *modereg)
{
    modereg->u = 0;
    modereg->s.rtt_park_00    = ddr4_rttpark_40ohm;
    modereg->s.vref_value_00  = 0x22;
    modereg->s.vref_range_00  = 0;
    modereg->s.rtt_park_01    = 0;
    modereg->s.vref_value_01  = 0;
    modereg->s.vref_range_01  = 0;
    modereg->s.rtt_park_10    = 0;
    modereg->s.vref_value_10  = 0;
    modereg->s.vref_range_10  = 0;
    modereg->s.rtt_park_11    = 0;
    modereg->s.vref_value_11  = 0;
    modereg->s.vref_range_11  = 0;
}

static void setup_modereg_params2_1rank_2slot(bdk_lmcx_modereg_params2_t *modereg)
{
    modereg->u = 0;
    modereg->s.rtt_park_00    = ddr4_rttpark_34ohm;
    modereg->s.vref_value_00  = 0x1f;
    modereg->s.vref_range_00  = 0;
    modereg->s.rtt_park_01    = 0;
    modereg->s.vref_value_01  = 0;
    modereg->s.vref_range_01  = 0;
    modereg->s.rtt_park_10    = ddr4_rttpark_34ohm;
    modereg->s.vref_value_10  = 0x1f;
    modereg->s.vref_range_10  = 0;
    modereg->s.rtt_park_11    = 0;
    modereg->s.vref_value_11  = 0;
    modereg->s.vref_range_11  = 0;
}

static void setup_modereg_params2_2rank_1slot(bdk_lmcx_modereg_params2_t *modereg)
{
    modereg->u = 0;
    modereg->s.rtt_park_00    = ddr4_rttpark_40ohm;
    modereg->s.vref_value_00  = 0x19;
    modereg->s.vref_range_00  = 0;
    modereg->s.rtt_park_01    = ddr4_rttpark_40ohm;
    modereg->s.vref_value_01  = 0x19;
    modereg->s.vref_range_01  = 0;
    modereg->s.rtt_park_10    = 0;
    modereg->s.vref_value_10  = 0;
    modereg->s.vref_range_10  = 0;
    modereg->s.rtt_park_11    = 0;
    modereg->s.vref_value_11  = 0;
    modereg->s.vref_range_11  = 0;
}

static void setup_modereg_params2_2rank_2slot(bdk_lmcx_modereg_params2_t *modereg)
{
    modereg->u = 0;
    modereg->s.rtt_park_00    = ddr4_rttpark_80ohm;
    modereg->s.vref_value_00  = 0x19;
    modereg->s.vref_range_00  = 0;
    modereg->s.rtt_park_01    = ddr4_rttpark_80ohm;
    modereg->s.vref_value_01  = 0x19;
    modereg->s.vref_range_01  = 0;
    modereg->s.rtt_park_10    = ddr4_rttpark_80ohm;
    modereg->s.vref_value_10  = 0x19;
    modereg->s.vref_range_10  = 0;
    modereg->s.rtt_park_11    = ddr4_rttpark_80ohm;
    modereg->s.vref_value_11  = 0x19;
    modereg->s.vref_range_11  = 0;
}

static void setup_modereg_params2_4rank_1slot(bdk_lmcx_modereg_params2_t *modereg)
{
    modereg->u = 0;
    modereg->s.rtt_park_00    = ddr4_rttpark_80ohm;
    modereg->s.vref_value_00  = 0x1f;
    modereg->s.vref_range_00  = 0;
    modereg->s.rtt_park_01    = ddr4_rttpark_80ohm;
    modereg->s.vref_value_01  = 0x1f;
    modereg->s.vref_range_01  = 0;
    modereg->s.rtt_park_10    = 0;
    modereg->s.vref_value_10  = 0;
    modereg->s.vref_range_10  = 0;
    modereg->s.rtt_park_11    = 0;
    modereg->s.vref_value_11  = 0;
    modereg->s.vref_range_11  = 0;
}

static void setup_dram_odt_1rank_configuration(dimm_odt_config_t odt[4])
{
    int dimm = 0;
    odt[dimm].odt_ena = ddr4_dqx_driver_34_ohm; /* DQX_CTL */
    odt[dimm].odt_mask = 0x00000000ULL; /* WODT_MASK */
    setup_modereg_params1_1rank_1slot(&odt[dimm].odt_mask1); /* LMCX_MODEREG_PARAMS1 */
    setup_modereg_params2_1rank_1slot(&odt[dimm].odt_mask2); /* LMCX_MODEREG_PARAMS2 */
    odt[dimm].qs_dic = ddr4_rodt_ctl_48_ohm; /* RODT_CTL */
    odt[dimm].rodt_ctl = 0x00000000ULL; /* RODT_MASK */
    odt[dimm].dic = 0; /* Reserved */

    dimm = 1;
    odt[dimm].odt_ena = ddr4_dqx_driver_34_ohm; /* DQX_CTL */
    odt[dimm].odt_mask = 0x00000000ULL; /* WODT_MASK */
    setup_modereg_params1_1rank_2slot(&odt[dimm].odt_mask1); /* LMCX_MODEREG_PARAMS1 */
    setup_modereg_params2_1rank_2slot(&odt[dimm].odt_mask2); /* LMCX_MODEREG_PARAMS2 */
    odt[dimm].qs_dic = ddr4_rodt_ctl_48_ohm; /* RODT_CTL */
    odt[dimm].rodt_ctl = 0x00000000ULL; /* RODT_MASK */
    odt[dimm].dic = 0; /* Reserved */
}

static void setup_dram_odt_2rank_configuration(dimm_odt_config_t odt[4])
{
    int dimm = 0;
    odt[dimm].odt_ena = ddr4_dqx_driver_34_ohm; /* DQX_CTL */
    odt[dimm].odt_mask = 0x00000000ULL; /* WODT_MASK */
    setup_modereg_params1_2rank_1slot(&odt[dimm].odt_mask1); /* LMCX_MODEREG_PARAMS1 */
    setup_modereg_params2_2rank_1slot(&odt[dimm].odt_mask2); /* LMCX_MODEREG_PARAMS2 */
    odt[dimm].qs_dic = ddr4_rodt_ctl_80_ohm; /* RODT_CTL */
    odt[dimm].rodt_ctl = 0x00000000ULL; /* RODT_MASK */
    odt[dimm].dic = 0; /* Reserved */

    dimm = 1;
    odt[dimm].odt_ena = ddr4_dqx_driver_34_ohm; /* DQX_CTL */
    odt[dimm].odt_mask = 0x00000102ULL; /* WODT_MASK */
    setup_modereg_params1_2rank_2slot(&odt[dimm].odt_mask1); /* LMCX_MODEREG_PARAMS1 */
    setup_modereg_params2_2rank_2slot(&odt[dimm].odt_mask2); /* LMCX_MODEREG_PARAMS2 */
    odt[dimm].qs_dic = ddr4_rodt_ctl_48_ohm; /* RODT_CTL */
    odt[dimm].rodt_ctl = 0x04080102ULL; /* RODT_MASK */
    odt[dimm].dic = 0; /* Reserved */
}

static void setup_dram_odt_4rank_configuration(dimm_odt_config_t odt[4])
{
    int dimm = 0;
    odt[dimm].odt_ena = ddr4_dqx_driver_34_ohm; /* DQX_CTL */
    odt[dimm].odt_mask = 0x01030203ULL; /* WODT_MASK */
    setup_modereg_params1_4rank_1slot(&odt[dimm].odt_mask1); /* LMCX_MODEREG_PARAMS1 */
    setup_modereg_params2_4rank_1slot(&odt[dimm].odt_mask2); /* LMCX_MODEREG_PARAMS2 */
    odt[dimm].qs_dic = ddr4_rodt_ctl_48_ohm; /* RODT_CTL */
    odt[dimm].rodt_ctl = 0x01010202ULL; /* RODT_MASK */
    odt[dimm].dic = 0; /* Reserved */
}

static int8_t dll_read_offset  [9]      = {0, 0, 0, 0, 0, 0, 0, 0, 0};
static int8_t dll_write_offset [9]      = {0, 0, 0, 0, 0, 0, 0, 0, 0};

static void setup_dram_custom_lmc_config(ddr3_custom_config_t *cfg)
{
    cfg->min_rtt_nom_idx        = 1;
    cfg->max_rtt_nom_idx        = 7;
    cfg->min_rodt_ctl           = 1;
    cfg->max_rodt_ctl           = 7;
    cfg->ck_ctl                 = ddr4_driver_34_ohm;
    cfg->cmd_ctl                = ddr4_driver_34_ohm;
    cfg->ctl_ctl                = ddr4_driver_34_ohm;
    cfg->min_cas_latency        = 0;
    cfg->offset_en              = 1;
    cfg->offset_udimm           = 2;
    cfg->offset_rdimm           = 2;
    cfg->ddr_rtt_nom_auto       = 0;
    cfg->ddr_rodt_ctl_auto      = 0;
    cfg->rlevel_comp_offset_udimm       = 0;
    cfg->rlevel_comp_offset_rdimm       = 0;
    cfg->rlevel_compute         = 0;
    cfg->ddr2t_udimm            = 1;
    cfg->ddr2t_rdimm            = 1;
    cfg->maximum_adjacent_rlevel_delay_increment = 2;
    cfg->fprch2                 = 2;
    cfg->dll_write_offset       = dll_write_offset;
    cfg->dll_read_offset        = dll_read_offset;
    cfg->parity                 = 0;
    cfg->rlevel_table		= 0; /* Initialized later */
}

static const dram_config_t *dram_get_config_crb_2s_by_node(bdk_node_t node)
{
    static dram_config_t cfg[2];

    /* Make all fields for the node default to zero */
    memset(&cfg[node], 0, sizeof(dram_config_t));

    /* Set the config name and the default frequency */
    cfg[node].name = DEFAULT_NAME;
    cfg[node].ddr_clock_hertz = DEFAULT_SPEED;

    /* Load the defaults for DIMMs on all four controllers */
    for (int lmc = 0; lmc < 4; lmc++)
    {
        setup_dram_custom_lmc_config(&cfg[node].config[lmc].custom_lmc_config);

        if (node == 0)
            cfg[node].config[lmc].custom_lmc_config.rlevel_table = rlevel_rank_values_node0;
        else
            cfg[node].config[lmc].custom_lmc_config.rlevel_table = rlevel_rank_values_node1;

        setup_dram_odt_1rank_configuration(cfg[node].config[lmc].odt_1rank_config);
        setup_dram_odt_2rank_configuration(cfg[node].config[lmc].odt_2rank_config);
        setup_dram_odt_4rank_configuration(cfg[node].config[lmc].odt_4rank_config);
    }

    if (USE_INTERNAL_SPD || bdk_is_platform(BDK_PLATFORM_ASIM))
    {
	int lmc_mask  = DEFAULT_LMC_MASK;
        int dimm_mask = DEFAULT_DIMM_MASK;
	for (int lmc = 0; lmc < 4; lmc++)
        {
            if (! (lmc_mask & (1 << lmc))) /* Could use the testbit macro */
                continue;

            for (int dimm = 0; dimm < 2; dimm++)
            {
                if (! (dimm_mask & (1 << dimm))) /* Could use the testbit macro */
                    continue;

                cfg[node].config[lmc].dimm_config_table[dimm].spd_ptrs[0] = DEFAULT_INTERNAL_SPD;
            }
        }
    }
    else
    {
        /* Set the SPD addresses as we are reading them from DIMMs */
        cfg[node].config[0].dimm_config_table[0].spd_addrs[0] = 0x2050;
        cfg[node].config[1].dimm_config_table[0].spd_addrs[0] = 0x2051;
        cfg[node].config[2].dimm_config_table[0].spd_addrs[0] = 0x2052;
        cfg[node].config[3].dimm_config_table[0].spd_addrs[0] = 0x2053;
    }

    return &cfg[node];
};

const dram_config_t *dram_get_config_crb_2s(void)
{
    return (dram_get_config_crb_2s_by_node(0));
}

const dram_config_t *dram_get_config_crb_2s_node0(void)
{
    return (dram_get_config_crb_2s_by_node(0));
}

const dram_config_t *dram_get_config_crb_2s_node1(void)
{
    return (dram_get_config_crb_2s_by_node(1));
}


