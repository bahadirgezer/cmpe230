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
    Tokenizes expressions
    @param line
*/
void tokenizer(char line[]) {
    int *token_start = line;
    int *token_end = line;
    
    for (int i = 0; i < strlen(line); i++) {
        if (isSpecialCharacter(line[0]) == 1) {
            
        }

        if (isAlphaNumeric(line[0])  == 1) {
            
        }

    }    
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
