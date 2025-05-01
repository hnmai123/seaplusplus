#ifndef VERTEBRATECHECKER_H
#define VERTEBRATECHECKER_H

#include "SeaChecker.h"
#include "CSVLoader.h"
#include <map>
using namespace std;

class VertebrateChecker : public SeaChecker {
    private:
        map<string, SpeciesRule> rules; // Map to hold species rules
    public:
        VertebrateChecker(const string& rulefile); // Constructor to load rules from a file
        bool checkCatch(const SeaCreature* creature) const override; // Override the checkCatch method
};

#endif // VERTEBRATECHECKER_H