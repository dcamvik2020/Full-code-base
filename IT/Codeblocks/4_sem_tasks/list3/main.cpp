#include <iostream>

/// Элементы списка индексируются с 0.
/// Если заданная позиция index выходит за пределы списка,
/// то ничего не должно происходить.

/// Роль головы будет иметь единственный
/// List *list = new List; созданный в main

using namespace std;


/// Класс -- не обязательно структура, это сущность
/// Сущность: Список
/// Объект: Конкретный список
/// У конкретного списка есть ПАРАМЕТРЫ
/// ПАРАМЕТР: Голова (специальный тип, struct Node)

/// Этого вполне достаточно, а уже в Node определим свойства
//#include <iostream>
using namespace std;
struct Node {
    int item;
    struct Node *next;
    Node (int item = 0, struct Node *next = NULL) : item(item), next(next) {
    }
    ~Node() {
        delete next;
        //next = NULL;
    }
};

class List {
public:
    //конструктор, инициализировать все поля
    List();
    //добавить элемент в начало списка
    void add(int item);
    //добавить элемент в конец списка
    void append(int item);
    //вставить элемент в позицию index
    //(если index == длине списка, то элемент добавляется в конец)
    void insert(unsigned index, int item);
    //удалить элемент с номером index
    void del(unsigned index);
    //удалить первый элемент
    void delete_first();
    //удалить последний элемент
    void delete_last();

    //получить элемент с номером index (если не найден, возвращается -1)
    int get(unsigned index);
    //изменить элемент с номером index
    void set(unsigned index, int item);
    //найти номер первого элемента, равного item (если не найден, возвращается -1)
    int find(int item);
    //длина списка
    unsigned size();

    //распечатать список (числа разделяются пробелами)
    void print();
    //распечатать список задом наперёд
    void reverse_print();
    //В конце списка распечатанных элементов должен быть переход на новую строку,
    //даже если список пустой.

    //деструктор, уничтожить список и освободить всю память
    ~List();

private:
    Node *head;
};

List::List(): head(NULL) {
    //cout << "              CONSTRUCTOR"<< endl;
    /// нужно инициализировать пустой список
    /// без головы
}

void List::add(int item) {
    head = new Node(item, head);
}

void List::append(int item) {
    Node *tmp;
    for (tmp = head; tmp && tmp->next; tmp = tmp->next);
    if (tmp) {
        tmp->next = new Node(item);
    } else {
        head = new Node(item);
    }
}

//(если index == длине списка, то элемент добавляется в конец)
void List::insert(unsigned index, int item) {
    if (index == 0) {
        add(item);
    } else if (head) {
        unsigned i;
        Node *tmp;
        for (i = 0, tmp = head; i < index - 1; i++, tmp = tmp->next) {
            if (!tmp->next) {
                return;
            }
        }
        /// now i = index - 1 and tmp = list[index - 1]
        tmp->next = new Node(item, tmp->next);
    }
}

void List::del(unsigned index) {
    Node *tmp, *old;
    unsigned i;
    if (index == 0) {
        delete_first();
    } else if (head) {
        for (i = 0, tmp = head; i < index - 1; i++, tmp = tmp->next) {
            if (!tmp->next) {
                return;
            }
        }
        /// now i = index - 1 and tmp = list[index - 1]
        if ((old = tmp->next)) {
            tmp->next = old->next;
            old->next = NULL;
            delete old;
        }
    }
}

void List::delete_first() {
    Node *old = head;
    if (head) {
        head = head->next;
        old->next = NULL;
        delete old;
    }
}

void List::delete_last() {
    Node *tmp, *old;
    if (head) {
        for (tmp = head, old = head->next; old && old->next;
                          tmp = tmp->next, old = old->next);
        if (old) {
            old->next = NULL;
            delete old;
            tmp->next = NULL;
        } else {
            delete head;
            head = NULL;
        }
    }
}

int List::get(unsigned index) {
    Node *tmp;
    unsigned i;
    for (i = 0, tmp = head; tmp; i++, tmp = tmp->next) {
        if (i == index) {
            return tmp->item;
        }
    }
    return -1; /// head = NULL --> ERROR --> (-1)
}

void List::set(unsigned index, int item) {
    Node *tmp;
    unsigned i;
    for (i = 0, tmp = head; tmp; i++, tmp = tmp->next) {
        if (i == index) {
            tmp->item = item;
        }
    }
}

int List::find(int item) {
    Node *tmp;
    unsigned i;
    for (i = 0, tmp = head; tmp; i++, tmp = tmp->next) {
        if (tmp->item == item) {
            return i;
        }
    }
    return -1;
}

unsigned List::size() {
    int size = 0;
    for (Node *tmp = head; tmp; tmp = tmp->next, size++);
    return size;
}

void List::print() {
    for (Node *tmp = head; tmp; tmp = tmp->next) {
        cout << tmp->item << " ";
    }
    cout << endl;
}

void print_reverse(Node *head) {
    /// flag = 0 <---> initial head, "root"
    if (head) {
        print_reverse(head->next);
        cout << head->item << " ";
    }
}

void List::reverse_print() {
    print_reverse(head);
    cout << endl;
}

List::~List() {
    //cout << "              DESTRUCTOR"<< endl;
    delete head;
    //for (Node *tmp = head; tmp; head = tmp) {
    //    tmp = head->next;
    //    delete head;
    /// tmp = tmp->next; --> Memory Access Error
    /// tmp = head, но head уже освободили
    //}
}

int main()
{
    List *list = new List; /// объект -- список, у которого есть
    int choice, value, index; /// методы и голова
    cout << "MENU:\n"
    "0. Exit\n"
    "1. Add item to head\n"
    "2. Add item to the end\n"
    "3. Insert item with index\n"
    "4. Delete item with index\n"
    "5. Del first item\n"
    "6. Del last item\n"
    "7. Get item\n"
    "8. Set item\n"
    "9. Find first with item\n"
    "10. Reverse print" << endl;
    do {
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list->add(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            list->append(value);
            break;
        case 3:
            cout << "Enter list index: ";
            cin >> index;
            cout << "Enter value: ";
            cin >> value;
            list->insert(index, value);
            break;
        case 4:
            cout << "Enter list index: ";
            cin >> index;
            list->del(index);
            break;
        case 5:
            list->delete_first();
            break;
        case 6:
            list->delete_last();
            break;
        case 7:
            cout << "Enter list index: ";
            cin >> index;
            cout << "item №" << index << " = " << list->get(index) << endl; ;
            break;
        case 8:
            cout << "Enter list index: ";
            cin >> index;
            cout << "Enter value: ";
            cin >> value;
            list->set(index, value);
            break;
        case 9:
            cout << "Enter value: ";
            cin >> value;
            if (list->find(value) > -1) {
                cout << "first element with value " << value << " ";
                cout << "has index " << list->find(value) << endl;
            } else {
                cout << "Doesn't exist" << endl;
            }
            break;
        case 10:
            cout << "reverse print of the list:" << endl;
            list->reverse_print();
            break;
        }
        cout << list->size() << " items in the list" << endl;
        list->print();
        cout << endl << endl;
    } while (choice);
    delete list;
    return 0;
}
