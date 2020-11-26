#include <iostream>

#include "queue.h"
using namespace std;

int main() {
    {
        Queue<int> queue;
        for (int i = 0; i < 10; i++) {
            queue.enqueue(i);
        }

        size_t length = queue.length();
        for (size_t i = 0; i < length; i++) {
            int outval = -1;
            queue.dequeue(outval);
            cout << outval << endl;
        }

        if (queue.last() == nullptr) {
            cout << "last node is null" << endl;
        }
    }
    cout << "-----------------------------" << endl;
    {
        Queue<double> queue;
        for (double i = 0; i < 10; i += 1.3) {
            queue.enqueue(i);
        }
        const Node<double>* node = queue.first();

        while (node != nullptr) {
            cout << node->data << endl;
            node = node->next;
        }
    }
    cout << "-----------------------------" << endl;
    {
        Queue<char> queue;
        for (int i = 0; i < 10; i++) {
            queue.enqueue('a' + i);
            cout << char('a' + i) << " <-" << endl;
        }
        cout << endl;
        size_t length = queue.length();
        for (size_t i = 0; i < length; i++) {
            char outval = 'Z';
            queue.dequeue(outval);
            cout << outval << " ->" << endl;
        }

        cout << "length: " << queue.length() << endl;
        char outval;
        if (!queue.dequeue(outval)) {
            cout << "dequeue failed" << endl;
        }
    }
    cout << "-----------------------------" << endl;
    {
        auto* queue = new Queue<int>;

        for (int i = 0; i < 10; i++) {
            queue->enqueue(i);
        }

        delete queue;
        cout << "queue deleted" << endl;
    }
}

/*
0
1
2
3
4
5
6
7
8
9
last node is null
-----------------------------
0
1.3
2.6
3.9
5.2
6.5
7.8
9.1
-----------------------------
a <-
b <-
c <-
d <-
e <-
f <-
g <-
h <-
i <-
j <-

a ->
b ->
c ->
d ->
e ->
f ->
g ->
h ->
i ->
j ->
length: 0
dequeue failed
-----------------------------
queue deleted
*/
