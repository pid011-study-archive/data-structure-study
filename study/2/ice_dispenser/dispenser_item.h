#pragma once

#include <iostream>

using std::string;

struct SelectResult
{
    bool succeed;
    int change;
};

class DispenserItem
{
public:
    DispenserItem();
    DispenserItem(string name, int price, int count, bool enable);

    string get_name()
    {
        return name;
    }

    unsigned int get_price()
    {
        return price;
    }

    unsigned int get_count()
    {
        return count;
    }

    bool get_enable()
    {
        return enable;
    }

    SelectResult select(int input_money);

private:
    string name;
    int price;
    int count;
    bool enable;
};

