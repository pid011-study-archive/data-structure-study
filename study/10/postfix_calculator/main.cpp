#include <iostream>
#include <string>

#include "calculator.h"

using namespace std;

int main() {
    auto calc = Calculator(100);
    char test_form[100] = "3 5 + =";
    calc.set_postfix(test_form);
    calc.calculate();
    calc.draw();
}
