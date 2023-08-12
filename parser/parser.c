#include "parser.h"

void
Parse_Command() {
    InputBuffer input_buffer;
    Statement statement;

    process_input_buffer(&input_buffer);

    if (prepare_statement(&input_buffer, &statement) == PREPARE_FAILURE) {
        return;
    }

    execute_statement(&input_buffer, &statement);
}

void
process_input_buffer(InputBuffer *input_buffer) {
    
    char c;

    for (int i = 0; i < input_buffer->input_size; i++) {
       c = input_buffer->input[i];
       input_buffer->input[i] = toupper(c);
    }
}

PrepareResult
prepare_statement(InputBuffer *input_buffer, Statement *statement) {
    
    if (strncmp(input_buffer->input, "INSERT", 6)) {
        statement->type = STATEMENT_INSERT;
        return PREPARE_SUCCESS;
    }

    if (strncmp(input_buffer->input, "SELECT", 6)) {
        statement->type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    }

    statement->type = STATEMENT_INVALID;

    return PREPARE_FAILURE;
}

void
execute_statement(InputBuffer *input_buffer,Statement *statement) {
    switch (statement->type)
    {
    case STATEMENT_INSERT:
        /* code */
        break;
    
    default:
        break;
    }
}