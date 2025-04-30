#include <iostream>
#include "Angler.h"
using namespace std;

int main() {
    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    
    Angler angler(name);
    angler.greet();

    return 0;
}