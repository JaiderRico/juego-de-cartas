#include "Juego.h"
#include "Ronda.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

Juego::Juego(vector<string> nombres, int cartasPorColor) : cartasPorColor(cartasPorColor) {
    for (size_t i = 0; i < nombres.size(); i++) {
        jugadores.emplace_back(nombres[i]);
    }
    generarMazo();
    repartirCartas();
}

void Juego::generarMazo() {
    vector<string> colores = {"Rojo", "Azul", "Verde", "Amarillo"};
    srand(time(0));
    for (auto& color : colores) {
        for (int i = 1; i <= cartasPorColor; i++) {
            mazo.emplace_back(i, color);
        }
    }
    random_shuffle(mazo.begin(), mazo.end());
}

void Juego::repartirCartas() {
    int numJugadores = jugadores.size();
    int cartasPorJugador = mazo.size() / numJugadores;
    for (int i = 0; i < cartasPorJugador * numJugadores; i++) {
        jugadores[i % numJugadores].agregarCarta(mazo[i]);
    }
}

void Juego::jugar() {
    int rondas = jugadores[0].mano.size();
    for (int i = 0; i < rondas; i++) {
        cout << "\n===== Ronda " << i + 1 << " =====" << endl;
        int indiceInicio = i % jugadores.size();
        Jugador* jugadorInicio = &jugadores[indiceInicio];
        Carta cartaInicial;
        if (!jugadorInicio->mano.empty()) {
            cout << "\n" << jugadorInicio->nombre << ", es tu turno para iniciar la ronda." << endl;
            cout << "Tu mano:" << endl;
            for (size_t j = 0; j < jugadorInicio->mano.size(); j++) {
                cout << j << ": " << jugadorInicio->mano[j].numero << " " 
                     << jugadorInicio->mano[j].color << endl;
            }
            int idx;
            cout << "Elige el índice de la carta a jugar como carta inicial: ";
            cin >> idx;
            while(idx < 0 || idx >= (int)jugadorInicio->mano.size()) {
                cout << "Índice inválido. Intenta de nuevo: ";
                cin >> idx;
            }
            cartaInicial = jugadorInicio->jugarCarta(idx);
        } else {
            continue;
        }

        // Reorganiza el vector de punteros para la ronda
        vector<Jugador*> jugadoresPtr;
        int total = jugadores.size();
        for (int j = 0; j < total; j++) {
            int idx = (indiceInicio + j) % total;
            jugadoresPtr.push_back(&jugadores[idx]);
        }

        Ronda ronda(jugadoresPtr, cartaInicial);
        ronda.jugarTurno();
    }
    determinarGanador();
}

void Juego::determinarGanador() {
    auto it = max_element(jugadores.begin(), jugadores.end(),
        [](Jugador a, Jugador b) { return a.acumulador.size() < b.acumulador.size(); });
    cout << "===== Ganador final: " << it->nombre << " con " 
         << it->acumulador.size() << " cartas acumuladas! =====" << endl;
}
