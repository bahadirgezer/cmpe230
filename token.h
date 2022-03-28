struct Token{
    char value[256];
    int type;
    int isOk;
};

typedef struct Token Token;

/*
    lookup table for int type
    0  -> scalar keyword
    1  -> vector keyword
    2  -> matrix keyword
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
    17 -> undetermined
    18 -> comment
    19 -> scalar variable
    20 -> vector variable
    21 -> matrix variable
*/