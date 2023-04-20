#include <Arduino.h>

#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
float data[5];
RF24 radio(7,8);
const uint64_t r= 0x00011001;
void setup(void){
 Serial.begin(115200);
 radio.begin();
 radio.setChannel(30);
 radio.setPayloadSize(32);
 radio.setDataRate(RF24_250KBPS);
 radio.openReadingPipe(1,r);
 radio.startListening();
}

void loop(void){
 if (radio.available()){  
     radio.read(data, sizeof(data));      
     Serial.print("lng:");
     Serial.print(data[0],8);
     Serial.print(" lat:");
     Serial.print(data[1],8);
     Serial.print(" speed:");
     Serial.print(data[2],6);
     Serial.print(" temp:");
     Serial.print(data[3],2);
     Serial.print(" pressure:");
     Serial.println(data[4],2);
     delay(30);
 }
 
}