#ifndef REPL_H
#define REPL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

#define HELPTEXT_PATH "../static/repl-helptext"

typedef struct {
    int buffer_size;
    int input_size;
    char *input;
} InputBuffer;

int read_input(InputBuffer *input_buffer);
void print_helptext();

#endif // REPL_H