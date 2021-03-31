#include <Servo.h>
Servo servo1;
Servo servo2;
int pot1=0;
int pot2=0;
#define PotValue1 A0
#define PotValue2 A1
void setup()
{
  servo1.attach(3);
  servo2.attach(5);
  Serial.begin(9600);
}
void loop()
{
  pot1=analogRead(PotValue1);
  pot2=analogRead(PotValue2);
  pot1=map(pot1,0,1023,0,90);
  pot2=map(pot2,0,1023,0,180);
  Serial.println(pot1);
  Serial.println(pot2);
  Serial.println("------");
  servo1.write(pot1);
  servo2.write(pot2);
  delay(10);
}
//Video Linki: https://www.youtube.com/watch?v=0f3VBQ_1XAQ
