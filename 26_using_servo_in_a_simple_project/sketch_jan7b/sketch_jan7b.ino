#include <Servo.h>
int servoPin = A4;
int lightVal;
int lightPin = A4;
int dt = 250;
int angle;
Servo myServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lightPin, INPUT);
  pinMode(servoPin, OUTPUT);
  myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal = analogRead(lightPin);
  Serial.println(lightVal);
  delay(dt);
  angle = (-16./63.)*lightVal+16.*780./63.;
  myServo.write(angle);
}
