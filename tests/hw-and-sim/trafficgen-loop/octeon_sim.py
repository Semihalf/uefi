import os
import sys
import subprocess
import socket
import time

def set_chip(chip):
    os.environ["SIM"] = chip

def get_chip():
    return os.getenv("SIM", "cn78xx")

class Simulator:
    def __init__(self, sim_log, sim_args):
        sim_binary = "%s-simulator64" % get_chip()
        sim_args.insert(0, sim_binary)
        log = open(sim_log, "w")
        port = 30000 + (os.getpid() & 0xff)
        sim_args.append("-uart0=%d" % port)
        print "[INFO]Starting simulator: ", sim_args
        self.sim = subprocess.Popen(sim_args, stdin=None, stdout=log, stderr=subprocess.STDOUT)
        assert(self.sim)
        time.sleep(0.1)
        print "[INFO]Connecting to uart socket"
        self.sock = socket.create_connection(("localhost", port))
        assert(self.sock)
        print "[INFO]Simulator running"
    def send(self, input_str):
        print "\n[INFO]Sending \"%s\"" % input_str.replace("\r", "\\r")
        self.sock.send(input_str)
    def waitFor(self, wait_str):
        print "\n[INFO]Waiting for \"%s\"" % wait_str
        buffer = ""
        while True:
            data = self.sock.recv(1)
            assert(data)
            sys.stdout.write(data)
            sys.stdout.flush()
            buffer += data
            buffer = buffer[-200:]
            if buffer.endswith(wait_str):
                break;
        pass
    def waitDie(self):
        print "\n[INFO]Waiting for simulator to complete"
        while True:
            data = self.sock.recv(1)
            if not data:
                break
            sys.stdout.write(data)
            sys.stdout.flush()
        self.sim.kill()
        print "\n[INFO]Simulator done"

