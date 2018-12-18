#include <common.h>
#include <errno.h>
#include <asm/io.h>
#include <serial.h>

#define UFCON0	((volatile unsigned int *)(0xFF000000))
#define UFCON1	((volatile unsigned int *)(0xFF000004))
#define UFCON2	((volatile unsigned int *)(0xFF000008))
#define UFCON3	((volatile unsigned int *)(0xFF00000c))
#define UFCON4	((volatile unsigned int *)(0xFF000010))

static void larm_putc(const char c) {
	if (c == '\n')
        *UFCON0='\r';
    *UFCON0=c;
}

static void larm_puts(const char *s) {
    while(*s)
        larm_putc(*s++);
}

static char larm_getc(void) {
    while(*UFCON2==0);
    return *UFCON0;      
}

DECLARE_GLOBAL_DATA_PTR;

int larm_one_serial_init(void)
{
	return 0;
}

static void larm_one_serial_putc(const char c)
{
    larm_putc(c);
}

static int larm_one_serial_getc(void)
{
    return larm_getc();
}

static int larm_one_serial_tstc(void)
{
    return *UFCON2;
}

static void larm_one_serial_setbrg(void)
{
}

static struct serial_device larm_one_serial_drv = {
	.name	= "larm_one_serial",
	.start	= larm_one_serial_init,
	.stop	= NULL,
	.setbrg	= larm_one_serial_setbrg,
	.putc	= larm_one_serial_putc,
	.puts	= default_serial_puts,
	.getc	= larm_one_serial_getc,
	.tstc	= larm_one_serial_tstc,
};

void larm_one_serial_initialize(void)
{
	serial_register(&larm_one_serial_drv);
}

__weak struct serial_device *default_serial_console(void)
{
	return &larm_one_serial_drv;
}
