#pragma once
#include <assert.h>

template<class T>
class ArrayStack {
    // Top of the stack
    int _top;

    // Stack array
    T* _stack;

    // Stack size
    int _max;

public:
    ArrayStack(int max = 100) : _top(0), _max(max) {
        _stack = new T[max];
        assert(_stack != nullptr);
    }

    ~ArrayStack() {
        delete[] _stack;
    }

    void push(T item) {
        is_full() ? -1 : _stack[_top++] = item;
    }

    T pop() {
        return is_empty() ? T() : _stack[--_top];
    }

    T peek() {
        return is_empty() ? T() : _stack[_top - 1];
    }

    bool is_empty() {
        return _top == 0;
    }

    bool is_full() {
        return _top == _max;
    }

    int size() {
        return _top;
    }
};
