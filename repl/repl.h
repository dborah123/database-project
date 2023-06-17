#ifndef REPL_H
#define REPL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct {
    int buffer_size;
    int input_size;
    char *input;
} InputBuffer;

int read_input(InputBuffer *input_buffer);

#endif // REPL_H