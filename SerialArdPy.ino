/* ### Arduino Part of the Project ###
 *  
 * This is a simple example code to send and receive data via serial port.
 * It could be used to send data captured from a sensor (or other data
 * processed on the Arduino) to a PC program for further processing.
 * This code could be changed to better attend a certain project. 
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 */

void setup()
{
  // Initialize the serial communication:
  Serial.begin(9600);
}

void loop()
{
  int dataA[10] = {1024, 512, 256, 128, 64, 32, 16, 8, 4, 2}, dataB = 1100; // Data to send
  char serCH;
  
  if (Serial.available()) // Check if data has been sent from the computer.
  {
    serCH = Serial.read(); // Receive a char.
    
    if(serCH == 'a') // First option, send the array A a few times.
    {
      for (char j = 0; j < 5; j++)
      {
        for(char i = 0; i < 10; i++)
        {
          Serial.println(dataA[i]);
          delay(100);
        }
        delay(2000);
      }
    }
    
    else if(serCH == 'b') // Second option, send the number B.
    {
      Serial.println(dataB); 
    }
    
    else
    {
      Serial.println(0);
    }
    
    Serial.println('E'); // End communication alert. Sends a letter to finish.
    
  }
}
