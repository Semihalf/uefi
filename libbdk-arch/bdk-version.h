
/**
 * @file
 *
 * Functions for identifying BDK build version.
 *
 * <hr>$Revision$<hr>
 */


extern const char bdk_version_str[];

/**
 * Return BDK version string
 *
 * @return BDK version string
 */
static inline const char *bdk_version_string(void)
{
	return bdk_version_str;
}
