#include "Snake.h"
#include "Tail.h"
#include <conio.h>

Snake::Snake() {
    m_tails = new GameObjectList;
    m_tails->append(new Tail(1, 1));
    m_dir = 1;
}

Snake::~Snake() {
    delete m_tails;
}

void Snake::update() {
    auto* head = m_tails->retrieve(0);
    int previous_x = head->getX(), previous_y = head->getY();
    // 0: UP, 1: DOWN, 2: LEFT, 3: RIGHT
    switch (m_dir) {
    case 0:
        head->setXY(previous_x, previous_y - 1);
        break;

    case 1:
        head->setXY(previous_x, previous_y + 1);
        break;

    case 2:
        head->setXY(previous_x - 1, previous_y);
        break;

    case 3:
        head->setXY(previous_x + 1, previous_y);
        break;

    default:
        break;
    }

    for (int i = 1; i < m_tails->getCount(); i++) {
        auto* tmp = m_tails->retrieve(i);
        tmp->setXY(previous_x, previous_y);
        previous_x = tmp->getX();
        previous_y = tmp->getY();
    }
}
