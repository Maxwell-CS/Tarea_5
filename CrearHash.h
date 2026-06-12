#pragma once
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

inline string generarHashSimulado(const string& input) {
    string resultado_hash = "";
    int mitad = input.length() / 2;

    for (int i = 0; i < input.length(); i++) {
        char caracter = input[i];

        if (i < mitad) {
            caracter = caracter + 24; // Primera mitad: +24 al ASCII
        } else {
            caracter = caracter - 4;  // Segunda mitad: -4 al ASCII
        }

        stringstream ss;
        ss << hex << setw(2) << setfill('0') << (int)(unsigned char)caracter;
        resultado_hash += ss.str();
    }
    
    return resultado_hash;
}