#include <Servo.h>

Servo servoLeft; // declared (aka made) servo object named servoLeft
//Servo servoRight;
Servo servoRight;

int IRsensorLF = A1;
int IRemitterLF = 8;

int IRsensorRF = A2;
int IRemitterRF = 7;

int IRsensorLB = A3;
int IRemitterLB = 4;

int IRsensorRB = A4;
int IRemitterRB = 2;

void setup() {
  // put your setup code here, to run once:
  servoLeft.attach(9);
  servoRight.attach(10);
  Serial.begin(9600);   //initialize Serial monitor

  servoLeft.write(90);
  servoRight.write(90);

  pinMode(IRemitterLF, OUTPUT);
  digitalWrite(IRemitterLF, HIGH);

  pinMode(IRemitterRF, OUTPUT);
  digitalWrite(IRemitterRF, HIGH);

  pinMode(IRemitterLB, OUTPUT);
  digitalWrite(IRemitterLB, HIGH);

  pinMode(IRemitterRB, OUTPUT);
  digitalWrite(IRemitterRB, HIGH);

}

void loop() {

  int sensorValue = analogRead(IRsensorLF); //reading IR sensor value
  Serial.print("Sensor 1: ");
  Serial.println(sensorValue);

  int sensorValue2 = analogRead(IRsensorRF);
  Serial.print("Sensor 2: ");
  Serial.println(sensorValue2);

  int sensorValue3 = analogRead(IRsensorLB);
  Serial.print("Sensor 3: ");
  Serial.println(sensorValue3);

  int sensorValue4 = analogRead(IRsensorRB);
  Serial.print("Sensor 4: ");
  Serial.println(sensorValue4);
  delay(100);

  if (sensorValue >= 1000 &&  sensorValue2 >= 1000)
  {
    goForward();
    Serial.print("Go");
  }
  
  else
  {
    stop();
    Serial.print("Stop");
  }

}

void goForward() {
  servoLeft.write(180);
  servoRight.write(0);
}

void stop() {
  servoLeft.write(90);
  servoRight.write(90);
}

