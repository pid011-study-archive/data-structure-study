#include "object_list.h"
#include "game_object.h"

ObjectList::~ObjectList() {
    Node* cur_node = _head;
    while (cur_node != nullptr) {
        Node* tmp_node = cur_node;
        cur_node = cur_node->Next;
        delete tmp_node;
    }
}

void ObjectList::append(GameObject* obj) {
    insert(_count - 1, obj);
}

void ObjectList::insert(int idx, GameObject* obj) {
    if (idx < 0 || idx > _count) {
        return;
    }

    Node* cur_node = _head;
    Node* insert_node = new Node;
    insert_node->Object = obj;

    if (idx == 0) {
        insert_node->Next = _head;
        _head = insert_node;
    } else {
        Node* tmp_node = _head;
        for (int i = 0; i < idx - 1; i++) {
            tmp_node = tmp_node->Next;
        }
        insert_node->Next = tmp_node->Next;
        tmp_node->Next = insert_node;
    }
    _count++;
}

void ObjectList::remove(int idx) {
    if (_count == 0) {
        return;
    }
    if (idx < 0 || idx > _count) {
        return;
    }

    if (idx == 0) {
        Node* cur_node = _head->Next;
        delete _head;
        _head = cur_node;
    } else {
        Node* cur_node = _head;
        for (int i = 0; i < idx - 1; i++) {
            cur_node = cur_node->Next;
        }
        Node* next = cur_node->Next->Next;
        delete cur_node->Next;
        cur_node->Next = next;
    }
    _count--;
}

void ObjectList::remove(GameObject* obj) {
    int idx = get_idx(obj);
    remove(idx);
}

GameObject* ObjectList::get_object(int idx) {
    if (idx < 0 || idx >= _count || _head == nullptr) {
        return nullptr;
    }

    Node* cur_node = _head;
    for (int i = 0; i < _count; i++, cur_node = cur_node->Next) {
        if (i == idx) {
            return cur_node->Object;
        }
    }

    return nullptr;
}

int ObjectList::get_idx(GameObject* obj) {
    int x = obj->get_x();
    int y = obj->get_y();
    Node* cur_node = _head;
    for (int i = 0; i < _count; i++, cur_node = cur_node->Next) {
        if (cur_node->Object->get_x() == x && cur_node->Object->get_y() == y) {
            return i;
        }
    }

    return -1;
}

void ObjectList::update() {
    Node* cur_node = _head;
    for (int i = 0; i < _count; i++, cur_node = cur_node->Next) {
        cur_node->Object->update();
    }
}

void ObjectList::draw() {
    Node* cur_node = _head;
    for (int i = 0; i < _count; i++, cur_node = cur_node->Next) {
        cur_node->Object->draw();
    }
}
