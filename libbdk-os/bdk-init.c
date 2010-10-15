#include <bdk.h>

void bdk_init(void)
{
    extern int main(int argc, const char *argv);
    main(0, NULL);
    bdk_fatal("main() returned\n");
}
