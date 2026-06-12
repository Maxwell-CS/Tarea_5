#include "Blockchain.h"

Blockchain* Blockchain::instancia = nullptr;

Blockchain::Blockchain() {
    dificultad = 2;
    crearBloqueGenesis();
}

Blockchain* Blockchain::getInstancia() {
    if (instancia == nullptr) {
        instancia = new Blockchain();
    }
    return instancia;
}

void Blockchain::setDificultad(int d) {
    dificultad = d;
}

void Blockchain::crearBloqueGenesis() {
    Block genesis(0, "0", {});
    mineBlock(genesis);
    cadena.push_back(genesis);
}

void Blockchain::mineBlock(Block& bloque) {
    while (true) {
        std::string hash = bloque.calcularHashBloque();
        bool valido = true;
        for (int i = 0; i < dificultad; i++) {
            if (hash[i] != '0') {
                valido = false;
                break;
            }
        }
        if (valido) {
            bloque.setCurrentHash(hash);
            return;
        }
        bloque.setNonce(bloque.getNonce() + 1);
    }
}

void Blockchain::agregarBloque(Block bloque) {
    cadena.push_back(bloque);
}

bool Blockchain::isChainValid() {
    for (size_t i = 1; i < cadena.size(); i++) {
        Block& actual = cadena[i];
        Block& anterior = cadena[i - 1];

        if (actual.getHash() != actual.calcularHashBloque()) {
            return false;
        }
        if (actual.getPreviousHash() != anterior.getHash()) {
            return false;
        }
    }
    return true;
}

Block Blockchain::getUltimoBloque() {
    return cadena.back();
}

std::vector<Block> Blockchain::getCadena() {
    return cadena;
}
