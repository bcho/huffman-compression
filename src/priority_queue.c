#include "priority_queue.h"
#include "assert.h"

#include <stdlib.h>


struct priority_queue {
    int size;
    void **data;
    int (*cmp)(void *, void *);
};

static inline void swap(void **a, void **b)
{
    void *t;

    t = *a;
    *a = *b;
    *b = t;
}

static inline void sink(struct priority_queue *q, int pos)
{
    int child;
    int size;

    for (size = q->size; pos * 2 + 1 < size; pos = child) {
        child = pos * 2 + 1;
        if (child < size - 1 && q->cmp(q->data[child], q->data[child + 1]) > 0)
            child = child + 1;
        if (q->cmp(q->data[pos], q->data[child]) > 0)
            swap(&q->data[pos], &q->data[child]);
        else
            break;
    }
}

static inline void swim(struct priority_queue *q, int pos)
{
    for (; q->cmp(q->data[pos], q->data[pos / 2]) < 0; pos = pos / 2)
        swap(&q->data[pos], &q->data[pos / 2]);
}

struct priority_queue *priority_queue_init(int (*cmp)(void *, void *))
{
    struct priority_queue *q;

    assert(cmp != NULL);

    if ((q = malloc(sizeof(struct priority_queue))) == NULL)
        return NULL;
    q->size = 0;
    q->data = NULL;
    q->cmp = cmp;

    return q;
}

void priority_queue_destory(struct priority_queue *q)
{
    free(q->data);
    free(q);
}

void priority_queue_add(struct priority_queue *q, void *item)
{
    q->size = q->size + 1;
    q->data = realloc(q->data, sizeof(struct priority_queue) * q->size);
    q->data[q->size - 1] = item;
    swim(q, q->size - 1);
}

void *priority_queue_get(struct priority_queue *q)
{
    if (q->size < 1)
        return NULL;

    return q->data[0];
}

void *priority_queue_pop(struct priority_queue *q)
{
    void *data;

    if (q->size < 1)
        return NULL;

    data = q->data[0];
    swap(&q->data[0], &q->data[q->size - 1]);
    q->size = q->size - 1;
    sink(q, 0);

    return data;
}

int priority_queue_size(struct priority_queue *q)
{
    return q->size;
}
