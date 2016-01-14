/*-
 * Copyright (C) 2008 MARVELL INTERNATIONAL LTD.
 * All rights reserved.
 *
 * Developed by Semihalf.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of MARVELL nor the names of contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <Protocol/I2cMaster.h>
#include <Protocol/DriverBinding.h>
#include <Protocol/CpuIo2.h>

#include "A8kI2cDxe.h"

/* TODO */
#define DELAY(x)
#define get_tclk(x)  1
#define device_printf(args...)
#define bzero(a,b)	0
#define device_get_softc(x) 0

STATIC A8K_I2C_BAUD_RATE baud_rate[IIC_FASTEST + 1];

EFI_STATUS
EFIAPI
A8kI2cInitialise (
  IN EFI_HANDLE	ImageHandle,
  IN EFI_SYSTEM_TABLE	*SystemTable
  )
{
  /* this is required to avoid errors about unused functions */
  A8kI2cCalBaudRate(TWSI_BAUD_RATE_SLOW, &baud_rate[IIC_SLOW]);
  A8kI2cRepeatedStart((EFI_HANDLE)0, 0, 0);
  A8kI2cStart((EFI_HANDLE)0, 0, 0);
  A8kI2cRead((EFI_HANDLE) 0, 0, 0, 0, 0, 0);
  A8kI2cWrite((EFI_HANDLE) 0, 0, 0, 0, 0);
  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
A8kI2cBindingSupported (
  IN EFI_DRIVER_BINDING_PROTOCOL            *This,
  IN EFI_HANDLE                             ControllerHandle,
  IN EFI_DEVICE_PATH_PROTOCOL               *RemainingDevicePath OPTIONAL
  )
{
  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
A8kI2cBindingStart (
  IN EFI_DRIVER_BINDING_PROTOCOL            *This,
  IN EFI_HANDLE                             ControllerHandle,
  IN EFI_DEVICE_PATH_PROTOCOL               *RemainingDevicePath OPTIONAL
  )
{
  /* bus logic doesn't apply, exclude for now */
#if 0
  A8K_I2C_INSTANCE *sc;
  phandle_t child, iicbusnode;
  device_t childdev;
  struct iicbus_ivar *devi;
  UINT8 dname[32];  /* 32 is taken from struct u_device */
  UINT32 paddr;
  UINTN len, error;

  sc = device_get_softc(dev);
  sc->dev = dev;
  bzero(baud_rate, sizeof(baud_rate));

  //mtx_init(&sc->mutex, device_get_nameunit(dev), MV_TWSI_NAME, MTX_DEF);

  /* Allocate IO resources */
  if (bus_alloc_resources(dev, res_spec, sc->res)) {
    device_printf(dev, "could not allocate resources\n");
    mv_twsi_detach(dev);
    return (EFI_UNSUPPORTED);
  }

  A8kI2cCalBaudRate(TWSI_BAUD_RATE_SLOW, &baud_rate[IIC_SLOW]);
  A8kI2cCalBaudRate(TWSI_BAUD_RATE_FAST, &baud_rate[IIC_FAST]);
  if (bootverbose)
    device_printf(dev, "calculated baud rates are:\n"
        " %" PRIu32 " kHz (M=%d, N=%d) for slow,\n"
        " %" PRIu32 " kHz (M=%d, N=%d) for fast.\n",
        baud_rate[IIC_SLOW].raw / 1000,
        baud_rate[IIC_SLOW].m,
        baud_rate[IIC_SLOW].n,
        baud_rate[IIC_FAST].raw / 1000,
        baud_rate[IIC_FAST].m,
        baud_rate[IIC_FAST].n);

  sc->iicbus = device_add_child(dev, IICBUS_DEVNAME, -1);
  if (sc->iicbus == NULL) {
    device_printf(dev, "could not add iicbus child\n");
    mv_twsi_detach(dev);
    return (EFI_UNSUPPORTED);
  }
  /* Attach iicbus. */
  bus_generic_attach(dev);

  iicbusnode = 0;
  /* Find iicbus as the child devices in the device tree. */
  for (child = OF_child(ofw_bus_get_node(dev)); child != 0;
      child = OF_peer(child)) {
    len = OF_getproplen(child, "model");
    if (len <= 0 || len > sizeof(dname) - 1)
      continue;
    error = OF_getprop(child, "model", &dname, len);
    dname[len + 1] = '\0';
    if (error == -1)
      continue;
    len = strlen(dname);
    if (len == strlen(IICBUS_DEVNAME) &&
        strncasecmp(dname, IICBUS_DEVNAME, len) == 0) {
      iicbusnode = child;
      break; 
    }
  }
  if (iicbusnode == 0)
    goto attach_end;

  /* Attach child devices onto iicbus. */
  for (child = OF_child(iicbusnode); child != 0; child = OF_peer(child)) {
    /* Get slave address. */
    error = OF_getprop(child, "i2c-address", &paddr, sizeof(paddr));
    if (error == -1)
      error = OF_getprop(child, "reg", &paddr, sizeof(paddr));
    if (error == -1)
      continue;

    /* Get device driver name. */
    len = OF_getproplen(child, "model");
    if (len <= 0 || len > sizeof(dname) - 1)
      continue;
    OF_getprop(child, "model", &dname, len);
    dname[len + 1] = '\0';

    if (bootverbose)
      device_printf(dev, "adding a device %s at %d.\n",
          dname, fdt32_to_cpu(paddr));
    childdev = BUS_ADD_CHILD(sc->iicbus, 0, dname, -1);
    devi = IICBUS_IVAR(childdev);
    devi->addr = fdt32_to_cpu(paddr);
  }

attach_end:
  bus_generic_attach(sc->iicbus);
#endif

  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
A8kI2cBindingStop (
  IN EFI_DRIVER_BINDING_PROTOCOL            *This,
  IN  EFI_HANDLE                            ControllerHandle,
  IN  UINTN                                 NumberOfChildren,
  IN  EFI_HANDLE                            *ChildHandleBuffer OPTIONAL
  )
{
/*
  A8K_I2C_INSTANCE *sc;
  UINTN rv;

  sc = device_get_softc(dev);

  if ((rv = bus_generic_detach(dev)) != 0)
    return (rv);

  if (sc->iicbus != NULL)
    if ((rv = device_delete_child(dev, sc->iicbus)) != 0)
      return (rv);

  bus_release_resources(dev, res_spec, sc->res);*/

  //mtx_destroy(&sc->mutex);
  return EFI_SUCCESS;
}

STATIC UINT32
TWSI_READ(
  IN A8K_I2C_INSTANCE *sc,
  IN UINTN off)
{

//  return (bus_read_4(sc->res[0], off));
  return 0;
}

STATIC
VOID
TWSI_WRITE (
  IN A8K_I2C_INSTANCE *sc,
  IN UINTN off,
  IN UINT32 val)
{

//  bus_write_4(sc->res[0], off, val);
}

STATIC
VOID
A8kI2cControlClear (
  IN A8K_I2C_INSTANCE *sc,
  IN UINT32 mask)
{
  UINT32 val;

  val = TWSI_READ(sc, TWSI_CONTROL);
  val &= ~mask;
  TWSI_WRITE(sc, TWSI_CONTROL, val);
}

STATIC
VOID
A8kI2cControlSet (
  IN A8K_I2C_INSTANCE *sc,
  IN UINT32 mask)
{
  UINT32 val;

  val = TWSI_READ(sc, TWSI_CONTROL);
  val |= mask;
  TWSI_WRITE(sc, TWSI_CONTROL, val);
}

STATIC
VOID
A8kI2cClearIflg (
 IN A8K_I2C_INSTANCE *sc
 )
{

  DELAY(1000);
  A8kI2cControlClear(sc, TWSI_CONTROL_IFLG);
  DELAY(1000);
}


/*
 * timeout given in us
 * returns
 *   0 on sucessfull mask change
 *   non-zero on timeout
 */
STATIC
UINTN
A8kI2cPollCtrl (
  IN A8K_I2C_INSTANCE *sc,
  IN UINTN timeout,
  IN UINT32 mask)
{

  timeout /= 10;
  while (!(TWSI_READ(sc, TWSI_CONTROL) & mask)) {
    DELAY(10);
    if (--timeout < 0)
      return (timeout);
  }
  return (0);
}


/*
 * 'timeout' is given in us. Note also that timeout handling is not exact --
 * A8kI2cLockedStart() total wait can be more than 2 x timeout
 * (A8kI2cPollCtrl() is called twice). 'mask' can be either TWSI_STATUS_START
 * or TWSI_STATUS_RPTD_START
 */
STATIC
EFI_STATUS
A8kI2cLockedStart (
  IN EFI_HANDLE dev,
  IN A8K_I2C_INSTANCE *sc,
  IN INT32 mask,
  IN UINT8 slave,
  IN UINTN timeout
  )
{
  UINTN read_access, iflg_set = 0;
  UINT32 status;

  //mtx_assert(&sc->mutex, MA_OWNED);

  if (mask == TWSI_STATUS_RPTD_START)
    /* read IFLG to know if it should be cleared later; from NBSD */
    iflg_set = TWSI_READ(sc, TWSI_CONTROL) & TWSI_CONTROL_IFLG;

  A8kI2cControlSet(sc, TWSI_CONTROL_START);

  if (mask == TWSI_STATUS_RPTD_START && iflg_set) {
    debugf("IFLG set, clearing\n");
    A8kI2cClearIflg(sc);
  }

  /*
   * Without this delay we timeout checking IFLG if the timeout is 0.
   * NBSD driver always waits here too.
   */
  DELAY(1000);

  if (A8kI2cPollCtrl(sc, timeout, TWSI_CONTROL_IFLG)) {
    debugf("timeout sending %sSTART condition\n",
        mask == TWSI_STATUS_START ? "" : "repeated ");
    return (EFI_NO_RESPONSE);
  }

  status = TWSI_READ(sc, TWSI_STATUS);
  if (status != mask) {
    debugf("wrong status (%02x) after sending %sSTART condition\n",
        status, mask == TWSI_STATUS_START ? "" : "repeated ");
    return (EFI_DEVICE_ERROR);
  }

  TWSI_WRITE(sc, TWSI_DATA, slave);
  DELAY(1000);
  A8kI2cClearIflg(sc);

  if (A8kI2cPollCtrl(sc, timeout, TWSI_CONTROL_IFLG)) {
    debugf("timeout sending slave address\n");
    return (EFI_NO_RESPONSE);
  }
  
  read_access = (slave & 0x1) ? 1 : 0;
  status = TWSI_READ(sc, TWSI_STATUS);
  if (status != (read_access ?
      TWSI_STATUS_ADDR_R_ACK : TWSI_STATUS_ADDR_W_ACK)) {
    debugf("no ACK (status: %02x) after sending slave address\n",
        status);
    return (EFI_NO_RESPONSE);
  }

  return (EFI_SUCCESS);
}

#define  ABSSUB(a,b)  (((a) > (b)) ? (a) - (b) : (b) - (a))
STATIC
VOID
A8kI2cCalBaudRate (
  IN CONST UINT32 target,
  IN OUT A8K_I2C_BAUD_RATE *rate
  )
{
  UINT32 clk, cur, diff, diff0;
  UINTN m, n, m0, n0;

  /* Calculate baud rate. */
  m0 = n0 = 4;  /* Default values on reset */
  diff0 = 0xffffffff;
  clk = get_tclk();

  for (n = 0; n < 8; n++) {
    for (m = 0; m < 16; m++) {
      cur = TWSI_BAUD_RATE_RAW(clk,m,n);
      diff = ABSSUB(target, cur);
      if (diff < diff0) {
        m0 = m;
        n0 = n;
        diff0 = diff;
      }
    }
  }
  rate->raw = TWSI_BAUD_RATE_RAW(clk, m0, n0);
  rate->param = TWSI_BAUD_RATE_PARAM(m0, n0);
  rate->m = m0;
  rate->n = n0;
}

/*
 * Only slave mode supported, disregard [old]addr
 */
EFI_STATUS
EFIAPI
A8kI2cReset (
  IN CONST EFI_I2C_MASTER_PROTOCOL *This
  )
{
  A8K_I2C_INSTANCE *sc;
  UINT32 param;

  sc = device_get_softc(dev);
/*
  switch (speed) {
  case IIC_SLOW:
  case IIC_FAST:
    param = baud_rate[speed].param;
    break;
  case IIC_FASTEST:
  case IIC_UNKNOWN:
  default:
    param = baud_rate[IIC_FAST].param;
    break;
  }*/
  param = baud_rate[IIC_FAST].param;

  //mtx_lock(&sc->mutex);
  TWSI_WRITE(sc, TWSI_SOFT_RESET, 0x0);
  DELAY(2000);
  TWSI_WRITE(sc, TWSI_BAUD_RATE, param);
  TWSI_WRITE(sc, TWSI_CONTROL, TWSI_CONTROL_TWSIEN | TWSI_CONTROL_ACK);
  DELAY(1000);
  //mtx_unlock(&sc->mutex);

  return (EFI_SUCCESS);
}

/*
 * timeout is given in us
 */
STATIC
EFI_STATUS
A8kI2cRepeatedStart (
  IN EFI_HANDLE dev,
  IN UINT8 slave,
  IN UINTN timeout
  )
{
  A8K_I2C_INSTANCE *sc;
  EFI_STATUS rv;

  sc = device_get_softc(dev);

  //mtx_lock(&sc->mutex);
  rv = A8kI2cLockedStart(dev, sc, TWSI_STATUS_RPTD_START, slave,
      timeout);
  //mtx_unlock(&sc->mutex);

  if (rv != EFI_SUCCESS) {
    A8kI2cStop(dev);
    return (rv);
  } else
    return (rv);
}

/*
 * timeout is given in us
 */
STATIC
EFI_STATUS
A8kI2cStart (
  IN EFI_HANDLE dev,
  IN UINT8 slave,
  IN UINTN timeout
  )
{
  A8K_I2C_INSTANCE *sc;
  EFI_STATUS rv;

  sc = device_get_softc(dev);

  //mtx_lock(&sc->mutex);
  rv = A8kI2cLockedStart(dev, sc, TWSI_STATUS_START, slave, timeout);
  //mtx_unlock(&sc->mutex);

  if (rv != EFI_SUCCESS) {
    A8kI2cStop(dev);
    return (rv);
  } else
    return (EFI_SUCCESS);
}

STATIC
EFI_STATUS
A8kI2cStop (
  IN EFI_HANDLE dev
  )
{
  A8K_I2C_INSTANCE *sc;

  sc = device_get_softc(dev);

  //mtx_lock(&sc->mutex);
  A8kI2cControlSet(sc, TWSI_CONTROL_STOP);
  DELAY(1000);
  A8kI2cClearIflg(sc);
  //mtx_unlock(&sc->mutex);

  return (EFI_SUCCESS);
}

STATIC
EFI_STATUS
A8kI2cRead (
  IN EFI_HANDLE dev,
  IN OUT UINT8 *buf,
  IN UINTN len,
  IN OUT UINTN *read,
  IN UINTN last,
  IN UINTN delay
  )
{
  A8K_I2C_INSTANCE *sc;
  UINT32 status;
  UINTN last_byte;
  EFI_STATUS rv;

  sc = device_get_softc(dev);

  //mtx_lock(&sc->mutex);
  *read = 0;
  while (*read < len) {
    /*
     * Check if we are reading last byte of the last buffer,
     * do not send ACK then, per I2C specs
     */
    last_byte = ((*read == len - 1) && last) ? 1 : 0;
    if (last_byte)
      A8kI2cControlClear(sc, TWSI_CONTROL_ACK);
    else
      A8kI2cControlSet(sc, TWSI_CONTROL_ACK);

    DELAY (1000);
    A8kI2cClearIflg(sc);

    if (A8kI2cPollCtrl(sc, delay, TWSI_CONTROL_IFLG)) {
      debugf("timeout reading data\n");
      rv = EFI_NO_RESPONSE;
      goto out;
    }

    status = TWSI_READ(sc, TWSI_STATUS);
    if (status != (last_byte ?
        TWSI_STATUS_DATA_RD_NOACK : TWSI_STATUS_DATA_RD_ACK)) {
      debugf("wrong status (%02x) while reading\n", status);
      rv = EFI_DEVICE_ERROR;
      goto out;
    }

    *buf++ = TWSI_READ(sc, TWSI_DATA);
    (*read)++;
  }
  rv = EFI_SUCCESS;
out:
  //mtx_unlock(&sc->mutex);
  return (rv);
}

STATIC
EFI_STATUS
A8kI2cWrite (
  IN EFI_HANDLE dev,
  IN OUT CONST UINT8 *buf,
  IN UINTN len,
  IN OUT UINTN *sent,
  IN UINTN timeout
  )
{
  A8K_I2C_INSTANCE *sc;
  UINT32 status;
  EFI_STATUS rv;

  sc = device_get_softc(dev);

  //mtx_lock(&sc->mutex);
  *sent = 0;
  while (*sent < len) {
    TWSI_WRITE(sc, TWSI_DATA, *buf++);

    A8kI2cClearIflg(sc);
    if (A8kI2cPollCtrl(sc, timeout, TWSI_CONTROL_IFLG)) {
      debugf("timeout writing data\n");
      rv = EFI_NO_RESPONSE;
      goto out;
    }

    status = TWSI_READ(sc, TWSI_STATUS);
    if (status != TWSI_STATUS_DATA_WR_ACK) {
      debugf("wrong status (%02x) while writing\n", status);
      rv = EFI_DEVICE_ERROR;
      goto out;
    }
    (*sent)++;
  }
  rv = EFI_SUCCESS;
out:
  //mtx_unlock(&sc->mutex);
  return (rv);
}

STATIC
EFI_STATUS
A8kI2cStartRequest (
  IN CONST EFI_I2C_MASTER_PROTOCOL *This,
  IN UINTN                         SlaveAddress,
  IN EFI_I2C_REQUEST_PACKET        *RequestPacket,
  IN EFI_EVENT                     Event      OPTIONAL,
  OUT EFI_STATUS                   *I2cStatus OPTIONAL
  )
{
  return EFI_SUCCESS;
}

EFI_I2C_MASTER_PROTOCOL gI2cMasterProtocol = {
  NULL,
  A8kI2cReset,
  A8kI2cStartRequest,
  NULL
};

EFI_DRIVER_BINDING_PROTOCOL gDriverBindingProtocol = {
  A8kI2cBindingSupported,
  A8kI2cBindingStart,
  A8kI2cBindingStop,
  0x10,			// version
  NULL,			// ImageHandle
  NULL			// DriverBindingHandle
};
