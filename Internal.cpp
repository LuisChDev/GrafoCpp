#include <iostream>
#include "Internal.hpp"

using namespace std;

/**
 * imprimir el grafo.
 * por cada fila con valor != 0, imprime las casillas que tengan
 * valor != 0.
 */
void printGraph(int grafo[MAXGRAPH][MAXGRAPH]) {
  for (int x = 1; x < MAXGRAPH; x++) {
    if (grafo[x][0] != 0) {
      cout << "( " << grafo[x][0] << " ): ";
      for (int y = 1; y < MAXGRAPH; y++) {
        if (grafo[x][y] != 0) {
          cout << " ->"<< grafo[0][y] << ": " << grafo[x][y] << ", ";
        }
      }
      cout << "\n";
    }
  }
}

void printAll(int grafo[MAXGRAPH][MAXGRAPH]) {
  for (int x = 0; x < MAXGRAPH; x++) {
    for (int y = 0; y < MAXGRAPH; y++) {
      cout << grafo[x][y] << " ";
    }
    cout << "\n";
  }
}


/**
 * insertar un nodo en el grafo.
 * primero busca el nodo. Si ya existe, no hace nada.
 * el algoritmo busca el primer par fila-columna vacíos que encuentre.
 * Procede a insertar el nodo en el espacio.
 */
void insertNode(int nodo, int grafo[MAXGRAPH][MAXGRAPH]) {
  for (int x = 1; x < MAXGRAPH; x++) {
    if (grafo[x][0] == nodo) {
      cout << "lo sentimos, este nodo ya existe." << endl;
      return;
    }
  }
  for (int x = 1; x < MAXGRAPH; x++) {
    if (grafo[x][0] == 0) {
      if (grafo[0][x] == 0) {
        grafo[x][0] = nodo;
        grafo[0][x] = nodo;
        return;
      }
    }
  }
  cout << "El nodo no se pudo insertar porque no hay espacio." << endl;
}

/**
 * elimina un nodo del grafo.
 * ubica el elemento a eliminar y reemplaza todas las entradas correspondientes
 * por cero.
 */
void removeNode(int nodo, int grafo[MAXGRAPH][MAXGRAPH]) {
  for (int x = 1; x < MAXGRAPH; x++) {
    if (grafo[x][0] == nodo) {
      for (int y = 0; y < MAXGRAPH; y++) {
        grafo[x][y] = 0;
        grafo[y][x] = 0;
      }
      return;
    }
  }
  cout << "El nodo no se pudo eliminar porque no existe." << endl;
}

/**
 * inserta un arco entre dos nodos.
 * si el nodo ya existía, se sobreescribe.
 * insertar un arco con valor 0 es equivalente a eliminarlo.
 */
void insertArch (int nodo1, int nodo2, int arco, int grafo[MAXGRAPH][MAXGRAPH]) {
  for (int x = 0; x < MAXGRAPH; x++) {
    if (grafo[x][0] == nodo1) {
      for (int y = 0; y < MAXGRAPH; y++) {
        if (grafo[0][y] == nodo2) {
          grafo[x][y] = arco;
          return;
        }
      }
      cout << "Lo sentimos, el segundo nodo no se encuentra en el grafo" << endl;
      return;
    }
  }
  cout << "Lo sentimos, el primer nodo no se encuentra en el grafo" << endl;
}

/**
 * elimina un nodo del arco.
 */
void deleteArch (int nodo1, int nodo2, int grafo[MAXGRAPH][MAXGRAPH]) {
  insertArch(nodo1, nodo2, 0, grafo);
}


/**
 * Verifica si existe un arco entre dos nodos dados.
 */
int arcoNodos(int nodo1, int nodo2, int grafo[MAXGRAPH][MAXGRAPH]) {
  for (int x = 0; x < MAXGRAPH; x++) {
    if (grafo[x][0] == nodo1) {
      for (int y = 0; y < MAXGRAPH; y++) {
        if (grafo[0][y] == nodo2) {
          return grafo[x][y];
        }
      }
      cout << "Lo sentimos, el segundo nodo no se encuentra en el grafo"
           << endl;
      return 0;
    }
  }
  cout << "Lo sentimos, el primer nodo no se encuentra en el grafo" << endl;
  return 0;
}
