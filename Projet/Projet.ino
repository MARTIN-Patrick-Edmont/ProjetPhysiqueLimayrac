//COMPILLER AVEC LE OLD BOLODER

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

#include <DFRobot_TFmini.h>            //TF Mini header file

SoftwareSerial mySerial(12, 13);      // RX, TX
DFRobot_TFmini  TFmini;
uint16_t distance,strength;



void setup()
{
  delay(5000);
  Serial.begin(115200);
  Serial.println("hello start");

  TFmini.begin(mySerial);


  
  
}
void loop() {

Serial.println("a");

  
  /**************TF Mini***************/
 //if(TFmini.measure())
 {                          //Measure Distance and get signal strength
        distance = TFmini.getDistance();       //Get distance data
        strength = TFmini.getStrength();       //Get signal strength data
        Serial.println(distance);
        Serial.println(" :: ");
        Serial.println(strength);
        Serial.println("\n");
        Serial.println("b");
        delay(100);
    }
    delay(1000);
}
