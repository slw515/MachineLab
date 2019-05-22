// same code used for other three stepper motors in project with minor 
//differences in assignment of stepper ports and IFR analog input pins.

#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
// Connect a stepper motor with 200 steps per revolution (1.8 degree)
// to motor port #2 (M3 and M4)
Adafruit_StepperMotor *myMotor = AFMS.getStepper(200, 2);


void setup() {
  Serial.begin(9600);           
  Serial.println("Stepper test!");

  AFMS.begin(); 
  //begin stepper motor. 
}

void loop() {
  // ifr value to be reset with every loop, analog read from A0, map between 0 and 800 for optimal
  //stepper speeds
  int ifr = map(analogRead(A0), 0, 600, 0, 800);
  myMotor->setSpeed(ifr);  // 10 rpm
  Serial.println(ifr);
  //5 steps seems to be optimal, go too low and no differences are perceived, go too high the 
  //feedback time is too slow.s
  myMotor->step(5, FORWARD, DOUBLE);
}
