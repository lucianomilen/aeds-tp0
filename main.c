#include "grafo.h"

int main(int argc, char *argv[]){
        int nodeInicial, nVertices, nArestas;
        scanf("%d %d", &nVertices, &nArestas);
        int *vIdades = leIdades(nVertices); // lê entrada de idades dos usuários
        node **Grafo = leGrafo(nVertices, nArestas); //inicializa o grafo com a memória necessária a partir de nVertices
        scanf("%d", &nodeInicial);
        int nGostaram = 0;
        int *vNodeVisitados = (int*) malloc((nVertices + 1) * sizeof(int)); //vetor para armazenar nós visitados pelo DFS
        memset(vNodeVisitados, 0, (size_t) (nVertices + 1)); //inicializa o vetor de nós visitados como 0
        DFS(Grafo, nodeInicial, &nGostaram, vNodeVisitados, vIdades); //faz busca em profundidade no grafo
        nGostaram += verificaPrimeiro(vIdades, nodeInicial); //devemos contabilizar também o nó inicial se idade < 35
        liberaGrafo(Grafo, nVertices); //libera memória alocada pro grafo
        free(vNodeVisitados);
        free(vIdades);
        printf("%d", nGostaram); // imprime resultado final
        return 0;
}
