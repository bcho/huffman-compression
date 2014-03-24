#ifndef CODE_H
#define CODE_H

struct code {
    char byte;
    int coding;
    int frequency;
};

// Only use lower byte.
#define CODE_GET_REAL(x) (x & 0xFF)

#endif
