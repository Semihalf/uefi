/** @file
*
*  Copyright (C) Marvell International Ltd. and its affiliates
*
*  This program and the accompanying materials
*  are licensed and made available under the terms and conditions of the BSD License
*  which accompanies this distribution.  The full text of the license may be found at
*  http://opensource.org/licenses/bsd-license.php
*
*  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
*  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
*
**/

#include <Library/ArmLib.h>
#include <Library/ArmPlatformLib.h>
#include <Library/DebugLib.h>
#include <Library/PcdLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/IoLib.h>

#define MPP_PIN_VAL(pin,func)  \
  (((func) & 0xf) << ((pin) * 4))

#define MPP_REG_COUNT 7
#define MPP_PINS_PER_REG  8

EFI_STATUS
PinMuxInitialize (
  )
{
  UINT8 *MppRegPcd[MPP_REG_COUNT];
  UINT32 i, j, CtrlVal;
  UINTN BaseAddr;

  MppRegPcd[0] = PcdGetPtr (PcdMppSel0);
  MppRegPcd[1] = PcdGetPtr (PcdMppSel1);
  MppRegPcd[2] = PcdGetPtr (PcdMppSel2);
  MppRegPcd[3] = PcdGetPtr (PcdMppSel3);
  MppRegPcd[4] = PcdGetPtr (PcdMppSel4);
  MppRegPcd[5] = PcdGetPtr (PcdMppSel5);
  MppRegPcd[6] = PcdGetPtr (PcdMppSel6);

  BaseAddr = PcdGet64 (PcdPinMuxBaseAddress);

  for (i = 0; i < MPP_REG_COUNT; i++) {
    CtrlVal = 0;
    for (j = 0; j < MPP_PINS_PER_REG; j++) {
      CtrlVal |= MPP_PIN_VAL(j, MppRegPcd[i][j]);
    }
    MmioWrite32 (BaseAddr + 4 * i, CtrlVal);
  }

  return EFI_SUCCESS;
}
