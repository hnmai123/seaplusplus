#ifndef INVERTEBRATECREATURE_H
#define INVERTEBRATECREATURE_H

#include "SeaCreature.h"
using namespace std;

class InvertebrateCreature : public SeaCreature {
    private:
        bool hasEggs; // Indicates if the invertebrate has eggs
    public:
        InvertebrateCreature(const string& specie, float size, int quantity, bool hasEggs); // Constructor
        string getType() const override; // Override the getType method
        bool getHasEggs() const; // Getter for hasEggs
};

#endif // INVERTEBRATECREATURE_H