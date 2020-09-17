#pragma once

#include "dispenser_item.h"

#include <iostream>

using std::cout;
using std::endl;

class IceDispenser {
public:
    IceDispenser();
    ~IceDispenser();

    void show_items() const;
    void select_item(int idx, int input_money);

private:
    const int item_count;
    DispenserItem* items;
};
