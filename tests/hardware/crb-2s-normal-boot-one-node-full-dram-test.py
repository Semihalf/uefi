import boards
import connection
import test_boot
import test_dram

def main(log):
    console, mcu1, mcu2 = boards.parseArgs()
    count = 0
    cnx = boards.Board_CRB_2S(console=console, bmc=mcu1, logObject=log)
    cnx.multinode = False # Override the default
    while True:
        count += 1
        print "Loop %d" % count
        test_boot.boot_normal(cnx)
        test_dram.dram_all(cnx)
    cnx.close()

log = connection.Log("crb-2s-one-node-full-dram.log")
main(log)
