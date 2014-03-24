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
    char *content;

    content = io_read_file(filename);
    assert(content != NULL);
    assert(strlen(content) != 0);
    free(content);
}

void test_write_file()
{
    char *content;

    io_write_file(TEST_PATH, TEST_CONTENT);

    content = io_read_file(TEST_PATH);
    assert(strcmp(TEST_CONTENT, content) == 0);
    free(content);

    remove(TEST_PATH);
}

int main(int argc, char *argv[])
{
    test_read_file(__FILE__);
    test_write_file();

    TEST_OK("IO test passed...");
}
