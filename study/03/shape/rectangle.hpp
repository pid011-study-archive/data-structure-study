#pragma once
#include <iostream>
#include "shape.hpp"

class Rectangle : public Shape {
public:
    Rectangle(Color color, double width, double height) : Shape(color) {
        _width  = width;
        _height = height;
    }

    double get_width() {
        return _width;
    }

    double get_height() {
        return _height;
    }

    virtual double calc_area() override {
        return _width * _height;
    }

    virtual void draw() override {
        using std::cout;
        using std::endl;

        cout << "[Rectangle]"
             << "\n\t"
             << "Color: " << _color.to_string() << "\n\t"
             << "Width: " << _width << "\n\t"
             << "Height: " << _height << "\n\t"
             << "Area: " << calc_area() << endl;
    }

private:
    double _width;
    double _height;
};
