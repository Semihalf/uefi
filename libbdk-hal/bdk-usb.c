#include <bdk.h>

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(USB);

/**
 * Initialize the clocks for USB such that it is ready for a generic XHCI driver
 *
 * @param node       Node to init
 * @param usb_port   Port to intialize
 * @param clock_type Type of clock connected to the usb port
 *
 * @return Zero on success, negative on failure
 */

int bdk_usb_initialize(bdk_node_t node, int usb_port, bdk_usb_clock_t clock_type)
{
    /* Asim's USB model is broken */
    if (bdk_is_platform(BDK_PLATFORM_ASIM))
        return -1;

    int is_usbdrd = !CAVIUM_IS_MODEL(CAVIUM_CN88XX);

    if (0 < bdk_usb_togglePoll(node, usb_port, DO_QUERY)) {
        // If xhci polling was active turn it off
        bdk_usb_togglePoll(node, usb_port, DO_TOGGLE);
    }

    /* Perform the following steps to initiate a cold reset. */

    /* 1.  Wait for all voltages to reach a stable state.  Ensure the
        reference clock is up and stable.
        a.  If 3.3V is up first, 0.85V must be soon after (within tens of ms). */

    /* 2.  Wait for IOI reset to deassert. */

    /* 3.  If Over Current indication and/or Port Power Control features
        are desired, program the GPIO CSRs appropriately.
        a.  For Over Current Indication, select a GPIO for the input and
            program GPIO_USBH_CTL[SEL].
        b. For Port Power Control, set one of
            GPIO_BIT_CFG(0..19)[OUTPUT_SEL] = USBH_VBUS_CTRL. */

    /* 4.  Assert all resets:
        a.  UPHY reset: USBDRD(0..1)_UCTL_CTL[UPHY_RST] = 1
        b. UAHC reset: USBDRD(0..1)_UCTL_CTL[UAHC_RST] = 1
        c. UCTL reset: USBDRD(0..1)_UCTL_CTL[UCTL_RST] = 1 */
    if (is_usbdrd)
    {
        BDK_CSR_MODIFY(c, node, BDK_USBDRDX_UCTL_CTL(usb_port),
            c.s.uphy_rst = 1;
            c.s.uahc_rst = 1;
            c.s.uctl_rst = 1);
    }
    else
    {
        BDK_CSR_MODIFY(c, node, BDK_USBHX_UCTL_CTL(usb_port),
            c.s.uphy_rst = 1;
            c.s.uahc_rst = 1;
            c.s.uctl_rst = 1);
    }

    /* 5.  Configure the controller clock:
        a.  Reset the clock dividers: USBDRD(0..1)_UCTL_CTL[H_CLKDIV_RST] = 1.
        b. Select the controller clock frequency
            USBDRD(0..1)_UCTL_CTL[H_CLKDIV] = desired value.
            USBDRD(0..1)_UCTL_CTL[H_CLKDIV_EN] = 1 to enable the controller
                clock.
            Read USBDRD(0..1)_UCTL_CTL to ensure the values take effect.
        c.  Deassert the controller clock divider reset: USB-
            DRD(0..1)_UCTL_CTL[H_CLKDIV_RST] = 0. */
    uint64_t sclk_rate = bdk_clock_get_rate(node, BDK_CLOCK_SCLK);
    uint64_t divider = (sclk_rate + 300000000-1) / 300000000;
    /*
    ** According to HRM Rules are:
    ** - clock must be below 300MHz
    ** USB3 full-rate requires 150 MHz or better
    ** USB3 requires 125 MHz
    ** USB2 full rate requires 90 MHz
    ** USB2 requires 62.5 MHz
    */
    if (divider <= 1)
        divider = 0;
    else if (divider <= 2)
        divider = 1;
    else if (divider <= 4)
        divider = 2;
    else if (divider <= 6)
        divider = 3;
    else if (divider <= 8)
        divider = 4;
    else if (divider <= 16)
        divider = 5;
    else if (divider <= 24)
        divider = 6;
    else
        divider = 7;
    if (is_usbdrd)
    {
        BDK_CSR_MODIFY(c, node, BDK_USBDRDX_UCTL_CTL(usb_port),
            c.s.h_clkdiv_rst = 1);
        BDK_CSR_MODIFY(c, node, BDK_USBDRDX_UCTL_CTL(usb_port),
            c.s.h_clkdiv_sel = divider;
            c.s.h_clk_en = 1);
        BDK_CSR_MODIFY(c, node, BDK_USBDRDX_UCTL_CTL(usb_port),
            c.s.h_clkdiv_rst = 0);
    }
    else
    {
        BDK_CSR_MODIFY(c, node, BDK_USBHX_UCTL_CTL(usb_port),
            c.s.h_clkdiv_rst = 1);
        BDK_CSR_MODIFY(c, node, BDK_USBHX_UCTL_CTL(usb_port),
            c.s.h_clkdiv_sel = divider;
            c.s.h_clk_en = 1);
        BDK_CSR_MODIFY(c, node, BDK_USBHX_UCTL_CTL(usb_port),
            c.s.h_clkdiv_rst = 0);
    }
    if (bdk_trace_enables & (1ull << BDK_TRACE_ENABLE_USB_XHCI)) {
        static bool printit[2] = {true,true};
        if (printit[usb_port]) {
            uint64_t fr_div;
            if (divider < 5) fr_div = divider * 2;
            else fr_div = 8 * (divider - 3);
            uint64_t freq = (typeof(freq)) (sclk_rate / fr_div);
            char *token;
            if (freq < 62500000ULL) token = "???Low";
            else if (freq < 90000000ULL) token = "USB2";
            else if (freq < 125000000ULL) token = "USB2 Full";
            else if (freq < 150000000ULL) token = "USB3";
            else token = "USB3 Full";
            printf("Freq %lld - %s\n",
                   (unsigned long long)freq, token);
            printit[usb_port] = false;
        }
    }
    /* 6.  Configure the strap signals in USBDRD(0..1)_UCTL_CTL.
        a.  Reference clock configuration (see Table 31.2): USB-
            DRD(0..1)_UCTL_CTL[REF_CLK_FSEL, MPLL_MULTIPLIER,
            REF_CLK_SEL, REF_CLK_DIV2].
        b. Configure and enable spread-spectrum for SuperSpeed:
            USBDRD(0..1)_UCTL_CTL[SSC_RANGE, SSC_EN, SSC_REF_CLK_SEL].
        c. Enable USBDRD(0..1)_UCTL_CTL[REF_SSP_EN].
        d. Configure PHY ports:
            USBDRD(0..1)_UCTL_CTL[USB*_PORT_PERM_ATTACH, USB*_PORT_DISABLE]. */
    if (is_usbdrd)
    {
        BDK_CSR_MODIFY(c, node, BDK_USBDRDX_UCTL_CTL(usb_port),
            c.s.ref_clk_fsel = 0x27;
            c.s.mpll_multiplier = 0x19;
            c.s.ref_clk_sel = 2;
            c.s.ref_clk_div2 = 0);
        BDK_CSR_MODIFY(c, node, BDK_USBDRDX_UCTL_CTL(usb_port),
            c.s.ssc_en = 1;
            c.s.ssc_ref_clk_sel = 0);
        BDK_CSR_MODIFY(c, node, BDK_USBDRDX_UCTL_CTL(usb_port),
            c.s.ref_ssp_en = 1);
    }
    else
    {
        BDK_CSR_MODIFY(c, node, BDK_USBHX_UCTL_CTL(usb_port),
            c.s.ref_clk_fsel = 0x27;
            c.s.mpll_multiplier = 0;
            c.s.ref_clk_sel = 0;
            c.s.ref_clk_div2 = 0);
        BDK_CSR_MODIFY(c, node, BDK_USBHX_UCTL_CTL(usb_port),
            c.s.ssc_en = 1;
            c.s.ssc_ref_clk_sel = 0);
        BDK_CSR_MODIFY(c, node, BDK_USBHX_UCTL_CTL(usb_port),
            c.s.ref_ssp_en = 1);
    }
    /* Hardware default is for ports to be enabled and not perm attach. Don't
        change it */

    /* 7.  The PHY resets in lowest-power mode. Power up the per-port PHY
       logic by enabling the following:
        a.  USBDRD(0..1)_UCTL_CTL [HS_POWER_EN] if high-speed/full-speed/low-
            speed functionality needed.
        b. USBDRD(0..1)_UCTL_CTL [SS_POWER_EN] if SuperSpeed functionality
            needed. */
    if (is_usbdrd)
    {
        BDK_CSR_MODIFY(c, node, BDK_USBDRDX_UCTL_CTL(usb_port),
            c.s.hs_power_en = 1;
            c.s.ss_power_en = 1);
    }
    else
    {
        BDK_CSR_MODIFY(c, node, BDK_USBHX_UCTL_CTL(usb_port),
            c.s.hs_power_en = 1;
            c.s.ss_power_en = 1);
    }

    /* 8.  Wait 10 controller-clock cycles from step 5. for controller clock
        to start and async FIFO to properly reset. */
    bdk_wait_usec(1);

    /* 9.  Deassert UCTL and UAHC resets:
        a.  USBDRD(0..1)_UCTL_CTL[UCTL_RST] = 0
        b. USBDRD(0..1)_UCTL_CTL[UAHC_RST] = 0
        c. [optional] For port-power control:
        - Set one of GPIO_BIT_CFG(0..47)[PIN_SEL] =  USB0_VBUS_CTRLor USB1_VBUS_CTRL.
        - Set USBDRD(0..1)_UCTL_HOST_CFG[PPC_EN] = 1 and USBDRD(0..1)_UCTL_HOST_CFG[PPC_ACTIVE_HIGH_EN] = 1.
        - Wait for the external power management chip to power the VBUS.ional port-power control.
        ]
        d. You will have to wait 10 controller-clock cycles before accessing
            any controller-clock-only registers. */
    if (is_usbdrd)
    {
        BDK_CSR_MODIFY(c, node, BDK_USBDRDX_UCTL_CTL(usb_port),
            c.s.uctl_rst = 0);
    }
    else
    {
        BDK_CSR_MODIFY(c, node, BDK_USBHX_UCTL_CTL(usb_port),
            c.s.uctl_rst = 0);
    }
    bdk_wait_usec(1);

    int usb_gpio = bdk_config_get_int(BDK_CONFIG_USB_PWR_GPIO, node, usb_port);
    int usb_polarity = bdk_config_get_int(BDK_CONFIG_USB_PWR_GPIO_POLARITY, node, usb_port);
    if (-1 != usb_gpio) {
        int gsrc = BDK_GPIO_PIN_SEL_E_USBX_VBUS_CTRL_CN9(usb_port);
        if (CAVIUM_IS_MODEL(CAVIUM_CN88XX)) {
            gsrc = BDK_GPIO_PIN_SEL_E_USBX_VBUS_CTRL_CN88XX(usb_port);
        }
        else if (CAVIUM_IS_MODEL(CAVIUM_CN81XX)) {
            gsrc = BDK_GPIO_PIN_SEL_E_USBX_VBUS_CTRL_CN81XX(usb_port);
        }
        else if (CAVIUM_IS_MODEL(CAVIUM_CN83XX)) {
            gsrc = BDK_GPIO_PIN_SEL_E_USBX_VBUS_CTRL_CN83XX(usb_port);}
        else {
            bdk_error("USB_VBUS_CTRL GPIO: unknown chip model\n");
        }

        BDK_CSR_MODIFY(c,node,BDK_GPIO_BIT_CFGX(usb_gpio),
                       c.s.pin_sel = gsrc;
                       c.s.pin_xor = (usb_polarity) ? 0 : 1;
            );

        if (is_usbdrd)
        {
            BDK_CSR_MODIFY(c, node, BDK_USBDRDX_UCTL_HOST_CFG(usb_port),
                           c.s.ppc_en = 1;
                           c.s.ppc_active_high_en = 1);
        }
        else
        {
            BDK_CSR_MODIFY(c, node, BDK_USBHX_UCTL_HOST_CFG(usb_port),
                           c.s.ppc_en = 1;
                           c.s.ppc_active_high_en = 1);
        }
        bdk_wait_usec(100000);
    }

    if (is_usbdrd)
    {
        BDK_CSR_MODIFY(c, node, BDK_USBDRDX_UCTL_CTL(usb_port),
            c.s.uahc_rst = 0);
    }
    else
    {
        BDK_CSR_MODIFY(c, node, BDK_USBHX_UCTL_CTL(usb_port),
            c.s.uahc_rst = 0);
    }

    bdk_wait_usec(100000);
    bdk_wait_usec(1);

    /* 10. Enable conditional coprocessor clock of UCTL by writing USB-
        DRD(0..1)_UCTL_CTL[CSCLK_EN] = 1. */
    if (is_usbdrd)
    {
        BDK_CSR_MODIFY(c, node, BDK_USBDRDX_UCTL_CTL(usb_port),
            c.s.csclk_en = 1);
    }
    else
    {
        BDK_CSR_MODIFY(c, node, BDK_USBHX_UCTL_CTL(usb_port),
            c.s.csclk_en = 1);
    }

    /* 11. Set USBDRD(0..1)_UCTL_CTL[DRD_MODE] to 1 for device mode, 0 for
        host mode. */
    if (is_usbdrd)
    {
        BDK_CSR_MODIFY(c, node, BDK_USBDRDX_UCTL_CTL(usb_port),
            c.s.drd_mode = 0);
    }

    /* 12. Soft reset the UPHY and UAHC logic via the UAHC controls:
        a.  USBDRD(0..1)_UAHC_GUSB2PHYCFG(0)[PHYSOFTRST] = 1
        b. USBDRD(0..1)_UAHC_GUSB3PIPECTL(0)[PHYSOFTRST] = 1
        c. USBDRD(0..1)_UAHC_GCTL[CORESOFTRESET] = 1 */
    if (is_usbdrd)
    {
        BDK_CSR_MODIFY(c, node, BDK_USBDRDX_UAHC_GUSB2PHYCFGX(usb_port, 0),
            c.s.physoftrst = 1);
        BDK_CSR_MODIFY(c, node, BDK_USBDRDX_UAHC_GUSB3PIPECTLX(usb_port, 0),
            c.s.physoftrst = 1);
        BDK_CSR_MODIFY(c, node, BDK_USBDRDX_UAHC_GCTL(usb_port),
            c.s.coresoftreset = 1);
    }
    else
    {
        BDK_CSR_MODIFY(c, node, BDK_USBHX_UAHC_GUSB2PHYCFGX(usb_port, 0),
            c.s.physoftrst = 1);
        BDK_CSR_MODIFY(c, node, BDK_USBHX_UAHC_GUSB3PIPECTLX(usb_port, 0),
            c.s.physoftrst = 1);
        BDK_CSR_MODIFY(c, node, BDK_USBHX_UAHC_GCTL(usb_port),
            c.s.coresoftreset = 1);
    }

    /* 13. Program USBDRD(0..1)_UAHC_GCTL[PRTCAPDIR] to 0x2 for device mode
        or 0x1 for host mode. */
    if (is_usbdrd)
    {
        BDK_CSR_MODIFY(c, node, BDK_USBDRDX_UAHC_GCTL(usb_port),
            c.s.prtcapdir = 1);
    }
    else
    {
        BDK_CSR_MODIFY(c, node, BDK_USBHX_UAHC_GCTL(usb_port),
            c.s.prtcapdir = 1);
    }

    /* 14. Wait 10us after step 13. for the PHY to complete its reset. */
    bdk_wait_usec(10);

    /* 15. Deassert UPHY reset: USBDRD(0..1)_UCTL_CTL[UPHY_RST] = 0. */
    if (is_usbdrd)
    {
        BDK_CSR_MODIFY(c, node, BDK_USBDRDX_UCTL_CTL(usb_port),
            c.s.uphy_rst = 0);
    }
    else
    {
        BDK_CSR_MODIFY(c, node, BDK_USBHX_UCTL_CTL(usb_port),
            c.s.uphy_rst = 0);
    }

    /* 16. Wait for at least 45us after step 15. for UPHY to output
        stable PHYCLOCK. */
    bdk_wait_usec(45);

    /* 17. Initialize any other strap signals necessary and make sure they
       propagate by reading back the last register written.
        a.  UCTL
            USBDRD(0..1)_UCTL_PORT0_CFG_*[*_TUNE]
            USBDRD(0..1)_UCTL_PORT0_CFG_*[PCS_*]
            USBDRD(0..1)_UCTL_PORT0_CFG_*[LANE0_TX_TERM_OFFSET]
            USBDRD(0..1)_UCTL_PORT0_CFG_*[TX_VBOOST_LVL]
            USBDRD(0..1)_UCTL__PORT0_CFG_*[LOS_BIAS]
            USBDRD(0..1)_UCTL_HOST_CFG
            USBDRD(0..1)_UCTL_SHIM_CFG
        b.  UAHC: only the following UAHC registers are accessible during
            CoreSoftReset.
            USBDRD(0..1)_UAHC_GCTL
            USBDRD(0..1)_UAHC_GUCTL
            USBDRD(0..1)_UAHC_GSTS
            USBDRD(0..1)_UAHC_GUID
            USBDRD(0..1)_UAHC_GUSB2PHYCFG(0)
            USBDRD(0..1)_UAHC_GUSB3PIPECTL(0) */

    /* 18. Release soft reset the UPHY and UAHC logic via the UAHC controls:
        a.  USBDRD(0..1)_UAHC_GUSB2PHYCFG(0)[PHYSOFTRST] = 0
        b. USBDRD(0..1)_UAHC_GUSB3PIPECTL(0)[PHYSOFTRST] = 0
        c. USBDRD(0..1)_UAHC_GCTL[CORESOFTRESET] = 0 */
    if (is_usbdrd)
    {
        BDK_CSR_MODIFY(c, node, BDK_USBDRDX_UAHC_GUSB2PHYCFGX(usb_port, 0),
            c.s.physoftrst = 0);
        BDK_CSR_MODIFY(c, node, BDK_USBDRDX_UAHC_GUSB3PIPECTLX(usb_port, 0),
            c.s.physoftrst = 0);
        BDK_CSR_MODIFY(c, node, BDK_USBDRDX_UAHC_GCTL(usb_port),
            c.s.coresoftreset = 0);
    }
    else
    {
        BDK_CSR_MODIFY(c, node, BDK_USBHX_UAHC_GUSB2PHYCFGX(usb_port, 0),
            c.s.physoftrst = 0);
        BDK_CSR_MODIFY(c, node, BDK_USBHX_UAHC_GUSB3PIPECTLX(usb_port, 0),
            c.s.physoftrst = 0);
        BDK_CSR_MODIFY(c, node, BDK_USBHX_UAHC_GCTL(usb_port),
            c.s.coresoftreset = 0);
    }

    /* 19. Configure the remaining UAHC_G* registers as needed, including
       any that were not configured in step 17.-b. */

    /* 20. Initialize the USB controller:
        a. To initialize the UAHC as a USB host controller, the application
            should perform the steps described in the xHCI specification
            (UAHC_X* registers). The xHCI sequence starts with poll for a 0 in
            USBDRD(0..1)_UAHC_USBSTS[CNR].
        b. To initialize the UAHC as a device, the application should TBD. The
            device initiation sequence starts with a device soft reset by
            setting USBDRD(0..1)_UAHC_DCTL[CSFTRST] = 1 and wait for a read
            operation to return 0. */
    return 0;
}

static int usb2_test_mode(bdk_node_t node, int usb_port, int usb2_mode)
{
    int is_usbdrd = !CAVIUM_IS_MODEL(CAVIUM_CN88XX);
    if (is_usbdrd)
    {
        /* Set Run/Stop bit in USBCMD to zero */
        BDK_CSR_MODIFY(c, node, BDK_USBDRDX_UAHC_USBCMD(usb_port),
            c.s.r_s = 0);

        /* Wait for HCHalted in USBSTS to transition to 1 */
        if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_USBDRDX_UAHC_USBSTS(usb_port), hch, ==, 1, 100000))
        {
            bdk_error("USB%d: Timeout waiting for controller halt\n", usb_port);
            return -1;
        }

        /* Set the Port Test Control field in PORTPMSC to the desired test */
        BDK_CSR_MODIFY(c, node, BDK_USBDRDX_UAHC_PORTPMSC_20X(usb_port, 0),
            c.s.port_test_control = usb2_mode);

        /* For force enable, turn Run/Stop back on */
        if (usb2_mode == 5)
        {
            BDK_CSR_MODIFY(c, node, BDK_USBDRDX_UAHC_USBCMD(usb_port),
                c.s.r_s = 1);
        }
    }
    else
    {
        /* Set Run/Stop bit in USBCMD to zero */
        BDK_CSR_MODIFY(c, node, BDK_USBHX_UAHC_USBCMD(usb_port),
            c.s.r_s = 0);

        /* Wait for HCHalted in USBSTS to transition to 1 */
        if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_USBHX_UAHC_USBSTS(usb_port), hch, ==, 1, 100000))
        {
            bdk_error("USB%d: Timeout waiting for controller halt\n", usb_port);
            return -1;
        }

        /* Set the Port Test Control field in PORTPMSC to the desired test */
        BDK_CSR_MODIFY(c, node, BDK_USBHX_UAHC_PORTPMSC_20X(usb_port, 0),
            c.s.port_test_control = usb2_mode);

        /* For force enable, turn Run/Stop back on */
        if (usb2_mode == 5)
        {
            BDK_CSR_MODIFY(c, node, BDK_USBHX_UAHC_USBCMD(usb_port),
                c.s.r_s = 1);
        }
    }
    return 0;
}

/**
 * Put the USB port into a specific testing mode
 *
 * @param node      Node to use
 * @param usb_port  Port to use
 * @param test_mode USB test mode
 *
 * @return Zero on success, negative on failure
 */
int bdk_usb_test_mode(bdk_node_t node, int usb_port, bdk_usb_test_t test_mode)
{
    switch (test_mode)
    {
        case BDK_USB_TEST_USB2_DISABLE:
            return usb2_test_mode(node, usb_port, 0);
        case BDK_USB_TEST_USB2_J_STATE:
            return usb2_test_mode(node, usb_port, 1);
        case BDK_USB_TEST_USB2_K_STATE:
            return usb2_test_mode(node, usb_port, 2);
        case BDK_USB_TEST_USB2_SE0_NAK:
            return usb2_test_mode(node, usb_port, 3);
        case BDK_USB_TEST_USB2_PACKET:
            return usb2_test_mode(node, usb_port, 4);
        case BDK_USB_TEST_USB2_FORCE_ENABLE:
            return usb2_test_mode(node, usb_port, 5);
        case BDK_USB_XHCI_INIT:
            return bdk_usb_HCInit(node, usb_port);
        case BDK_USB_XHCI_LIST_ADDRESSES:
            return bdk_usb_HCList();
        case BDK_USB_XHCI_POLL_STATUS:
            return bdk_usb_HCPoll(node, usb_port);
        case BDK_USB_XHCI_TOGGLE_POLLING:
            bdk_usb_togglePoll(node, usb_port, DO_TOGGLE);
            return 0;
        case BDK_USB_TEST_USB2_LAST:
            break;
    }
    bdk_error("USB%d: Illegal test mode\n", test_mode);
    return -1;
}

/**
 * Convert a USB test enumeration into a string for display to the user
 *
 * @param test_mode Mode to convert
 *
 * @return String name of test
 */
const char* bdk_usb_get_test_mode_string(bdk_node_t node, int usb_port, bdk_usb_test_t test_mode)
{
    static char pollState[64];
    switch (test_mode)
    {
        case BDK_USB_TEST_USB2_DISABLE:
            return "Disable testing";
        case BDK_USB_TEST_USB2_J_STATE:
            return "USB 2.0 J_STATE test";
        case BDK_USB_TEST_USB2_K_STATE:
            return "USB 2.0 K_STATE test";
        case BDK_USB_TEST_USB2_SE0_NAK:
            return "USB 2.0 SE0_NAK test";
        case BDK_USB_TEST_USB2_PACKET:
            return "USB 2.0 PACKET test";
        case BDK_USB_TEST_USB2_FORCE_ENABLE:
            return "USB 2.0 FORCE_ENABLE test";
        case BDK_USB_XHCI_INIT:
            return "Initialize host controller";
        case BDK_USB_XHCI_LIST_ADDRESSES:
            return "List USB interfaces";
    	case BDK_USB_XHCI_POLL_STATUS:
            return "USB hxci poll root hub status";
    	case BDK_USB_XHCI_TOGGLE_POLLING:
        {
            int i = bdk_usb_togglePoll(node, usb_port, DO_QUERY);
            if (i>=0) {
                snprintf(pollState,sizeof(pollState),
                         "Toggle USB Polling (currently %s)", i ? "On" : "Off");
            } else
                return "Toggle USB Polling (NA)";
        }
        return pollState;
        case BDK_USB_TEST_USB2_LAST:
            break;
    }
    return NULL;
}

