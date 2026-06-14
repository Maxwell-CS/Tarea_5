#ifndef MESAELECTORALOBSERVER_H
#define MESAELECTORALOBSERVER_H

#pragma once
#include "Block.h"

class MesaElectoralObserver {
public:
    virtual void update(const Block& nuevoBloque) = 0;
    virtual ~MesaElectoralObserver() = default;
};

#endif //MESAELECTORALOBSERVER_H
