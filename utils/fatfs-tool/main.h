#ifndef _MAIN_H_
#define _MAIN_H_

extern int verbose;
#define CHAT(args...) do { if (verbose) printf(args); } while (0)

#endif /* _MAIN_H_ */
