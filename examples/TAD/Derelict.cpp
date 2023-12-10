#include "Derelict.h"
#include <iostream>

Derelict::Derelict(){
    std::cout << "Derelict created" << std::endl;
    setIntegrity(50);
    setEnergy(90);
}


Derelict::Derelict(int i, double d, const std::string &s)
    : integrity(i), energy(d), name(s)
{
} 

Derelict::Derelict(const std::string& s)
    :name(s) { 
      //valores default
      this->integrity = 70;
      this->energy = 50.0;
}

int Derelict::getIntegrity() const {
    return integrity;
}

void Derelict::setIntegrity(int i) {
    if (i >= 0) {
        integrity = i;
    } else {
        std::cerr << "integrity não pode ser negativa." << std::endl;
    }
}

double Derelict::getEnergy() const {
    return energy;
}

void Derelict::setEnergy(double d) {
     if (d >= 0.0) {
        this->energy = d;
    }
}

const std::string& Derelict::getName() const {
    return name;
}

//operator << overload
std::ostream& operator<<(std::ostream& output, Derelict const &nave){
  output << "Derelict name: s" << nave.getName() << "\n";
  output << "Integrity: " << nave.getIntegrity() << "\n";
  output << "Energy: " << nave.getEnergy() << "\n";
  return output;
}

Derelict::~Derelict() {} //destructor