#include "MenuStack.h"

MenuStack::~MenuStack() {
    for (auto iter = stack.begin(); iter != stack.end(); iter++) {
        delete *iter;
    }
    stack.~deque();
}

void MenuStack::Push(BaseMenu* item) {
    stack.push_front(item);
}

bool MenuStack::Pop() {
    if (IsEmpty()) {
        return false;
    }
    delete stack[0];
    stack.pop_front();
    return true;
}

bool MenuStack::Peek(BaseMenu*& retval) {
    if (IsEmpty()) {
        return false;
    }
    retval = stack[0];
    return true;
}

size_t MenuStack::Count() {
    return stack.size();
}

bool MenuStack::IsEmpty() {
    return Count() == 0;
}
