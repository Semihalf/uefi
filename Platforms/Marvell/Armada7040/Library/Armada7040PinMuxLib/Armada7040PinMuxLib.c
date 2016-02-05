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
