#include "NaveAbandonada.h"
#include <iostream>


NaveAbandonada::NaveAbandonada(int i, double d, const std::string &s)
    : integridade(i), energia(d), nome(s)
{
} // construtor 1

NaveAbandonada::NaveAbandonada(const std::string& s) //construtor 2
    :nome(s) { 
      //valores default
      this->integridade = 70;
      this->energia = 50.0;
}

int NaveAbandonada::getIntegridade() const {
    return integridade;
}

void NaveAbandonada::setIntegridade(int i) {
    if (i >= 0) {
        integridade = i;
    } else {
        std::cerr << "Integridade não pode ser negativa." << std::endl;
    }
}

double NaveAbandonada::getEnergia() const {
    return energia;
}

void NaveAbandonada::setEnergia(double d) {
     if (d >= 0.0) {
        this->energia = d;
    } else {
        std::cerr << "Error: Energia não pode ser negativa" << std::endl;
    }
}

const std::string& NaveAbandonada::getNome() const {
    return nome;
}

void NaveAbandonada::printNome() const {
    // Faça algo aqui
    std::cout << nome << std::endl;
}

NaveAbandonada::~NaveAbandonada() {} //destrutor