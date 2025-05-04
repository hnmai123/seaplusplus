#ifndef SEACHECKER_H
#define SEACHECKER_H

#include "SeaCreature.h"
#include <map>
#include "SpeciesRule.h"

using namespace std;

class SeaChecker {
    public:
        virtual ~SeaChecker() = default; // Virtual destructor
        virtual bool checkCatch(const SeaCreature* creature) const = 0; // Abtract method to check the catch
    protected:
        string findMatchingSpecies(const map<string, SpeciesRule>& speciesRules, const string& input) const; // Helper method to find matching species
};

#endif // SEACHECKER_H