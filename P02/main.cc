#include "simulator.h"
#include <string>
#include <sstream>

int main(int argc, char *argv[]) 
{
  std::string archivo = argv[1];
  Simulator sim(archivo);

  sim.InfoAnts();
  sim.run();
  std::cout << sim;
}