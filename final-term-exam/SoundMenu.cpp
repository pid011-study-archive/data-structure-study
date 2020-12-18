#include "SoundMenu.h"

#include <iostream>

#include "MainMenu.h"

void SoundMenu::ShowMenu() {
    using namespace std;

    cout << "1. Sound On\n";
    cout << "2. Sound Off\n";
    cout << "3. Back to main\n";
}

void SoundMenu::Process(int menuIndex, MenuStack& menuStack) {
    using namespace std;

    switch (menuIndex) {
    case 1:
        cout << "Sound On" << endl;
        break;
    case 2:
        cout << "Sound Off" << endl;
        break;
    case 3:
        cout << "Back to main..." << endl;
        menuStack.Pop();
        break;
    default:
        cout << "Invalid number." << endl;
        break;
    }
}
