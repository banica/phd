//#include <Wire.h> 
//#include <LiquidCrystal_I2C.h>

#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

//LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_PCF8574 lcd(0x27);  // set the LCD address to 0x27 for a 16 chars and 2 line display

//int contor = 0;

void setup()
{
  Serial.begin(9600);
  // LCD
  Serial.println("LCD...");
  Wire.begin();
  Wire.beginTransmission(0x27);
  Serial.println("Check for LCD");
  int error = Wire.endTransmission();
  Serial.print("Error: ");
  Serial.print(error);
  if (error == 0) {
    Serial.println(": LCD found.");
    lcd.begin(16, 2); // initialize the lcd
    lcd.setBacklight(255);
    lcd.home(); 
    lcd.clear();
    lcd.print("Hello LCD");
    delay(1000);
  } else {
    Serial.println(": LCD not found.");
  } // if else
}


void loop()
{
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println(voltage);
  lcd.clear();
  lcd.setCursor(4,0);  //coloana - linie
  lcd.print("Voltmetru");
  lcd.setCursor(5,1);  //coloana - linie
  lcd.print(voltage);
  lcd.setCursor(10,1);  //coloana - linie
  lcd.print(" V");

  delay(100);
}
