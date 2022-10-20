#ifndef FSRButton_h
#define FSRButton_h

#include <Arduino.h>

#define COUNT_FALLING 0
#define COUNT_RISING  1
#define COUNT_BOTH    2

class FSRButton
{
	private:
		int btnPin;
		int trigger;
		unsigned long debounceTime;
		unsigned long count;
		int countMode;

		int rawState;
		int previousSteadyState; 
		int lastSteadyState;
		int lastFlickerableState;

		unsigned long lastDebounceTime;

	public:
		FSRButton(int pin, int threshold);
		void setDebounceTime(unsigned long time);
		int getState(void);
		int getStateRaw(void);
		int getRawAnalogRead(void);
		int getRawAnalogReadPercent(void);
		bool isPressed(void);
		bool isReleased(void);
		void setCountMode(int mode);
		void setThreshold(int threshold);
		unsigned long getCount(void);
		void resetCount(void);
		void loop(void);
};

#endif
