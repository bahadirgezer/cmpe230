#include "string_functions.h"
#include <string.h>


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
    for (int i = 0; i < strlen(ch); i++) {
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
