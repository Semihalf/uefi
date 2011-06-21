import tools

def test(child):
    child.sendline("ilua")
    child.expect("ILUA")
    child.expect(">")
    child.sendline("3*5")
    child.expect("15")
    child.expect(">")
    child.sendline("pprint(octeon)")
    child.expect("CN63XX")
    child.expect("CONFIG_FPA_POOL_SIZE7")
    child.expect("bdk_board_table_entry")
    child.expect("c = {")
    child.expect("is_model = ")
    child.expect("trafficgen = {")
    child.expect(">")
    child.sendline("quit")

tools.add_test(test, "iLua")
