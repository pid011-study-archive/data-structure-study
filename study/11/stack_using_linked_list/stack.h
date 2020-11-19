#pragma once
#include <cassert>

template<class T>
struct Node {
    T Data;
    Node* Next;
};

template<class T>
class Stack {
    Node<T>* _top;

public:
    Stack() : _top(nullptr) { }

    ~Stack() {
        while (!is_empty()) {
            pop();
        }
    }

    void push(T item) {
        Node<T>* in_node = new Node<T>;
        in_node->Data = item;
        in_node->Next = _top;
        _top = in_node;
    }

    T pop() {
        assert(!is_empty());

        Node<T>* del_node = _top;
        T pop_data = del_node->Data;
        _top = del_node->Next;
        delete del_node;

        return pop_data;
    }

    T top() {
        return is_empty() ? T{} : _top->Data;
    }

    bool is_empty() {
        return _top == nullptr;
    }
};
