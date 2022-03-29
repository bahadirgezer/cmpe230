#include <stdio.h>
#include <string.h>
#include "main.h"
#include "string_functions.h"

Vector tokens;
int line_number;
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
void tokenizer(char line[]) {
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
        
        if (is_comment(current) == 1) {
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

        if (is_dot(current) == 1) {
            if (token_type == 2) {
                token_len++;
                index++;
                continue;
            } else {
                error();
                break;
            }
        }

        if (is_whitespace(current) == 1) {
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

        if (is_special_character(current) == 1) {
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

        if (is_alphanumeric(current) == 1) {
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

        error();
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

void error() {
    printf("Error on line %d\n", line_number);
}

//parser -> assignment, decleration (with keyword), for loop, print(), printsep(), 
//needs expression parser, expression parser is recursive.
//parser is not recursive.
//function_parser is used as the last part (else) of these two functions.
//function_parser is not recursive, but it calls expression parser, which is.

void parser(Vector *tokens) {
    int delimiter_index;
    int placeholder_index;

    if (tokens->pSize == 0) {
        return;
    }
    Token token = tokens->pGet(tokens, 0); //checking first token
    
    if (strcmp("scalar", token.value) == 0) {
        token.type = 0;

        Token variable = tokens->pGet(tokens, 1);
        if (is_alphanumeric_literal(variable.value) != 1 || variable.isOk != 1) {
            error();
            return;
        }
        variable.type = 19;

        if (is_ok_ending(&tokens, placeholder_index) != 1) {
            error();
            return;
        }

    } else if (strcmp("vector", token.value) == 0) {
        token.type = 1;

        Token variable = tokens->pGet(tokens, 1);
        if (is_alphanumeric_literal(variable.value) != 1 || variable.isOk != 1) {
            error();
            return;
        }
        variable.type = 20;

        Token left_brace = tokens->pGet(tokens, 2);
        if (is_single_character(left_brace.value) != 1) {
            error();
            return;
        }
        if (is_left_brace(left_brace.value[0]) != 1 || left_brace.isOk != 1) {
            error();
            return;
        }
        left_brace.type = 7;

        //int delimiter_index = parse_expression(); //right brace as delimiter
        //WILL PASS EXPRESSION INTO VECTOR VALUE

        Token right_brace = tokens->pGet(tokens, delimiter_index);
        if (is_single_character(right_brace.value) != 1) {
            error();
            return;
        }
        if (is_right_brace(right_brace.value[0]) != 1 || right_brace.isOk != 1) {
            error();
            return;
        }
        right_brace.type = 8;

        if (is_ok_ending(&tokens, placeholder_index) != 1) {
            error();
            return;
        }

    } else if (strcmp("matrix", token.value) == 0) {
        token.type = 2;

        Token variable = tokens->pGet(tokens, 1);
        if (is_alphanumeric_literal(variable.value) != 1 || variable.isOk != 1) {
            error();
            return;
        }
        variable.type = 21;

        Token left_brace = tokens->pGet(tokens, 2);
        if (is_single_character(left_brace.value) != 1) {
            error();
            return;
        }
        if (is_left_brace(left_brace.value[0]) != 1 || left_brace.isOk != 1) {
            error();
            return;
        }
        left_brace.type = 7;

        //int delimiter_index = parse_expression(); //comma as delimiter
        //WILL PASS EXPRESSION INTO VECTOR VALUE

        //int delimiter_index = parse_expression(); //right brace as delimiter
        //WILL PASS EXPRESSION INTO VECTOR VALUE


        Token right_brace = tokens->pGet(tokens, delimiter_index);
        if (is_single_character(right_brace.value) != 1) {
            error();
            return;
        }
        if (is_right_brace(right_brace.value[0]) != 1 || right_brace.isOk != 1) {
            error();
            return;
        }
        right_brace.type = 8;

        if (is_ok_ending(&tokens, placeholder_index) != 1) {
            error();
            return;
        }

    } else if (strcmp("for", token.value) == 0) {
        token.type = 4;

        Token left_paranthesis = tokens->pGet(tokens, 1);
        if (is_single_character(left_paranthesis.value) != 1) {
            error();
            return;
        }
        if(is_left_paranthesis(left_paranthesis.value[0]) != 1 || left_paranthesis.isOk != 1) {
            error();
            return;
        }
        left_paranthesis.type = 5;

        //INSIDE OF FOR ASSIGNMENT

        Token right_paranthesis = tokens->pGet(tokens, placeholder_index);
        if (is_single_character(right_paranthesis.value) != 1) {
            error();
            return;
        }
        if (is_right_paranthesis(right_paranthesis.value[0]) != 1 || right_paranthesis.isOk != 1) {
            error();
            return;
        }
        right_paranthesis.type = 6;

        Token left_curly_brace = tokens->pGet(tokens, placeholder_index + 1);
        if (is_single_character(right_paranthesis.value) != 1) {
            error();
            return;
        }
        if (is_left_curly_brace(left_curly_brace.value[0]) != 1 || left_curly_brace.isOk != 1) {
            error();
            return;
        }
        left_curly_brace.type = 9;

        if (is_ok_ending(&tokens, placeholder_index) != 1) {
            error();
            return;
        }

    } else if (is_variable(token.value) == 1) {
        Token attributed_variable = get_variable(token.value);
        assign_type(&token, &attributed_variable);

        Token equals = tokens->pGet(tokens, 1);
        if (is_single_character(equals.value) != 1) {
            error();
            return;
        }
        if (is_equals(equals.value[0]) != 1 || equals.isOk != 1) {
            error();
            return;
        }
        equals.type = 11;

        Token after_equals = tokens->pGet(tokens, 2);
        if (is_single_character(after_equals) != 1) {
            error();
            return;
        }
        if (is_left_curly_brace(after_equals.value[0]) != 1 || after_equals.isOk != 1) {
            //delimiter right curly brace
            //get_expression() -> this part is an expression

            Token right_curly_brace = tokens->pGet(tokens, placeholder_index); 
            if (is_single_character(right_curly_brace.value) != 1) {
                error();
                return;
            }
            if (is_right_curly_brace(right_curly_brace.value[0] != 1 || right_curly_brace.isOk != 1) {
                error();
                return;
            }

            if (is_ok_ending(&tokens, placeholder_index) != 1) {
                error();
                return;
            }
        }

        //delimiter comment or line end
        //get_expression() -> this part is an expression
        
        if (is_ok_ending(&tokens, placeholder_index) != 1) {
            error();
            return;
        }

    } else if (strcmp("print", token.value) == 0) {
        token.type = 23;

        Token left_paranthesis = tokens->pGet(tokens, 1);
        if (is_single_character(left_paranthesis.value) != 1) {
            error();
            return;
        }
        if (is_left_paranthesis(left_paranthesis.value[0]) != 1 || left_paranthesis.isOk != 1) {
            error();
            return;
        }

        //Token variable;
        //might give an index if it is a matrix or vector

        Token right_paranthesis = tokens->pGet(tokens, placeholder_index);
        if (is_single_character(right_paranthesis.value) != 1) {
            error();
            return;
        }
        if (is_right_paranthesis(right_paranthesis.value[0]) != 1 || right_paranthesis.isOk != 1) {
            error();
            return;
        }

        if (is_ok_ending(&tokens, placeholder_index) != 1) {
            error();
            return;
        }

    } else if (strcmp("printsep", token.value) == 0) {
        token.type = 23;

        Token left_paranthesis = tokens->pGet(tokens, 1);
        if (is_single_character(left_paranthesis.value) != 1) {
            error();
            return;
        }
        if (is_left_paranthesis(left_paranthesis.value[0]) != 1 || left_paranthesis.isOk != 1) {
            error();
            return;
        }

        Token right_paranthesis = tokens->pGet(tokens, placeholder_index);
        if (is_single_character(right_paranthesis.value) != 1) {
            error();
            return;
        }
        if (is_right_paranthesis(right_paranthesis.value[0]) != 1 || right_paranthesis.isOk != 1) {
            error();
            return;
        }
    
        if (is_ok_ending(&tokens, placeholder_index) != 1) {
            error();
            return;
        }

    } else {
        error();
    }
}

int get_expression(Vector *tokens, int start_index, int delimiter_type) { //if delimiter not found, must stop at the last token
    Token current_token;
    Token next_token;
    //parser(get);


    return 0;
}

/*
    Checks if there is something left in the remaining part of the vector. 
    @returns 
    0 if there is something left -which is not a comment-
    1 if there is nothing left
    @param Vector* tokens
    @param int start_index  
*/
int is_ok_ending(Vector *tokens, int start_index) {
    int vector_size = tokens.pSize;
    int index = start_index;
    if (start_index == vector_size) {
        return 0;
    }
    if (start_index == vector_size-1) {
        Token comment = tokens->pGet(tokens, start_index-1);
        if (is_comment(comment.value[0]) == 1) {
            comment.type = 18;
            return 0;
        }
    }
    return 1;
}

/*
    Checks if a given alphanumeric string is a variable name.
    @param char[] name - value )as in the value field inside the token) of the suspected variable.
    @returns int - 
    1 if there is a variable with name name[]
    0 if there isn't a variable with name name[]
*/
int is_variable(char name[]) {
    
    return 0;
}

/*
    Gets the fully attributed token for the given variable name.
    @param char[] name - value (as in the value field inside the token) of the variable.
    @returns Token token - struct Token of the variable
*/
Token get_variable(char name[]) {
    Token token;

    return token;
}

/*
    Returns the type of that variable. Type values are assigned in the lookup table
    inside the token.h file
*/
int assign_type(Token *variable) {
    
    return 0;
}

int main(int argc, char *argv[]) {
    int line_number = 1;
    char line[256] = "scalar X   ";    
    tokenizer(line);
    parser(&tokens);
    
    for (int i = 0; i < tokens.pSize(&tokens); i++) {
        Token token = tokens.pGet(&tokens, i);
        printf("\"%d\"\n", token.type);
    }
}
