#include <iostream>
#include "Voto.h"
#include "Block.h"
#include "Blockchain.h"
#include "MesaElectoral.h"
#include "CentroElectoralSubject.h"
using namespace std;

int main() {
    Blockchain* blockchain = Blockchain::getInstancia();

    MesaElectoral mesa1("Mesa 1 - Lima");
    MesaElectoral mesa2("Mesa 2 - Cusco");
    MesaElectoral mesa3("Mesa 3 - Arequipa");

    CentroElectoralSubject red;
    red.attach(&mesa1);
    red.attach(&mesa2);
    red.attach(&mesa3);

    vector<Voto> votos1 = {
        Voto("001", "Candidato A"),
        Voto("002", "Candidato B"),
        Voto("003", "Candidato A"),
    };

    Block bloque1(1, blockchain->getUltimoBloque().getHash(), votos1);
    blockchain->mineBlock(bloque1);

    cout << "Hash bloque 1: " << bloque1.getHash() << endl << endl;

    cout << "Bloque 1 minado -> Notificando a las mesas" << endl;
    red.notificarNuevoBloque(bloque1);

    vector<Voto> votos2 = {
        Voto("004", "Candidato B"),
        Voto("005", "Candidato A"),
    };

    Block bloque2(2, bloque1.getHash(), votos2);
    blockchain->mineBlock(bloque2);

    cout << endl << "Hash bloque 2: " << bloque2.getHash() << endl << endl;

    cout << "Bloque 2 minado -> Notificando a las mesas" << endl;
    red.notificarNuevoBloque(bloque2);

    cout << endl << "Estado final: " << endl;
    mesa1.mostrarCantidadBloques();
    mesa2.mostrarCantidadBloques();
    mesa3.mostrarCantidadBloques();

    return 0;
}