#include "cursor.h"
#include "map.h"
#include "tile.h"
#include "util.h"
#include <conio.h>
#include <string>
#include <time.h>

int main(int, char**) {
    Map* map = new Map(15, 15, 10);
    Cursor cursor(15, 15);

    screen_init();
    // ScreenClear();

    int cur_time, old_time = clock();
    bool game_end = false;
    bool loop_break = false;
    string game_end_string;

    while (true) {
        int key;
        if (_kbhit()) {
            key = _getch();
            switch (key) {
            case UP:
                cursor.up();
                break;
            case DOWN:
                cursor.down();
                break;
            case LEFT:
                cursor.left();
                break;
            case RIGHT:
                cursor.right();
                break;
            case SPACE:
                if (game_end) {
                    loop_break = true;
                } else {
                    // Loose
                    if (map->open_tile(cursor.get_x(), cursor.get_y())) {
                        game_end_string = "You loose...";
                        game_end = true;

                        // Open all mines
                        for (int i = 0; i < map->get_row(); i++) {
                            for (int j = 0; j < map->get_col(); j++) {
                                if (map->check_mine(j, i)) {
                                    map->open_tile(j, i);
                                }
                            }
                        }
                    }
                }

                break;
            default:
                break;
            }
        }

        // Win
        if (map->get_opened_tile_count() == map->get_col() * map->get_row() - map->get_mine_count()) {
            game_end_string = "You win!";
            game_end = true;
        }

        if (game_end) {
            screen_print(0, map->get_row(), game_end_string.c_str());
            screen_print(0, map->get_row() + 1, "Press space to exit the game.");
        }

        map->draw();
        cursor.draw();
        screen_flipping();

        // delay
        while (true) {
            cur_time = clock();
            if (cur_time - old_time > 33) {
                old_time = cur_time;
                break;
            }
        }

        if (loop_break) {
            break;
        }
    }

    screen_release();
    delete map;
}
