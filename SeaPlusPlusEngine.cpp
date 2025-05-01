#include "SeaPlusPlusEngine.h"
#include <iostream>

using namespace std;

SeaPlusPlusEngine::SeaPlusPlusEngine(const string& vertebrateRuleFile, const string& invertebrateRuleFile)
    : vertebrateChecker(vertebrateRuleFile), invertebrateChecker(invertebrateRuleFile) {}

bool SeaPlusPlusEngine::checkCatch(const SeaCreature* creature) const {
    string type = creature->getType();

    if (type == "Vertebrate") {
        return vertebrateChecker.checkCatch(creature);
    } else if (type == "Invertebrate") {
        return invertebrateChecker.checkCatch(creature);
    } else {
        cout << "Unknown creature type: " << type << endl;
        return false; // Unknown type
    }
}