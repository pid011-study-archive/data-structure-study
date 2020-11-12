#define _CRT_SECURE_NO_WARNINGS

#include "calculator.h"

#include <cassert>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

const string _operation = "+-*/";

Calculator::Calculator(int max = 100) : _result{0.0f}, _read_pos{0} {
    _postfix = new char[max];
    assert(_postfix != nullptr);
}

void Calculator::set_postfix(const char* postfix) {
    size_t len = strlen(postfix) + 1;
    _postfix = new char[len];
    strncpy(_postfix, postfix, len);
}

TokenType Calculator::get_token(char* token) {
    int token_pos{0};
    switch (_postfix[_read_pos]) {
    case '+':
        token[token_pos++] = _postfix[_read_pos++];
        token[token_pos] = '\0';
        return TokenType::Plus;
    case '-':
        token[token_pos++] = _postfix[_read_pos++];
        token[token_pos] = '\0';
        return TokenType::Minus;
    case '*':
        token[token_pos++] = _postfix[_read_pos++];
        token[token_pos] = '\0';
        return TokenType::Multi;
    case '/':
        token[token_pos++] = _postfix[_read_pos++];
        token[token_pos] = '\0';
        return TokenType::Divide;
    case ' ':
        _read_pos++;
        return TokenType::Blank;
    case '\0':
    case '=':
        return TokenType::End;
    default:
        while (_postfix[_read_pos] >= '0' && _postfix[_read_pos] <= '9') {
            token[token_pos++] = _postfix[_read_pos++];
        }
        token[token_pos] = '\0';
        return TokenType::Number;
    }

    return TokenType::End;
}

void Calculator::calculate() {
    float pop1{0.0f}, pop2{0.0f};
    float number{0.0f};
    char token[20];
    _read_pos = 0;
    TokenType current_token;
    while ((current_token = get_token(token)) != TokenType::End) {
        switch (current_token) {
        case TokenType::Plus:
            pop2 = _stack.pop();
            pop1 = _stack.pop();
            _stack.push(pop1 + pop2);
            break;

        case TokenType::Minus:
            pop2 = _stack.pop();
            pop1 = _stack.pop();
            _stack.push(pop1 - pop2);
            break;

        case TokenType::Multi:
            pop2 = _stack.pop();
            pop1 = _stack.pop();
            _stack.push(pop1 * pop2);
            break;

        case TokenType::Divide:
            pop2 = _stack.pop();
            pop1 = _stack.pop();
            _stack.push(pop1 / pop2);
            break;

        case TokenType::Number:
            number = 0.0f;
            for (int i = 0; token[i] != '\0'; i++) {
                number = 10.0f * number + token[i] - '0';
            }
            _stack.push(number);
            break;

        case TokenType::Blank:
            break;

        case TokenType::End:
            break;

        default:
            break;
        }
    }

    _result = _stack.pop();
}

void Calculator::draw() {
    cout << "Postfix: " << _postfix << " = " << _result << endl;
}
