#pragma once
#include <assert.h>

class ArrayStack {
    // Top of the stack
    int _top;

    // Stack array
    int* _stack;

    // Stack size
    int _max;

public:
    ArrayStack(int max = 100) {
        _stack = new int[max];
        assert(_stack != nullptr);
    }

    ~ArrayStack() { delete[] _stack; }

    void push(int item) { is_full() ? -1 : _stack[_top++] = item; }

    int pop() { return is_empty() ? -9999 : _stack[--_top]; }

    int peek() { return is_empty() ? -9999 : _stack[_top - 1]; }

    bool is_empty() { return _top == 0; }

    bool is_full() { _top == _max; }

    int size() { return _top; }
};
