#include <SoftwareSerial.h>

#include <Servo.h>
Servo myservo;

const int rxPin = 4; // pin used to receive data
const int txPin = 3; // pin used to send data
SoftwareSerial softwareSerial(rxPin, txPin);
int in1=7;
int in2=8;
int serv=9;
char var;

String forward="0",backward="0",up="0",down="0",left="0",right="0";

int index=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  softwareSerial.begin(9600);
  myservo.attach(serv);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  myservo.write(105);
  Serial.println("hello");
  softwareSerial.println("hello");
}

void loop() {
  // put your main code here, to run repeatedly:
  String  values="";
  while(softwareSerial.available()>0){
    var=softwareSerial.read();
    //Serial.print(var);
    values+=var;
    
   
  }
  if(softwareSerial.available()==0 && values.length()>0)
  {
    assignValues(values);
    
    Serial.println("==============================================");
    Serial.println("forward="+forward);
    Serial.println("backward="+backward);
    Serial.println("up="+up);
    Serial.println("down="+down);
    Serial.println("left="+left);
    Serial.println("right="+right);
  }
  if(Serial.available()){
    char va;
    va=Serial.read();
    if(va=='q'){
      Serial.println("==============================================");
      Serial.println("forward="+forward);
      Serial.println("backward="+backward);
      Serial.println("up="+up);
      Serial.println("down="+down);
      Serial.println("left="+left);
      Serial.println("right="+right);
    }
  }
  
  

}
void assignValues(String arg){
  
  if(arg[0]=='f'){
    forward=arg.substring(arg.indexOf('f')+1,arg.indexOf(':'));
    backward="0";
  }
  else if(arg[0]=='b'){
    backward=arg.substring(arg.indexOf('b')+1,arg.indexOf(':'));
    forward="0";
  }
  else if(arg[0]=='u'){
    up=arg.substring(arg.indexOf('u')+1,arg.indexOf(':'));
    down="0";
  }else if(arg[0]=='d'){
    down=arg.substring(arg.indexOf('d')+1,arg.indexOf(':'));
    up="0";
  }else if(arg[0]=='l'){
    left=arg.substring(arg.indexOf('l')+1,arg.indexOf(':'));
    right="0";
  }else if(arg[0]=='r'){
    right=arg.substring(arg.indexOf('r')+1,arg.indexOf(':'));
    left="0";
  }
}


