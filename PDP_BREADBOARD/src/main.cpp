#include <DHT.h> //inclur la library DTH pour le capteur de température DTH22

#define pinDHT 33   // const pour savoir sur quel pin est brancher le capteur
#define typeDeDHT DHT11          // Définir le type de DTH dans notre cas ------ DTH22

DHT dht(pinDHT, typeDeDHT); // déclaration de la fonction



void setup() 
{

  Serial.begin(115200); 
  Serial.println("Programme de test du DHT22/DHT11");
  Serial.println("==========================");
  Serial.println();

  
  dht.begin(); // Initialisation du DHT22

}

void loop() 
{


  float humidite = dht.readHumidity();         // Stock dans la variable humidite le taux d'humidité (en %)
  float temperature = dht.readTemperature();   // Stock dans la variable temperature, la température (en °C)

  Serial.print("Humidité = ");
  Serial.print(humidite);
  Serial.println(" %");
  
  Serial.print("Température = ");
  Serial.print(temperature);
  Serial.println(" °C");
  
  delay(5000);


}