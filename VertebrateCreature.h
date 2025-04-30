#ifndef VERTEBRATECREATURE_H
#define VERTEBRATECREATURE_H

#include "SeaCreature.h"
using namespace std;

class VertebrateCreature : public SeaCreature {
    public:
        VertebrateCreature(const string& specie, float size, int quantity);
        string getType() const override; // Override the getType method
};

#endif // VERTEBRATECREATURE_H