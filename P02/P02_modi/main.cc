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

  std::string archivo_2 = "archivo_salida.txt";
  sim.Save(archivo_2);

  char respuesta;
  std::cout << "¿Desea guardar el resultado gráfico final? (s/n): ";
  std::cin >> respuesta;

  if (respuesta == 's' || respuesta == 'S')
  {
    if (sim.Save(archivo_2))
    {
      std::cout << "Mapa guardado con éxito." << std::endl;
    }
  } else {
    std::cout << "Gracias" << std::endl;
  }
}