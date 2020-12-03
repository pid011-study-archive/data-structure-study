#pragma once

namespace MyQueue {
    template<class T>
    struct Node {
        T data;
        Node* next;
    };

    template<class T>
    class Queue {
        Node<T>* _head{nullptr};
        Node<T>* _tail{nullptr};
        size_t _length{0};

    public:
        ~Queue() {
            while (_length != 0) {
                T out;
                dequeue(out);
            }
        }
        void enqueue(T item);
        bool dequeue(T& out);
        const Node<T>* first() { return _head; }
        const Node<T>* last() { return _tail; }
        size_t length() { return _length; }
    };

    template<class T>
    void Queue<T>::enqueue(T item) {
        auto* data = new Node<T>{item, nullptr};
        if (_length == 0) {
            _head = data;
            _tail = _head;
        } else {
            _tail->next = data;
            _tail = data;
        }
        _length++;
    }

    template<class T>
    bool Queue<T>::dequeue(T& out) {
        if (_length == 0) {
            return false;
        }

        out = _head->data;
        auto* last = _head->next;
        delete _head;
        _head = last;

        if (--_length == 0) {
            _head = _tail = nullptr;
        }

        return true;
    }

} // namespace MyQueue
