/**
 * @file
 *
 * Functions for reading input.
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @addtogroup stdio
 * @{
 */

/**
 * Prompt for a line from the user and return it. Full line
 * editing and history are supported.
 *
 * @param prompt Prompt to show
 *
 * @return Line that was read. Return is a persistant pointer into the
 *         command history and should not be freed.
 */
extern const char *bdk_readline(const char *prompt);

/** @} */
