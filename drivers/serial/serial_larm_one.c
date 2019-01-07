#include <common.h>
#include <errno.h>
#include <asm/io.h>
#include <serial.h>

#include <asm/mach-larm/larm_one.h>

static void larm_putc(const char c) {
	if (c == '\n')
        larm_write32('\r', LARM_UART_REG_RTX);
    larm_write32(c, LARM_UART_REG_RTX);
}

static char larm_getc(void) {
    while(larm_read32(LARM_UART_REG_RX_READY)==0);
    return (char)larm_read32(LARM_UART_REG_RTX);
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
    return larm_read32(LARM_UART_REG_RX_READY);
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
