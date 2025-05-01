#include "App.h"
#include <iostream>
#include "VertebrateCreature.h"
#include "InvertebrateCreature.h"
#include <algorithm>

using namespace std;
string toLower(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

App::App() {
    engine = new SeaPlusPlusEngine("regulation/vertebrate_rules.csv", "regulation/invertebrate_rules.csv");
    angler = nullptr;
}

App::~App() {
    delete engine;
    delete angler;
}

void App::run() {
    cout << "Welcome to Sea++!" << endl;
    string name;    
    cout << "Enter your name: ";
    getline(cin, name);
    angler = new Angler(name);
    angler->greet();

    SeaCreature* creature = getCatchData();
    bool result = engine->checkCatch(creature);
    displayCatchData(creature);
    displayResult(result);

    delete creature; // Clean up the creature object
    displayGoodbye();
}

SeaCreature* App::getCatchData() {
    string specie, type;
    float size;
    int quantity;
    cout << "Enter the type of sea creature (Vertebrate/Invertebrate): ";
    getline(cin, type);
    type = toLower(type);  // Normalize to lowercase
    cout << "Enter the species of the sea creature: ";
    getline(cin, specie);
    cout << "Enter the size of the sea creature (in cm): ";
    cin >> size;
    cout << "Enter the quantity of the sea creature: ";
    cin >> quantity;

    // Create a new SeaCreature object based on the type
    SeaCreature* creature;
    if (type == "vertebrate") {
        creature = new VertebrateCreature(specie, size, quantity);
    } else if (type == "invertebrate") {
        creature = new InvertebrateCreature(specie, size, quantity);
    } else {
        cout << "Unknown type of sea creature. Defaulting to Vertebrate." << endl;
        creature = new VertebrateCreature(specie, size, quantity);
    }

    return creature;
}

void App::displayCatchData(SeaCreature* creature) {
    cout << "Caught " << creature->getSpecie() << " of size " << creature->getSize() << " cm and quantity " << creature->getQuantity() << endl;
}

void App::displayResult(bool result) {
    if (result) {
        cout << "You can keep the catch!" << endl;
    } else {
        cout << "You must release the catch back to nature!" << endl;
    }
}

void App::displayGoodbye() {
    cout << "Thank you for using Sea++. Goodbye!" << endl;
}