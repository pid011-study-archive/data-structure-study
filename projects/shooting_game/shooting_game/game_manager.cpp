#include "game_manager.h"

GameManager* GameManager::get_instance() {
    static GameManager* manager = nullptr;
    if (!manager) {
        manager = new GameManager();
    }

    return manager;
}

bool GameManager::collide() {
    int bullet_count = _bullets->get_count();
    if (bullet_count == 0) {
        return false;
    }

    // 맵과 총알의 충돌처리
    for (int i = 0; i < bullet_count; i++) {
        GameObject* cur_bullet = _bullets->get_object(i);
        if (cur_bullet->get_y() < 1) {
            _bullets->remove(i);
        }
    }

    // 총알과 적기들과의 충돌 처리로직 구현. GameObject::is_collide() 활용
    return false;
}

void GameManager::update() {
    _plane->update();
    _bullets->update();
}

void GameManager::draw() {
    _plane->draw();
    _bullets->draw();
}
