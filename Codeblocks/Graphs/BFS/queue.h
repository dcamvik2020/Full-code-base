#include <stdlib.h>

typedef struct Queue {
    unsigned v;
    struct Queue *next;
} Queue;

Queue *Enqueue(Queue *Q, unsigned source);

unsigned Dequeue(Queue **Q);
