#pragma once

#include "array_stack.h"

enum class TokenType { Plus, Minus, Multi, Divide, Number, Blank, End };

class Calculator {
    char* _postfix;
    ArrayStack<float> _stack;
    float _result;
    int _read_pos;

public:
    Calculator(int max);

    ~Calculator() {
        delete[] _postfix;
    }

    float get_result() const {
        return _result;
    }

    void set_postfix(const char* postfix);
    TokenType get_token(char* token);
    void calculate();
    void draw();
};
