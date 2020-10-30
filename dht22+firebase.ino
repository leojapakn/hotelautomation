#include <FirebaseArduino.h> // Firebase library
#include "DHT.h"  
#include <DHT.h> // inlcude dht library
#include <DHT_U.h>
#include  <ESP8266WiFi.h> // include esp8266 library
#define FIREBASE_HOST "your-firebase-host-without http:// "
#define FIREBASE_AUTH "do not need to put this"  
#define WIFI_SSID "your ssid"
#define WIFI_PASSWORD "your password"

#define DHTPIN 0    // Pin 0 in my case of ESP8266
#define DHTTYPE DHT22   // define sensor as dht22
DHT dht(DHTPIN, DHTTYPE);

void setup() {   
 Serial.begin(115200);
 
  Serial.print("A ligar a: ");
  Serial.println(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
Serial.println("");
  Serial.println("Ligado");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
  dht.begin();
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);    
  
}
void loop() {
  delay(10);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
Serial.print("Humidade: "); Serial.print(h); Serial.println(" %");
Serial.print("Temperatura: "); Serial.print(t); Serial.println("ºC");
Firebase.setFloat ("Temperature",t);
Firebase.setFloat ("Humidity",h);
  delay(200);
}
