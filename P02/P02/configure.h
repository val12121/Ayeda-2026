#include "simulator.h"
#include <fstream>
#include <string>
#include <sstream>

class Configure {
  public:
    Configure (std::string nombre_archivo) { Configurar(nombre_archivo); }
    int Configurar (std::string nombre_archivo) {
      std::ifstream archivo(nombre_archivo); // Abrir el archivo en modo lectura

      if (!archivo.is_open()) {
        std::cout << "Error al abrir el archivo: " << nombre_archivo << "\n";
        return 1;
      }

      std::string linea;
      std::getline(archivo, linea);
      std::stringstream ss(linea);
      
      std::string xx;
      ss >> xx;
      int x = std::stoi(xx);

      std::string yy;
      ss >> yy;
      int y = std::stoi(yy);

      
    }
  private:
};