#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN pins
const uint8_t address[6] = "00001";
const int buttonPin = 2; // Pin connected to the button
bool buttonPressed = false; // To track the button state

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT); // Set button pin as input
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.setDataRate(RF24_2MBPS);
  radio.setChannel(0x60);  // Set the same channel as on the Raspberry Pi
  radio.setRetries(15, 15);
  radio.stopListening();
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) { // Check if button is pressed
    if (!buttonPressed) { // Only send the message once when the button is pressed
      buttonPressed = true; // Set the flag to indicate the button has been pressed
      const char text[] = "Button pressed";
      radio.write(&text, sizeof(text));
      Serial.println("Sent: Button pressed");
    }
  } else {
    buttonPressed = false; // Reset the flag when the button is released
  }
}