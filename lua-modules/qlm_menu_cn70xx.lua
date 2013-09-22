-- BDK QLM menu for CN70XX configuration.
require("strict")
require("utils")
require("menu")

local node = 0

local function setup_dlmx_ref(qlm, default_option)
    local m = menu.new("DLM%d Reference clock" % qlm)
    m:item("c0", "Common reference clock 0 (DLMC_REF_CLK0_P/N)")
    m:item("c1", "Common reference clock 1 (DLMC_REF_CLK1_P/N)")
    if qlm == 0 then
        m:item("e0", "External reference clock 0 (DLM0_REF_CLK_P/N)")
    end
    local ref = m:show(default_option)
    if ref == "c0" then
        octeon.csr.GSERX_DLMX_REF_USE_PAD(0,qlm).ref_use_pad = 0
        octeon.csr.GSERX_DLMX_REFCLK_SEL(0,qlm).refclk_sel = 0
    elseif ref == "c1" then
        octeon.csr.GSERX_DLMX_REF_USE_PAD(0,qlm).ref_use_pad = 0
        octeon.csr.GSERX_DLMX_REFCLK_SEL(0,qlm).refclk_sel = 1
    else
        octeon.csr.GSERX_DLMX_REF_USE_PAD(0,qlm).ref_use_pad = 1
        octeon.csr.GSERX_DLMX_REFCLK_SEL(0,qlm).refclk_sel = 0
    end
end

local function setup_dlm0(mode, speed, flags)
    assert(0 == octeon.c.bdk_qlm_set_mode(node, 0, mode, speed, flags), "Setting DLM0 mode failed")
end

local function setup_gpio_output(gpio, mode)
    if gpio == -1 then
        return
    elseif gpio >= 16 then
        octeon.csr.GPIO_XBIT_CFGX(gpio).encode({OUTPUT_SEL = mode, TX_OE = 1})
    else
        octeon.csr.GPIO_BIT_CFGX(gpio).encode({OUTPUT_SEL = mode, TX_OE = 1})
    end
end

-- Chip specific configuration prompting for CN70XX
function qlm_setup_cn70xx()
    if ((octeon.c.bdk_qlm_get_mode(node, 0) ~= octeon.QLM_MODE_DISABLED) or
        (octeon.c.bdk_qlm_get_mode(node, 1) ~= octeon.QLM_MODE_DISABLED) or
        (octeon.c.bdk_qlm_get_mode(node, 2) ~= octeon.QLM_MODE_DISABLED)) then
        assert(false, "DLMs already configured once. You must reset before reconfig")
    end

    setup_dlmx_ref(0, "e0")
    setup_dlmx_ref(1, "c0")
    setup_dlmx_ref(2, "c0")

    local m = menu.new("DLM0 Mode")
    m:item("xa", "RXAUI   lanes 0-1",              setup_dlm0, octeon.QLM_MODE_RXAUI_1X2,       6250, 0)
    m:item("ss", "SGMII   lane 0, SGMII   lane 1", setup_dlm0, octeon.QLM_MODE_SGMII_SGMII,     1250, 0)
    m:item("sq", "SGMII   lane 0, QSGMII  lane 1", setup_dlm0, octeon.QLM_MODE_SGMII_QSGMII,    5000, 0)
    m:item("sd", "SGMII   lane 0, Disable lane 1", setup_dlm0, octeon.QLM_MODE_SGMII_DISABLED,  1250, 0)
    m:item("qs", "QSGMII  lane 0, SGMII   lane 1", setup_dlm0, octeon.QLM_MODE_QSGMII_SGMII,    5000, 0)
    m:item("qq", "QSGMII  lane 0, QSGMII  lane 1", setup_dlm0, octeon.QLM_MODE_QSGMII_QSGMII,   5000, 0)
    m:item("qd", "QSGMII  lane 0, Disable lane 1", setup_dlm0, octeon.QLM_MODE_QSGMII_DISABLED, 5000, 0)
    m:item("ds", "Disable lane 0, SGMII   lane 1", setup_dlm0, octeon.QLM_MODE_DISABLED_SGMII,  1250, 0)
    m:item("dq", "Disable lane 0, QSGMII  lane 1", setup_dlm0, octeon.QLM_MODE_DISABLED_QSGMII, 5000, 0)
    m:item("dd", "Disable both lanes",             setup_dlm0, octeon.QLM_MODE_DISABLED,        0,    0)
    local net_mode = m:show("qq")

    local m = menu.new("DLM1-2 Mode")
    m:item("1x4", "PCIe x4 lanes 2-5")
    m:item("2x2", "PCIe x2 lanes 2-3, PCIe x2 lanes 4-5")
    m:item("3x1", "PCIe x1 lane  2,   PCIe x1 lane  4,  PCIe x1 lane  5")
    m:item("1x2", "PCIe x2 lanes 2-3, SATA    lanes 4,5")
    m:item("2x1", "PCIe x1 lane  2,   PCIe x1 lane  3,  SATA    lanes 4,5")
    m:item("dis", "Disable lanes 2-5")
    local pcie_mode = m:show("2x1")

    local pcie_gen2
    local pcie1_root
    local flags = 0
    if pcie_mode ~= "dis" then
        pcie_gen2 = menu.prompt_yes_no("Configure PCIe for gen2", "y")
        pcie1_root = menu.prompt_yes_no("Configure PCIe port 1 as a root complex", "y")
        flags = pcie_gen2 and octeon.QLM_MODE_FLAG_GEN2 or octeon.QLM_MODE_FLAG_GEN1
        flags = flags + (pcie1_root and 0 or octeon.QLM_MODE_FLAG_ENDPOINT)
    end

    -- SATA can use a number of GPIOs for various signals
    -- Prompt the user for which GPIOs are needed
    local have_sata = (pcie_mode == "1x2") or (pcie_mode == "2x1")
    if have_sata then
        -- PORT0
        local sata_lab_lb_pin = menu.prompt_number("GPIO for SATA compliance lab loopback testing (lab_lb_pin)", -1, -1, 19)
        sata_lab_lb_pin = (sata_lab_lb_pin == -1) and 31 or sata_lab_lb_pin
        octeon.csr.GPIO_SATA_CTL.sel0 = sata_lab_lb_pin

        local p0_mp_switch = menu.prompt_number("GPIO for SATA0 mechanical presence detect (p0_mp_switch)", -1, -1, 19)
        p0_mp_switch = (p0_mp_switch == -1) and 31 or p0_mp_switch
        octeon.csr.GPIO_SATA_CTL.sel1 = p0_mp_switch

        local p0_cp_det = menu.prompt_number("GPIO for SATA0 cold presence detect (p0_cp_det)", -1, -1, 19)
        p0_cp_det = (p0_cp_det == -1) and 31 or p0_cp_det
        octeon.csr.GPIO_SATA_CTL.sel3 = p0_cp_det

        local p0_cp_pod = menu.prompt_number("GPIO for SATA0 cold presence power-on device (p0_cp_pod)", -1, -1, 19)
        setup_gpio_output(p0_cp_pod, 0x15)

        local p0_act_led = menu.prompt_number("GPIO for SATA0 activity LED(p0_act_led)", -1, -1, 19)
        setup_gpio_output(p0_act_led, 0x17)

        -- PORT1
        local p1_mp_switch = menu.prompt_number("GPIO for SATA1 mechanical presence detect (p1_mp_switch)", -1, -1, 19)
        p1_mp_switch = (p1_mp_switch == -1) and 31 or p1_mp_switch
        octeon.csr.GPIO_SATA_CTL.sel2 = p1_mp_switch

        local p1_cp_det = menu.prompt_number("GPIO for SATA1 cold presence detect (p1_cp_det)", -1, -1, 19)
        p1_cp_det = (p1_cp_det == -1) and 31 or p1_cp_det
        octeon.csr.GPIO_SATA_CTL.sel4 = p1_cp_det

        local p1_cp_pod = menu.prompt_number("GPIO for SATA1 cold presence power-on device (p1_cp_pod)", -1, -1, 19)
        setup_gpio_output(p1_cp_pod, 0x16)

        local p1_act_led = menu.prompt_number("GPIO for SATA1 activity LED (p1_act_led)", -1, -1, 19)
        setup_gpio_output(p1_act_led, 0x18)
    end

    if pcie_mode == "1x4" then
        assert(0 == octeon.c.bdk_qlm_set_mode(node, 1, octeon.QLM_MODE_PCIE_1X4, 5000, flags), "Setting DLM1 mode failed")
    elseif pcie_mode == "2x2" then
        assert(0 == octeon.c.bdk_qlm_set_mode(node, 1, octeon.QLM_MODE_PCIE_1X2, 5000, flags), "Setting DLM1 mode failed")
        assert(0 == octeon.c.bdk_qlm_set_mode(node, 2, octeon.QLM_MODE_PCIE_1X2, 5000, flags), "Setting DLM2 mode failed")
    elseif pcie_mode == "3x1" then
        assert(0 == octeon.c.bdk_qlm_set_mode(node, 1, octeon.QLM_MODE_PCIE_1X1, 5000, flags), "Setting DLM1 mode failed")
        assert(0 == octeon.c.bdk_qlm_set_mode(node, 2, octeon.QLM_MODE_PCIE_2X1, 5000, flags), "Setting DLM2 mode failed")
    elseif pcie_mode == "1x2" then
        assert(0 == octeon.c.bdk_qlm_set_mode(node, 1, octeon.QLM_MODE_PCIE_1X2, 5000, flags), "Setting DLM1 mode failed")
        assert(0 == octeon.c.bdk_qlm_set_mode(node, 2, octeon.QLM_MODE_SATA_2X1, 3125, flags), "Setting DLM2 mode failed")
    elseif pcie_mode == "2x1" then
        assert(0 == octeon.c.bdk_qlm_set_mode(node, 1, octeon.QLM_MODE_PCIE_2X1, 5000, flags), "Setting DLM1 mode failed")
        assert(0 == octeon.c.bdk_qlm_set_mode(node, 2, octeon.QLM_MODE_SATA_2X1, 3125, flags), "Setting DLM2 mode failed")
    else
        assert(0 == octeon.c.bdk_qlm_set_mode(node, 1, octeon.QLM_MODE_DISABLED, 0, 0), "Setting DLM1 mode failed")
        assert(0 == octeon.c.bdk_qlm_set_mode(node, 2, octeon.QLM_MODE_DISABLED, 0, 0), "Setting DLM2 mode failed")
    end
end

