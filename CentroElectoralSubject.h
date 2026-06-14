#ifndef CENTROELECTORALSUBJECT_H
#define CENTROELECTORALSUBJECT_H

#pragma once
#include <vector>
#include "MesaElectoralObserver.h"
#include "Block.h"
using namespace std;

class CentroElectoralSubject {
private:
    vector<MesaElectoralObserver*> observadores;
public:
    void attach(MesaElectoralObserver* mesa);
    void notificarNuevoBloque(
        const Block& bloque
    );
};

#endif //CENTROELECTORALSUBJECT_H
