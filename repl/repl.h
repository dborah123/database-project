#ifndef REPL_H
#define REPL_H

typedef struct {
    int buffer_size;
    int input_size;
    char *input;
} InputBuffer;

int read_input(InputBuffer *input_buffer);

#endif // REPL_H