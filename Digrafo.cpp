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
#include <limits>

using namespace std;

Grafo::Grafo(int num_vertices) {
    num_vertices_ = num_vertices;
    num_arestas_ = 0;

    matriz_adj_.resize(num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        matriz_adj_[i].resize(num_vertices, 0);
    }
}

int Grafo::num_vertices() {
    return num_vertices_;
}

int Grafo::num_arestas() {
    return num_arestas_;
}

bool Grafo::tem_aresta(Aresta e) {
    if (matriz_adj_[e.v1][e.v2] != 0) {
        return true;
    }
    return false;
}

void Grafo::insere_aresta(Aresta e) {
    if (!tem_aresta(e) && (e.v1 != e.v2)) {
        matriz_adj_[e.v1][e.v2] = e.peso;
        num_arestas_++;
    }
}

void Grafo::imprime() {
    cout << "Grafo:\n";
    for (int i = 0; i < num_vertices_; i++) {
        cout << i << ":";
        for (int j = 0; j < num_vertices_; j++) {
            if (matriz_adj_[i][j] != 0) {
                cout << " " << j;
            }
        }
        cout << "\n";
    }
}

bool Grafo::bellman_ford(int s, vector<int> &pai, vector<int> &dp) {
    int INF = numeric_limits<int>::max() / 2;

    for(int w = 0; w < num_vertices_; w++){
        dp[w] = INF;
        pai[w] = -1;
    }
    dp[s] = 0;

    for(int i = 0; i < num_vertices_ - 1; i++){
        for(int u = 0; u < num_vertices_; u++){
            for(int v = 0; v < num_vertices_; v++){
                if (matriz_adj_[u][v] != 0 && dp[u] != INF && dp[u] + matriz_adj_[u][v] < dp[v]){
                    dp[v] = dp[u] + matriz_adj_[u][v];
                    pai[v] = u;
                }
            }
        }
    }

    for(int u = 0; u < num_vertices_; u++){
        for(int v = 0; v < num_vertices_; v++){
            if (matriz_adj_[u][v] != 0 && dp[u] != INF && dp[u] + matriz_adj_[u][v] < dp[v]){
                return false; 
            }
        }
    }
    return true;
}

void Grafo::min_vidas(int s) {
    vector<int> dp(num_vertices_);
    vector<int> pai(num_vertices_);

    if (!bellman_ford(s, pai, dp)) {
        cout << s << ": ilimitada\n";
    } else {
        int min_v = 0; 
        int INF = numeric_limits<int>::max() / 2;
        
        for (int i = 0; i < num_vertices_; i++) {
            if (dp[i] != INF && dp[i] < min_v) {
                min_v = dp[i];
            }
        }
        cout << s << ": " << min_v << "\n";
    }
}