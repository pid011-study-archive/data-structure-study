#include <iostream>
using namespace std;

class IntList {
private:
    int* _data;
    int _count;
    int _capacity;

    void resize_list() {
        _capacity *= 2;
        int* copy = new int[_capacity];
        for (size_t i = 0; i < _count; i++) {
            copy[i] = _data[i];
        }
        delete[] _data;
        _data = copy;
    }

public:
    IntList(int capacity = 50) : _capacity(capacity), _count(0) {
        _data = new int[capacity];
        _count = 0;
    }

    IntList(IntList& copy) : _capacity(copy._capacity), _count(copy._count) {
        _data = new int[copy._capacity];
        for (size_t i = 0; i < copy._count; i++) {
            _data[i] = copy._data[i];
        }
    }

    ~IntList() {
        delete[] _data;
    }

    void add(int item) {
        if (_count == _capacity) {
            resize_list();
        }

        _data[_count] = item;
        _count++;
    }

    void insert(int idx, int item) {
        if (idx < 0 || idx > _count - 1) {
            cout << "Index out of range." << endl;
            return;
        }

        if (_count == _capacity) {
            resize_list();
        }

        for (size_t i = _count; i > idx; i--) {
            _data[i] = _data[i - 1];
        }
        _data[idx] = item;
        _count++;
    }

    void remove(int idx) {
        if (idx < 0 || idx > _count - 1) {
            cout << "Index out of range." << endl;
            return;
        }

        for (size_t i = idx; i < _count - 1; i++) {
            _data[i] = _data[i + 1];
        }
        _count--;
    }

    int retrieve(int idx) {
        if (idx < 0 || idx > _count - 1) {
            cout << "Index out of range." << endl;
            return 0;
        }

        return _data[idx];
    }

    int length() {
        return _count;
    }

    int capacity() {
        return _capacity;
    }
};

inline void print_list(IntList& list) {
    for (size_t i = 0; i < list.length(); i++) {
        cout << list.retrieve(i) << " ";
    }
    cout << endl;
}

inline void print_list_info(IntList& list) {
    print_list(list);
    cout << "length: " << list.length() << ", capacity: " << list.capacity() << endl;
}

int main(int, char**) {
    IntList* list = new IntList(5);

    cout << "[Add items]" << endl;
    for (size_t i = 0; i < 10; i++) {
        list->add(i * 2);
        print_list(*list);
        cout << "length: " << list->length() << ", capacity: " << list->capacity() << endl;
    }

    cout << endl;

    cout << "[Insert 100 to index 2]" << endl;
    list->insert(2, 100);
    print_list_info(*list);

    cout << endl;

    cout << "[Insert 99 to index 10]" << endl;
    list->insert(10, 99);
    print_list_info(*list);

    cout << endl;

    cout << "[Remove index 5]" << endl;
    list->remove(5);
    print_list_info(*list);

    delete list;
}

/*
--OUTPUT--
[Add items]
0
length: 1, capacity: 5
0 2
length: 2, capacity: 5
0 2 4
length: 3, capacity: 5
0 2 4 6
length: 4, capacity: 5
0 2 4 6 8
length: 5, capacity: 5
0 2 4 6 8 10
length: 6, capacity: 10
0 2 4 6 8 10 12
length: 7, capacity: 10
0 2 4 6 8 10 12 14
length: 8, capacity: 10
0 2 4 6 8 10 12 14 16
length: 9, capacity: 10
0 2 4 6 8 10 12 14 16 18
length: 10, capacity: 10

[Insert 100 to index 2]
0 2 100 4 6 8 10 12 14 16 18
length: 11, capacity: 20

[Insert 99 to index 10]
0 2 100 4 6 8 10 12 14 16 99 18
length: 12, capacity: 20

[Remove index 5]
0 2 100 4 6 10 12 14 16 99 18
length: 11, capacity: 20
*/
