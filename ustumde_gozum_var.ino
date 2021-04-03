#include <NewPing.h>
const int trig=12;
const int echo=8;
const int buzzer=13;
const int MAX_Uzaklik=50;
NewPing uzaklik(trig, echo, MAX_Uzaklik);
float duration, mesafe;
void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  mesafe=uzaklik.ping_cm();
  mesafe=mesafe-3;
  Serial.print("Uzaklık: ");
  Serial.print(mesafe);
  Serial.println(" Cm");
  Serial.println("----------------");

  if(mesafe<=50 && mesafe>=20)
  {
    digitalWrite(buzzer, HIGH);
    delay(2000);
    digitalWrite(buzzer, LOW);
    delay(10000);
  }
}
