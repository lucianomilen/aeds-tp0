#ifndef GRAFO
#define GRAFO

typedef struct node //estrutura recursiva de lista encadeada
{
    struct node *prox;
    int vertice; //identifica o valor do próximo nó
} node;

int *leIdades(int nVertices);

node **leGrafo(int nVertices, int nArestas);

void insere(int vi, int vj, node **Grafo);

void DFS(node **Grafo, int nodeAtual, int *nGostaram, int *vNodeVisitados, int *vIdades);

int verificaPrimeiro(int *vIdades, int nodeInicial);

void liberaGrafo(node **Grafo, int nVertices);

void imprimeGrafo(node **Grafo, int j);

#endif
