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
 * Format of a tab completion entry. Pass an array of these to bdk_readline()
 * to get tab completion of words. Once the first word is completed from "str",
 * the next is pointer is used to find the completions of the next word. This
 * can be NULL if there are no completions available. The list of completions
 * ends with the first item with str==NULL.
 */
typedef struct bdk_readline_tab
{
    const char *str;
    const struct bdk_readline_tab *next;
} bdk_readline_tab_t;

/**
 * Prompt for a line from the user and return it. Full line
 * editing and history are supported.
 *
 * @param prompt     Prompt to show
 * @param tab        Information about tab completion
 * @param timeout_us Return NULL if a line isn't entered in this amount of time. Next
 *                   call will continue the partial line.
 *
 * @return Line that was read. Return is a persistant pointer into the
 *         command history and should not be freed.
 */
extern const char *bdk_readline(const char *prompt, const bdk_readline_tab_t *tab, int timeout_us);

/**
 * Function which checks for keyboard input from the user
 *
 * @param timeout_us Return 0 if no input is entered in this amount of time.
 *                   If timeout_us is 0, program waits for input until it is given.
 *
 * @return Value of character that was entered.  Returns 0 instead on timeout.
 */
extern char bdk_kbhit(int timeout_us);

/** @} */
