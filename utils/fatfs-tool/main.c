#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <ff.h>
#include <diskio_img_file.h>

#include "cmd.h"
#include "main.h"

/******************************************************************************/

int fatfs_tool_debug = 0;

int verbose = 1;

/******************************************************************************/

static void usage()
{
	printf(
		"USAGE: fatfs-tool [-q] [-d] [-m] -i <image_file> command [args]...\n"
		"        -q               - Be quiet\n"
		"        -d               - Enable debug messages\n"
		"        -i <image_file>  - Image file to use\n"
		"        command          - Command to execute\n"
		"\n"
		"        Available commands:\n"
		"        cp    src... target_dir   - cp files into filesystem image\n"
		"        mkfs                      - Create new FAT filesystem in image\n"
		"                                    WARNING: This will erase all existing data in image file\n"
		);
	exit(-1);
}

int main(int argc, char **argv)
{
	int  ch;
	char *img_name = NULL;
	while (EOF != (ch = getopt(argc, argv, "qdi:")))
	{
		switch (ch)
		{
		case 'q':
			verbose = 0;
			break;
		case 'd':
			fatfs_tool_debug = 1;
			break;
		case 'i':
			img_name = optarg;
			break;

		default:
			usage();
		}
	}
	argc -= optind;
	argv += optind;

	if (!img_name) /* bail if no image has been specified */
	{
		usage();
	}

	if (!*argv) /* bail if no command has been specified */
	{
		usage();
	}

	/* Set the image filename */
	CHAT("Using disk image file '%s'\n", img_name);
	diskio_img_file_set_filename(img_name);

	/* Mount the filesystem image */
	FRESULT res;
	FATFS fatfs;
	res = f_mount(&fatfs, "DISK_IMG", 0);
	if (res)
	{
		fprintf(stderr, "ERROR: Could not mount FAT filesystem image %s: res:%d\n",
				img_name, res);
		goto out;
	}

	/* run the command that is left on the command line. */
	run_command(argc, argv);


	CHAT("Done.\n");
out:
	diskio_img_file_close();
	return 0;
}
