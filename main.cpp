#include <iostream>
#include "Internal.hpp"
#include "Busquedas.hpp"

using namespace std;

// Autor: Luis Eduardo Chavarriaga - T00056784

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
      break;

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
