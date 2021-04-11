#include "queue.h"

Queue *Enqueue(Queue *Q, unsigned source) {
    Queue *new_item = (Queue *) malloc(sizeof(Queue));
    Queue *q;
    new_item->v = source;
    new_item->next = NULL;
    if (Q) {
        for (q = Q; q->next; q = q->next);
        q->next = new_item;
    } else {
        Q = new_item;
    }
    return Q;
}

unsigned Dequeue(Queue **Q) {
    unsigned v = (*Q)->v;
    Queue *q = *Q;
    *Q = (*Q)->next;
    free(q);
    return v;
}
