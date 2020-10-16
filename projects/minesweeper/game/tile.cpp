#include "tile.h"

void Tile::draw() {
    const char* tile_img[] { "0", "1", "2", "3", "4", "5", "6", "7", "8", "M", "■" };

    if (_is_open) {
        if (_num == 9) {
            set_color(12);
            screen_print(_x, _y, tile_img[_num]);
            set_color(15);
        } else {
            screen_print(_x, _y, tile_img[_num]);
        }
    } else {
        screen_print(_x, _y, tile_img[10]);
    }
}
