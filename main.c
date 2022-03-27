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
    int line_len = strlen(line);
    int token_type = 0; //0: loopbegin, whitespace; 1: specialcharacter 2: alphanumeric
    int token_len = 0;
    char current;

    int index = 0;
    while (index < line_len) {
        char current = line[index];
        printf("%d\t", token_type);
        //printf("%c\t", line[index]);
        //printf("%d\t", token_type);
        //printf("%d\n", token_len);
        
        if (isWhitespace(current) == 1) {
            if (token_type == 0 || token_type == 1) {
                index++;
                token_start = line + index;
                token_type = 0;
                token_len = 0;
            } else {
                printf("in1\n");
                extract_token(token_start, token_len+1);
                index++;
                token_start = line + index;
                token_type = 0;
                token_len = 0;
            }
            continue;
        }

        // if (isWhitespace(current) == 1) {
        //     if (token_type != 0) {
        //         extract_token(token_start, token_len);
        //         token_start = token_start + token_len + 1;
        //         token_type = 0;
        //         token_len = 0;
        //     } else {
        //         token_start = token_start + 1;
        //         token_len = 0;
        //     }
        //     index++;
        //     continue;
        // }
        
        if (isSpecialCharacter(current) == 1) {
            if (token_type != 1 || token_type != 0) {
                printf("in2\n");

                extract_token(token_start, token_len+1);
                extract_token(line + index, 1);
                index++;
                token_start = line + index;
                token_type = 1;
                token_len = 0;
            } else {
                index++;
                token_start = line + index;
                printf("in3\n");

                extract_token(token_start, 1);
                token_type = 1;
                token_len = 0;
            }

            continue;
        }

        // if (isSpecialCharacter(current) == 1) {
        //     if (token_type != 0) {
        //         extract_token(token_start, token_len);
        //         token_start = token_start + token_len;
        //         token_len = 0;
        //         token_type = 1;
        //     } else {
        //         token_len = 1;
        //         extract_token(token_start, token_len);
        //         token_len = 0;
        //         token_type = 1;
        //     }
        //     index++;
        //     continue;
        // }

        if (isAlphaNumeric(current) == 1) {
            if (token_type == 2) {
                token_len++;
                index++;
            } else {
                token_start = line + index;
                token_type = 2;
                token_len = 0;
                index++;
            }
            continue;
        }
  

        printf("error on line _");
        break;
    }
}

void extract_token(int *token_start, int token_len) {
    Token token;
    // printf("%p\t", token_start);
    // printf("%c\t", *token_start);
    // printf("%c\t", *(token_start + token_len));
    // printf("%d\n", token_len);

    memset(token.value, '\0', sizeof(token.value));
    strncpy(token.value, token_start, token_len);
    printf("\"%s\"\n", token.value);
}


int main(int argc, char *argv[]) {
    char line[256] = "vector   xy2[4] xy2 [4]";
    tokenizer(line);

    //NumericLiteral_init(num1_p, *value, val);
    //printf("%s %s %d\n", num1.type, num1.value, val);
}
