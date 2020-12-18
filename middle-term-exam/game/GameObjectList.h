#pragma once

class GameObject;
struct node {
    GameObject* object;
    node* next;
};

class GameObjectList {
    node* m_head;
    int m_count;

public:
    GameObjectList() : m_head(nullptr), m_count(0) { }
    ~GameObjectList();

    void insert(int pos, GameObject* obj);
    void append(GameObject* obj); // 리스트의 마지막 위치에 추가
    void remove(int pos);
    void remove(GameObject* obj);
    GameObject* retrieve(int pos);
    int getPos(GameObject* obj);
    int getCount() const {
        return m_count;
    }

    void draw();
};
