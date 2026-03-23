#include <iostream>
#include <string>
#include <vector>
#include "empleado.h"

#include "hash.h"

// Usamos std::string como tipo base para que acepte letras
template <typename T>
void ejecutar_menu(T &tabla)
{
  int opcion;
  std::string clave_string; 
  std::string nombre;
  std::string apellido;
  std::string telefono;
  do
  {
    std::cout << "\n---------- MENÚ HASH ----------" << std::endl;
    std::cout << "1. Insertar NIF (Normal)" << std::endl;
    std::cout << "2. Buscar NIF" << std::endl;
    std::cout << "3. Mostrar tabla" << std::endl;
    std::cout << "4. Insertar empleado" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "Seleccione opción: ";
    std::cin >> opcion;

    switch (opcion)
    {
    case 1:
      std::cout << "Introduzca clave: ";
      std::cin >> clave_string;
      if (tabla.insert(clave_string)) {
        std::cout << ">>> Clave " << clave_string << " insertada con éxito." << std::endl;
      }
      else {
        std::cout << ">>> Error: Ya existe o tabla llena." << std::endl;
      }
      break;

    case 2:
      std::cout << "Introduzca clave a buscar: ";
      std::cin >> clave_string;
      if (tabla.search(clave_string)) {
        std::cout << ">>> Clave " << clave_string << " ENCONTRADA." << std::endl;
      }
      else {
        std::cout << ">>> Clave " << clave_string << " NO encontrada." << std::endl;
      }
      break;

    case 3:
      std::cout << "\nESTADO ACTUAL DE LA TABLA HASH:" << std::endl;
      tabla.print();
      break;

    case 4: {
        std::string p1, p2, p3;
        std::cout << "Introduzca las 3 partes separadas por espacio: ";
        std::cin >> p1 >> p2 >> p3;
        
        std::string clave_final = p1 + p2 + p3; // Concatenación de strings pura
        
        std::cout << "Insertando clave compuesta: " << clave_final << std::endl;
        if (tabla.insert(clave_final)) {
            std::cout << ">>> Insertada con éxito." << std::endl;
        } else {
            std::cout << ">>> Error al insertar." << std::endl;
        }
        break;
        
        std::cin >> nombre;
        std::cin >> apellido;
        std::cin >> telefono;

        Empleado empl1(clave_final, nombre, apellido, telefono);
    }

    case 0:
      std::cout << "Saliendo del programa..." << std::endl;
      break;

    default:
      std::cout << "Opción no válida." << std::endl;
      break;
    }
  } while (opcion != 0);
}

int main(int argc, char *argv[])
{
  if (argc < 7)
  {
    std::cerr << "Uso: ./main -ts <table> -fd <1|2|3> -hash <open|close> [-bs <size> -fe <1|2|3>]" << std::endl;
    return 1;
  }

  unsigned tablesize = std::stoi(argv[2]);
  unsigned fd_option = std::stoi(argv[4]);
  std::string hash_type = argv[6];

  DispersionFunction<std::string> *fd = nullptr;
  switch (fd_option)
  {
  case 1:
    fd = new FD_Sum<std::string>(tablesize);
    break;
  case 2:
    fd = new FD_Rand<std::string>(tablesize);
    break;
  default:
    fd = new FD_Module<std::string>(tablesize);
    break;
  }

  if (hash_type == "close")
  {
    unsigned bs = std::stoi(argv[8]);
    unsigned fe_option = std::stoi(argv[10]);

    ExplorationFunction<std::string> *fe = nullptr;
    if (fe_option == 1)
      fe = new FE_Quadratic<std::string>();
    else if (fe_option == 2)
      fe = new FE_DoubleHash<std::string>(*(new FD_Sum<std::string>(tablesize)));
    else
      fe = new FE_lineal<std::string>();

    // Tabla con std::string
    HashTable<std::string, staticSequence<std::string>> ht(tablesize, *fd, *fe, bs);
    ejecutar_menu(ht);
  }
  else
  {
    ExplorationFunction<std::string> *fe = new FE_lineal<std::string>();
    HashTable<std::string, dynamicSequence<std::string>> ht(tablesize, *fd, *fe, 0);
    ejecutar_menu(ht);
  }

  return 0;
}