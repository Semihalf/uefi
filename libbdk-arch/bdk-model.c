#include <bdk.h>

/* Definition of each SKU table entry for the different dies */
typedef struct
{
    int         fuse_index; /* Index programmed into PNAME fuses to match this entry. Must never change once fused parts ship */
    const char *prefix;     /* Prefix before model number, usually "CN" */
    int         model_base; /* Model number with zeros for the last two digits */
    int         num_balls;  /* Number of balls on package, included in SKU */
    const char *segment;    /* Market segment SKU is for, 2-3 character string */
    uint16_t    fuses[16];  /* List of fuses required for operation of this SKU */
} model_sku_info_t;

/***************************************************/
/* SKU table for t88 */
/***************************************************/
static const model_sku_info_t t88_sku_info[] =
{
    { 0x01, "CN", 8800, 2601, "AAP",
        { /* List of fuses for this SKU */
            0 /* End of fuse list marker */
        }
    },
    { 0x02, "CN", 8800, 2601, "ST",
        { /* List of fuses for this SKU */
            BDK_MIO_FUS_FUSE_NUM_E_PEM_DISX(0),
            BDK_MIO_FUS_FUSE_NUM_E_PEM_DISX(2),
            BDK_MIO_FUS_FUSE_NUM_E_TNS_CRIPPLE_CN88XX,
            0 /* End of fuse list marker */
        }
    },
    { 0x03, "CN", 8800, 2601, "ST",
        { /* List of fuses for this SKU */
            BDK_MIO_FUS_FUSE_NUM_E_OCX_DIS_CN88XX,
            BDK_MIO_FUS_FUSE_NUM_E_BGX_DISX(1),
            BDK_MIO_FUS_FUSE_NUM_E_PEM_DISX(0),
            BDK_MIO_FUS_FUSE_NUM_E_PEM_DISX(2),
            BDK_MIO_FUS_FUSE_NUM_E_LMC_DIS_CN88XX,
            BDK_MIO_FUS_FUSE_NUM_E_TNS_CRIPPLE_CN88XX,
            0 /* End of fuse list marker */
        }
    },
    { 0x04, "CN", 8800, 2601, "STT",
        { /* List of fuses for this SKU */
            BDK_MIO_FUS_FUSE_NUM_E_PEM_DISX(0),
            BDK_MIO_FUS_FUSE_NUM_E_PEM_DISX(2),
            0 /* End of fuse list marker */
        }
    },
    { 0x05, "CN", 8800, 2601, "NT",
        { /* List of fuses for this SKU */
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(0),
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(2),
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(3),
            0 /* End of fuse list marker */
        }
    },
    { 0x06, "CN", 8800, 2601, "NT",
        { /* List of fuses for this SKU */
            BDK_MIO_FUS_FUSE_NUM_E_OCX_DIS_CN88XX,
            BDK_MIO_FUS_FUSE_NUM_E_BGX_DISX(1),
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(0),
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(2),
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(3),
            BDK_MIO_FUS_FUSE_NUM_E_LMC_DIS_CN88XX,
            0 /* End of fuse list marker */
        }
    },
    { 0x07, "CN", 8800, 2601, "CP",
        { /* List of fuses for this SKU */
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(0),
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(2),
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(3),
            BDK_MIO_FUS_FUSE_NUM_E_TNS_CRIPPLE_CN88XX,
            BDK_MIO_FUS_FUSE_NUM_E_NOZIP,
            BDK_MIO_FUS_FUSE_NUM_E_NODFA_CP2_CN88XX, /* HFA */
            BDK_MIO_FUS_FUSE_NUM_E_RSVD134X(0), /* HNA */
            0 /* End of fuse list marker */
        }
    },
    { 0x08, "CN", 8800, 2601, "CP",
        { /* List of fuses for this SKU */
            BDK_MIO_FUS_FUSE_NUM_E_OCX_DIS_CN88XX,
            BDK_MIO_FUS_FUSE_NUM_E_BGX_DISX(1),
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(0),
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(2),
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(3),
            BDK_MIO_FUS_FUSE_NUM_E_LMC_DIS_CN88XX,
            BDK_MIO_FUS_FUSE_NUM_E_TNS_CRIPPLE_CN88XX,
            BDK_MIO_FUS_FUSE_NUM_E_NOZIP,
            BDK_MIO_FUS_FUSE_NUM_E_NODFA_CP2_CN88XX, /* HFA */
            BDK_MIO_FUS_FUSE_NUM_E_RSVD134X(0), /* HNA */
            0 /* End of fuse list marker */
        }
    },
    { 0x09, "CN", 8800, 2601, "SNT",
        { /* List of fuses for this SKU */
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(0),
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(2),
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(3),
            0 /* End of fuse list marker */
        }
    },
    { 0x0a, "CN", 8800, 2601, "SC",
        { /* List of fuses for this SKU */
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(0),
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(2),
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(3),
            BDK_MIO_FUS_FUSE_NUM_E_TNS_CRIPPLE_CN88XX,
            BDK_MIO_FUS_FUSE_NUM_E_NOZIP,
            BDK_MIO_FUS_FUSE_NUM_E_NODFA_CP2_CN88XX, /* HFA */
            BDK_MIO_FUS_FUSE_NUM_E_RSVD134X(0), /* HNA */
            0 /* End of fuse list marker */
        }
    },
    { 0x10, "CN", 8600, 1676, "AAP",
        { /* List of fuses for this SKU */
            BDK_MIO_FUS_FUSE_NUM_E_CHIP_IDX(6), /* Alternate package fuse */
            0 /* End of fuse list marker */
        }
    },
    { 0x10, "CN", 8600, 1676, "SCP",
        { /* List of fuses for this SKU */
            BDK_MIO_FUS_FUSE_NUM_E_CHIP_IDX(6), /* Alternate package fuse */
            BDK_MIO_FUS_FUSE_NUM_E_L2C_CRIPX(1),
            BDK_MIO_FUS_FUSE_NUM_E_NODFA_CP2_CN88XX, /* HFA */
            BDK_MIO_FUS_FUSE_NUM_E_RSVD134X(0), /* HNA */
            BDK_MIO_FUS_FUSE_NUM_E_LMC_DIS_CN88XX,
            BDK_MIO_FUS_FUSE_NUM_E_OCX_DIS_CN88XX,
            BDK_MIO_FUS_FUSE_NUM_E_TNS_CRIPPLE_CN88XX,
            0 /* End of fuse list marker */
        }
    },
    {  0, } /* End of SKU list marker */
};

/***************************************************/
/* SKU table for t83 */
/***************************************************/
static const model_sku_info_t t83_sku_info[] =
{
    // FIXME
    { 0x01, "CN", 8300, 1676, "SCP",
        { /* List of fuses for this SKU */
            0 /* End of fuse list marker */
        }
    },
    { 0x02, "CN", 8300, 1676, "CP",
        { /* List of fuses for this SKU */
            BDK_MIO_FUS_FUSE_NUM_E_NOZIP, /* Just a guess, no info yet */
            0 /* End of fuse list marker */
        }
    },
    {  0, } /* End of SKU list marker */
};

/***************************************************/
/* SKU table for t81 */
/***************************************************/
static const model_sku_info_t t81_sku_info[] =
{
    // FIXME
    { 0x01, "CN", 8100, 676, "SCP",
        { /* List of fuses for this SKU */
            0 /* End of fuse list marker */
        }
    },
    { 0x02, "CN", 8100, 676, "CP",
        { /* List of fuses for this SKU */
            BDK_MIO_FUS_FUSE_NUM_E_NOZIP, /* Just a guess, no info yet */
            0 /* End of fuse list marker */
        }
    },
    {  0, } /* End of SKU list marker */
};

/**
 * Return non-zero if the die is in an alternate package. The
 * normal is_model() checks will treat alternate package parts
 * as all the same, where this function can be used to detect
 * them.
 *
 * @param arg_model One of the CAVIUM_* constants for chip models and passes
 *
 * @return Non-zero if match
 */
int cavium_is_altpkg(uint32_t arg_model)
{
    if (CAVIUM_IS_MODEL(arg_model))
    {
        BDK_CSR_INIT(mio_fus_dat2, bdk_numa_local(), BDK_MIO_FUS_DAT2);
        return (mio_fus_dat2.s.chip_id & 0x40) != 0;
    }
    else
        return 0;
}

/**
 * Return the SKU string for a chip
 *
 * @param node   Node to get SKU for
 *
 * @return Chip's SKU
 */
const char* bdk_model_get_sku(int node)
{
    /* Storage for SKU is per node. Static variable stores the value
       so we don't decode on every call */
    static char chip_sku[BDK_NUMA_MAX_NODES][32] = { { 0, }, };

    /* Return the cached string if we've already filled it in */
    if (chip_sku[node][0])
        return chip_sku[node];

    /* Figure out which SKU list to use */
    const model_sku_info_t *sku_info;
    uint64_t result;
    asm ("mrs %[rd],MIDR_EL1" : [rd] "=r" (result));
    result = bdk_extract(result, 4, 12);
    switch (result)
    {
        case 0xa1:
            sku_info = t88_sku_info;
            break;
        case 0xa2:
            sku_info = t81_sku_info;
            break;
        case 0xa3:
            sku_info = t83_sku_info;
            break;
        default:
            bdk_fatal("SKU detect: Unknown die\n");
    }

    /* Read the SKU index from the PNAME fuses */
    int match_index = -1;
    // FIXME: Implement PNAME reads

    /* Search the SKU list for the best match, where all the fuses match.
       Only needed if the PNAME fuses don't specify the index */
    if (match_index == -1)
    {
        match_index = 0;
        int match_score = -1;
        int index = 0;
        while (sku_info[index].fuse_index)
        {
            int score = 0;
            int fuse_index = 0;
            /* Count the number of fuses that match. A mismatch forces the worst
               score (-1) */
            while (sku_info[index].fuses[fuse_index])
            {
                int fuse = bdk_fuse_read(node, sku_info[index].fuses[fuse_index]);
                if (fuse)
                {
                    /* Match, improve the score */
                    score++;
                }
                else
                {
                    /* Mismatch, force score bad */
                    score = -1;
                    break;
                }
                fuse_index++;
            }
            /* If this score is better than the last match, use this index as the
               match */
            if (score > match_score)
            {
                match_score = score;
                match_index = index;
            }
            index++;
        }
    }

    /* Use the SKU table to determine the defaults for the SKU parts */
    const char *prefix  = sku_info[match_index].prefix;
    int         model   = sku_info[match_index].model_base;
    int         cores   = bdk_get_num_cores(node);
    int         rclk    = bdk_clock_get_rate(node, BDK_CLOCK_RCLK) / 1000000;
    const char *bg_str  = "BG"; /* Default not low power */
    int         balls   = sku_info[match_index].num_balls;
    const char *segment = sku_info[match_index].segment;
    const char *suffix  = ""; /* Default for production */

    /* Update the model number with the number of cores. If the number of
       cores is between two model levels, use the lower level. This assumes
       that a model gaurantees a minimum number of cores. This should never
       happen, but you never know */
    model = (model / 100) * 100; /* Zero out lower two digits */
    switch (cores)
    {
        case 1: /* CNxx10 = 1 core */
            model += 10;
            break;
        case 2 ... 3: /* CNxx20 = 2 cores */
            model += 20;
            break;
        case 4 ... 7: /* CNxx30 = 4 cores */
            model += 30;
            break;
        case 8 ... 11: /* CNxx40 = 8 cores */
            model += 40;
            break;
        case 12 ... 15: /* CNxx50 = 12 cores */
            model += 50;
            break;
        case 16 ... 19: /* CNxx60 = 16 cores */
            model += 60;
            break;
        case 20 ... 23: /* CNxx65 = 20 cores */
            model += 65; /* This currently isn't used */
            break;
        case 24 ... 31: /* CNxx70 = 24 cores */
            model += 70;
            break;
        case 32 ... 47: /* CNxx80 = 32 cores */
            model += 80;
            break;
        default: /* CNxx90 = 48 cores */
            model += 90;
            break;
    }

    /* Update the RCLK setting based on MIO_FUS_DAT3[core_pll_mul] */
    BDK_CSR_INIT(mio_fus_dat3, node, BDK_MIO_FUS_DAT3);
    if (mio_fus_dat3.s.core_pll_mul)
    {
        /* CORE_PLL_MUL covers bits 5:1, so we need to multiple by 2 */
        rclk = mio_fus_dat3.s.core_pll_mul * 2 * 50;
    }

    /* Read PNAME fuses, looking for SKU overrides */
    // FIXME: Implement PNAME reads

    /* Read the Pass information from fuses. Note that pass info in
       MIO_FUS_DAT2[CHIP_ID] is encoded as
            bit[7] = Unused, zero
            bit[6] = Alternate package
            bit[5..3] = Major pass
            bit[2..0] = Minor pass */
    BDK_CSR_INIT(mio_fus_dat2, node, BDK_MIO_FUS_DAT2);
    const char *pass_str; /* String representing pass */
    int major_pass = ((mio_fus_dat2.s.chip_id >> 3) & 7) + 1;
    switch (major_pass)
    {
        case 2:
            pass_str = "-Y";
            break;
        case 3:
            pass_str = "-Z";
            break;
        default:
            pass_str = "";
            break;
    }

    /* Build the SKU string */
    snprintf(chip_sku[node], sizeof(chip_sku[node]), "%s%d-%d%s%d-%s%s%s-G",
        prefix, model, rclk, bg_str, balls, segment, suffix, pass_str);

    return chip_sku[node];
}
