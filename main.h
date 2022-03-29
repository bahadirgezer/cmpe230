#include "token.h"
#include "vector.h"
#include "stack.h"

void extract_token(char *token_start, int token_len, Vector *tokens, int token_type);
void tokenizer(char line[]);
void error();
void parser(Vector *tokens);
Token get_variable(char name[]);
int parse_expression(int start_index, Vector *tokens, int delimiter_type);
int is_variable(char name[]);

