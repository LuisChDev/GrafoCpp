#include <iostream>
#include "Busquedas.hpp"

using namespace std;

/**
 * stack implementado sobre un arreglo.
 */
struct stack {
  int top;
  int capacity;
  int array[MAXGRAPH];
};

/**
 * funciones push y pop del stack.
 */
void push(int nodo, stack &pila) {
  if (pila.top + 1 < pila.capacity) {
    pila.top++;
    pila.array[pila.top] = nodo;
  } else {
    cout << "Error: stack overflow" << endl;
  }
}

int pop(stack &pila) {
  if (pila.top - 1 >= 0) {
    int valor = pila.array[pila.top];
    pila.top--;
    return valor;
  } else {
    cout << "Error: stack underflow" << endl;
    return 0;
  }
}

/**
 * fila implementada sobre un arreglo.
 */
struct queue {
  int top;
  int bottom;
  int capacity;
  int array[MAXGRAPH];
};

/**
 * implementación de enqueue y dequeue.
 */
void enqueue(int nodo, queue &fila) {
  if ((fila.top + 1) % fila.capacity != fila.bottom) {
    fila.array[fila.top] = nodo;
    fila.top = (fila.top + 1) % fila.capacity;
  } else {
    cout << "Error: fila llena" << endl;
  }
}

int dequeue(queue &fila) {
  if ((fila.bottom + 1) % fila.capacity != fila.top + 1) {
    int valor = fila.array[fila.bottom];
    fila.array[fila.bottom] = 0;
    fila.bottom = (fila.bottom + 1) % fila.capacity;
    return valor;
  } else {
    cout << "Error: fila vacía" << endl;
    return 0;
  }
}
/**
 * busca un elemento en el arreglo dado.
 */
bool isIn(int buscado, int lista[MAXGRAPH]) {
  for (int i = 0; i < MAXGRAPH; i++) {
    if (buscado == lista[i]) {
      return true;
    }
  }
  return false;
}

/**
 * recorrido del grafo en profundidad.
 * imprime los nodos en el orden que son visitados.
 * toma como argumento el nodo inicial.
 * visita los nodos en el orden que aparezcan en la implementación.
 */
void DFS(int inicial, int grafo[MAXGRAPH][MAXGRAPH]) {
  // stack auxiliar.
  // se implementa como un arreglo.
  stack aux {
    aux.top = 0,
    aux.capacity = MAXGRAPH };
  push(inicial, aux);

  // arreglo donde se guardarán los nodos ya visitados.
  int visitados[MAXGRAPH] = {0};
  int actual = 0;

  // mientras el stack tenga elementos:
  while(aux.top > 0) {
    int current = pop(aux);
    // si no ha sido leído:
    if (!isIn(current, visitados)) {
      // se agrega a la lista.
      visitados[actual] = current;
      actual++;
      // se imprime.
      cout << current << " - ";
      // cada nodo que tenga una conexión con este,
      // y no ha sido visitado, se añade al stack.
      for (int i = 0; i < MAXGRAPH; i++) {
        int nodo = arcoNodos(current, grafo[0][i], grafo);
        if (nodo != 0 && !isIn(grafo[0][i], visitados)) {
          push(grafo[0][i], aux);
        }
      }
    }
  }
  cout << endl;
}


/**
 * recorrido del grafo en anchura.
 * imprime los nodos en el orden que son visitados.
 * toma como argumento el nodo inicial.
 * los nodos son visitados en el orden en que aparezcan en la implementación.
 */
void BFS (int inicial, int grafo[MAXGRAPH][MAXGRAPH]) {
  // fila auxiliar.
  queue aux {
    aux.top = 0,
    aux.bottom = 0,
    aux.capacity = MAXGRAPH };
  enqueue(inicial, aux);

  // lista con los nodos ya visitados.
  int visitados[MAXGRAPH] = {0};
  int actual = 0;

  // mientras la fila tenga nodos:
  while(aux.top != aux.bottom) {
    // se toma el primero de la fila
    int current = dequeue(aux);
    // se visita
    visitados[actual] = current;
    actual++;
    cout << current << " - ";
    // se añaden todos los nodos vecinos que no han sido visitados a la fila.
    for (int i = 0; i < MAXGRAPH; i++) {
      int nodo = arcoNodos(current, grafo[0][i], grafo);
      if (nodo != 0 && !isIn(grafo[0][i], visitados)) {
        enqueue(grafo[0][i], aux);
      }
    }
  }
  cout << endl;
}

