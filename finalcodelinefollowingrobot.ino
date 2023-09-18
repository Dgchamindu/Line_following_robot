#include <NewPing.h>

#define LMF 12
#define LMB 13
#define LMS 6
#define RMF 10
#define RMB 11
#define RMS 5

#define IR_SENSOR_PIN_1 9
#define IR_SENSOR_PIN_2 4
#define IR_SENSOR_PIN_3 8
#define IR_SENSOR_PIN_4 7
#define IR_SENSOR_PIN_5 3

#define THRESHOLD 500

void setup() {
  pinMode(LMF, OUTPUT);
  pinMode(LMB, OUTPUT);
  pinMode(LMS, OUTPUT);
  pinMode(RMF, OUTPUT);
  pinMode(RMB, OUTPUT);
  pinMode(RMS, OUTPUT);

  pinMode(IR_SENSOR_PIN_1, INPUT);
  pinMode(IR_SENSOR_PIN_2, INPUT);
  pinMode(IR_SENSOR_PIN_3, INPUT);
  pinMode(IR_SENSOR_PIN_4, INPUT);
  pinMode(IR_SENSOR_PIN_5, INPUT);

  Serial.begin(9600);
}

void loop() {
  int sensorValue1 = digitalRead(IR_SENSOR_PIN_1);
  int sensorValue2 = digitalRead(IR_SENSOR_PIN_2);
  int sensorValue3 = digitalRead(IR_SENSOR_PIN_3);
  int sensorValue4 = digitalRead(IR_SENSOR_PIN_4);
  int sensorValue5 = digitalRead(IR_SENSOR_PIN_5);

  // Serial.print("Sensor 1: ");
  // Serial.print(sensorValue1 == HIGH ? "HIGH" : "LOW");
  // Serial.print(" - Sensor 2: ");
  // Serial.print(sensorValue2 == HIGH ? "HIGH" : "LOW");
  // Serial.print(" - Sensor 3: ");
  // Serial.print(sensorValue3 == HIGH ? "HIGH" : "LOW");
  // Serial.print(" - Sensor 4: ");
  // Serial.print(sensorValue4 == HIGH ? "HIGH" : "LOW");
  // Serial.print(" - Sensor 5: ");
  // Serial.println(sensorValue5 == HIGH ? "HIGH" : "LOW");

  bool isBlackLineDetected = (sensorValue3 == LOW);

  if(sensorValue1 == LOW && sensorValue2 == LOW && sensorValue3==HIGH && sensorValue4 == LOW && sensorValue5 == LOW){
    forward(); //L L H L L
    Serial.println("forward");
    // delay(100);
  }
  else if((sensorValue1 == LOW && sensorValue2 == HIGH && sensorValue3==HIGH && sensorValue4 == LOW && sensorValue5 == LOW)||(sensorValue1 == LOW && sensorValue2 == HIGH && sensorValue3==LOW && sensorValue4 == LOW && sensorValue5 == LOW)){
    adjustRight(); // L H H L L || L H L L L
    Serial.println("adjustRight");
    // delay(100);
  }
  else if((sensorValue1 == LOW && sensorValue2 == LOW && sensorValue3==HIGH && sensorValue4 == HIGH && sensorValue5 == LOW)||(sensorValue1 == LOW && sensorValue2 == LOW && sensorValue3==LOW && sensorValue4 == HIGH && sensorValue5 == LOW)){
    adjustLeft(); // L L H H L || L L L H L
    Serial.println("adjustLeft");
    // delay(100);
  }
  else if((sensorValue1 == HIGH && sensorValue2 == HIGH && sensorValue3==HIGH && sensorValue4 == LOW && sensorValue5 == LOW)||(sensorValue1 == HIGH && sensorValue2 == HIGH && sensorValue3==LOW && sensorValue4 == LOW && sensorValue5 == LOW)||(sensorValue1 == HIGH && sensorValue2 == HIGH && sensorValue3==HIGH && sensorValue4 == HIGH && sensorValue5 == LOW)||(sensorValue1 == HIGH && sensorValue2 == HIGH && sensorValue3==HIGH && sensorValue4 == LOW && sensorValue5 == HIGH)){
    turnLeft(); // H H H L L || H H L L L || H H H H L || H H H L H
    Serial.println("turnleft");
    //L
    }
    // delay(100);
  else if((sensorValue1 == LOW && sensorValue2 == LOW && sensorValue3==HIGH && sensorValue4 == HIGH && sensorValue5 == HIGH)||(sensorValue1 == LOW && sensorValue2 == LOW && sensorValue3==LOW && sensorValue4 == HIGH && sensorValue5 == HIGH)||(sensorValue1 == LOW && sensorValue2 == HIGH && sensorValue3==HIGH && sensorValue4 == HIGH && sensorValue5 == HIGH)||(sensorValue1 == HIGH && sensorValue2 == LOW && sensorValue3==HIGH && sensorValue4 == HIGH && sensorValue5 == HIGH)){
    turnRight(); // L L H H H || L L L H H || L H H H H 
    Serial.println("turnRight");
    //L
    // delay(100);
    }
  else if(sensorValue1 == HIGH && sensorValue2 == HIGH && sensorValue3==HIGH && sensorValue4 == HIGH && sensorValue5 == HIGH){
    turnLeft();  // T 
    Serial.println(" T ");
    // delay(100);
    }
  else if((sensorValue1 == HIGH && sensorValue2 == LOW && sensorValue3==LOW && sensorValue4 == LOW && sensorValue5 == LOW)||(sensorValue1 == LOW && sensorValue2 == HIGH && sensorValue3==LOW && sensorValue4 == LOW && sensorValue5 == LOW)){
    adr();
    Serial.println("adr");
    // H L L L L|| L H L L L
    // delay(100);
   }
  else if((sensorValue1 == LOW && sensorValue2 == LOW && sensorValue3==LOW && sensorValue4 == LOW && sensorValue5 == HIGH)||(sensorValue1 == LOW && sensorValue2 == LOW && sensorValue3==LOW && sensorValue4 == HIGH && sensorValue5 == LOW)){
    adl();
    Serial.println("adl");
    // L L L L H || L L L H L
    // delay(100);
  }
  else if(sensorValue1 == LOW && sensorValue2 == LOW && sensorValue3==LOW && sensorValue4 == LOW && sensorValue5 == LOW){
         Utern();
         Serial.println("Uturn");
       }
    // delay(100);
  else{
    backword();
    Serial.println("backword");
    // delay(100);
  }
}

void forward() {
  digitalWrite(LMF, HIGH);
  digitalWrite(RMF, HIGH);
  digitalWrite(LMB, LOW);
  digitalWrite(RMB, LOW);
  analogWrite(LMS, 100);
  analogWrite(RMS, 100);
}

void backword(){
  digitalWrite(LMF, LOW);
  digitalWrite(RMF, LOW);
  digitalWrite(LMB, HIGH);
  digitalWrite(RMB, HIGH);
  analogWrite(LMS, 100);
  analogWrite(RMS, 100);
}

void adjustLeft() {
  digitalWrite(LMF, HIGH);
  digitalWrite(RMF, HIGH);
  digitalWrite(LMB, LOW);
  digitalWrite(RMB, LOW);
  analogWrite(LMS, 100);
  analogWrite(RMS, 90);
}
void adl(){
  digitalWrite(LMF, HIGH);
  digitalWrite(RMF, HIGH);
  digitalWrite(LMB, LOW);
  digitalWrite(RMB, LOW);
  analogWrite(LMS, 100);
  analogWrite(RMS, 80);
}

void adjustRight() {
  digitalWrite(LMF, HIGH);
  digitalWrite(RMF, HIGH);
  digitalWrite(LMB, LOW);
  digitalWrite(RMB, LOW);
  analogWrite(LMS, 90);
  analogWrite(RMS, 100);
}
void adr(){
  digitalWrite(LMF, HIGH);
  digitalWrite(RMF, HIGH);
  digitalWrite(LMB, LOW);
  digitalWrite(RMB, LOW);
  analogWrite(LMS, 80);
  analogWrite(RMS, 100);
}

void turnRight(){
  digitalWrite(LMF, HIGH);
  digitalWrite(RMF, LOW);
  digitalWrite(LMB, LOW);
  digitalWrite(RMB, HIGH);
  analogWrite(LMS, 100);
  analogWrite(RMS, 90);
}
void turnLeft(){
  digitalWrite(LMF, LOW);
  digitalWrite(RMF, HIGH);
  digitalWrite(LMB, HIGH);
  digitalWrite(RMB, LOW);
  analogWrite(LMS, 100);
  analogWrite(RMS, 90);
}
void Utern(){
  digitalWrite(LMF, LOW);
  digitalWrite(RMF, HIGH);
  digitalWrite(LMB, HIGH);
  digitalWrite(RMB, LOW);
  analogWrite(RMS, 100);
  analogWrite(LMS, 90);
}

void stop() {
  digitalWrite(LMF, LOW);
  digitalWrite(RMF, LOW);
  digitalWrite(LMB, LOW);
  digitalWrite(RMB, LOW);
  analogWrite(LMS, 0);
  analogWrite(RMS, 0);
}
