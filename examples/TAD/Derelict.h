#ifndef NAVE_ABANDONADA_H
#define NAVE_ABANDONADA_H

#include <string>
using std::string;

class Derelict
{
    friend std::ostream &operator<<(std::ostream &, const Derelict &);

public:
    // Constructors
    Derelict();
    Derelict(int, double, const string &);
    Derelict(const string &);

    // Destructor
    ~Derelict();

    // Getters e Setters
    int getIntegrity() const;
    double getEnergy() const;
    const string &getName() const;

    void setIntegrity(int);
    void setEnergy(double);

private:
    int integrity;
    double energy;
    string name;
};

#endif // NAVE_ABANDONADA_H