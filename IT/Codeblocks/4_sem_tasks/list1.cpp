#include <iostream>
#include <cstdlib>

typedef struct List {
    int item;
    struct List *next;
    struct List *prev;
} List;

unsigned list_size(List *head) {
    unsigned size;
    for (size = 0; head; size++, head = head->next);
    return size;
}

List *list_add(List *head, int item) {
    List *new_item = (List *) malloc(sizeof(List));
    new_item->item = item;
    new_item->next = head;
    new_item->prev = NULL;
    if (head) {
        head->prev = new_item;
    }
    return new_item;
}

List *list_append(List *head, int item) {
    List *new_item = (List *) malloc(sizeof(List));
    List *list;
    new_item->item = item;
    new_item->next = NULL;
    new_item->prev = NULL;
    if (head) {
        for (list = head; list->next; list = list->next);
        list->next = new_item;
        new_item->prev = list;
    } else {
        head = new_item;
    }
    return head;
}

/// indexes from zero
List *list_insert(List *head, unsigned index, int item) {
    unsigned i;
    List *tmp, *new_item;
    if (index == 0) {
        return list_add(head, item);
    } else if (head) {
        for (i = 0, tmp = head; i < index - 1; i++, tmp = tmp->next) {
            if (!tmp->next) {
                return head;
            }
        }
        /// now i = index - 1 and tmp = list[index - 1]
        new_item = (List *) malloc(sizeof(List));
        new_item->item = item;
        new_item->next = tmp->next;
        new_item->prev = tmp;
        tmp->next = new_item;
        if (new_item->next) {
            new_item->next->prev = new_item;
        }
    }
    return head;
}


List *list_delete_first(List *head) {
    List *list;
    if (!head) {
        return head;
    }
    list = head->next;
    if (list) {
        list->prev = NULL;
    }
    free(head);
    return list;
}

List *list_delete(List *head, unsigned index) {
    List *tmp, *old;
    unsigned i;
    if (index == 0) {
        return list_delete_first(head);
    }
    if (head) {
        for (i = 0, tmp = head; i < index - 1; i++, tmp = tmp->next) {
            if (!tmp->next) {
                return head;
            }
        }
        /// now i = index - 1 and tmp = list[index - 1]
        if ((old = tmp->next)) {
            tmp->next = old->next;
            if (tmp->next->prev) {
                tmp->next->prev = tmp;
            }
            free(old);
        }
    }
    return head;
}
List *list_delete_last(List *head) {
    List *list = head;
    if (list) {
        for(; list->next; list = list->next);
        if (list == head) {
            free(list);
            return NULL;
        }
        list->prev->next = NULL;
        free(list);
    }
    return head;
}

int list_get(List *head, unsigned index) {
    List *list;
    unsigned int i = 0;
    for (list = head; list; i++, list = list->next) {
        if (i == index) {
            return list->item;
        }
    }
    return -1;
}

void list_set(List *head, unsigned index, int item) {
    List *list;
    unsigned int i = 0;
    for (list = head; list; i++, list = list->next)
        if (i == index) {
            list->item = item;
            return;
        }
}

int list_find(List *head, int item) {
    List *list;
    unsigned int i = 0;
    for (list = head; list; list = list->next, i++) {
        if (list->item == item) {
            return i;
        }
    }
    return -1;
}

void list_print(List *head) {
    List *list;
    for (list = head; list; list = list->next) {
        printf("%d ", list->item);
    }
    puts("");
}

void list_reverse_print(List *head) {
    List *list = head;
    if (list) {
        for (; list->next; list = list->next);
        for (; list; list = list->prev) {
            printf("%d ", list->item);
        }
    }
    puts("");
}

void list_destroy(List *head) {
    while (head) {
        head = list_delete_first(head);
    }
}
