#include "InputHelper.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

string toLower(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

float readFloat(const string& prompt) {
    string input;
    float value;

    while (true) {
        cout << prompt;
        getline(cin, input);
        stringstream ss(input);

        if (ss >> value && ss.eof()) {
            // Check if the input is a valid float
            // Check if there are any remaining characters in the stream
            return value;
        } else {
            cout << "❌ Invalid input. Please enter a number." << endl;
        }
    }
}

int readInt(const string& prompt) {
    string input;
    int value;

    while (true) {
        cout << prompt;
        getline(cin, input);
        stringstream ss(input);
        // Check if the input is a valid integer
        if (ss >> value && ss.eof()) {
            return value;
        } else {
            cout << "❌ Invalid input. Please enter a whole number." << endl;
        }
    }
}

string readString(const string& prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}

bool readYesNo(const string& prompt) {
    string input;
    while (true) {
        cout << prompt << " (y/n): ";
        getline(cin, input);
        if (toLower(input) == "y" || toLower(input) == "yes") {
            // Check if the input is 'y', 'Y', 'yes', or 'Yes'
            return true;
        } else if (toLower(input) == "n" || input == "N" || toLower(input) == "no") {
            return false;
        } else {
            cout << "❌ Invalid input. Please enter 'y/yes' or 'n/no'." << endl;
        }
    }
}