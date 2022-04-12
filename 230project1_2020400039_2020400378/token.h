struct Token{
    char value[512];
    int type;
    int isOk;
    int matrix_i;
    int matrix_j;
    int vector;
};

typedef struct Token Token;

//https://www.javatpoint.com/convert-infix-to-postfix-notation

/*
    lookup table for int type;
    Type of token to value dictionary
    =================   =================   
    "scalar" -> 0
    "vector" -> 1
    "matrix" -> 2
    "tr" | "sqrt" | "choose" -> 3
    "for" -> 4
    "(" -> 5
    ")" -> 6
    "[" -> 7
    "]" -> 8
    "{" -> 9
    "}" -> 10
    "=" -> 11
    "*" -> 12
    "+" -> 13
    "-" -> 14
    "," -> 15
    ":" -> 16
    DEFAULT_VALUE (if no other value is assignable) -> 17
    "#" -> 18
    (variable tokens that have "scalar" keyword) -> 19
    (variable tokens that have "vector" keyword) -> 20
    (variable tokens that have "matrix" keyword) -> 21
    (variable tokens that are assigned after the "for" keyword) -> 22
    "print" | "printfsep" -> 23
    "in" -> 24
    (variable tokens that have "matrix" keyword and are indexed with square braces afterwards (eg. matrix A[1,2]) -> 25
    (variable tokens that have "vector" keyword and are indexed with square braces afterwards (eg. vector A[1]) -> 26
    (function tokens "choose" | "sqrt" | "tr" that evaluate to a "scalar" value) -> 27
    (function tokens "tr" that evaluate to a "matrix" value) -> 28
*/
