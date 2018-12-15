
#include <asm/mach-types.h>
#include <asm/global_data.h>
#include <common.h>

DECLARE_GLOBAL_DATA_PTR;

int board_init(void)
{
    gd->bd->bi_arch_number = MACH_TYPE_LARM_ONE;
    gd->bd->bi_boot_params = CONFIG_BOOT_PARAMS_ADDR;
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
