import boards
import connection
import test_boot
import test_dram

USE_WATCHDOG = False

def run_test(cnx):
    if USE_WATCHDOG:
        cnx.powerCycle()
        cnx.waitfor("Verifying image", timeout=300)
        cnx.match("Putting all cores except this one in reset")
        cnx.match("Jumping to image at")
        cnx.waitfor("---")
        test_boot.wait_for_bdk_boot(cnx)
        test_boot.wait_for_main_menu(cnx)
    else:
        test_boot.boot_normal(cnx)
    test_dram.dram_all(cnx)

def main(logName):
    console, mcu1, mcu2 = boards.parseArgs()
    log = connection.Log(logName)
    cnx = boards.Board_CRB_2S(console=console, bmc=mcu1, logObject=log)
    cnx.runTestLoop(run_test)
    cnx.close()

main("crb-2s-two-node-full-dram.log")
