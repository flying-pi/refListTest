#include <iostream>

class ListItem;

extern ListItem dummy;


ListItem *add(ListItem &to, int value);

class ListItem {

public:
    int value;
    ListItem &next;

    ListItem() : next(dummy) {
        std::cout << " ListItem() : next(dummy) " << std::endl;
    }

    ListItem(int v) : next(dummy), value(v) {
        std::cout << " ListItem(int v) : next(dummy), value(v) :: " << v << std::endl;
    }

    ListItem(int v, ListItem &&n) : value(v), next(n) {
        std::cout << "ListItem(int v, ListItem &&n) : value(v), next(n)  :: " << v << "\t::" << n.value << std::endl;
    }

    ListItem(int v, ListItem &n) : value(v), next(n) {
        std::cout << " ListItem(int v, ListItem &n) : value(v), next(n) :: " << v << "\t::" << n.value << std::endl;
    }


};

ListItem *add(ListItem &to, int value) {
    std::cout << "____" << std::endl;
    return new ListItem(to.value,
                        (&to.next == &dummy) ?
                        (*(new ListItem(value))) :
                        (*add(to.next, value)));
}

void print(int count, ListItem &item) {
    if (count == 0)
        return;
    std::cout << item.value << std::endl;
    print(count - 1, item.next);
}

int main() {
    ListItem *item = new ListItem(10);
    std::cout << "=====================================" << std::endl;
    item = add(*item, 11);
    std::cout << "=====================================" << std::endl;
    item = add(*item, 12);
    std::cout << "=====================================" << std::endl;
    item = add(*item, 13);

    while (item != &dummy) {
        std::cout << item->value << std::endl;
        item = &item->next;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

ListItem dummy;