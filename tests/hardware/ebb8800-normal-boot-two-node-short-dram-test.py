import boards
import connection
import test_boot
import test_dram

def main(log):
    console, mcu1, mcu2 = boards.parseArgs()
    count = 0
    cnx = boards.Board_EVB(console=console, mcu=mcu1, mcu2=mcu2, logObject=log)
    while True:
        count += 1
        print "Loop %d" % count
        test_boot.boot_normal(cnx)
        test_dram.dram_short(cnx)
    cnx.close()

log = connection.Log("ebb8800-two-node-short-dram.log")
main(log)
