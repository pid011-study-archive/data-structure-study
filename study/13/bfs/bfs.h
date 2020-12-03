#pragma once
#include "queue.h"
#include "stack.h"

class BFS {
    MyStack::Stack<int> _stack;
    MyQueue::Queue<int> _queue;

    int _startNode;
    int _targetNode;

public:
    BFS(int snode, int tnode) : _startNode(snode), _targetNode(tnode) { }
    ~BFS() { }
    bool PathFinding();
    void Draw();
};
