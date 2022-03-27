#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
int main() {

    Vector v1;
    CreateVector(&v1);


    for(int i = 0; i < 100; i++){
        Token t;
        t.value = "a";
        v1.pAdd(&v1,t);
    }
    for(int i = 0; i < v1.pSize(&v1); i++){
        Token t = v1.pGet(&v1,i);

        printf("%s\n", t.value);
    }

    return 0;
}
