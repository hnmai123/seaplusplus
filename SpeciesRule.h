#ifndef SPECIESRULE_H
#define SPECIESRULE_H

#include <string>
using namespace std;

struct SpeciesRule {
    string name;
    float minSize;
    float maxSize;
    int bagLimit;
};

#endif // SPECIESRULE_H