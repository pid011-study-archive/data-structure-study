#pragma once
#include "GameObject.h"
class Tail : public GameObject {
public:
    Tail() { }
    ~Tail() { }
    Tail(int x, int y) : GameObject(x, y) { }
    void draw(int type) override;
};
