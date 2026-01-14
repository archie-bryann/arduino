#include <LiquidCrystal.h>
int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int trigPin = 12;
int echoPin = 11;
int dt = 25;

long pingTravelTime;
float distanceToTarget;

void setup() {
  lcd.begin(16, 12);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Send trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo time in microseconds
  pingTravelTime = pulseIn(echoPin, HIGH);

  // Convert time to distance (inches)
  // distance = (time * speed of sound) / 2
  distanceToTarget = (pingTravelTime * 0.0133) / 2;

  Serial.print("Distance to Target is: ");
  Serial.println(distanceToTarget);
  Serial.println(" inches");
  lcd.setCursor(0, 0);
  lcd.print("Target Distance");
  lcd.setCursor(0, 1);
  lcd.print(distanceToTarget);

  // Serial.print(0);
  // Serial.print(",");
  // Serial.print(distanceToTarget);
  // Serial.print(",");
  // Serial.println(10);


  delay(dt);
}
