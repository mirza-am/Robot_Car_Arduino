// Projek Robot Car Control With IR Remote
// By mirzaam_
// With Module L298N

#include<IRremote.h>

//Make Variable From IR Remote
const int pinIR = 12;
IRrecv recv(pinIR);
decode_results hasil;


// Make Variable From Module L298N
const int ENA = 10, ENB = 9;
const int in1 = 7, in2 = 6, in3 = 5, in4 = 4;


void setup() {
  Serial.begin(9600);
  recv.enableIRIn();
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  if(recv.decode(&hasil)){
    Serial.println(hasil.value);
    if(hasil.value==16718055){
     forward();
    }
    if(hasil.value==16730805){
     backward();
    }
    if(hasil.value==16716015){
     left();
    }
    if(hasil.value==16734885){
     right();
    }
    if(hasil.value==16726215){
     stop();
    }
    if(hasil.value==16750695){
     turn();
    }
    recv.resume();
  }
}


  //Maju
void forward() {
  Serial.println("Jalan");
  
  analogWrite(ENA, 80); // set right motors speed
  analogWrite(ENB, 80); // set left motors speed
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}


  //Mundur
void backward() {
  Serial.println("Mundur");
  
  analogWrite(ENA, 80); // set right motors speed
  analogWrite(ENB, 80); // set left motors speed
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}


  //Berhenti
void stop() {
  Serial.println("Berhenti");
  
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}


  //Belok Ke Kanan
void right() {
  Serial.println("Belok Ke Kanan");

  analogWrite(ENA, 100);
  analogWrite(ENB, 100);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}


  //Belok Ke Kiri
void left() {
  Serial.println("Belok Ke Kiri");

  analogWrite(ENA, 100);
  analogWrite(ENB, 100);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}


  //Putar Balik
void turn() {
  Serial.println("Putar Balik");
  
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
