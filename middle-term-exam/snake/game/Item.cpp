#include "Item.h"
#include "util.h"

void Item::draw(int type) {
    int x = getX();
    int y = getY();
    ScreenPrint(x, y, L"■");
}
