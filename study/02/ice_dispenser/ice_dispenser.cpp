#include "ice_dispenser.h"

IceDispenser::IceDispenser() : item_count(3) {
    items = new DispenserItem[item_count] { DispenserItem("Water", 1, 50, true),
                                            DispenserItem("Ice water", 2, 30, true),
                                            DispenserItem("Cube ice", 1, 60, true) };
}

IceDispenser::~IceDispenser() {
    delete[] items;
}

void IceDispenser::show_items() const {
    for (int i = 0; i < item_count; i++) {
        cout << "[" << i << "] - " << items[i].get_name() << "\n\t"
             << "Can buy: " << (items[i].get_enable() ? "O" : "X") << "\n\t"
             << "Remaning: " << items[i].get_count() << "\n\t"
             << "Price: " << items[i].get_price() << endl;

        if (i < item_count - 1) {
            cout << endl;
        }
    }
}

void IceDispenser::select_item(int idx, int input_money) {
    if (idx < 0 && idx > item_count - 1) {
        cout << "Wrong number." << endl;
        return;
    }

    SelectResult result = items[idx].select(input_money);

    if (result.succeed) {
        cout << "Returned " << items[idx].get_name() << ".\n";
    } else {
        cout << "Cannot buy " << items[idx].get_name() << ".\n";
    }

    cout << "Change: $" << result.change << endl;
}
