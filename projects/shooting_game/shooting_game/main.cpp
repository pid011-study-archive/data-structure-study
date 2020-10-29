#include "bullet.h"
#include "game_manager.h"
#include "game_object.h"
#include "plane.h"
#include <Windows.h>
#include <iostream>
#include <time.h>

int main() {
    const int WIDTH = 30;
    const int HEIGHT = 18;
    Plane* plane = new Plane(15, 16, "▲");
    ObjectList* bullets = new ObjectList;

    GameManager::get_instance()->init_game(plane, bullets, WIDTH, HEIGHT);

    screen_init();

    bool is_stop = false;
    clock_t old_time, cur_time;
    old_time = clock();

    // game loop
    while (!is_stop) {
        screen_clear();

        GameManager::get_instance()->update();

        char str[30];
        sprintf_s(str, "bullet count: %d", bullets->get_count());
        screen_print(1, 20, str);

        GameManager::get_instance()->collide();
        GameManager::get_instance()->draw();

        screen_flipping();

        while (true) {
            cur_time = clock();
            if (cur_time - old_time > 33) {
                old_time = cur_time;
                break;
            }
        }
    }
}
