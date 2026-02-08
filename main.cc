#include "simulator.h"
#include <fstream>
#include <string>
#include <sstream>

int main (int argc, char *argv[]) {

  if (argc > 1) {
    std::string nombreArchivo = argv[1]; // Primer argumento después del programa
    std::ifstream archivo(nombreArchivo); // Abrir el archivo en modo lectura

    if (!archivo.is_open()) {
        std::cout << "Error al abrir el archivo: " << nombreArchivo << "\n";
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

    Tape tape(x, y); 
    std::getline(archivo, linea);
    std::stringstream nn(linea);

    nn >> xx;
    nn >> yy;

    x = std::stoi(xx);
    y = std::stoi(yy);
    std::string dir; 

    nn >> dir; 
    Ant ant(x, y, static_cast<Direction>(std::stoi(dir)));

    Simulator sim (tape, ant);
    sim.run();

  } else {
    Tape tape;
    Ant ant (5, 5, static_cast<Direction>(3));
    Simulator sim(tape, ant);
    sim.run();
  }
  return 0;
}