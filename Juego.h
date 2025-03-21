#ifndef JUEGO_H
#define JUEGO_H

#include <vector>
#include <string>
#include "Jugador.h"
#include "Carta.h"
using namespace std;

class Juego {
public:
    vector<Jugador> jugadores; // Jugadores
    vector<Carta> mazo;        // Mazo de cartas
    int cartasPorColor;        // Cantidad de cartas por color

    // Constructor
    Juego(vector<string> nombres, int cartasPorColor);

    // Métodos
    void generarMazo();
    void repartirCartas();
    void jugar();
    void determinarGanador();
};

#endif // JUEGO_H
