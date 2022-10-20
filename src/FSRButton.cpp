#include <FSRButton.h>

FSRButton::FSRButton(int pin, int threshold = 50)
{
	btnPin = pin;
	trigger = threshold;
	debounceTime = 0;
	count = 0;
	countMode = COUNT_FALLING;

	previousSteadyState = getStateRaw();
	lastSteadyState = previousSteadyState;
	lastFlickerableState = previousSteadyState;
	lastDebounceTime = 0;
}

void FSRButton::setDebounceTime(unsigned long time)
{
	debounceTime = time;
}

int FSRButton::getState(void)
{
	return lastSteadyState;
}

int FSRButton::getRawAnalogRead(void){
	return analogRead(btnPin);
}

int FSRButton::getRawAnalogReadPercent(void){
	int percent = map(getRawAnalogRead(), 0, 1023, 0, 100);
	return percent;
}

int FSRButton::getStateRaw(void)
{
	int state;
	rawState = getRawAnalogReadPercent();
	if (rawState < trigger){
		state = 0;
	} else {
		state = 1;
	}
	return state;
}

void FSRButton::setThreshold(int threshold){
	trigger = threshold;
}

bool FSRButton::isPressed(void)
{
	if (previousSteadyState == LOW && lastSteadyState == HIGH)
		return true;
	else
		return false;
}

bool FSRButton::isReleased(void)
{
	if (previousSteadyState == HIGH && lastSteadyState == LOW)
		return true;
	else
		return false;
}

void FSRButton::setCountMode(int mode)
{
	countMode = mode;
}

unsigned long FSRButton::getCount(void)
{
	return count;
}

void FSRButton::resetCount(void)
{
	count = 0;
}

void FSRButton::loop(void)
{
	int currentState = getStateRaw();

	unsigned long currentTime = millis();

	if (currentState != lastFlickerableState)
	{
		lastDebounceTime = currentTime;
		lastFlickerableState = currentState;
	}

	if ((currentTime - lastDebounceTime) >= debounceTime)
	{
		previousSteadyState = lastSteadyState;
		lastSteadyState = currentState;
	}

	if (previousSteadyState != lastSteadyState)
	{
		if (countMode == COUNT_BOTH)
			count++;
		else if (countMode == COUNT_FALLING)
		{
			if (previousSteadyState == HIGH && lastSteadyState == LOW)
				count++;
		}
		else if (countMode == COUNT_RISING)
		{
			if (previousSteadyState == LOW && lastSteadyState == HIGH)
				count++;
		}
	}
}
