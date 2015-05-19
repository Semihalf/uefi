import boards
import connection
import test_boot
import test_dram

def run_test(cnx):
    test_boot.boot_normal(cnx)
    test_dram.dram_short(cnx)

def main(logName):
    console, mcu1, mcu2 = boards.parseArgs()
    log = connection.Log(logName)
    cnx = boards.Board_EVB(console=console, mcu=mcu1, mcu2=mcu2, logObject=log)
    cnx.runTestLoop(run_test)
    cnx.close()

# This script should work with either one or two nodes
main("ebb880x-short-dram.log")
