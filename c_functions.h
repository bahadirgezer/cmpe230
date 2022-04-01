#include "matrix.h"

float choose(float exp1, float exp2, float exp3, float exp4){
    if (exp1 == 0){
        return exp2;
    }
    else if(exp1 > 0){
        return exp3;
    }
    else if(exp1 < 0){
        return exp4;
    }
}


