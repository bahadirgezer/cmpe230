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
Token type_check(Token op1, Token op2, Token operator);
int has_higher_precedence(int incoming, int top);
int is_ok_ending(int start_index);
int assign_type(Token *variable, Token *complete_variable);
int get_expression(int start_index, int delimiter_type);
Token evaluate_postfix(Vector *postfix);
Token infix_to_postfix(Vector subtokens, int start, int end);
void initialize_scalar(char name[]);
void initialize_vector(char name[]);
void initialize_matrix(char name[]);
