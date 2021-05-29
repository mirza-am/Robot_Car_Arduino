// Projek Robot Line Follower
// By mirzaam_
// With Module L298N

// Make Variable Sensor Left, Right, And Left
const int sensorCenter = 8;
const int sensorRight = 3;
const int sensorLeft = 2;

// Make Variable From Module L298N
const int ENA = 10;
const int ENB = 9;
const int in1 = 7;
const int in2 = 6;
const int in3 = 5;
const int in4 = 4;


void setup() {
  Serial.begin(9600);
  pinMode(sensorCenter, INPUT);
  pinMode(sensorRight, INPUT);
  pinMode(sensorLeft, INPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  int sensorC = digitalRead(sensorCenter);
  int sensorR = digitalRead(sensorRight);
  int sensorL = digitalRead(sensorLeft);

  Serial.print("Sensor Tengah: ");
  Serial.print(sensorC);
  Serial.print("      Sensor Kanan: ");
  Serial.print(sensorR);
  Serial.print("      Sensor Kiri: ");
  Serial.println(sensorL);

//Maju 
  if((sensorC == HIGH) && (sensorR == LOW) && (sensorL == LOW))
  {
    forward();
  }

//Berhenti
  else if((sensorC == HIGH) && (sensorR == HIGH) && (sensorL == HIGH))
  {
    stop();
  }  

//Ke Kanan
  else if ((sensorC == LOW) && (sensorR == HIGH) && (sensorL == LOW))
  { 
    right();
  }

//Ke Kiri
  else if ((sensorC == LOW) && (sensorR == LOW) && (sensorL == HIGH))
  { 
    left();
  }

//Putar Balik
  else if ((sensorR == LOW) && (sensorR == LOW) && (sensorL == LOW))
  { 
    turn();
    delay(650);
    stop();
    delay(1000);
  }

//Another
  else{}
}


void forward() {
  //Maju
  Serial.println("Jalan");
  
  analogWrite(ENA, 80); // set right motors speed
  analogWrite(ENB, 80); // set left motors speed
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}


void stop() {
  //Berhenti
  Serial.println("Berhenti");
  
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}


void right() {
  //Belok Ke Kanan
  Serial.println("Belok Ke Kanan");

  analogWrite(ENA, 100);
  analogWrite(ENB, 100);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}


void left() {
  //Belok Ke Kiri
  Serial.println("Belok Ke Kiri");

  analogWrite(ENA, 100);
  analogWrite(ENB, 100);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}


void turn() {
  //Putar Balik
  Serial.println("Putar Balik");
  
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
