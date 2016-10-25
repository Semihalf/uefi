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
int thunder_get_ecam_offset(const char *prop);
int thunder_get_next_offset(int offset);
const char *thunder_get_prop_name(int offset);
const char *thunder_get_prop_value(int offset);
int dts_get_num_from_str(const char *str);
int dts_get_substr_index(const char *str, char *substr, char sep);

extern board_fdt_t bfdt;
#endif
