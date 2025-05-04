#include "SeaChecker.h"
#include "InputHelper.h"

using namespace std;

string SeaChecker::findMatchingSpecies(const map<string, SpeciesRule>& speciesRules, const string& input) const {
    string lowerInput = toLower(input);
    for (const auto& [key, rule] : speciesRules) {
        if (toLower(key).find(lowerInput) != string::npos) {
            return key; // Return the first matching species name
        }
    }
    return "";
}