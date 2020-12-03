#include "bfs.h"

#include <iostream>
#include <memory>
using namespace std;

constexpr int MAX_NODE = 9;
// graph
int _city[MAX_NODE][MAX_NODE]{
    //  A B C D E F G H I
    {0, 1, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0},
};

enum {
    UNVISIT,
    VISIT
};

char _cityName[MAX_NODE] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};

bool BFS::PathFinding() {
    bool visitInfo[MAX_NODE];
    int parent[MAX_NODE];
    bool isFound = false;

    memset(visitInfo, UNVISIT, sizeof(visitInfo));
    memset(parent, -1, sizeof(parent));

    _queue.enqueue(_startNode);
    visitInfo[_startNode] = true;
    parent[_startNode] = _startNode;

    while (_queue.length() != 0) {
        int front = _queue.first()->data;
        if (front == _startNode) {
            isFound = true;
            break;
        }
        for (size_t i = 0; i < MAX_NODE; i++) {
            if (_city[front][i] && visitInfo[i] == UNVISIT) {
                _queue.enqueue(i);
                visitInfo[i] = VISIT;
                parent[i] = front;
            }
        }
        int outval;
        _queue.dequeue(outval);
    }
    if (isFound) {
        int curNode = _targetNode;
        _stack.push(curNode);
        do {
            curNode = parent[curNode];
            _stack.push(curNode);
        } while (curNode != _startNode);
    }

    return isFound;
}

void BFS::Draw() {
    while (!_stack.is_empty()) {
        cout << _stack.pop() << " -> ";
    }
    cout << endl;
}
