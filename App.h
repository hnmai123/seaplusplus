#ifndef APP_H
#define APP_H

#include "Angler.h"
#include "SeaCreature.h"
#include "SeaPlusPlusEngine.h"

class App {
    private:
        SeaPlusPlusEngine* engine;
        Angler* angler;
    public:
        App();
        ~App();

        void run(); // Entry point for the application
        SeaCreature* getCatchData(); // Ask user for catch data
        void displayCatchData(SeaCreature* creature); // Display catch data
        void displayResult(bool result); // Display result of the catch (can keep or release)
        void displayGoodbye(); // Display goodbye message
};

#endif // APP_H