#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "abb.h"
#include "abe.h"
#include "nif.h"

void Menu()
{
  cout << "---------- MENU ----------\n";
  cout << "[0] Salir\n";
  cout << "[1] Insertar clave\n";
  cout << "[2] Buscar clave\n";
  cout << "[3] Mostrar arbol (inorden)\n";
  cout << "[4] Mostrar arbol (por niveles)\n";
  cout << "Selecciona una opcion: ";
}

int main(int argc, char *argv[])
{
  int ab = 0;
  int size_vector = std::stoi(argv[5]);

  ArbolB<nif>* arbol = nullptr;
  //std::cout << argv[2] << std::endl;
  if (std::string(argv[2]) == "abe") {
    arbol = new ABE<nif>();
  } 
  if (std::string(argv[2]) == "abb") {
    arbol = new ABB<nif>();
  }
  if (std::string(argv[4]) == "random") {
    srand(time(0));
    int max = 100;
    int min = 1;

    std::cout << "Los números insertados fueron: ";
    for (int i = 0; i < size_vector; i++) {
      long valor_aleatorio = (rand() % (max - min + 1) + min);
      nif dato(valor_aleatorio);
      std::cout << dato << " ";
      arbol->insertar(dato);
    } 
  }
  if (std::string(argv[4]) == "manual") {
    long elemento;
    for (int i = 0; i < size_vector; i++) {
      std::cout << "introduce el elemento numero " << i << ": ";
      std::cin >> elemento;
      arbol->insertar(nif(elemento));
      std::cout << std::endl;
    }
  }

  
  std::cout << std::endl;

  int option = 10;

  while (option != 0) {
    Menu();
    std::cin >> option;
    switch (option) {
      case 0:
        std::cout << "Adios\n";
        break;
      case 1:
        std::cout << "Valor a insertar: ";
        long num;
        std::cin >> num;
        arbol->insertar(nif(num));
        std::cout << "El número se ha insertado\n\n";
        num = 0;
        break;
      case 2:
        std::cout << "Ingrese el elemento a buscar:\n";
        std::cin >> num;
        if (arbol->buscar(nif(num)))
          cout << "Clave encontrada.\n";
        else
          cout << "Clave NO encontrada.\n";
        break;
      case 3:
        std::cout << "\nSe procede a mostrar el arbol (Inorden):\n";
        arbol->InOrder();
        std::cout << std::endl;
        break;
      case 4:
        std::cout << "\nSe procede a mostrar el arbol (Por niveles):\n";
        std::cout << *arbol << std::endl;
        break; 
      default:
        Menu();
      break;
    }
  }
}