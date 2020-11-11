#include "GameMap.h"
#include "util.h"

GameMap::GameMap() {
    m_width = 30;
    m_height = 30;
    m_map = new int*[m_height];
    for (int i = 0; i < m_height; i++)
        m_map[i] = new int[m_width];
    initMap();
}

GameMap::~GameMap() {
    if (m_map) {
        for (int i = 0; i < m_height; i++)
            delete[] m_map[i];
        delete[] m_map;
    }
}

void GameMap::initMap() {
    TILETYPE t;
    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {
            t = (x == 0 || x == m_width - 1 || y == 0 || y == m_height - 1) ? WALL : BLANK;
            m_map[y][x] = t;
        }
    }
}

void GameMap::draw() {
    const wchar_t* tileImg[] = { L" ", L"▩" };
    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {
            ScreenPrint(x, y, tileImg[m_map[y][x]]);
        }
    }
}
