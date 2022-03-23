#include "main.h"
#include <stdio.h>

void expression(char *expr[]) {
    if (1) {}

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
