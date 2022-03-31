<<<<<<< HEAD
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
void infix_to_postfix(Vector subtokens);
void evaluate_postfix(Vector postfix);
Token type_check(Token op1, Token op2, Token operator);
int has_higher_precedence(int incoming, int top);

=======
typedef struct Token Token;

void NumericLiteral_init(Token *token, char *value, int val);
int isAlphaNumeric(char ch);
int isLetter(char ch);
int isNumber(char ch);
int isParanthesis(char ch);
>>>>>>> cec54b1 (Added rudimentary isNumber, isLetter functions)

