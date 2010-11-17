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
 * @param prompt     Prompt to show
 * @param timeout_us Return NULL if a line isn't entered in this amount of time. Next
 *                   call will continue the partial line.
 *
 * @return Line that was read. Return is a persistant pointer into the
 *         command history and should not be freed.
 */
extern const char *bdk_readline(const char *prompt, int timeout_us);

/** @} */
