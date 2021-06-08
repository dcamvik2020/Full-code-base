#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct List {
    int item;
    struct List *next;
    struct List *prev;
} List;

void list_add(List **head, int item)
{
    List *new_item = (List *) malloc(sizeof(List));
    new_item->item = item;
    if (!(*head))
    {
        new_item->next = NULL;
        new_item->prev = NULL;
        //return new_item;
    } else {
        new_item->next = *head;
        (*head)->prev = new_item;
        new_item->prev = NULL;
    }
    (*head) = new_item;
    //return new_item;
}

void list_append(List **head, int item)
{
    List *new_item = (List *) malloc(sizeof(List));
    List *list;
    new_item->item = item;
    new_item->next = NULL;
    new_item->prev = NULL;
    if (*head)
    {
        for (list = *head; list->next; list = list->next);
        list->next = new_item;
        new_item->prev = list;
    } else {
        *head = new_item;
    }
    //return head;
}

void list_insert(List **head, unsigned index, int item)
{
    unsigned i;
    List *new_item = (List *) malloc(sizeof(List));
    List *list;
    if (index == 0)
    {
        new_item->item = item;
        if (!(*head))
        {
            new_item->next = NULL;
            new_item->prev = NULL;
            //return new_item;
        } else {
            new_item->next = *head;
            (*head)->prev = new_item;
            new_item->prev = NULL;
        }
        *head = new_item;
        //return new_item;
        return;
    }
    for (i = 0, list = *head; list; i++, list = list->next);
    if (index > i)
    {
        free(new_item);
        //return head;
        return;
    }
    i = 0;
    new_item->item = item;
    for (list = *head; list; i++, list = list->next)
        if (i == index - 1)
        {
            if (list->next)
            {
                list->next->prev = new_item;
                new_item->next = list->next;
                list->next = new_item;
                new_item->prev = list;
            }
            else
            {
                list->next = new_item;
                new_item->prev = list;
                new_item->next = NULL;
            }
            break;
        }
    return;
    //return head;
}

void list_delete(List **head, unsigned index)
{
    List *list, *old_item;
    unsigned i = 0;
    if (!(*head))
    {
        //return head;
        return;
    }
    if (index == 0)
    {
        list = (*head)->next;
        if (list)
            list->prev = NULL;
        free(*head);
        //return list;
        *head = list;
        return;
    }
    list = *head;
    for (; i < index - 1; i++)
    {
        if (!list->next)
        {
            //return head;
            return;
        }
        list = list->next;
    }
    old_item = list->next;
    if (old_item)
    {
        if (old_item->next)
        {
            old_item->next->prev = list;
            list->next = old_item->next;
            free(old_item);
            //return head;
            return;
        }
        list->next = old_item->next;
        free(old_item);
    }
    //return head;
    return;
}

void list_delete_first(List **head)
{
    List *list;
    if (!(*head))
    {
        //return head;
        return;
    }
    list = (*head)->next;
    if (list)
        list->prev = NULL;
    free(*head);
    //return list;
    *head = list;
}

void list_delete_last(List **head)
{
    List *list;
    if (!(*head))
    {
        //return head;
        return;
    }
    for(list = *head; list->next; list = list->next);
    if (list == *head)
    {
        *head = (*head)->next;
        free(list);
        //return head;
        return;
    }
    list->prev->next = NULL;
    free(list);
    //return head;
    return;
}

int list_get(List *head, unsigned index)
{
    List *list;
    unsigned int i = 0;
    for (list = head; list; i++, list = list->next)
    {
        if (i == index)
        {
            return list->item;
        }
    }
    return -1;
}

void list_set(List *head, unsigned index, int item)
{
    List *list;
    unsigned int i = 0;
    for (list = head; list; i++, list = list->next)
        if (i == index)
        {
            list->item = item;
            return;
        }
}

int list_find(List *head, int item)
{
    List *list;
    unsigned int i = 0;
    for (list = head; list; list = list->next, i++)
        if (list->item == item)
            return i;
    return -1;
}

unsigned list_size(List *head)
{
    List *list;
    list = head;
    if (list)
        return 1 + list_size(list->next);
    return 0;
}

void list_print(List *head)
{
    List *list;
    for (list = head; list; list = list->next)
        printf("%d ", list->item);
    puts("");
}

void list_reverse_print(List *head)
{
    List *list;
    if (!head)
    {
        puts("");
        return;
    }
    for (list = head; list->next; list = list->next);
    while(list)
    {
        printf("%d ", list->item);
        list = list->prev;
    }
    puts("");
}

void list_destroy(List **head)
{
    List *list;
    list = *head;
    if(list)
    {
        list_destroy(&(list->next));
        free(list);
    }
}





int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
