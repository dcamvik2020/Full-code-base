
#include <iostream>

using namespace std;

class List;

int main(void) {
    int choice, index, value;
    List *list = new List; //List list;
    do {
        cin >> choice;
        switch (choice) {
        case 1:
            cin >> value;
            list->add(value);
            break;
        case 2:
            cin >> index >> value;
            list->insert(index, value);
            break;
        case 3:
            cin >> value;
            list->append(value);
            break;
        case 25:
            cin >> index;
            list->del(index);
            break;
        case 20:
            list->delete_first();
            break;
        case 29:
            list->delete_last();
            break;
        case 3:
            cin >> index;
            cout << list->get(index) << endl;
            break;
        case 4:
            cin >> index >> value;
            list->set(index, value);
            break;
        case 5:
            cin >> value;
            cout << list->find(value) << endl;
            break;
        }
        cout << list->size() << endl;
        list->print();
        list->reverse_print();
        cout << endl;
    } while (choice);
    delete list;
    return 0;
}

