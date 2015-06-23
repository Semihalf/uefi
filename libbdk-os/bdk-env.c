#include <bdk.h>
#include <errno.h>
#include <string.h>

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(ENVIRONMENT);

extern char **environ;

static int bdk_env_file_read(const char *filename)
{
    char line[BDK_ENV_MAX_LINE_LEN];

    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        bdk_warn("Opening BDK configuration file %s for reading failed (%s).\n",
                    filename, strerror(errno));
        return -1;
    }

    while (fgets(line, sizeof(line), fp))
    {
        char *pv = line;
        char *p;

        /* ignore comments, empty lines and lines that start with a whitespace */
        if ('#' == *pv || '\n' == *pv || '\t' == *pv || ' ' == *pv)
            continue;

        /* find the '=' */
        pv = strchr(pv, '=');
        if (!pv)
        {
            bdk_warn("Malformed entry in BDK configuration file. Missing '=':\n"
                     "  %s\n", line);
            continue; /* no '=' in line, skip */
        }
        *pv = '\0'; /* split name and value */
        pv++;       /* now points to value */

        /* find '\n' and remove it */
        p = strchr(pv, '\n');
        if (p)
            *p = '\0';
        else
            bdk_warn("Possibly truncated variable '%s', value '%s'\n", line, pv);

        BDK_TRACE(ENV, "Read env variable %s=%s\n", line, pv);

        /* set variable */
        if (0 != setenv(line, pv, 1))
            break; /* bail on error */
    }

    if (0 != fclose(fp))
    {
        bdk_warn("Could not close BDK configuration file (%s)\n", strerror(errno));
        /* Should this return -1? */
    }

    BDK_TRACE(ENV, "Read configuration file %s.\n", filename);
    return 0;
}

static int bdk_env_file_write(const char *filename)
{
    char **ep;
    int rc = -1;
    FILE *fp;
    char *header =
"# Valid mode strings for QLM.MODE configuration:\n"
"#\n"
"#    QLM_MODE_DISABLED      /* QLM is disabled */\n"
"#    QLM_MODE_PCIE_1X1      /* 1 PCIe, 1 lane. Other lanes unused */\n"
"#    QLM_MODE_PCIE_2X1      /* 2 PCIe, 1 lane each */\n"
"#    QLM_MODE_PCIE_1X2      /* 1 PCIe, 2 lanes */\n"
"#    QLM_MODE_PCIE_1X4      /* 1 PCIe, 4 lanes */\n"
"#    QLM_MODE_PCIE_1X8      /* 1 PCIe, 8 lanes */\n"
"#\n"
"#    QLM_MODE_SATA_4X1      /* SATA, each lane independent */\n"
"#\n"
"#    QLM_MODE_ILK           /* ILK 4 lanes */\n"
"#    QLM_MODE_SGMII         /* SGMII, each lane independent */\n"
"#    QLM_MODE_XAUI_1X4      /* 1 XAUI or DXAUI, 4 lanes */\n"
"#    QLM_MODE_RXAUI_2X2     /* 2 RXAUI, 2 lanes each */\n"
"#    QLM_MODE_OCI           /* OCI Multichip interconnect */\n"
"#    QLM_MODE_XFI_4X1       /* 4 XFI, 1 lane each */\n"
"#    QLM_MODE_XLAUI_1X4     /* 1 XLAUI, 4 lanes each */\n"
"#    QLM_MODE_10G_KR_4X1    /* 4 10GBASE-KR, 1 lane each */\n"
"#    QLM_MODE_40G_KR4_1X4   /* 1 40GBASE-KR4, 4 lanes each */\n"
"#    QLM_MODE_SKIP          /* Skip configuration of this QLM */\n"
"#\n";

    fp = fopen(filename, "w");
    if (!fp)
    {
        bdk_warn("Opening BDK configuration file %s for writing failed (%s).\n",
                    filename, strerror(errno));
        goto out;
    }

    /* Write file header */
    if (1 != fwrite(header, strlen(header), 1, fp))
        goto out;

    /* Write out variable entries */
    ep = environ;
    while (*ep)
    {
        if (1 != fwrite(*ep, strlen(*ep), 1, fp))
            goto out;
        if (EOF == fputc('\n', fp))
            goto out;
        ep++;
    }
    BDK_TRACE(ENV, "Saved environment variables to BDK configuration file %s\n", filename);

    rc = 0;
out:
    if (fp)
        if (0 != fclose(fp))
            bdk_warn("Could not close BDK configuration file (i%s)\n", strerror(errno));
    return rc;
}

int bdk_loadenv(const char *filename)
{
    if (!filename)
        filename = BDK_ENV_CFG_FILE_NAME;
    return bdk_env_file_read(filename);
}

int bdk_saveenv(const char *filename)
{
    if (!filename)
        filename = BDK_ENV_CFG_FILE_NAME;
    return bdk_env_file_write(filename);
}

void bdk_setenv(const char *name, const char *value)
{
    if (value)
       setenv(name, value, 1);
    else
       unsetenv(name);
}

void bdk_showenv(void)
{
    if (!environ)
    {
        bdk_error("Environment not allocated\n");
        return;
    }

    char **ptr = environ;
    while (*ptr)
    {
        printf("    %s\n", *ptr);
        ptr++;
    }
}

/*
 * API for board configuration.
 */
/* Clip off the last dotted segment of the id string */
static void bdk_board_cfg_clip_end(char *id)
{
    char *p = id;

    while (*p++) ;
    while ('.' != *--p && p != id) ;
    *p = '\0';
}

/* Look up a board configuration variable in the environment. */
static const char *bdk_board_cfg_get_value(const char *id, int recursive)
{
    char name[BDK_BRD_CFG_MAX_VAR_NAME_LEN];
    const char *val;

    /* copy the id so we can clip it if we need to */
    strncpy(name, id, sizeof(name));

    while (*name)
    {
        if (NULL != (val = getenv(name)))
        {
            BDK_TRACE(ENV, "GET %s (using %s) -> %s\n", id, name, val);
            return val;
        }

        /* If the recursive flag is set we'll try to find a parent entry that
         * has a value we can use.
         */
        if (recursive)
            bdk_board_cfg_clip_end(name);
        else
            break;
    }
    BDK_TRACE(ENV, "GET %s -> NOT FOUND\n", id);
    return NULL;
}

/* Set a board configuration variable in the environment. */
static void bdk_board_cfg_set_value(const char *id, const char *value)
{
    BDK_TRACE(ENV, "SET %s=%s\n", id, value);
    bdk_setenv(id, value);
}

/*
 * Public API
 */
/* Look up a board configuration variable.
 *
 * The variable name  is constructed by using the format string and the
 * arguments, following the printf() convention.
 */
long bdk_brd_cfg_get_int(const char *format, ...)
{
    char name[BDK_BRD_CFG_MAX_VAR_NAME_LEN];
    va_list args;

    va_start(args, format);
    vsnprintf(name, sizeof(name), format, args);
    va_end(args);
    return atol(bdk_board_cfg_get_value(name, 1));
}

/* Set a board configuration variable.
 *
 * The variable name  is constructed by using the format string and the
 * arguments, following the printf() convention.
 */
void bdk_brd_cfg_set_int(long value, const char *format, ...)
{
    char name[BDK_BRD_CFG_MAX_VAR_NAME_LEN];
    char valstr[32];
    va_list args;

    va_start(args, format);
    vsnprintf(name, sizeof(name), format, args);
    va_end(args);

    snprintf(valstr, sizeof(valstr), "%ld", value);
    bdk_board_cfg_set_value(name, valstr);
}

/* Look up a board configuration variable.
 *
 * The variable name  is constructed by using the format string and the
 * arguments, following the printf() convention.
 */
const char *bdk_brd_cfg_get_str(const char *format, ...)
{
    char name[BDK_BRD_CFG_MAX_VAR_NAME_LEN];
    va_list args;

    va_start(args, format);
    vsnprintf(name, sizeof(name), format, args);
    va_end(args);
    return bdk_board_cfg_get_value(name, 1);
}

/* Set a board configuration variable.
 *
 * The variable name  is constructed by using the format string and the
 * arguments, following the printf() convention.
 */
void bdk_brd_cfg_set_str(const char *value, const char *format, ...)
{
    char name[BDK_BRD_CFG_MAX_VAR_NAME_LEN];
    va_list args;

    va_start(args, format);
    vsnprintf(name, sizeof(name), format, args);
    va_end(args);
    bdk_board_cfg_set_value(name, value);
}
