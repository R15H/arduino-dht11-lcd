# arduino-dht11-lcd
Arduino Temperature and Humidity sensor with LCD display and LED lights for status

## Basic working of this project
Input comes from DHT11
Arduino system processes Input
Display happens on LCD in F for Temperature and % for Humidity
LED's are configured the following way:
If 30 < humidity < 50 && 20C < Temperature < 25C ;  then green, else
If 20 < humidity < 70 && 18C < Temperature < 30C ;  then yellow, else Red
