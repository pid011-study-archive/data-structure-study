#pragma once

template<class T>
class Queue {
    T* _queue;
    size_t _size;
    size_t _tail;
    size_t _max;
    size_t _front;

public:
    Queue(size_t size = 100) : _front(0), _tail(0), _size(0), _max(size) {
        _queue = new T[size];
    }

    ~Queue() {
        delete[] _queue;
    }

    void enqueue(T item);
    T dequeue();
    bool is_empty() { return _size == 0; }
    bool is_full() { return _size == _max; }
    int get_front() { return is_empty() ? T() : _queue[_front]; }
    int size() { return _size; }
};

template<class T>
void Queue<T>::enqueue(T item) {
    /*if (!is_full()) {
        _queue[_tail] = item;
        if (++_tail == _max) {
            _tail = 0;
        }
    }*/
    if (!is_full()) {
        _queue[_tail] = item;
        _tail = (_tail + 1) % _max;
        _size++;
    }
}
template<class T>
T Queue<T>::dequeue() {
    if (!is_empty()) {
        T retval = _queue[_front];
        _front = (_front + 1) % _max;
        _size--;
        return retval;
    }
    return T();
}
