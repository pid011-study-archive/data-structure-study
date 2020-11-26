#include <iostream>

#include "queue.h"
using namespace std;

int main() {
    {
        Queue<int> queue(5);
        for (int i = 0; i < 7; i++) {
            queue.enqueue(i * 10);
        }
        cout << "data size: " << queue.size() << endl;
        cout << "Dequeue..." << endl;
        cout << queue.dequeue() << endl;
        cout << queue.dequeue() << endl;
        cout << queue.dequeue() << endl;
        cout << queue.dequeue() << endl;
        cout << queue.dequeue() << endl;
        cout << queue.dequeue() << endl;
        cout << queue.dequeue() << endl;
    }
    cout << "-----------------------------" << endl;
    {
        Queue<float> queue(5);
        for (int i = 0; i < 7; i++) {
            queue.enqueue(i * 10.2f);
        }
        cout << "data size: " << queue.size() << endl;
        cout << "Dequeue..." << endl;
        cout << queue.dequeue() << endl;
        cout << queue.dequeue() << endl;
        cout << queue.dequeue() << endl;
        cout << queue.dequeue() << endl;
        cout << queue.dequeue() << endl;
        cout << queue.dequeue() << endl;
        cout << queue.dequeue() << endl;
    }
    cout << "-----------------------------" << endl;
    {
        Queue<char> queue(5);
        for (int i = 0; i < 7; i++) {
            queue.enqueue('a' + i);
        }
        cout << "data size: " << queue.size() << endl;
        cout << "Dequeue..." << endl;
        cout << queue.dequeue() << endl;
        cout << queue.dequeue() << endl;
        cout << queue.dequeue() << endl;
        cout << queue.dequeue() << endl;
        cout << queue.dequeue() << endl;
        cout << queue.dequeue() << endl;
        cout << queue.dequeue() << endl;
    }
}
