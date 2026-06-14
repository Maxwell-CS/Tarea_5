#pragma once
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

inline string generarHashSimulado(const string& input) {
    string resultado_hash = "";
    unsigned long acumulador = 5381; //valor inicial del hash

    for (size_t i = 0; i < input.length(); i++) {
        acumulador = ((acumulador << 5) + acumulador) ^ (unsigned char)input[i];
    }

    for (int indice = 0; indice < 16; indice++) {
        acumulador = ((acumulador << 5) + acumulador) ^ (indice * 31 + 7);
        stringstream ss;
        ss << hex << setw(2) << setfill('0') << (acumulador % 256);
        resultado_hash += ss.str();
    }

    return resultado_hash;
}
