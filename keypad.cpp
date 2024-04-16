#include "keypad.hpp"

#include "adc.hpp"

Keypad keypad;

uint16_t Keypad::measure()
{
	measurement = adc.measure();
	return measurement;
}

void Keypad::initialize() const
{
	adc.initialize();
}

KEY Keypad::currentKey() const
{
	return KEY_NONE;
}

KEY Keypad::oneTimeKey()
{
	return KEY_NONE;
}
