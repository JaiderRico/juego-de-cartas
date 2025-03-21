#include "Ronda.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using namespace std;

Ronda::Ronda(vector<Jugador*>& jugadores, Carta cartaInicial)
    : jugadores(jugadores), cartaInicial(cartaInicial), ganador(nullptr) {}

void Ronda::jugarTurno() {
    vector<Carta> cartasJugadas;
    vector<Jugador*> jugadoresValidos;

    // El jugador que inició ya jugó su carta (cartaInicial)
    cartasJugadas.push_back(cartaInicial);
    jugadoresValidos.push_back(jugadores[0]);

    // Cada uno de los otros jugadores juega una carta (se solicita manualmente)
    for (size_t i = 1; i < jugadores.size(); i++) {
        Jugador* jugador = jugadores[i];
        if (jugador->mano.empty()) {
            cout << jugador->nombre << " no tiene cartas y queda fuera de la ronda." << endl;
            continue;
        }

        // Muestra la mano del jugador
        cout << "\n" << jugador->nombre << ", tu mano:" << endl;
        for (size_t j = 0; j < jugador->mano.size(); j++) {
            cout << j << ": " << jugador->mano[j].numero 
                 << " " << jugador->mano[j].color << endl;
        }
        int idx;
        cout << "Elige el índice de la carta a jugar: ";
        cin >> idx;
        while(idx < 0 || idx >= (int)jugador->mano.size()) {
            cout << "Índice inválido. Intenta de nuevo: ";
            cin >> idx;
        }
        Carta cartaJug = jugador->jugarCarta(idx);
        cout << jugador->nombre << " juega: " 
             << cartaJug.numero << " " << cartaJug.color << endl;
        cartasJugadas.push_back(cartaJug);
        jugadoresValidos.push_back(jugador);
    }

    // Se determina el ganador de la ronda (carta con mayor número)
    if (!cartasJugadas.empty()) {
        auto maxIt = max_element(cartasJugadas.begin(), cartasJugadas.end(),
            [](Carta a, Carta b) { return a.numero < b.numero; });
        int index = distance(cartasJugadas.begin(), maxIt);
        ganador = jugadoresValidos[index];

        // El ganador acumula todas las cartas jugadas
        ganador->acumulador.insert(ganador->acumulador.end(), cartasJugadas.begin(), cartasJugadas.end());
        cout << "\nGanador de la ronda: " << ganador->nombre << "\n" << endl;
    }
}
