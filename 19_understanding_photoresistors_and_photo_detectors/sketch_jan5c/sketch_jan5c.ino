int lightPen = A0;
int lightVal;
int dv = 250;

void setup() {
  // put your setup code here, to run once:
  pinMode(lightPen, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal = analogRead(lightPen);
  Serial.println(lightVal);
  delay(dv);
}
