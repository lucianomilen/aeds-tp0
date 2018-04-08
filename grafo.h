#ifndef GRAFO
#define GRAFO

typedef struct node
{
    struct node *prox;
    int vertice;
} node;

node **leGrafo(int nVertices, int nArestas);

void insere(int vi, int vj, node **Grafo);

void imprimeGrafo(node **Grafo, int j);

#endif
