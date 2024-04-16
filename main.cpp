#include "keypad.hpp"
#include "lcdDisplay.hpp"

#include <stdio.h>

/**
 * Wykonuje pomiar klawiatury i wyświetla go.
 */
void printMeasure()
{
	char buf[16];
}

/**
 * Wyświetla bieżący klawisz.
 */
void printKey()
{
}

/**
 * Obsługuje licznik.
 */
void handleCounter()
{
	static int16_t counter;
	char buf[16];
}

/**
 * Funkcja główna.
 */
int main()
{
	lcdDisplay.initialize();
	keypad.initialize();

	lcdDisplay.goTo(0, 0);
	lcdDisplay.write("ADC:");

	lcdDisplay.goTo(0, 9);
	lcdDisplay.write("K:");

	lcdDisplay.goTo(1, 0);
	lcdDisplay.write("COUNTER:");

	while (true) {
		printMeasure();
		printKey();
		handleCounter();
	}
}
