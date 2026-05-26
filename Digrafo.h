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
    /** Constroi um grafo simples que possui o numero de vertices recebido por
     *  parametro e que nao possui arestas */
    Grafo(int num_vertices);

    int num_vertices();
    int num_arestas();

    bool tem_aresta(Aresta e);

    /** Insere uma aresta no grafo caso a aresta ainda nao exista no grafo e
     *  nao seja um laco */
    void insere_aresta(Aresta e);

    // bool caminho(int v, int w, int ind, int marcado[]);
    // bool caminho_restrito(int v, int w, int t, int z, int marcado[]);
    bool bellman_ford(int s, std::vector<int> &pai, std::vector<int> &dp);

    void imprime();
    
private:
    int num_vertices_;
    int num_arestas_;
    std::vector<std::vector<int>> matriz_adj_;
};

#endif /* GRAFO_H */
