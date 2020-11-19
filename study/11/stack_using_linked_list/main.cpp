#include <iostream>

#include "stack.h"
using namespace std;

void stack_test_int() {
    Stack<int> stack;
    for (int i = 0; i < 5; i++) {
        stack.push(i * 10);
    }

    do {
        cout << stack.pop() << endl;
    } while (!stack.is_empty());
}

void stack_test_double() {
    Stack<double> stack;
    for (double i = 0; i < 5; i++) {
        stack.push(i * 2.5);
    }

    do {
        cout << stack.pop() << endl;
    } while (!stack.is_empty());
}

int main() {
    stack_test_int();
    cout << endl;
    stack_test_double();
}
