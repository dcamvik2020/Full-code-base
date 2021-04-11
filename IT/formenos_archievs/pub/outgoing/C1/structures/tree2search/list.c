#include <stdlib.h>
#include "list.h"

//UNSHIFT
//void list_add(List **list, void *item) {
//always update head of list using returned link
List *list_add(List *list, void *item) {
	List *new_item = (List *) malloc(sizeof(List));
	new_item->item = item;
	new_item->next = list;
	return new_item;
}

//PUSH
//initialize head of list using returned link
List *list_append(List *list, void *item) {
	List *head = list;
	//create list item
	List *new_item = (List *) malloc(sizeof(List));
	new_item->item = item;
	new_item->next = NULL;
	if (head) {
		//go to the end
		while (list->next)
			list = list->next;
		//append
		list->next = new_item;
	} else
		head = new_item;
	return head;
}

//SHIFT
//always update head of list using returned link
List *list_del_first(List *list, void **item) {
	List *head = list;
	if (!head)
		return head;
	head = head->next;
	*item = list->item;
	free(list);
	return head;
}

/*	//// UNUSED ////
//POP
//returns new last item; if NULL - clear head
List *list_del_last(List *list, void **item) {
	List *head = list;
	if (!head)
		return head;
	//special case: head removed
	if (!head->next) {
		*item = head->item;
		free(head);
		return NULL;
	}
	//pass other elements
	while (list->next->next)
		list = list->next;
	//remove item
	*item = list->next->item;
	free(list->next);
	list->next = NULL;
	return list;
}

unsigned list_size(List *list) {
	if (!list)
		return 0;
	else
		return list_size(list->next) + 1;
}

static void list_print(List *list) {
	while (list) {
		printf("%i ", list->item);
		list = list->next;
	}
	printf("\n");
}

static void list_destroy(List *list) {
	if (list) {
		list_destroy(list->next);
		free(list);
	}
}
*/

Stack (*stack_push)(Stack stack, void *item) = list_add;
Stack (*stack_pop)(Stack stack, void **item) = list_del_first;
//unsigned (*stack_size)(Stack stack) = list_size;

Queue (*queue_push)(Queue queue, void *item) = list_append;
Queue (*queue_shift)(Queue queue, void **item) = list_del_first;
//unsigned (*queue_size)(Queue stack) = list_size;
