struct Token{
    char value[256];
    int type;
};

typedef struct Token Token;

/*
    lookup table for int type
    0  -> scalar
    1  -> vector
    2  -> matrix
    3  -> function keyword (tr, sqrt, choose, print, printsep)
    4  -> for
    5  -> left paranthesis
    6  -> right paranthesis
    7  -> left square brace
    8  -> right square brace
    9  -> left curly brace
    10 -> right curely brace
    11 -> equals
    12 -> multiplication
    13 -> addition
    14 -> subtraction
    15 -> comma 
    16 -> colon
*/