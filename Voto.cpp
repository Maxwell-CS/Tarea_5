//
// Created by maxwe on 11/06/2026.
//

#include "Voto.h"
#include "CrearHash.h"

using namespace std;
int Voto::indice_votacion = 0;
Voto::Voto(string cand) {
    indice_votacion ++;
    candidato = cand;
    hash_voto = calcularHashVoto();
}

string Voto::calcularHashVoto() const {
    string datos_unidos = to_string(indice_votacion) + candidato;
    return generarHashSimulado(datos_unidos);
}

int Voto::getIndice() const { return indice_votacion; }
string Voto::getCandidato() const { return candidato; }
string Voto::getHashVoto() const { return hash_voto; }