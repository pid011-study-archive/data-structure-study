#include "MainMenu.h"

#include <iostream>

#include "SoundMenu.h"

void MainMenu::ShowMenu() {
    using namespace std;

    cout << "1. Start Game\n";
    cout << "2. Save Game\n";
    cout << "3. Sound Setting\n";
    cout << "4. End\n";
}

void MainMenu::Process(int menuIndex, MenuStack& menuStack) {
    using namespace std;

    switch (menuIndex) {
    case 1:
        cout << "Staring the gmae..." << endl;
        break;
    case 2:
        cout << "Saving the game..." << endl;
        break;
    case 3:
        cout << "Sound Setting" << endl;
        menuStack.Push(new SoundMenu);
        break;
    case 4:
        cout << "Exit the program." << endl;
        menuStack.Pop();
        break;
    default:
        cout << "Invalid number." << endl;
        break;
    }
}
