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
    int *token_start = line;
    int *token_end = line;
    int token_type;
    
    for (int i = 0; i < strlen(line); i++) {
        if (isSpecialCharacter(line[0]) == 1) {
            if (token_type != 0) {
                
                token_start = line + i;
                token_end = line + i;
            }

        }

        if (isAlphaNumeric(line[0])  == 1) {
            
        }

    }
}

void extract_token() {
}


int main(int argc, char *argv[]) {
    char str1[] = "123123";
    char str2[] = "askdlasn";
    char str3[] = "alksnd1231";

    printf("%d", isNumber(')'));
    printf("%d", isNumber('1'));
    printf("%d", isNumberLiteral(str1));
    printf("%d", isNumberLiteral(str2));
    printf("%d", isNumberLiteral(str3));

    /*
    char line[256];
    struct Token num1;
    char value[60] = "19204381923";
    int val = 109238102;
    Token *num1_p = &num1;
    */
    
    //NumericLiteral_init(num1_p, *value, val);
    //printf("%s %s %d\n", num1.type, num1.value, val);
}
