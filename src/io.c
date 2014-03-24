#include <stdio.h>
#include <stdlib.h>

#include "assert.h"
#include "io.h"


/*
 * Get file's size.
 */
static inline long get_file_size(FILE *fp)
{
    long rv;

    assert(fp != NULL);

    fseek(fp, 0, SEEK_END);
    rv = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    return rv;
}


/*
 * Read the whole file. (By allocating new buffer.)
 */
char *io_read_file(const char *filename, long *size)
{
    FILE *fp;
    char *buffer;

    fp = fopen(filename, "rb");
    assert(fp != NULL);

    *size = get_file_size(fp);
    buffer = malloc(sizeof(char) * *size);
    assert(buffer != NULL);

    fread(buffer, *size, 1, fp);

    fclose(fp);
    return buffer;
}

/*
 * Write to file.
 */
void io_write_file(const char *filename, char *content)
{
    FILE *fp;

    fp = fopen(filename, "wb");
    assert(fp != NULL);

    fprintf(fp, content);
    fclose(fp);
}
