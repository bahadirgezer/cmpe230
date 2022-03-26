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

int main(int argc, char *argv[]) {
    char line[256];
    struct Token num1;
    char value[60] = "19204381923";
    int val = 109238102;
    Token *num1_p = &num1;

    NumericLiteral_init(num1_p, *value, val);
    printf("%s %s %d\n", num1.type, num1.value, val);
}
