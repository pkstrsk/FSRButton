// Minimum Working Example (for Arduino) - DemoDriver uses the same structure

#include <FSRButton.h>

#define FSRPin A0  // Pin where the sensor is connected to (A0)

FSRButton fsr(FSRPin, 800); // instance of the FSRButton object, 800 set as press/release threshold (600 default) MIN:0 MAX:1023

void setup(){
    fsr.setDebounceTime(50); // set debounce time to 50 milliseconds
    fsr.setCountMode(COUNT_RISING);  // not necessary for mwe, unless you want to count presses
}

void loop(){
    fsr.loop();
    if (fsr.isPressed()){
        // pressed action
    }
    if (fsr.isReleased()){
        // released action
    }
}

