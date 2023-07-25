import serial.tools.list_ports

ports = serial.tools.list_ports.comports()
serialInst = serial.Serial()

portVar = "COM3"  # storing the port in a variable {in my machine there is only one port}
serialInst.baudrate = 9600  # setting the baud-rate such that the value matches with that in the arduino
serialInst.port = portVar  # setting the port value
serialInst.open()  # taking input from port:COM3 @baud-rate 9600


def heart_rate_sensor():
    while True:  # while receiving the value
        if serialInst.in_waiting:
            packet = serialInst.readline()  # reads the encoded packet
            decoded_packet = packet.decode('utf')  # decodes using utf  {unicode transformation format}
            return decoded_packet

