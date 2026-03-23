#include "simulator.h"
#include "color_exception.h"
#include "fstream"
#include "sstream"

Simulator::Simulator(std::string filename, const std::string opcion) : steps_(0)
{
  std::ifstream file(filename);
  if (!file.is_open())
  {
    std::cerr << "Error al abrir el fichero: " << filename << std::endl;
    return;
  }

  int rows, cols, num_colors;
  file >> rows >> cols >> num_colors;
  if (opcion ==  "-S" || opcion ==  "-s") {
    tape_ = new TapeSliding(rows, cols);
  } else if (opcion == "-R" || opcion == "-r") {
    tape_ = new TapeReflective(rows, cols);
  } else if (opcion == "-P" || opcion == "-p") {
    tape_ = new TapePeriodic(rows, cols);
  }

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
      // --- separar tipo y reglas ---
      char type = rules[0];                    // H o C
      std::string realRules = rules.substr(2); // quitar "H-" o "C-"

      if (type == 'H')
      {
        ants_.push_back(new Ant_Herbivore(x, y, d, realRules));
      }
      else if (type == 'C')
      {
        ants_.push_back(new Ant_Carnivore(x, y, d, realRules));
      }
    }
  }

  int cx, cy, cColor;
  while (file >> cx >> cy >> cColor)
  { 
    if (cColor > num_colors) {
      throw Color_Exception();
    }
    tape_->SetCell(cx, cy, cColor);
  }
}

void Simulator::run()
{
  while (!isFinished())
  {
    std::cout << *this;
    
    for (int i = 0; i < ants_.size(); i++) {
      if (ants_[i]->ant_type() == "Car") {
        double food = 0;
        // Obtenemos el color de la celda donde está el carnívoro
        //int color_carnivoro = tape_->get_color(ants_[i]->getx(), ants_[i]->gety());
        for (int j = 0; j < ants_.size(); j++) {
          // Si es herbívora Y está en una celda del mismo color que el carnívoro
          if (ants_[j]->ant_type() == "Her") {
            //int color_herbivora = tape_->get_color(ants_[j]->getx(), ants_[j]->gety());
            
            if (ants_[i]->getx() == ants_[j]->getx() && ants_[i]->gety() == ants_[j]->gety() ) {
              // Sumamos su vida al acumulador 
              food += ants_[j]->get_life();
              // Aplicamos daño 
              ants_[j]->Damage(ants_[i]->get_voracity());
            }
          }
        }
        // El carnívoro usa la función Eat con el total de vida recolectado
        ants_[i]->Eat(food);
      }
    }
    for (auto it = ants_.begin(); it != ants_.end(); ) {
      if ((*it)->get_life() <= 0) {
        std::cout << "Una hormiga " << (*it)->ant_type() << " ha fallecido" << std::endl;
        delete *it;           
        it = ants_.erase(it); 
      } else {
        ++it; 
      }
    }
    for (int i = 0; i < ants_.size(); i++)
    {
      ants_[i]->step(tape_);
      tape_->switcher(ants_[i]);
    }
    steps_++;
    std::string input;
    std::cout << "Presiona Enter para continuar o escribe 'exit' para parar: \n";
    // Leemos la línea completa
    std::getline(std::cin, input);
    
    // Si el usuario escribió exit, salimos del bucle
    if (input == "exit") {
      std::cout << "Simulación finalizada por el usuario.";
      break; 
    }
  }
}

int Simulator::Save(const std::string &filename)
{
  std::ofstream file(filename);
  if (!file.is_open())
    return false;

  file << "FINAL DE LA SIMULACIÓN. PASOS: " << steps_ << "\n";
  for (int i = tape_->get_min_sizeX(); i <= tape_->get_max_sizeX(); i++) {
    for (int j = tape_->get_min_sizeY(); j <= tape_->get_max_sizeY(); j++) {
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
      else {
        // Representamos los colores con caracteres o espacios
        int color = tape_->get_color(i, j);
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