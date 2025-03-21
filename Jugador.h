#ifndef JUGADOR_H
#define JUGADOR_H

#include <vector>
#include "Carta.h"
using namespace std;

class Jugador {
public:
    string nombre;             // Nombre del jugador
    vector<Carta> mano;        // Mano de cartas
    vector<Carta> acumulador;  // Cartas ganadas

    // Constructor
    Jugador(string nom);

    // Métodos
    void agregarCarta(Carta carta);
    Carta jugarCarta(int indice);
};

#endif // JUGADOR_H
