#include "dfs.h"

#include <iostream>
#include <memory>
using namespace std;

// graph
int _city[9][9]{
    // A B C D E F G H I
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

char _city_name[9] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};

void DFS::find_path() {
    bool visit_info[9];
    memset(visit_info, UNVISIT, sizeof(visit_info));

    _stack.push(_snode);
    visit_info[_snode] = VISIT;

    while (!_stack.is_empty() && _tnode != _stack.top()) {
        int cur_city = _stack.top();
        bool bvisit_to_next = false;
        for (int next_city = 0; next_city < 9; next_city++) {
            if (_city[cur_city][next_city] == 1 && visit_info[next_city] == UNVISIT) {
                _stack.push(next_city);
                visit_info[next_city] = VISIT;
                bvisit_to_next = true;
                break;
            }
        }

        if (!bvisit_to_next) {
            _stack.pop();
        }
    }
}

void DFS::draw() {
    while (!_stack.is_empty()) {
        cout << _city_name[_stack.pop()] << endl;
    }
}
