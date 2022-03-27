#include "vector.h"
#include "stack.h"

int isAlphaNumeric(char ch);
int isLetter(char ch);
int isNumber(char ch);
int isParanthesis(char ch);
int isNumberLiteral(char ch[]);
void extract_token(char *token_start, int token_len, Vector *tokens);
Vector* tokenizer(char line[], int line_number);
void error(int line_number);
void parser(Vector *tokens);
Token get_variable(char name[]);

