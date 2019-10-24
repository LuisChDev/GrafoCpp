#include <iostream>
#include <limits>
#define MAXGRAPH 21
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
          cout << " ->"<< y + 1 << ": " << grafo[x][y] << ", ";
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
  grafo[nodo1 - 1][nodo2 - 1] = arco;
}

/**
 * elimina un nodo del arco.
 */
void deleteArch (int nodo1, int nodo2, int grafo[MAXGRAPH][MAXGRAPH]) {
  grafo[nodo1 - 1][nodo2 - 1] = 0;
}


/**
 * Verifica si existe un arco entre dos nodos dados.
 */
int arcoNodos(int nodo1, int nodo2, int grafo[MAXGRAPH][MAXGRAPH]) {
  return grafo[nodo1 - 1][nodo2 - 1];
}


int main() {
  // declarando el grafo
  // se declara como matriz aprovechando el máximo de 20 nodos
  // impuesto por el ejercicio.
  // la primera fila y columna almacenan el valor del nodo.
  int grafo[MAXGRAPH][MAXGRAPH];
  grafo[0][0] = 0; // este valor no está definido

  // se inicializa el grafo, todo en cero.
  for (int x = 0; x < MAXGRAPH; x++) {
    for (int y = 0; y < MAXGRAPH; y++) {
      grafo[x][y] = 0;
    }
  }

  // opción del usuario
  int option, input, input2, input3;

  cout << "bienvenido al programa." << endl;
  cout << "Ingrese 1 para imprimir el grafo." << endl;
  cout << "Ingrese 2 para insertar un nodo." << endl;
  cout << "Ingrese 3 para eliminar un nodo." << endl;
  cout << "Ingrese 4 para insertar un arco." << endl;
  cout << "Ingrese 5 para eliminar un arco." << endl;
  cout << "Ingrese 6 para averiguar si un arco existe." << endl;
  cout << "ingrese 7 para ver todos los valores." << endl;
  cout << "Ingrese 8 para salir." << endl;

  do {
    cout << "Ingrese su comando." << endl;
    cin >> option;

    switch (option) {
    case 1:
      printGraph(grafo);
      break;

    case 2:
      cout << "por favor inserte el valor del nodo: " << endl;
      cin >> input;
      insertNode(input, grafo);
      break;

    case 3:
      cout << "por favor ingrese el nodo a eliminar: " << endl;
      cin >> input;
      removeNode(input, grafo);

    case 4:
      cout << "por favor ingrese el primer nodo: " << endl;
      cin >> input;
      cout << "por favor ingrese el segundo nodo: " << endl;
      cin >> input2;
      cout << "por último, ingrese el valor del arco: " << endl;
      cin >> input3;
      insertArch(input, input2, input3, grafo);
      break;

    case 5:
      cout << "por favor, ingrese el valor del primer nodo: " << endl;
      cin >> input;
      cout << "por favor, ingrese el valor del segundo nodo: " << endl;
      cin >> input2;
      deleteArch(input, input2, grafo);
      break;

    case 6:
      cout << "inserte el primer nodo: " << endl;
      cin >> input;
      cout << "inserte el segundo nodo: " << endl;
      cin >> input2;
      input3 = arcoNodos(input, input2, grafo);
      if (input3 == 0) {
        cout << "lo sentimos, este arco no existe." << endl;
      } else {
        cout << "El arco existe y tiene valor de " << input3 << endl;
      }
      break;

    case 7:
      printAll(grafo);
      break;

    default:
      cout << "Esta opción no es válida. Ingrese una opción válida." << endl;
      cin.clear();
      cin.ignore();
    }
  } while (option != 8);
  cout << "gracias por usar el programa." << endl;
  return 0;
}

// numeric_limits<streamsize>::max()
