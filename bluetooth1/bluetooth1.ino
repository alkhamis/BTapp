#include <Servo.h>
#include <SoftwareSerial.h>

const int rxPin = 11; // pin used to receive data
const int txPin = 12; // pin used to send data
SoftwareSerial softwareSerial(rxPin, txPin);


const int SERVO_LEFT_HIP   = 10;
const int SERVO_LEFT_FOOT  = 9;
const int SERVO_RIGHT_HIP  = 8;
const int SERVO_RIGHT_FOOT = 7;


const int LEFT_HIP_CENTRE = 140;
const int LEFT_HIP_MIN    = LEFT_HIP_CENTRE - 80;
const int LEFT_HIP_MAX    = LEFT_HIP_CENTRE + 80;

const int LEFT_FOOT_CENTRE = 130;
const int LEFT_FOOT_MIN    = LEFT_FOOT_CENTRE - 80;
const int LEFT_FOOT_MAX    = LEFT_FOOT_CENTRE + 80;

const int RIGHT_HIP_CENTRE = 80;
const int RIGHT_HIP_MIN    = RIGHT_HIP_CENTRE - 80;
const int RIGHT_HIP_MAX    = RIGHT_HIP_CENTRE + 80;

const int RIGHT_FOOT_CENTRE = 50;
const int RIGHT_FOOT_MIN    = RIGHT_FOOT_CENTRE - 80;
const int RIGHT_FOOT_MAX    = RIGHT_FOOT_CENTRE + 80;

//Wiring code
char val; // variable to receive data from the serial port

//----------------------------------------------------------------------------------
// Servo Variables
//----------------------------------------------------------------------------------

Servo servoLeftHip;
Servo servoLeftFoot;
Servo servoRightHip;
Servo servoRightFoot;

void setup() {
  
  softwareSerial.begin(9600);
    
    // Setup the Servos
    servoLeftHip.attach(SERVO_LEFT_HIP);
    servoLeftFoot.attach( SERVO_LEFT_FOOT);
    servoRightHip.attach( SERVO_RIGHT_HIP);
    servoRightFoot.attach(SERVO_RIGHT_FOOT);

    servoLeftHip.write(140); 
    servoLeftFoot.write(130);
    servoRightHip.write(80); 
    servoRightFoot.write(50);

  softwareSerial.println("Goodnight moon!");
}
void loop() {
  if( softwareSerial.available() )       // if data is available to read
  {
    val = softwareSerial.read();         // read it and store it in 'val'
    softwareSerial.println("reading");
    if(val=='1'){
      softwareSerial.println("moving left hip");
      for(int pos = LEFT_HIP_MIN ; pos <= LEFT_HIP_MAX    ; pos += 1) // goes from 0 degrees to 180 degrees 
          {                                  // in steps of 1 degree 
            servoLeftHip.write(pos);              // tell servo to go to position in variable 'pos' 
            delay(15);                       // waits 15ms for the servo to reach the position 
          } 
          
          servoLeftHip.write(LEFT_HIP_CENTRE);
    }
    else if(val=='2'){
      softwareSerial.println("moving left foot");
      for(int pos = LEFT_FOOT_MIN ; pos <= LEFT_FOOT_MAX    ; pos += 1) // goes from 0 degrees to 180 degrees 
          {                                  // in steps of 1 degree 
            servoLeftFoot.write(pos);              // tell servo to go to position in variable 'pos' 
            delay(15);                       // waits 15ms for the servo to reach the position 
          } 
          
          servoLeftFoot.write(LEFT_FOOT_CENTRE);
      
    }
    else if(val=='3'){
      softwareSerial.println("moving right hip"); 
      for(int pos = RIGHT_HIP_MIN ; pos <= RIGHT_HIP_MAX    ; pos += 1) // goes from 0 degrees to 180 degrees 
          {                                  // in steps of 1 degree 
            servoRightHip.write(pos);              // tell servo to go to position in variable 'pos' 
            delay(15);                       // waits 15ms for the servo to reach the position 
          } 
          
          servoRightHip.write(RIGHT_HIP_CENTRE);
    }
    else if(val=='4'){
      softwareSerial.println("moving right foot");
      for(int pos = RIGHT_FOOT_MIN ; pos <= RIGHT_FOOT_MAX    ; pos += 1) // goes from 0 degrees to 180 degrees 
          {                                  // in steps of 1 degree 
            servoRightFoot.write(pos);              // tell servo to go to position in variable 'pos' 
            delay(15);                       // waits 15ms for the servo to reach the position 
          } 
          
          servoRightFoot.write(RIGHT_FOOT_CENTRE);   
            
           
    }
    else if(val=='5'){
      softwareSerial.println("moving FORWORD");
      mforword();
          
            
            
           
    }
  }
  
  delay(100);                    // wait 100ms for next reading
}
void move1 (Servo ser1,int current,int dist,int sgin){

  
  for(int pos = current ; pos <= dist    ; pos += 5) // goes from 0 degrees to 180 degrees 
          {                                  // in steps of 1 degree 
            ser1.write(pos);              // tell servo to go to position in variable 'pos' 
            delay(35);                       // waits 15ms for the servo to reach the position 
          } 
}
void move2 (Servo ser1,int current,int dist,int sgin){

  
  for(int pos = current ; pos >= dist    ; pos =pos- 5) // goes from 0 degrees to 180 degrees 
          {                                  // in steps of 1 degree 
            ser1.write(pos);              // tell servo to go to position in variable 'pos' 
            delay(35);                      // waits 15ms for the servo to reach the position 
          } 
}
void mforword()
{   move1(servoRightFoot,RIGHT_FOOT_CENTRE,RIGHT_FOOT_CENTRE+70,1);
    delay(150);
    int cur=LEFT_FOOT_CENTRE;
    int dist=LEFT_FOOT_CENTRE+30;
    move1(servoLeftFoot,cur,dist,1);
    delay(150);
    cur=LEFT_HIP_CENTRE;
    dist=LEFT_HIP_CENTRE-35;
    move2(servoLeftHip,cur,dist,-1);
    delay(150);
    move2(servoRightFoot,RIGHT_FOOT_CENTRE+70,RIGHT_FOOT_CENTRE,1);
    delay(350);
    move2(servoLeftFoot,LEFT_FOOT_CENTRE+30,LEFT_FOOT_CENTRE,1);
    center();
}
void center(){
  servoLeftHip.write(140); 
    servoLeftFoot.write(130);
    servoRightHip.write(80); 
    servoRightFoot.write(50);
}



