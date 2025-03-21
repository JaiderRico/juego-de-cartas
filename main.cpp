#include <iostream>
#include <vector>
#include <string>
#include "Juego.h"
using namespace std;

int main() {
    int numJugadores;
    int cartasPorColor;

    // Solicitar número de jugadores (entre 2 y 4)
    do {
        cout << "Ingrese el número de jugadores (entre 2 y 4): ";
        cin >> numJugadores;
    } while(numJugadores < 2 || numJugadores > 4);

    // Opciones para la cantidad de cartas por color (5, 10 o 15)
    cout << "Seleccione la cantidad de cartas por color:" << endl;
    cout << "1. 5 cartas" << endl;
    cout << "2. 10 cartas" << endl;
    cout << "3. 15 cartas" << endl;
    int opcion;
    do {
        cout << "Ingrese la opción (1-3): ";
        cin >> opcion;
    } while(opcion < 1 || opcion > 3);

    switch(opcion) {
        case 1: cartasPorColor = 5; break;
        case 2: cartasPorColor = 10; break;
        case 3: cartasPorColor = 15; break;
    }

    // Crear nombres de jugadores
    vector<string> nombres;
    for (int i = 1; i <= numJugadores; i++) {
        nombres.push_back("Jugador " + to_string(i));
    }

    // Crear y ejecutar el juego
    Juego juego(nombres, cartasPorColor);
    juego.jugar();

    return 0;
}
