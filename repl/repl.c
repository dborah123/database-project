#include "repl.h"


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

        // Send command to server

        // Print info
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

    if (strncmp(input, ".help", 5) == 0) {
        print_helptext();
    }

    return 0;
}

void
print_helptext() {
    /**
     * DESCRIPTION: Prints the repl's helptext
     * Helptext defined in ../static/repl-helptext
    */

    // Open the file
    int fd = open(HELPTEXT_PATH, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return;
    }

    // Get file size
    struct stat stat_buffer;
    if (fstat(fd, &stat_buffer) == -1) {
        perror("fstat");
    }

    // Malloc area for the helptext buffer
    void *helptext_buffer = malloc(stat_buffer.st_size);
    if (helptext_buffer == NULL) {
        perror("malloc");
    }

    // Read the file into the buffer
    if (read(fd, helptext_buffer, stat_buffer.st_size) == -1) {
        perror("read");
    }

    printf(helptext_buffer);

    free(helptext_buffer);

}