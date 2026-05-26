/*
 * Trabalho 3 - Desbravo Bros.
 *
 * GEN505 - Grafos - 2026/1
 *
 * Nome:      Bruno Vendruscolo
 * Matricula: 222110004
 */

#include "Digrafo.h"
#include <iostream>

using namespace std;

int main() {
        int Regiao;
        int Cano;
        int X;
        int Y;
        int D;
        int O;
        int Z;
        cin >> Regiao >> Cano;


        Grafo g(Regiao);
        for (int i = 0; i < Cano; i++) {
            cin >> X >> Y >> D;
            g.insere_aresta(Aresta(X, Y, D));
        }
        cin >> O;
        
        if (O > -1){
        for (int i = 0; i <= O; i++){
            cin >> Z;
            std::vector<int> dp(g.num_vertices());
            std::vector<int> pai(g.num_vertices());
            g.bellman_ford(Z, pai, dp);

        }}
        else throw(runtime_error("O valor deve ser maior ou igual a zero"));

    return 0;
}
