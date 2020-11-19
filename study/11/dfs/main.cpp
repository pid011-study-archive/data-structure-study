#include <iostream>

#include "dfs.h"
using namespace std;

int main() {
    DFS dfs(0, 7);
    dfs.find_path();
    dfs.draw();
}
