/*
 * Trabalho 3 - Desbravo Bros.
 *
 * GEN505 - Grafos - 2026/1
 *
 * Nome:      Bruno Vendruscolo
 * Matricula: 222110004
 */

#ifndef DIGRAFO_H

#define DIGRAFO_H

#include "Aresta.h"
#include <vector>

class Grafo {
public:

    Grafo(int num_vertices);

    int num_vertices();
    int num_arestas();

    bool tem_aresta(Aresta e);


    void insere_aresta(Aresta e);

    bool bellman_ford(int s, std::vector<int> &pai, std::vector<int> &dp);
    
    void min_vidas(int s);

    void imprime();
    
private:
    int num_vertices_;
    int num_arestas_;
    std::vector<std::vector<int>> matriz_adj_;
};

#endif /* DIGRAFO_H */