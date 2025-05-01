#ifndef SEACHECKER_H
#define SEACHECKER_H

#include "SeaCreature.h"

class SeaChecker {
    public:
        virtual ~SeaChecker() = default; // Virtual destructor
        virtual bool checkCatch(const SeaCreature* creature) const = 0; // Abtract method to check the catch
};

#endif // SEACHECKER_H