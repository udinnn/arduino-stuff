#include <dht.h>

dht DHT;

#define DHT11_PIN 7 // colok digital pin 7 ke dht
#define RELAY  6 // colok digital pin 6 ke relay

void setup(){
  Serial.begin(9600);
  pinMode(RELAY, OUTPUT);
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  float suhu = DHT.temperature;
  float lembab = DHT.humidity;
  Serial.print("Temperatur = ");
  Serial.println(suhu);
  Serial.print("Kelembaban = ");
  Serial.println(lembab);
  delay(1000);

  if (suhu < 30.00){
    digitalWrite(RELAY,LOW);  // heater nyala
   }
   else if(suhu >= 30.00){
    digitalWrite(RELAY,HIGH); // heater mati
   }
}
