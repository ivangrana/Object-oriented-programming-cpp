#ifndef NAVE_ABANDONADA_H
#define NAVE_ABANDONADA_H

#include <string>

class NaveAbandonada {
public:
    // Construtores
    NaveAbandonada(); //construtor padrão sem parâmetros.
    // é um construtor que aceita três parâmetros, sendo integridade, energia e nome. 
    //O último parâmetro tem um valor padrão vazio, o que significa que pode ser omitido na chamada.
    NaveAbandonada(int integridade, double energia, const std::string& nome = "");
    NaveAbandonada(const std::string& nome); // é um construtor que aceita apenas um parâmetro, nome.

    // Destrutor
    ~NaveAbandonada();

    // Getters e Setters
    int getIntegridade() const;
    void setIntegridade(int integridade);
    double getEnergia() const;
    void setEnergia(double energia);
    const std::string& getNome() const;
    void setNome(const std::string& nome);
    void printNome() const; 
private:
    int integridade;
    double energia;
    std::string nome;
};

#endif // NAVE_ABANDONADA_H