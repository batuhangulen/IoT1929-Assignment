#include <MFRC522.h>//RFID Kapı kilit sisteminin kütüphanesi
#include <SPI.h>//Çevresel birimlerle iletişime geçmek için gerekli kütüphane
#define LED_PIN_1 5//Birinci ledimizin 5 numaralı pinde olduğunu belirttik.
#define LED_PIN_2 6//İkinci ledimizin 6 numaralı pinde olduğunu belirttik.
#define RST 9
#define SS 10 //RFID Modülündeki pinleri belirtiyoruz.
MFRC522 rfid(SS, RST);//MFRC Modülünü başlattık.
byte KartID [4] = {159, 24, 125, 224};//Geçici olarak modül ID mizi belirttik.
void setup()
{
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  Serial.begin(9600);//9600 BR olarak seri ekranımızı başlattık.
  SPI.begin;//SPI haberleşmesini başlattık.
  rfid.PCD_Init();//RFID Modülünü başlattık.
}
void loop()
{
  if(!rfid.PICC_IsNewCardPresent())//Eğer RFID modülü yeni bir kart okursa...
  {
    return;
  }
  if(!rfid.PICC_ReadCardSerial())//Eğer RFID modülü kart okursa...
  {
    return;
  }
  if(rfid.uid.uidByte[0] == KartID[0] &&
  rfid.uid.uidByte[1] == KartID[1] &&
  rfid.uid.uidByte[2] == KartID[2] &&
  rfid.uid.uidByte[3] == KartID[3])//Okunan Kart ID'si doğru mu diye kontrol ediliyor.
  {
    Serial.println("Kapı Açıldı");
    digitalWrite(LED_PIN_1, HIGH);
    KartIDYazdir();//Birazdan yazacağımız fonksiyon
  }
  else
  {
    Serial.println("Kart Geçersiz");
    digitalWrite(LED_PIN_2, HIGH);
    KartIDYazdir();
  }
  rfid.PICC_HaltA();
}
void KartIDYazdir()
{
  Serial.print("Kart ID Numarası: ");
  for(int i;i<4;i++)
  {
    Serial.print(rfid.uid.uidByte[i]);
    Serial.print(" ");
  } 
  Serial.println("");
}
//Video Linki: https://www.youtube.com/watch?v=jhRcAimLlBs
