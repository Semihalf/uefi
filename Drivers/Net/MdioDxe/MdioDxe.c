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
#include <Protocol/Mdio.h>

#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/IoLib.h>
#include <Library/DebugLib.h>
#include <Library/PcdLib.h>
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>

#include "MdioDxe.h"

#define MVEBU_SMI_TIMEOUT      10000

/* SMI register fields */
#define  MVEBU_SMI_DATA_OFFS      0  /* Data */
#define  MVEBU_SMI_DATA_MASK      (0xffff << MVEBU_SMI_DATA_OFFS)
#define  MVEBU_SMI_DEV_ADDR_OFFS      16  /* PHY device address */
#define  MVEBU_SMI_REG_ADDR_OFFS      21  /* PHY device reg addr*/
#define  MVEBU_SMI_OPCODE_OFFS      26  /* Write/Read opcode */
#define  MVEBU_SMI_OPCODE_READ      (1 << MVEBU_SMI_OPCODE_OFFS)
#define  MVEBU_SMI_READ_VALID      (1 << 27)  /* Read Valid */
#define  MVEBU_SMI_BUSY        (1 << 28)  /* Busy */

#define  MVEBU_PHY_REG_MASK      0x1f
#define  MVEBU_PHY_ADDR_MASK      0x1f

#define MdioRegWrite32(x, y) MmioWrite32((y), (x))
UINTN SmiBase = 0;

EFI_STATUS
MdioCheckParam (
 INTN PhyAddr,
 INTN RegOff
 )
{
  if (PhyAddr > MVEBU_PHY_ADDR_MASK) {
    DEBUG((DEBUG_ERROR, "Invalid PHY address %d\n", PhyAddr));
    return EFI_INVALID_PARAMETER;
  }

  if (RegOff > MVEBU_PHY_REG_MASK) {
    DEBUG((DEBUG_ERROR, "Invalid register offset %d\n", RegOff));
    return EFI_INVALID_PARAMETER;
  }
  return EFI_SUCCESS;
}

EFI_STATUS
MdioWaitReady (
  )
{
  UINT32 Timeout = MVEBU_SMI_TIMEOUT;
  UINT32 SmiReg;

  /* wait till the SMI is not busy */
  do {
    /* read smi register */
    SmiReg = MmioRead32(SmiBase);
    if (Timeout-- == 0) {
      DEBUG((DEBUG_ERROR, "SMI busy Timeout\n"));
      return EFI_TIMEOUT;
    }
  } while (SmiReg & MVEBU_SMI_BUSY);

  return EFI_SUCCESS;
}

UINT32
MdioRead (
  IN CONST EFI_MDIO_PROTOCOL *This,
  IN UINT32 PhyAddr,
  IN UINT32 RegOff
  )
{
  EFI_STATUS Status;
  UINT32 SmiReg;
  UINT32 Timeout;

  if (SmiBase == 0)
    return 0;

  Status = MdioCheckParam(PhyAddr, RegOff);
  if (EFI_ERROR(Status))
    return 0;

  /* wait till the SMI is not busy */
  Status = MdioWaitReady();
  if (EFI_ERROR(Status))
    return 0;

  /* fill the phy address and regiser offset and read opcode */
  SmiReg = (PhyAddr << MVEBU_SMI_DEV_ADDR_OFFS)
    | (RegOff << MVEBU_SMI_REG_ADDR_OFFS)
    | MVEBU_SMI_OPCODE_READ;

  /* write the smi register */
  MdioRegWrite32(SmiReg, SmiBase);

  /* wait till read value is ready */
  Timeout = MVEBU_SMI_TIMEOUT;
  do {
    /* read smi register */
    SmiReg = MmioRead32(SmiBase);
    if (Timeout-- == 0) {
      DEBUG((DEBUG_ERROR, "SMI read ready time-out\n"));
      return 0;
    }
  } while (!(SmiReg & MVEBU_SMI_READ_VALID));

  return MmioRead32(SmiBase) & MVEBU_SMI_DATA_MASK;
}

EFI_STATUS
MdioWrite (
  IN CONST EFI_MDIO_PROTOCOL *This,
  IN UINT32 PhyAddr,
  IN UINT32 RegOff,
  IN UINT32 Data
  )
{
  UINT32 SmiReg;
  EFI_STATUS Status;

  if (SmiBase == 0)
    return EFI_INVALID_PARAMETER;

  Status = MdioCheckParam(PhyAddr, RegOff);
  if (EFI_ERROR(Status))
    return Status;

  /* wait till the SMI is not busy */
  Status = MdioWaitReady();
  if (EFI_ERROR(Status))
    return Status;

  /* fill the phy addr and reg offset and write opcode and data */
  SmiReg = (Data << MVEBU_SMI_DATA_OFFS);
  SmiReg |= (PhyAddr << MVEBU_SMI_DEV_ADDR_OFFS)
      | (RegOff << MVEBU_SMI_REG_ADDR_OFFS);
  SmiReg &= ~MVEBU_SMI_OPCODE_READ;

  /* write the smi register */
  MdioRegWrite32(SmiReg, SmiBase);

  /* make sure that the write transaction  is over */
  Status = MdioWaitReady();
  if (EFI_ERROR(Status))
    return Status;

  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
MdioDxeInitialise (
  IN EFI_HANDLE  ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  EFI_MDIO_PROTOCOL *Mdio;
  EFI_STATUS Status;
  EFI_HANDLE Handle = NULL;

  DEBUG((DEBUG_ERROR, "MdioDxeInitialise\n"));

  Mdio = AllocateZeroPool (sizeof (EFI_MDIO_PROTOCOL));
  Mdio->Read = MdioRead;
  Mdio->Write = MdioWrite;
  SmiBase = 0x12A200 + 0xf2000000;
  Status = gBS->InstallMultipleProtocolInterfaces (
                  &Handle,
                  &gEfiMdioProtocolGuid, Mdio,
                  NULL
                  );

  if (EFI_ERROR(Status)) {
    DEBUG((DEBUG_ERROR, "Failed to install interfaces\n"));
    return Status;
  }
  DEBUG((DEBUG_ERROR, "Succesfully installed protocol interfaces\n"));

  return EFI_SUCCESS;
}
