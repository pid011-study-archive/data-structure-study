#include "map.hpp"
#include "minesweeper.hpp"

int main(int, char**) {
    Map* map = new Map(8, 8, 10);
    map->print();

    delete map;
}
