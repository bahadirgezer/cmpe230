#include <stdio.h>
#include <string.h>
#include "main.h"
#include "string_functions.h"

Vector tokens;
/*
process_line(char line[], File c_file) {
	tokens = tokenizer(line)
	parser(tokens)
	//no syntax error at this point
	c_line = line_builder(tokens)
	printf(C_file, c_line)
	
}

print(C.out, neededfunctions)
while(nextLine) {
	line
	process_line(line, C.out)
}


parser(Vector tokens) {
	expression(subTokens) //calls expression when necessarry
}


expression(Vector subTokens) {
	Vector postfixSubTokens = infixToPostfix(subTokens)
	evaluatePostfix(postfixSubTokens)
}
*/

/*
    Tokenizes expressions. Takes a single line from the .mat file, returns a vector of tokens.
    Does not modify the initial line, uses two pointers to denote a token. When found, copies
    the token to the token struct. Uses token_type to keep track of which token is being parsed.
    @param char[] line
*/
void tokenizer(char line[], int line_number) {
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
                    extract_token(token_start, line_len - index, &tokens, 18);
                } else {
                    extract_token(token_start + 1, line_len - index, &tokens, 18);
                }
            } else if (token_type == 1) {
                extract_token(token_start, token_len, &tokens, 17);
                extract_token(token_start + 1, line_len - index, &tokens, 18);
            } else if (token_type == 2) {
                extract_token(token_start, token_len, &tokens, 17);
                extract_token(token_start + 1, line_len - index, &tokens, 18);
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
                extract_token(token_start, token_len, &tokens, 17);
                token_len = 0;
                token_start = line + index;
                index++;
            } else if (token_type == 2) {
                extract_token(token_start, token_len, &tokens, 17);
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
                extract_token(token_start, token_len, &tokens, 17);
                token_len = 1;
                token_start = line + index;
                index++;
            } else if (token_type == 2) {
                extract_token(token_start, token_len, &tokens, 17);
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
                extract_token(token_start, token_len, &tokens, 17);
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
}

/*
    Helper function for the tokenizer() function. extracts the token and puts it
    inside a struct Token.
    @param char* token_start
    @param int token_len 
    @param Vector* tokens
*/
void extract_token(char *token_start, int token_len, Vector *tokens, int token_type) {
    Token token;
    token.isOk = 1;
    memset(token.value, '\0', sizeof(token.value));
    strncpy(token.value, token_start, token_len);
    token.type = token_type;
    tokens->pAdd(tokens, token);
}

void error(int line_number) {
    printf("Error on line %d\n", line_number);
}

void parser(Vector *tokens, int line_number) {
    if (tokens->pSize == 0) {
        return;
    }
    Token token = tokens->pGet(tokens, 0); //checking first token
    
    if (strcmp("scalar", token.value) == 0) {
        token.type = 0;

        Token variable = tokens->pGet(tokens, 1);
        if (isAlphaNumericLiteral(variable.value) != 1 || variable.isOk != 1) {
            error(line_number);
        }
        variable.type = 19;

    } else if (token.type ==  1) {
    } else if (token.type ==  2) {
    } else if (token.type ==  3) {
    } else if (token.type ==  4) {
    } else if (token.type ==  5) {
    } else if (token.type ==  6) {
    } else if (token.type ==  7) {
    } else if (token.type ==  8) {
    } else if (token.type ==  9) {
    } else if (token.type == 10) {
    } else if (token.type == 11) {
    } else if (token.type == 12) {
    } else if (token.type == 13) {
    } else if (token.type == 14) {
    } else if (token.type == 15) {
    } else if (token.type == 16) {
    }
}

/*
    Gets the value of the variable for the given name.
    @param char[] name - value (as in the value field inside the token) of the variable.
    @returns Token token - struct Token of the variable
*/
Token get_variable(char name[]) {
    Token token;
    return token;
}


int main(int argc, char *argv[]) {
    char line[256] = "matrix A[2,2]     \t # variables and stuff and ]][][][{}[]])_0-=-&@@@@";    
    tokenizer(line, 1);
    
    for (int i = 0; i < tokens.pSize(&tokens); i++)
    {
        Token first_token = tokens.pGet(&tokens, i);
        printf("\"%s\"\n", first_token.value);
    }
}
