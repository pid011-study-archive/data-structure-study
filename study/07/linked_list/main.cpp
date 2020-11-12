#include "linkedlist.hpp"
#include <iostream>

inline void print_linkedlist(LinkedList& list) {
    const Node* node = list.head();
    while (node != nullptr) {
        std::cout << node->Data << " ";
        node = node->Next;
    }
    std::cout << std::endl;
}

int main(int, char**) {
    LinkedList* list = new LinkedList;
    for (int i = 0; i < 10; i++) {
        list->add_last(i);
        print_linkedlist(*list);
    }

    std::cout << std::endl;

    for (int i = 0; i < 10; i++) {
        list->add_first(i);
        print_linkedlist(*list);
    }

    std::cout << std::endl;

    list->insert(3, 100);
    print_linkedlist(*list);

    std::cout << std::endl;

    list->remove(0);
    print_linkedlist(*list);

    std::cout << std::endl;

    list->remove(4);
    print_linkedlist(*list);

    std::cout << std::endl;

    list->remove(list->length() - 1);
    print_linkedlist(*list);

    std::cout << std::endl;

    std::cout << list->retreive(0) << std::endl;
    std::cout << list->retreive(5) << std::endl;
    std::cout << list->retreive(list->length() - 1) << std::endl;

    delete list;
}

/*
--OUTPUT--
0
0 1
0 1 2
0 1 2 3
0 1 2 3 4
0 1 2 3 4 5
0 1 2 3 4 5 6
0 1 2 3 4 5 6 7
0 1 2 3 4 5 6 7 8
0 1 2 3 4 5 6 7 8 9

0 0 1 2 3 4 5 6 7 8 9
1 0 0 1 2 3 4 5 6 7 8 9
2 1 0 0 1 2 3 4 5 6 7 8 9
3 2 1 0 0 1 2 3 4 5 6 7 8 9
4 3 2 1 0 0 1 2 3 4 5 6 7 8 9
5 4 3 2 1 0 0 1 2 3 4 5 6 7 8 9
6 5 4 3 2 1 0 0 1 2 3 4 5 6 7 8 9
7 6 5 4 3 2 1 0 0 1 2 3 4 5 6 7 8 9
8 7 6 5 4 3 2 1 0 0 1 2 3 4 5 6 7 8 9
9 8 7 6 5 4 3 2 1 0 0 1 2 3 4 5 6 7 8 9

9 8 7 100 6 5 4 3 2 1 0 0 1 2 3 4 5 6 7 8 9

8 7 100 6 5 4 3 2 1 0 0 1 2 3 4 5 6 7 8 9

8 7 100 6 4 3 2 1 0 0 1 2 3 4 5 6 7 8 9

8 7 100 6 4 3 2 1 0 0 1 2 3 4 5 6 7 8

8
3
8
*/
