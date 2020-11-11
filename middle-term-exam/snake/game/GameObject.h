#pragma once
class GameObject {
    int m_x;
    int m_y;

public:
    GameObject() : m_x(0), m_y(0) { }
    ~GameObject() { }
    GameObject(int x, int y) : m_x(x), m_y(y) { }
    int getX() {
        return m_x;
    }
    int getY() {
        return m_y;
    }
    void setXY(int x, int y) {
        m_x = x;
        m_y = y;
    }
    virtual void draw(int type) = 0;
};
