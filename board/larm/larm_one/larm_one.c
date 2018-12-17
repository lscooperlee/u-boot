
#include <common.h>

DECLARE_GLOBAL_DATA_PTR;

int board_init(void)
{
	return 0;
}

int print_cpuinfo(void)
{
	return 0;
}

int dram_init(void)
{
    gd->ram_size = CONFIG_SYS_INIT_RAM_SIZE;
	return 0;
}
