#include "Carta.h"

// Constructor por defecto
Carta::Carta() : numero(0), color("") {}

// Constructor que inicializa la carta con un número y un color
Carta::Carta(int num, string col) : numero(num), color(col) {}
