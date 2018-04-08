#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"

int *leIdades(int nVertices){
    int *vIdades = (int *) malloc((nVertices+1) * sizeof(int));
    int lixo, i;
    for(i = 1;i <= nVertices;i++)
    {
        scanf("%d %d", &lixo, &vIdades[i]);
    }
    return vIdades;
}

int verificaPrimeiro(int *vIdades, int nodeInicial){
    int primeiroGostou = (vIdades[nodeInicial] < 35) ? 1 : 0;
    return primeiroGostou;
}

void dfs(node **Grafo, int nodeAtual, int *nGostaram, int *vNodeVisitados, int *vIdades){
    node *p = Grafo[nodeAtual];
    vNodeVisitados[nodeAtual] = 1;
    while (p != NULL)
    {
        nodeAtual = p->vertice; // age[i-1]
        if (!vNodeVisitados[nodeAtual] && vIdades[nodeAtual] < 35){
            *nGostaram += 1;
            dfs(Grafo, nodeAtual, nGostaram, vNodeVisitados, vIdades);
        }
        p = p->prox;
    }
}

void liberaGrafo(node **Grafo, int nVertices){
    int i;
    for (i = 0; i <= nVertices; i++)
    {
        node *p = Grafo[i];
        while(p != NULL){
            p = p->prox;
        }
        free(p);
    }
    free(Grafo);
}

int main(int argc, char *argv[]){
    int nodeInicial, nVertices, nArestas;
    scanf("%d %d", &nVertices, &nArestas);
    int *vIdades = leIdades(nVertices);
    node **Grafo = leGrafo(nVertices, nArestas);
    //imprimeGrafo(Grafo);
    scanf("%d", &nodeInicial);
    int nGostaram = 0;
    int *vNodeVisitados = (int*) malloc(nVertices * sizeof(int));
    memset(vNodeVisitados, 0, (size_t) nVertices);
    dfs(Grafo, nodeInicial, &nGostaram, vNodeVisitados, vIdades);
    nGostaram += verificaPrimeiro(vIdades, nodeInicial);
    liberaGrafo(Grafo, nVertices);
    free(vNodeVisitados);
    free(vIdades);
    printf("%d", nGostaram);
    return 0;
}
