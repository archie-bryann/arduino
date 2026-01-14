#include <IRremote.hpp>
#define IR_RECEIVE_PIN 9

void setup()
{
  Serial.begin(9600); // // Establish serial communication
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Start the receiver
}

void loop() {
  if (IrReceiver.decode()) {
      Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); // Print "old" raw data
      // IrReceiver.printIRResultShort(&Serial); // Print complete received data in one line
      // IrReceiver.printIRSendUsage(&Serial);   // Print the statement required to send this data
      // delay(1500);
      IrReceiver.resume(); // Enable receiving of the next value
  }
}

// https://github.com/Arduino-IRremote/Arduino-IRremote?tab=readme-ov-file#converting-your-2x-program-to-the-4x-version