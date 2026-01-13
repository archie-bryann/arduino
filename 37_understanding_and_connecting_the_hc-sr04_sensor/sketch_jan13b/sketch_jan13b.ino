int trigPin = 12;
int echoPin = 11;

long pingTravelTime;
float distanceToTarget;

void setup() {
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

  // Serial.print(0);
  // Serial.print(",");
  // Serial.print(distanceToTarget);
  // Serial.print(",");
  // Serial.println(10);


  delay(25);
}
