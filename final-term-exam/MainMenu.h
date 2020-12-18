#pragma once
#include "BaseMenu.h"
#include "MenuStack.h"

class MenuStack;

class MainMenu : public BaseMenu {
public:
    virtual void ShowMenu() override;
    virtual void Process(int menuIndex, MenuStack& menuStack) override;
};
