#include <bdk.h>

/*
    Format of a SKU
    CN8890-2000BG2601-AAP-G
    CN8890-2000BG2601-AAP-PR-Y-G
    CN XX XX X - XXX BG XXX - XX (- XX) (- X) - G
    |  |  |  |   |   |  |     |     |      |    ^ RoHS Option, G=RoHS 6/6
    |  |  |  |   |   |  |     |     |      ^ Product Revision, blank for pass 1, Y=pass 2, W=pass 3
    |  |  |  |   |   |  |     |     ^ Product Phase, blank=production, PR=Prototype, ES=Engineering Sample
    |  |  |  |   |   |  |     ^ Marketing Segment Option (SC, SNT, etc)
    |  |  |  |   |   |  ^ Number of balls on the package
    |  |  |  |   |   ^ Ball Grid Array
    |  |  |  |   ^ Frequency in Mhz, 3 or 4 digits (300 - 2000)
    |  |  |  ^ Optional Customer Code, blank or A-Z
    |  |  ^ Number of cores, see table below
    |  ^ Processor family, plus or minus for L2 sizes and such (88, 86, 83, 81, 80)
    ^ Cavium Prefix, sometimes changed for customer specific parts

    Table of Core to Model encoding
        >= 48 shows xx90
        >= 44 shows xx88
        >= 42 shows xx85
        >= 32 shows xx80
        >= 24 shows xx70
        >= 20 shows xx65
        >= 16 shows xx60
        = 15 shows xx58
        = 14 shows xx55
        = 13 shows xx52
        = 12 shows xx50
        = 11 shows xx48
        = 10 shows xx45
        = 9 shows xx42
        = 8 shows xx40
        = 7 shows xx38
        = 6 shows xx34
        = 5 shows xx32
        = 4 shows xx30
        = 3 shows xx25
        = 2 shows xx20
        = 1 shows xx10
*/

/* Definition of each SKU table entry for the different dies */
typedef struct
{
    uint8_t     fuse_index; /* Index programmed into PNAME fuses to match this entry. Must never change once fused parts ship */
    const char  prefix[4];  /* Prefix before model number, usually "CN". Third letter is customer code shown after the model */
    uint8_t     model_base; /* First two digits of the model number */
    uint16_t    num_balls;  /* Number of balls on package, included in SKU */
    const char  segment[4]; /* Market segment SKU is for, 2-3 character string */
    uint16_t    fuses[32];  /* List of fuses required for operation of this SKU */
} model_sku_info_t;

/***************************************************/
/* SKU table for t88 */
/***************************************************/
static const model_sku_info_t t88_sku_info[] =
{
    /* Index zero reserved for no fuses programmed */
    { 0x01, "CN", 88, 2601, "AAP",
        { /* List of fuses for this SKU */
            0 /* End of fuse list marker */
        }
    },
    { 0x02, "CN", 88, 2601, "ST", /* 48 cores */
        { /* List of fuses for this SKU */
            BDK_MIO_FUS_FUSE_NUM_E_TNS_CRIPPLE, /* Disable TNS */
            BDK_MIO_FUS_FUSE_NUM_E_PEM_DISX(0), /* Disable PEM0-1 */
            BDK_MIO_FUS_FUSE_NUM_E_PEM_DISX(2), /* Disable PEM4-5 */
            0 /* End of fuse list marker */
        }
    },
    { 0x03, "CN", 88, 2601, "STT", /* 48 cores */
        { /* List of fuses for this SKU */
            BDK_MIO_FUS_FUSE_NUM_E_PEM_DISX(0), /* Disable PEM0-1 */
            BDK_MIO_FUS_FUSE_NUM_E_PEM_DISX(2), /* Disable PEM4-5 */
            0 /* End of fuse list marker */
        }
    },
    { 0x04, "CN", 88, 2601, "STP", /* 48 cores */
        { /* List of fuses for this SKU */
            BDK_MIO_FUS_FUSE_NUM_E_LMC_DIS,     /* Disable LMC2-3 */
            BDK_MIO_FUS_FUSE_NUM_E_TNS_CRIPPLE, /* Disable TNS */
            0 /* End of fuse list marker */
        }
    },
    { 0x05, "CN", 88, 2601, "ST", /* 32 cores */
        { /* List of fuses for this SKU */
            BDK_MIO_FUS_FUSE_NUM_E_TNS_CRIPPLE, /* Disable TNS */
            BDK_MIO_FUS_FUSE_NUM_E_PEM_DISX(0), /* Disable PEM0-1 */
            BDK_MIO_FUS_FUSE_NUM_E_PEM_DISX(2), /* Disable PEM4-5 */
            BDK_MIO_FUS_FUSE_NUM_E_BGX_DISX(1), /* Disable BGX1 */
            0 /* End of fuse list marker */
        }
    },
    { 0x06, "CN", 88, 2601, "ST", /* 24 cores */
        { /* List of fuses for this SKU */
            BDK_MIO_FUS_FUSE_NUM_E_LMC_DIS,     /* Disable LMC2-3 */
            BDK_MIO_FUS_FUSE_NUM_E_OCX_DIS,     /* Disable CCPI */
            BDK_MIO_FUS_FUSE_NUM_E_TNS_CRIPPLE, /* Disable TNS */
            BDK_MIO_FUS_FUSE_NUM_E_PEM_DISX(0), /* Disable PEM0-1 */
            BDK_MIO_FUS_FUSE_NUM_E_PEM_DISX(2), /* Disable PEM4-5 */
            BDK_MIO_FUS_FUSE_NUM_E_BGX_DISX(1), /* Disable BGX1 */
            0 /* End of fuse list marker */
        }
    },
    { 0x07, "CN", 88, 2601, "NTP", /* 48 cores */
        { /* List of fuses for this SKU */
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(0),/* Disable SATA0-3 */
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(1),/* Disable SATA4-7 */
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(2),/* Disable SATA8-11 */
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(3),/* Disable SATA12-15 */
            0 /* End of fuse list marker */
        }
    },
    { 0x08, "CN", 88, 2601, "NT", /* 48 cores */
        { /* List of fuses for this SKU */
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(0),/* Disable SATA0-3 */
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(2),/* Disable SATA8-11 */
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(3),/* Disable SATA12-15 */
            0 /* End of fuse list marker */
        }
    },
    { 0x09, "CN", 88, 2601, "NT", /* 32 cores */
        { /* List of fuses for this SKU */
            BDK_MIO_FUS_FUSE_NUM_E_LMC_DIS,     /* Disable LMC2-3 */
            BDK_MIO_FUS_FUSE_NUM_E_OCX_DIS,     /* Disable CCPI */
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(0),/* Disable SATA0-3 */
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(2),/* Disable SATA8-11 */
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(3),/* Disable SATA12-15 */
            BDK_MIO_FUS_FUSE_NUM_E_BGX_DISX(1), /* Disable BGX1 */
            0 /* End of fuse list marker */
        }
    },
    { 0x0a, "CN", 88, 2601, "CP", /* 48,32 cores */
        { /* List of fuses for this SKU */
            BDK_MIO_FUS_FUSE_NUM_E_NOZIP,       /* Disable Compression */
            BDK_MIO_FUS_FUSE_NUM_E_NODFA_CP2,   /* Disable HFA */
            BDK_MIO_FUS_FUSE_NUM_E_RSVD134X(0), /* Disable HNA */
            BDK_MIO_FUS_FUSE_NUM_E_TNS_CRIPPLE, /* Disable TNS */
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(0),/* Disable SATA0-3 */
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(2),/* Disable SATA8-11 */
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(3),/* Disable SATA12-15 */
            0 /* End of fuse list marker */
        }
    },
    { 0x0b, "CN", 88, 2601, "CP", /* 24 cores */
        { /* List of fuses for this SKU */
            BDK_MIO_FUS_FUSE_NUM_E_LMC_DIS,     /* Disable LMC2-3 */
            BDK_MIO_FUS_FUSE_NUM_E_NOZIP,       /* Disable Compression */
            BDK_MIO_FUS_FUSE_NUM_E_NODFA_CP2,   /* Disable HFA */
            BDK_MIO_FUS_FUSE_NUM_E_RSVD134X(0), /* Disable HNA */
            BDK_MIO_FUS_FUSE_NUM_E_OCX_DIS,     /* Disable CCPI */
            BDK_MIO_FUS_FUSE_NUM_E_TNS_CRIPPLE, /* Disable TNS */
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(0),/* Disable SATA0-3 */
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(2),/* Disable SATA8-11 */
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(3),/* Disable SATA12-15 */
            BDK_MIO_FUS_FUSE_NUM_E_BGX_DISX(1), /* Disable BGX1 */
            0 /* End of fuse list marker */
        }
    },
    { 0x0c, "CN", 88, 2601, "SNT", /* 48,32 cores, Nitrox connects to PEM2x8, QLM4-5 */
        { /* List of fuses for this SKU */
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(0),/* Disable SATA0-3 */
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(2),/* Disable SATA8-11 */
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(3),/* Disable SATA12-15 */
            0 /* End of fuse list marker */
        }
    },
    { 0x0d, "CN", 88, 2601, "SC", /* 48,32 cores, Nitrox connects to PEM2x8, QLM4-5 */
        { /* List of fuses for this SKU */
            BDK_MIO_FUS_FUSE_NUM_E_NOZIP,       /* Disable Compression */
            BDK_MIO_FUS_FUSE_NUM_E_NODFA_CP2,   /* Disable HFA */
            BDK_MIO_FUS_FUSE_NUM_E_RSVD134X(0), /* Disable HNA */
            BDK_MIO_FUS_FUSE_NUM_E_TNS_CRIPPLE, /* Disable TNS */
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(0),/* Disable SATA0-3 */
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(2),/* Disable SATA8-11 */
            BDK_MIO_FUS_FUSE_NUM_E_SATA_DISX(3),/* Disable SATA12-15 */
            0 /* End of fuse list marker */
        }
    },
    /* Index gap for adding more CN88 variants */
    { 0x20, "CN", 86, 1676, "AAP", /* No part, match unfused CN86XX */
        { /* List of fuses for this SKU */
            BDK_MIO_FUS_FUSE_NUM_E_CHIP_IDX(6), /* Alternate package fuse */
            0 /* End of fuse list marker */
        }
    },
    { 0x21, "CN", 86, 1676, "SCP", /* 40-8 cores */
        { /* List of fuses for this SKU */
            BDK_MIO_FUS_FUSE_NUM_E_CHIP_IDX(6), /* Alternate package fuse */
            BDK_MIO_FUS_FUSE_NUM_E_L2C_CRIPX(1),/* L2C is half size */
            BDK_MIO_FUS_FUSE_NUM_E_NODFA_CP2,   /* Disable HFA */
            BDK_MIO_FUS_FUSE_NUM_E_RSVD134X(0), /* Disable HNA */
            BDK_MIO_FUS_FUSE_NUM_E_LMC_DIS,     /* Disable LMC2-3 */
            BDK_MIO_FUS_FUSE_NUM_E_OCX_DIS,     /* Disable CCPI */
            BDK_MIO_FUS_FUSE_NUM_E_TNS_CRIPPLE, /* Disable TNS */
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
    /* Index zero reserved for no fuses programmed */
    { 0x01, "CN", 83, 1676, "SCP",
        { /* List of fuses for this SKU */
            // FIXME
            0 /* End of fuse list marker */
        }
    },
    { 0x02, "CN", 83, 1676, "CP",
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
    /* Index zero reserved for no fuses programmed */
    { 0x01, "CN", 81, 676, "SCP",
        { /* List of fuses for this SKU */
            /* No fuses */
            0 /* End of fuse list marker */
        }
    },
    { 0x02, "CN", 81, 676, "CP",
        { /* List of fuses for this SKU */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(0), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(1), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(2), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(3), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(4), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(5), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(6), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(7), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(8), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(9), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(10), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(11), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(12), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(13), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(14), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(15), /* Nitrox */
            0 /* End of fuse list marker */
        }
    },
    { 0x03, "CN", 80, 676, "SCP",
        { /* List of fuses for this SKU */
            BDK_MIO_FUS_FUSE_NUM_E_CHIP_IDX(7),     /* Alternate package fuse 2? */
            BDK_MIO_FUS_FUSE_NUM_E_L2C_CRIPX(1),    /* L2C is half size */
            BDK_MIO_FUS_FUSE_NUM_E_LMC_HALF,        /* LMC is half width */
            0 /* End of fuse list marker */
        }
    },
    { 0x04, "CN", 80, 676, "CP",
        { /* List of fuses for this SKU */
            BDK_MIO_FUS_FUSE_NUM_E_CHIP_IDX(7),     /* Alternate package fuse 2? */
            BDK_MIO_FUS_FUSE_NUM_E_L2C_CRIPX(1),    /* L2C is half size */
            BDK_MIO_FUS_FUSE_NUM_E_LMC_HALF,        /* LMC is half width */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(0), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(1), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(2), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(3), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(4), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(5), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(6), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(7), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(8), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(9), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(10), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(11), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(12), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(13), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(14), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(15), /* Nitrox */
            0 /* End of fuse list marker */
        }
    },
    { 0x05, "CN", 80, 555, "SCP",
        { /* List of fuses for this SKU */
            BDK_MIO_FUS_FUSE_NUM_E_CHIP_IDX(6),     /* Alternate package fuse */
            BDK_MIO_FUS_FUSE_NUM_E_L2C_CRIPX(1),    /* L2C is half size */
            BDK_MIO_FUS_FUSE_NUM_E_LMC_HALF,        /* LMC is half width */
            0 /* End of fuse list marker */
        }
    },
    { 0x06, "CN", 80, 555, "CP",
        { /* List of fuses for this SKU */
            BDK_MIO_FUS_FUSE_NUM_E_CHIP_IDX(6),     /* Alternate package fuse */
            BDK_MIO_FUS_FUSE_NUM_E_L2C_CRIPX(1),    /* L2C is half size */
            BDK_MIO_FUS_FUSE_NUM_E_LMC_HALF,        /* LMC is half width */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(0), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(1), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(2), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(3), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(4), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(5), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(6), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(7), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(8), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(9), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(10), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(11), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(12), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(13), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(14), /* Nitrox */
            BDK_MIO_FUS_FUSE_NUM_E_CPT_ENG_DISX(15), /* Nitrox */
            0 /* End of fuse list marker */
        }
    },
    {  0, } /* End of SKU list marker */
};

/**
 * Given a core count, return the last two digits of a model number
 *
 * @param cores  Number of cores
 *
 * @return Two digit model number
 */
static int model_digits_for_cores(int cores)
{
    /* If the number of cores is between two model levels, use the lower
       level. This assumes that a model gaurantees a minimum number of
       cores. This should never happen, but you never know */
    switch (cores)
    {
        case  1: return 10; /* CNxx10 = 1 core */
        case  2: return 20; /* CNxx20 = 2 cores */
        case  3: return 25; /* CNxx25 = 3 cores */
        case  4: return 30; /* CNxx30 = 4 cores */
        case  5: return 32; /* CNxx32 = 5 cores */
        case  6: return 34; /* CNxx34 = 6 cores */
        case  7: return 38; /* CNxx38 = 7 cores */
        case  8: return 40; /* CNxx40 = 8 cores */
        case  9: return 42; /* CNxx42 = 9 cores */
        case 10: return 45; /* CNxx45 = 10 cores */
        case 11: return 48; /* CNxx48 = 11 cores */
        case 12: return 50; /* CNxx50 = 12 cores */
        case 13: return 52; /* CNxx52 = 13 cores */
        case 14: return 55; /* CNxx55 = 14 cores */
        case 15: return 58; /* CNxx58 = 15 cores */
        case 16 ... 19: return 60; /* CNxx60 = 16 cores */
        case 20 ... 23: return 65; /* CNxx65 = 20 cores */
        case 24 ... 31: return 70; /* CNxx70 = 24 cores */
        case 32 ... 39: return 80; /* CNxx80 = 32 cores */
        case 40 ... 43: return 85; /* CNxx85 = 40 cores */
        case 44 ... 47: return 88; /* CNxx88 = 44 cores */
        default: return 90; /* CNxx90 = 48 cores */
    }
}

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
    const char *prefix          = sku_info[match_index].prefix;
    int         model           = 100 * sku_info[match_index].model_base;
    int         cores           = bdk_get_num_cores(node);
    const char *customer_code   = "";
    int         rclk_limit      = bdk_clock_get_rate(node, BDK_CLOCK_RCLK) / 1000000;
    const char *bg_str          = "BG"; /* Default Ball Grid array */
    int         balls           = sku_info[match_index].num_balls; /* Num package balls */
    const char *segment         = sku_info[match_index].segment; /* Market segment */
    const char *prod_phase      = ""; /* Default for production */
    const char *prod_rev        = ""; /* Product revision */
    const char *rohs_option     = "G"; /* RoHS is always G for current parts */

    /* Update the model number with the number of cores */
    model = (model / 100) * 100 + model_digits_for_cores(cores);

    /* Update the RCLK setting based on MIO_FUS_DAT3[core_pll_mul] */
    BDK_CSR_INIT(mio_fus_dat3, node, BDK_MIO_FUS_DAT3);
    if (mio_fus_dat3.s.core_pll_mul)
    {
        /* CORE_PLL_MUL covers bits 5:1, so we need to multiple by 2 */
        rclk_limit = mio_fus_dat3.s.core_pll_mul * 2 * 50;
    }

    /* Read the Pass information from fuses. Note that pass info in
       MIO_FUS_DAT2[CHIP_ID] is encoded as
            bit[7] = Unused, zero
            bit[6] = Alternate package
            bit[5..3] = Major pass
            bit[2..0] = Minor pass */
    BDK_CSR_INIT(mio_fus_dat2, node, BDK_MIO_FUS_DAT2);
    int major_pass = ((mio_fus_dat2.s.chip_id >> 3) & 7) + 1;
    switch (major_pass)
    {
        case 2:
            prod_rev = "-Y";
            break;
        case 3:
            prod_rev = "-W";
            break;
        default:
            prod_rev = "";
            break;
    }

    /* Read PNAME fuses, looking for SKU overrides */
    // FIXME: Implement PNAME reads

    /* Build the SKU string */
    snprintf(chip_sku[node], sizeof(chip_sku[node]), "%s%d%s-%d%s%d-%s%s%s-%s",
        prefix, model, customer_code, rclk_limit, bg_str, balls, segment,
        prod_phase, prod_rev, rohs_option);

    return chip_sku[node];
}
