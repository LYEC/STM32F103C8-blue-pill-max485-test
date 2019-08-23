/*
 *       II         II     II     IIIIIII      IIIIIIII
 *       II          II   II      II          II
 *       II           IIII        IIIIIII     II
 *       II            II         II          II
 *       IIIIII        II         IIIIIII      IIIIIIII         
 */

#include "SoftSerialSTM32.h"   

SoftSerialSTM32 max_av2(PA10,PA9); 
int count = 0;
char gelen_data;
void rs485_yaz(Stream &lyec,char veri){ 
lyec.print(veri);
lyec.flush();
}

void rs_dinle(Stream &l_stream){
if(l_stream.available()){  
 while(l_stream.available()){
   gelen_data = l_stream.read();
   Serial.println(gelen_data);
   }
}
}
void setup() {
 Serial3.begin(9600);
 max_av2.begin(9600);
}

void loop() {
rs485_yaz(max_av2,'A');
rs_dinle(Serial3);
delay(100);
count++;
}
