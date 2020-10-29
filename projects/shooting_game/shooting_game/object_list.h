#pragma once

class GameObject;

struct Node {
    GameObject* Object;
    Node* Next;
};

class ObjectList {
private:
    Node* _head;
    int _count;

public:
    ObjectList() : _head(nullptr), _count(0) { }
    ~ObjectList();

    int get_count() const {
        return _count;
    }

    void append(GameObject* obj);
    void insert(int idx, GameObject* obj);
    void remove(int idx);
    void remove(GameObject* obj);
    GameObject* get_object(int idx);
    int get_idx(GameObject* obj);
    void update();
    void draw();
};
