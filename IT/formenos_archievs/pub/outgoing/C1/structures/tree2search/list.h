#ifndef LIST_H_
#define LIST_H_

typedef struct List List;
struct List {
	void *item;
	List *next;
};

//UNSHIFT
//void list_add(List **list, void *item) {
//always update head of list using returned link
List *list_add(List *list, void *item);

//PUSH
//initialize head of list using returned link
List *list_append(List *list, void *item);

//SHIFT
//always update head of list using returned link
List *list_del_first(List *list, void **item);

//POP
//returns new last item; if NULL - clear head
//List *list_del_last(List *list, void **item);

//unsigned list_size(List *list);

typedef List* Stack;
extern Stack (*stack_push)(Stack stack, void *item);
extern Stack (*stack_pop)(Stack stack, void **item);
//extern unsigned (*stack_size)(Stack stack);

typedef List* Queue;
extern Queue (*queue_push)(Queue queue, void *item);
extern Queue (*queue_shift)(Queue queue, void **item);
//extern unsigned (*queue_size)(Queue stack);

#endif /* LIST_H_ */
