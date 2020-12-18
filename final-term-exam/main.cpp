#include <iostream>

#include "BaseMenu.h"
#include "MainMenu.h"

using namespace std;

int main() {
    MenuStack menuStack;

    BaseMenu* menu = new MainMenu();
    menuStack.Push(menu);

    while (!menuStack.IsEmpty()) {
        menuStack.Peek(menu);

        menu->ShowMenu();
        cout << "=======================================\n";
        cout << "Choice: ";

        int choice;
        cin >> choice;

        cout << "Process " << choice << ": ";

        menu->Process(choice, menuStack);

        cout << '\n'
             << endl;
    }

    return 0;
}
