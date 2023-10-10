// Created by Gunider M. August 11, 2021; modified by Matteo F and Alex A, October 6, 2023//

//pin assignment
int PWM_A = 11; 
int PWM_B = 3;
int EnablePin1 = 8;
const byte Megamoto_current= A5; 
const int Trig_Pin = 35;
const int Echo_Pin = 40;   

//defining values
long Distance_value;
int CRaw1;      
int Previous_CRaw;
int CRawAvg;

void setup() {
  //MegaMoto
  Serial.begin(9600);
  pinMode(Trig_Pin, OUTPUT);
  pinMode(Echo_Pin, INPUT);
  pinMode(Megamoto_current, INPUT);
  pinMode(PWM_A, OUTPUT);
  pinMode(PWM_B, OUTPUT);
  pinMode(EnablePin1, OUTPUT);
  digitalWrite(EnablePin1, HIGH); //enable the board

}

void loop() {

  while (Serial.available() == 0) {}     //wait for data available
  char teststr = Serial.read();  //read until timeout
  if (teststr == 'w') {
    Serial.println("Direction Change");
    digitalWrite(EnablePin1, LOW); //disable the board (freewheeling)
    delay(200);
    Serial.println("Extending");
    digitalWrite(PWM_A, LOW); digitalWrite(PWM_B, HIGH); //Extend
    digitalWrite(EnablePin1, HIGH); //enable the board
  } else if (teststr == 'e') {
    Serial.println("Direction Change");
    digitalWrite(EnablePin1, LOW); //disable the board (freewheeling)
    delay(200);
    Serial.println("Retracting");
    digitalWrite(PWM_A, HIGH); digitalWrite(PWM_B, LOW); //Retract
    digitalWrite(EnablePin1, HIGH); //enable the board
  }

}
