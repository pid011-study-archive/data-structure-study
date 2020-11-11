#include "GameObjectList.h"
#include "GameObject.h"

GameObjectList::~GameObjectList() {
    node* current_node = m_head;
    while (current_node != nullptr) {
        node* tmp_node = current_node;
        current_node = current_node->next;
        delete tmp_node;
    }
}

void GameObjectList::insert(int pos, GameObject* obj) {
    if (pos < 0 || pos > m_count) {
        return;
    }

    node* current_node = m_head;
    node* insert_node = new node;
    insert_node->object = obj;
    if (pos == 0) {
        insert_node->next = m_head;
        m_head = insert_node;
    } else {
        node* tmp_node = m_head;
        for (int i = 0; i < pos - 1; i++) {
            tmp_node = tmp_node->next;
        }

        insert_node->next = tmp_node->next;
        tmp_node->next = insert_node;
    }

    m_count++;
}

void GameObjectList::append(GameObject* obj) {
    insert(m_count, obj);
}

void GameObjectList::remove(int pos) {
    if (m_count == 0) {
        return;
    }
    if (pos < 0 || pos > m_count) {
        return;
    }

    if (pos == 0) {
        node* current_node = m_head->next;
        delete m_head;
        m_head = current_node;
    } else {
        node* current_node = m_head;
        for (int i = 0; i < pos - 1; i++) {
            current_node = current_node->next;
        }
        node* next_node = current_node->next->next;
        delete current_node->next;
        current_node->next = next_node;
    }
    m_count--;
}

void GameObjectList::remove(GameObject* obj) {
    int pos = getPos(obj);
    remove(pos);
}

GameObject* GameObjectList::retrieve(int pos) {
    if (pos < 0 || pos >= m_count || m_head == nullptr) {
        return nullptr;
    }

    node* current_node = m_head;
    for (int i = 0; i < m_count; i++, current_node = current_node->next) {
        if (i == pos) {
            return current_node->object;
        }
    }

    return nullptr;
}

int GameObjectList::getPos(GameObject* obj) {
    int x = obj->getX();
    int y = obj->getY();
    node* current_node = m_head;
    for (int i = 0; i < m_count; i++, current_node = current_node->next) {
        if (current_node->object->getX() == x && current_node->object->getY() == y) {
            return i;
        }
    }

    return -1;
}

void GameObjectList::draw() {
    node* current_node = m_head;
    current_node->object->draw(0);
    current_node = current_node->next;
    for (int i = 1; i < m_count; i++, current_node = current_node->next) {
        current_node->object->draw(1);
    }
}
