#ifndef CARTA_H
#define CARTA_H

#include <string>
using namespace std;

class Carta {
public:
    int numero;      // Valor numérico de la carta
    string color;    // Color de la carta

    // Constructores
    Carta();
    Carta(int num, string col);
};

#endif // CARTA_H
