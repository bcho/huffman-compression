#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

struct priority_queue;

struct priority_queue *priority_queue_init();
void priority_queue_destory(struct priority_queue *);
void priority_queue_add(struct priority_queue *, void *);
void *priority_queue_get(struct priority_queue *);
void *priority_queue_pop(struct priority_queue *);
int priority_queue_size(struct priority_queue *);

#endif
