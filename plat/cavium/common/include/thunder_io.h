#ifndef __THUNDER_IO_H__
#define __THUNDER_IO_H__

#include <stdint.h>

#define PCI_MSIX_CAP_ID		0x11

/* Various IRQs ... */

#define IRQ_SEC_PHY_TIMER	0x1d /* secure physical generic timer */

/*
 * GPIO POWER IRQ for graceful shutdown.
 * GPIO_PWR_S_IRQ: Secure IRQ that comes first as soon as GPIO is triggered
 * GPIO_PWR_NS_IRQ: Non-Secure IRQ to kernel to initiate graceful shutdown
 * KEY_POWER_IRQ: Firmware generated IRQ to signal KEY_POWER to non-secure
 *                software
 */
#define GPIO_PWR_NS_IRQ		0x20
#define GPIO_PWR_S_IRQ		0x21
#define KEY_POWER_IRQ		GPIO_PWR_NS_IRQ

#define UAA0_IRQ		0x25
#define UAA1_IRQ		0x26
#define UAA2_IRQ		0x27
#define UAA3_IRQ		0x28

/*
 * TWSI-1 Secure IRQ for CLST events
 */
#define TWSI_1_S_IRQ		0x22

/*
 * 4 irq per PEM (INTA, INTB, INTC, INTD)
 * 12 PEM (6 per node)
 * 48 (0x30) IRQs needed
 */
#define PEM_INTBASE_IRQ		0x30
/* First available irq after PEM is 0x60 */

/* Keep ATF's SPI IRQs above Linux's 0..0x3f, in 0x40..0x9f range */

/* Modify the below to change ths SMMU SPI's */
/*
 * SMMU 0..3 NODE0
 * SMMU 4..7 NODE1
 */
#define SMMU0_GLOBAL_IRQ	0x64
#define SMMU0_CONTEXT_IRQ	0x65
#define SMMU1_GLOBAL_IRQ	0x66
#define SMMU1_CONTEXT_IRQ	0x67
#define SMMU2_GLOBAL_IRQ	0x68
#define SMMU2_CONTEXT_IRQ	0x69
#define SMMU3_GLOBAL_IRQ	0x6a
#define SMMU3_CONTEXT_IRQ	0x6b
#define SMMU4_GLOBAL_IRQ	0x6c
#define SMMU4_CONTEXT_IRQ	0x6d
#define SMMU5_GLOBAL_IRQ	0x6e
#define SMMU5_CONTEXT_IRQ	0x6f
#define SMMU6_GLOBAL_IRQ	0x70
#define SMMU6_CONTEXT_IRQ	0x71
#define SMMU7_GLOBAL_IRQ	0x72
#define SMMU7_CONTEXT_IRQ	0x73

/* Watchdog IRQs assigned dynamically from here up */
#define GTI_IRQ0		0x74

#define SMMU_GLOBAL_VECTOR_OFFSET 0x1000
#define SMMU_NUM_CONTEXTS	0x80

struct msix_cap {
    uint8_t cap_ID;
    uint8_t next_pointer;
    uint16_t messagecontrol;
    uint32_t message_upper_address;
    uint32_t table_offset_and_bir;

}__attribute__((__packed__));

struct pcie_config {
    uint16_t         vendor_id;
    uint16_t         devid;
    uint16_t         command;
    uint16_t         status;
    int         revision_id : 8;
    int         class_code : 24;
    int         cache_line_size : 8;
    int         lat_timer : 8;
    int         header_type : 8;
    int         bist : 8;
    uint32_t         baseaddress_reg[6];
    int         card_bus_cis_pointer;
    uint16_t         sub_system_vendor_id;
    uint16_t         sub_system_id;
    int         exp_rom_base_address;
    int         cap_pointer : 8;
    int         res0 : 24;
    int         res1;
    int         intterrupt_line : 8;
    int         intterrupt_pin : 8;
    int         max_gnt : 8;
    int         max_lat : 8;
    int         res2[1008];  /* make it 4K boundary */
} __attribute__((__packed__));

int init_thunder_io();

#endif
