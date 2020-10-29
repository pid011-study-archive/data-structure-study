#pragma once
#include "util.h"

class GameObject {
protected:
    int _x;
    int _y;
    const char* _img;

public:
    GameObject() : _x(0), _y(0), _img(" ") { }
    GameObject(int x, int y, const char* img) : _x(x), _y(y), _img(img) { }
    ~GameObject() { }

    int get_x() {
        return _x;
    }

    int get_y() {
        return _y;
    }

    const char* get_img() {
        return _img;
    }

    void set_xy(int x, int y) {
        _x = x;
        _y = y;
    }

    void set_img(const char* img) {
        _img = img;
    }

    virtual void update() { }

    bool is_collide(GameObject* other) {
        return _x == other->get_x() && _y == other->get_y();
    }

    void draw() {
        screen_print(_x, _y, _img);
    }
};
