#ifndef TABLE_H
#define TABLE_H


#define TABLE_SIZE (0xFF + 1)

void table_init();
unsigned int table_get(const unsigned int);
void table_set(const unsigned int, unsigned int);
void table_inc(const unsigned int);

#endif
