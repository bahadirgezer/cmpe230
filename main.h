typedef struct Token Token;

void NumericLiteral_init(Token *token, char *value, int val);
int isAlphaNumeric(char ch);
int isLetter(char ch);
int isNumber(char ch);
int isParanthesis(char ch);
int isNumberLiteral(char ch[]);
void extract_token(int *token_start, int *token_end, char line[]);
void tokenizer(char line[]);

