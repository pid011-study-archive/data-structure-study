#pragma once
#include <iostream>

struct Node {
    int Data;
    Node* Next;
};

class LinkedList {
private:
    Node* _head = nullptr;
    int _count = 0;

public:
    LinkedList();
    ~LinkedList();

    void add_first(int data);
    void add_last(int data);
    void insert(int idx, int data);
    void remove(int idx);
    int retreive(int idx);
    const Node* head() const {
        return _head;
    }
    int length() {
        return _count;
    }
};
