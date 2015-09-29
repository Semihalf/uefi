import boards
import connection
import test_boot
import test_dram

def run_test(cnx):
    test_boot.boot_normal(cnx)
    test_dram.dram_all(cnx)

def main(logName):
    console, mcu1, mcu2 = boards.parseArgs()
    log = connection.Log(logName)
    cnx = boards.Board_CRB_2S(console=console, bmc=mcu1, logObject=log)
    cnx.runTestLoop(run_test)
    cnx.close()

main("inv-p3e003-two-node-full-dram.log")
