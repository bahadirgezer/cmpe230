#include <stdio.h>
#include <string.h>
#include "main.h"
#include "string_functions.h"

Vector tokens;
Vector variables;
Vector postfix_vector;
int in_for_loop;
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

// v[1,2] * tr(m1[3,1])

/*
    Tokenizes expressions. Takes a single line from the .mat file, returns a vector of tokens.
    Does not modify the initial line, uses two pointers to denote a token. When found, copies
    the token to the token struct. Uses token_type to keep track of which token is being parsed.
    @param char[] line
*/
void tokenizer(char line[]) { //                                                                                    NEED TO STRIPLAST WHITESPACE
    CreateVector(&tokens);

    char append = ' '; // needs an not important character at the end to read the last token.
    strncat(line, &append, 1);
    char *token_start = line;
    int line_len = strlen(line);
    int token_type = 0; //0: loopbegin, whitespace; 1: specialcharacter 2: alphanumeric
    int token_len = 0;
    char current;

    int index = 0;
    printf("%d\n", line_len);
    while (index < line_len) {
        char current = line[index]; 
        printf("%d\n", index);
        
        if (is_comment(current) == 1) {
            if (token_type == 0) {
                if (token_start == line) {
                    extract_token(token_start, line_len - index, 18);
                } else {
                    extract_token(token_start + 1, line_len - index, 18);
                }
            } else if (token_type == 1) {
                extract_token(token_start, token_len, 17);
                extract_token(token_start + 1, line_len - index, 18);
            } else if (token_type == 2) {
                extract_token(token_start, token_len, 17);
                extract_token(token_start + 1, line_len - index, 18);
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
                extract_token(token_start, token_len, 17);
                token_len = 0;
                token_start = line + index;
                index++;
            } else if (token_type == 2) {
                extract_token(token_start, token_len, 17);
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
                extract_token(token_start, token_len, 17);
                token_len = 1;
                token_start = line + index;
                index++;
            } else if (token_type == 2) {
                extract_token(token_start, token_len, 17);
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
                extract_token(token_start, token_len, 17);
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
void extract_token(char *token_start, int token_len, int token_type) {
    Token token;
    token.isOk = 1;
    memset(token.value, '\0', sizeof(token.value));
    strncpy(token.value, token_start, token_len);
    token.type = token_type;
    tokens.pAdd(&tokens, token);
}

void error() {
    printf("Error on line %d\n", line_number);
}

/*
    Returns the first index after the functions ends. (the index after the right paranthesis.)
    Returns -1 if there is an error();
*/
int function_parser(int start_token_index) {
    Token token = tokens.pGet(&tokens, start_token_index);

    if (strcmp(token.value, "tr")) { // WRONG WRONG WRONG WEONGGGG 
        Token left_paranthesis = tokens.pGet(&tokens, start_token_index + 1);
        if (is_single_character(left_paranthesis.value) != 1) {
            error();
            return -1;
        }
        if (is_left_paranthesis(left_paranthesis.value[0]) != 1 || left_paranthesis.isOk != 1) {
            error();
            return -1;
        }
        left_paranthesis.type = 5;

        int expression_last_token_index = get_expression(start_token_index + 2, 6);
        //delimiter stack

        Token right_paranthesis = tokens.pGet(&tokens, expression_last_token_index + 1);
        if (is_single_character(right_paranthesis.value) != 1) {
            error();
            return -1;
        }
        if (is_right_paranthesis(right_paranthesis.value[0]) != 1 || right_paranthesis.isOk != 1) {
            error();
            return -1;
        }
        right_paranthesis.type = 6;

    } else if (strcmp(token.value, "choose")) {
        Token left_paranthesis = tokens.pGet(&tokens, start_token_index + 1);
        if (is_single_character(left_paranthesis.value) != 1) {
            error();
            return -1;
        }
        if (is_left_paranthesis(left_paranthesis.value[0]) != 1 || left_paranthesis.isOk != 1) {
            error();
            return -1;
        }
        left_paranthesis.type = 5;

        int expression_last_token_index = get_expression(start_token_index + 2, 6);
        
        Token right_paranthesis = tokens.pGet(&tokens, expression_last_token_index + 1);
        if (is_single_character(right_paranthesis.value) != 1) {
            error();
            return -1;
        }
        if (is_right_paranthesis(right_paranthesis.value[0]) != 1 || right_paranthesis.isOk != 1) {
            error();
            return -1;
        }
        right_paranthesis.type = 6;

    } else if (strcmp(token.value, "sqrt")) {
        Token left_paranthesis = tokens.pGet(&tokens, start_token_index + 1);
        if (is_single_character(left_paranthesis.value) != 1) {
            error();
            return -1;
        }
        if (is_left_paranthesis(left_paranthesis.value[0]) != 1 || left_paranthesis.isOk != 1) {
            error();
            return -1;
        }
        left_paranthesis.type = 5;

        int expression_last_token_index = get_expression(start_token_index + 2, 6);
            
        Token right_paranthesis = tokens.pGet(&tokens, expression_last_token_index + 1);
        if (is_single_character(right_paranthesis.value) != 1) {
            error();
            return -1;
        }
        if (is_right_paranthesis(right_paranthesis.value[0]) != 1 || right_paranthesis.isOk != 1) {
            error();
            return -1;
        }
        right_paranthesis.type = 6;
    } else {
        printf("shouldn't even be in here");
        return -1;
    }
    return -1; //not good
}

/*
    Returns -1 if there is an error. Assigns type and attribute values to tokens inside of an expression.
    Returns the index of the last token of the expression.
*/
int get_expression(int start_index, int delimiter_type) { //if delimiter not found, must stop at the last token
    int delimiter_stack = 0;
    int delimiter_found = 0; // can have right curly brace, right square brace or comment as delimiter
    int tokens_size = tokens.pSize(&tokens); //Vector pointer to int conversion error
    if (tokens_size == start_index) {
        return -1;
    }
    int increment = 0;
    while(!delimiter_found) {
        Token token = tokens.pGet(&tokens, start_index + increment);
        if (token.isOk != 1) {
            return -1;
        }

        if (is_variable(token.value) == 1) {
            //Token attributed_variable = get_variable(token.value);
            //assign_type(&token, &attributed_variable);

            if (1) { //if variable type is  matrix, check for square braces
                ///                                                                 EXPRESSION VARIABLE PARSING WILL BE IN HERE 
            }

        } else if (is_number_literal(token.value) == 1 || is_float(token.value) == 1) {
            tokens.p_update_type(&tokens, start_index + increment, 19);

        } else if (is_function_keyword(token.value) == 1) {
            
            int after_function_index = function_parser(start_index + increment);


        } else if (is_comment(token.value[0]) == 1) { //DELIMITER
            token.type = 18;
            if (delimiter_type != token.type) { //might have a semantic error
                return -1;
            }
            return start_index + increment - 1;

        } else if (is_single_character(token.value) == 1) {
            if (is_left_paranthesis(token.value[0]) == 1) {
                token.type = 5;
                if (delimiter_type == 5) {
                    delimiter_stack += 1;
                }

            } else if (is_star(token.value[0]) == 1) {
                token.type = 12;
            } else if (is_plus(token.value[0]) == 1) {
                token.type = 13;
            } else if (is_minus(token.value[0]) == 1) {
                token.type = 14;
            
            } else if (is_right_paranthesis(token.value[0]) == 1) { //MAYBE A DELIMITER
                token.type = 6;
                if (delimiter_stack != 0) {
                    delimiter_stack -= 1;
                    continue;
                }
                if (delimiter_type != token.type) {
                    return -1;
                }
                return start_index + increment - 1;

            } else if (is_colon(token.value[0]) == 1) { //DELIMITER
                token.type = 16;
                if (delimiter_type != token.type) {
                    return -1;
                }
                return start_index + increment - 1;

            } else if (is_comma(token.value[0]) == 1) { //DELIMITER
                token.type = 15;
                if (delimiter_type != token.type) {
                    return -1;
                }
                return start_index + increment - 1;

            } else if (is_right_curly_brace(token.value[0]) == 1) { //DELIMITER
                token.type = 10;
                if (delimiter_type != token.type) {
                    return -1;
                }
                return start_index + increment - 1;

            } else if (is_right_brace(token.value[0]) == 1) { //DELIMITER
                token.type = 8;
                if (delimiter_type != token.type) {
                    return -1;
                }
                return start_index + increment - 1;
            } else { // add delimiter
                return -1;
            }
        }
        increment++;
    }
    return 0;
}

//parser -> assignment, decleration (with keyword), for loop, print(), printsep(), 
//needs expression parser, expression parser is recursive.
//parser is not recursive.
//function_parser is used as the last part (else) of these two functions.
//function_parser is not recursive, but it calls expression parser, which is.

void parser() {
    int delimiter_index;
    int placeholder_index;
    
    if (tokens.pSize(&tokens) == 0) {
        return;
    }
    Token token = tokens.pGet(&tokens, 0); //checking first token
    if (in_for_loop == 1) {
        if (is_single_character(token.value) == 1 && token.isOk == 1) {
            if (is_right_curly_brace(token.value[0]) == 1) {
                tokens.p_update_type(&tokens, 0, 10);
                in_for_loop -= 1;

                if (is_ok_ending(placeholder_index) != 1) {
                    error();
                    return;
                }
            }
        }
    } else if (strcmp("scalar", token.value) == 0) {
        tokens.p_update_type(&tokens, 0, 0);

        Token variable = tokens.pGet(&tokens, 1);
        if (is_alphanumeric_literal(variable.value) != 1 || variable.isOk != 1) {
            error();
            return;
        }
        tokens.p_update_type(&tokens, 1, 19);
        initialize_scalar(variable.value);

        if (is_ok_ending(placeholder_index) != 1) {
            error();
            return;
        }

    } else if (strcmp("vector", token.value) == 0) {
        tokens.p_update_type(&tokens, 0, 1);

        Token variable = tokens.pGet(&tokens, 1);
        if (is_alphanumeric_literal(variable.value) != 1 || variable.isOk != 1) {
            error();
            return;
        }
        tokens.p_update_type(&tokens, 1, 20);

        Token left_brace = tokens.pGet(&tokens, 2);
        if (is_single_character(left_brace.value) != 1) {
            error();
            return;
        }
        if (is_left_brace(left_brace.value[0]) != 1 || left_brace.isOk != 1) {
            error();
            return;
        }
        tokens.p_update_type(&tokens, 2, 7);

        Token vector_size = tokens.pGet(&tokens, 3);
        if (is_number_literal(vector_size.value) != 1 || vector_size.isOk != 1) {
            error();
            return;
        }
        tokens.p_update_type(&tokens, 3, 19);
        int integer_vector_size = atoi(vector_size.value);
        initialize_vector(variable.value, integer_vector_size);
        
        Token right_brace = tokens.pGet(&tokens, 4);
        if (is_single_character(right_brace.value) != 1) {
            error();
            return;
        }
        if (is_right_brace(right_brace.value[0]) != 1 || right_brace.isOk != 1) {
            error();
            return;
        }
        tokens.p_update_type(&tokens, 4, 8);

        if (is_ok_ending(placeholder_index) != 1) {
            error();
            return;
        }

    } else if (strcmp("matrix", token.value) == 0) {
        tokens.p_update_type(&tokens, 0, 2);

        Token variable = tokens.pGet(&tokens, 1);
        if (is_alphanumeric_literal(variable.value) != 1 || variable.isOk != 1) {
            error();
            return;
        }
        tokens.p_update_type(&tokens, 1, 21);

        Token left_brace = tokens.pGet(&tokens, 2);
        if (is_single_character(left_brace.value) != 1) {
            error();
            return;
        }
        if (is_left_brace(left_brace.value[0]) != 1 || left_brace.isOk != 1) {
            error();
            return;
        }
        tokens.p_update_type(&tokens, 2, 7);


        Token matrix_size_i = tokens.pGet(&tokens, 3);
        if (is_number_literal(matrix_size_i.value) != 1 || matrix_size_i.isOk != 1) {
            error();
            return;
        }
        tokens.p_update_type(&tokens, 3, 19);
        int integer_matrix_size_i = atoi(matrix_size_i.value);

        Token comma = tokens.pGet(&tokens, 4);
        if (is_single_character(comma.value) != 1) {
            error();
            return;
        }
        if (is_comma(comma.value[0]) != 1 || comma.isOk != 1) {
            error();
            return;
        }
        tokens.p_update_type(&tokens, 4, 15);

        Token matrix_size_j = tokens.pGet(&tokens, 5);
        if (is_number_literal(matrix_size_j.value) != 1 || matrix_size_j.isOk != 1) {
            error();
            return;
        }
        tokens.p_update_type(&tokens, 5, 19);
        int integer_matrix_size_j = atoi(matrix_size_j.value);
        initialize_matrix(variable.value, integer_matrix_size_i, integer_matrix_size_j);

        Token right_brace = tokens.pGet(&tokens, 6);
        if (is_single_character(right_brace.value) != 1) {
            error();
            return;
        }
        if (is_right_brace(right_brace.value[0]) != 1 || right_brace.isOk != 1) {
            error();
            return;
        }
        tokens.p_update_type(&tokens, 6, 8);

        if (is_ok_ending(placeholder_index) != 1) {
            error();
            return;
        }

    } else if (strcmp("for", token.value) == 0) {
        tokens.p_update_type(&tokens, 0, 4);

        Token left_paranthesis = tokens.pGet(&tokens, 1);
        if (is_single_character(left_paranthesis.value) != 1) {
            error();
            return;
        }
        if(is_left_paranthesis(left_paranthesis.value[0]) != 1 || left_paranthesis.isOk != 1) {
            error();
            return;
        }
        tokens.p_update_type(&tokens, 1, 5);

        Token variable_1 = tokens.pGet(&tokens, 2);
        if (is_alphanumeric_literal(variable_1.value) != 1 || variable_1.isOk != 1) {
            error();
            return;
        }
        tokens.p_update_type(&tokens, 2, 19);

        int right_paranthesis_index;
        Token in = tokens.pGet(&tokens, 3);
        if (strcmp(in.value, "in") == 0 && in.isOk == 1) {
            in.type = 24;
            tokens.p_update_type(&tokens, 3, 24);

            int expr_end_1 = get_expression(4, 16);
            if (expr_end_1 == -1) {
                error();
                return;
            }
            if (expression(&tokens, 4, expr_end_1, 19) != 1) {
                error();
                return;
            }
            
            int expr_end_2 = get_expression(expr_end_1 + 1, 16);
            if (expr_end_2 == -1) {
                error();
                return;
            }
            if (expression(&tokens, expr_end_1 + 1, expr_end_2, 19) != 1) {
                error();
                return;
            }

            int expr_end_3 = get_expression(expr_end_2 + 1, 6);
            if (expr_end_3 == -1) {
                error();
                return;
            }
            if (expression(&tokens, expr_end_2 + 1, expr_end_3, 19) != 1) {
                error();
                return;
            }
            right_paranthesis_index = expr_end_3 + 1;

        } else {
            Token comma_1 = tokens.pGet(&tokens, 3);
            if (is_single_character(comma_1.value) != 1) {
                error();
                return;
            }
            if (is_comma(comma_1.value[0]) != 1 || comma_1.isOk != 1) {
                error();
                return;
            }
            tokens.p_update_type(&tokens, 3, 15);

            Token variable_2 = tokens.pGet(&tokens, 4);
            if (is_alphanumeric_literal(variable_2.value) != 1 || variable_2.isOk != 1) {
                error();
                return;
            }
            variable_2.type = 19;
            tokens.p_update_type(&tokens, 4, 19);

            Token in = tokens.pGet(&tokens, 5);
            if (strcmp(in.value, "in") != 0 || in.isOk != 1) {
                error();
                return;
            }
            tokens.p_update_type(&tokens, 5, 24);

            int expr_end_1 = get_expression(6, 16);
            if (expr_end_1 == -1) {
                error();
                return;
            }
            if (expression(&tokens, 6, expr_end_1, 19) != 1) {
                error();
                return;
            }

            int expr_end_2 = get_expression(expr_end_1 + 1, 16); ///ADD COMMA AS DELIMITER IN GET_EXPRESSION()
            if (expr_end_2 == -1) {
                error();
                return;
            }
            if (expression(&tokens, expr_end_1 + 1, expr_end_2, 19) != 1) {
                error();
                return;
            }

            int expr_end_3 = get_expression(expr_end_2 + 1, 15);
            if (expr_end_3 == -1) {
                error();
                return;
            }
            if (expression(&tokens, expr_end_2 + 1, expr_end_3, 19) != 1) {
                error();
                return;
            }

            Token comma_2 = tokens.pGet(&tokens, expr_end_3 + 1);
            if (is_single_character(comma_2.value) != 1) {
                error();
                return;
            }
            if (is_comma(comma_2.value[0]) != 1 || comma_2.isOk != 1) {
                error();
                return;
            }
            tokens.p_update_type(&tokens, expr_end_3 + 1, 15);

            int expr_end_4 = get_expression(expr_end_3 + 2, 16);
            if (expr_end_4 == -1) {
                error();
                return;
            }
            if (expression(&tokens, 6, expr_end_4, 19) != 1) {
                error();
                return;
            }

            int expr_end_5 = get_expression(expr_end_4 + 1, 16); ///ADD COMMA AS DELIMITER IN GET_EXPRESSION()
            if (expr_end_5 == -1) {
                error();
                return;
            }
            if (expression(&tokens, expr_end_4 + 1, expr_end_5, 19) != 1) {
                error();
                return;
            }

            int expr_end_6 = get_expression(expr_end_5 + 1, 15);
            if (expr_end_6 == -1) {
                error();
                return;
            }
            if (expression(&tokens, expr_end_5 + 1, expr_end_6, 19) != 1) {
                error();
                return;
            }

            right_paranthesis_index = expr_end_6 + 1;
        }

        Token right_paranthesis = tokens.pGet(&tokens, right_paranthesis_index);
        if (is_single_character(right_paranthesis.value) != 1) {
            error();
            return;
        }
        if (is_right_paranthesis(right_paranthesis.value[0]) != 1 || right_paranthesis.isOk != 1) {
            error();
            return;
        }
        tokens.p_update_type(&tokens, right_paranthesis_index, 6);

        Token left_curly_brace = tokens.pGet(&tokens, right_paranthesis_index + 1);
        if (is_single_character(right_paranthesis.value) != 1) {
            error();
            return;
        }
        if (is_left_curly_brace(left_curly_brace.value[0]) != 1 || left_curly_brace.isOk != 1) {
            error();
            return;
        }
        tokens.p_update_type(&tokens, right_paranthesis_index + 1, 9);
        in_for_loop = 1;

        if (is_ok_ending(placeholder_index) != 1) {
            error();
            return;
        }

    } else if (is_variable(token.value) == 1) { //                                                  VARIABLE ACCESS  //AKJSHDLKASJHDLKAJSHDLKJASHDLKASHJDHKAS
        //Token attributed_variable = *get_variable(token.value);
        //assign_type(&token, &attributed_variable);
        
        /*

        Token equals = tokens.pGet(&tokens, 1);
        if (is_single_character(equals.value) != 1) {
            error();
            return;
        }
        if (is_equals(equals.value[0]) != 1 || equals.isOk != 1) {
            error();
            return;
        }
        equals.type = 11;

        Token after_equals = tokens.pGet(&tokens, 2);
        if (is_single_character(after_equals.value) != 1) {
            error();
            return;
        }
        if (is_left_curly_brace(after_equals.value[0]) != 1 || after_equals.isOk != 1) { /////// VARIABLE ACCESSSSS !! ! ! !  ! ! !  ! ! !  
            //delimiter right curly brace
            //get_expression() -> this part is an expression

            Token right_curly_brace = tokens.pGet(&tokens, placeholder_index); 
            if (is_single_character(right_curly_brace.value) != 1) {
                error();
                return;
            }
            if (is_right_curly_brace(right_curly_brace.value[0]) != 1 || right_curly_brace.isOk != 1) {
                error();
                return;
            }

            if (is_ok_ending(placeholder_index) != 1) {
                error();
                return;
            }
        }

        //delimiter comment or line end
        //get_expression() -> this part is an expression KLAJSDLKASJD:LASJD:LAJSKDJAK:SLJDKLASJDKLJAS:KLDHAJSKLDBAKHSBD:AKSJDBLJA
        
        if (is_ok_ending(placeholder_index) != 1) {
            error();
            return;
        }

        */  //                                                   COMMENT 

    } else if (strcmp("print", token.value) == 0) {
        tokens.p_update_type(&tokens, 0, 23);

        Token left_paranthesis = tokens.pGet(&tokens, 1);
        if (is_single_character(left_paranthesis.value) != 1) {
            error();
            return;
        }
        if (is_left_paranthesis(left_paranthesis.value[0]) != 1 || left_paranthesis.isOk != 1) {
            error();
            return;
        }
        tokens.p_update_type(&tokens, 1, 5);

        //Token variable;                                                                           KLSNADKLASKJBDLAKSNDLAHSBDN:LAMSLDJBASLNDKJBASKJDH
        //might give an index if it is a matrix or vector

        //Token right_paranthesis = tokens.pGet(&tokens, placeholder_index); //PLACEHOLDER INDEX
        // if (is_single_character(right_paranthesis.value) != 1) {
        //     error();
        //     return;
        // }
        // if (is_right_paranthesis(right_paranthesis.value[0]) != 1 || right_paranthesis.isOk != 1) {
        //     error();
        //     return;
        // }
        //tokens.p_update_type(&tokens, 0, 10); // PLACEHOLDER INDEX 

        // if (is_ok_ending(placeholder_index) != 1) {                              NEED TO FINISH THIS 
        //     error();
        //     return;
        // }

    } else if (strcmp("printsep", token.value) == 0) {
        token.type = 23;

        Token left_paranthesis = tokens.pGet(&tokens, 1);
        if (is_single_character(left_paranthesis.value) != 1) {
            error();
            return;
        }
        if (is_left_paranthesis(left_paranthesis.value[0]) != 1 || left_paranthesis.isOk != 1) {
            error();
            return;
        }
        tokens.p_update_type(&tokens, 1, 5);
      
        Token right_paranthesis = tokens.pGet(&tokens, 2);
        if (is_single_character(right_paranthesis.value) != 1) {
            error();
            return;
        }
        if (is_right_paranthesis(right_paranthesis.value[0]) != 1 || right_paranthesis.isOk != 1) {
            error();
            return;
        }
        tokens.p_update_type(&tokens, 2, 6);

        if (is_ok_ending(3) != 1) {
            error();
            return;
        }

    } else {
        error();
    }
}

/*
    Initializes the attributes and adds scalar to Vector variables.
    @param char[] name - name of the variable.
*/
void initialize_scalar(char name[]) {
    Token scalar;
    scalar.isOk = 1;
    strcpy(scalar.value, name);
    scalar.type = 19;
    variables.pAdd(&variables, scalar);

}

/*
    Initializes the attributes and adds vector to Vector variables.
    @param char[] name - name of the variable.
    @param int vector_size - lenght of the vector
*/
void initialize_vector(char name[], int vector_size) {
    Token vector;
    vector.isOk = 1;
    strcpy(vector.value, name);
    vector.vector = vector_size;
    vector.type = 20;
    variables.pAdd(&variables, vector);

}

/*
    Initializes the attributes and adds matrix to Vector variables.
    @param char[] name - name of the variable.
    @param int matrix_i - i size of the matrix
    @param int matrix_j - j size of the matrix
*/
void initialize_matrix(char name[], int matrix_i, int matrix_j) {
    Token matrix;
    matrix.isOk = 1;
    strcpy(matrix.value, name);
    matrix.matrix_i = matrix_i;
    matrix.matrix_j = matrix_j;
    matrix.type = 21;
    variables.pAdd(&variables, matrix);
}

/*
    Returns the index of the right curly brace which closes the initialization.
*/
int parse_vector_matrix_initialization(int start_index) {
    Token token;
    int index = 0;
    int tokens_size = tokens.pSize(&tokens);
    while (index < tokens_size) {
        token = tokens.pGet(&tokens, start_index + index);
        if (is_single_right_curly_brace(token.value) == 1) {
            return start_index + index;
        }
        if (is_number_literal(token.value) != 1 || is_float(token.value) != 1) {
            return -1;
        }
        index++;
    }

    return -1; //placeholder
}

/*
    Checks if there is something left in the remaining part of the vector. 
    @returns 
    0 if there is something left -which is not a comment-
    1 if there is nothing left
    @param Vector* tokens
    @param int start_index  
*/
int is_ok_ending(int start_index) {
    int vector_size = tokens.pSize(&tokens); //vector pointer to int error
    int index = start_index;
    if (start_index == vector_size) {
        return 0;
    }
    if (start_index == vector_size-1) {
        Token comment = tokens.pGet(&tokens, start_index-1);
        if (is_comment(comment.value[0]) != 1) {
            return 0;
        }
        comment.type = 18;
    }
    return 1;
}

/*
    Checks if a given alphanumeric string is a variable name.
    @param char[] name - value )as in the value field inside the token) of the suspected variable.
    @returns int - 
    1 if there is a variable with name name[]
    -1 if there isn't a variable with name name[]
*/
int is_variable(char name[]) {
    for (int i = 0; i < variables.pSize(&tokens); i++) {
        Token variable = tokens.pGet(&tokens, i);
        if (strcmp(name, variable.value) == 0) {
            return 1;
        }
    }
    return -1;
}

/*
    Gets the fully attributed token for the given variable name.
    @param char[] name - value (as in the value field inside the token) of the variable.
    @returns Token token - struct Token of the variable
*/
Token get_variable(char name[]) { 
    Token variable;
    for (int i = 0; i < variables.pSize(&tokens); i++) {
        variable = tokens.pGet(&tokens, i);
        if (strcmp(name, variable.value) == 0) {    
            break;
        }
    }
    
    return variable;
}

/*
    Returns the type of that variable. Type values are assigned in the lookup table
    inside the token.h file
*/
int assign_type(Token *variable, Token *complete_variable) {
    
    return 0;
}

/*

*/
void output_generator() {
    for (int i = 0; i < tokens.pSize(&tokens); i++) {

    }
}

int main(int argc, char *argv[]) {
    
    //FILE *file;
    //file = fopen(argv[1], "r");
    int line_number = 0;
    int in_for_loop = 0;
    char line[256] = "scalar #sdasdasd";

    line_number = 1;
    printf("%s",line);
    tokenizer(line);
    parser();
    
    //printf("no no no");
    //index++;

    /*
    int index = 0;
    while(fgets(line,256,file) != NULL ) {
        printf("%s",line);
        line_number = index;
        tokenizer(line);
        
        printf("here");
        parser(&tokens);
        printf("no no no");
        index++;
    }
    */
    //fclose(file);
}

// NEEDS AN EXPRESSION FUNCTION WHICH WILL GET THE VECTOR AND THE DESIRED TYPE THAN RETURN 1 OR 0; IF 1 EXPRESSION IS VALID IF 0 EXPRESSION IS INVALID. 
// OUTPUT BOOLEAN WILL BE AFFECTED FROM BOTH SYNTAX AND EXPECTED OUTPUT
int expression(Vector *tokens, int start_index, int end_index, int expected_type){
    Token expr;
    expr = infix_to_postfix(tokens, start_index, end_index);
    if (expr.isOk == 0){
        return 0;
    }
    else{
        if (expr.type == expected_type){
            return 1;
        }
        else{
            return 0;
        }
    }
}

/*
returns the pseudo-token needed for the expression function
converts the infix expression to postfix
*/
Token infix_to_postfix(Vector *subtokens, int start, int end){
    Vector postfix_vector;
    CreateVector(&postfix_vector);
    Stack postfix_stack;
    CreateStack(&postfix_stack);
    Token return_token;
    int i = start;
    int flag = 1;

    while(i < end){
        Token next_token = subtokens->pGet(subtokens,i);

        if (next_token.type == 19 || next_token.type == 20 || next_token.type == 21) { // if the next token is an operand
            postfix_vector.pAdd(&postfix_vector, next_token);
        } else if (next_token.type == 5) { // if the next token is a left paranthesis
            postfix_stack.pPush(&postfix_stack,next_token);
        } else if (next_token.type == 6) { // if the next token is a right paranthesis
            while (postfix_stack.pPeek(&postfix_stack).type != 5) { // while we don't encounter a right paranthesis
                if (postfix_stack.pIsEmpty(&postfix_stack)) {
                    flag = 0;
                    error();
                    break;
                }
                Token tokenPoped;
                tokenPoped = postfix_stack.pPop(&postfix_stack);
                postfix_vector.pAdd(&postfix_vector,tokenPoped);
            }
            if (postfix_stack.pPeek(&postfix_stack).type == 5) {
                postfix_stack.pPop(&postfix_stack);
            }
        } else if (next_token.type == 12 || next_token.type == 13 || next_token.type == 14) { // if the next token is an operator
            if (postfix_stack.pIsEmpty(&postfix_stack) == 1) { // if the stack is empty push the operator into the stack
                postfix_stack.pPush(&postfix_stack,next_token);
            } else if (postfix_stack.pPeek(&postfix_stack).type == 5) { // if the top element is a left paranthesis push the operator into the stack
                postfix_stack.pPush(&postfix_stack,next_token);
            } else if (has_higher_precedence(next_token.type,postfix_stack.pPeek(&postfix_stack).type) == 1) { // if the operator has higher precedence than the top of the stack
                postfix_stack.pPush(&postfix_stack,next_token);
            } else if (has_higher_precedence(next_token.type,postfix_stack.pPeek(&postfix_stack).type) == 0) { // if the operator has lower precedence than the top of the stack
                while(has_higher_precedence(next_token.type,postfix_stack.pPeek(&postfix_stack).type == 0)) {
                    Token tokenPoped;
                    tokenPoped = postfix_stack.pPop(&postfix_stack);
                    postfix_vector.pAdd(&postfix_vector,tokenPoped);
                    if (postfix_stack.pIsEmpty(&postfix_stack)){
                        break;
                    }
                }
                postfix_stack.pPush(&postfix_stack,next_token);
            }
            // if they have the same precedence assume left associativity
            else if (has_higher_precedence(next_token.type,postfix_stack.pPeek(&postfix_stack).type) == 2) {
                Token tokenPoped;
                tokenPoped = postfix_stack.pPop(&postfix_stack);
                postfix_vector.pAdd(&postfix_vector,tokenPoped);
                postfix_stack.pPush(&postfix_stack, next_token);
            }
        }
        i++;
    }
    if (postfix_stack.pIsEmpty(&postfix_stack) == 0) {
        while (postfix_stack.pIsEmpty(&postfix_stack) != 1) {
            if (postfix_stack.pPeek(&postfix_stack).type != 5) {
                postfix_vector.pAdd(&postfix_vector,postfix_stack.pPop(&postfix_stack));
            } else {
                flag = 0;
                error();
                break;
            }
        }
    }
    if (flag != 0){
        return_token = evaluate_postfix(&postfix_vector);
        postfix_vector.p_free(&postfix_vector);
        postfix_stack.p_free(&postfix_stack);
        return return_token;
    }
    else{
        return_token.isOk = 0;
        postfix_vector.p_free(&postfix_vector);
        postfix_stack.p_free(&postfix_stack);
        return return_token;
    }
}

/*
evaluates the postfix expression and checks for syntax errors
returns the pseudo-token needed by the expression function
*/
Token evaluate_postfix(Vector *postfix) {
    int i = 0;
    int flag = 0;
    Stack evaluation_stack;
    CreateStack(&evaluation_stack);
    Token last_result;

    while(i < postfix->pSize(postfix)){
        Token next_token = postfix->pGet(postfix, i);

        if (next_token.type == 19 || next_token.type == 20 || next_token.type == 21) { // if the next token is an operand
            evaluation_stack.pPush(&evaluation_stack,next_token);
        } else if (next_token.type == 12 || next_token.type == 13 || next_token.type == 14) { // if the next token is an operator
            if (evaluation_stack.pSize(&evaluation_stack) >= 2) {
                Token op2 = evaluation_stack.pPop(&evaluation_stack);
                Token op1 = evaluation_stack.pPop(&evaluation_stack);
                Token result;
                result = type_check(op1,op2,next_token);
                if (result.isOk == 0) {
                    error();
                    flag = 1;
                    break;
                } else {
                    evaluation_stack.pPush(&evaluation_stack,result);
                }
            } else {
                error();
                flag = 1; 
                break;
            }
            
        }
        else{
            last_result.isOk = 0;
            evaluation_stack.p_free(&evaluation_stack);
            return last_result;
        }
        i++;
    }

    if (evaluation_stack.pSize(&evaluation_stack) != 1) {
        error();
        flag = 1;
    } else if (flag == 0) {
        printf("no error\n"); //printf???
        last_result = evaluation_stack.pPop(&evaluation_stack);
        evaluation_stack.p_free(&evaluation_stack);
        return last_result;
    }
    last_result.isOk = 0;
    evaluation_stack.p_free(&evaluation_stack);
    return last_result;
}

/*
checks if an operation is possible
compares the types according to syntax rules
retuns the resulting token
*/
Token type_check(Token op1, Token op2, Token operator) {
   Token result_token;

   if (operator.type == 12) { // if the operator is *
       if (op1.type == 18) { // if op1 is scalar
            if (op2.type == 18) { // if op2 is scalar
                // the resulting token is a scalar
                result_token.type = 18;
                result_token.isOk = 1;
                return result_token;
            } else if (op2.type == 19) { // if op2 is vector
                result_token.type = 19;
                result_token.isOk = 1;
                return result_token;
            } else if (op2.type == 20) { // if op2 is matrix
                result_token.type = 20;
                result_token.isOk = 1;
                return result_token;
            }
        } else if (op1.type == 19) { // if op1 is vector
            if (op2.type == 18) { // if op2 is scalar
                if (op1.vector == 1) {
                    result_token.type = 18;
                    result_token.isOk = 1;
                    return result_token;
                } else {
                    result_token.isOk = 0;
                    return result_token;
                }
           } else if (op2.type == 19) { // if op2 is vector
                if (op2.vector == 1) {
                    result_token.type = 19;
                    result_token.isOk = 1;
                    return result_token;
                } else {
                    result_token.isOk = 0;
                    return result_token;
                }
            } else if (op2.type == 20) { // if op2 is matrix
                if(op2.matrix_i == 1) {
                    result_token.type = 20;
                    result_token.isOk = 1;
                    return result_token;
                } else {
                    result_token.isOk = 0;
                    return result_token;
                }
            }
        } else if (op1.type == 20) { // if op1 is a matrix
            if (op2.type == 18) { // if op2 is scalar
                if (op1.matrix_i == 1 && op1.matrix_j == 1) {
                    result_token.type = 18;
                    result_token.isOk = 1;
                    return result_token;
                }
            } else if (op2.type == 19){ // if op2 is vector
                if (op1.matrix_j == op2.vector) {
                    result_token.type = 19;
                    result_token.isOk = 1;
                    return result_token;
                } else {
                    result_token.isOk = 0;
                    return result_token;
                }
            } else if (op2.type == 20) { // if op2 is matrix
                if (op1.matrix_j == op2.matrix_i) {
                    result_token.type = 20;
                    result_token.isOk =1;
                    return result_token;
                }
            }
        }
   } if (operator.type == 13 || operator.type == 14) { // if the operator is + or - 
       if (op1.type == 18) { // if op1 is scalar
            if (op2.type == 18) { // if op2 is scalar
                result_token.type = 18;
                result_token.isOk = 1;
                return result_token;
           } else if (op2.type == 19) { // if op2 is vector
                result_token.isOk = 0;
                return result_token;
           } else if (op2.type == 20) { // if op2 is matrix
                result_token.isOk = 0;
                return result_token;
           }
       } else if (op1.type == 19) {  // if op1 is vector
            if (op2.type == 18) { // if op2 is scalar
                result_token.isOk = 0;
                return result_token;
            } else if (op2.type == 19) { // if op2 is vector
                if (op1.vector == op2.vector) {
                    result_token.type = 19;
                    result_token.isOk = 1;
                    return result_token;
                } else {
                    result_token.isOk = 0;
                    return result_token;
                }
           } else if (op2.type == 20) { // if op2 is matrix
                if (op1.vector == op2.matrix_i && op2.matrix_j == 1) {
                    result_token.type = 19;
                    result_token.isOk  = 1;
                    return result_token;
                } else {
                    result_token.isOk = 0;
                    return result_token;
                }
           }
        } else if (op1.type == 20) { // if op1 is a matrix
            if (op2.type == 18) { // if op2 is scalar
                result_token.isOk = 0;
                return result_token;
            } else if (op2.type == 19) { // if op2 is vector
                if (op1.matrix_i == op2.vector && op1.matrix_j == 1) {
                    result_token.type = 19;
                    result_token.isOk = 1;
                    return result_token;
                } else {
                    result_token.isOk = 0;
                    return result_token;
                }
            } else if (op2.type == 20) { // if op3 is matrix
                if (op1.matrix_i == op2.matrix_i && op1.matrix_j == op2.matrix_j) {
                    result_token.type = 20;
                    result_token.isOk = 1;
                    return result_token;
                } else {
                    result_token.isOk = 0;
                    return result_token;
                }
            }
        }
    }

    result_token.isOk = 0;
    return result_token;
}

/*
    checks which operator has higher precedence
    @returns
    @param int incoming
    @param int top
*/
int has_higher_precedence(int incoming, int top) {
    // if the given operator is *
    if (incoming == 12) {
        if (top == 13 || top == 14){
            return 1;
        }
        else if (top == 12) {
            return 2;
        }
    } else if (incoming == 13 || incoming == 14) {
        if (top == 12) {
            return 0;
        }
        else if (top == 13 || top == 14) {
            return 2;
        }
    }

    return 3;
}
