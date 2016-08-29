#include <platform_def.h>
#include <thunder_private.h>
#include <debug.h>
#include <debug.h>
#include <assert.h>

#ifndef DEBUG_THUNDER_PCI
#define DEBUG_THUNDER_PCI 0
#endif

#if DEBUG_THUNDER_PCI
#define ECAM_TRACE(...) VERBOSE(__VA_ARGS__)
#else
#define ECAM_TRACE(...) ((void)0)
#endif

#define THUNDER_ECAM_PER_NODE 4
#define THUNDER_ECAM_MAX_BUS 256

struct ecam_device {
	int bus;
	int dev;
	int func;
};

static struct ecam_device thunder_ecam_devs0[] = {
	{0,  1,   0}, /* PCCBR_MRML */
	{0,  2,   0}, /* SMMU 0 */
	{0,  3,   0}, /* GIC */
	{0,  4,   0}, /* GTI */
	{0,  6,   0}, /* GPIO */
	{0,  7,   0}, /* MPI */
	{0,  8,   0}, /* MIO_PTP */
	{0,  9,   0}, /* RNM */
	{0, 16,   0}, /* USB 0 */
	{0, 17,   0}, /* USB 1 */
	{0, 20,   0}, /* PCCBR_RAD */
	{0, 21,   0}, /* PCCBR_ZIP */
	{0, 22,   0}, /* PCCBR_DFA */
	{1,  0,   0}, /* MRML */
	{1,  0,   1}, /* RST */
	// 102 DAP
	// 103 MIO_FUS
	// 104 FUSF
	{1,  0,   5}, /* OCX */
	// 108 NCSI
	// 109 L2C
	// 10A Serial GPIO
	{1,  0,  11}, /* SMI */
	{1,  0,  12}, /* MIO_EMM */
	// 10D KEY
	// 10E MIO_BOOT

	{1 , 0,  48}, /* L2C-TAD 0 */
	{1 , 0,  49}, /* L2C-TAD 1 */
	{1 , 0,  50}, /* L2C-TAD 2 */
	{1 , 0,  51}, /* L2C-TAD 3 */
	{1 , 0,  52}, /* L2C-TAD 4 */
	{1 , 0,  53}, /* L2C-TAD 5 */
	{1 , 0,  54}, /* L2C-TAD 6 */
	{1 , 0,  55}, /* L2C-TAD 7 */
	{1 , 0,  56}, /* L2C-CBC 0 */
	{1 , 0,  57}, /* L2C-CBC 1 */
	{1 , 0,  58}, /* L2C-CBC 2 */
	{1 , 0,  59}, /* L2C-CBC 3 */
	{1 , 0,  60}, /* L2C-MCI 0 */
	{1 , 0,  61}, /* L2C-MCI 1 */
	{1 , 0,  62}, /* L2C-MCI 2 */
	{1 , 0,  63}, /* L2C-MCI 3 */

	{1,  0,  64}, /* UAA 0 */
	{1,  0,  65}, /* UAA 1 */
	{1 , 0,  72}, /* TWSI 0 */
	{1 , 0,  73}, /* TWSI 1 */
	{1 , 0,  74}, /* TWSI 2 */
	{1 , 0,  75}, /* TWSI 3 */
	{1 , 0,  76}, /* TWSI 4 */
	{1 , 0,  77}, /* TWSI 5 */

	{1 , 0,  80}, /* LMC 0 */
	{1 , 0,  81}, /* LMC 1 */
	{1 , 0,  82}, /* LMC 2 */
	{1 , 0,  83}, /* LMC 3 */

	// 158 IOBN 0
	// 159 IOBN 1

	{1 , 0,  96}, /* OCLA 0 */
	{1 , 0,  97}, /* OCLA 1 */
	{1 , 0,  98}, /* OCLA 2 */
	{1 , 0,  99}, /* OCLA 3 */

	{1 , 0, 112}, /* PEM 0 */
	{1 , 0, 113}, /* PEM 1 */
	{1 , 0, 114}, /* PEM 2 */
	{1 , 0, 115}, /* PEM 3 */
	{1 , 0, 116}, /* PEM 4 */
	{1 , 0, 117}, /* PEM 5 */

	{1,  0, 128}, /* BGX 0 */
	{1,  0, 129}, /* BGX 1 */

	// 1E0 GSER 0
	// 1E1 GSER 1
	// 1E2 GSER 2
	// 1E3 GSER 3
	// 1E4 GSER 4
	// 1E5 GSER 5
	// 1E6 GSER 6
	// 1E7 GSER 7
	// 1E8 GSER 8
	// 1E9 GSER 9
	// 1EA GSER 10
	// 1EB GSER 11
	// 1EC GSER 12
	// 1ED GSER 13

	{2,  0,   0}, /* RAD */
	{3,  0,   0}, /* ZIP */
	{4,  0,   0}, /* HFA */
	{-1, 0,   0},
};

static struct ecam_device thunder_ecam_devs1[] = {
	{0,  1, 0},            /* SMMU 1 */
	// 0, 2, 0 SLI 0
	{0,  4, 0}, /* SATA 0 */
	{0,  5, 0}, /* SATA 1 */
	{0,  6, 0}, /* SATA 2 */
	{0,  7, 0}, /* SATA 3 */
	{0,  8, 0}, /* SATA 4 */
	{0,  9, 0}, /* SATA 5 */
	{0, 10, 0}, /* SATA 6 */
	{0, 11, 0}, /* SATA 7 */
	// 0, 16, 0 PCIeRC 0
	// 0, 18, 0 PCIeRC 1
	// 0, 20, 0 PCIeRC 2
	{-1, 0, 0},
};

static struct ecam_device thunder_ecam_devs2[] = {
	{0,  1, 0},            /* SMMU 2 */
	{0,  2, 0},            /* PCCBR_NIC */
	{0,  3, 0},            /* TNS */
	{1,  0, 0},            /* NIC */
	{-1, 0, 0},
};

static struct ecam_device thunder_ecam_devs3[] = {
	{0,  1, 0}, /* SMMU 3 */
	// 0, 2, 0 SLI 1
	{0,  4, 0}, /* SATA 8 */
	{0,  5, 0}, /* SATA 9 */
	{0,  6, 0}, /* SATA 10 */
	{0,  7, 0}, /* SATA 11 */
	{0,  8, 0}, /* SATA 12 */
	{0,  9, 0}, /* SATA 13 */
	{0, 10, 0}, /* SATA 14 */
	{0, 11, 0}, /* SATA 15 */
	// 0, 16, 0 PCIeRC 3
	// 0, 18, 0 PCIeRC 4
	// 0, 20, 0 PCIeRC 5
	{-1, 0, 0},
};

static struct ecam_device *thunder_ecam_devices[THUNDER_ECAM_PER_NODE] = {
	thunder_ecam_devs0,
	thunder_ecam_devs1,
	thunder_ecam_devs2,
	thunder_ecam_devs3,
};

static int ecam_errata_workaround(void)
{
	uint64_t midr = read_midr();

	/* Check if T88, only pass1.0 chip needs workaround */
	if (IS_THUNDER_PASS(midr, 1, 0)) {
		return 1;
	}

	return 0;
}


static inline void thunder_ecam_bus_disable(unsigned node, unsigned ecam, unsigned bus)
{
	ecamx_busx_sdis_t bus_sdis;

	ECAM_TRACE("%s %d:%d:%d\n", __func__, node, ecam, bus);

	/* Pass 1.0 ECAM errata */
	if (ecam_errata_workaround())
		return;

	/* disable bus */
	bus_sdis.u = CSR_READ_PA(node, ECAMX_BUSX_SDIS(ecam, bus));
	bus_sdis.s.sec = 1;
	CSR_WRITE_PA(node, ECAMX_BUSX_SDIS(ecam, bus), bus_sdis.u);
}

static inline void thunder_ecam_bus_enable(unsigned node, unsigned ecam, unsigned bus)
{
	ecamx_busx_sdis_t bus_sdis;
	ecamx_busx_nsdis_t bus_nsdis;

	ECAM_TRACE("%s %d:%d:%d\n", __func__, node, ecam, bus);

	/* Pass 1.0 ECAM errata */
	if (ecam_errata_workaround())
		return;

	/* enable bus */
	bus_sdis.u = CSR_READ_PA(node, ECAMX_BUSX_SDIS(ecam, bus));
	bus_sdis.s.sec = 0;
	bus_sdis.s.dis = 0;
	CSR_WRITE_PA(node, ECAMX_BUSX_SDIS(ecam, bus), bus_sdis.u);

	bus_nsdis.u = CSR_READ_PA(node, ECAMX_BUSX_NSDIS(ecam, bus));
	bus_nsdis.s.dis = 0;
	CSR_WRITE_PA(node, ECAMX_BUSX_NSDIS(ecam, bus), bus_nsdis.u);
}

static unsigned thunder_ecam_bus_skip(unsigned node, unsigned ecam, unsigned bus)
{
	if (ecam == 0)
		return bus > 4;
	else if (ecam == 2)
		return bus > 1;
	else
		return bus > 0;
}

static int thunder_ecam_bus_is_rsl(unsigned node, unsigned ecam, unsigned bus)
{
	return (ecam == 0 && bus == 1);
}

static void thunder_ecam_dev_secure(unsigned node, unsigned ecam, unsigned bus, unsigned dev, unsigned func)
{
	ECAM_TRACE("%s %d:%d:%d:%x:%x\n", __func__, node, ecam, bus, dev, func);

	if (thunder_ecam_bus_is_rsl(node, ecam, bus)) {
		ecamx_rslx_sdis_t rsl_sdis;

		/* disable function */
		rsl_sdis.u = CSR_READ_PA(node, ECAMX_RSLX_SDIS(ecam, func));
		rsl_sdis.s.sec = 1;
		CSR_WRITE_PA(node, ECAMX_RSLX_SDIS(ecam, func), rsl_sdis.u);
	} else if (bus == 0) {
		ecamx_devx_sdis_t dev_sdis;

		/* Pass 1.0 ECAM errata */
		if(ecam_errata_workaround())
			return;

		/* disable device */
		dev_sdis.u = CSR_READ_PA(node,ECAMX_DEVX_SDIS(ecam, dev));
		dev_sdis.s.sec = 1;
		CSR_WRITE_PA(node, ECAMX_DEVX_SDIS(ecam, dev), dev_sdis.u);
	}
}

static void thunder_ecam_dev_nonsecure(unsigned node, unsigned ecam, unsigned bus, unsigned dev, unsigned func)
{
	ECAM_TRACE("%s %d:%d:%d:%x:%x\n", __func__, node, ecam, bus, dev, func);

	if (thunder_ecam_bus_is_rsl(node, ecam, bus)) {
		ecamx_rslx_sdis_t rsl_sdis;
		ecamx_rslx_nsdis_t rsl_nsdis;

		/* enable function */
		rsl_sdis.u = CSR_READ_PA(node, ECAMX_RSLX_SDIS(ecam, func));
		rsl_sdis.s.sec = 0;
		rsl_sdis.s.dis = 0;
		CSR_WRITE_PA(node, ECAMX_RSLX_SDIS(ecam, func), rsl_sdis.u);

		rsl_nsdis.u = CSR_READ_PA(node, ECAMX_RSLX_NSDIS(ecam, func));
		rsl_nsdis.s.dis = 0;
		CSR_WRITE_PA(node, ECAMX_RSLX_NSDIS(ecam, func), rsl_nsdis.u);
	} else if (bus == 0) {
		ecamx_devx_sdis_t dev_sdis;
		ecamx_devx_nsdis_t dev_nsdis;

		/* Pass 1.0 ECAM errata */
		if(ecam_errata_workaround())
			return;

		/* enable device */
		dev_sdis.u = CSR_READ_PA(node,ECAMX_DEVX_SDIS(ecam, dev));
		dev_sdis.s.sec = 0;
		dev_sdis.s.dis = 0;
		CSR_WRITE_PA(node, ECAMX_DEVX_SDIS(ecam, dev), dev_sdis.u);

		dev_nsdis.u = CSR_READ_PA(node,ECAMX_DEVX_NSDIS(ecam, dev));
		dev_nsdis.s.dis = 0;
		CSR_WRITE_PA(node, ECAMX_DEVX_NSDIS(ecam, dev), dev_nsdis.u);
	}
}

/* Workaround: reading the space for unexisting device will cause exception*/
static uint64_t thunder_ecam_dev_config(unsigned node, unsigned ecam, unsigned bus, unsigned dev, unsigned func)
{
	uint64_t ecam_pconfig = CSR_PA(node, ECAMX_PF_BAR2(ecam));
	struct ecam_device *devs = thunder_ecam_devices[ecam];
	unsigned i;

	for (i = 0; devs[i].bus != -1; i++) {
		if (bus < devs[i].bus ||
		   (bus == devs[i].bus && dev < devs[i].dev) ||
		   (bus == devs[i].bus && dev == devs[i].dev && func < devs[i].func))
			return 0;

		if (bus == devs[i].bus && dev == devs[i].dev && func == devs[i].func)
			return ecam_pconfig + (bus << 20) + (dev << 15) + (func << 12);
	}

	return 0;
}

static int thunder_ecam_dev_skip(unsigned node, unsigned ecam, unsigned bus, unsigned dev, unsigned func)
{
	uint64_t pconfig = thunder_ecam_dev_config(node, ecam, bus, dev, func);
	pccpf_xxx_id_t pccpf_id;

	if (!pconfig)
		return 1;

	pccpf_id.u = cavm_read32(pconfig + offset_PCCPF_XXX_ID);
	if (pccpf_id.s.vendid == 0xffff || pccpf_id.s.devid == 0xffff)
		return 1;

	return 0;
}

#define THUNDER_ECAM_DEV_SECURE		2
#define THUNDER_ECAM_DEV_NS		1
#define THUNDER_ECAM_DEV_DISABLE	0

static int thunder_ecam_secure_init(unsigned node, uint64_t pconfig)
{
	return THUNDER_ECAM_DEV_SECURE;
}

static int thunder_ecam_smmu_init(unsigned node, uint64_t pconfig)
{
	pccpf_xxx_vsec_ctl_t vsec_ctl;
	unsigned i;

	vsec_ctl.u = cavm_read32(pconfig + offset_PCCPF_XXX_VSEC_CTL);
	INFO("Node %d SMMU(%d) init at %lx\n", node, vsec_ctl.s.inst_num, pconfig);

	/* Mark all devices as non-secure */
	for (i = 0; i < 2048; i++)
		CSR_WRITE_PA(node, SMMUX_SSDRX(vsec_ctl.s.inst_num, i), 0xffffffff);

	return THUNDER_ECAM_DEV_SECURE;
}

static uint64_t thunder_ecam_smmu_get_msg(unsigned node, uint64_t pconfig, unsigned idx)
{
	pccpf_xxx_vsec_ctl_t vsec_ctl;

	vsec_ctl.u = cavm_read32(pconfig + offset_PCCPF_XXX_VSEC_CTL);

	return THUNDER_IRQ_SMMU_BASE + node * 8 + vsec_ctl.s.inst_num * 2 + (idx < 0x100 ? 1 : 0);
}

static int thunder_ecam_gpio_init(unsigned node, uint64_t pconfig)
{
	pccpf_xxx_vsec_ctl_t vsec_ctl __unused;

	vsec_ctl.u = cavm_read32(pconfig + offset_PCCPF_XXX_VSEC_CTL);
	INFO("Node %d GPIO(%d) init at %lx\n", node, vsec_ctl.s.inst_num, pconfig);

	return THUNDER_ECAM_DEV_SECURE;
}

static uint64_t thunder_ecam_gpio_get_msg(unsigned node, uint64_t pconfig, unsigned idx)
{
	return THUNDER_IRQ_MASKED;
}

static int thunder_ecam_uaa_init(unsigned node, uint64_t pconfig)
{
	pccpf_xxx_vsec_ctl_t vsec_ctl __unused;

	vsec_ctl.u = cavm_read32(pconfig + offset_PCCPF_XXX_VSEC_CTL);
	INFO("Node %d UAA(%d) init at %lx\n", node, vsec_ctl.s.inst_num, pconfig);

	return THUNDER_ECAM_DEV_SECURE;
}

static uint64_t thunder_ecam_uaa_get_msg(unsigned node, uint64_t pconfig, unsigned idx)
{
	pccpf_xxx_vsec_ctl_t vsec_ctl;

	vsec_ctl.u = cavm_read32(pconfig + offset_PCCPF_XXX_VSEC_CTL);

	if (vsec_ctl.s.inst_num == 0)
		return THUNDER_IRQ_UAA0;
	else
		return THUNDER_IRQ_UAA1;
}

static int thunder_ecam_gti_init(unsigned node, uint64_t pconfig)
{
	pccpf_xxx_vsec_ctl_t vsec_ctl __unused;

	vsec_ctl.u = cavm_read32(pconfig + offset_PCCPF_XXX_VSEC_CTL);
	INFO("Node %d GTI(%d) init at %lx\n", node, vsec_ctl.s.inst_num, pconfig);

	return THUNDER_ECAM_DEV_SECURE;
}

static uint64_t thunder_ecam_gti_get_msg(unsigned node, uint64_t pconfig, unsigned idx)
{
	if (idx == GTI_INT_VEC_E_SECURE_WATCHDOG ||
	    idx == GTI_INT_VEC_E_SECURE_WATCHDOG_CLEAR)
		return THUNDER_IRQ_GTI_WDOG;
	return THUNDER_IRQ_MASKED;
}

static int thunder_ecam_twsi_init(unsigned node, uint64_t pconfig)
{
	pccpf_xxx_vsec_ctl_t vsec_ctl __unused;

	vsec_ctl.u = cavm_read32(pconfig + offset_PCCPF_XXX_VSEC_CTL);
	INFO("Node %d TWSI(%d) init at %lx\n", node, vsec_ctl.s.inst_num, pconfig);

	return THUNDER_ECAM_DEV_NS;
}

static uint64_t thunder_ecam_twsi_get_msg(unsigned node, uint64_t pconfig, unsigned idx)
{
	return THUNDER_IRQ_MASKED;
}

static int thunder_ecam_sata_init(unsigned node, uint64_t pconfig)
{
	pccpf_xxx_vsec_ctl_t vsec_ctl;
	gserx_cfg_t cfg;

	vsec_ctl.u = cavm_read32(pconfig + offset_PCCPF_XXX_VSEC_CTL);
	INFO("Node %d SATA(%d) init at %lx\n", node, vsec_ctl.s.inst_num, pconfig);

	cfg.u = CSR_READ_PA(node, GSERX_CFG(vsec_ctl.s.inst_num / 4 + 2));

	return cfg.s.sata ? THUNDER_ECAM_DEV_NS : THUNDER_ECAM_DEV_DISABLE;
}

static int thunder_ecam_pem_init(unsigned node, uint64_t pconfig)
{
	pccpf_xxx_vsec_ctl_t vsec_ctl;
	rst_soft_prstx_t soft_prstx;

	vsec_ctl.u = cavm_read32(pconfig + offset_PCCPF_XXX_VSEC_CTL);
	INFO("Node %d PEM(%d) init at %lx\n", node, vsec_ctl.s.inst_num, pconfig);

	soft_prstx.u = CSR_READ_PA(node, RST_SOFT_PRSTX(vsec_ctl.s.inst_num));

	return soft_prstx.s.soft_prst ? THUNDER_ECAM_DEV_DISABLE : THUNDER_ECAM_DEV_SECURE;
}

static uint64_t thunder_ecam_pem_get_msg(unsigned node, uint64_t pconfig, unsigned idx)
{
	pccpf_xxx_vsec_ctl_t vsec_ctl;

	vsec_ctl.u = cavm_read32(pconfig + offset_PCCPF_XXX_VSEC_CTL);

	if (idx < 4 || idx >= 12)
		return THUNDER_IRQ_MASKED;

	return THUNDER_IRQ_PEM_BASE + (24 * node) + 4 * vsec_ctl.s.inst_num + (idx - 4) / 2;
}

static int thunder_ecam_lmc_init(unsigned node, uint64_t pconfig)
{
	pccpf_xxx_vsec_ctl_t vsec_ctl;

	vsec_ctl.u = cavm_read32(pconfig + offset_PCCPF_XXX_VSEC_CTL);
	INFO("Node %d LMC(%d) init at %lx\n", node, vsec_ctl.s.inst_num, pconfig);

	WARN("Enabled: %d\n", thunder_dram_is_lmc_enabled(node, vsec_ctl.s.inst_num));

	return thunder_dram_is_lmc_enabled(node, vsec_ctl.s.inst_num) ?
				THUNDER_ECAM_DEV_NS:
				THUNDER_ECAM_DEV_DISABLE;
}

static int thunder_ecam_ocla_init(unsigned node, uint64_t pconfig)
{
	pccpf_xxx_vsec_ctl_t vsec_ctl __unused;
	uint32_t midr;

	vsec_ctl.u = cavm_read32(pconfig + offset_PCCPF_XXX_VSEC_CTL);
	INFO("Node %d OCLA(%d) init at %lx\n", node, vsec_ctl.s.inst_num, pconfig);

	midr = read_midr();

	/* Disable OCLA for T88 pass 1.x as it does not have trace. */
	if (IS_THUNDER_PASS(midr, 1, 0) || IS_THUNDER_PASS(midr, 1, 1))
		return THUNDER_ECAM_DEV_DISABLE;

	return THUNDER_ECAM_DEV_NS;
}

static int thunder_ecam_bgx_init(unsigned node, uint64_t pconfig)
{
	pccpf_xxx_vsec_ctl_t vsec_ctl;
	gserx_cfg_t cfg;

	vsec_ctl.u = cavm_read32(pconfig + offset_PCCPF_XXX_VSEC_CTL);
	INFO("Node %d BGX(%d) init at %lx\n", node, vsec_ctl.s.inst_num, pconfig);

	cfg.u = CSR_READ_PA(node, GSERX_CFG(vsec_ctl.s.inst_num));

	return cfg.s.bgx ? THUNDER_ECAM_DEV_NS : THUNDER_ECAM_DEV_DISABLE;
}

typedef uint64_t (*thunder_ecam_dev_get_msg_t)(unsigned node, uint64_t pconfig, unsigned idx);
struct thunder_ecam_callbacks {
	uint16_t vendid;
	uint16_t devid;
	int (*init)(unsigned node, uint64_t pconfig);
	thunder_ecam_dev_get_msg_t get_msg;
};

static struct thunder_ecam_callbacks thunder_ecam_init_fn[] = {
	{ /* SMMU */
		.vendid = 0x177d,
		.devid = 0xa008,
		.init = thunder_ecam_smmu_init,
		.get_msg = thunder_ecam_smmu_get_msg,
	},
	{ /* GIC */
		.vendid = 0x177d,
		.devid = 0xa009,
		.init = thunder_ecam_secure_init,
	},
	{ /* GPIO */
		.vendid = 0x177d,
		.devid = 0xa00a,
		.init = thunder_ecam_gpio_init,
		.get_msg = thunder_ecam_gpio_get_msg,
	},
	{ /* MPI */
		.vendid = 0x177d,
		.devid = 0xa00b,
		.init = thunder_ecam_secure_init,
	},
	{ /* MIO_PTP */
		.vendid = 0x177d,
		.devid = 0xa00c,
		.init = thunder_ecam_secure_init,
	},
	{ /* UAA */
		.vendid = 0x177d,
		.devid = 0xa00f,
		.init = thunder_ecam_uaa_init,
		.get_msg = thunder_ecam_uaa_get_msg,
	},
	{ /* TWSI */
		.vendid = 0x177d,
		.devid = 0xa012,
		.init = thunder_ecam_twsi_init,
		.get_msg = thunder_ecam_twsi_get_msg,
	},
	{ /* GTI */
		.vendid = 0x177d,
		.devid = 0xa017,
		.init = thunder_ecam_gti_init,
		.get_msg = thunder_ecam_gti_get_msg,
	},
	{ /* SATA */
		.vendid = 0x177d,
		.devid = 0xa01c,
		.init = thunder_ecam_sata_init,
	},
	{ /* PEM */
		.vendid = 0x177d,
		.devid = 0xa020,
		.init = thunder_ecam_pem_init,
		.get_msg = thunder_ecam_pem_get_msg,
	},
	{ /* LMC */
		.vendid = 0x177d,
		.devid = 0xa022,
		.init = thunder_ecam_lmc_init,
	},
	{ /* OCLA */
		.vendid = 0x177d,
		.devid = 0xa023,
		.init = thunder_ecam_ocla_init,
	},
	{ /* BGX */
		.vendid = 0x177d,
		.devid = 0xa026,
		.init = thunder_ecam_bgx_init,
	},
	{
		.vendid = 0xffff,
		.devid = 0xffff,
	},
};

#define PCI_CAP_ID_MSIX		0x11
#define PCI_CAP_ID_EA		0x14

static uint64_t thunder_ecam_get_bar(uint64_t pconfig, uint8_t bar)
{
	uint8_t cap_ptr = cavm_read32(pconfig + 0x34) & 0xff;
	uint32_t cap_id;
	uint64_t addrl = 0, addrh = 0;

	while (cap_ptr) {
		cap_id = cavm_read32(pconfig + cap_ptr);

		if ((cap_id & 0xff) == PCI_CAP_ID_EA)
			break;

		cap_ptr = (cap_id >> 8) & 0xff;
	}

	if (cap_ptr) { /* Found EA */
		unsigned num_entries = (cap_id >> 16) & 0x3f;
		unsigned offset = 4;

		for ( ; num_entries; num_entries--) {
			unsigned es, bei;
			uint32_t dw;
			dw = cavm_read32(pconfig + cap_ptr + offset);
			es = dw & 0x7;
			bei = (dw >> 4) & 0xf;

			printf("EA: %x %x %x\n", num_entries, offset, dw);

			if (bei == bar) {
				addrl = cavm_read32(pconfig + cap_ptr + offset + 0x4);
				if (addrl & 0x2)
					addrh = cavm_read32(pconfig + cap_ptr + offset + 0xc);

				addrl &= ~0x3ull;

				break;
			}

			offset += (es + 1) * 4;
		}
	} else {
		addrl = cavm_read32(pconfig + 0x10 + bar * 4);
		if (addrl & 0x4) {
			addrh = cavm_read32(pconfig + 0x14 + bar * 4);
		}
		addrl &= ~0xfull;
	}

	return (addrh << 32) | addrl;
}

static void thunder_ecam_msix_enable(unsigned node, uint64_t pconfig,
		thunder_ecam_dev_get_msg_t get_msg)
{
	uint8_t cap_ptr = cavm_read32(pconfig + 0x34) & 0xff;
	uint32_t cap_id;
	uint16_t table_size;
	uint32_t table_offset;
	uint8_t bir;
	uint64_t bar;
	unsigned i;

	while (cap_ptr) {
		cap_id = cavm_read32(pconfig + cap_ptr);

		if ((cap_id & 0xff) == PCI_CAP_ID_MSIX)
			break;

		cap_ptr = (cap_id >> 8) & 0xff;
	}

	if (!cap_ptr) {
		WARN("No MSI-X Capability found for device at %lx\n", pconfig);
		return;
	}

	table_size = ((cap_id >> 16) & 0x3ff) + 1;

	table_offset = cavm_read32(pconfig + cap_ptr + 4);
	bir = table_offset & 0x7;
	table_offset &= ~0x7;

	bar = thunder_ecam_get_bar(pconfig, bir);

	printf("DEV %lx %x %lx %x %x\n", pconfig, bir, bar, table_offset, table_size);

	if (bar == 0) {
		printf("NO MSI-X BAR FOUND!\n");
		return;
	}

	pccpf_xxx_vsec_sctl_t vsec_sctl;

	/* Program MSI-X vectors as secured and bypassing SMMU */
	vsec_sctl.u = cavm_read32(pconfig + offset_PCCPF_XXX_VSEC_SCTL);
	vsec_sctl.s.msix_phys = 1;
	vsec_sctl.s.msix_sec = 1;
	cavm_write32(pconfig + offset_PCCPF_XXX_VSEC_SCTL, vsec_sctl.u);

	for (i = 0; i < table_size; i++) {
		uint64_t addr = (i % 2) ? GICD_CLRSPI_SR : GICD_SETSPI_SR;
		//uint64_t addr = (i % 2) ? GICD_CLRSPI_NSR : GICD_SETSPI_NSR;
		addr |= 1;
		uint64_t msg = get_msg(node, pconfig, i);

		ECAM_TRACE("%x %lx %lx\n", i, addr, msg);
		cavm_write64(bar + table_offset + i * 16 + 0, addr);
		cavm_write64(bar + table_offset + i * 16 + 8, msg);
	}

	cavm_write32(pconfig + cap_ptr, cap_id | (1 << (15 + 16))); /* Enable MSI-X */
}

static int thunder_ecam_dev_init(unsigned node, unsigned ecam, unsigned bus, unsigned dev, unsigned func)
{
	uint64_t pconfig = thunder_ecam_dev_config(node, ecam, bus, dev, func);
	pccpf_xxx_id_t pccpf_id;
	unsigned i;

	if (!pconfig)
		return 0;

	pccpf_id.u = cavm_read32(pconfig + offset_PCCPF_XXX_ID);
	ECAM_TRACE("%s %d:%d:%d:%x:%x -> %lx %x %x\n", __func__, node, ecam, bus, dev, func,
			pconfig,
			pccpf_id.s.vendid,
			pccpf_id.s.devid);

	/* Be safe: only Cavium devices here */
	assert(pccpf_id.s.vendid == 0x177d);

	for (i = 0; thunder_ecam_init_fn[i].devid != 0xffff; i++) {
		int rc = THUNDER_ECAM_DEV_NS;

		if (thunder_ecam_init_fn[i].vendid != pccpf_id.s.vendid ||
		    thunder_ecam_init_fn[i].devid != pccpf_id.s.devid)
			continue;

		if (thunder_ecam_init_fn[i].init)
			rc = thunder_ecam_init_fn[i].init(node, pconfig);

		if (rc != THUNDER_ECAM_DEV_DISABLE && thunder_ecam_init_fn[i].get_msg)
			thunder_ecam_msix_enable(node, pconfig, thunder_ecam_init_fn[i].get_msg);

		return rc;
	}

	return THUNDER_ECAM_DEV_NS;
}

static unsigned prev_func = 0;
static void thunder_ecam_dev_enumerate(unsigned node, unsigned ecam, unsigned bus, unsigned dev, unsigned func)
{
	int rc;

	if (thunder_ecam_dev_skip(node, ecam, bus, dev, func)) {
		thunder_ecam_dev_secure(node, ecam, bus, dev, func);

		return;
	}

	if (func == 0)
		prev_func = 0;

	rc = thunder_ecam_dev_init(node, ecam, bus, dev, func);

	switch (rc) {
	case THUNDER_ECAM_DEV_NS:
		/* Non secure */

		if (thunder_ecam_bus_is_rsl(node, ecam, bus)) {
			uint64_t pconfig = thunder_ecam_dev_config(node, ecam, bus, dev, prev_func);
			pccpf_xxx_vsec_ctl_t vsec_ctl;

			/* Program ARI capability of the previous device */
			vsec_ctl.u = cavm_read32(pconfig + offset_PCCPF_XXX_VSEC_CTL);
			vsec_ctl.s.nxtfn_ns = func;
			cavm_write32(pconfig + offset_PCCPF_XXX_VSEC_CTL, vsec_ctl.u);
			ECAM_TRACE("Programmed prev_func %x -> %x\n", prev_func, func);

			prev_func = func;
		}

		thunder_ecam_dev_nonsecure(node, ecam, bus, dev, func);
		break;

	case THUNDER_ECAM_DEV_SECURE:
		thunder_ecam_dev_secure(node, ecam, bus, dev, func);
		break;

	default:
	case THUNDER_ECAM_DEV_DISABLE:
		/* Just hide the device from NS world */
		thunder_ecam_dev_secure(node, ecam, bus, dev, func);
		break;
	}
}

static void thunder_ecam_bus_enumerate(unsigned node, unsigned ecam, unsigned bus)
{
	if (thunder_ecam_bus_is_rsl(node, ecam, bus)) {
		unsigned func;

		for (func = 0; func < 256; func++)
			thunder_ecam_dev_enumerate(node, ecam, bus, 0, func);
	} else {
		unsigned dev;

		for (dev = 0; dev < 32; dev++)
			thunder_ecam_dev_enumerate(node, ecam, bus, dev, 0);
	}
}

static void thunder_ecam_setup(unsigned node, unsigned ecam)
{
	unsigned bus;

	for (bus = 0; bus < THUNDER_ECAM_MAX_BUS; bus ++) {
		if (thunder_ecam_bus_skip(node, ecam, bus)) {
			thunder_ecam_bus_disable(node, ecam, bus);
			continue;
		}

		thunder_ecam_bus_enable(node, ecam, bus);
		thunder_ecam_bus_enumerate(node, ecam, bus);
	}
}

void thunder_pci_init(void)
{
	unsigned node, node_count, ecam;

	node_count = thunder_get_node_count();
	for (node = 0; node < node_count; node++) {
		for (ecam = 0; ecam < THUNDER_ECAM_PER_NODE; ecam ++)
			thunder_ecam_setup(node, ecam);
	}
}
