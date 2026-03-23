#include <iostream>

template <typename key>
class Empleado
{
public:
  Empleado(key clave, std::string nombre, std::string apellidos, std::string telefono)
      : key_(clave), nombre_(nombre), apellidos_(apellidos), telefono_(telefono) {}
  void show()
  {
    std::cout << nombre_ << " " << apellidos_ << " " << telefono_ << "\n";
  }

  bool operator==(const std::string &nif_buscado) const
  {
    return key_ == nif_buscado;
  }

  friend std::ostream &operator<<(std::ostream &os, const Empleado &emp)
  {
    os << "ID: " << emp.id_ << " | " << emp.nombre_ << " " << emp.apellido_ << " | Tlf: " << emp.telefono_;
    return os;
  }

private:
  std::string nombre_;
  std::string apellidos_;
  std::string telefono_;
  key key_;
};