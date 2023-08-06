#include "../repl/repl.h"
#include <string.h>
#include <ctype.h>

// Supported commands
typedef enum {
    STATEMENT_INSERT,
    STATEMENT_SELECT,
    STATEMENT_INVALID
} StatementType;

typedef struct {
    StatementType type;
} Statement;


void Parse_Command();
int prepare_statement(InputBuffer *input_buffer, Statement *statement);
void process_input_buffer(InputBuffer *input_buffer);