#include <iostream>

class Retangulo {
private:
  double Comprimento;
  double Altura;

public:
  // constructor
  Retangulo(double len, double wid) {
    Comprimento = len;
    Altura = wid;
  }

  
  double CalcularArea() {
    return Comprimento * Altura;
  }

  double CalcularPerimetro() {
    return 2 * (Comprimento + Altura);
  }
};

int main() {
  // create an object of Retangulo class
  Retangulo rect(5.0, 3.0);

  // call methods on the object
  double area = rect.CalcularArea();
  double perimeter = rect.CalcularPerimetro();

  // display the results
  std::cout << "Area: " << area << std::endl;
  std::cout << "Perimeter: " << perimeter << std::endl;

  return 0;
}
