#include <bdk.h>
#include <stdio.h>

#define MAX_TRA 4
#define MAX_TRA_DATA 1024

/**
 * TRA data format definition. Use the type field to
 * determine which union element to use.
 */
typedef union
{
    struct
    {
#if __BYTE_ORDER == __BIG_ENDIAN
        uint64_t  datahi;
        uint64_t  data;
#else
        uint64_t  data;
        uint64_t  datahi;
#endif
    } u128;
    struct
    {
#if __BYTE_ORDER == __BIG_ENDIAN
        uint64_t    reserved1   : 59;
        uint64_t    discontinuity:1;
        uint64_t    valid       : 1;
        uint64_t    addresshi   : 3;   /* Split the address to fit in upper 64 bits  */
        uint64_t    addresslo   : 35;  /* and lower 64-bits. */
        uint64_t    reserved    : 10;
        uint64_t    source      : 5;
        uint64_t    type        : 6;
        uint64_t    timestamp   : 8;
#else
        uint64_t    timestamp   : 8;
        uint64_t    type        : 6;
        uint64_t    source      : 5;
        uint64_t    reserved    : 10;
        uint64_t    addresslo   : 35;
        uint64_t    addresshi   : 3;
        uint64_t    valid       : 1;
        uint64_t    discontinuity:1;
        uint64_t    reserved1   : 59;
#endif
    } cmn2; /**< for LDT, LDI, PL2, RPL2, DWB, WBL2, SET*, CLR*, INCR*, DECR* */
    struct
    {
#if __BYTE_ORDER == __BIG_ENDIAN
        uint64_t    reserved1   : 59;
        uint64_t    discontinuity:1;
        uint64_t    valid       : 1;
        uint64_t    addresshi   : 3;   /* Split the address to fit in upper 64 bits  */
        uint64_t    addresslo   : 35;  /* and lower 64-bits */
        uint64_t    reserved    : 2;
        uint64_t    mask        : 8;
        uint64_t    source      : 5;
        uint64_t    type        : 6;
        uint64_t    timestamp   : 8;
#else
        uint64_t    timestamp   : 8;
        uint64_t    type        : 6;
        uint64_t    source      : 5;
        uint64_t    mask        : 8;
        uint64_t    reserved    : 2;
        uint64_t    addresslo   : 35;
        uint64_t    addresshi   : 3;
        uint64_t    valid       : 1;
        uint64_t    discontinuity:1;
        uint64_t    reserved1   : 59;
#endif
    } store2; /**< for STC, STF, STP, STT, LDD, PSL1, SAA32, SAA64, FAA32, FAA64, FAS32, FAS64 */
    struct
    {
#if __BYTE_ORDER == __BIG_ENDIAN
        uint64_t    reserved1   : 59;
        uint64_t    discontinuity:1;
        uint64_t    valid       : 1;
        uint64_t    addresshi   : 3;   /* Split the address to fit in upper 64 bits  */
        uint64_t    addresslo   : 35;  /* and lower 64-bits */
        uint64_t    reserved    : 2;
        uint64_t    subid       : 3;
        uint64_t    dest        : 5;
        uint64_t    source      : 5;
        uint64_t    type        : 6;
        uint64_t    timestamp   : 8;
#else
        uint64_t    timestamp   : 8;
        uint64_t    type        : 6;
        uint64_t    source      : 5;
        uint64_t    dest        : 5;
        uint64_t    subid       : 3;
        uint64_t    reserved    : 2;
        uint64_t    addresslo   : 35;
        uint64_t    addresshi   : 3;
        uint64_t    valid       : 1;
        uint64_t    discontinuity:1;
        uint64_t    reserved1   : 59;
#endif
    } iobld2; /**< for IOBLD8, IOBLD16, IOBLD32, IOBLD64, IOBST64, IOBST32, IOBST16, IOBST8 */
    struct
    {
#if __BYTE_ORDER == __BIG_ENDIAN
        uint64_t    reserved1   : 59;
        uint64_t    discontinuity:1;
        uint64_t    valid       : 1;
        uint64_t    addresshi   : 3;   /* Split the address to fit in upper 64 bits  */
        uint64_t    addresslo   : 32;  /* and lower 64-bits */
        uint64_t    mask        : 8;
        uint64_t    dest        : 5;
        uint64_t    source      : 5;
        uint64_t    type        : 6;
        uint64_t    timestamp   : 8;
#else
        uint64_t    timestamp   : 8;
        uint64_t    type        : 6;
        uint64_t    source      : 5;
        uint64_t    dest        : 5;
        uint64_t    mask        : 8;
        uint64_t    addresslo   : 32;
	uint64_t    addresshi   : 3;
        uint64_t    valid       : 1;
        uint64_t    discontinuity:1;
        uint64_t    reserved1   : 59;
#endif
    } iob2; /**< for IOBDMA */
} bdk_tra_data_t;

typedef struct
{
    struct
    {
        bdk_trax_ctl_t control;
        bdk_tra_data_t data[MAX_TRA_DATA];
    } tra[MAX_TRA];
} __bdk_tra_capture_t;


static const char *TYPE_ARRAY2[] = {
    "NOP     - None",
    "LDT     - Icache/IO fill, skip L2",
    "LDI     - Icache/IO fill",
    "PL2     - Prefetch into L2",
    "RPL2    - Mark for replacement in L2",
    "DWB     - Don't write back",
    "RSVD6",
    "RSVD7",
    "LDD     - Dcache fill",
    "PSL1    - Prefetch L1, skip L2",
    "RSVD10",
    "RSVD11",
    "RSVD12",
    "RSVD13",
    "RSVD14",
    "IOBDMA  - Async IOB",
    "STF     - Store full",
    "STT     - Store full, skip L2",
    "STP     - Store partial",
    "STC     - Store conditional",
    "STFIL1  - Store full, invalidate L1",
    "STTIL1  - Store full, skip L2, invalidate L1",
    "FAS32   - Atomic 32bit swap",
    "FAS64   - Atomic 64bit swap",
    "WBIL2i  - Writeback, invalidate, by index/way",
    "LTGL2i  - Read tag@index/way",
    "STGL2i  - Write tag@index/way",
    "RSVD27",
    "INVL2   - Invalidate, by address",
    "WBIL2   - Writeback, invalidate, by address",
    "WBL2    - Writeback, by address",
    "LCKL2   - Allocate, lock, by address",
    "IOBLD8  - IOB 8bit load",
    "IOBLD16 - IOB 16bit load",
    "IOBLD32 - IOB 32bit load",
    "IOBLD64 - IOB 64bit load",
    "IOBST8  - IOB 8bit store",
    "IOBST16 - IOB 16bit store",
    "IOBST32 - IOB 32bit store",
    "IOBST64 - IOB 64bit store",
    "SET8    - 8bit Atomic swap with 1's",
    "SET16   - 16bit Atomic swap with 1's",
    "SET32   - 32bit Atomic swap with 1's",
    "SET64   - 64bit Atomic swap with 1's",
    "CLR8    - 8bit Atomic swap with 0's",
    "CLR16   - 16bit Atomic swap with 0's",
    "CLR32   - 32bit Atomic swap with 0's",
    "CLR64   - 64bit Atomic swap with 0's",
    "INCR8   - 8bit Atomic fetch & add by 1",
    "INCR16  - 16bit Atomic fetch & add by 1",
    "INCR32  - 32bit Atomic fetch & add by 1",
    "INCR64  - 64bit Atomic fetch & add by 1",
    "DECR8   - 8bit Atomic fetch & add by -1",
    "DECR16  - 16bit Atomic fetch & add by -1",
    "DECR32  - 32bit Atomic fetch & add by -1",
    "DECR64  - 64bit Atomic fetch & add by -1",
    "RSVD56",
    "RSVD57",
    "FAA32   - 32bit Atomic fetch and add",
    "FAA64   - 64bit Atomic fetch and add",
    "RSVD60",
    "RSVD61",
    "SAA32   - 32bit Atomic add",
    "SAA64   - 64bit Atomic add"
};

static const char *SOURCE_ARRAY[] = {
    "PP0",
    "PP1",
    "PP2",
    "PP3",
    "PP4",
    "PP5",
    "PP6",
    "PP7",
    "PP8",
    "PP9",
    "PP10",
    "PP11",
    "PP12",
    "PP13",
    "PP14",
    "PP15",
    "PIP/IPD",
    "PKO-R",
    "FPA/TIM/DFA/PCI/ZIP/SSO/PKO-W",
    "DWB",
    "RSVD20",
    "RSVD21",
    "RSVD22",
    "RSVD23",
    "RSVD24",
    "RSVD25",
    "RSVD26",
    "RSVD27",
    "RSVD28",
    "RSVD29",
    "RSVD30",
    "RSVD31"
};

static const char *DEST_ARRAY[] = {
    "CIU/GPIO",
    "RSVD1",
    "RSVD2",
    "PCI/PCIe/SLI",
    "KEY",
    "FPA",
    "DFA",
    "ZIP",
    "RNG",
    "IPD",
    "PKO",
    "RSVD11",
    "SSO",
    "USB0",
    "RAD",
    "RSVD15",
    "RSVD16",
    "RSVD17",
    "RSVD18",
    "RSVD19",
    "RSVD20",
    "RSVD21",
    "RSVD22",
    "RSVD23",
    "RSVD24",
    "RSVD25",
    "RSVD26",
    "DPI",
    "RSVD28",
    "RSVD29",
    "FAU",
    "RSVD31"
};

#define BDK_TRA_SOURCE_MASK       0xf00ff
#define BDK_TRA_DESTINATION_MASK  0xfffffffful

static int __bdk_tra_num(void)
{
    if (OCTEON_IS_MODEL(OCTEON_CN63XX))
        return 1;
    else
        return 4;
}

static int __bdk_tra_size(void)
{
    return MAX_TRA_DATA;
}

/**
 * @INTERNAL
 * Setup the trace buffer filter command mask. The bit position of filter commands
 * are different for each Octeon model.
 *
 * @param filter    Which event to log
 * @return          Bitmask of filter command based on the event.
 */
static uint64_t __bdk_tra_set_filter_cmd_mask(bdk_tra_filt_t filter)
{
    bdk_trax_filt_cmd_t filter_command;

    if ((filter & BDK_TRA_FILT_ALL) == -1ull)
        filter_command.u64 = BDK_TRA_FILT_ALL;
    else
        filter_command.u64 = filter;

    filter_command.s.reserved_60_61 = 0;
    filter_command.s.reserved_56_57 = 0;
    filter_command.s.reserved_27_27 = 0;
    filter_command.s.reserved_10_14 = 0;
    filter_command.s.reserved_6_7 = 0;
    return filter_command.u64;
}

/**
 * Decode a TRA entry into human readable output
 *
 * @param tra_ctl Trace control setup
 * @param data    Data to decode
 */
void bdk_tra_decode_text(bdk_trax_ctl_t tra_ctl, bdk_tra_data_t data)
{
    {
        int type;

        type = data.cmn2.type;

        switch (1ull<<type)
        {
            case BDK_TRA_FILT_DECR64:
            case BDK_TRA_FILT_DECR32:
            case BDK_TRA_FILT_DECR16:
            case BDK_TRA_FILT_DECR8:
            case BDK_TRA_FILT_INCR64:
            case BDK_TRA_FILT_INCR32:
            case BDK_TRA_FILT_INCR16:
            case BDK_TRA_FILT_INCR8:
            case BDK_TRA_FILT_CLR64:
            case BDK_TRA_FILT_CLR32:
            case BDK_TRA_FILT_CLR16:
            case BDK_TRA_FILT_CLR8:
            case BDK_TRA_FILT_SET64:
            case BDK_TRA_FILT_SET32:
            case BDK_TRA_FILT_SET16:
            case BDK_TRA_FILT_SET8:
            case BDK_TRA_FILT_WBL2:
            case BDK_TRA_FILT_DWB:
            case BDK_TRA_FILT_RPL2:
            case BDK_TRA_FILT_PL2:
            case BDK_TRA_FILT_LDI:
            case BDK_TRA_FILT_LDT:
                printf("%02llx%016llx %c%+10d %-45s %s 0x%016llx%llx\n",
                   (unsigned long long)data.u128.datahi, (unsigned long long)data.u128.data,
                   (data.cmn2.discontinuity) ? 'D' : ' ',
                   data.cmn2.timestamp << (tra_ctl.s.time_grn*3),
                   TYPE_ARRAY2[type],
                   SOURCE_ARRAY[data.cmn2.source],
                   (unsigned long long)data.cmn2.addresshi,
                   (unsigned long long)data.cmn2.addresslo);
                break;
            case BDK_TRA_FILT_PSL1:
            case BDK_TRA_FILT_LDD:
            case BDK_TRA_FILT_FAS64:
            case BDK_TRA_FILT_FAS32:
            case BDK_TRA_FILT_FAA64:
            case BDK_TRA_FILT_FAA32:
            case BDK_TRA_FILT_SAA64:
            case BDK_TRA_FILT_SAA32:
            case BDK_TRA_FILT_STC:
            case BDK_TRA_FILT_STF:
            case BDK_TRA_FILT_STP:
            case BDK_TRA_FILT_STT:
                printf("%02llx%016llx %c%+10d %-45s %s mask=0x%02x 0x%016llx%llx\n",
                   (unsigned long long)data.u128.datahi, (unsigned long long)data.u128.data,
                   (data.cmn2.discontinuity) ? 'D' : ' ',
                   data.cmn2.timestamp << (tra_ctl.s.time_grn*3),
                   TYPE_ARRAY2[type],
                   SOURCE_ARRAY[data.store2.source],
                   (unsigned int)data.store2.mask,
                   (unsigned long long)data.store2.addresshi,
                   (unsigned long long)data.store2.addresslo);
                break;
            case BDK_TRA_FILT_IOBST64:
            case BDK_TRA_FILT_IOBST32:
            case BDK_TRA_FILT_IOBST16:
            case BDK_TRA_FILT_IOBST8:
            case BDK_TRA_FILT_IOBLD64:
            case BDK_TRA_FILT_IOBLD32:
            case BDK_TRA_FILT_IOBLD16:
            case BDK_TRA_FILT_IOBLD8:
                printf("%02llx%016llx %c%+10d %-45s %s->%s subdid=0x%x 0x%016llx%llx\n",
                   (unsigned long long)data.u128.datahi, (unsigned long long)data.u128.data,
                   (data.cmn2.discontinuity) ? 'D' : ' ',
                   data.cmn2.timestamp << (tra_ctl.s.time_grn*3),
                   TYPE_ARRAY2[type],
                   SOURCE_ARRAY[data.iobld2.source],
                   DEST_ARRAY[data.iobld2.dest],
                   (unsigned int)data.iobld2.subid,
                   (unsigned long long)data.iobld2.addresshi,
                   (unsigned long long)data.iobld2.addresslo);
                break;
            case BDK_TRA_FILT_IOBDMA:
                printf("%02llx%016llx %c%+10d %-45s %s->%s len=0x%x 0x%016llx%llx\n",
                   (unsigned long long)data.u128.datahi, (unsigned long long)data.u128.data,
                   (data.iob2.discontinuity) ? 'D' : ' ',
                   data.iob2.timestamp << (tra_ctl.s.time_grn*3),
                   TYPE_ARRAY2[type],
                   SOURCE_ARRAY[data.iob2.source],
                   DEST_ARRAY[data.iob2.dest],
                   (unsigned int)data.iob2.mask,
                   (unsigned long long)data.iob2.addresshi << 3,
                   (unsigned long long)data.iob2.addresslo << 3);
                break;
            default:
                printf("%02llx%016llx %c%+10d Unknown format\n",
                   (unsigned long long)data.u128.datahi, (unsigned long long)data.u128.data,
                   (data.cmn2.discontinuity) ? 'D' : ' ',
                   data.cmn2.timestamp << (tra_ctl.s.time_grn*3));
                break;
        }
    }
}


/**
 * Setup the TRA buffer for use
 *
 * @param filter  Which events to log
 * @param source_filter
 *                Source match
 * @param dest_filter
 *                Destination match
 * @param address Address compare
 * @param address_mask
 *                Address mask
 */
void bdk_tra_setup(bdk_tra_filt_t filter,
                    bdk_tra_sid_t source_filter, bdk_tra_did_t dest_filter,
                    uint64_t address, uint64_t address_mask)
{
    BDK_CSR_DEFINE(control, BDK_TRAX_CTL(0));
    BDK_CSR_DEFINE(filt_cmd, BDK_TRAX_FILT_CMD(0));
    BDK_CSR_DEFINE(filt_sid, BDK_TRAX_FILT_SID(0));
    BDK_CSR_DEFINE(filt_did, BDK_TRAX_FILT_DID(0));

    if (sizeof(bdk_tra_capture_t) < sizeof(__bdk_tra_capture_t))
        bdk_fatal("Internal TRA size larger than external\n");

    control.u64 = 0;
    control.s.rdat_md = 1;
    control.s.ignore_o = 1;
    control.s.wrap = 1;

    filt_cmd.u64 = __bdk_tra_set_filter_cmd_mask(filter);
    filt_sid.u64 = source_filter & BDK_TRA_SOURCE_MASK;
    filt_did.u64 = dest_filter & BDK_TRA_DESTINATION_MASK;

    for (int tra=0; tra<__bdk_tra_num(); tra++)
    {
        BDK_CSR_WRITE(BDK_TRAX_CTL(tra),            control.u64);
        BDK_CSR_WRITE(BDK_TRAX_FILT_CMD(tra),       filt_cmd.u64);
        BDK_CSR_WRITE(BDK_TRAX_FILT_SID(tra),       filt_sid.u64);
        BDK_CSR_WRITE(BDK_TRAX_FILT_DID(tra),       filt_did.u64);
        BDK_CSR_WRITE(BDK_TRAX_FILT_ADR_ADR(tra),   address);
        BDK_CSR_WRITE(BDK_TRAX_FILT_ADR_MSK(tra),   address_mask);
    }
}


/**
 * Setup a TRA trigger. How the triggers are used should be
 * setup using bdk_tra_setup.
 *
 * @param trigger Trigger to setup (0 or 1)
 * @param filter  Which types of events to trigger on
 * @param source_filter
 *                Source trigger match
 * @param dest_filter
 *                Destination trigger match
 * @param address Trigger address compare
 * @param address_mask
 *                Trigger address mask
 */
void bdk_tra_trig_setup(int trigger, bdk_tra_filt_t filter,
                         bdk_tra_sid_t source_filter, bdk_tra_did_t dest_filter,
                         uint64_t address, uint64_t address_mask)
{
    BDK_CSR_DEFINE(filt_cmd, BDK_TRAX_FILT_CMD(0));
    BDK_CSR_DEFINE(filt_sid, BDK_TRAX_FILT_SID(0));
    BDK_CSR_DEFINE(filt_did, BDK_TRAX_FILT_DID(0));

    filt_cmd.u64 = __bdk_tra_set_filter_cmd_mask(filter);
    filt_sid.u64 = source_filter & BDK_TRA_SOURCE_MASK;
    filt_did.u64 = dest_filter & BDK_TRA_DESTINATION_MASK;

    for (int tra=0; tra<__bdk_tra_num(); tra++)
    {
        if (trigger)
        {
            BDK_CSR_WRITE(BDK_TRAX_TRIG1_CMD(tra),       filt_cmd.u64);
            BDK_CSR_WRITE(BDK_TRAX_TRIG1_SID(tra),       filt_sid.u64);
            BDK_CSR_WRITE(BDK_TRAX_TRIG1_DID(tra),       filt_did.u64);
            BDK_CSR_WRITE(BDK_TRAX_TRIG1_ADR_ADR(tra),   address);
            BDK_CSR_WRITE(BDK_TRAX_TRIG1_ADR_MSK(tra),   address_mask);
        }
        else
        {
            BDK_CSR_WRITE(BDK_TRAX_TRIG0_CMD(tra),       filt_cmd.u64);
            BDK_CSR_WRITE(BDK_TRAX_TRIG0_SID(tra),       filt_sid.u64);
            BDK_CSR_WRITE(BDK_TRAX_TRIG0_DID(tra),       filt_did.u64);
            BDK_CSR_WRITE(BDK_TRAX_TRIG0_ADR_ADR(tra),   address);
            BDK_CSR_WRITE(BDK_TRAX_TRIG0_ADR_MSK(tra),   address_mask);
        }
    }
}


void bdk_tra_enable(void)
{
    BDK_CSR_INIT(control, BDK_TRAX_CTL(0));
    control.s.ena = 1;
    for (int tra=0; tra<__bdk_tra_num(); tra++)
        BDK_CSR_WRITE(BDK_TRAX_CTL(tra), control.u64);
}

void bdk_tra_disable(void)
{
    BDK_CSR_INIT(control, BDK_TRAX_CTL(0));
    control.s.ena = 0;
    for (int tra=0; tra<__bdk_tra_num(); tra++)
        BDK_CSR_WRITE(BDK_TRAX_CTL(tra), control.u64);
}

int bdk_tra_capture(bdk_tra_capture_t *capture_ext)
{
    __bdk_tra_capture_t *capture = (__bdk_tra_capture_t*)capture_ext;

    memset(capture, 0, sizeof(*capture));

    for (int tra=0; tra<__bdk_tra_num(); tra++)
    {
        capture->tra[tra].control.u64 = BDK_CSR_READ(BDK_TRAX_CTL(tra));
        for (int count=0; count<__bdk_tra_size(); count++)
        {
            bdk_tra_data_t data;
            if (OCTEON_IS_MODEL(OCTEON_CN63XX_PASS1_X))
            {
                data.u128.data = BDK_CSR_READ(BDK_TRAX_READ_DAT(tra));
                data.u128.datahi = BDK_CSR_READ(BDK_TRAX_READ_DAT(tra));
            }
            else
            {
                data.u128.data = BDK_CSR_READ(BDK_TRAX_READ_DAT(tra));
                data.u128.datahi = BDK_CSR_READ(BDK_TRAX_READ_DAT_HI(tra));
            }

            if (!data.cmn2.valid)
                break;
            capture->tra[tra].data[count] = data;
        }
    }
    return 0;
}

int bdk_tra_decode(bdk_tra_capture_t *capture_ext)
{
    const __bdk_tra_capture_t *capture = (const __bdk_tra_capture_t*)capture_ext;

    for (int tra=0; tra<__bdk_tra_num(); tra++)
    {
        printf("TRA%d:\n", tra);
        for (int count=0; count<__bdk_tra_size(); count++)
        {
            if (!capture->tra[tra].data[count].cmn2.valid)
                break;
            bdk_tra_decode_text(capture->tra[tra].control, capture->tra[tra].data[count]);
        }
    }
    return 0;
}

