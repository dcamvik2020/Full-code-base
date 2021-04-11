

//реализация односвязного списка

#include <stdio.h>
#include <stdlib.h>

typedef struct List List;
struct List {
    int item;
    List *next;
};

List *list_add(List *head, int item) {
    //create list item
    List *new_item = (List *) malloc(sizeof(List));
    new_item->item = item;
    new_item->next = NULL;
    if (head) {
        List *list;
        //go to the end
        for (list = head; list->next; list = list->next);
        list->next = new_item; //append
    } else {
        head = new_item; //init (create) list
    }
    return head;
}

List *list_del(List *head, unsigned index) {
    List *list = head;
    List *old_item;
    unsigned i;
    if (!head)
        return head;
    //special case: head removed
    if (index == 0) {
        head = head->next;
        free(list);
        return head;
    }
    //pass other elements
    for (i = 0; i < index - 1; i++) {
        if (!list->next)
            return head;
        list = list->next;
    }
    old_item = list->next;
    //remove item
    if (old_item) {
        list->next = list->next->next;
        free(old_item);
    }
    return head;
}

int list_get(List *list, unsigned index) {
    unsigned i;
    for (i = 0; list; list = list->next, i++)
        if (i == index)
            return list->item;
    return -1;
}

void list_set(List *list, unsigned index, int item) {
    unsigned i;
    for (i = 0; list; list = list->next, i++)
        if (i == index) {
            list->item = item;
            return;
        }
}

unsigned list_size(List *list) {
    if (!list)
        return 0;
    else
        return list_size(list->next) + 1;
}

void list_print(List *list) {
    for ( ; list; list = list->next)
        printf("%d->", list->item);
    printf("NULL\n");
}

void list_destroy(List *list) {
    if (list) {
        list_destroy(list->next);
        free(list);
    }
}

int main(void) {
    int choice, index, value;
    List *list = NULL;
    do {
        printf("MENU:\n"
                "0. Exit\n"
                "1. Add item\n"
                "2. Del item\n"
                "3. Get item\n"
                "4. Set item\n"
                "Enter your choice: "
                );
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            list = list_add(list, value);
            break;
        case 2:
            printf("Enter list index: ");
            scanf("%d", &index);
            list = list_del(list, index);
            break;
        case 3:
            printf("Enter list index: ");
            scanf("%d", &index);
            printf("%d item = %d\n", index, list_get(list, index));
            break;
        case 4:
            printf("Enter list index: ");
            scanf("%d", &index);
            printf("Enter value: ");
            scanf("%d", &value);
            list_set(list, index, value);
            break;
        }
        printf("\n%u items:\n", list_size(list));
        list_print(list);
        printf("\n");
    } while (choice);
    list_destroy(list);
    return 0;
}
