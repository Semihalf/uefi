import boards
import connection
import test_boot
import test_dram

def main(log):
    console, mcu1, mcu2 = boards.parseArgs()
    count = 0
    cnx = boards.Board_CRB_2S(console=console, serialbox=mcu1, logObject=log)
    while True:
        count += 1
        print "Loop %d" % count

        cnx.powerCycle()
        cnx.waitfor("Verifying image", timeout=300)
        cnx.match("Putting all cores except this one in reset")
        cnx.match("Jumping to image at")
        cnx.waitfor("---")
        test_boot.wait_for_bdk_boot(cnx)
        test_boot.wait_for_main_menu(cnx)
        test_dram.dram_all(cnx)
    cnx.close()

log = connection.Log("crb-2s-two-node-full-dram.log")
main(log)
