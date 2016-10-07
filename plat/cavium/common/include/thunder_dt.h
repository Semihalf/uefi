#ifndef _THUNDER_DT_H_
#define _THUNDER_DT_H_

typedef struct board_fdt {
	char board_model[64];
	int bmc_boot_twsi_node;
	int bmc_boot_twsi_bus;
	int bmc_boot_twsi_addr;
	int bmc_ipmi_twsi_node;
	int bmc_ipmi_twsi_bus;
	int bmc_ipmi_twsi_addr;
	int gpio_shutdown_ctl_in;
	int gpio_shutdown_ctl_out;
} board_fdt_t;

int thunder_fill_board_details(int info);
uint64_t thunder_get_ecam_config_addr(int node, int ecam);
uint64_t thunder_get_ecam_config_size(int node, int ecam);

extern board_fdt_t bfdt;
#endif
