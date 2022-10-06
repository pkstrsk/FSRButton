## FSRButton Library for Arduino
This library is designed to make it easy to use Force Sensitive Resistor as a button..​. It is easy to use for not only beginners but also experienced users.

__FSRButton__ stands for __Force Sensitive Resistor Button__

Features
----------------------------
* Uses the analogRead function to get a reading from the FSR
* Supports debounce to eliminate the chattering phenomenon
* Supports the pressed and released events
* Supports the counting (for FALLING, RISING and BOTH)
* Easy to use with multiple buttons
* All functions are non-blocking

Available Examples
----------------------------
* [mwe.cpp] Minimum working example

Available Functions
----------------------------
* setDebounceTime()
* getState()
* getStateRaw()
* getRawAnalogRead()
* isPressed()
* isReleased()
* setCountMode()
* setThreshold()
* getCount()
* resetCount()
* loop()

References
----------------------------
Based on ezButton Library
* [ezButton Library Reference](https://arduinogetstarted.com/tutorials/arduino-button-library)
