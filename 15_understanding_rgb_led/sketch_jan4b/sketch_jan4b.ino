int redPin = 8;
int greenPin = 9;
int bluePin = 10;
String myColor;
String msg = "What Color Do You Want? ";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // Initialize serial communication
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg);
  while (Serial.available() == 0) {

  }
  myColor = Serial.readString();
  myColor.trim();  // Remove whitespace and newline characters

  if (myColor == "red") {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }

  if (myColor == "green") {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
  }

  if (myColor == "blue") {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
  }

  if (myColor == "off") {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }

  // rgb
  if (myColor == "aqua") {
    analogWrite(redPin, LOW);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 255);
  }

  if (myColor == "purple") {
    analogWrite(redPin, 128);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 128);
  }
}