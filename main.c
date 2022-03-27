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
    int token_type = 0; //0: loopbegin; 1: special character; 2: alphanumeric
    int token_len = 0;
    char current;

    for (int i = 0; i < strlen(line); i++) {
        char current = line[i];
        printf("%c\t", line[i]);
        printf("%d\t", token_type);
        printf("%d\n", token_len);

        if (isWhitespace(current) == 1) {
            if (token_type != 0) {
                extract_token(token_start, token_len);
                token_start = token_start + token_len + 1;
                token_type = 0;
                token_len = 0;
            } else {
                token_start = token_start + 1;
                token_len = 0;
            }

            continue;
        }

        if (isAlphaNumeric(current) == 1) {
            if (token_type == 2 || token_type == 0) {    
                token_len++;
                token_type = 2;
            } else {
                extract_token(token_start, token_len);
                token_start = token_start + token_len;
                token_len = 0;
                token_type = 0;
            }

            continue;
        }

    }
    extract_token(token_start, token_len);
}

void extract_token(int *token_start, int token_len) {
    Token token;
    printf("%p\t", token_start);
    printf("%c\t", *token_start);
    printf("%c\t", *(token_start + token_len));
    printf("%d\n", token_len);

    memset(token.value, '\0', sizeof(token.value));
    strncpy(token.value, token_start, token_len);
    printf("%s\n", token.value);
}


int main(int argc, char *argv[]) {
    char line[256] = "This is a2 line";
    tokenizer(line);

    //NumericLiteral_init(num1_p, *value, val);
    //printf("%s %s %d\n", num1.type, num1.value, val);
}
