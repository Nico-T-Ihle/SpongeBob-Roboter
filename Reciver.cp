#include <RF24/RF24.h>
#include <iostream>
#include <unistd.h>

RF24 radio(17, 0); // CE=GPIO17, CSN=SPI CE0 (entspricht /dev/spidev0.0)

const uint8_t address[6] = "00001";

void setup() {
    std::cout << "Starting radio setup..." << std::endl;
    if (!radio.begin()) {
        std::cerr << "Radio hardware is not responding!" << std::endl;
        exit(1);  // Exit if the radio is not responding
    }
    radio.openReadingPipe(1, address);
    radio.setPALevel(RF24_PA_MIN);
    radio.setDataRate(RF24_2MBPS);
    radio.setChannel(0x60);  // Gleicher Kanal wie der Sender
    radio.startListening();
    std::cout << "Listening for messages..." << std::endl;
}

void loop() {
    while (true) {
        if (radio.available()) {
            char text[32] = {0};
            radio.read(&text, sizeof(text));
            std::cout << "Received: " << text << std::endl;
        } else {
            std::cout << "No message available." << std::endl;
        }
        usleep(1000000); // 1 second delay
    }
}

int main() {
    setup();
    loop();
    return 0;
}