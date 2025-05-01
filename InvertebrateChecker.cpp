#include "InvertebrateChecker.h"
#include <iostream>
#include "CSVLoader.h"

using namespace std;

InvertebrateChecker::InvertebrateChecker(const string& rulefile) {
    // Load rules from the CSV file
    rules = CSVLoader::loadRules(rulefile);
};

bool InvertebrateChecker::checkCatch(const SeaCreature* creature) const {
    string specie = creature->getSpecie();
    float length = creature->getSize();
    int quantity = creature->getQuantity();
    auto it = rules.find(specie);

    // Check if the species is in the rules
    if (it == rules.end()) {
        cout << "Species not found in rules: " << specie << endl;
        return false; // Species not found
    }

    const SpeciesRule& rule = it->second;

    if (length < rule.minSize & rule.minSize > 0) {
        cout << "Caught " << specie << " is too small. Minimum size: " << rule.minSize << endl;
        return false; // Too small
    }

    if (length > rule.maxSize & rule.maxSize > 0) {
        cout << "Caught " << specie << " is too large. Maximum size: " << rule.maxSize << endl;
        return false; // Too large
    }

    if (quantity > rule.bagLimit) {
        cout << "Caught " << specie << " exceeds bag limit. Bag limit: " << rule.bagLimit << endl;
        return false; // Exceeds bag limit
    }

    cout << "Caught " << specie << " is within legal limits." << endl;

    return true; // All checks passed
}