#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <memory>

#include "nif.h"
#include "sequences.h"
#include "sortmethods.h"
#include "algorithms.h"

void print_sequence(staticSequence<nif> &seq)
{
  for (unsigned i = 0; i < seq.size(); ++i)
  {
    std::cout << seq[i] << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char *argv[])
{
  unsigned size = 0;
  std::string metodo = "";
  std::string init = "manual";
  std::string filename = "";
  int trace = 0;
  double alfa = 0.5;

  for (int i = 1; i < argc; ++i)
  {
    std::string arg = argv[i];
    if (arg == "-size" && i + 1 < argc)
    {
      size = std::stoi(argv[++i]);
    }
    else if (arg == "-ord" && i + 1 < argc)
    {
      metodo = argv[++i]; // Espera: a, b, c, d, e
    }
    else if (arg == "-init" && i + 1 < argc)
    {
      init = argv[++i];
      if (init == "file" && i + 1 < argc)
      {
        filename = argv[++i];
      }
    }
    else if (arg == "-trace" && i + 1 < argc)
    {
      trace = (std::stoi(std::string(argv[++i])));
    }
    else if (arg == "-alfa" && i + 1 < argc)
    {
      alfa = std::stod(argv[++i]);
    }
  }

  if (size == 0 || metodo == "")
  {
    std::cerr << "Uso: " << argv[0] << " -size <n> -ord <m> [-init <manual|random|file f>] [-trace <y|n>] [-alfa <a>]" << std::endl;
    return 1;
  }

  staticSequence<nif> seq(size);

  if (init == "manual")
  {
    std::cout << "Introduzca " << size << " NIFs (solo números):" << std::endl;
    for (unsigned i = 0; i < size; ++i)
    {
      std::cin >> seq[i];
    }
  }
  else if (init == "random")
  {
    std::srand(std::time(nullptr));
    for (unsigned i = 0; i < size; ++i)
    {
      seq[i] = nif(std::rand() % 100000000);
    }
  }
  else if (init == "file")
  {
    std::ifstream file(filename);
    if (!file.is_open())
    {
      std::cerr << "Error: No se pudo abrir el fichero " << filename << std::endl;
      return 1;
    }
    for (unsigned i = 0; i < size && file >> seq[i]; ++i)
      ;
  }

  std::cout << "\n--- Secuencia Inicial ---" << std::endl;
  print_sequence(seq);

  std::unique_ptr<SortMethod<nif>> sorter;

  if (metodo == "a")
  {
    sorter = std::make_unique<SelectionSort<nif>>(seq, size, trace);
  }
  else if (metodo == "b")
  {
    sorter = std::make_unique<BubbleSort<nif>>(seq, size, trace);
  }
  else if (metodo == "c")
  {
    sorter = std::make_unique<MergeSortMethod<nif>>(seq, size, trace);
  }
  else if (metodo == "d")
  {
    sorter = std::make_unique<HeapSortMethod<nif>>(seq, size, trace);
  }
  else if (metodo == "e")
  {
    sorter = std::make_unique<ShellSortMethod<nif>>(seq, size, trace, alfa);
  }
  else
  {
    std::cerr << "Error: Método '" << metodo << "' no reconocido. Use a, b, c, d o e." << std::endl;
    return 1;
  }

  std::cout << "\nEjecutando ordenación..." << std::endl;
  sorter->Sort();

  std::cout << "\n--- Secuencia Final Ordenada ---" << std::endl;
  print_sequence(seq);

  std::cout << "\n--- Resultados del Análisis ---" << std::endl;
  std::cout << "Comparaciones: " << sorter->get_comps() << std::endl;
  std::cout << "Intercambios:  " << sorter->get_swaps() << std::endl;
  std::cout << "-------------------------------" << std::endl;

  return 0;
}