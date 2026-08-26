#include <Servo.h>
Servo motors[4];

int motorPins[4] = {
  8,9,10,11
};

int angles[4] = {
  90,90,90,90
};

int minAngles[4] = {
  30, 30 ,30, 30
};

int maxAngles[4] = {
  150,150,150,150
};

void setup() {
  Serial.begin(9600);
  for(int i=0;i<4;i++){
    motors[i].attach(motorPins[i]);
    motors[i].write(angles[i]);
  }
  delay(1000);
}

void loop() {
  int joystick[4];
  joystick[0] = analogRead(A0);
  joystick[1] = analogRead(A1);
  joystick[2] = analogRead(A2);
  joystick[3] = analogRead(A3);
  Serial.print("A0  : ");
  Serial.println(joystick[0]);
  for(int i =0; i<4;i++){
    moveMotor(i,joystick[i]);
  }
  delay(10);
}

void moveMotor(int motorNumber,int joystickValue){
  if(joystickValue > 600){
    angles[motorNumber]++;
  }
  else if(joystickValue < 400){
    angles[motorNumber]--;
  }
  
  angles[motorNumber] = constrain(
    angles[motorNumber],
    minAngles[motorNumber],
    maxAngles[motorNumber]
  );

  motors[motorNumber].write(angles[motorNumber]);
}