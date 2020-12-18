#pragma once
#include "GameObjectList.h"
#include "util.h"

typedef int DIR;

class Snake {
    GameObjectList* m_tails;
    DIR m_dir;

public:
    ~Snake();
    Snake();
    GameObjectList* getList() {
        return m_tails;
    }

    /**
     * @brief 방향전환
     * @param d 0: UP, 1: DOWN, 2: LEFT, 3: RIGHT
    */
    void setDir(DIR d) {
        m_dir = d;
    } // 방향전환 설정

    void update(); // 매 프레임마다 상태 업데이트 ==> 구현할 내용

    void draw() {
        m_tails->draw();
    }
};
