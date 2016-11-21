#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <thunder_private.h>
#include "thunder_common.h"
#include "thunder_dt.h"
#include "thunder_ecam.h"
#include "thunder_io.h"

//#define DEBUG_ATF_IO

#ifdef DEBUG_ATF_IO
#define debug_io printf
#else
#define debug_io(x,...);
#endif

extern const struct ecam_platform_defs ecam_defs;

static const struct ecam_platform_defs *ecam_devices_ops_list[] = {
	&ecam_defs,
	NULL
};

static const struct ecam_platform_defs *ecam_devices_ops = NULL;

static void fixup_ecam(struct ecam_device *devs, int node, int ecam)
{
	int valid;

	if (!devs) {
		printf("WARNING : valid devs not found node %d ecam %d\n", node,
		       ecam);
		return;
	}

	for (; devs->ecam_id >= 0; devs++) {
		if (!devs->ns_visible)
			continue;
		valid = TRUE;
		if (devs->probe_fn)
			valid = devs->probe_fn(node, devs->probe_arg);
		if (!valid) {
			devs->ns_visible = FALSE;
			continue;
		}
	}
}

static uint64_t get_bar_val(struct pcie_config *pconfig, int bar)
{
	uint32_t cap;
	int cap_offset = pconfig->cap_pointer & 0xfc;
	uint64_t h, l, ret = 0;

	do {
		cap = *(uint32_t *) ((uint8_t *) pconfig + cap_offset);
		if ((cap & 0xff) == 0x14)
			break;
		cap_offset = (cap >> 8) & 0xfc;
	} while (cap_offset);
	if (cap_offset) {
		/* Found EA */
		int es, bei;
		int ne = (cap >> 16) & 0x3f;

		cap_offset += 4;
		while (ne) {
			uint32_t dw0 = *(uint32_t *) ((uint8_t *) pconfig + cap_offset + 0);

			es = dw0 & 7;
			bei = (dw0 >> 4) & 0xf;
			if (bei == bar) {
				h = 0;
				l = *(uint32_t *) ((uint8_t *) pconfig + cap_offset + 4);
				if (l & 2)
					h = *(uint32_t *) ((uint8_t *) pconfig + cap_offset + 12);
				ret = (h << 32) | (l & ~0xfull);
				break;
			}
			cap_offset += (es + 1) * 4;
			ne--;
		}

	} else {
		h = 0;
		l = pconfig->baseaddress_reg[bar];
		if (l & 4)
			h = pconfig->baseaddress_reg[bar + 1];
		ret = (h << 32) | (l & ~0xfull);
	}
	return ret;
}

static struct ecam_device *get_dev_idx(int node, int ecam, int bus, int dev,
				       int func)
{
	int i = 0;
	struct ecam_device *devs;

	devs = ecam_devices_ops->get_dev_idx(node, ecam);

	if (!devs) {
		printf("WARNING : valid devs not found  node %d ecam %d\n",
		       node, ecam);
		return NULL;
	}
	while (devs[i].ecam_id >= 0) {
		if (devs[i].ecam_id == ecam && devs[i].bus == bus &&
		    devs[i].dev == dev && devs[i].fun == func)
			return &devs[i];

		i++;
	}
	return NULL;
}

#ifdef DEBUG_ATF_IO

static void print_config_space(struct pcie_config *pconfig)
{
	int i;
	debug_io("************pcie config(%x:%x)***************\n",
		 pconfig->devid, pconfig->vendor_id);

	debug_io(" class_code\t\t::%6x\n", pconfig->class_code);
	debug_io(" header_type\t\t::%2x\n", (uint8_t) pconfig->header_type);
	for (i = 0; i < 6; i++)
		debug_io(" baseaddress_reg[%d]\t::%x\n", i,
			 pconfig->baseaddress_reg[i]);
	debug_io(" sub_system_vendor_id\t::%4x\n",
		 pconfig->sub_system_vendor_id);
	debug_io(" sub_system_id\t\t::%4x\n", pconfig->sub_system_id);
	debug_io(" cap_pointer\t\t::%2x\n", pconfig->cap_pointer);
	debug_io(" intterrupt_line\t::%2x\n", pconfig->intterrupt_line);
	debug_io(" intterrupt_pin\t\t::%2x\n", pconfig->intterrupt_pin);

	debug_io("**********************************************\n");
}
#else
static inline void print_config_space(struct pcie_config *pconfig)
{
}
#endif

static int enable_msix(uint64_t config_base, uint8_t cap_pointer, uint16_t * table_size,
		       uint8_t * bir)
{
	struct msix_cap *msicap;
	/* enable MSI-X */
	while (1 && cap_pointer) {
		msicap = (struct msix_cap *)(config_base + cap_pointer);
		if (msicap->cap_ID == PCI_MSIX_CAP_ID) {
			msicap->messagecontrol |= (1 << 15);
			*table_size = (msicap->messagecontrol & 0x3ff) + 1;
			*bir = (msicap->table_offset_and_bir & 0x7);
			break;
		}
		cap_pointer = msicap->next_pointer;
	}
	return 0;

}

static inline int smmu_get_irq(int node, int smmunr, int vectornr)
{
	int irq =
	    (node * 8) + smmunr +
	    ((vectornr < (SMMU_NUM_CONTEXTS * 2)) ? 0 : 4);
	switch (irq) {
	case 0:
		return SMMU0_CONTEXT_IRQ;
	case 1:
		return SMMU1_CONTEXT_IRQ;
	case 2:
		return SMMU2_CONTEXT_IRQ;
	case 3:
		return SMMU3_CONTEXT_IRQ;
	case 4:
		return SMMU0_GLOBAL_IRQ;
	case 5:
		return SMMU1_GLOBAL_IRQ;
	case 6:
		return SMMU2_GLOBAL_IRQ;
	case 7:
		return SMMU3_GLOBAL_IRQ;
	case 8:
		return SMMU4_CONTEXT_IRQ;
	case 9:
		return SMMU5_CONTEXT_IRQ;
	case 10:
		return SMMU6_CONTEXT_IRQ;
	case 11:
		return SMMU7_CONTEXT_IRQ;
	case 12:
		return SMMU4_GLOBAL_IRQ;
	case 13:
		return SMMU5_GLOBAL_IRQ;
	case 14:
		return SMMU6_GLOBAL_IRQ;
	case 15:
		return SMMU7_GLOBAL_IRQ;

	}
	return -1;
}

void init_smmu(int node, uint64_t config_base, uint64_t config_size)
{
	struct pcie_config *pconfig = (struct pcie_config *)config_base;
	uint8_t cap_pointer = pconfig->cap_pointer;
	uint16_t table_size = 0;
	uint8_t bir = 0;
	uint64_t vector_base = 0;
	int i;
	int smmunr = ((config_base >> 36) & 0xff) - 0x48;

	debug_io("SMMU(%d) NODE(%d) init called config_base:%lx size:%lx\n",
		 smmunr, node, config_base, config_size);
	print_config_space(pconfig);

	/* Allow all IO units to access only non secure memory 
	 * We can program secure devices later when they discovered.
	 *
	 */
	/* FIXME: Making devices non-secure from SMMU should be done differently */
	for (int i = 0; i < 2048; i++) {
		/* Only eMMC in SMMU0 is secure */
		/*if (i == 8 && smmunr == 0) {
			CSR_WRITE_PA((unsigned long)node,
				     CAVM_SMMUX_SSDRX(smmunr, i), 0xffffcfff);
			continue;
		}*/

		CSR_WRITE_PA((unsigned long)node, CAVM_SMMUX_SSDRX(smmunr, i),
			     0xffffffff);
	}

	enable_msix(config_base, cap_pointer, &table_size, &bir);
	/* initialise MSI-X Vector table */

	/* evn though size and bir got from generic code
	 * this is hilghy specific to cn88xx pass 1.0
	 * */
	if (1 && table_size) {
		debug_io("table_size :%x bir:%1x \n", table_size, bir);
		vector_base = get_bar_val(pconfig, bir);
		debug_io("MSI-X vector base:%lx\n", vector_base);

		/* configure interrupt vectors first */
		for (i = 0; i < table_size; i++) {
			*(uint64_t *) vector_base =
			    (i % 2) ? CAVM_GICD_CLRSPI_NSR : CAVM_GICD_SETSPI_NSR;
			vector_base += 8;
			*(uint64_t *) vector_base = smmu_get_irq(node, smmunr, i);
			vector_base += 8;
			//debug_io("SMMU(%d) : Vector:%d address :%lx irq:%d\n",smmunr, i, 
			//       ((i%2)? CAVM_GICD_CLRSPI_NSR : CAVM_GICD_SETSPI_NSR),smmu_get_irq(smmunr, i));
		}
	}
}

static void init_gpio(int node, uint64_t config_base, uint64_t config_size)
{
	struct pcie_config *pconfig = (struct pcie_config *)config_base;
	uint8_t cap_pointer = pconfig->cap_pointer;
	uint16_t table_size = 0;
	uint8_t bir = 0;
	uint64_t vector_base = 0;
	int i;
	uint32_t *sctl = (uint32_t *) (config_base + CAVM_PCCPF_XXX_VSEC_SCTL);
	union cavm_pccpf_xxx_vsec_ctl vsec_ctl;
	vsec_ctl.u = cavm_read32(config_base + CAVM_PCCPF_XXX_VSEC_CTL);
	//int gpio_pin = GPIO_PWR_PIN;
	int gpio_pin = bfdt.gpio_shutdown_ctl_in;

	if (gpio_pin < 0)
		return;

	/* not intialising node1 gpio */
	if (node)
		return;

	debug_io("setting secure/phys @%p\n", (void *)sctl);
	*sctl |= 3;

	printf("GPIO(%d) Node(%d) init called config_base:%lx size:%lx\n",
	       vsec_ctl.s.inst_num, node, config_base, config_size);
	print_config_space(pconfig);
	enable_msix(config_base, cap_pointer, &table_size, &bir);
	/* initialise MSI-X Vector table */

	/* evn though size and bir got from generic code
	 * this is highly specific to cn88xx pass 1.0
	 * */
	if (1 && table_size) {
		printf("table_size :%x bir:%1x \n", table_size, bir);
		vector_base = get_bar_val(pconfig, bir);
		printf("MSI-X vector base:%lx\n", vector_base);

		/* configure interrupt vectors first */
		for (i = 0; i < table_size; i++) {
			if (i == (48 + (gpio_pin * 2))
			    || i == (49 + (gpio_pin * 2))) {
				*(uint64_t *) vector_base = ((i % 2) ? CAVM_GICD_CLRSPI_SR : CAVM_GICD_SETSPI_SR);	//enable SECVEC (bit 0)
				//*(uint64_t *)vector_base = ((i%2)? CAVM_GICD_CLRSPI_NSR : CAVM_GICD_SETSPI_NSR) ; 
				vector_base += 8;
				*(uint64_t *) vector_base = GPIO_PWR_S_IRQ;
				vector_base += 8;
				printf("GPIO(%d)-NODE(%d): Vector:%d address :%lx irq:%d\n",
				       vsec_ctl.s.inst_num, node, i,
				       (i % 2) ? CAVM_GICD_CLRSPI_SR : CAVM_GICD_SETSPI_SR,
				       GPIO_PWR_S_IRQ);
			} else {
				vector_base += 0x10;
			}
		}
	}

}

static inline int uaa_get_irq(int uaanr)
{
	switch (uaanr) {
	case 0:
		return UAA0_IRQ;
	case 1:
		return UAA1_IRQ;
	case 2:
		return UAA2_IRQ;
	case 3:
		return UAA3_IRQ;
	default:
		return -1;
	}
}

static void init_uaa(int node, uint64_t config_base, uint64_t config_size)
{
	struct pcie_config *pconfig = (struct pcie_config *)config_base;
	uint8_t cap_pointer = pconfig->cap_pointer;
	uint16_t table_size = 0;
	uint8_t bir = 0;
	uint64_t vector_base = 0;
	int i, uaa_irq;
	union cavm_pccpf_xxx_vsec_ctl vsec_ctl;
	vsec_ctl.u = cavm_read32(config_base + CAVM_PCCPF_XXX_VSEC_CTL);

	/* not intialising node1 uaa */
	if (node)
		return;

	uaa_irq = uaa_get_irq(vsec_ctl.s.inst_num);

	if (uaa_irq < 0)
		return;

	debug_io("UAA(%d) Node(%d) init called config_base:%lx size:%lx\n",
		 vsec_ctl.s.inst_num, node, config_base, config_size);
	print_config_space(pconfig);
	enable_msix(config_base, cap_pointer, &table_size, &bir);
	/* initialise MSI-X Vector table */

	/* evn though size and bir got from generic code
	 * this is highly specific to cn88xx pass 1.0
	 * */
	if (1 && table_size) {
		debug_io("table_size :%x bir:%1x \n", table_size, bir);
		vector_base = get_bar_val(pconfig, bir);
		debug_io("MSI-X vector base:%lx\n", vector_base);

		/* configure interrupt vectors first */
		for (i = 0; i < table_size; i++) {
			*(uint64_t *) vector_base =
			    (i % 2) ? CAVM_GICD_CLRSPI_NSR : CAVM_GICD_SETSPI_NSR;
			vector_base += 8;
			printf("\r"); /* Need to revisit and remove this workaround */
			*(uint64_t *) vector_base = uaa_irq;
			vector_base += 8;
			debug_io("UAA(%d)-NODE(%d): Vector:%d address :%lx irq:%d\n",
				 vsec_ctl.s.inst_num, node, i,
				 ((i % 2) ? CAVM_GICD_CLRSPI_NSR : CAVM_GICD_SETSPI_NSR),
				 uaa_irq);
		}
	}
}

static void init_twsi(int node, uint64_t config_base, uint64_t config_size)
{
	struct pcie_config *pconfig = (struct pcie_config *)config_base;
	uint8_t cap_pointer = pconfig->cap_pointer;
	uint16_t table_size = 0;
	uint8_t bir = 0;
	uint64_t vector_base = 0;
	uint32_t devfn = (config_base >> 12) & 0xffUL;
	int i;
	uint32_t *sctl = (uint32_t *) (config_base + CAVM_PCCPF_XXX_VSEC_SCTL);
	union cavm_pccpf_xxx_vsec_ctl vsec_ctl;

	vsec_ctl.u = cavm_read32(config_base + CAVM_PCCPF_XXX_VSEC_CTL);

	/* not intialising node1 twsi */
	if (node)
		return;

	debug_io("Using TWSI func = 0x%x\n", devfn);

	if ((devfn & 0x7) != bfdt.bmc_boot_twsi_bus)
		return;

	debug_io("setting secure/phys @%p\n", (void *)sctl);
	*sctl |= 3;
	printf("TWSI1(%d) Node(%d) init called config_base:%lx size:%lx\n",
	       vsec_ctl.s.inst_num, node, config_base, config_size);
	print_config_space(pconfig);
	enable_msix(config_base, cap_pointer, &table_size, &bir);
	/* initialise MSI-X Vector table */

	/* even though size and bir got from generic code
	 * this is highly specific to cn88xx pass 1.0
	 */
	if (1 && table_size) {
		printf("table_size :%x bir:%1x \n", table_size, bir);
		vector_base = get_bar_val(pconfig, bir);
		printf("MSI-X vector base:%lx\n", vector_base);

		/* configure interrupt vectors first */
		for (i = 0; i < table_size; i++) {
			*(uint64_t *) vector_base =
			    (i % 2) ? CAVM_GICD_CLRSPI_SR : CAVM_GICD_SETSPI_SR;
			vector_base += 8;
			*(uint64_t *) vector_base = TWSI_1_S_IRQ;
			vector_base += 8;
			debug_io("TWSI1(%d)-NODE(%d): Vector:%d address :%lx irq:%d\n",
				 vsec_ctl.s.inst_num, node, i,
				 ((i % 2) ? CAVM_GICD_CLRSPI_SR : CAVM_GICD_SETSPI_SR),
				 TWSI_1_S_IRQ);

		}

	}
}

/* Probe RST_CTLX for PEM usability. */
static int ecam_probe_pem(int node, unsigned long arg)
{
	union cavm_rst_soft_prstx soft_prst;

	soft_prst.u = CSR_READ_PA(node, CAVM_RST_SOFT_PRSTX(arg));

	return soft_prst.s.soft_prst == 0;
}

static void init_pem(int node, uint64_t config_base, uint64_t config_size)
{
	struct pcie_config *pconfig = (struct pcie_config *)config_base;
	uint8_t cap_pointer = pconfig->cap_pointer;
	uint16_t table_size = 0;
	uint8_t bir = 0;
	uint64_t vector_base = 0;
	int i;
	uint64_t msg;
	union cavm_pccpf_xxx_vsec_ctl vsec_ctl;
	vsec_ctl.u = cavm_read32(config_base + CAVM_PCCPF_XXX_VSEC_CTL);

	if (!ecam_probe_pem(node, vsec_ctl.s.inst_num))
		return;

	debug_io("PEM(%d) Node(%d) init called config_base:%lx size:%lx\n",
		 vsec_ctl.s.inst_num, node, config_base, config_size);
	print_config_space(pconfig);
	enable_msix(config_base, cap_pointer, &table_size, &bir);
	/* initialise MSI-X Vector table */

	/* evn though size and bir got from generic code
	 * this is highly specific to cn88xx pass 1.0
	 * */
	if (table_size) {
		debug_io("table_size :%x bir:%1x \n", table_size, bir);
		vector_base = get_bar_val(pconfig, bir);
		debug_io("MSI-X vector base:%lx\n", vector_base);

		/* configure interrupt vectors first */
		for (i = 0; i < table_size; i++) {
			*(uint64_t *) vector_base = (i % 2) ? CAVM_GICD_CLRSPI_NSR : CAVM_GICD_SETSPI_NSR;
			vector_base += 8;
			if (i >= 4 && i < 12)
				msg = ((i - 4) / 2) + PEM_INTBASE_IRQ +
					(24 * node) + (4 * vsec_ctl.s.inst_num);
			else
				msg = 0x100000000ull;	/* Masked */
			*(uint64_t *) vector_base = msg;
			vector_base += 8;
			debug_io
			    ("PEM(%d)-NODE(%d): Vector:%d address :%lx irq:%lu\n",
			     vsec_ctl.s.inst_num, node, i,
			     ((i % 2) ? CAVM_GICD_CLRSPI_NSR : CAVM_GICD_SETSPI_NSR),
			     msg);
		}
	}
}

void init_gti(int node, uint64_t config_base, uint64_t config_size)
{
	struct pcie_config *pconfig = (struct pcie_config *)config_base;
	uint8_t cap_pointer;
	uint16_t table_size = 0;
	uint8_t bir = 0;

	debug_io("GTI NODE(%d) init called config_base:%lx size:%lx\n", node,
		 config_base, config_size);
	cap_pointer = pconfig->cap_pointer;
	print_config_space(pconfig);

	uint32_t *sctl = (uint32_t *) (config_base + CAVM_PCCPF_XXX_VSEC_SCTL);
	debug_io("setting secure/phys @%p\n", (void *)sctl);
	*sctl |= 3;
	enable_msix(config_base, cap_pointer, &table_size, &bir);

	/* initialise MSI-X Vector table */
	if (table_size) {
		uint64_t vector_base = pconfig->baseaddress_reg[bir] & ~0xf;
		vector_base |= ((uint64_t) pconfig->baseaddress_reg[bir + 1] << 32);
		debug_io("table_size :%x bir:%1x \n", table_size, bir);
		debug_io("MSI-X vector base:%lx\n", vector_base);
	}

	/* populate MSI-X Vector table elsewhere */
}

/*
 *This is the callback structure that holds callback for 
 *different devices.
 *
 */
struct ecam_callback callbacks[] = {
	{0xa008, 0x177d, init_smmu},
	{0xa00a, 0x177d, init_gpio},
	{0xa00f, 0x177d, init_uaa},
	{0xa012, 0x177d, init_twsi},
	{0xa017, 0x177d, init_gti},
	{0xa020, 0x177d, init_pem},
	{0, 0, 0},		//no more callbacks
};

static void find_and_call_init(int node, int devid, int vendor_id, uint64_t base,
			       uint64_t size)
{
	int i = 0;

	while (callbacks[i].io_init) {
		if (callbacks[i].devid == devid
		    && callbacks[i].vendor_id == vendor_id) {
			debug_io("'calling init_io .. %lx\n",
				 (uint64_t) callbacks[i].io_init);
			callbacks[i].io_init(node, base, size);
			//dont break allow multiple callbacks..so that inits can be specific
		}
		i++;
	}
}

static inline void disable_bus(int node, int ecam, int bus)
{
	union cavm_ecamx_busx_sdis bus_sdis;

	/* disable bus */
	bus_sdis.u = CSR_READ_PA(node, CAVM_ECAMX_BUSX_SDIS(ecam, bus));
	bus_sdis.s.sec = 1;
	CSR_WRITE_PA(node, CAVM_ECAMX_BUSX_SDIS(ecam, bus), bus_sdis.u);
	debug_io("disable_bus %d:%d:%d\n", node, ecam, bus);
}

static inline void enable_bus(int node, int ecam, int bus)
{
	union cavm_ecamx_busx_sdis bus_sdis;
	union cavm_ecamx_busx_nsdis bus_nsdis;

	/* enable bus */
	bus_sdis.u = CSR_READ_PA(node, CAVM_ECAMX_BUSX_SDIS(ecam, bus));
	bus_sdis.s.sec = 0;
	bus_sdis.s.dis = 0;
	CSR_WRITE_PA(node, CAVM_ECAMX_BUSX_SDIS(ecam, bus), bus_sdis.u);

	bus_nsdis.u = CSR_READ_PA(node, CAVM_ECAMX_BUSX_NSDIS(ecam, bus));
	bus_nsdis.s.dis = 0;
	CSR_WRITE_PA(node, CAVM_ECAMX_BUSX_NSDIS(ecam, bus), bus_nsdis.u);

	debug_io("enable_bus %d:%d:%d\n", node, ecam, bus);
}

static inline void disable_dev(int node, int ecam, int dev)
{
	union cavm_ecamx_devx_sdis dev_sdis;

	/* disable device */
	dev_sdis.u = CSR_READ_PA(node, CAVM_ECAMX_DEVX_SDIS(ecam, dev));
	dev_sdis.s.sec = 1;
	CSR_WRITE_PA(node, CAVM_ECAMX_DEVX_SDIS(ecam, dev), dev_sdis.u);
	debug_io("disable_dev %d:%d:%02x\n", node, ecam, (unsigned)dev);
}

static inline void enable_dev(int node, int ecam, int dev)
{
	union cavm_ecamx_devx_sdis dev_sdis;
	union cavm_ecamx_devx_nsdis dev_nsdis;

	/* enable device */
	dev_sdis.u = CSR_READ_PA(node, CAVM_ECAMX_DEVX_SDIS(ecam, dev));
	dev_sdis.s.sec = 0;
	dev_sdis.s.dis = 0;
	CSR_WRITE_PA(node, CAVM_ECAMX_DEVX_SDIS(ecam, dev), dev_sdis.u);

	dev_nsdis.u = CSR_READ_PA(node, CAVM_ECAMX_DEVX_NSDIS(ecam, dev));
	dev_nsdis.s.dis = 0;
	CSR_WRITE_PA(node, CAVM_ECAMX_DEVX_NSDIS(ecam, dev), dev_nsdis.u);

	debug_io("enable_dev %d:%d:%02x\n", node, ecam, (unsigned)dev);
}

static inline void disable_func(int node, int ecam, int func)
{
	union cavm_ecamx_rslx_sdis rsl_sdis;
	/* disable function */
	rsl_sdis.u = CSR_READ_PA(node, CAVM_ECAMX_RSLX_SDIS(ecam, func));
	rsl_sdis.s.sec = 1;
	CSR_WRITE_PA(node, CAVM_ECAMX_RSLX_SDIS(ecam, func), rsl_sdis.u);
	debug_io("disable_func %d:%d:%02x\n", node, ecam, (unsigned)func);
}

static inline void enable_func(int node, int ecam, int func)
{
	union cavm_ecamx_rslx_sdis rsl_sdis;
	union cavm_ecamx_rslx_nsdis rsl_nsdis;
	/* enable function */
	rsl_sdis.u = CSR_READ_PA(node, CAVM_ECAMX_RSLX_SDIS(ecam, func));
	rsl_sdis.s.sec = 0;
	rsl_sdis.s.dis = 0;
	CSR_WRITE_PA(node, CAVM_ECAMX_RSLX_SDIS(ecam, func), rsl_sdis.u);

	rsl_nsdis.u = CSR_READ_PA(node, CAVM_ECAMX_RSLX_NSDIS(ecam, func));
	rsl_nsdis.s.dis = 0;
	CSR_WRITE_PA(node, CAVM_ECAMX_RSLX_NSDIS(ecam, func), rsl_nsdis.u);

	debug_io("enable_func %d:%d:%02x\n", node, ecam, (unsigned)func);
}

static inline int skip_bus(int node, int ecam, int bus)
{
	if (ecam_devices_ops->disable_device_on_bus(node, bus))
		return 1;
	if (bus > ecam_devices_ops->get_max_bus(ecam))
		return 1;
	return 0;
}

static inline int is_rsl_bus(int ecam, int bus)
{
	if (ecam == 0 && bus == 1)
		return 1;
	return 0;
}

static unsigned prev_ns_func = 0; /* Hold number of last ns func */
static inline int walk_through_functions(int node, int ecam,
					 struct pcie_config *pconfig)
{
	int i = 0;
	int bus, dev, func;
	uint64_t config_base;
	struct ecam_device *devs;
	union cavm_pccpf_xxx_vsec_ctl vsec_ctl;

	config_base = (uint64_t) pconfig;

	for (i = 0; i < 256; i++) {
		bus = (((uint64_t) pconfig) >> 20) & 0xffUL;
		dev = 0;
		func = (((uint64_t) pconfig) >> 12) & 0xffUL;
		devs = get_dev_idx(node, ecam, bus, dev, func);

		if (devs && pconfig->devid != 0xffffUL
		    && pconfig->vendor_id != 0xffffUL) {
			find_and_call_init(node, pconfig->devid,
					   pconfig->vendor_id, (uint64_t) pconfig,
					   sizeof(struct pcie_config));

			/* Program ARI capability of the previous device */
			if (devs->ns_visible) {
				vsec_ctl.u = cavm_read32(config_base +
							 sizeof(struct pcie_config) * prev_ns_func +
							 CAVM_PCCPF_XXX_VSEC_CTL);
				vsec_ctl.s.nxtfn_ns = func;
				cavm_write32(config_base + sizeof(struct pcie_config) * prev_ns_func +
					     CAVM_PCCPF_XXX_VSEC_CTL, vsec_ctl.u);

				enable_func(node, ecam, func);
				prev_ns_func = func;
			} else {
				disable_func(node, ecam, func);
			}
		} else {
			disable_func(node, ecam, func);
		}
		pconfig++; /* skip to next function */
	}

	return 0;
}

static inline int walk_through_devices(int node, int ecam,
				       struct pcie_config *pconfig)
{
	int i = 0;
	int bus, dev, func;
	uint64_t config_base;
	struct ecam_device *devs;

	for (i = 0; i < 32; i++) {
		config_base = (uint64_t) pconfig;
		bus = (config_base >> 20) & 0xffUL;
		dev = (config_base >> 15) & 0x1fUL;
		func = (config_base >> 12) & 0x7UL;
		devs = get_dev_idx(node, ecam, bus, dev, func);

		if (devs && pconfig->devid != 0xffffUL
		    && pconfig->vendor_id != 0xffffUL) {
			find_and_call_init(node, pconfig->devid,
					   pconfig->vendor_id, (uint64_t) pconfig,
					   sizeof(struct pcie_config));
			if (devs->ns_visible)
				enable_dev(node, ecam, dev);
			else
				disable_dev(node, ecam, dev);
		} else {
			disable_dev(node, ecam, dev);
		}
		pconfig += 8;	//skip to next device
	}

	return 0;
}

int init_thunder_io(int node_count)
{
	int ecam_id = 0, i = 0;
	int bus, node, offset_ecams;
	int ecams_per_node = thunder_get_num_ecams_per_node();
	int soc_type = CAVIUM_SOC_TYPE();
	uint64_t config_base;
	uint64_t ecam_base;
	uint64_t ecam_size;
	struct pcie_config *pconfig;

	/* Match ops with SoC type */
	while (ecam_devices_ops_list[i]) {
		if (soc_type == ecam_devices_ops_list[i]->soc_type) {
			ecam_devices_ops = ecam_devices_ops_list[i];
			break;
		}
		i++;
	}

	if (!ecam_devices_ops) {
		printf("ERROR: valid SoC not found %d\n", soc_type);
		return -1;
	}

	/* Enumeration */
	for (node = 0; node < node_count; node++) {
		for (ecam_id = 0; ecam_id < ecams_per_node; ecam_id++) {
			fixup_ecam(ecam_devices_ops->get_dev_idx(node, ecam_id),
				   node, ecam_id);

			offset_ecams = (node * ecams_per_node) + ecam_id;

			debug_io
			    ("starting Ecam(%d) of node %d offset_ecams %d scan..\n",
			     ecam_id, node, offset_ecams);

			ecam_base =
			    ecam_devices_ops->get_config_addr(node, ecam_id);
			ecam_size =
			    ecam_devices_ops->get_config_size(node, ecam_id);

			pconfig = (struct pcie_config *)ecam_base;

			while ((uint64_t) pconfig <
			       (ecam_base + ecam_size -
				sizeof(struct pcie_config))) {
				config_base = (uint64_t) pconfig;
				bus = (config_base >> 20) & 0xffUL;
				if (skip_bus(node, offset_ecams, bus)) {
					disable_bus(node, ecam_id, bus);
				} else {
					enable_bus(node, ecam_id, bus);
					if (is_rsl_bus(ecam_id, bus))
						walk_through_functions(node,
								       ecam_id,
								       pconfig);
					else if (bus == 0)
						walk_through_devices(node,
								     ecam_id,
								     pconfig);
				}
				pconfig += 256;
			}
		}
	}
	return 0;
}
