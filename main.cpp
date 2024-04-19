#include "keypad.hpp"
#include "lcdDisplay.hpp"

#include <avr/pgmspace.h>

#include <stdio.h>

/**
 * Lokalizacja wraz ze współrzędnymi.
 */
struct Location {
	const char* name; ///< Nazwa miejscowości.
	float latitude; ///< Szerokość geograficzna północna.
	float longitude; ///< Długość geograficzna wschodnia.
};

/**
 * @defgroup LocationNames Nazwy miejscowości.
 *
 * Nie umieszczamy ich wprost w tablicy, ale za pośrednictwem poniższych zmiennych,
 * gdyż tylko tak można zapewnić ich przechowywanie w pamięci Flash.
 *
 * @{
 */
const char AUGUSTOW[] = "Augustow, podlaskie";
const char GDYNIA[] = "Gdynia, pomorskie - 0123456789";
const char GNIEZNO[] = "Gniezno, wielkopolskie - 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char KRAKOW[] = "Krakow, malopolskie - 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char WARSZAWA[] = "Warszawa, mazowieckie - 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
/**
 * @}
 */

/**
 * Baza danych miejscowości wraz ze współrzędnymi.
 */
const Location LOCATIONS[] = {
	{AUGUSTOW, 53 + 51.0 / 60, 22 + 58.0 / 60},
	{GDYNIA, 54 + 32.0 / 60, 18 + 32.0 / 60},
	{GNIEZNO, 52 + 32.0 / 60, 17 + 36.0 / 60},
	{KRAKOW, 50 + 3.0 / 60, 19 + 57.0 / 60},
	{WARSZAWA, 52 + 12.0 / 60, 21 + 2.0 / 60},
};

constexpr uint8_t DISPLAY_LENGTH{16}; ///< Szerokość wyświetlacza.

/**
 * Mierzy długość napisu w pamięci Flash.
 *
 * @param text Adres tekstu w pamięci Flash.
 *
 * @return Długość tekstu.
 */
size_t flashTextLength(const char* text)
{
	return SIZE_MAX;
}

/**
 * Pętla główna.
 *
 * Obsługuje interfejs urządzenia.
 */
void mainLoop()
{
	static uint8_t locationIndex;
	static size_t textOffset;
	char buf[DISPLAY_LENGTH + 1];

	keypad.measure();
	switch (keypad.oneTimeKey()) {
	case KEY_UP:
		if (locationIndex > 0) {
			locationIndex--;
		}
		textOffset = 0;
		break;
	case KEY_DOWN:
		if (locationIndex < sizeof(LOCATIONS) / sizeof(LOCATIONS[0]) - 1) {
			locationIndex++;
		}
		textOffset = 0;
		break;
	case KEY_SELECT:
		locationIndex = 0;
		textOffset = 0;
		break;
	case KEY_LEFT:
		if (textOffset > 0) {
			textOffset--;
		}
		break;
	case KEY_RIGHT:
		textOffset++;
		break;
	default:
		break;
	}

	lcdDisplay.goTo(0, 0);
	snprintf(buf, sizeof(buf), "%s", LOCATIONS[locationIndex].name);
	lcdDisplay.write(buf);

	lcdDisplay.goTo(1, 0);
	double latitude = LOCATIONS[locationIndex].latitude;
	snprintf(buf, sizeof(buf), "%06.3fN", latitude);
	lcdDisplay.write(buf);

	lcdDisplay.goTo(1, 8);
	double longitude = LOCATIONS[locationIndex].longitude;
	snprintf(buf, sizeof(buf), "%06.3fE", longitude);
	lcdDisplay.write(buf);
}

/**
 * Funkcja główna.
 */
int main()
{
	lcdDisplay.initialize();
	keypad.initialize();

	while (true) {
		mainLoop();
	}
}
