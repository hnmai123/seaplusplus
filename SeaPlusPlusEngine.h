#ifndef SEAPLUSPLUSENGINE_H
#define SEAPLUSPLUSENGINE_H

#include "SeaCreature.h"
#include "SeaChecker.h"
#include "VertebrateChecker.h"
#include "InvertebrateChecker.h"

class SeaPlusPlusEngine {
    private:
        VertebrateChecker vertebrateChecker; // Checker for vertebrates
        InvertebrateChecker invertebrateChecker; // Checker for invertebrates
    public: 
        SeaPlusPlusEngine(const string& vertebrateRuleFile, const string& invertebrateRuleFile);

        bool checkCatch(const SeaCreature* creature) const; // Method to check the catch
};

#endif // SEAPLUSPLUSENGINE_H