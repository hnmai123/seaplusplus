#ifndef INVERTEBRATECREATURE_H
#define INVERTEBRATECREATURE_H

#include "SeaCreature.h"
using namespace std;

class InvertebrateCreature : public SeaCreature {
    public:
        InvertebrateCreature(const string& specie, float size, int quantity);
        string getType() const override; // Override the getType method
};

#endif // INVERTEBRATECREATURE_H