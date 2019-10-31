#ifndef INTERNAL_HPP
#define INTERNAL_HPP

#define MAXGRAPH 21

void printGraph(int grafo[MAXGRAPH][MAXGRAPH]);

void printAll(int grafo[MAXGRAPH][MAXGRAPH]);

void insertNode(int nodo, int grafo[MAXGRAPH][MAXGRAPH]);

void removeNode(int nodo, int grafo[MAXGRAPH][MAXGRAPH]);

void insertArch(int nodo1, int nodo2, int arco,
                int grafo[MAXGRAPH][MAXGRAPH]);

void deleteArch(int nodo1, int nodo2, int grafo[MAXGRAPH][MAXGRAPH]);

int arcoNodos(int nodo1, int nodo2, int grafo[MAXGRAPH][MAXGRAPH]);

bool isInGraph(int nodo, int grafo[MAXGRAPH][MAXGRAPH]);

#endif
