#include <bdk.h>

int cvmx_twsix_read_ia(int twsi_id, uint8_t dev_addr, uint16_t internal_addr, int num_bytes, int ia_width_bytes, uint64_t *data)
{
    int64_t result = bdk_twsix_read_ia(twsi_id, dev_addr, internal_addr, num_bytes, ia_width_bytes);
    if (result == -1)
        return -1;
    *data = result;
    return num_bytes;
}

uint64_t cvmx_clock_get_rate(int clock)
{
    switch (clock)
    {
        case 0: // CVMX_CLOCK_RCLK
            return bdk_clock_get_rate(BDK_CLOCK_RCLK);
        case 1: // CVMX_CLOCK_SCLK
            return bdk_clock_get_rate(BDK_CLOCK_SCLK);
        case 2: // CVMX_CLOCK_DDR
            return 0;
        case 3: // CVMX_CLOCK_CORE
            return bdk_clock_get_rate(BDK_CLOCK_CORE);
        case 4: // CVMX_CLOCK_TIM
            return bdk_clock_get_rate(BDK_CLOCK_TIM);
        case 5: // CVMX_CLOCK_IPD
            return bdk_clock_get_rate(BDK_CLOCK_IPD);
    }
    return 0;
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

int bdk_is_model_wrapper(unsigned int arg_model)
{
    return OCTEON_IS_MODEL(arg_model);
}
