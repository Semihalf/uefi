
static inline void dram_csr_write(bdk_node_t node, const char *csr_name, bdk_csr_type_t type, int busnum, int size, uint64_t address, uint64_t value)
{
    if (dram_is_verbose())
        dram_printf("DDR Config %s[%016lx] => %016lx\n", csr_name, address, value);
    bdk_csr_write(node, type, busnum, size, address, value);
}

/**
 * Macro to write a CSR, logging if necessary
 */
#define DRAM_CSR_WRITE(node, csr, value) \
    dram_csr_write(node, basename_##csr, bustype_##csr, busnum_##csr, sizeof(typedef_##csr), csr, value)

/**
 * Macro to make a read, modify, and write sequence easy. The "code_block"
 * should be replaced with a C code block or a comma separated list of
 * "name.s.field = value", without the quotes.
 */
#define DRAM_CSR_MODIFY(name, node, csr, code_block) do { \
        typedef_##csr name = {.u = bdk_csr_read(node, bustype_##csr, busnum_##csr, sizeof(typedef_##csr), csr)}; \
        code_block; \
        dram_csr_write(node, basename_##csr, bustype_##csr, busnum_##csr, sizeof(typedef_##csr), csr, name.u); \
    } while (0)

