//
// Created by maxwe on 11/06/2026.
//

#include "Block.h"
#include "CrearHash.h"

using namespace std;

Block::Block(int idx, string prev_hash, vector<Voto> votos) {
    index = idx;
    previous_hash = prev_hash;
    lista_de_votos = votos;
    nonce = 0;
    current_hash = calcularHashBloque();
}

string Block::calcularHashBloque() const {
    string datos_unidos = to_string(index) + previous_hash + to_string(nonce);

    // Sumamos los hashes individuales de cada voto al string principal
    for (size_t i = 0; i < lista_de_votos.size(); i++) {
        datos_unidos += lista_de_votos[i].getHashVoto();
    }

    return generarHashSimulado(datos_unidos);
}

int Block::getIndex() const { return index; }
string Block::getPreviousHash() const { return previous_hash; }
string Block::getHash() const { return current_hash; }
int Block::getNonce() const { return nonce; }

void Block::setNonce(int n) { nonce = n; }
void Block::setCurrentHash(string hash) { current_hash = hash; }