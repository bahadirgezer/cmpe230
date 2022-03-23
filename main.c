#include "main.h"
#include <stdio.h>
#define MAX_SIZE 256;


struct Stack {
    int size;
};

void initialize_stack(struct Stack stack) {
    stack.size = 0;
}

int isfull(struct Stack stack) {
    if (stack.size == MAX_SIZE) {
        return 1;
    } else {
        return 0;
    }
}

void push(struct Stack stack) {
    if (stack.currentSize < MAX_SIZE)
}

void expression(char *expr[]) {
    

}

void tr() {

}

int main(int argc, char *argv[]) {
    FILE *input_file;

    /* Open file for reading Filename is given on the command line */
    input_file = fopen(argv[1], "r");

    if(input_file == NULL) {
        printf("Cannot open %s\n",argv[1]);
        return 1;
    }
    
    while( fgets(line,80,fp) != NULL ) {
        printf("%s",line) ;
    }
    fclose(input_file);
    return 0;
}
