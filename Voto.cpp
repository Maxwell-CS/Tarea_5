//
// Created by maxwe on 11/06/2026.
//

#include "Voto.h"
#include "CrearHash.h"

using namespace std;

Voto::Voto(string id, string cand) {
    id_votante = id;
    candidato = cand;
    hash_voto = calcularHashVoto();
}

string Voto::calcularHashVoto() const {
    string datos_unidos = id_votante + candidato;
    return generarHashSimulado(datos_unidos);
}

string Voto::getIdVotante() const { return id_votante; }
string Voto::getCandidato() const { return candidato; }
string Voto::getHashVoto() const { return hash_voto; }