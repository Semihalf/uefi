import sys
import boards
import connection
import test_boot
import test_dram

USE_WATCHDOG = False

def main(log):
    console, mcu1, mcu2 = boards.parseArgs()
    count = 0
    pass_count = 0
    fail_count = 0
    cnx = boards.Board_CRB_2S(console=console, bmc=mcu1, logObject=log)
    while True:
        count += 1
        print "Loop %d: Pass %d, Fail %d" % (count, pass_count, fail_count)
        try:
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
            pass_count += 1
        except (KeyboardInterrupt, SystemExit):
            raise
        except:
            fail_count += 1
            try:
                cnx.waitfor("JUNK", timeout=1)
            except:
                pass
            cnx.log("FAIL: Exception: %s %s %s" % sys.exc_info())
        cnx.log("After loop %d: Pass %d, Fail %d" % (count, pass_count, fail_count))
    cnx.close()

log = connection.Log("crb-2s-two-node-full-dram.log")
main(log)
