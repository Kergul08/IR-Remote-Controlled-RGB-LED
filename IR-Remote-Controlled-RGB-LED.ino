#include <IRremote.hpp>

int IRpin=6;
int rPin=9;
int bPin=10;
int gPin=5;
int rBright;
int bBright;
int gBright;
unsigned long myCode;
float dFact=1;

void setup() {
  pinMode(rPin,OUTPUT);
  pinMode(bPin,OUTPUT);
  pinMode(gPin,OUTPUT);
  IrReceiver.begin(IRpin);
  Serial.begin(9600);
}

void loop() {
  while(IrReceiver.decode()==0) {

  }
  myCode = IrReceiver.decodedIRData.decodedRawData;  
  delay(50);
  IrReceiver.resume();

  if(myCode==0xE31CFF00){
    rBright=255;
    gBright=255;
    bBright=255;
    dFact=1;
  }
  if(myCode==0xE916FF00){
    rBright=0;
    gBright=0;
    bBright=0;
    dFact=0;
  }
  if(myCode==0xBA45FF00){
    rBright=255;
    gBright=255;
    bBright=255;
  }
  if(myCode==0xB946FF00){
    rBright=255;
    gBright=0;
    bBright=0;
  }
  if(myCode==0xB847FF00){
    rBright=0;
    gBright=255;
    bBright=0;
  }
  if(myCode==0xBB44FF00){
    rBright=0;
    gBright=0;
    bBright=255;
  }
  if(myCode==0xBF40FF00){
    rBright=255;
    gBright=0;
    bBright=255;
  }
  if(myCode==0xBC43FF00){
    rBright=255;
    gBright=200;
    bBright=0;
  }
  if(myCode==0xF807FF00){
    rBright=0;
    gBright=255;
    bBright=200;
  }
  if(myCode==0xAD52FF00){
    dFact=dFact*.75;
  }
  if(myCode==0xE718FF00){
    dFact=dFact*1.3;
    if(dFact>1){
      dFact=1;
    }
  }
  analogWrite(rPin,rBright*dFact);
  analogWrite(gPin,gBright*dFact);
  analogWrite(bPin,bBright*dFact);
  Serial.println(dFact);
}
