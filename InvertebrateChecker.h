#ifndef INVERTEBRATECHECKER_H
#define INVERTEBRATECHECKER_H

#include "SeaChecker.h"
#include "CSVLoader.h"
#include <map>
using namespace std;

class InvertebrateChecker : public SeaChecker {
    private:
        map<string, SpeciesRule> rules; // Map to hold species rules
    public:
        InvertebrateChecker(const string& rulefile); // Constructor to load rules from a file
        bool checkCatch(const SeaCreature* creature) const override; // Override the checkCatch method
};

#endif // INVERTEBRATECHECKER_H