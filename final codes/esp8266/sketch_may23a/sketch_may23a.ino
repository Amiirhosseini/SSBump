#define BLYNK_PRINT Serial
#define BLYNK_DEBUG        // Optional, this enables more detailed prints

#define BLYNK_TEMPLATE_ID "TMPL47-OFEvqe"
#define BLYNK_TEMPLATE_NAME "NEW"
#define BLYNK_AUTH_TOKEN "uk0r3UtRaD45kAcXXCsY8RH4gCq-yKN4"

//#include <WiFi.h>
//#include <WiFiClient.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char Mymessage[2]; //String data

//SSID
char ssid[]= "AndroidShare_7463";

//pass
char pass[]="123456789";

//int LED_BUILTIN = 2;


void setup() {
  // Debug console
  Serial.begin(9600);
//pinMode (LED_BUILTIN, OUTPUT);
//digitalWrite(LED_BUILTIN, HIGH);
Blynk.begin(BLYNK_AUTH_TOKEN ,"jadel","11899697");
//Blynk.begin(BLYNK_AUTH_TOKEN ," Amir iPhone","amirreza");
//Blynk.begin(BLYNK_AUTH_TOKEN ,"ali","123456789");
}

void loop()
{

if (Serial.available()) {
        Serial.readBytes(Mymessage,2); //Read the serial data and store in var
        Serial.println(Mymessage); //Print data on Serial Monitor

    // Send the data to the Blynk dashboard
    Blynk.virtualWrite(V1, Mymessage);
      }

  //Serial.println(ssid);
  Blynk.run();
  //Serial.println(pass);
}