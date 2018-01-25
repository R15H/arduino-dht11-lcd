#include <SimpleDHT.h>

// ajay@malhotra.ca
// simple sensor for Rishi Room
#include <SimpleDHT.h>
#include <LiquidCrystal.h>

// Define Pins for LEDs
#define RED 4
#define YELLOW 5
#define GREEN 6

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
/*
    The circuit:
   LCD RS pin to digital pin 7
   LCD Enable pin to digital pin 8
   LCD D4 pin to digital pin 9
   LCD D5 pin to digital pin 10
   LCD D6 pin to digital pin 11
   LCD D7 pin to digital pin 12
   LCD R/W pin to ground
   LCD VSS pin to ground
   LCD VCC pin to 5V
   10K resistor:
   ends to +5V and ground
   wiper to LCD VO pin (pin 3)
*/
int pinDHT11 = 13;
SimpleDHT11 dht11;


void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Rishi Room Temp & Humidity Sensor!");
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(YELLOW, HIGH);
}

void loop() {
  byte temperature = 0;
  byte humidity = 0;
  byte data[40] = {0};
  Serial.println("Sample DHT11...");
  if (dht11.read(pinDHT11, &temperature, &humidity, data)) {
    Serial.print("Read DHT11 failed");
    return;
  }

  Serial.print((int)temperature); Serial.print(" *C, ");
  Serial.print((float)temperature*1.8+32); Serial.print(" *F, ");
  Serial.print((int)humidity); Serial.println(" %");

  lcd.clear();

  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  lcd.print("Temp.: ");
  lcd.setCursor(7, 0);
  lcd.print((float)temperature*1.8+32);
  lcd.setCursor(13, 0);
  lcd.print((char)223);
  lcd.setCursor(14, 0);
  lcd.print("F");

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.setCursor(10, 1);
  lcd.print((int)humidity);
  lcd.setCursor(12, 1);
  lcd.print(" %");
  // DHT11 sampling rate is 1HZ.

  if ((30 < humidity) && (humidity < 50) && (20 < temperature) && (temperature < 25)) {
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, HIGH);
  }
  else {
    if ( ((20 < humidity) && (humidity < 70)) && ((18 < temperature) && (temperature < 30)) ) {
      digitalWrite(RED, HIGH);
      digitalWrite(GREEN, HIGH);
      digitalWrite(YELLOW, LOW);
    }
    else {
      digitalWrite(RED, LOW);
      digitalWrite(GREEN, HIGH);
      digitalWrite(YELLOW, HIGH);
    }
  }

  delay(1000);

}
