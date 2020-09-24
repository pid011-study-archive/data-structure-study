#pragma once
#include <string>

class Color {
public:
    Color() {
        _r = 0;
        _g = 0;
        _b = 0;
    }
    Color(int r, int g, int b) {
        _r = r;
        _g = g;
        _b = b;
    }

    int get_r() {
        return _r;
    }

    int get_g() {
        return _g;
    }

    int get_b() {
        return _b;
    }

    std::string to_string() {
        return "(" + std::to_string(_r) + ", " + std::to_string(_g) + ", " + std::to_string(_b) + ")";
    }

private:
    int _r;
    int _g;
    int _b;
};
