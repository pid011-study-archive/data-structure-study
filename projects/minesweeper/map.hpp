#pragma once

#include <cstdio>
#include <cstdlib>

class Map {
private:
    const int _number_mine = -1;
    const char _symbol_mine = '*';

    const int _row;
    const int _col;
    const int _mine_count;
    int** _map;

    /**
     * @brief Fill the map to mines and empty cell
     *
     */
    void initialize_map() {
        for (int i = 0; i < _mine_count; i++) {
            int x, y;
            do {
                x = rand() % _col;
                y = rand() % _row;
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

    /**
     * @brief Check position is in the map
     *
     * @param x position x
     * @param y position y
     * @return Return true when position is in the map
     */
    bool is_position_in_map(int x, int y) const {
        return x < 0 || x >= _col || y < 0 || y >= _row;
    }

    /**
     * @brief Plant the mine
     *
     * @param x Position x of mine to be planted
     * @param y Position y of mine to be planted
     * @return Has mine planted
     */
    bool plant_mine(int x, int y) {
        if (is_position_in_map(x, y)) {
            return false;
        }

        if (_map[y][x] == _number_mine) {
            return false;
        }

        _map[y][x] = _number_mine;
        return true;
    }

    /**
     * @brief Returns the number of mines around the cell
     *
     * @param x Position x
     * @param y Position y
     * @return The number of mines
     */
    int calculate_cell(int x, int y) {
        int neighbor_mine = 0;

        for (int check_y = y - 1; check_y <= y + 1; check_y++) {
            for (int check_x = x - 1; check_x <= x + 1; check_x++) {
                neighbor_mine += check_mine(check_x, check_y) ? 1 : 0;
            }
        }

        return neighbor_mine;
    }

    bool check_mine(int x, int y) const {
        if (is_position_in_map(x, y)) {
            return false;
        }

        return _map[y][x] == _number_mine;
    }

public:
    Map(int row, int col, int mine_count)
        : _row(row), _col(col), _mine_count(mine_count) {
        _map = new int*[_row];
        for (int i = 0; i < _row; i++) {
            _map[i] = new int[_col];
        }

        initialize_map();
    }

    ~Map() {
        for (int i = 0; i < _row; i++) {
            delete[] _map[i];
        }
        delete[] _map;
    }

    void print() const {
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

    /**
     * @brief Returns row of the map
     */
    int get_row() const {
        return _row;
    }

    /**
     * @brief Returns column of the map
     */
    int get_col() const {
        return _col;
    }

    /**
     * @brief Returns mines count in the map
     */
    int get_mine_count() const {
        return _mine_count;
    }
};
