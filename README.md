# Temparatur-Monitor-outside
A Temp. Monitor for boats to measure outside- and inside Temp and humidity

Required hardware: Arduino mini, LCD Display 4 x 20 with I2C-adapter FC113, DHT22 Sensor, DS1820B, 12 to 5V DC-DC adapter

The address of the DS1820B has to be identified and inserted into the sketch prior programming.
The threshold of the dimming can be adapted by changing the value "if(analogRead(3)>= 200)	//threshold"
The min brightness is defined by the value "  analogWrite(LCDPin, 10);  // dimmed brightness"
