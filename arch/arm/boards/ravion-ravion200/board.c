/*
 */

#include <debug_ll.h>
#include <common.h>
#include <envfs.h>
#include <gpio.h>
#include <init.h>
#include <mach/imx6.h>
#include <net.h>
#include <linux/nvmem-consumer.h>


static int ravion200_late_init(void)
{
	if (!of_machine_is_compatible("ravion,imx6qp-ravion200"))
		return 0;

	/*
	 * ToDo: late init code placed here
	 */

	return 0;
}
/*
 * When this function is called "hog" pingroup in device tree needs to
 * be already initialized
 */
late_initcall(ravion200_late_init);

static int ravion200_devices_init(void)
{
	if (!of_machine_is_compatible("ravion,imx6qp-ravion200"))
		return 0;

	barebox_set_hostname("ravion200");

	/*
	 * ToDo: machine init code placed here
	 */

	return 0;
}
device_initcall(ravion200_devices_init);
