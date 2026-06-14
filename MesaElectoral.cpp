#include "MesaElectoral.h"
#include <iostream>
using namespace std;

MesaElectoral::MesaElectoral(string nombreMesa) {
    nombre = nombreMesa;
}

void MesaElectoral::update(const Block& nuevoBloque) {
    cout << nombre << " recibio el bloque " << nuevoBloque.getIndex() << endl;
    blockchainLocal.push_back(nuevoBloque);
}

void MesaElectoral::mostrarCantidadBloques() const {
    cout << nombre << " tiene " << blockchainLocal.size() << " bloques" << endl;
}