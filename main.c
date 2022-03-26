#include "main.h"
#include <stdio.h>
#include <string.h>

struct Token {
    char type[60];
    char value[60];
    int val;
};

typedef struct Token Token;

void NumericLiteral_init(Token *token, char *value, int val) {
    strcpy(token->type, "Numeric Literal");
    //strcpy(token->value, *value);
    //token->value = value;
    token->val = val;

}

/*
void expression(char ) {
    
}

void term() {

}

void moreterms() {
    
} 

void factor() {

}

void morefactors() {

}

*/





/*
    @returns 
    1 if ch is an alphanumeric character
    0 if ch is not an alphanumeric character
*/
int isAlphaNumeric(char ch) {
    if (isLetter(ch) == 1 || isNumber(ch) == 1) {
        return 1;
    } else {
        return 0;
    }
}

/*
    @returns 
    1 if ch is a letter
    0 if ch is not a letter
*/
int isLetter(char ch) {
    if (('A' <= ch && ch <= 'Z') || ('a' <= ch <= 'z')) {
        return 1;
    } else {
        return 0;
    }
}

/*
    @returns 
    1 if ch is a number
    0 if ch is not a number
*/
int isNumber(char ch) {
    if ('0' <= ch && ch <= '9') {
        return 1;
    } else {
        return 0;
    }
}

/*
    @returns 
    1 if ch is a left paranthesis
    2 if ch is a right paranthesis
    0 if ch is not a paranthesis
*/
int isParanthesis(char ch) {
    if (ch == '(' || ch == ')') {
        if (ch == '(') {
            return 1;
        } else {
            return 2;
        }
    } else {
        return 0;
    }
}

int main(int argc, char *argv[]) {
    char expression[] = "9+10";
    printf("%d", isParanthesis('('));
    printf("%d", isParanthesis('a'));
    printf("%d", isParanthesis(')'));

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
