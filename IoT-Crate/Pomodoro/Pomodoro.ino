#include <TM1637Display.h>

// COUNTDOWN TIME
const unsigned long countdownTime = 25 * 60; // 25MIN IN SECS

// DECALRNG PINS
#define clkPin 2
#define dioPin 3
#define resetButton 10
//DECLARE OBJECTS AND VARIABLES
TM1637Display display(clkPin, dioPin);
unsigned long startTime;
unsigned long currentTime;
unsigned long elapsedTime;
bool resetButtonPressed = false;
// SETUP THE DISPLAY AND START THE COUNTING
void setup() {
    display.setBrightness(7); 
    display.clear(); 
    pinMode(resetButton, INPUT_PULLUP); 
    startTime = millis(); 
}

void loop() {
   // Bunch of ifs to countdown  and then  reset:
    if (digitalRead(resetButton) == LOW) {
        resetButtonPressed = true;
    }

    if (!resetButtonPressed) {
        currentTime = millis(); 
        elapsedTime = (currentTime - startTime) / 1000; 

        if (elapsedTime <= countdownTime) {
            unsigned long remainingTime = countdownTime - elapsedTime;
            unsigned int minutes = remainingTime / 60;
            unsigned int seconds = remainingTime % 60;
            display.showNumberDecEx(minutes * 100 + seconds, 0b01000000, true);

            if (remainingTime == 0) {
                // Start blinking when countdown reaches 00:00
                while (true) {
                    display.showNumberDecEx(0, 0b01000000, true); 
                    delay(500);
                    display.clear(); 
                    delay(500);
                }
            }
        }
    } else {
       
        display.clear();
        resetButtonPressed = false;
        startTime = millis();
    }

    delay(1000); 
}
