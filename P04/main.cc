#include <iostream>
#include <string>
#include <vector>

#include "hash.h"

template <typename T>
void ejecutar_menu(T &tabla)
{
  int opcion;
  long clave;
  do
  {
    std::cout << "\n---------- MENÚ HASH ----------" << std::endl;
    std::cout << "1. Insertar NIF" << std::endl;
    std::cout << "2. Buscar NIF" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "Seleccione opción: ";
    std::cin >> opcion;

    switch (opcion)
    {
    case 1:
      std::cout << "Introduzca NIF (8 dígitos): ";
      std::cin >> clave;
      if (tabla.insert(clave)) {
        std::cout << ">>> Clave " << clave << " insertada con éxito." << std::endl;
      }
      else {
        std::cout << ">>> Error: La clave ya existe o el bloque/tabla está lleno." << std::endl;
      }
      break;
    case 2:
      std::cout << "Introduzca NIF a buscar: ";
      std::cin >> clave;
      if (tabla.search(clave)) {
        std::cout << ">>> Clave " << clave << " ENCONTRADA en la tabla." << std::endl;
      }
      else {
        std::cout << ">>> Clave " << clave << " NO encontrada." << std::endl;
      }
      break;
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
  // Verificación de argumentos mínimos (ts, fd, hash)
  if (argc < 7)
  {
    std::cerr << "Uso: ./main -ts <table> -fd <1|2|3> -hash <open|close> [-bs <size> -fe <1|2|3>]" << std::endl;
    std::cerr << "FD: 1:Suma, 2:Random, 3:Modulo" << std::endl;
    std::cerr << "FE: 1:Cuadrática, 2:DobleHash, 3:Lineal" << std::endl;
    return 1;
  }

  // 1. Captura de parámetros
  unsigned tablesize = std::stoi(argv[2]);
  unsigned fd_option = std::stoi(argv[4]);
  std::string hash_type = argv[6]; // "open" o "close"

  // 2. Selección de la Función de Dispersión
  DispersionFunction<long> *fd = nullptr;
  switch (fd_option)
  {
  case 1:
    fd = new FD_Sum<long>(tablesize);
    break;
  case 2:
    fd = new FD_Rand<long>(tablesize);
    break;
  default:
    fd = new FD_Module<long>(tablesize);
    break;
  }

  // 3. Selección de la lógica según el tipo de Tabla
  if (hash_type == "close")
  {
    // Para cerrada necesitamos blockSize y Función de Exploración
    if (argc < 11)
    {
      std::cerr << "Error: Faltan parámetros para dispersión cerrada (-bs y -fe)." << std::endl;
      return 1;
    }
    unsigned bs = std::stoi(argv[8]);
    unsigned fe_option = std::stoi(argv[10]);

    ExplorationFunction<long> *fe = nullptr;
    if (fe_option == 1)
    {
      fe = new FE_Quadratic<long>();
    }
    else if (fe_option == 2)
    {
      fe = new FE_DoubleHash<long>(*(new FD_Sum<long>(tablesize)));
    }
    else
    {
      fe = new FE_lineal<long>();
    }

    // Instanciar Tabla con Secuencia Estática
    HashTable<long, staticSequence<long>> ht(tablesize, *fd, *fe, bs);
    ejecutar_menu(ht);
  }
  else if (hash_type == "open")
  {
    // En abierta, la exploración es lineal por defecto (no se usa realmente para saltos)
    ExplorationFunction<long> *fe = new FE_lineal<long>();

    // Instanciar Tabla con Secuencia Dinámica (bs = 0 porque no tiene límite)
    HashTable<long, dynamicSequence<long>> ht(tablesize, *fd, *fe, 0);
    ejecutar_menu(ht);
  }
  else
  {
    std::cerr << "Tipo de hash desconocido: " << hash_type << ". Use 'open' o 'close'." << std::endl;
    return 1;
  }

  return 0;
}