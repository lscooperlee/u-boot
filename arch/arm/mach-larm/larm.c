#include <common.h>

__attribute__((noreturn)) void reset_cpu(ulong addr __attribute__((unused)))
{
    asm("mov pc, #0");
    while(1); // for noreturn warning
}
