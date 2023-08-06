#include "parser.h"

void
Parse_Command() {
    InputBuffer input_buffer;
    Statement statement;

    process_input_buffer(&input_buffer);

    if (prepare_statement(&input_buffer, &statement)) {
        return;
    }
}

void
process_input_buffer(InputBuffer *input_buffer) {
    
    char c;

    for (int i = 0; i < input_buffer->input_size; i++) {
       c = input_buffer->input[i];
       input_buffer->input[i] = toupper(c);
    }
}

int
prepare_statement(InputBuffer *input_buffer, Statement *statement) {
    
    if (strncmp(input_buffer->input, "INSERT", 6)) {
        statement->type = STATEMENT_INSERT;
        return 0;
    }

    if (strncmp(input_buffer->input, "SELECT", 6)) {
        statement->type = STATEMENT_SELECT;
        return 0;
    }

    statement->type = STATEMENT_INVALID;

    return 1;
}