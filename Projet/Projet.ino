/*
  * @File  : DFRobot_TFmini_test.ino
  * @Brief : This example use TFmini to measure distance
  *         With initialization completed, we can get distance value and signal strength
  * @Copyright   [DFRobot](https://www.dfrobot.com), 2016
  *             GNU Lesser General Public License
  *
  * @version  V1.0
  * @date  2018-1-10
*/
#include <Wire.h>
#include <DFRobot_RGBLCD.h>
#include <DFRobot_TFmini.h>            //TF Mini header file

SoftwareSerial mySerial(12, 13);      // RX, TX
DFRobot_TFmini  TFmini;
uint16_t distance,strength;

unsigned int lcd_r = 0, lcd_g = 0, lcd_b = 0;
unsigned long delaytime = 0, lighttime = 0;
DFRobot_RGBLCD lcd(16, 2);
void setup()
{lcd.init();
  delay(5000);
  Serial.begin(115200);
  Serial.println("hello start");

  TFmini.begin(mySerial);
  lighttime = millis();
  lcd.setCursor(0, 0);
  lcd.print("Dis:");
  lcd.setCursor(0, 1);
  lcd.print("Str:");
  lcd.setRGB(255, 255, 000);
}
void loop() {

/******************LCD*******************/
 lcd_r = random(256);
  delayMicroseconds(10);
  lcd_g = random(256);
  delayMicroseconds(10);
  lcd_b = random(256);
  if (millis() - lighttime > 3000)
  {
    lcd.setRGB(lcd_r, lcd_g, lcd_b);
    lighttime = millis();
  }
  //delay(100);
  /**************TF Mini***************/
 if(TFmini.measure()){                          //Measure Distance and get signal strength
        distance = TFmini.getDistance();       //Get distance data
        strength = TFmini.getStrength();       //Get signal strength data

    lcd.setCursor(5, 0);                       //LCD display
    lcd.print(  distance / 10000);
    lcd.print(  distance/ 1000 % 10);
    lcd.print('.');
    lcd.print(  distance / 100 % 10);
    lcd.print(  distance / 10 % 10);
    lcd.print(  distance  % 10);
    lcd.print(" m");
    lcd.setCursor(5, 1);
    lcd.print(strength / 10000);
    lcd.print(strength / 1000 % 10);
    lcd.print(strength / 100 % 10);
    lcd.print(strength / 10 % 10);
    lcd.print(strength % 10);
    }
}
