typedef struct List {
    int item;
    struct List *next;
    struct List *prev;
} List;

List *list_add(List *head, int item)
{
    List *new_item = (List *) malloc(sizeof(List));
    new_item->item = item;
    if (!head)
    {
        new_item->next = NULL;
        new_item->prev = NULL;
        return new_item;
    }
    new_item->next = head;
    head->prev = new_item;
    new_item->prev = NULL;
    return new_item;
}

List *list_append(List *head, int item)
{
    List *new_item = (List *) malloc(sizeof(List));
    List *list;
    new_item->item = item;
    new_item->next = NULL;
    new_item->prev = NULL;
    if (head)
    {
        for (list = head; list->next; list = list->next);
        list->next = new_item;
        new_item->prev = list;
    } else {
        head = new_item;
    }
    return head;
}

List *list_insert(List *head, unsigned index, int item)
{
    unsigned i;
    List *new_item = (List *) malloc(sizeof(List));
    List *list;
    if (index == 0)
    {
        new_item->item = item;
        if (!head)
        {
            new_item->next = NULL;
            new_item->prev = NULL;
            return new_item;
        }
        new_item->next = head;
        head->prev = new_item;
        new_item->prev = NULL;
        return new_item;
    }
    for (i = 0, list = head; list; i++, list = list->next);
    if (index > i)
    {
        free(new_item);
        return head;
    }
    i = 0;
    new_item->item = item;
    for (list = head; list; i++, list = list->next)
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
    return head;
}

List *list_delete(List *head, unsigned index)
{
    List *list, *old_item;
    unsigned i = 0;
    if (!head)
        return head;
    if (index == 0)
    {
        list = head->next;
        if (list)
            list->prev = NULL;
        free(head);
        return list;
    }
    list = head;
    for (; i < index - 1; i++)
    {
        if (!list->next)
        {
            return head;
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
            return head;
        }
        list->next = old_item->next;
        free(old_item);
    }
    return head;
}

List *list_delete_first(List *head)
{
    List *list;
    if (!head)
        return head;
    list = head->next;
    if (list)
        list->prev = NULL;
    free(head);
    return list;
}

List *list_delete_last(List *head)
{
    List *list;
    if (!head)
        return head;
    for(list = head; list->next; list = list->next);
    if (list == head)
    {
        head = head->next;
        free(list);
        return head;
    }
    list->prev->next = NULL;
    free(list);
    return head;
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

void list_destroy(List *head)
{
    List *list;
    list = head;
    if(list)
    {
        list_destroy(list->next);
        free(list);
    }
}
