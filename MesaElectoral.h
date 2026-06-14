#ifndef MESAELECTORAL_H
#define MESAELECTORAL_H

#pragma once
#include <string>
#include <vector>
#include "MesaElectoralObserver.h"
#include "Block.h"
using namespace std;

class MesaElectoral : public MesaElectoralObserver {
private:
    string nombre;
    vector<Block> blockchainLocal;
public:
    MesaElectoral(string nombreMesa);
    void update(const Block& nuevoBloque) override;
    void mostrarCantidadBloques() const;
};

#endif //MESAELECTORAL_H
