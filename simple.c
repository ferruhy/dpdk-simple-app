#include <stdio.h>
#include <stdlib.h>

#include <rte_eal.h>
#include <rte_common.h>
#include <rte_ethdev.h>

int main(int argc, char *argv[])
{
	int ret;
	uint8_t nb_ports;

	/*
	 * EAL: Environment Abstract Layer"
	 *
	 * eal gets parameters from cli, returns number of parsed args
	 *
	 * cpu_init: fill cpu_info structure
	 * log_init
	 * config_init: create memory configuration in shared memory
	 * pci_init: scan pci bus
	 * memory_init (hugepages)
	 * memzone_init: initialize memzone subsystem
	 * alarm_init: for timer interrupts
	 * timer_init
	 * plugin init
	 * dev_init: initialize and probe virtual devices
	 * intr_init: create an interrupt handler thread
	 * lcore_init: create a thread per lcore
	 * pci_probe: probe all physical devices
	 */
	ret = rte_eal_init(argc, argv);
	if (ret < 0)
		rte_exit(EXIT_FAILURE, "EAL Init failed\n");

	argc -= ret;
	argv += ret;

	/*
	 * Check that there is an even number of ports to
	 * send/receive on.
	 */
	nb_ports = rte_eth_dev_count();
	if (nb_ports < 2 || (nb_ports & 1))
		rte_exit(EXIT_FAILURE, "Invalid port number\n");

	/* There is no un-init for eal */

	return 0;
}
