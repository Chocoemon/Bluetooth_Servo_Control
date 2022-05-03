#include <SoftwareSerial.h>


int Tx = 2; //전송 보내는핀  
int Rx = 3; //수신 받는핀
bool is_on = false;
SoftwareSerial BtSerial(Tx,Rx);

void setup() { 
  // put your setup code here, to run once:
    pinMode(9, OUTPUT);  // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
    pinMode(8,OUTPUT);
  digitalWrite(9, HIGH);
  Serial.begin(38400);
  //Serial.println("hello");
  BtSerial.begin(38400);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (BtSerial.available()) {       
    Serial.write(BtSerial.read());
    if(!is_on){
        is_on = true;
        digitalWrite(8, HIGH);
    }

    else{
        is_on = false;
        digitalWrite(8, LOW);
      
    }
  }
  if (Serial.available()) {         
    BtSerial.write(Serial.read());
  }
}
