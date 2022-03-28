#include "token.h"
#include "vector.h"
#include "stack.h"

void extract_token(char *token_start, int token_len, Vector *tokens, int token_type);
void tokenizer(char line[], int line_number);
void error(int line_number);
void parser(Vector *tokens, int line_number);
Token get_variable(char name[]);
int parse_expression(int start_index, Vector *tokens, int delimiter_type);


