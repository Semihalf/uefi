/* Flag bits in top byte */
#define OM_IGNORE_REVISION        0x01000000      /* Ignores revision in model checks */
#define OM_CHECK_SUBMODEL         0x02000000      /* Check submodels */
#define OM_MATCH_PREVIOUS_MODELS  0x04000000      /* Match all models previous than the one specified */
#define OM_IGNORE_MINOR_REVISION  0x08000000      /* Ignores the minor revison on newer parts */
#define OM_FLAG_MASK              0xff000000

#define OM_MATCH_5XXX_FAMILY_MODELS     0x20000000 /* Match all cn5XXX Octeon models. */
#define OM_MATCH_6XXX_FAMILY_MODELS     0x40000000 /* Match all cn6XXX Octeon models. */

/*
 * CN6XXX models with new revision encoding
 */
#define OCTEON_CN63XX_PASS1_0   0x000d9000
#define OCTEON_CN63XX_PASS1_1   0x000d9001
#define OCTEON_CN63XX_PASS1_2   0x000d9002
#define OCTEON_CN63XX_PASS2_0   0x000d9008

#define OCTEON_CN63XX           (OCTEON_CN63XX_PASS1_0 | OM_IGNORE_REVISION)
#define OCTEON_CN63XX_PASS1_X   (OCTEON_CN63XX_PASS1_0 | OM_IGNORE_MINOR_REVISION)
#define OCTEON_CN63XX_PASS2_X   (OCTEON_CN63XX_PASS2_0 | OM_IGNORE_MINOR_REVISION)

#define OCTEON_CN68XX_PASS1_0   0x000d9100

#define OCTEON_CN68XX           (OCTEON_CN68XX_PASS1_0 | OM_IGNORE_REVISION)
#define OCTEON_CN68XX_PASS1_X   (OCTEON_CN68XX_PASS1_0 | OM_IGNORE_MINOR_REVISION)

/*
 * CN5XXX models with new revision encoding
 */
#define OCTEON_CN58XX_PASS1_0   0x000d0300
#define OCTEON_CN58XX_PASS1_1   0x000d0301
#define OCTEON_CN58XX_PASS1_2   0x000d0303
#define OCTEON_CN58XX_PASS2_0   0x000d0308
#define OCTEON_CN58XX_PASS2_1   0x000d0309
#define OCTEON_CN58XX_PASS2_2   0x000d030a
#define OCTEON_CN58XX_PASS2_3   0x000d030b

#define OCTEON_CN58XX           (OCTEON_CN58XX_PASS1_0 | OM_IGNORE_REVISION)
#define OCTEON_CN58XX_PASS1_X   (OCTEON_CN58XX_PASS1_0 | OM_IGNORE_MINOR_REVISION)
#define OCTEON_CN58XX_PASS2_X   (OCTEON_CN58XX_PASS2_0 | OM_IGNORE_MINOR_REVISION)
#define OCTEON_CN58XX_PASS1     OCTEON_CN58XX_PASS1_X
#define OCTEON_CN58XX_PASS2     OCTEON_CN58XX_PASS2_X

#define OCTEON_CN56XX_PASS1_0   0x000d0400
#define OCTEON_CN56XX_PASS1_1   0x000d0401
#define OCTEON_CN56XX_PASS2_0   0x000d0408
#define OCTEON_CN56XX_PASS2_1   0x000d0409

#define OCTEON_CN56XX           (OCTEON_CN56XX_PASS2_0 | OM_IGNORE_REVISION)
#define OCTEON_CN56XX_PASS1_X   (OCTEON_CN56XX_PASS1_0 | OM_IGNORE_MINOR_REVISION)
#define OCTEON_CN56XX_PASS2_X   (OCTEON_CN56XX_PASS2_0 | OM_IGNORE_MINOR_REVISION)
#define OCTEON_CN56XX_PASS1     OCTEON_CN56XX_PASS1_X
#define OCTEON_CN56XX_PASS2     OCTEON_CN56XX_PASS2_X

#define OCTEON_CN57XX           OCTEON_CN56XX
#define OCTEON_CN57XX_PASS1     OCTEON_CN56XX_PASS1
#define OCTEON_CN57XX_PASS2     OCTEON_CN56XX_PASS2

#define OCTEON_CN55XX           OCTEON_CN56XX
#define OCTEON_CN55XX_PASS1     OCTEON_CN56XX_PASS1
#define OCTEON_CN55XX_PASS2     OCTEON_CN56XX_PASS2

#define OCTEON_CN54XX           OCTEON_CN56XX
#define OCTEON_CN54XX_PASS1     OCTEON_CN56XX_PASS1
#define OCTEON_CN54XX_PASS2     OCTEON_CN56XX_PASS2

#define OCTEON_CN50XX_PASS1_0   0x000d0600

#define OCTEON_CN50XX           (OCTEON_CN50XX_PASS1_0 | OM_IGNORE_REVISION)
#define OCTEON_CN50XX_PASS1_X   (OCTEON_CN50XX_PASS1_0 | OM_IGNORE_MINOR_REVISION)
#define OCTEON_CN50XX_PASS1     OCTEON_CN50XX_PASS1_X

/* NOTE: Octeon CN5000F model is not identifiable using the OCTEON_IS_MODEL()
    functions, but are treated as CN50XX */

#define OCTEON_CN52XX_PASS1_0   0x000d0700
#define OCTEON_CN52XX_PASS2_0   0x000d0708

#define OCTEON_CN52XX           (OCTEON_CN52XX_PASS2_0 | OM_IGNORE_REVISION)
#define OCTEON_CN52XX_PASS1_X   (OCTEON_CN52XX_PASS1_0 | OM_IGNORE_MINOR_REVISION)
#define OCTEON_CN52XX_PASS2_X   (OCTEON_CN52XX_PASS2_0 | OM_IGNORE_MINOR_REVISION)
#define OCTEON_CN52XX_PASS1     OCTEON_CN52XX_PASS1_X
#define OCTEON_CN52XX_PASS2     OCTEON_CN52XX_PASS2_X

/*
 * CN3XXX models with old revision enconding
 */
//#define OCTEON_CN38XX_PASS1     0x000d0000    // is not supported
#define OCTEON_CN38XX_PASS2     0x000d0001
#define OCTEON_CN38XX_PASS3     0x000d0003
#define OCTEON_CN38XX           (OCTEON_CN38XX_PASS3 | OM_IGNORE_REVISION)

#define OCTEON_CN38XX_PASS2_X   OCTEON_CN38XX_PASS2
#define OCTEON_CN38XX_PASS3_X   OCTEON_CN38XX_PASS3

/* The OCTEON_CN31XX matches CN31XX models and the CN3020 */
#define OCTEON_CN31XX_PASS1     0x000d0100
#define OCTEON_CN31XX_PASS1_1   0x000d0102
#define OCTEON_CN31XX           (OCTEON_CN31XX_PASS1 | OM_IGNORE_REVISION)

/* This model is only used for internal checks, it
** is not a valid model for the OCTEON_MODEL environment variable.
** This matches the CN3010 and CN3005 but NOT the CN3020*/
#define OCTEON_CN30XX_PASS1     0x000d0200
#define OCTEON_CN30XX_PASS1_1   0x000d0202
#define OCTEON_CN30XX           (OCTEON_CN30XX_PASS1 | OM_IGNORE_REVISION)

/* This matches the complete family of CN3xxx CPUs, and not subsequent models */
#define OCTEON_CN3XXX           (OCTEON_CN58XX_PASS1_0 | OM_MATCH_PREVIOUS_MODELS | OM_IGNORE_REVISION)
#define OCTEON_CN5XXX           (OCTEON_CN58XX_PASS1_0 | OM_MATCH_5XXX_FAMILY_MODELS)
#define OCTEON_CN6XXX           (OCTEON_CN63XX_PASS1_0 | OM_MATCH_6XXX_FAMILY_MODELS)

/* The revision byte (low byte) has two different encodings.
** CN3XXX:
**
**     bits
**     <7:5>: reserved (0)
**     <4>:   alternate package
**     <3:0>: revision
**
** CN5XXX:
**
**     bits
**     <7>:   reserved (0)
**     <6>:   alternate package
**     <5:3>: major revision
**     <2:0>: minor revision
**
*/

/* Masks used for the various types of model/family/revision matching */
#define OCTEON_38XX_FAMILY_MASK      0x00ffff00
#define OCTEON_38XX_FAMILY_REV_MASK  0x00ffff0f
#define OCTEON_38XX_MODEL_MASK       0x00ffff10
#define OCTEON_38XX_MODEL_REV_MASK   (OCTEON_38XX_FAMILY_REV_MASK | OCTEON_38XX_MODEL_MASK)

/* CN5XXX and later use different layout of bits in the revision ID field */
#define OCTEON_58XX_FAMILY_MASK      OCTEON_38XX_FAMILY_MASK
#define OCTEON_58XX_FAMILY_REV_MASK  0x00ffff3f
#define OCTEON_58XX_MODEL_MASK       0x00ffffc0
#define OCTEON_58XX_MODEL_REV_MASK   (OCTEON_58XX_FAMILY_REV_MASK | OCTEON_58XX_MODEL_MASK)
#define OCTEON_58XX_MODEL_MINOR_REV_MASK (OCTEON_58XX_MODEL_REV_MASK & 0x00fffff8)
#define OCTEON_5XXX_MODEL_MASK       0x00ff0fc0

static int __OCTEON_MATCH_MASK__(uint32_t x, uint32_t y, uint32_t z)
{
    return (x & z) == (y & z);
}

static int OCTEON_IS_MODEL(uint32_t arg_model)
{
    uint32_t chip_model;
    BDK_MF_COP0(chip_model, COP0_PRID);

    if ((arg_model & OCTEON_38XX_FAMILY_MASK) < OCTEON_CN58XX_PASS1_0)
    {
        if ((arg_model & OM_FLAG_MASK) == (OM_IGNORE_REVISION | OM_CHECK_SUBMODEL))
        {
            return __OCTEON_MATCH_MASK__(chip_model, arg_model, OCTEON_38XX_MODEL_MASK);
        }
        else if ((arg_model & OM_FLAG_MASK) == 0)
        {
            return __OCTEON_MATCH_MASK__(chip_model, arg_model, OCTEON_38XX_FAMILY_REV_MASK);
        }
        else if ((arg_model & OM_FLAG_MASK) == OM_IGNORE_REVISION)
        {
            return __OCTEON_MATCH_MASK__(chip_model, arg_model, OCTEON_38XX_FAMILY_MASK);
        }
        else if ((arg_model & OM_FLAG_MASK) == OM_CHECK_SUBMODEL)
        {
            return __OCTEON_MATCH_MASK__(chip_model, arg_model, OCTEON_38XX_MODEL_REV_MASK);
        }
        else if ((arg_model & OM_MATCH_PREVIOUS_MODELS) == OM_MATCH_PREVIOUS_MODELS)
        {
            return (chip_model & OCTEON_38XX_MODEL_MASK) < (arg_model & OCTEON_38XX_MODEL_MASK);
        }
    }
    else
    {
        if ((arg_model & OM_FLAG_MASK) == (OM_IGNORE_REVISION | OM_CHECK_SUBMODEL))
        {
            return __OCTEON_MATCH_MASK__(chip_model, arg_model, OCTEON_58XX_MODEL_MASK);
        }
        else if ((arg_model & OM_FLAG_MASK) == 0)
        {
            return __OCTEON_MATCH_MASK__(chip_model, arg_model, OCTEON_58XX_FAMILY_REV_MASK);
        }
        else if ((arg_model & OM_FLAG_MASK) == OM_IGNORE_MINOR_REVISION)
        {
            return __OCTEON_MATCH_MASK__(chip_model, arg_model, OCTEON_58XX_MODEL_MINOR_REV_MASK);
        }
        else if ((arg_model & OM_FLAG_MASK) == OM_IGNORE_REVISION)
        {
            return __OCTEON_MATCH_MASK__(chip_model, arg_model, OCTEON_58XX_FAMILY_MASK);
        }
        else if ((arg_model & OM_FLAG_MASK) == OM_CHECK_SUBMODEL)
        {
            return __OCTEON_MATCH_MASK__(chip_model, arg_model, OCTEON_58XX_MODEL_REV_MASK);
        }
        else if ((arg_model & OM_MATCH_5XXX_FAMILY_MODELS) == OM_MATCH_5XXX_FAMILY_MODELS)
        {
            return (chip_model >= OCTEON_CN58XX_PASS1_0) && (chip_model < OCTEON_CN63XX_PASS1_0);
        }
        else if ((arg_model & OM_MATCH_6XXX_FAMILY_MODELS) == OM_MATCH_6XXX_FAMILY_MODELS)
        {
            return chip_model >= OCTEON_CN63XX_PASS1_0;
        }
        else if ((arg_model & OM_MATCH_PREVIOUS_MODELS) == OM_MATCH_PREVIOUS_MODELS)
        {
            return (chip_model & OCTEON_58XX_MODEL_MASK) < (arg_model & OCTEON_58XX_MODEL_MASK);
        }
    }
    return 0;
}

