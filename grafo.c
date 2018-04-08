#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

node **leGrafo(int nVertices, int nArestas)
{
    int i, vi, vj;

    node **Grafo = (node **)malloc((nVertices + 1) * sizeof(node *));

    for (i = 0; i <= nVertices; i++)
    {
        Grafo[i] = (node *)malloc(sizeof(node));
        Grafo[i]->prox = NULL;
        Grafo[i]->vertice = -5;
    }

    for (i = 0; i < nArestas; i++)
    {
        scanf("%d %d", &vi, &vj);
        insere(vi, vj, Grafo);
        insere(vj, vi, Grafo);
    }
    //imprimeGrafo(Grafo, nVertices);
    return Grafo;
}

void imprimeGrafo(node **Grafo, int n)
{
    int j;
    for (j = 1; j <= n; j++)
    {
        node *i = Grafo[j];
        while (i != NULL)
        {
            printf("\n%d vertice %d\n", j, i->vertice);
            i = i->prox;
        }
    }
}

void insere(int vi, int vj, node **Grafo)
{
    node *i, *j;

    j = (node *)malloc(sizeof(node));
    j->vertice = vj;
    j->prox = NULL;

    if (Grafo[vi]->vertice == -5)
    {
        Grafo[vi] = j;
    }

    else
    {
        i = Grafo[vi];
        while (i->prox != NULL)
            i = i->prox;
        i->prox = j;
    }
    //free(j);
}
