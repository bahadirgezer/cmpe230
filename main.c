#include "main.h"
#include <stdio.h>
#include <string.h>

typedef struct Token Token;

struct Token {
    char type[60];
    char value[60];
    int val;
};

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
    Checks if ch is an alphanumeric a character
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
    Checks if a string is comprised of only alphanumeric characters
    @returns 
    1 if the string ch[] has only alphanumeric characters
    0 if the string ch[] does not have only alphanumeric characters
*/
int isAlphaNumericLiteral(char ch[]) {
    for (int i = 0; i < strlen(ch); i++) {
        if (isLetter(ch[i] == 0 || isNumber == 0)) {
            return 0;
        }
    }
    return 1;
}


/*
    Checks if ch is a letter
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
    Checks if a string is comprised of only letters
    @returns 
    1 if the string ch[] has only letters
    0 if the string ch[] does not have only letters
*/
int isLetterLiteral(char ch[]) {
    for (int i = 0; i < strlen(ch); i)++) {
        if (isLetter(ch[i] == 0)) {
            return 0;
        }
    }
    return 1;
}

/*
    Checks if ch is a number
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
    Checks if a string is comprised of only numbers
    @returns 
    1 if the string ch[] has only numbers
    0 if the string ch[] does not have only numbers
*/
int isNumberLiteral(char ch[]) {
    for (int i = 0; i < strlen(ch); i++) {
        if (isNumber(ch[i]) == 0) {
            return 0;
        }
    }
    return 1;
}

/*
    Checks if ch is a paranthesis
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
    char str1[] = "123123";
    char str2[] = "askdlasn";
    char str3[] = "alksnd1231";

    printf("%d", isNumber(')')); 
    printf("%d", isNumber('1')); 
    printf("%d", isNumber(str1));
    printf("%d", isNumber(str2));
    printf("%d", isNumber(str3));

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
