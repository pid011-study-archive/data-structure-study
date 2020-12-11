#include <iostream>
#include <list>

class Item {
    int _id;
    int _money;

public:
    Item(int id, int money) : _id(id), _money(money) { }

    int id() const {
        return _id;
    }

    int money() const {
        return _money;
    }
};

int main() {
    using namespace std;

    list<Item> items;
    items.push_front(Item(1, 2000));
    items.push_front(Item(2, 1000));
    items.push_back(Item(3, 3000));
    items.push_back(Item(4, 4500));

    list<Item>::iterator iter_end = items.end();
    for (list<Item>::iterator iter_pos = items.begin(); iter_pos != iter_end; iter_pos++) {
        cout << "아이템 코드 : " << iter_pos->id() << endl;
    }
}
