"""
   ### PC Part of the Project ###

This is a simple code to send and receive data via serial port to an
Arduino.
It could be used to capture/process data from a sensor or other data
sended from the Arduino.
This code could be changed to better attend a certain project.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
"""

import time
import serial

ser = serial.Serial('/dev/ttyUSB0', 9600) # Basic serial config. Check your serial port!

while True:
    ch = input("Enter the data you want to receive 'a' or 'b': ")
    ser.write(bytes(ch, 'ascii')) # Sends the option via serial. 
    data_in = 0
    
    while isinstance(data_in, int): # When receives a number from the Arduino, stays in this loop (the last thing received is going to be a char)
        while ser.in_waiting: # Return the number of bytes in the receiver buffer, that means, if is not zero, there is data arriving.
            data_in = ser.readline() # Read from serial. The in type is 'bytes'.
            try:
                data_in = int(data_in) # Try to convert bytes to int. If receives a char, ERROR.
                print(data_in)
            except ValueError: # When the data received cannot be converted to int, finishes the processing.
                break
        
        
