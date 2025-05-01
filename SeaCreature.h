#ifndef SEACREATURE_H
#define SEACREATURE_H
#include <string>

using namespace std;

class SeaCreature {
    protected:
        string specie; // Species of the sea creature
        float size; // Size in cm
        int quantity; // Quantity for the species
    public:
        SeaCreature(const string& specie, float size, int quantity);
        virtual ~SeaCreature() = default;

        float getSize() const; // Get the size of the sea creature
        string getSpecie() const; // Get the species of the sea creature
        int getQuantity() const; // Get the Quantity for the species
        
        virtual string getType() const = 0; // Abstract method
};

#endif // SEACREATURE_H