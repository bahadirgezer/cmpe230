#include "string_functions.h"
#include <string.h>


/*
    Checks if ch is an alphanumeric a character
    @returns 
    1 if ch is an alphanumeric character
    0 if ch is not an alphanumeric character
    @param ch character to check
*/
int is_alphanumeric(char ch) {
    if (is_letter(ch) == 1 || is_number(ch) == 1) {
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
    @param ch character to check
*/
int is_alphanumeric_literal(char ch[]) {
    for (int i = 0; i < strlen(ch); i++) {
        if (is_alphanumeric(ch[i]) == 0) {
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
    @param ch character to check

*/
int is_letter(char ch) {
    if (('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z')) {
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
    @param ch character to check
*/
int is_letter_literal(char ch[]) {
    for (int i = 0; i < strlen(ch); i++) {
        if (is_letter(ch[i]) == 0) {
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
    @param ch character to check
*/
int is_number(char ch) {
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
    @param ch character to check
*/
int is_number_literal(char ch[]) {
    for (int i = 0; i < strlen(ch); i++) {
        if (is_number(ch[i]) == 0) {
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
    @param ch character to check
*/
int is_paranthesis(char ch) {
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

/*
    Checks if ch is a special character which were predetermined
    @returns 
    1 if ch is a special character
    0 is ch is not a special character
    @param ch character to check
*/
int is_special_character(char ch) {
    if (ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}' || ch == '=' || ch == '+' || ch == '*' || ch == '-' || ch == ',' || ch == ':') {
        return 1;
    } else {
        return 0;
    }
}

/*
    Checks if ch is a white-space
    @returns
    1 if ch is a white-space
    0 if ch is not a white-space
    @param ch character to check
*/
int is_whitespace(char ch) {
    if (ch == ' ' || ch == '\t' || ch == '\v' || ch == '\n') {
        return 1;
    } else {
        return 0;
    }
}

/*
    Checks if ch is a dot
    @returns
    1 if ch is a dot
    0 if ch is not a dot
    @param ch character to check
*/
int is_dot(char ch) {
    if (ch == '.') {
        return 1;
    } else {
        return 0;
    }
}

/*
    Checks if ch is a charater for comments, in matlang this is #
    @returns
    1 if ch is a character for comments
    0 if ch is not a character for comments
    @param ch character to check
*/
int is_comment(char ch) {
    if (ch == '#') {
        return 1;
    } else {
        return 0;
    }
}

/*
    Checks if ch is a left brace
    @returns
    1 if ch is a left brace
    0 if ch is not a left brace
    @param ch character to check
*/
int is_left_brace(char ch) {
    if (ch == '[') {
        return 1;
    } else {
        return 0;
    }
}

/*
    Checks if ch is a right brace
    @returns
    1 if ch is a right brace
    0 if ch is not a right brace
    @param ch character to check
*/
int is_right_brace(char ch) {
    if (ch == ']') {
        return 1;
    } else {
        return 0;
    }
}

/*
    Checks if ch is a left paranthesis
    @returns
    1 if ch is a left paranthesis
    0 if ch is not a left paranthesis
    @param ch character to check
*/
int is_left_paranthesis(char ch) {
    if (ch == '(') {
        return 1;
    } else {
        return 0;
    }
}

/*
    Checks if ch is a right paranthesis
    @returns
    1 if ch is a right paranthesis
    0 if ch is not a right paranthesis
    @param ch character to check
*/
int is_right_paranthesis(char ch) {
    if (ch == ')') {
        return 1;
    } else {
        return 0;
    }
}

/*
    Checks if ch is a left curly brace
    @returns
    1 if ch is a left curly brace
    0 if ch is not a left curly brace
    @param ch character to check
*/
int is_left_curly_brace(char ch) {
    if (ch == '{') {
        return 1;
    } else {
        return 0;
    }
}

/*
    Checks if ch is a right curly brace
    @returns
    1 if ch is a right curly brace
    0 if ch is not a right curly brace
    @param ch character to check
*/
int is_right_curly_brace(char ch) {
    if (ch == '}') {
        return 1;
    } else {
        return 0;
    }
}

/*
    Checks if a character array is made up of a single character, this function is used for
    special characters. 
    @returns 
    1 if ch[] is a single character
    0 if ch[] is not a single character
    @param char[] ch character array to check 
*/
int is_single_character(char ch[]) {
    if (strlen(ch) == 1) {
        return 1;
    } else {
        return 0;
    }
}