#include <LiquidCrystal.h>
int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;

float firstNum;
float secNum;
float answer;

String op;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  // Get first number
  lcd.setCursor(0, 0);
  lcd.print("Input First Number");
  while (Serial.available() == 0) {
    // Wait for input
  }
  firstNum = Serial.parseFloat();
  Serial.read(); // Clear remaining newline character
  
  // Get second number
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Input Second Number"); // Fixed: was "First" again
  while (Serial.available() == 0) {
    // Wait for input
  }
  secNum = Serial.parseFloat();
  Serial.read(); // Clear remaining newline character

  // Get operator
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Input Operator");
  lcd.setCursor(0, 1);
  lcd.print("(+, -, *, /)");
  while (Serial.available() == 0) {
    // Wait for input
  }
  op = Serial.readString();
  op.trim(); // Remove whitespace and newline characters

  // Calculate result
  if (op == "+") {
    answer = firstNum + secNum;
  } else if (op == "-") {
    answer = firstNum - secNum;
  } else if (op == "*") {
    answer = firstNum * secNum;
  } else if (op == "/") {
    answer = firstNum / secNum;
  }

  // Display result
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(firstNum);
  lcd.print(op);
  lcd.print(secNum); // Fixed: was "secondNum" instead of "secNum"
  lcd.print(" = ");
  lcd.print(answer);
  lcd.setCursor(0, 1);
  lcd.print("Thank You");
  delay(15000);
  lcd.clear();
}