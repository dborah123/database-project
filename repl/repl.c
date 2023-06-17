#include "repl.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define READ_BUFFER_SIZE 200

int
main(int argc, char *argv[]) {

    int exit_loop = 0;

    InputBuffer input_buffer;
    input_buffer.buffer_size = READ_BUFFER_SIZE;
    input_buffer.input = malloc(READ_BUFFER_SIZE);

    if (input_buffer.input == NULL) {
        perror("Malloc failed");
        exit(1);
    }

    while (!exit_loop) {
        write(1, "> ", 2);

        exit_loop = read_input(&input_buffer);

        if (exit_loop) break;

        // Process input functionality here
    }

    free(input_buffer.input);
}

int
read_input(InputBuffer *input_buffer) {

    char *input = input_buffer->input;

    if (fgets(input, READ_BUFFER_SIZE, stdin) == NULL) {
        perror("fgets failed");
        free(input);
    }

    // TODO: Should modularize this into proccessing inputs once more commands are created
    if (strncmp(input, ".exit", 5) == 0) {
        return 1;
    }

    return 0;
}