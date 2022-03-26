#include <stdio.h>
#include <string.h>

int main (int argc,char *argv[]) {
FILE *fp;
FILE *out;
int flag = 0;



char line[255];

/* Open file for reading Filename is given on the command line */

if (argc != 2) {

    printf("Give filename as command line argument\n") ;

    return(1);  

}
// printf("%s",argv[1]);

fp = fopen(argv[1], "r");

out = fopen("out.c" , "w");

if(fp == NULL) {

    printf("Cannot open %s\n",argv[1]);

    return(1);
}


while( fgets(line,255,fp) != NULL ) { 

    char* tokens = strtok(line, " ");
    if (strcmp(tokens,"#") == 0){ 
        fprintf(out,"// ");
        while (tokens != NULL){   
            tokens = strtok(NULL,tokens);
            
            fprintf(out,"%s",tokens);
            
            tokens = strtok(NULL," ");
        }
    }
    else if (strcmp(tokens,"scalar") == 0){
        fprintf(out,"int ");
        tokens = strtok(NULL," ");
        tokens[strcspn(tokens, "\n")] = 0;
        fprintf(out, "%s;\n" , tokens);

        
    }
    else if (strcmp(tokens,"vector") == 0){
        tokens = strtok(NULL," ");
        fprintf(out,"int ");
        char* nexttoken = tokens;
        char vectorName[256] = "";
        char vectorSize[256] = "";
        
        while(*nexttoken != '['){
            // printf("%c", *nexttoken);
            strncat(vectorName,nexttoken,1);
            // printf("%s-----------\n",toprint);
            nexttoken++;
        }
        nexttoken++;
        while(*nexttoken != ']'){
            // printf("%c", *nexttoken);
            strncat(vectorSize,nexttoken,1);
            // printf("%s&&&&&&&&&\n",toprint);
            nexttoken++;
        }
        // printf("%s\n", toprint);
        // printf("%s\n" , varsize);
        fprintf(out, "%s[%s];\n",vectorName,vectorSize);
        vectorName[0] = '\0';
        vectorSize[0] = '\0';
        // printf("%s",toprint);

        
    }
    else if (strcmp(tokens,"matrix") == 0){
        fprintf(out,"int ");
        tokens = strtok(NULL," ");
        char* nexttoken = tokens;
        char matrixName[] = "";
        char firstSize[] = "";
        char secondSize[] = "";
        while(*nexttoken != '['){
            // printf("%c", *nexttoken);
            strncat(matrixName,nexttoken,1);
            nexttoken++;
        }
        nexttoken++;
        while (*nexttoken != ','){
            strncat(firstSize, nexttoken,1);
            nexttoken++;
        }
        nexttoken++;
        while (*nexttoken != ']')
        {
            strncat(secondSize,nexttoken,1);
            nexttoken++;
        }
        fprintf(out,"%s[%s][%s];\n",matrixName,firstSize,secondSize);
        matrixName[0] = '\0';
        firstSize[0] = '\0';
        secondSize[0] = '\0';

    }


}
// fprintf(out, "int main(){return 0;}");
fclose(fp);


return(0);

}