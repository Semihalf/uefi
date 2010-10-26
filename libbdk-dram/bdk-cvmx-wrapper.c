#include <bdk.h>

int cvmx_twsix_read_ia(int twsi_id, uint8_t dev_addr, uint16_t internal_addr, int num_bytes, int ia_width_bytes, uint64_t *data)
{
    return bdk_twsix_read_ia(twsi_id, dev_addr, internal_addr, num_bytes, ia_width_bytes, data);
}

uint64_t cvmx_clock_get_rate(bdk_clock_t clock)
{
    return bdk_clock_get_rate(clock);
}

void octeon_delay_cycles(uint64_t cycles)
{
    bdk_wait(cycles);
}

int cvmx_l2c_get_num_assoc(void)
{
    return bdk_l2c_get_num_assoc();
}

int cvmx_l2c_set_core_way_partition(uint32_t core, uint32_t mask)
{
    return bdk_l2c_set_core_way_partition(core, mask);
}

int cvmx_l2c_set_hw_way_partition(uint32_t mask)
{
    return bdk_l2c_set_hw_way_partition(mask);
}

void exit(int status)
{
    bdk_reset_octeon();
    while (1) {}
}
