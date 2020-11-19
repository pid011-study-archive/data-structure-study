#pragma once
#include "stack.h"

class DFS {
    Stack<int> _stack;
    int _snode;
    int _tnode;
    bool _bfound;

public:
    DFS(int sn, int tn)
        : _snode(sn), _tnode(tn), _bfound(false) { }

    ~DFS() { }

    void find_path();
    void draw();
};
