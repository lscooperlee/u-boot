#ifndef __LARM_ONE_CONFIG_H__
#define __LARM_ONE_CONFIG_H__

#define CONFIG_ENV_SIZE                     0x8000
#define CONFIG_SYS_SDRAM_BASE               0
#define CONFIG_SYS_LOAD_ADDR                (CONFIG_SYS_SDRAM_BASE + 4 * 1024 * 1024)
#define CONFIG_SYS_MALLOC_LEN               1 * 1024 * 1024

#define CONFIG_SYS_INIT_RAM_SIZE            8 * 1024 * 1024
#define CONFIG_SYS_INIT_SP_ADDR             (CONFIG_SYS_SDRAM_BASE + (CONFIG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE))

#endif
