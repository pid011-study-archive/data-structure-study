#pragma once
#include "color.hpp"

class Shape {
public:
    Shape() {
        _color = Color();
    }
    Shape(Color color) {
        _color = color;
    }

    void fill_color(Color color) {
        _color = color;
    }
    const Color get_color() {
        return _color;
    }

    virtual double calc_area() {
        return 0;
    }
    virtual void draw() { }

protected:
    Color _color;
};
