#include "assert.h"
#include "test.h"
#include "table.h"


int main()
{
    int i;

    table_init();

    for (i = 0; i < TABLE_SIZE; i++)
        assert(table_get(i) == 0);

    table_set(1, 2);
    assert(table_get(1) == 2);

    table_inc(3);
    assert(table_get(3) != 0);
    assert(table_get(3) == 1);

    TEST_OK("Table test passed...");
}
