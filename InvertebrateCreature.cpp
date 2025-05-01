#include "InvertebrateCreature.h"

InvertebrateCreature::InvertebrateCreature(const string& specie, float size, int quantity, bool hasEggs)
    : SeaCreature(specie, size, quantity), hasEggs(hasEggs) {}

string InvertebrateCreature::getType() const {
    return "Invertebrate"; 
}

bool InvertebrateCreature::getHasEggs() const {
    return hasEggs;
}