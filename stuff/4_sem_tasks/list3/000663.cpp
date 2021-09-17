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
}
