#
# Wait for the DRAM main menu
#
def wait_for_main_menu(cnx):
    cnx.match("=================================")
    cnx.match("DRAM Menu")
    cnx.match("=================================")
    if cnx.multinode:
        cnx.match("node) Select active node (Currently 0)")
    cnx.match("verbose) Toggle verbose output (Currently OFF)")
    cnx.match("setenv) Set environment variable")
    cnx.match("getenv) Get environment variable")
    cnx.match("showenv) Show environment variables")
    cnx.match("ebb8800) Initialize DRAM using config \"ebb8800\"")
    cnx.match("ebb8804) Initialize DRAM using config \"ebb8804\"")
    cnx.match("cn88xx-crb-1s) Initialize DRAM using config \"cn88xx-crb-1s\"")
    cnx.match("cn88xx-crb-2s) Initialize DRAM using config \"cn88xx-crb-2s\"")
    cnx.match("test) Memory Testing Menu")
    cnx.match("quit) Main menu")
    cnx.match("(INS)Menu choice []:")

#
# Wait for the DRAM test menu
#
def wait_for_test_menu(cnx):
    cnx.match("=================================")
    cnx.match("DRAM Test Menu")
    cnx.match("=================================")
    cnx.match("cores) Bringup Cores for multi-core testing")
    cnx.match("repeat) Number of time to repeat the test (1)")
    cnx.matchRE("start\\) Starting address \\(0x[0-9a-fA-F]*\\)")
    cnx.matchRE("length\\) Length of the range to check \\([^)]*\\)")
    cnx.match("64MB) Set test range from 64MB to 128MB")
    cnx.match("all) Run all DRAM tests")
    cnx.match("test0) Data Bus")
    cnx.match("test1) Address Bus")
    cnx.match("test2) Marching Rows")
    cnx.match("test3) Random Data")
    cnx.match("test4) Random XOR (32 Burst)")
    cnx.match("test5) Self Address")
    cnx.match("test6) March C- Solid Bits")
    cnx.match("test7) March C- Checkerboard")
    cnx.match("test8) Walking Ones Left")
    cnx.match("test9) Walking Ones Right")
    cnx.match("test10) Walking Zeros Left")
    cnx.match("test11) Walking Zeros Right")
    cnx.match("test12) Random XOR (224 Burst)")
    cnx.match("spec) Run special DRAM tests")
    cnx.match("abort) Abort on Errors (Currently ON)")
    cnx.match("quit) Main menu")
    cnx.match("(INS)Menu choice []:")

#
# Wait for a single DRAM test
#
def wait_for_dram_test(cnx, test_name):
    cnx.match("Starting Test \"%s\" for" % test_name)
    cnx.matchRE("\\[0x[0-9a-fA-F]*:0x[0-9a-fA-F]*\\] using [0-9]* core\\(s\\)")
    cnx.waitfor("Node", timeout=600)
    cnx.matchRE("0, LMC0: ops [0-9]*, cycles [0-9]*, used [0-9]*\\.[0-9]\\%")
    try:
        for i in range(7):
            cnx.matchRE("Node [0-1], LMC[0-3]: ops [0-9]*, cycles [0-9]*, used [0-9]*\\.[0-9]\\%", timeout=0.1)
    except:
        pass

#
# Wait for all DRAM tests
#
def wait_for_all_dram_test(cnx):
    tests = []
    tests.append("Data Bus")
    tests.append("Address Bus")
    tests.append("Marching Rows")
    tests.append("Random Data")
    tests.append("Random XOR (32 Burst)")
    tests.append("Self Address")
    tests.append("March C- Solid Bits")
    tests.append("March C- Checkerboard")
    tests.append("Walking Ones Left")
    tests.append("Walking Ones Right")
    tests.append("Walking Zeros Left")
    tests.append("Walking Zeros Right")
    tests.append("Random XOR (224 Burst)")
    for t in tests:
        wait_for_dram_test(cnx, t)

#
# Run all DRAM tests over all of memory
#
def dram_all(cnx):
    cnx.sendEcho("ddr")
    wait_for_main_menu(cnx)
    cnx.sendEcho("test")
    wait_for_test_menu(cnx)
    cnx.sendEcho("cores")
    wait_for_test_menu(cnx)
    cnx.sendEcho("all")
    cnx.match("Pass 1 of 1")
    wait_for_all_dram_test(cnx)
    cnx.match("All tests passed (time ")
    cnx.waitfor(")")
    wait_for_test_menu(cnx)
    cnx.sendEcho("quit")
    wait_for_main_menu(cnx)
    cnx.sendEcho("quit")

#
# Run all DRAM tests over 64MB of memory
#
def dram_short(cnx):
    cnx.sendEcho("ddr")
    wait_for_main_menu(cnx)
    cnx.sendEcho("test")
    wait_for_test_menu(cnx)
    cnx.sendEcho("cores")
    wait_for_test_menu(cnx)
    cnx.sendEcho("64MB")
    wait_for_test_menu(cnx)
    cnx.sendEcho("all")
    cnx.match("Pass 1 of 1")
    wait_for_all_dram_test(cnx)
    cnx.match("All tests passed (time ")
    cnx.waitfor(")")
    wait_for_test_menu(cnx)
    cnx.sendEcho("quit")
    wait_for_main_menu(cnx)
    cnx.sendEcho("quit")

