#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <dht.h>

#define DHTPIN 8
#define DHTTYPE DHT11
#define RELAY 6 // colok digital pin 6 ke relay


dht DHT;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  Serial.println("System start.\n\n");
  pinMode(RELAY, OUTPUT);
  lcd.begin(); 
  lcd.backlight();
}

void loop() {
  int chk = DHT.read11(DHTPIN), humi = DHT.humidity, tempC = DHT.temperature;

  lcd.clear();
  lcd.setCursor(0, 0); // Set keluaran kelembaban di baris 1 LCD
  lcd.print("Kelembaban = ");
  lcd.print(humi);
  lcd.print("%");

  lcd.setCursor(0, 1); // Set keluaran suhu di baris 2 LCD
  lcd.print("Suhu = ");
  lcd.print(tempC);
  lcd.write(223);
  lcd.print("C");

  if (tempC >= 30.00){
    digitalWrite(RELAY,LOW);  // relay nyala
   }
  else if(tempC < 30.00){
    digitalWrite(RELAY,HIGH); // relay mati
   }

  delay(1000); 
}
