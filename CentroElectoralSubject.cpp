#include "CentroElectoralSubject.h"

void CentroElectoralSubject::attach(MesaElectoralObserver* mesa) {
    observadores.push_back(mesa);
}

void CentroElectoralSubject::notificarNuevoBloque(const Block& bloque) {
    for (auto mesa : observadores) {
        mesa->update(bloque);
    }
}