#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "assert.h"
#include "test.h"
#include "io.h"

#define TEST_PATH "/tmp/test.out"
#define TEST_CONTENT "io_test"


void test_read_file(char *filename)
{
    long size;
    char *content;

    content = io_read_file(filename, &size);
    assert(content != NULL);
    assert(size != 0);
    free(content);
}

void test_write_file()
{
    long size;
    char *content;

    io_write_file(TEST_PATH, TEST_CONTENT);

    content = io_read_file(TEST_PATH, &size);
    assert(strncmp(TEST_CONTENT, content, size) == 0);
    free(content);

    remove(TEST_PATH);
}

int main(int argc, char *argv[])
{
    test_read_file(__FILE__);
    test_write_file();

    TEST_OK("IO test passed...");
}
