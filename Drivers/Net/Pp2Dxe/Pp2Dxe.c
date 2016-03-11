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
#include <Protocol/SimpleNetwork.h>
#include <Protocol/DevicePath.h>
#include <Protocol/Phy.h>

#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/IoLib.h>
#include <Library/DebugLib.h>
#include <Library/PcdLib.h>
#include <Library/NetLib.h>
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>

#include "Pp2Dxe.h"
#include "mvpp2_lib.h"

typedef struct {
  MAC_ADDR_DEVICE_PATH      Pp2Mac;
  EFI_DEVICE_PATH_PROTOCOL  End;
} PP2_DEVICE_PATH;

MVPP2_SHARED *Mvpp2Shared;
BUFFER_LOCATION BufferLocation;

PP2_DEVICE_PATH Pp2DevicePathTemplate = {
  {
    {
      MESSAGING_DEVICE_PATH, MSG_MAC_ADDR_DP,
      { (UINT8) (sizeof(MAC_ADDR_DEVICE_PATH)), (UINT8) ((sizeof(MAC_ADDR_DEVICE_PATH)) >> 8) }
    },
    { { 0 } },
    0
  },
  {
    END_DEVICE_PATH_TYPE,
    END_ENTIRE_DEVICE_PATH_SUBTYPE,
    { sizeof(EFI_DEVICE_PATH_PROTOCOL), 0 }
  }
};

STATIC
EFI_STATUS
Pp2DxeBmPoolInit (
  VOID
  )
{
  INTN i;
  UINT8 *pool_addr;

  for (i = 0; i < MVPP2_BM_POOLS_NUM; i++) {
    /* Mask BM all interrupts */
    mvpp2_write(Mvpp2Shared, MVPP2_BM_INTR_MASK_REG(i), 0);
    /* Clear BM cause register */
    mvpp2_write(Mvpp2Shared, MVPP2_BM_INTR_CAUSE_REG(i), 0);
  }

  Mvpp2Shared->bm_pools = AllocateZeroPool (sizeof(struct mvpp2_bm_pool));
  
  if (!Mvpp2Shared->bm_pools)
    return EFI_OUT_OF_RESOURCES;

  pool_addr = AllocateZeroPool ((sizeof(VOID*) * MVPP2_BM_SIZE)*2 +
      MVPP2_BM_POOL_PTR_ALIGN);

  if (!pool_addr) {
    return EFI_OUT_OF_RESOURCES;
  }
  if (IS_NOT_ALIGN((unsigned long)pool_addr,
    MVPP2_BM_POOL_PTR_ALIGN))
    pool_addr =
    (unsigned char *)ALIGN_UP((unsigned long)pool_addr,
            MVPP2_BM_POOL_PTR_ALIGN);

  Mvpp2Shared->bm_pools->id = MVPP2_BM_POOL;
  Mvpp2Shared->bm_pools->virt_addr = (MV_U32*)pool_addr;
  Mvpp2Shared->bm_pools->phys_addr = (unsigned long)pool_addr;

  mvpp2_bm_pool_hw_create(Mvpp2Shared, Mvpp2Shared->bm_pools, MVPP2_BM_SIZE);

  return EFI_SUCCESS;
}
STATIC
VOID
Pp2DxeAxiConfig (
  VOID
  )
{
  /* Config AXI Read&Write Normal and Soop mode  */
  mvpp2_write(Mvpp2Shared, MVPP22_AXI_RD_NORMAL_CODE_REG,
    MVPP22_AXI_RD_CODE_MASK);
  mvpp2_write(Mvpp2Shared, MVPP22_AXI_RD_SNP_CODE_REG, MVPP22_AXI_RD_CODE_MASK);
  mvpp2_write(Mvpp2Shared, MVPP22_AXI_WR_NORMAL_CODE_REG,
    MVPP22_AXI_WR_CODE_MASK);
  mvpp2_write(Mvpp2Shared, MVPP22_AXI_WR_SNP_CODE_REG, MVPP22_AXI_WR_CODE_MASK);
}

STATIC
VOID
Pp2DxeLinkEvent (
  IN EFI_SIMPLE_NETWORK_PROTOCOL  *Snp
  )
{
  PP2DXE_CONTEXT *Pp2Context = INSTANCE_FROM_SNP(Snp);
  PP2DXE_PORT *Port = &Pp2Context->Port;
  PHY_DEVICE *PhyDev = Pp2Context->PhyDev;
  UINT32 Data;
  BOOLEAN StatusChange = FALSE;

  if (PhyDev->LinkUp) {
    if ((Port->speed != PhyDev->Speed) ||
        (Port->duplex != PhyDev->Duplex)) {
      UINT32 Data;

      Data = mvpp2_gmac_read(Port, MVPP2_GMAC_AUTONEG_CONFIG);
      Data = 0xb;
      Data &= ~(MVPP2_GMAC_CONFIG_MII_SPEED |
         MVPP2_GMAC_CONFIG_GMII_SPEED |
         MVPP2_GMAC_CONFIG_FULL_DUPLEX |
         MVPP2_GMAC_AN_SPEED_EN |
         MVPP2_GMAC_AN_DUPLEX_EN);

      if (PhyDev->Duplex)
        Data |= MVPP2_GMAC_CONFIG_FULL_DUPLEX;

      if (PhyDev->Speed == SPEED_1000)
        Data |= MVPP2_GMAC_CONFIG_GMII_SPEED;
      else if (PhyDev->Speed == SPEED_100)
        Data |= MVPP2_GMAC_CONFIG_MII_SPEED;

      mvpp2_gmac_write(Port, MVPP2_GMAC_AUTONEG_CONFIG, Data);

      Port->duplex = PhyDev->Duplex;
      Port->speed  = PhyDev->Speed;
    }
  }

  if (PhyDev->LinkUp != Port->link) {
    if (!PhyDev->LinkUp) {
      Port->duplex = FALSE;
      Port->speed = NO_SPEED;
    }

    Port->link = PhyDev->LinkUp;
    StatusChange = TRUE;
  }

  if (StatusChange) {
    if (PhyDev->LinkUp) {
      Data = mvpp2_gmac_read(Port, MVPP2_GMAC_AUTONEG_CONFIG);
      Data = 0xb;
      Data |= (MVPP2_GMAC_FORCE_LINK_PASS |
        MVPP2_GMAC_FORCE_LINK_DOWN);
      mvpp2_gmac_write(Port, MVPP2_GMAC_AUTONEG_CONFIG, Data);
    //  mvpp2_egress_enable(Port);
    //  mvpp2_ingress_enable(Port);
    } else {
    //  mvpp2_ingress_disable(Port);
    //  mvpp2_egress_disable(Port);
    }
   // phy_print_status(PhyDev);
  }
}

EFI_STATUS
EFIAPI
Pp2DxeSnpInitialize (
  IN EFI_SIMPLE_NETWORK_PROTOCOL                    *This,
  IN UINTN                                          ExtraRxBufferSize  OPTIONAL,
  IN UINTN                                          ExtraTxBufferSize  OPTIONAL
  )
{
  EFI_STATUS Status;
  PP2DXE_CONTEXT *Pp2Context;
  Pp2Context = INSTANCE_FROM_SNP(This);
  UINT8 *PhyAddresses;

  PhyAddresses = PcdGetPtr (PcdPhySmiAddresses);
  DEBUG((DEBUG_ERROR, "Pp2Dxe%d: initialize\n", Pp2Context->Instance));
  DEBUG((DEBUG_ERROR, "PhyAddresses are: %d %d\n", PhyAddresses[0], PhyAddresses[1]));

  switch (This->Mode->State) {
  case EfiSimpleNetworkStarted:
    break;
  case EfiSimpleNetworkInitialized:
    return (EFI_SUCCESS);
  case EfiSimpleNetworkStopped:
    return (EFI_NOT_STARTED);
  default:
    return (EFI_DEVICE_ERROR);
  }

  This->Mode->State = EfiSimpleNetworkInitialized;
  if (Pp2Context->Initialized)
    return EFI_SUCCESS;

  Status = gBS->LocateProtocol (
		  &gEfiPhyProtocolGuid,
		  NULL,
		  (VOID **) &Pp2Context->Phy
		  );
  if (EFI_ERROR(Status))
    return Status;

  Pp2Context->Initialized = TRUE;

  Pp2Context->Phy->Init(
      Pp2Context->Phy,
      PhyAddresses[Pp2Context->Instance],
      &Pp2Context->PhyDev
      );
  Pp2Context->Phy->Status(Pp2Context->Phy, Pp2Context->PhyDev);
  DEBUG((DEBUG_ERROR,
    "PHY%d: ",
    Pp2Context->PhyDev->Addr));
  DEBUG((DEBUG_ERROR,
    Pp2Context->PhyDev->LinkUp ? "link up, " : "link down, "));
  DEBUG((DEBUG_ERROR,
    Pp2Context->PhyDev->Duplex ? "duplex, " : "no duplex, "));
  DEBUG((DEBUG_ERROR,
    Pp2Context->PhyDev->Speed == SPEED_10 ? "speed 10\n" : (Pp2Context->PhyDev->Speed == SPEED_100 ? "speed 100\n" : "speed 1000\n")));
   return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
Pp2SnpStart (
  IN EFI_SIMPLE_NETWORK_PROTOCOL  *This
  )
{
  PP2DXE_CONTEXT *Pp2Context;
  Pp2Context = INSTANCE_FROM_SNP(This);
  DEBUG((DEBUG_ERROR, "Pp2Dxe%d: started\n", Pp2Context->Instance));
  switch (This->Mode->State) {
  case EfiSimpleNetworkStopped:
    break;
  case EfiSimpleNetworkStarted:
  case EfiSimpleNetworkInitialized:
    DEBUG((EFI_D_WARN, "Pp2Dxe: Driver already started\n"));
    return (EFI_ALREADY_STARTED);
  default:
    DEBUG((EFI_D_ERROR, "Pp2Dxe: Driver in an invalid state: %u\n",
          (UINTN)This->Mode->State));
    return (EFI_DEVICE_ERROR);
  }
  This->Mode->State = EfiSimpleNetworkStarted;
  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
Pp2SnpStop (
  IN EFI_SIMPLE_NETWORK_PROTOCOL  *This
  )
{
  DEBUG((DEBUG_ERROR, "Pp2SnpStop \n"));
  switch (This->Mode->State) {
  case EfiSimpleNetworkStarted:
  case EfiSimpleNetworkInitialized:
    break;
  case EfiSimpleNetworkStopped:
    return (EFI_NOT_STARTED);
  default:
    return (EFI_DEVICE_ERROR);
  }
  This->Mode->State = EfiSimpleNetworkStopped;
  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
Pp2SnpReset (
  IN EFI_SIMPLE_NETWORK_PROTOCOL   *This,
  IN BOOLEAN                       ExtendedVerification
  )
{
  DEBUG((DEBUG_ERROR, "Pp2SnpReset \n"));
  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
Pp2SnpShutdown (
  IN EFI_SIMPLE_NETWORK_PROTOCOL  *This
  )
{
  switch (This->Mode->State) {
  case EfiSimpleNetworkInitialized:
    break;
  case EfiSimpleNetworkStarted:
    return (EFI_DEVICE_ERROR);
  case EfiSimpleNetworkStopped:
    return (EFI_NOT_STARTED);
  default:
    return (EFI_DEVICE_ERROR);
  }

  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
Pp2SnpReceiveFilters (
  IN EFI_SIMPLE_NETWORK_PROTOCOL                             *This,
  IN UINT32                                                  Enable,
  IN UINT32                                                  Disable,
  IN BOOLEAN                                                 ResetMCastFilter,
  IN UINTN                                                   MCastFilterCnt     OPTIONAL,
  IN EFI_MAC_ADDRESS                                         *MCastFilter OPTIONAL
  )
{
  DEBUG((DEBUG_ERROR, "Pp2SnpReceiveFilt \n"));
  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
Pp2SnpNetStat (
  IN EFI_SIMPLE_NETWORK_PROTOCOL          *This,
  IN BOOLEAN                              Reset,
  IN OUT UINTN                            *StatisticsSize   OPTIONAL,
  OUT EFI_NETWORK_STATISTICS              *StatisticsTable  OPTIONAL
  )
{
  DEBUG((DEBUG_ERROR, "Pp2SnpNetStat \n"));
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Pp2SnpIpToMac (
  IN EFI_SIMPLE_NETWORK_PROTOCOL          *This,
  IN BOOLEAN                              IPv6,
  IN EFI_IP_ADDRESS                       *IP,
  OUT EFI_MAC_ADDRESS                     *MAC
  )
{
  DEBUG((DEBUG_ERROR, "Pp2SnpIpToMac \n"));
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Pp2SnpNvData (
  IN EFI_SIMPLE_NETWORK_PROTOCOL          *This,
  IN BOOLEAN                              ReadWrite,
  IN UINTN                                Offset,
  IN UINTN                                BufferSize,
  IN OUT VOID                             *Buffer
  )
{
  DEBUG((DEBUG_ERROR, "Pp2SnpNvData \n"));
  return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
Pp2SnpGetStatus (
  IN EFI_SIMPLE_NETWORK_PROTOCOL          *Snp,
  OUT UINT32                              *InterruptStatus OPTIONAL,
  OUT VOID                                **TxBuf OPTIONAL
  )
{
//  DEBUG((DEBUG_ERROR, "Pp2SnpGetStatus \n"));
  PP2DXE_CONTEXT *Pp2Context = INSTANCE_FROM_SNP(Snp);

  if (!Pp2Context->Initialized)
    return EFI_NOT_READY;
  Pp2Context->Phy->Status(Pp2Context->Phy, Pp2Context->PhyDev);
  if (Pp2Context->PhyDev->LinkUp != Snp->Mode->MediaPresent)
    DEBUG((DEBUG_ERROR, "Pp2Dxe%d: Link %s\n", Pp2Context->Instance, Pp2Context->PhyDev->LinkUp ? "up" : "down"));
  Snp->Mode->MediaPresent = Pp2Context->PhyDev->LinkUp;
  Pp2DxeLinkEvent(Snp);
  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
Pp2SnpTransmit (
  IN EFI_SIMPLE_NETWORK_PROTOCOL          *This,
  IN UINTN                                HeaderSize,
  IN UINTN                                BufferSize,
  IN VOID                                 *Buffer,
  IN EFI_MAC_ADDRESS                      *SrcAddr  OPTIONAL,
  IN EFI_MAC_ADDRESS                      *DestAddr OPTIONAL,
  IN UINT16                               *Protocol OPTIONAL
  )
{
  return EFI_DEVICE_ERROR;
}

EFI_STATUS
EFIAPI
Pp2SnpReceive (
  IN EFI_SIMPLE_NETWORK_PROTOCOL          *This,
  OUT UINTN                               *HeaderSize OPTIONAL,
  IN OUT UINTN                            *BufferSize,
  OUT VOID                                *Buffer,
  OUT EFI_MAC_ADDRESS                     *SrcAddr    OPTIONAL,
  OUT EFI_MAC_ADDRESS                     *DestAddr   OPTIONAL,
  OUT UINT16                              *Protocol   OPTIONAL
  )
{
  return EFI_TIMEOUT;
}

EFI_STATUS
Pp2DxeSnpInstall (
  IN PP2DXE_CONTEXT *Pp2Context
  )
{   
  EFI_HANDLE Handle = NULL;
  EFI_STATUS Status;
  PP2_DEVICE_PATH *Pp2DevicePath;

  DEBUG((DEBUG_ERROR, "Pp2Dxe%d: Installing protocols\n", Pp2Context->Instance));
  Pp2Context->Snp.Mode = AllocateZeroPool (sizeof (EFI_SIMPLE_NETWORK_MODE));
  Pp2DevicePath = AllocateCopyPool (sizeof (PP2_DEVICE_PATH), &Pp2DevicePathTemplate);
  Pp2DevicePath->Pp2Mac.MacAddress.Addr[0] = Pp2Context->Instance; /* TODO */
  Pp2Context->Signature = PP2DXE_SIGNATURE;
  Pp2Context->Snp.Initialize = Pp2DxeSnpInitialize;
  Pp2Context->Snp.Start = Pp2SnpStart;
  Pp2Context->Snp.Stop = Pp2SnpStop;
  Pp2Context->Snp.Reset = Pp2SnpReset;
  Pp2Context->Snp.Shutdown = Pp2SnpShutdown;
  Pp2Context->Snp.ReceiveFilters = Pp2SnpReceiveFilters;
  Pp2Context->Snp.Statistics = Pp2SnpNetStat;
  Pp2Context->Snp.MCastIpToMac = Pp2SnpIpToMac;
  Pp2Context->Snp.NvData = Pp2SnpNvData;
  Pp2Context->Snp.GetStatus = Pp2SnpGetStatus;
  Pp2Context->Snp.Transmit = Pp2SnpTransmit;
  Pp2Context->Snp.Receive = Pp2SnpReceive;
  Pp2Context->Snp.Revision = EFI_SIMPLE_NETWORK_PROTOCOL_REVISION;

  Pp2Context->Snp.Mode->State = EfiSimpleNetworkStopped;
  Pp2Context->Snp.Mode->IfType = NET_IFTYPE_ETHERNET;
  Pp2Context->Snp.Mode->HwAddressSize = NET_ETHER_ADDR_LEN;
  Pp2Context->Snp.Mode->MediaHeaderSize = sizeof (ETHER_HEAD);
  Pp2Context->Snp.Mode->MaxPacketSize = EFI_PAGE_SIZE;
  Pp2Context->Snp.Mode->ReceiveFilterMask = EFI_SIMPLE_NETWORK_RECEIVE_UNICAST |
			       EFI_SIMPLE_NETWORK_RECEIVE_MULTICAST |
			       EFI_SIMPLE_NETWORK_RECEIVE_BROADCAST |
			       EFI_SIMPLE_NETWORK_RECEIVE_PROMISCUOUS |
			       EFI_SIMPLE_NETWORK_RECEIVE_PROMISCUOUS_MULTICAST;
  Pp2Context->Snp.Mode->ReceiveFilterSetting = EFI_SIMPLE_NETWORK_RECEIVE_UNICAST |
				  EFI_SIMPLE_NETWORK_RECEIVE_MULTICAST |
				  EFI_SIMPLE_NETWORK_RECEIVE_BROADCAST;
  Pp2Context->Snp.Mode->MaxMCastFilterCount = MAX_MCAST_FILTER_CNT;
  Pp2Context->Snp.Mode->MCastFilterCount = 0;
  Pp2Context->Snp.Mode->MediaPresentSupported = TRUE;
  Pp2Context->Snp.Mode->MediaPresent = FALSE;
  ZeroMem (&Pp2Context->Snp.Mode->MCastFilter, MAX_MCAST_FILTER_CNT * sizeof(EFI_MAC_ADDRESS));
  SetMem (&Pp2Context->Snp.Mode->BroadcastAddress, sizeof (EFI_MAC_ADDRESS), 0xFF);

  Pp2DevicePath->Pp2Mac.IfType = Pp2Context->Snp.Mode->IfType;
  Status = gBS->InstallMultipleProtocolInterfaces (
		  &Handle,
		  &gEfiSimpleNetworkProtocolGuid, &Pp2Context->Snp,
		  &gEfiDevicePathProtocolGuid, Pp2DevicePath,
		  NULL
		  );

  if (EFI_ERROR(Status))
    DEBUG((DEBUG_ERROR, "Failed to install protocols.\n"));

  return Status;
}

EFI_STATUS
EFIAPI
Pp2DxeInitialise (
  IN EFI_HANDLE  ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  PP2DXE_CONTEXT *Pp2Context;
  EFI_STATUS Status;
  EFI_HANDLE Handle;
  INTN i;
  UINT8 *PortIds;
  VOID *BufferSpace;

  /* alloc mvpp2  structure  */
  Mvpp2Shared = AllocateZeroPool (sizeof (MVPP2_SHARED));
  if (Mvpp2Shared == NULL) {
    DEBUG((DEBUG_ERROR, "Allocation fail.\n"));
    return EFI_OUT_OF_RESOURCES;
  }

  Mvpp2Shared->base = PcdGet64 (PcdPp2SharedAddress);
  DEBUG((DEBUG_ERROR, "Pp2Dxe: shared base is 0x%lx\n", Mvpp2Shared->base));

  /* buffer_loc */
  BufferSpace = UncachedAllocateAlignedPool (BD_SPACE, MVPP2_BUFFER_ALIGN_SIZE);
  if (BufferSpace == NULL)
    return EFI_OUT_OF_RESOURCES;

  BufferLocation.tx_descs = (struct mvpp2_tx_desc *)BufferSpace;

  BufferLocation.aggr_tx_descs = (struct mvpp2_tx_desc *)
    ((unsigned long)BufferSpace + MVPP2_MAX_TXD
    * sizeof(struct mvpp2_tx_desc));

  BufferLocation.rx_descs = (struct mvpp2_rx_desc *)
    ((unsigned long)BufferSpace +
    (MVPP2_MAX_TXD + MVPP2_AGGR_TXQ_SIZE)
    * sizeof(struct mvpp2_tx_desc));

  BufferLocation.rx_buffers = (unsigned long)
    (BufferSpace + (MVPP2_MAX_TXD + MVPP2_AGGR_TXQ_SIZE)
    * sizeof(struct mvpp2_tx_desc) +
    MVPP2_MAX_RXD * sizeof(struct mvpp2_rx_desc));

  Pp2DxeAxiConfig();
  Pp2DxeBmPoolInit();
  mvpp2_rx_fifo_init(Mvpp2Shared);
  mvpp2_prs_default_init(Mvpp2Shared);
  mvpp2_cls_init(Mvpp2Shared);

  for (i = 0; i < PcdGet32 (PcdPp2PortNumber); i++) {
    /* pp2x_initialize_dev */
    /* install snp */
    Pp2Context = AllocateZeroPool (sizeof (PP2DXE_CONTEXT));
    if (Pp2Context == NULL) {
      DEBUG((DEBUG_ERROR, "Allocation fail.\n"));
      return EFI_OUT_OF_RESOURCES;
    }

    /* Instances are enumerated from 0 */
    Pp2Context->Instance = i;

    Status = Pp2DxeSnpInstall(Pp2Context);
    /* TODO: free resources */
    if (EFI_ERROR(Status))
      return Status;

    PortIds = PcdGetPtr (PcdPp2PortIds);
    Pp2Context->Port.id = PortIds[Pp2Context->Instance];
    Pp2Context->Port.base = PcdGet64 (PcdPp2GmacBaseAddress) +
      PcdGet32 (PcdPp2GmacObjSize) * Pp2Context->Port.id;
    DEBUG((DEBUG_ERROR, "Pp2Dxe%d: port%d at 0x%lx\n", Pp2Context->Instance, Pp2Context->Port.id,
      Pp2Context->Port.base));

  }

  return EFI_SUCCESS;
}
