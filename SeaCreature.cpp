#include "SeaCreature.h"

SeaCreature::SeaCreature(const string& specie, float size, int quantity)
    : specie(specie), size(size), quantity(quantity) {}

float SeaCreature::getSize() const {
    return size;
}

string SeaCreature::getSpecie() const {
    return specie;
}

int SeaCreature::getQuantity() const {
    return quantity;
}