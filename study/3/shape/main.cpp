#include "triangle.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "shape.hpp"

int main() {
    auto t = Triangle(Color(252, 3, 3), 4, 10);
    auto c = Circle(Color(252, 235, 3), 7);
    auto r = Rectangle(Color(3, 53, 252), 9, 9);

    t.draw();
    c.draw();
    r.draw();
}
