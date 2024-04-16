#pragma once

#include <stdint.h>

/**
 * Kody klawiszy.
 */
enum KEY {
	KEY_NONE, ///< Żaden klawisz nie jest wciśnięty.
	KEY_SELECT, ///< Wciśnięty klawisz SELECT.
	KEY_LEFT, ///< Wciśnięty klawisz LEFT.
	KEY_DOWN, ///< Wciśnięty klawisz DOWN.
	KEY_UP, ///< Wciśnięty klawisz UP.
	KEY_RIGHT, ///< Wciśnięty klawisz RIGHT.
};

/**
 * Sterownik klawiatury analogowej.
 */
struct Keypad {
	/**
	 * Inicjalizacja klawiatury.
	 */
	void initialize() const;

	/**
	 * Wykonuje pomiar.
	 *
	 * @return Wartość pomiaru.
	 */
	uint16_t measure();

	/**
	 * Sprawdza, który klawisz jest aktualnie wciśnięty.
	 *
	 * @return Kod aktualnie wciśniętego klawisza.
	 */
	KEY currentKey() const;

	/**
	 * Sprawdza, czy nastąpiła zmiana stanu klawiatury.
	 *
	 * @return Kod klawisza, jeżeli zmienił się stan klawiatury. W innym przypadku kod braku klawisza.
	 */
	KEY oneTimeKey();

private:
	uint16_t measurement{1023}; ///< Wynik ostatniego pomiaru.
	KEY lastKey{KEY_NONE}; ///< Ostatnio wciśnięty klawisz.
};

/**
 * Instancja sterownika klawiatury.
 */
extern Keypad keypad;
