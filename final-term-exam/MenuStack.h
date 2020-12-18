#pragma once
#include <deque>

#include "BaseMenu.h"

class BaseMenu;

class MenuStack {
    std::deque<BaseMenu*> stack;

public:
    ~MenuStack();
    void Push(BaseMenu* item);
    bool Pop();
    bool Peek(BaseMenu*& retval);
    size_t Count();
    bool IsEmpty();
};
