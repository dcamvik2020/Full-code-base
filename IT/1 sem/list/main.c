#include <stdio.h>
#include <stdlib.h>


int main()
{
    List *list = NULL;
    int choice, value, index;
    printf("MENU:\n"
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
            "10. Reverse print\n"
            );
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            //puts("");
            list = list_add(list, value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            //puts("");
            list = list_append(list, value);
            break;
        case 3:
            printf("Enter list index: ");
            scanf("%d", &index);
            printf("Enter value: ");
            scanf("%d", &value);
            //puts("");
            list = list_insert(list, index, value);
            break;
        case 4:
            printf("Enter list index: ");
            scanf("%d", &index);
            //puts("");
            list = list_delete(list, index);
            break;
        case 5:
            //puts("");
            list = list_delete_first(list);
            break;
        case 6:
            //puts("");
            list = list_delete_last(list);
            break;
        case 7:
            printf("Enter list index: ");
            scanf("%d", &index);
            printf("%d item = %d\n", index, list_get(list, index));
            break;
        case 8:
            printf("Enter list index: ");
            scanf("%d", &index);
            printf("Enter value: ");
            scanf("%d", &value);
            list_set(list, index, value);
            break;
        case 9:
            printf("Enter value: ");
            scanf("%d", &value);
            if (list_find(list, value))
                printf("first element with value %d has index %d\n", value, list_find(list, value));
            else
                puts("Doesn't exist");
            break;
        case 10:
            //puts("");
            puts("reverse print of the list");
            list_reverse_print(list);
            //puts("");
            break;
        }
        printf("%u items in the list\n", list_size(list));
        list_print(list);
        printf("\n");
    } while (choice);
    list_destroy(list);
    return 0;
}
