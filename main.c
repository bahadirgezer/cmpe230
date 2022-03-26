#include <stdio.h>
#include <string.h>
#include "main.h"
#include "string_functions.h"

typedef struct Token Token;

struct Token {
    char type[60];
    char value[60];
    int val;
};


/*
    Tokenizes expressions. Takes a single line from the .mat file, returns a vector of tokens.
    Does not modify the initial line, uses two pointers to denote a token. When found, copies
    the token to the token struct. Uses token_type to keep track of which token is being parsed.
    @param line a single line in the .mat file
*/
void tokenizer(char line[]) {
    char *token_start = line;
    char *token_end = line;
    int token_type = 0; //0: loopbegin; 1: special character; 2: alphanumeric
    
    for (int i = 0; i < strlen(line); i++) {
        printf("%c", line[i]);

        if (isSpecialCharacter(line[0]) == 1) {
            if (token_type != 1 || token_type != 0) {
                extract_token(token_start, token_end, line);
                token_start = line + i;
                token_end = line + i;
                token_type = 0;
            }
            token_type = 1;


            continue;
        }

        if (isAlphaNumeric(line[0]) == 1) {
            if (token_type != 2 || token_type != 0) {
                extract_token(token_start, token_end, line);
                token_start = line + i;
                token_end = line + i;
                token_type = 0;
            }
            token_type = 2;

            continue;
        }

    }
}

void extract_token(int *token_start, int *token_end, char line[]) {
    Token token;
    int strlen = (*token_start - *token_end) / sizeof(*token_start);
    strncpy(token_start, token.value, strlen);
    //printf("%s", token.value);
}


int main(int argc, char *argv[]) {
    char line[256] = "This is a2 line";
    tokenizer(line);

    
    //NumericLiteral_init(num1_p, *value, val);
    //printf("%s %s %d\n", num1.type, num1.value, val);
}
