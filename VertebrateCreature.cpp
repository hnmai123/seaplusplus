#include "VertebrateCreature.h"

using namespace std;

VertebrateCreature::VertebrateCreature(const string& specie, float size, int quantity)
    : SeaCreature(specie, size, quantity) {}

string VertebrateCreature::getType() const {
    return "Vertebrate"; 
}