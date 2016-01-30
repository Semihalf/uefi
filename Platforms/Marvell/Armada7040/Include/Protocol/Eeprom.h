#ifndef __EEPROM_H__
#define __EEPROM_H__

#define EFI_EEPROM_PROTOCOL_GUID { 0xcd728a1f, 0x45b5, 0x4feb, { 0x98, 0xc8, 0x31, 0x3d, 0xa8, 0x11, 0x74, 0x62 }}

typedef struct _EFI_EEPROM_PROTOCOL EFI_EEPROM_PROTOCOL;

#define EEPROM_READ   0x1
#define EEPROM_WRITE  0x0
typedef
EFI_STATUS
(EFIAPI *EFI_EEPROM_TRANSFER) (
  IN CONST EFI_EEPROM_PROTOCOL	*This,
  IN UINT16			Address,
  IN UINT32			Length,
  IN UINT8			*Buffer,
  IN UINT8			Operation
  );

struct _EFI_EEPROM_PROTOCOL {
  EFI_EEPROM_TRANSFER Transfer;
  UINT8		      Identifier;
};

extern EFI_GUID gEfiEepromProtocolGuid;
#endif
