#pragma once
#include <iostream>
#include "shape.hpp"

class Circle : public Shape {
public:
    Circle(Color color, double radius) : Shape(color) {
        _radius = radius;
    }

    virtual double calc_area() override {
        return _radius * _radius * 3.14;
    }

    virtual void draw() override {
        using std::cout;
        using std::endl;

        cout << "[Circle]"
             << "\n\t"
             << "Color: " << _color.to_string() << "\n\t"
             << "Radius: " << _radius << "\n\t"
             << "Area: " << calc_area() << endl;
    }

private:
    double _radius;
};
