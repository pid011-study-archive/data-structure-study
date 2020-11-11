#pragma once
#include "GameObject.h"
class Item : public GameObject {
public:
    Item() { }
    ~Item() { }
    Item(int x, int y) : GameObject(x, y) { }
    void draw(int type) override;
};
