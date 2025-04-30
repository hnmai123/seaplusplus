#include "InvertebrateCreature.h"

InvertebrateCreature::InvertebrateCreature(const string& specie, float size, int quantity)
    : SeaCreature(specie, size, quantity) {}

string InvertebrateCreature::getType() const {
    return "Invertebrate"; 
}