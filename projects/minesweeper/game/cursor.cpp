#include "cursor.h"
#include "util.h"

void Cursor::set_x(int x) {
    if (x < 0) {
        _x = 0;
        return;
    }

    if (x >= _col) {
        _x = _col - 1;
        return;
    }

    _x = x;
}

void Cursor::set_y(int y) {
    if (y < 0) {
        _y = 0;
        return;
    }

    if (y >= _row) {
        _y = _row - 1;
        return;
    }

    _y = y;
}

void Cursor::up() {
    set_y(_y - 1);
}

void Cursor::down() {
    set_y(_y + 1);
}

void Cursor::left() {
    set_x(_x - 1);
}

void Cursor::right() {
    set_x(_x + 1);
}

void Cursor::draw() {
    const char* img = "$";

    set_color(10);
    screen_print(_x, _y, img);
    set_color(15);
}
