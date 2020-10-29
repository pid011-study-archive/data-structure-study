#include "plane.h"
#include "bullet.h"
#include "game_manager.h"
#include <conio.h>

/**
 * @brief 키보드 왼쪽 오른쪽 방향키 -> 이동, 스페이스바 -> 총알 발사
*/
void Plane::update() {
    int input_key;
    if (_kbhit()) {
        input_key = _getch();
        switch (input_key) {
        case LEFT:
            if (_x - 1 > 0) { // 왼쪽으로 갈 수 있는지 판단
                _x--;
            }
            break;
        case RIGHT:
            if (_x + 1 < GameManager::get_instance()->get_width()) { // 오른쪽으로 갈 수 있는지 판단
                _x++;
            }
            break;
        case SPACE:
            GameManager::get_instance()->get_bullets()->insert(0, new Bullet(_x, _y - 1, "^"));
            break;
        default:
            break;
        }
    }
}
