// Demo code for Grove - Temperature Sensor V1.1/1.2
// Loovee @ 2015-8-26
 
#include <math.h>

#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

int colorR =255;
int colorG = 0;
int colorB = 140;
 
const int B = 4275;               // B value of the thermistor
const int R0 = 100000;            // R0 = 100k
const int pinTempSensor = A0;     // Grove - Temperature Sensor connect to A0
 
#if defined(ARDUINO_ARCH_AVR)
#define debug  Serial
#elif defined(ARDUINO_ARCH_SAMD) ||  defined(ARDUINO_ARCH_SAM)
#define debug  SerialUSB
#else
#define debug  Serial
#endif
 
void setup()
{
    Serial.begin(9600);
    lcd.begin(16, 2);

    lcd.setRGB(colorR, colorG, colorB);

    // Print a message to the LCD.
    lcd.print("Tempo!");
    delay(1000);
}
 
void loop()
{
  lcd.setRGB(colorR, colorG, colorB);
    int a = analogRead(pinTempSensor);
 
    float R = 1023.0/a-1.0;
    R = R0*R;
 
    float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15; // convert to temperature via datasheet
 
 lcd.setCursor(0, 1);
    Serial.print("temperature = ");
    Serial.println(temperature);
    lcd.print(temperature);
    lcd.print("C");
    colorR = temperature * (145.00/30.00);
    delay(1000);
}
