﻿#pragma once

#include "tile.h"
#include <cstdio>
#include <random>

class Map {
private:
    const int _number_mine = 9;
    const int _row;
    const int _col;

    int _mine_count;
    Tile** _tiles;
    int _opened_tiles;
    bool _is_open;

    /**
     * @brief Fill the map to mines and empty cell
     *
     */
    void initialize_map();

    /**
     * @brief Check position is in the map
     *
     * @param x: position x
     * @param y: position y
     * @return Return true when position is in the map
     */
    bool is_position_in_map(int x, int y) const;

    /**
     * @brief Plant the mine
     *
     * @param x: Position x of mine to be planted
     * @param y: Position y of mine to be planted
     * @return Has mine planted
     */
    bool plant_mine(int x, int y);

    /**
     * @brief Returns the number of mines around the cell
     *
     * @param x: Position x
     * @param y: Position y
     * @return The number of mines
     */
    int calculate_cell(int x, int y);

public:
    Map(int row, int col, int mine_count);

    ~Map();

    /**
     * @brief Draw this map
    */
    void draw() const;
    // void print() const;

    /**
     * @brief Open the tile
     * @param x: Position x
     * @param y: Position y
     * @return Returns true if opened tile is a mine
    */
    bool open_tile(int x, int y);

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

    /**
     * @brief Returns opened tile count in the map
    */
    int get_opened_tile_count() const {
        return _opened_tiles;
    }

    bool check_mine(int x, int y) const;
};
