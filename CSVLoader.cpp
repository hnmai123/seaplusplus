#include "CSVLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

map<string, SpeciesRule> CSVLoader::loadRules(const string& filename) {
    map<string, SpeciesRule> rules;
    ifstream file(filename);
    
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return rules; // Return empty map on error
    }
    
    string line;
    getline(file, line); // Skip the header line

    // Read each line of the CSV file
    while (getline(file, line)) {
        stringstream ss(line);
        string name, minStr, maxStr, bagStr;

        getline(ss, name, ',');
        getline(ss, minStr, ',');
        getline(ss, maxStr, ',');
        getline(ss, bagStr, ',');

        try {
            float minLength = stof(minStr);
            float maxLength = stof(maxStr);
            int bagLimit = stoi(bagStr);

            SpeciesRule rule{name, minLength, maxLength, bagLimit};
            rules[name] = rule;
        } catch (...) {
            cerr << "Skipping bad line: " << line << endl;
        }
    }
    
    file.close();
    return rules; // Return the loaded rules
}