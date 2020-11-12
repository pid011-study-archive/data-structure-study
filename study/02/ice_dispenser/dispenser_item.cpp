#include "dispenser_item.h"

DispenserItem::DispenserItem() {
    name   = "Unknown";
    price  = 0;
    count  = 0;
    enable = false;
}

DispenserItem::DispenserItem(string name, int price, int count, bool enable) {
    this->name  = name;
    this->price = price;

    this->count = count;

    this->enable = count == 0 ? false : enable;
}

SelectResult DispenserItem::select(int input_money) {
    if (!enable || price > input_money) {
        return SelectResult { false, input_money };
    }

    count--;
    if (count == 0) {
        enable = false;
    }
    return SelectResult { true, input_money - price };
}
