/*******************************************************************************
Copyright (C) 2016 Marvell International Ltd.

Marvell BSD License Option

If you received this File from Marvell, you may opt to use, redistribute and/or
modify this File under the following licensing terms.
Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.

* Neither the name of Marvell nor the names of its contributors may be
  used to endorse or promote products derived from this software without
  specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*******************************************************************************/

#include "../../../MdeModulePkg/Bus/Pci/SdMmcPciHcDxe/SdMmcPciHcDxe.h"

#include <Library/IoLib.h>

#define SD_BAR_INDEX 0

/* Register Offset of SD Host Controller SOCP self-defined register */

#define SDHC_IPID                     0x0100
#define SDHC_SYS_CFG_INFO             0x0104
#define SLOT_TYPE_SDIO_SHIFT          24
#define SLOT_TYPE_EMMC_MASK           0xff
#define SLOT_TYPE_EMMC_SHIFT          16
#define SLOT_TYPE_SD_SDIO_MMC_MASK    0xff
#define SLOT_TYPE_SD_SDIO_MMC_SHIFT   8

#define SDHC_SYS_OP_CTRL              0x0108
#define AUTO_CLKGATE_DISABLE_MASK     (0x1<<20)
#define SDCLK_IDLEOFF_ENABLE_SHIFT    8
#define SLOT_ENABLE_SHIFT             0

#define SDHC_SYS_EXT_OP_CTRL          0x010c
#define SDHC_TEST_OUT                 0x0110
#define SDHC_TESTOUT_MUXSEL           0x0114

#define SDHC_SLOT_EXT_INT_STATUS      0x0120
#define SDHC_SLOT_EXT_ERR_STATUS      0x0122
#define SDHC_SLOT_EXT_INT_STATUS_EN   0x0124
#define SDHC_SLOT_EXT_ERR_STATUS_EN   0x0126

#define SDHC_SLOT_OP_STATUS_CTRL      0x0128
#define TUNING_PROG_FIXED_DELAY_MASK  0x7ff
#define FORCE_SEL_INVERSE_CLK_SHIFT   11

#define SDHC_SLOT_FIFO_CTRL           0x012c

#define SDHC_SLOT_eMMC_CTRL           0x0130
#define ENABLE_DATA_STROBE_SHIFT      24
#define SET_EMMC_RSTN_SHIFT           16
#define eMMC_VCCQ_MASK                0x3
#define eMMC_VCCQ_1_8V                0x1
#define eMMC_VCCQ_1_2V                0x2
#define eMMC_VCCQ_3_3V                0x3

#define SDHC_SLOT_OUTPUT_DLY_CTRL     0x0134
#define SDHC_SLOT_DCM_CTRL            0x0137

#define SDHC_SLOT_DLL_CTRL            0x0138
#define SELECT_DEF_DLL                0x1

#define SDHC_SLOT_DLL_PHASE_SEL       0x013c
#define DLL_UPDATE_STROBE             7

#define SDHC_SLOT_STROBE_DLY_CTRL     0x0140
#define STROBE_DELAY_FIXED_MASK       0xffff

#define SDHC_SLOT_RETUNING_REQ_CTRL   0x0144
#define RETUNING_COMPATIBLE           0x1

#define SDHC_SLOT_AUTO_RETUNING_CTRL  0x0148
#define ENABLE_AUTO_RETUNING          0x1

#define SDHC_SLOT_EXT_PRESENT_STATE   0x014c
#define SDHC_SLOT_DLL_CUR_DLY_VAL     0x0150
#define SDHC_SLOT_TUNING_CUR_DLY_VAL  0x0154
#define SDHC_SLOT_STROBE_CUR_DLY_VAL  0x0158
#define SDHC_SLOT_SUB_CMD_STRL        0x015c

#define SDHC_SLOT_CQ_TASK_INFO        0x0160

#define SDHC_SLOT_TUNING_DEBUG_INFO   0x01f0
#define SDHC_SLOT_DATAIN_DEBUG_INFO   0x01f4

#define XENON_MMC_MAX_CLK             400000000
#define XENON_MMC_CLK_RATIO           2046
#define XENON_MMC_BASE_CLK            XENON_MMC_MAX_CLK / XENON_MMC_CLK_RATIO

#define XENON_MMC_CMD_MAX_TIMEOUT     3200
#define XENON_MMC_CMD_DEFAULT_TIMEOUT 100

/* Tuning Parameter */
#define TMR_RETUN_NO_PRESENT          0xf
#define XENON_MAX_TUN_COUNT           0xb

#define EMMC_PHY_REG_BASE                 0x170
#define EMMC_PHY_TIMING_ADJUST            EMMC_PHY_REG_BASE
#define OUTPUT_QSN_PHASE_SELECT           (1 << 17)
#define SAMPL_INV_QSP_PHASE_SELECT        (1 << 18)
#define SAMPL_INV_QSP_PHASE_SELECT_SHIFT  18
#define PHY_INITIALIZAION                 (1 << 31)
#define WAIT_CYCLE_BEFORE_USING_MASK      0xf
#define WAIT_CYCLE_BEFORE_USING_SHIFT     12
#define FC_SYNC_EN_DURATION_MASK          0xf
#define FC_SYNC_EN_DURATION_SHIFT         8
#define FC_SYNC_RST_EN_DURATION_MASK      0xf
#define FC_SYNC_RST_EN_DURATION_SHIFT     4
#define FC_SYNC_RST_DURATION_MASK         0xf
#define FC_SYNC_RST_DURATION_SHIFT        0

#define EMMC_PHY_FUNC_CONTROL     (EMMC_PHY_REG_BASE + 0x4)
#define DQ_ASYNC_MODE             (1 << 4)
#define DQ_DDR_MODE_SHIFT         8
#define DQ_DDR_MODE_MASK          0xff
#define CMD_DDR_MODE              (1 << 16)

#define EMMC_PHY_PAD_CONTROL      (EMMC_PHY_REG_BASE + 0x8)
#define REC_EN_SHIFT              24
#define REC_EN_MASK               0xf
#define FC_DQ_RECEN               (1 << 24)
#define FC_CMD_RECEN              (1 << 25)
#define FC_QSP_RECEN              (1 << 26)
#define FC_QSN_RECEN              (1 << 27)
#define OEN_QSN                   (1 << 28)
#define AUTO_RECEN_CTRL           (1 << 30)

#define EMMC_PHY_PAD_CONTROL1        (EMMC_PHY_REG_BASE + 0xc)
#define EMMC_PHY_PAD_CONTROL2        (EMMC_PHY_REG_BASE + 0x10)
#define EMMC_PHY_DLL_CONTROL         (EMMC_PHY_REG_BASE + 0x14)
#define DLL_DELAY_TEST_LOWER_SHIFT   8
#define DLL_DELAY_TEST_LOWER_MASK    0xff
#define DLL_BYPASS_EN                0x1

#define EMMC_LOGIC_TIMING_ADJUST       (EMMC_PHY_REG_BASE + 0x18)
#define EMMC_LOGIC_TIMING_ADJUST_LOW   (EMMC_PHY_REG_BASE + 0x1c)

#define MVEBU_IP_CONFIG_REG            (0xf0000000 + 0x6F4100)

#define LOGIC_TIMING_VALUE             0x5a54 /* Recommend by HW team */

/* Hyperion only have one slot 0 */
#define XENON_MMC_SLOT_ID_HYPERION    (0)

#define MMC_TIMING_LEGACY     0
#define MMC_TIMING_MMC_HS     1
#define MMC_TIMING_SD_HS      2
#define MMC_TIMING_UHS_SDR12  3
#define MMC_TIMING_UHS_SDR25  4
#define MMC_TIMING_UHS_SDR50  5
#define MMC_TIMING_UHS_SDR104 6
#define MMC_TIMING_UHS_DDR50  7
#define MMC_TIMING_MMC_HS200  8
#define MMC_TIMING_MMC_HS400  10

/* Data time out default value 0xE: TMCLK x 227 */
#define DATA_TIMEOUT_DEF_VAL  0xe

/* SDMA start address should allign with 0x8, align mask 0x7 */
#define DMA_START_ADDR_ALIGN_MASK 0x7

#define  SDHCI_RETUNE_EVT_INTSIG  0x00001000

/* MMC modes */
#define XENON_MMC_MODE_EMMC     0
#define XENON_MMC_MODE_SD_SDIO  1

/* MMC Voltage */
#define MMC_VDD_165_195   0x00000080  /* VDD voltage 1.65 - 1.95 */
#define MMC_VDD_20_21     0x00000100  /* VDD voltage 2.0 ~ 2.1 */
#define MMC_VDD_21_22     0x00000200  /* VDD voltage 2.1 ~ 2.2 */
#define MMC_VDD_22_23     0x00000400  /* VDD voltage 2.2 ~ 2.3 */
#define MMC_VDD_23_24     0x00000800  /* VDD voltage 2.3 ~ 2.4 */
#define MMC_VDD_24_25     0x00001000  /* VDD voltage 2.4 ~ 2.5 */
#define MMC_VDD_25_26     0x00002000  /* VDD voltage 2.5 ~ 2.6 */
#define MMC_VDD_26_27     0x00004000  /* VDD voltage 2.6 ~ 2.7 */
#define MMC_VDD_27_28     0x00008000  /* VDD voltage 2.7 ~ 2.8 */
#define MMC_VDD_28_29     0x00010000  /* VDD voltage 2.8 ~ 2.9 */
#define MMC_VDD_29_30     0x00020000  /* VDD voltage 2.9 ~ 3.0 */
#define MMC_VDD_30_31     0x00040000  /* VDD voltage 3.0 ~ 3.1 */
#define MMC_VDD_31_32     0x00080000  /* VDD voltage 3.1 ~ 3.2 */
#define MMC_VDD_32_33     0x00100000  /* VDD voltage 3.2 ~ 3.3 */
#define MMC_VDD_33_34     0x00200000  /* VDD voltage 3.3 ~ 3.4 */
#define MMC_VDD_34_35     0x00400000  /* VDD voltage 3.4 ~ 3.5 */
#define MMC_VDD_35_36     0x00800000  /* VDD voltage 3.5 ~ 3.6 */

/* SDHCI FLAGS */
#define SDHCI_POWER_ON   0x01
#define SDHCI_POWER_180  0x0A
#define SDHCI_POWER_300  0x0C
#define SDHCI_POWER_330  0x0E

#define SDHCI_DIVIDER_SHIFT     8
#define SDHCI_DIVIDER_HI_SHIFT  6
#define SDHCI_DIV_MASK          0xFF
#define SDHCI_DIV_MASK_LEN      8
#define SDHCI_DIV_HI_MASK       0x300
#define SDHCI_CLOCK_CARD_EN     0x0004
#define SDHCI_CLOCK_INT_STABLE  0x0002
#define SDHCI_CLOCK_INT_EN      0x0001

#define SDHCI_VENDOR_VER_MASK   0xFF00
#define SDHCI_VENDOR_VER_SHIFT  8
#define SDHCI_SPEC_VER_MASK     0x00FF
#define SDHCI_SPEC_VER_SHIFT    0
#define SDHCI_SPEC_100          0
#define SDHCI_SPEC_200          1
#define SDHCI_SPEC_300          2

#define SDHCI_SIGNAL_ENABLE     0x38

#define SDHCI_MAX_DIV_SPEC_200  256
#define SDHCI_MAX_DIV_SPEC_300  2046

UINTN
XenonSetClk (
  IN EFI_PCI_IO_PROTOCOL   *PciIo,
  IN SD_MMC_HC_PRIVATE_DATA *Private,
  IN UINT32 Clock
  );

VOID
XenonPhyInit (
  IN EFI_PCI_IO_PROTOCOL   *PciIo
  );

VOID
XenonReset (
  IN SD_MMC_HC_PRIVATE_DATA *Private,
  IN UINT8 Slot,
  IN UINT8 Mask
  );

EFI_STATUS
XenonTransferData (
  IN SD_MMC_HC_PRIVATE_DATA *Private,
  IN UINT8 Slot,
  IN OUT VOID *Buffer,
  IN UINT32 DataLen,
  IN UINT16 BlockSize,
  IN UINT16 Blocks,
  IN BOOLEAN Read
  );

EFI_STATUS
XenonInit (
  IN SD_MMC_HC_PRIVATE_DATA *Private
  );

EFI_STATUS
SdCardSendStatus (
  IN  EFI_SD_MMC_PASS_THRU_PROTOCOL  *PassThru,
  IN  UINT8                          Slot,
  IN  UINT16                         Rca,
  OUT UINT32                         *DevStatus
  );
