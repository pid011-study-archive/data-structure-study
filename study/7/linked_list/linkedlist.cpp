#include "linkedlist.hpp"

LinkedList::LinkedList() { }

LinkedList::~LinkedList() {
    Node* cnode = _head;
    while (cnode != nullptr) {
        Node* tmpnode = cnode;
        cnode = cnode->Next;
        delete tmpnode;
    }
}

void LinkedList::add_first(int data) {
    Node* tmpnode = _head;
    _head = new Node { data, tmpnode };
    _count++;
}

void LinkedList::add_last(int data) {
    if (_count == 0) {
        _head = new Node { data, nullptr };
        _count++;
        return;
    }
    insert(_count, data);
}

void LinkedList::insert(int idx, int data) {
    if (idx < 0 || idx > _count) {
        std::cout << "Index out of range!" << std::endl;
        return;
    }

    Node* insert_node = new Node { data, nullptr };

    if (idx == 0) {
        insert_node->Next = _head;
        _head = insert_node;
    } else {
        Node* tmpnode = _head;
        for (size_t i = 0; i < idx - 1; i++) {
            tmpnode = tmpnode->Next;
        }
        insert_node->Next = tmpnode->Next;
        tmpnode->Next = insert_node;
    }
    _count++;
}

void LinkedList::remove(int idx) {
    if (_count == 0) {
        std::cout << "There is nothing to delete it." << std::endl;
        return;
    }
    if (idx < 0 || idx > _count) {
        std::cout << "Index out of range!" << std::endl;
        return;
    }

    if (idx == 0) {
        Node* tmpnode = _head->Next;
        delete _head;
        _head = tmpnode;
    } else {
        Node* tmpnode = _head;
        for (size_t i = 0; i < idx - 1; i++) {
            tmpnode = tmpnode->Next;
        }
        Node* next = tmpnode->Next->Next;
        delete tmpnode->Next;
        tmpnode->Next = next;
    }
    _count--;
}

int LinkedList::retreive(int idx) {
    if (_count == 0) {
        std::cout << "There is nothing to return." << std::endl;
        return 0;
    }
    if (idx < 0 || idx > _count) {
        std::cout << "Index out of range!" << std::endl;
        return 0;
    }

    Node* target = _head;
    for (size_t i = 0; i < idx; i++) {
        target = target->Next;
    }

    return target->Data;
}
