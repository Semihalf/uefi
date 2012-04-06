import re
import os
import socket
import connection

#
# Create a TCP network connection to a remote object. The connect_string
# is of the format "host:port". The "host" field can be a name or numeric
# IP address. The ":port" is optional and defaults to 23.
#
def NetworkConnection(connection, connect_string):
    assert not "/" in connect_string, "Invalid network connection string"
    match = re.match("^([^:]+)(:[0-9]+)?$", connect_string)
    assert match, "Invalid network connection string"
    connection.host = match.group(1)
    port_str = match.group(2)
    connection.port = 23
    if port_str:
        connection.port = int(port_str[1:])
        assert (connection.port > 0) and (connection.port < 65536), "Invalid port"
    connection.sock = socket.create_connection((connection.host, connection.port))
    connection.fileno = connection.sock.fileno()

