// Projek Robot Ostacle Avoiding
// By mirzaam_
// With Module L298N

#include <Servo.h>          //Servo motor library. This is standard library
#include <NewPing.h>        //Ultrasonic sensor function library. You must install this library

//our L298N control pins
const int in1 = 7;
const int in2 = 6;
const int in3 = 5;
const int in4 = 4;

//sensor pins
#define trig_pin 11 // input 1
#define echo_pin 12 // input 2
#define maximum_distance 200

bool goesForward = false;
int distance = 100;

NewPing sonar(trig_pin, echo_pin, maximum_distance); //sensor function
Servo servo_motor; //our servo name


void setup(){

  pinMode(in3, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in4, OUTPUT);
  
  servo_motor.attach(10); //our servo pin

  servo_motor.write(130);
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop(){

  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

  if (distance <= 35){
    moveStop();
    delay(300);
    moveBackward();
    delay(400);
    moveStop();
    delay(300);
    distanceRight = lookRight();
    delay(300);
    distanceLeft = lookLeft();
    delay(300);

    if (distance >= distanceLeft){
      turnRight();
      moveStop();
    }
    else{
      turnLeft();
      moveStop();
    }
  }
  else{
    moveForward(); 
  }
    distance = readPing();
}


int lookRight(){  
  servo_motor.write(50);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(115);
  return distance;
}


int lookLeft(){
  servo_motor.write(180);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(115);
  return distance;
  delay(100);
}


int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}


void moveStop(){
  
  digitalWrite(in3, LOW);
  digitalWrite(in1, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(in2, LOW);
}


void moveForward(){
  if(!goesForward){
    goesForward=true;
    
    digitalWrite(in1, HIGH);
    digitalWrite(in3, HIGH);
  
    digitalWrite(in2, LOW);
    digitalWrite(in4, LOW); 
  }
}


void moveBackward(){
  goesForward=false;

  digitalWrite(in2, HIGH);
  digitalWrite(in4, HIGH);
  
  digitalWrite(in1, LOW);
  digitalWrite(in3, LOW);  
}


void turnRight(){
  digitalWrite(in1, HIGH);
  digitalWrite(in4, HIGH);
  
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  
  delay(500);
  
  digitalWrite(in1, HIGH);
  digitalWrite(in3, HIGH);
  
  digitalWrite(in2, LOW);
  digitalWrite(in4, LOW);  
}


void turnLeft(){
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  
  digitalWrite(in1, LOW);
  digitalWrite(in4, LOW);

  delay(500);
  
  digitalWrite(in1, HIGH);
  digitalWrite(in3, HIGH);
  
  digitalWrite(in2, LOW);
  digitalWrite(in4, LOW);
}
