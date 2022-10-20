// Minimum Working Example (for Arduino) - DemoDriver uses the same structure

#include <FSRButton.h>

#define FSRPin A0  // Pin where the sensor is connected to (A0)

FSRButton fsr(FSRPin, 75); // instance of the FSRButton object, 75% set as press/release threshold (50 default) MIN:0 MAX:100

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

