//
// Created by maxwe on 11/06/2026.
//

#ifndef TAREA_5_VOTO_H
#define TAREA_5_VOTO_H

#pragma once
#include <string>

using namespace std;

class Voto {
private:
    static int indice_votacion;
    string candidato;
    string hash_voto;

    string calcularHashVoto() const;

public:
    Voto(string cand);

    int getIndice() const;
    string getCandidato() const;
    string getHashVoto() const;
};

#endif //TAREA_5_VOTO_H