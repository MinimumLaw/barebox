/*
 */

#include <debug_ll.h>
#include <common.h>
#include <mach/esdctl.h>
#include <mach/generic.h>
#include <mach/imx6.h>
#include <mach/xload.h>
#include <mach/iomux-mx6.h>
#include <asm/barebox-arm.h>

extern char __dtb_imx6qp_ravion_ravion200_start[];

static inline void setup_uart(void)
{
	void __iomem *iomuxbase = IOMEM(MX6_IOMUXC_BASE_ADDR);

	imx_setup_pad(iomuxbase, MX6Q_PAD_CSI0_DAT10__UART1_TXD);
	imx6_uart_setup_ll();
}

ENTRY_FUNCTION(start_ravion200, r0, r1, r2)
{
	imx6_cpu_lowlevel_init();

	if (IS_ENABLED(CONFIG_DEBUG_LL)) {
		setup_uart();
	};
	
	/*
	 * When still running in SRAM, we need to setup the DRAM now and load
	 * the remaining image.
	 */
	if (get_pc() < MX6_MMDC_PORT01_BASE_ADDR) {
		/* OCRAM area 0x00900000...0x0093FFFF - 256KiB,
		 * setup stack from middle to top of OCRAM area */
		arm_setup_stack(0x00920000 - 8);
		relocate_to_current_adr();
		setup_c();
	}

	imx6q_barebox_entry(__dtb_imx6qp_ravion_ravion200_start
		+ get_runtime_offset());
}
