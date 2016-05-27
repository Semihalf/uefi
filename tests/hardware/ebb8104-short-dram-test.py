import boards
import connection
import test_boot
import test_dram

def run_test(cnx):
    # First run from a cold power on
    test_boot.boot_normal(cnx) # Does a power cycle
    test_dram.dram_short(cnx)
    # Second run from a warm reset on twice. After a power cycle, the first
    # warm reset might be a little different than the second. Do two to make
    # sure both combinations are tested
    for reset in [0,1]:
        cnx.sendEcho("rbt")
        test_boot.boot_normal(cnx, powerCycle=False) # Skip power cycle
        test_dram.dram_short(cnx)

def main(logName):
    console, mcu1, mcu2 = boards.parseArgs()
    log = connection.Log(logName)
    cnx = boards.Board_EVB(console=console, mcu=mcu1, mcu2=mcu2, logObject=log)
    cnx.runTestLoop(run_test)
    cnx.close()

main("ebb8104-short-dram.log")
