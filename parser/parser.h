#include "../repl/repl.h"
#include <string.h>
#include <ctype.h>

// Supported commands
typedef enum {
    STATEMENT_INSERT,
    STATEMENT_SELECT,
    STATEMENT_INVALID
} StatementType;

typedef enum {
    PREPARE_SUCCESS,
    PREPARE_FAILURE
} PrepareResult;

typedef struct {
    StatementType type;
} Statement;


void Parse_Command();
PrepareResult prepare_statement(InputBuffer *input_buffer, Statement *statement);
void process_input_buffer(InputBuffer *input_buffer);
void execute_statement(InputBuffer *input_buffer, Statement *statement);