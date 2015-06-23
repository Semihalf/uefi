#include <stdio.h>
#include <string.h>

#include <ff.h>

#include "main.h"

static const char *get_basename(const char *filename)
{
	const char *base = filename;

	while (filename)
	{
		if (NULL == (filename = strchr(filename, '/')))
			break;
		base = ++filename; /* skip '/' */
	}
	return base;
}

static int copy_file(const char *filename)
{
	int  rc = -1;
	FILE *sfp;
	FIL  tfp;
	FRESULT res;

	char buf[1024];
	int  n;
	UINT count;

	sfp = fopen(filename, "rb");
	if (!sfp)
		goto out;

	/* Get the file's base name */
	const char *base = get_basename(filename);

	res = f_open(&tfp, base, FA_WRITE | FA_CREATE_ALWAYS);
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

static int mkfs(char **argv)
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

static int put_files(char **argv)
{
	CHAT("Putting files:\n");
	while (*argv)
	{
		CHAT(" * %s - ", *argv);

		if (0 != copy_file(*argv))
			CHAT("ERROR\n");
		else
			CHAT("OK\n");

		argv++;
	}
	return 0;
}

static struct cmd_d
{
	const char	*cmd;
	int			(*f)(char **argv);
}
cmd_list[] =
{
	{ "mkfs",	mkfs },
	{ "put",	put_files },
	{ NULL,		NULL },
};

int run_command(char **argv)
{
	struct cmd_d *cmd = cmd_list;

	while (cmd->cmd)
	{
		if (0 == strcmp(*argv, cmd->cmd))
		{
			argv++;
			if (cmd->f)
				return (*cmd->f)(argv);
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
