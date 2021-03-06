﻿#include "ice_dispenser.h"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    IceDispenser* dispenser = new IceDispenser;
    while (true) {
        cout << "[Ice Dispenser]\n" << endl;
        dispenser->show_items();
        cout << "\n"
             << "input money > ";

        int money;
        cin >> money;

        cout << "input number > ";

        int input;
        cin >> input;
        dispenser->select_item(input, money);
        cout << endl;
    }

    delete dispenser;
}
