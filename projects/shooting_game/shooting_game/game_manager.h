#pragma once
#include "object_list.h"
#include "plane.h"

class GameManager {
private:
    GameObject* _plane;
    ObjectList* _bullets;
    int _width;
    int _height;

    // Singleton initializer
    GameManager() : _plane(nullptr), _bullets(nullptr), _width(0), _height(0) { }

public:
    // Singleton instance
    static GameManager* get_instance();

    void init_game(GameObject* plane, ObjectList* bullets, int width, int height) {
        _plane = plane;
        _bullets = bullets;
        _width = width;
        _height = height;
    }

    GameObject* get_plane() const {
        return _plane;
    }

    ObjectList* get_bullets() const {
        return _bullets;
    }

    int get_width() const {
        return _width;
    }

    int get_height() const {
        return _height;
    }

    bool collide();
    void update();
    void draw();
};
