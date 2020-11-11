#pragma once
enum TILETYPE { BLANK, WALL };
class GameMap {
    int** m_map;
    int m_width;
    int m_height;

public:
    GameMap();
    ~GameMap();
    GameMap(int w, int h) : m_width(w), m_height(h) {
        m_map = new int*[h];
        for (int i = 0; i < h; i++)
            m_map[i] = new int[w];
        initMap();
    }
    int getWidth() {
        return m_width;
    }
    int getHeight() {
        return m_height;
    }
    void initMap();
    void draw();
};
