
#include <stdio.h>

typedef struct List List;

List *list_add(List *head, int item);
List *list_append(List *head, int item);
List *list_insert(List *head, unsigned index, int item);
List *list_delete(List *head, unsigned index);
List *list_delete_first(List *head);
List *list_delete_last(List *head);
int list_get(List *head, unsigned index);
void list_set(List *head, unsigned index, int item);
int list_find(List *head, int item);
unsigned list_size(List *head);
void list_print(List *head);
void list_reverse_print(List *head);
void list_destroy(List *head);

int main(void) {
	int choice, index, value;
	List *list = NULL;
	do {
		scanf("%d", &choice);
		switch (choice) {
		case 10:
			scanf("%d", &value);
			list = list_add(list, value);
			break;
		case 15:
			scanf("%d %d", &index, &value);
			list = list_insert(list, index, value);
			break;
		case 19:
			scanf("%d", &value);
			list = list_append(list, value);
			break;
		case 25:
			scanf("%d", &index);
			list = list_delete(list, index);
			break;
		case 20:
			list = list_delete_first(list);
			break;
		case 29:
			list = list_delete_last(list);
			break;
		case 3:
			scanf("%d", &index);
			printf("%d\n", list_get(list, index));
			break;
		case 4:
			scanf("%d %d", &index, &value);
			list_set(list, index, value);
			break;
		case 5:
			scanf("%d", &value);
			printf("%d\n", list_find(list, value));
			break;
		}
		printf("%u\n", list_size(list));
		list_print(list);
		list_reverse_print(list);
		printf("\n");
	} while (choice);
	list_destroy(list);
	return 0;
}

