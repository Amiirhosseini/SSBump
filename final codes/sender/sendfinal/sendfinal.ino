#include <SPI.h>

#include <LoRa.h>


int counter = 0;


void setup() {

Serial.begin(9600);

while (!Serial);


Serial.println("LoRa Sender");


 if (!LoRa.begin(433E6)) {

 Serial.println("Starting LoRa failed!");

 while (1);

}


 LoRa.setTxPower(20);

 

}

 int latitude =10;
 int langtitude=20;
void loop() {

 Serial.print("Sending packet: ");

 Serial.println(counter);


// send packet

 LoRa.beginPacket();

char buffer[150];
sprintf(buffer,"%d%d",latitude,langtitude);
LoRa.print(buffer);
 LoRa.endPacket();



Serial.println(buffer);
 latitude++;
 langtitude++; 

counter++;
 delay(5000);

}
