#include "Angler.h"
#include <iostream>
using namespace std;

Angler::Angler(const string& name) : name(name) {}

string Angler::getName() const {
    return name;
}

void Angler::greet() const {
    cout << "Hello " << name << "! 🎣 Let's check your catch!\n" << endl;
    cout << "=======================================\n" << endl;
}