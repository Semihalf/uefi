#include <stdio.h>
#include <string.h>

#include <ff.h>

#include "main.h"

/*
 * Helper functions
 */
static const char *get_basename(const char *filename)
{
	const char *p = filename;

	while (*p++) ; /* find end of line */
	while (*--p != '/' && p != filename) ; /* walk back until '/' or beginning */

	return p == filename ? p : ++p;
}

static int copy_file(const char *filename, const char *target_dir)
{
	int  rc = -1;
	FILE *sfp;
	FIL  tfp;
	FRESULT res;

	char fullpath[256];
	char buf[1024];
	int  n;
	UINT count;

	sfp = fopen(filename, "rb");
	if (!sfp)
		goto out;

	/* Get the file's base name */
	const char *base = get_basename(filename);

	snprintf(fullpath, sizeof(fullpath), "%s/%s", target_dir, base);

	res = f_open(&tfp, fullpath, FA_WRITE | FA_CREATE_ALWAYS);
	if (res)
		goto out;

	while (0 != (n = fread(buf, 1, sizeof(buf), sfp)))
		f_write(&tfp, buf, n, &count);

	rc = 0;
out:
	if (sfp)
		fclose(sfp);
	f_close(&tfp);
	return rc;
}

static int dir_exists(const char *path)
{
	DIR dp;
	FRESULT res = f_opendir(&dp, path);
	if (res)
		return 0;

	f_closedir(&dp);
	return 1;
}

/*
 * Commands
 */
static int mkfs(int argc, char **argv)
{
	if (*argv)
	{
		fprintf(stderr, "WARNING: Ignoring arguments for mkfs:");
		while (*argv)
		{
			fprintf(stderr, " %s", *argv);
			argv++;
		}
		fprintf(stderr, "\n");
	}

	CHAT("Creating FAT filesystem - ");
	FRESULT res = f_mkfs("DISK_IMG",	/* dummy, not used right now */
						 1,				/* SFD */
						 1);			/* 1 sector allocation size */

	if (res)
	{
		CHAT("ERROR (%d)\n", res);
		return -1;
	}
	CHAT("OK\n");
	return 0;
}

static int mkdir(int argc, char **argv)
{
	while (*argv)
	{
		CHAT("Creating directory %s\n", *argv);

		FRESULT res = f_mkdir(*argv);
		if (res)
		{
			CHAT("ERROR (%d)\n", res);
			return -1;
		}
		else
			CHAT("OK\n");

		argv++;
	}
	return 0;
}

static int cp(int argc, char **argv)
{
	CHAT("Copy files:\n");

	if (argc < 3)
	{
		fprintf(stderr, "cp: not enough arguments\n");
		return -1;
	}

	const char *target_dir = argv[argc -2];

	if (!dir_exists(target_dir))
	{
		fprintf(stderr, "cp: Target directory %s does not exist. Aborting.\n", target_dir);
		return -1;
	}

	int is_root = *target_dir == '/' && !*(target_dir +1);

	while (argc > 2)
	{
		const char *base_name  = get_basename(*argv);
		CHAT(" * %s -> %s%s%s ", *argv, target_dir, is_root ? "" : "/", base_name);

		if (0 != copy_file(*argv, target_dir))
			CHAT("ERROR\n");
		else
			CHAT("OK\n");

		argv++;
		argc--;
	}
	return 0;
}

/*
 * Main handler
 */
static struct cmd_d
{
	const char	*cmd;
	int			(*f)(int argc, char **argv);
}
cmd_list[] =
{
	{ "mkfs",	mkfs },
	{ "mkdir",	mkdir },
	{ "cp",		cp },
	{ NULL,		NULL },
};

int run_command(int argc, char **argv)
{
	struct cmd_d *cmd = cmd_list;

	while (cmd->cmd)
	{
		if (0 == strcmp(*argv, cmd->cmd))
		{
			argv++;
			if (cmd->f)
				return (*cmd->f)(argc, argv);
			return -1;
		}

		cmd++;
	}

	if (!cmd->cmd)
	{
		fprintf(stderr, "ERROR: Illegal command '%s'\n", *argv);
		return -1; /* command not found */
	}

	return 0;
}
