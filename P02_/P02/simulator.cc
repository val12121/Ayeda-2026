#include "simulator.h"
#include "fstream"
#include "sstream"

Simulator::Simulator(std::string filename) : steps_(0)
{
  std::ifstream file(filename);
  if (!file.is_open())
  {
    std::cerr << "Error al abrir el fichero: " << filename << std::endl;
    return;
  }

  int rows, cols, num_colors;
  file >> rows >> cols >> num_colors;
  tape_ = Tape(rows, cols);

  std::string line;
  std::getline(file, line); // Consumir salto de línea
  std::getline(file, line); // Leer línea de hormigas

  std::stringstream ss(line);
  std::string segment;
  while (std::getline(ss, segment, ';'))
  {
    std::stringstream ss_ant(segment);
    std::string rules, dirStr;
    int x, y;
    if (ss_ant >> rules >> x >> y >> dirStr)
    {
      Direction d = charToDir(dirStr);
      if (rules.length() > 2)
      {
        ants_.push_back(new Ant_X(x, y, d, rules));
      }
      else
      {
        ants_.push_back(new Ant(x, y, d, rules));
      }
    }
  }

  int cx, cy, cColor;
  while (file >> cx >> cy >> cColor)
  {
    tape_.SetCell(cx, cy, cColor);
  }
}

void Simulator::run()
{
  while (!isFinished())
  {

    std::cout << *this;

    std::cin.get();

    for (int i = 0; i < ants_.size(); i++)
    {
      ants_[i]->step(tape_);
    }
    steps_++;
  }
}

int Simulator::Save(const std::string &filename)
{
  std::ofstream file(filename);
  if (!file.is_open())
    return false;

  file << "FINAL DE LA SIMULACIÓN. PASOS: " << steps_ << "\n";
  for (int i = 0; i < tape_.get_max_sizeX(); i++)
  {
    for (int j = 0; j < tape_.get_max_sizeY(); j++)
    {
      Ant *aux = nullptr;
      for (Ant *a : ants_) {
        if (a->getx() == i && a->gety() == j)
        {
          aux = a;
          break;
        }
      }

      if (aux != nullptr) {
        file << *aux << " ";
      }
      else
      {
        // Representamos los colores con caracteres o espacios
        int color = tape_.get_color(i, j);
        if (color >= 0)
          file << color << " "; // Otros colores: el número
      }
    }
    file << "\n";
  }
  return 0;
}

Direction Simulator::charToDir(std::string c)
{
  if (c == "^")
    return Direction::Up;
  if (c == ">")
    return Direction::Right;
  if (c == "v")
    return Direction::Down;
  return Direction::Left;
}