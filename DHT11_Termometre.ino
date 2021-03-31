#include <dht11.h>
int DHT_PIN = 2;
dht11 dht_sensor;
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  delay(1000)
  int test = dht_sensor.read(DHT_PIN);
  Serial.print("Nem Oranı (%): ");
  Serial.println((float)dht_sensor.humidity,2);

  Serial.print("Sıcaklık (Celcius): ");
  Serial.println((float)dht_sensor.temperature,2);

  Serial.print("Sıcaklık (Kelvin): ");
  Serial.println((float)dht_sensor.kelvin,2);

  Serial.print("Sıcaklık (Fahrenheit): ");
  Serial.println((float)dht_sensor.fahrenheit);
  //Video Linki: https://www.youtube.com/watch?v=0Onqd_VhCBY
}
