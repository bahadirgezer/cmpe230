#include <stdio.h>
#include <string.h>
#include "main.h"
#include "string_functions.h"


/*
    Tokenizes expressions. Takes a single line from the .mat file, returns a vector of tokens.
    Does not modify the initial line, uses two pointers to denote a token. When found, copies
    the token to the token struct. Uses token_type to keep track of which token is being parsed.
    @param line a single line in the .mat file
*/
Vector* tokenizer(char line[]) {
    Vector tokens;
    CreateVector(&tokens);

    char append = ' '; // needs an not important character at the end to read the last token.
    strncat(line, &append, 1);
    char *token_start = line;
    int line_len = strlen(line);
    int token_type = 0; //0: loopbegin, whitespace; 1: specialcharacter 2: alphanumeric
    int token_len = 0;
    char current;

    int index = 0;
    while (index < line_len) {
        char current = line[index];

        if (isWhitespace(current) == 1) {
            if (token_type == 0) {
                token_len = 0;
                index++;
                token_start = line + index;
            } else if (token_type == 1) {
                extract_token(token_start, token_len, &tokens);
                token_len = 0;
                index++;
                token_start = line + index;
            } else if (token_type == 2) {
                extract_token(token_start, token_len, &tokens);
                token_len = 0;
                index++;
                token_start = line + index;
            }   
            token_type = 0;     
            continue;
        }

        if (isSpecialCharacter(current) == 1) {
            if (token_type == 0) {
                token_len = 1;
                token_start = line + index;
                index++;
            } else if (token_type == 1) {
                extract_token(token_start, token_len, &tokens);
                token_len = 1;
                token_start = line + index;
                index++;
            } else if (token_type == 2) {
                extract_token(token_start, token_len, &tokens);
                token_len = 1;
                token_start = line + index;
                index++;
            }
            token_type = 1;
            continue;
        }

        if (isAlphaNumeric(current) == 1) {
            if (token_type == 0) {
                token_len = 1;
                token_start = line + index;
                index++;
            } else if (token_type == 1) {
                extract_token(token_start, token_len, &tokens);
                token_len = 1;
                token_start = line + index;
                index++;
            } else if (token_type == 2) {
                token_len++;
                index++;
            }
            token_type = 2;
            continue;
        }

        printf("This line has an error\n");
        break;
    }
    return &tokens;
}

void extract_token(char *token_start, int token_len, Vector *tokens) {
    Token token;
    tokens->pAdd(&tokens, token);
    memset(token.value, '\0', sizeof(token.value));
    strncpy(token.value, token_start, token_len);
    printf("%s", token.value);
}



int main(int argc, char *argv[]) {
    char line[256] = "matrix   A[4,4]";
    Vector firstline;
    CreateVector(&firstline);
    Vector v = *tokenizer(line);

    printf("%s", v.pGet(&v, 0).value);
    // printf("%s\n", firstline.pGet(&firstline, 0).value);
    // printf("%s\n", firstline.pGet(&firstline, 1).value);
    // printf("%s\n", firstline.pGet(&firstline, 2).value);
    // printf("%s\n", firstline.pGet(&firstline, 3).value);
    // printf("%s\n", firstline.pGet(&firstline, 4).value);
}
