#include "assert.h"
#include "test.h"
#include "../src/priority_queue.h"


int char_cmp(void *a, void *b)
{
    return (char *) a - (char *) b;
}


int main()
{
    struct priority_queue *q;

    q = priority_queue_init(char_cmp);
    assert(q != NULL);
    assert(priority_queue_size(q) == 0);

    priority_queue_add(q, (void *) 'a');
    assert(priority_queue_size(q) == 1);
    assert((char) priority_queue_get(q) == 'a');
    
    priority_queue_add(q, (void *) 'b');
    assert(priority_queue_size(q) == 2);
    assert((char) priority_queue_get(q) == 'a');
    
    priority_queue_add(q, (void *) 'c');
    assert(priority_queue_size(q) == 3);

    assert((char) priority_queue_pop(q) == 'a');
    assert(priority_queue_size(q) == 2);
    assert((char) priority_queue_pop(q) == 'b');
    assert((char) priority_queue_pop(q) == 'c');
    assert(priority_queue_pop(q) == NULL);

    priority_queue_destory(q);

    TEST_OK("priority queue test passed...");
}
