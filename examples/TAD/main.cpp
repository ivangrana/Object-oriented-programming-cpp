#include "NaveAbandonada.h"
#include <iostream>

int main() {
  NaveAbandonada ship1("taylor swift");
  ship1.setEnergia(-10);
  std::cout << ship1.getIntegridade() << std::endl;
  std::cout << ship1.getEnergia()<< std::endl;
  ship1.printNome();
}
