#ifndef CSVLOADER_H
#define CSVLOADER_H

#include "SpeciesRule.h"
#include <map>
#include <string>

using namespace std;

class CSVLoader {
    public:
        static map<string, SpeciesRule> loadRules(const string& filename); // Static method to load rules from a CSV file
};

#endif // CSVLOADER_H