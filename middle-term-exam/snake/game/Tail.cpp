#include "Tail.h"
#include "util.h"

void Tail::draw(int type) {
    int x = getX();
    int y = getY();
    if (type == 0) { // 뱀의 머리 출력
        ScreenPrint(x, y, L"★");
    } else // 뱀의 꼬리 출력
        ScreenPrint(x, y, L"●");
}
