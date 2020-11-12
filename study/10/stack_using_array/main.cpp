#include <iostream>
#include "array_stack.h"
using namespace std;

int main() {
    ArrayStack<int> int_stack(10);
    for (int i = 0; i < 5; i++) {
        int_stack.push(i);
    }

    while (!int_stack.is_empty()) {
        cout << int_stack.pop() << endl;
    }
}
