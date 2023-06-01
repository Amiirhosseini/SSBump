
 #include <SPI.h>

#include <LoRa.h>


int counter = 0;
int LDRSensor1 = 4;
 int LDRSensor2 = 3;
 int waitingfor2nd =0;
 int flg2 ;
 int flg ;
 long int t1 = 0;
 long int t2 = 0;
 double dist = 60;

 const int stepPin = 5; 
const int dirPin = 2; 
const int enPin = 8;
long int tmotor1 = 0;
long int tmotor2 = 0;
int  bumperdown =0;
char Mymessage[3] ; //String data
char lor[4] ; //String data

void setup()
 {
  //Initialize Sensor (pin3) as an INPUT.
  pinMode (LDRSensor1, INPUT);
  pinMode (LDRSensor2, INPUT);

      pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(enPin,OUTPUT);
  digitalWrite(enPin,LOW);
  //Define baud rate for serial communication
  
    Serial.begin(9600);
  if (!LoRa.begin(433E6)) {  // Set the frequency (change to match your module frequency)
    Serial.println("LoRa initialization failed. Check your connections.");
    while (true);  // Stay in an infinite loop if initialization fails
  }


 }
 
void loop()
 {

int Sensordata1 = digitalRead (LDRSensor1);
int Sensordata2 = digitalRead (LDRSensor2);

if(!(Sensordata1 == 1 && Sensordata2 == 1)){
if(Sensordata1 == 1  && waitingfor2nd == 0){
waitingfor2nd = 1;
t1 = millis();
}}
if (Sensordata2 == 1 && waitingfor2nd == 1){
t2 = millis();
//Serial.print("Speed: "); /
//Serial.print(dist*3.6/double((t2-t1))); 
//Serial.println("km per hour");
//send to server  dist*3.6/double((t2-t1))
waitingfor2nd = 0;
//double a=43.4;
  double a=dist*36/double((t2-t1));
  int integerNumber = static_cast<int>(a);

  sprintf(Mymessage,"%02d\n",integerNumber);
  Serial.write(Mymessage,2); //Write the serial data


}
if (LoRa.parsePacket()) {
  int i =0;
    while (LoRa.available()) {
      //Serial.write(LoRa.read());  // Print received data to the serial monitor
    
    //sprintf(lor,"%s",LoRa.read());
    lor[i]=LoRa.read();
    i++;
    }
    //Serial.write(lor);
    //Serial.println();
    if(lor[0]=='1' &&  lor[1]=='7')/*distance << tresh*/{
  //bumper down
digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  for(int x = 0; x < 5200; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(500); 

  }
digitalWrite(dirPin,LOW); //Changes the direction of rotation
  for(int x = 0; x < 500; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(500);
  
    tmotor1 = millis();
    bumperdown = 1;
  }
  }
  }
    tmotor2 = millis();
 
 if(bumperdown == 1 && tmotor2-tmotor1>=5000){
//bumper up
bumperdown= 0;
digitalWrite(dirPin,LOW); //Changes the direction of rotation
  for(int x = 0; x < 5200; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(500);
  }

    digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  for(int x = 0; x < 500; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(500); 

  }

 }
 
 
 }
