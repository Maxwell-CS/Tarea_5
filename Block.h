

#ifndef TAREA_5_BLOCK_H
#define TAREA_5_BLOCK_H


#pragma once
#include <string>
#include <vector>
#include "Voto.h"

using namespace std;

class Block {
private:
    int index;
    string previous_hash;
    vector<Voto> lista_de_votos;
    int nonce;
    string current_hash;

public:
    Block(int idx, string prev_hash, vector<Voto> votos);

    string calcularHashBloque() const;

    int getIndex() const;
    string getPreviousHash() const;
    string getHash() const;
    int getNonce() const;

    void setNonce(int n);
    void setCurrentHash(string hash);
};


#endif //TAREA_5_BLOCK_H