#include <Arduino.h>
#include <DHT.h> //inclur la library DTH pour le capteur de température DTH22
#include <esp_sleep.h>

#define pinDHT 33   // const pour savoir sur quel pin est brancher le capteur
#define typeDeDHT DHT11          // Définir le type de DTH dans notre cas ------ DHT11

DHT dht(pinDHT, typeDeDHT); // déclaration de la fonction



void setup() 
{

  Serial.begin(9600); 

   // configure deep sleep
  esp_sleep_enable_timer_wakeup(5000); // wake up after 5 seconds
  
  Serial.println("Programme de test du DHT22/DHT11");
  Serial.println("==========================");
  Serial.println();
  

  
  dht.begin(); // Initialisation du DHT22
  delay(500);
  
  Serial.print("Humidité = ");
  Serial.print(dht.readHumidity());
  Serial.println(" %");
  
  Serial.print("Température = ");
  Serial.print(dht.readTemperature());
  Serial.println(" °C");

   // go to sleep
  esp_deep_sleep_start();

}

void loop() 
{
}