#include "map.hpp"

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
            if (check_mine(x, y)) {
                continue;
            }
            _map[y][x] = calculate_cell(x, y);
        }
    }
}

bool Map::is_position_in_map(int x, int y) const {
    return x < 0 || x >= _col || y < 0 || y >= _row;
}

bool Map::plant_mine(int x, int y) {
    if (is_position_in_map(x, y)) {
        return false;
    }

    if (_map[y][x] == _number_mine) {
        return false;
    }

    _map[y][x] = _number_mine;
    return true;
}

int Map::calculate_cell(int x, int y) {
    int neighbor_mine = 0;

    for (int check_y = y - 1; check_y <= y + 1; check_y++) {
        for (int check_x = x - 1; check_x <= x + 1; check_x++) {
            neighbor_mine += check_mine(check_x, check_y) ? 1 : 0;
        }
    }

    return neighbor_mine;
}

bool Map::check_mine(int x, int y) const {
    if (is_position_in_map(x, y)) {
        return false;
    }

    return _map[y][x] == _number_mine;
}

Map::Map(int row, int col, int mine_count) : _row(row), _col(col), _mine_count(mine_count) {
    _map = new int*[_row];
    for (int i = 0; i < _row; i++) {
        _map[i] = new int[_col];
    }

    initialize_map();
}

Map::~Map() {
    for (int i = 0; i < _row; i++) {
        delete[] _map[i];
    }
    delete[] _map;
}

void Map::print() const {
    for (int i = 0; i < _row; i++) {
        for (int j = 0; j < _col; j++) {
            char next = j < _col - 1 ? ' ' : '\n';

            if (_map[i][j] == _number_mine) {
                printf("%c%c", _symbol_mine, next);
                continue;
            }
            printf("%d%c", _map[i][j], next);
        }
    }
}
