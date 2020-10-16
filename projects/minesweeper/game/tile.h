#pragma once
#include "util.h"

class Tile {
private:
    int _x;
    int _y;
    int _num;      // 주변에 있는 지뢰의 개수
    bool _is_open; // 타일을 오픈했는지 여부
public:
    Tile() : _x(0), _y(0), _num(0), _is_open(false) { }
    ~Tile() { }

    void draw();

    int get_tile_num() {
        return _num;
    }

    bool is_tile_open() {
        return _is_open;
    }

    void set_xy(int x, int y) {
        _x = x;
        _y = y;
    }

    void set_tile_num(int num) {
        _num = num;
    }

    void set_tile_open(bool open) {
        _is_open = open;
    }
};
