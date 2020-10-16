#include "map.h"

Map::Map(int row, int col, int mine_count) : _row(row), _col(col), _mine_count(mine_count), _opened_tiles(0) {
    _tiles = new Tile*[_row];
    for (int i = 0; i < _row; i++) {
        _tiles[i] = new Tile[_col];
    }

    initialize_map();
}

Map::~Map() {
    for (int i = 0; i < _row; i++) {
        delete[] _tiles[i];
    }
    delete[] _tiles;
}

void Map::initialize_map() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis_col(0, _col - 1);
    std::uniform_int_distribution<int> dis_row(0, _row - 1);

    for (int i = 0; i < _mine_count; i++) {
        int x, y;
        do {
            x = dis_col(gen);
            y = dis_row(gen);
        } while (!plant_mine(x, y));
    }

    for (int y = 0; y < _row; y++) {
        for (int x = 0; x < _col; x++) {
            _tiles[y][x].set_xy(x, y);
            _tiles[y][x].set_tile_num(check_mine(x, y) ? _number_mine : calculate_cell(x, y));
        }
    }
}

bool Map::is_position_in_map(int x, int y) const {
    return x >= 0 && x < _col && y >= 0 && y < _row;
}

bool Map::plant_mine(int x, int y) {
    if (!is_position_in_map(x, y)) {
        return false;
    }

    if (_tiles[y][x].get_tile_num() == _number_mine) {
        return false;
    }

    _tiles[y][x].set_tile_num(_number_mine);
    return true;
}

int Map::calculate_cell(int x, int y) {
    int neighbor_mine = 0;

    for (int check_y = y - 1; check_y <= y + 1; check_y++) {
        for (int check_x = x - 1; check_x <= x + 1; check_x++) {
            if (check_x == x && check_y == y) {
                continue;
            }
            neighbor_mine += check_mine(check_x, check_y) ? 1 : 0;
        }
    }

    return neighbor_mine;
}

bool Map::check_mine(int x, int y) const {
    if (!is_position_in_map(x, y)) {
        return false;
    }

    return _tiles[y][x].get_tile_num() == _number_mine;
}

void Map::draw() const {
    for (int i = 0; i < _row; i++) {
        for (int j = 0; j < _col; j++) {
            _tiles[i][j].draw();
        }
    }
}

bool Map::open_tile(int x, int y) {
    Tile& tile = _tiles[y][x];
    if (!is_position_in_map(x, y) || tile.is_tile_open()) {
        return false;
    }

    tile.set_tile_open(true);
    _opened_tiles++;

    if (tile.get_tile_num() == 9) {
        return true;
    }

    if (tile.get_tile_num() == 0) {
        for (int check_y = y - 1; check_y <= y + 1; check_y++) {
            for (int check_x = x - 1; check_x <= x + 1; check_x++) {
                if (check_x == x && check_y == y) {
                    continue;
                }

                if (open_tile(check_x, check_y)) {
                    return true;
                }
            }
        }
    }

    return false;
}

//void Map::print() const {
//    for (int i = 0; i < _row; i++) {
//        for (int j = 0; j < _col; j++) {
//            char next = j < _col - 1 ? ' ' : '\n';
//
//            if (_map[i][j] == _number_mine) {
//                printf("%c%c", _symbol_mine, next);
//                continue;
//            }
//            printf("%d%c", _map[i][j], next);
//        }
//    }
//}
