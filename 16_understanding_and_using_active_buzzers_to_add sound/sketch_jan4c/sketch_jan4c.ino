int potVal;
int myNumb;
int buzzPin = 8;
int potPin = A3;
String msg = "Please Input Your Number";
int dt = 100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println(msg);
  // while (Serial.available() == 0) {

  // }
  // myNumb = Serial.parseInt();
  // Serial.read(); // Clear the newline character from buffer
  
  potVal = analogRead(potPin);
  Serial.println(potVal);
  // if (myNumb > 10) {
  while (potVal > 1000) {
    digitalWrite(buzzPin, HIGH);
    potVal = analogRead(potPin);
    Serial.println(potVal);
  }
  digitalWrite(buzzPin, LOW);
}
