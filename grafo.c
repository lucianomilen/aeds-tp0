#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int *leIdades(int nVertices)
{
  int *vIdades = (int *) malloc((nVertices+1) * sizeof(int)); //aloca memória pro vetor de idades com a qtd de vertices
  int lixo, i;
  for(i = 1;i <= nVertices;i++)
  {
    scanf("%d %d", &lixo, &vIdades[i]); //motivação pro "lixo": a entrada de idades já é sequencial, não precisa do índice
  }
  return vIdades; //retorna um ponteiro pro vetor de idades
}

node **leGrafo(int nVertices, int nArestas)
{
    int i, vi, vj;

    node **Grafo = (node **)malloc((nVertices + 1) * sizeof(node *)); //aloca memoria para a lista de adj
    //motivação do "nVertices+1": precisamos começar a lista por 1, até nVertices
    for (i = 0; i <= nVertices; i++)
    {
        Grafo[i] = (node *)malloc(sizeof(node)); //aloca memoria pra cada indice da lista de adj
        Grafo[i]->prox = NULL;
        Grafo[i]->vertice = -5; //motivação do "-5": significa para o programa que o vértice ainda não foi atribuido
    }

    for (i = 0; i < nArestas; i++) //lê as arestas
    {
        scanf("%d %d", &vi, &vj);
        insere(vi, vj, Grafo);
        insere(vj, vi, Grafo); //insere bidirecionalmente
    }
    //imprimeGrafo(Grafo, nVertices);
    return Grafo; //retorna ponteiro para o grafo
}

void insere(int vi, int vj, node **Grafo)
{
    node *i, *j;

    j = (node *)malloc(sizeof(node)); //aloca memoria pro novo nó
    j->vertice = vj;
    j->prox = NULL;

    if (Grafo[vi]->vertice == -5) //se o vértice não foi atribuido ainda, podemos inserir o nó na posicao vi
    {
        Grafo[vi] = j;
    }

    else
    {
        i = Grafo[vi]; //caminhamos até a ultima posicao disponivel para inserir o novo nó no atual->prox
        while (i->prox != NULL)
            i = i->prox;
        i->prox = j;
    }
}

void DFS(node **Grafo, int nodeAtual, int *nGostaram, int *vNodeVisitados, int *vIdades)
{
    node *p = Grafo[nodeAtual]; //inicializa um nó p do grafo na posicao atual de busca
    vNodeVisitados[nodeAtual] = 1; //visitamos o nó atual, logo o vetor de nós visitados é atualizado
    while (p != NULL) //percorre o grafo até seu fim
    {
        nodeAtual = p->vertice;
        if (!vNodeVisitados[nodeAtual] && vIdades[nodeAtual] < 35){ //se não visitamos o nó atual e temos sua idade < 35
            *nGostaram += 1; //podemos entrar na sua "árvore", então o nó atual vai gostar da música e compartilhar
            dfs(Grafo, nodeAtual, nGostaram, vNodeVisitados, vIdades); //recursivamente entramos nas adjs do nó
        }
        p = p->prox; //vamos para o próximo nó
    }
  }

int verificaPrimeiro(int *vIdades, int nodeInicial)
{
    int primeiroGostou = (vIdades[nodeInicial] < 35) ? 1 : 0; //o individuo do nó inicial tem < 35 anos?
    return primeiroGostou; //significa que ele vai gostar da musica. se for >=35, não irá gostar
}

void liberaGrafo(node **Grafo, int nVertices)
{
    int i;
    for (i = 0; i <= nVertices; i++) //percorre cada nó liberando memória
    {
        node *p = Grafo[i];
        while(p != NULL){
            p = p->prox;
        }
        free(p);
    }
    free(Grafo); //libera o grafo no geral
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
