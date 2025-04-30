#ifndef ANGLER_H
#define ANGLER_H
#include <string>
using namespace std;

class Angler {
    private:
        string name;
    public:
        Angler(const string& name);
        string getName() const;
        void greet() const;
};

#endif // ANGLER_H
