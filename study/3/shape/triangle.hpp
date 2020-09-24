#pragma once
#include <iostream>
#include "shape.hpp"
#include "color.hpp"

class Triangle : public Shape {
public:
    Triangle(Color color, double base, double height) : Shape(color) {
        _base = base;
        _height = height;
    }

    double get_base() {
        return _base;
    }

    double get_height() {
        return _height;
    }

    virtual double calc_area() override {
        return _base * _height / 2;
    }

    virtual void draw() override {
        using std::cout;
        using std::endl;
        cout << "[Triangle]"
             << "\n\t"
             << "Color: " << _color.to_string() << "\n\t"
             << "Base: " << _base << "\n\t"
             << "Height: " << _height << "\n\t"
             << "Area: " << calc_area() << endl;
    }

private:
    double _base;
    double _height;
};
