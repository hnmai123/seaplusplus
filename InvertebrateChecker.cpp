#include "InvertebrateChecker.h"
#include <iostream>
#include "CSVLoader.h"
#include "InvertebrateCreature.h"

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
        cout << "\n❌ Species not found in rules: " << specie << endl;
        return false; // Species not found
    }

    const SpeciesRule& rule = it->second;
    const InvertebrateCreature* invertebrate = dynamic_cast<const InvertebrateCreature*>(creature);
    if (invertebrate && invertebrate->getHasEggs()) {
        cout << "\n🥚 Caught " << specie << " is carrying eggs. Must be released.\n";
        return false; // Has eggs
    }

    if (length < rule.minSize & rule.minSize > 0) {
        cout << "\n📏 Caught " << specie << " is too small. Minimum size: " << rule.minSize << " cm ❗\n";
        return false; // Too small
    }

    if (length > rule.maxSize & rule.maxSize > 0) {
        cout << "\n📏 Caught " << specie << " is too large. Maximum size: " << rule.maxSize << " cm ❗\n";
        return false; // Too large
    }

    if (quantity > rule.bagLimit) {
        cout << "\n🔢 Caught " << specie << "(s) exceeds bag limit. Bag limit: " << rule.bagLimit << " ❗\n";
        return false; // Exceeds bag limit
    }

    cout << "\n✅ Caught " << specie << " is within legal limits. You may keep it!" << endl;

    return true; // All checks passed
}