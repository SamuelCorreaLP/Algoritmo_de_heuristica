#ifndef GRAFO_H
#define GRAFO_H

#include "aresta.h"

class XGrafo {
    public:
        XGrafo (int numVertices);
        void insereAresta (int v1, int v2, int peso);
        bool existeAresta (int v1, int v2);
        Aresta* primeiroListaAdj (int v);
        Aresta* proxAdj (int v);
        Aresta* retiraAresta (int v1, int v2);
        int peso (int v1, int v2);
        int tamanho ();
        void imprime ();
        
    private:
        int** m_mat;
        int m_numVertices;
        int* m_pos;
};

#endif