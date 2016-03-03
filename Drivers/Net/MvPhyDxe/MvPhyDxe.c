/********************************************************************************
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

#include <Protocol/DriverBinding.h>
#include <Protocol/Phy.h>
#include <Protocol/Mdio.h>

#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/IoLib.h>
#include <Library/DebugLib.h>
#include <Library/PcdLib.h>
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>

#define MII_BMCR      0x00  /* Basic mode control Register */
#define MII_BMSR      0x01  /* Basic mode status Register  */
#define MII_PHYSID1      0x02  /* PHYS ID 1           */
#define MII_PHYSID2      0x03  /* PHYS ID 2           */
#define MII_ADVERTISE      0x04  /* Advertisement control Reg   */
#define MII_LPA        0x05  /* Link partner ability Reg    */
#define MII_EXPANSION      0x06  /* Expansion Register         */
#define MII_CTRL1000      0x09  /* 1000BASE-T control         */
#define MII_STAT1000      0x0a  /* 1000BASE-T status         */
#define MII_ESTATUS      0x0f  /* Extended Status */
#define MII_DCOUNTER      0x12  /* Disconnect counter         */
#define MII_FCSCOUNTER      0x13  /* False carrier counter       */
#define MII_NWAYTEST      0x14  /* N-way auto-neg test Reg     */
#define MII_RERRCOUNTER     0x15  /* Receive error counter       */
#define MII_SREVISION      0x16  /* Silicon revision         */
#define MII_RESV1      0x17  /* Reserved...           */
#define MII_LBRERROR      0x18  /* Lpback, rx, bypass error    */
#define MII_PHYADDR      0x19  /* PHY address           */
#define MII_RESV2      0x1a  /* Reserved...           */
#define MII_TPISTATUS      0x1b  /* TPI status for 10mbps       */
#define MII_NCONFIG      0x1c  /* Network interface config    */

/* Basic mode control Register. */
#define BMCR_RESV    0x003f  /* Unused...           */
#define BMCR_SPEED1000    0x0040  /* MSB of Speed (1000)         */
#define BMCR_CTST    0x0080  /* Collision test         */
#define BMCR_FULLDPLX    0x0100  /* Full duplex           */
#define BMCR_ANRESTART    0x0200  /* Auto negotiation restart    */
#define BMCR_ISOLATE    0x0400  /* Disconnect DP83840 from MII */
#define BMCR_PDOWN    0x0800  /* Powerdown the DP83840       */
#define BMCR_ANENABLE    0x1000  /* Enable auto negotiation     */
#define BMCR_SPEED100    0x2000  /* Select 100Mbps         */
#define BMCR_LOOPBACK    0x4000  /* TXD loopback bits         */
#define BMCR_RESET    0x8000  /* Reset the DP83840         */

/* Basic mode status Register. */
#define BMSR_ERCAP		0x0001	/* Ext-Reg capability	       */
#define BMSR_JCD		0x0002	/* Jabber detected	       */
#define BMSR_LSTATUS		0x0004	/* Link status		       */
#define BMSR_ANEGCAPABLE	0x0008	/* Able to do auto-negotiation */
#define BMSR_RFAULT		0x0010	/* Remote fault detected       */
#define BMSR_ANEGCOMPLETE	0x0020	/* Auto-negotiation complete   */
#define BMSR_RESV		0x00c0	/* Unused...		       */
#define BMSR_ESTATEN		0x0100	/* Extended Status in R15 */
#define BMSR_100HALF2		0x0200	/* Can do 100BASE-T2 HDX */
#define BMSR_100FULL2		0x0400	/* Can do 100BASE-T2 FDX */
#define BMSR_10HALF		0x0800	/* Can do 10mbps, half-duplex  */
#define BMSR_10FULL		0x1000	/* Can do 10mbps, full-duplex  */
#define BMSR_100HALF		0x2000	/* Can do 100mbps, half-duplex */
#define BMSR_100FULL		0x4000	/* Can do 100mbps, full-duplex */
#define BMSR_100BASE4		0x8000	/* Can do 100mbps, 4k packets  */

#define PHY_ANEG_TIMEOUT 4000

#define PHY_INTERFACE_MODE_RGMII 0
#define PHY_INTERFACE_MODE_RGMII_ID 1
#define PHY_INTERFACE_MODE_RGMII_RXID 2
#define PHY_INTERFACE_MODE_RGMII_TXID 3
#define PHY_INTERFACE_MODE_SGMII 4
#define PHY_INTERFACE_MODE_RTBI 5

#define PHY_AUTONEGOTIATE_TIMEOUT 5000

/* 88E1011 PHY Status Register */
#define MIIM_88E1xxx_PHY_STATUS    0x11
#define MIIM_88E1xxx_PHYSTAT_SPEED  0xc000
#define MIIM_88E1xxx_PHYSTAT_GBIT  0x8000
#define MIIM_88E1xxx_PHYSTAT_100  0x4000
#define MIIM_88E1xxx_PHYSTAT_DUPLEX  0x2000
#define MIIM_88E1xxx_PHYSTAT_SPDDONE  0x0800
#define MIIM_88E1xxx_PHYSTAT_LINK  0x0400

#define MIIM_88E1xxx_PHY_SCR    0x10
#define MIIM_88E1xxx_PHY_MDI_X_AUTO  0x0060

/* 88E1111 PHY LED Control Register */
#define MIIM_88E1111_PHY_LED_CONTROL  24
#define MIIM_88E1111_PHY_LED_DIRECT  0x4100
#define MIIM_88E1111_PHY_LED_COMBINE  0x411C

/* 88E1111 Extended PHY Specific Control Register */
#define MIIM_88E1111_PHY_EXT_CR    0x14
#define MIIM_88E1111_RX_DELAY    0x80
#define MIIM_88E1111_TX_DELAY    0x2

/* 88E1111 Extended PHY Specific Status Register */
#define MIIM_88E1111_PHY_EXT_SR    0x1b
#define MIIM_88E1111_HWCFG_MODE_MASK    0xf
#define MIIM_88E1111_HWCFG_MODE_COPPER_RGMII  0xb
#define MIIM_88E1111_HWCFG_MODE_FIBER_RGMII  0x3
#define MIIM_88E1111_HWCFG_MODE_SGMII_NO_CLK  0x4
#define MIIM_88E1111_HWCFG_MODE_COPPER_RTBI  0x9
#define MIIM_88E1111_HWCFG_FIBER_COPPER_AUTO  0x8000
#define MIIM_88E1111_HWCFG_FIBER_COPPER_RES  0x2000

#define MIIM_88E1111_COPPER    0
#define MIIM_88E1111_FIBER    1

/* 88E1118 PHY defines */
#define MIIM_88E1118_PHY_PAGE    22
#define MIIM_88E1118_PHY_LED_PAGE  3

/* 88E1121 PHY LED Control Register */
#define MIIM_88E1121_PHY_LED_CTRL  16
#define MIIM_88E1121_PHY_LED_PAGE  3
#define MIIM_88E1121_PHY_LED_DEF  0x0030

/* 88E1121 PHY IRQ Enable/Status Register */
#define MIIM_88E1121_PHY_IRQ_EN    18
#define MIIM_88E1121_PHY_IRQ_STATUS  19

#define MIIM_88E1121_PHY_PAGE    22

/* 88E1145 Extended PHY Specific Control Register */
#define MIIM_88E1145_PHY_EXT_CR 20
#define MIIM_M88E1145_RGMII_RX_DELAY  0x0080
#define MIIM_M88E1145_RGMII_TX_DELAY  0x0002

#define MIIM_88E1145_PHY_LED_CONTROL  24
#define MIIM_88E1145_PHY_LED_DIRECT  0x4100

#define MIIM_88E1145_PHY_PAGE  29
#define MIIM_88E1145_PHY_CAL_OV 30

#define MIIM_88E1149_PHY_PAGE  29

/* 88E1310 PHY defines */
#define MIIM_88E1310_PHY_LED_CTRL  16
#define MIIM_88E1310_PHY_IRQ_EN    18
#define MIIM_88E1310_PHY_RGMII_CTRL  21
#define MIIM_88E1310_PHY_PAGE    22

UINTN PhyMode;
EFI_MDIO_PROTOCOL *Mdio;

EFI_STATUS
MvPhyStatus (
  IN CONST EFI_PHY_PROTOCOL *This,
  IN PHY_DEVICE	*PhyDev
  );

EFI_STATUS
MvPhyReset (
  IN UINT32 PhyAddr
  )
{
  UINT32 Reg = 0;
  INTN timeout = 500;

  Reg = Mdio->Read(Mdio, PhyAddr, MII_BMCR);
  Reg |= BMCR_RESET;
  Mdio->Write(Mdio, PhyAddr, MII_BMCR, Reg);

  /*
   * Poll the control Register for the reset bit to go to 0 (it is
   * auto-clearing).  This should happen within 0.5 seconds per the
   * IEEE spec.
   */
  while ((Reg & BMCR_RESET) && timeout--) {
    Reg = Mdio->Read(Mdio, PhyAddr, MII_BMCR);

    gBS->Stall(1000);
  }

  if (Reg & BMCR_RESET) {
    DEBUG((DEBUG_ERROR, "PHY reset timed out\n"));
    return EFI_TIMEOUT;
  }

  return EFI_SUCCESS;
}

/* Marvell 88E1111S */
EFI_STATUS
MvPhyM88e1111sConfig (
  IN PHY_DEVICE *PhyDev 
  )
{
  UINT32 Reg;

  if ((PhyDev->Connection == PHY_INTERFACE_MODE_RGMII) ||
      (PhyDev->Connection == PHY_INTERFACE_MODE_RGMII_ID) ||
      (PhyDev->Connection == PHY_INTERFACE_MODE_RGMII_RXID) ||
      (PhyDev->Connection == PHY_INTERFACE_MODE_RGMII_TXID)) {
    Reg = Mdio->Read(Mdio, PhyDev->Addr,
      MIIM_88E1111_PHY_EXT_CR);
    if ((PhyDev->Connection == PHY_INTERFACE_MODE_RGMII) ||
      (PhyDev->Connection == PHY_INTERFACE_MODE_RGMII_ID)) {
      Reg |= (MIIM_88E1111_RX_DELAY | MIIM_88E1111_TX_DELAY);
    } else if (PhyDev->Connection == PHY_INTERFACE_MODE_RGMII_RXID) {
      Reg &= ~MIIM_88E1111_TX_DELAY;
      Reg |= MIIM_88E1111_RX_DELAY;
    } else if (PhyDev->Connection == PHY_INTERFACE_MODE_RGMII_TXID) {
      Reg &= ~MIIM_88E1111_RX_DELAY;
      Reg |= MIIM_88E1111_TX_DELAY;
    }

    Mdio->Write(Mdio, PhyDev->Addr,
      MIIM_88E1111_PHY_EXT_CR, Reg);

    Reg = Mdio->Read(Mdio, PhyDev->Addr,
      MIIM_88E1111_PHY_EXT_SR);

    Reg &= ~(MIIM_88E1111_HWCFG_MODE_MASK);

    if (Reg & MIIM_88E1111_HWCFG_FIBER_COPPER_RES)
      Reg |= MIIM_88E1111_HWCFG_MODE_FIBER_RGMII;
    else
      Reg |= MIIM_88E1111_HWCFG_MODE_COPPER_RGMII;

    Mdio->Write(Mdio, PhyDev->Addr,
      MIIM_88E1111_PHY_EXT_SR, Reg);
  }

  if (PhyDev->Connection == PHY_INTERFACE_MODE_SGMII) {
    Reg = Mdio->Read(Mdio, PhyDev->Addr,
      MIIM_88E1111_PHY_EXT_SR);

    Reg &= ~(MIIM_88E1111_HWCFG_MODE_MASK);
    Reg |= MIIM_88E1111_HWCFG_MODE_SGMII_NO_CLK;
    Reg |= MIIM_88E1111_HWCFG_FIBER_COPPER_AUTO;

    Mdio->Write(Mdio, PhyDev->Addr, 
      MIIM_88E1111_PHY_EXT_SR, Reg);
  }

  if (PhyDev->Connection == PHY_INTERFACE_MODE_RTBI) {
    Reg = Mdio->Read(Mdio, PhyDev->Addr,
      MIIM_88E1111_PHY_EXT_CR);
    Reg |= (MIIM_88E1111_RX_DELAY | MIIM_88E1111_TX_DELAY);
    Mdio->Write(Mdio, PhyDev->Addr,
      MIIM_88E1111_PHY_EXT_CR, Reg);

    Reg = Mdio->Read(Mdio, PhyDev->Addr, 
      MIIM_88E1111_PHY_EXT_SR);
    Reg &= ~(MIIM_88E1111_HWCFG_MODE_MASK |
      MIIM_88E1111_HWCFG_FIBER_COPPER_RES);
    Reg |= 0x7 | MIIM_88E1111_HWCFG_FIBER_COPPER_AUTO;
    Mdio->Write(Mdio, PhyDev->Addr, 
      MIIM_88E1111_PHY_EXT_SR, Reg);

    /* soft reset */
    MvPhyReset(PhyDev->Addr);

    Reg = Mdio->Read(Mdio, PhyDev->Addr, 
      MIIM_88E1111_PHY_EXT_SR);
    Reg &= ~(MIIM_88E1111_HWCFG_MODE_MASK |
      MIIM_88E1111_HWCFG_FIBER_COPPER_RES);
    Reg |= MIIM_88E1111_HWCFG_MODE_COPPER_RTBI |
      MIIM_88E1111_HWCFG_FIBER_COPPER_AUTO;
    Mdio->Write(Mdio, PhyDev->Addr, 
      MIIM_88E1111_PHY_EXT_SR, Reg);
  }

  /* soft reset */
  MvPhyReset(PhyDev->Addr);

  MvPhyReset(PhyDev->Addr);

  return EFI_SUCCESS;
}

EFI_STATUS
MvPhyParseStatus (
  IN PHY_DEVICE *PhyDev 
  )
{
  UINT32 Data;
  UINT32 Speed;

  Data = Mdio->Read(Mdio, PhyDev->Addr, MIIM_88E1xxx_PHY_STATUS);

  if ((Data & MIIM_88E1xxx_PHYSTAT_LINK) &&
    !(Data & MIIM_88E1xxx_PHYSTAT_SPDDONE)) {
    INTN i = 0;

    DEBUG((DEBUG_ERROR,"Waiting for PHY realtime link"));
    while (!(Data & MIIM_88E1xxx_PHYSTAT_SPDDONE)) {
      if (i > PHY_AUTONEGOTIATE_TIMEOUT) {
        DEBUG((DEBUG_ERROR," TIMEOUT !\n"));
	PhyDev->LinkUp = FALSE;
        break;
      }

      if ((i++ % 1000) == 0)
        DEBUG((DEBUG_ERROR, "."));
      gBS->Stall(1000);
      Data = Mdio->Read(Mdio, PhyDev->Addr, 
          MIIM_88E1xxx_PHY_STATUS);
    }
    DEBUG((DEBUG_ERROR," done\n"));
    gBS->Stall(500000);
  } else {
    if (Data & MIIM_88E1xxx_PHYSTAT_LINK) {
      DEBUG((DEBUG_ERROR, "link up\n"));
      PhyDev->LinkUp = TRUE;
    } else {
      DEBUG((DEBUG_ERROR, "link down\n"));
      PhyDev->LinkUp = FALSE;
    }
  }

  if (Data & MIIM_88E1xxx_PHYSTAT_DUPLEX) {
    DEBUG((DEBUG_ERROR, "duplex\n"));
    PhyDev->Duplex = TRUE;
  } else {
    DEBUG((DEBUG_ERROR, "no duplex\n"));
    PhyDev->Duplex = FALSE;
  }

  Speed = Data & MIIM_88E1xxx_PHYSTAT_SPEED;

  switch (Speed) {
  case MIIM_88E1xxx_PHYSTAT_GBIT:
    DEBUG((DEBUG_ERROR, "Speed 1000\n"));
    PhyDev->Speed = SPEED_1000;
    break;
  case MIIM_88E1xxx_PHYSTAT_100:
    DEBUG((DEBUG_ERROR, "Speed 100\n"));
    PhyDev->Speed = SPEED_100;
    break;
  default:
    DEBUG((DEBUG_ERROR, "Speed 10\n"));
    PhyDev->Speed = SPEED_10;
    break;
  }

  return 0;
}
EFI_STATUS
MvPhyInit (
  IN CONST EFI_PHY_PROTOCOL *Snp,
  IN UINT32 PhyAddr,
  IN OUT PHY_DEVICE **OutPhyDev
  )
{
  EFI_STATUS Status;
  DEBUG((DEBUG_ERROR, "MvPhyInit\n"));
  PHY_DEVICE *PhyDev;
  UINT32 Data;
  INTN i;

  Status = gBS->LocateProtocol (
      &gEfiMdioProtocolGuid,
      NULL,
      (VOID **) &Mdio
      );
  if (EFI_ERROR(Status))
    return Status;

  PhyDev = AllocateZeroPool (sizeof (PHY_DEVICE));
  PhyDev->Addr = PhyAddr;
  DEBUG((DEBUG_ERROR, "PhyAddr is %d\n", PhyAddr));
  PhyDev->Connection = PHY_CONNECTION_RGMII;
  *OutPhyDev = PhyDev;

  MvPhyM88e1111sConfig (PhyDev);

  Data = Mdio->Read(Mdio, PhyAddr, MII_BMSR);

  if ((Data & BMSR_ANEGCAPABLE) && !(Data & BMSR_ANEGCOMPLETE)) {

    DEBUG((DEBUG_ERROR, "Waiting for PHY auto negotiation... "));
    for (i = 0; !(Data & BMSR_ANEGCOMPLETE); i++) {
      if (i > PHY_ANEG_TIMEOUT) {
	DEBUG((DEBUG_ERROR, " timeout\n"));
	PhyDev->LinkUp = FALSE;
        return EFI_TIMEOUT;
      }

      gBS->Stall(1000);  /* 1 ms */
      Data = Mdio->Read(Mdio, PhyAddr, MII_BMSR);
    }
    PhyDev->LinkUp = TRUE;
 //   DEBUG((DEBUG_ERROR, "MvPhyStatus: link up\n"));
  } else {
    Data = Mdio->Read(Mdio, PhyAddr, MII_BMSR);

    if (Data & BMSR_LSTATUS) {
      PhyDev->LinkUp = TRUE;
  //    DEBUG((DEBUG_ERROR, "MvPhyStatus: link up\n"));
    } else {
      PhyDev->LinkUp = FALSE;
//      DEBUG((DEBUG_ERROR, "MvPhyStatus: link down\n"));
    }
  }
  DEBUG((DEBUG_ERROR, "PhyDev->LinkUp is %d\n", PhyDev->LinkUp));
  MvPhyParseStatus (PhyDev);
  return EFI_SUCCESS;
}

EFI_STATUS
MvPhyStatus (
  IN CONST EFI_PHY_PROTOCOL *This,
  IN PHY_DEVICE	*PhyDev
  )
{
  UINT32 Data;

  Data = Mdio->Read(Mdio, PhyDev->Addr, MII_BMSR);
  Data = Mdio->Read(Mdio, PhyDev->Addr, MII_BMSR);

  if ((Data & BMSR_LSTATUS) == 0) {
    PhyDev->LinkUp = FALSE;
  } else {
    PhyDev->LinkUp = TRUE;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
MvPhyDxeInitialise (
  IN EFI_HANDLE  ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  EFI_PHY_PROTOCOL *Phy;
  EFI_STATUS Status;
  EFI_HANDLE Handle = NULL;

  DEBUG((DEBUG_ERROR, "MvPhyDxe init\n"));

  Phy = AllocateZeroPool (sizeof (EFI_PHY_PROTOCOL));
  Phy->Status = MvPhyStatus;
  Phy->Init = MvPhyInit;

  Status = gBS->InstallMultipleProtocolInterfaces (
                  &Handle,
                  &gEfiPhyProtocolGuid, Phy,
                  NULL
                  );

  if (EFI_ERROR(Status)) {
    DEBUG((DEBUG_ERROR, "Failed to install interfaces\n"));
    return Status;
  }
  DEBUG((DEBUG_ERROR, "Succesfully installed protocol interfaces\n"));

  return EFI_SUCCESS;
}
