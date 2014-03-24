#include "assert.h"
#include "code.h"
#include "table.h"


static unsigned int table[TABLE_SIZE];


void table_init()
{
    int i;

    for (i = 0; i < TABLE_SIZE; i++)
        table[i] = 0u;
}

unsigned int table_get(const unsigned int key)
{
    assert(key >= 0);
    assert(key < TABLE_SIZE);

    return table[key];
}

void table_set(const unsigned int key, unsigned int value)
{
    assert(key >= 0);
    assert(key < TABLE_SIZE);

    table[key] = value;
}

void table_inc(const unsigned int key)
{
    assert(key >= 0);
    assert(key < TABLE_SIZE);

    table[key] = table[key] + 1u;
}
