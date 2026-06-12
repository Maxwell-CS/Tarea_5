#pragma once
#include <vector>
#include "Block.h"

class Blockchain {
private:
    static Blockchain* instancia;
    std::vector<Block> cadena;
    int dificultad;

    Blockchain();

public:
    static Blockchain* getInstancia();

    void setDificultad(int d);
    void crearBloqueGenesis();
    void mineBlock(Block& bloque);
    void agregarBloque(Block bloque);
    bool isChainValid();
    Block getUltimoBloque();
    std::vector<Block> getCadena();
};
