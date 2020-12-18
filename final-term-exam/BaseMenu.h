#pragma once
#include "MenuStack.h"

class MenuStack;

class BaseMenu {
public:
    BaseMenu() { }
    virtual void ShowMenu() = 0;
    virtual void Process(int menuIndex, MenuStack& menuStack) = 0;
};
