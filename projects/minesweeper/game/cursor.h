#pragma once
class Cursor {
private:
    int _x;
    int _y;
    const int _row;
    const int _col;

    void set_x(int x);
    void set_y(int y);

public:
    Cursor(int row, int col, int x = 0, int y = 0) : _row(row), _col(col), _x(x), _y(y) { }
    ~Cursor() { }

    int get_x() {
        return _x;
    }

    int get_y() {
        return _y;
    }

    void set_xy(int x, int y) {
        _x = x;
        _y = y;
    }

    void up();
    void down();
    void left();
    void right();
    void draw();
};
