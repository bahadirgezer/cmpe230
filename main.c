#include <stdio.h>
#include <string.h>
#include "main.h"
#include "string_functions.h"


/*
    Tokenizes expressions. Takes a single line from the .mat file, returns a vector of tokens.
    Does not modify the initial line, uses two pointers to denote a token. When found, copies
    the token to the token struct. Uses token_type to keep track of which token is being parsed.
    @param char[] line
*/
Vector* tokenizer(char line[], int line_number) {
    Vector tokens;
    CreateVector(&tokens);

    char append = ' '; // needs an not important character at the end to read the last token.
    strncat(line, &append, 1);
    char *token_start = line;
    int line_len = strlen(line);
    int token_type = 0; //0: loopbegin, whitespace; 1: specialcharacter 2: alphanumeric
    int token_len = 0;
    char current;

    int index = 0;
    while (index < line_len) {
        char current = line[index]; 
        
        if (isComment(current) == 1) {
            if (token_type == 0) {
                if (token_start == line) {
                    extract_token(token_start, line_len - index, &tokens);
                } else {
                    extract_token(token_start + 1, line_len - index, &tokens);
                }
            } else if (token_type == 1) {
                extract_token(token_start, token_len, &tokens);
                extract_token(token_start + 1, line_len - index, &tokens);
            } else if (token_type == 2) {
                extract_token(token_start, token_len, &tokens);
                extract_token(token_start + 1, line_len - index, &tokens);
            }
            break;
        }

        if (isDot(current) == 1) {
            if (token_type == 2) {
                token_len++;
                index++;
                continue;
            } else {
                error(line_number);
                break;
            }
        }

        if (isWhitespace(current) == 1) {
            if (token_type == 0) {
                token_len = 0;
                token_start = line + index;
                index++;
            } else if (token_type == 1) {
                extract_token(token_start, token_len, &tokens);
                token_len = 0;
                token_start = line + index;
                index++;
            } else if (token_type == 2) {
                extract_token(token_start, token_len, &tokens);
                token_len = 0;
                token_start = line + index;
                index++;
            }   
            token_type = 0;     
            continue;
        }

        if (isSpecialCharacter(current) == 1) {
            if (token_type == 0) {
                token_len = 1;
                token_start = line + index;
                index++;
            } else if (token_type == 1) {
                extract_token(token_start, token_len, &tokens);
                token_len = 1;
                token_start = line + index;
                index++;
            } else if (token_type == 2) {
                extract_token(token_start, token_len, &tokens);
                token_len = 1;
                token_start = line + index;
                index++;
            }
            token_type = 1;
            continue;
        }

        if (isAlphaNumeric(current) == 1) {
            if (token_type == 0) {
                token_len = 1;
                token_start = line + index;
                index++;
            } else if (token_type == 1) {
                extract_token(token_start, token_len, &tokens);
                token_len = 1;
                token_start = line + index;
                index++;
            } else if (token_type == 2) {
                token_len++;
                index++;
            }
            token_type = 2;
            continue;
        }

        error(line_number);
        break;
    }
    return &tokens;
}

/*
    Helper function for the tokenizer() function. extracts the token and puts it
    inside a struct Token.
    @param char* token_start
    @param int token_len 
    @param Vector* tokens
*/
void extract_token(char *token_start, int token_len, Vector *tokens) {
    Token token;
    memset(token.value, '\0', sizeof(token.value));
    strncpy(token.value, token_start, token_len);
    tokens->pAdd(tokens, token);
}

void error(int line_number) {
    printf("Error on line %d\n", line_number);
}

void parser(Vector *tokens) {

}

int main(int argc, char *argv[]) {
    char line[256] = "matrix A[2,2]     \t # variables and stuff and ]][][][{}[]])_0-=-&@@@@";
    Vector firstline;
    CreateVector(&firstline);
    Vector v = *tokenizer(line, 1);
    for (int i = 0; i < v.pSize(&v); i++)
    {
        Token first_token = v.pGet(&v, i);
        printf("\"%s\"\n", first_token.value);
    }
}
