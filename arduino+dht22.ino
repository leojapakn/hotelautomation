#include <DHT.h> //inclui biblioteca do sensor dht22
#include <DHT_U.h>
#define DHTPIN 12 //Define pino sensor como 12
#define DHTTYPE DHT22 //sensor usado

DHT dht(DHTPIN, DHTTYPE);// Objeto do sensor criado

float h=0,t=0; // define como float h e t
const int ledPin = 13; //LED verde para controle de temperatura
const int ledPin2 = 11; // LED Vermelho para controle de temperatura
long previousMillis = 0;
long interval = 2000; // lê sensor a cada 2 segundos

String inputString = "";         // string para receber dados
bool stringComplete = false;  // enquanto string não está completa

void setup() {
  // initialize serial:
  Serial.begin(115200);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  pinMode(ledPin,OUTPUT); // Led VERDE
  pinMode(ledPin2,OUTPUT); // Led Vermelho
  dht.begin();//START NO SENSOR DHT22
  digitalWrite(ledPin2,LOW);//LED VERMELHO DESLIGADO 
  digitalWrite(ledPin,LOW);//LED VERDE DESLIGADO
}

void loop() 
{
  delay(1000);
  {
     
     h = dht.readHumidity();//Valor da umidade
     t = dht.readTemperature();//Valor da temperatura em graus celsius
     
     
     if(t>=24)// Se temperatura for igual ou acima dos 24 graus ( ar condicionado liga)
    {
      digitalWrite(ledPin,HIGH);//ativa ar condicionado LED VERDE
      digitalWrite(ledPin2,LOW); // Led vermelho permanece desligado
      Serial.print(" Temp: ");
      Serial.print(t);
      Serial.println(" Celsius");
      delay(1000);
     
    }
    else if(t<24 )//se temperatura estiver abaixo dos 24 graus (ar condicionado permanece desligado)
    {
      digitalWrite(ledPin2,HIGH); //desativa ar condicionado aciona LED VERMELHO
      digitalWrite(ledPin,LOW);//  Led verde permanece desligado 
      Serial.print(" Temp: ");
      Serial.print(t);
      Serial.println(" Celsius");
      delay(1000);
    }
  }
}
