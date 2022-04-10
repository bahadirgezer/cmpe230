#include <stdio.h>
#include "matlangc_functions.h"
int main(){
// # count how many elements are
 // # greater than or equal to 4
 Matrix A;
create_matrix(&A,4,4);
float count;
float incr;
float i;
float j;
A.arr[0][0] = 0;
A.arr[0][1] = 1;
A.arr[0][2] = 2;
A.arr[0][3] = 3;
A.arr[1][0] = 4;
A.arr[1][1] = 5;
A.arr[1][2] = 6;
A.arr[1][3] = 7;
A.arr[2][0] = 8;
A.arr[2][1] = 9;
A.arr[2][2] = 1;
A.arr[2][3] = 1;
A.arr[3][0] = 1;
A.arr[3][1] = 2;
A.arr[3][2] = 3;
A.arr[3][3] = 4;
count = 0;
for (i = 1; i <= 4; i+=1) {
	for (j = 1; j <= 4; j+=1) {
	incr = choose((get_matrix_elem(A, i, j)-4), 1, 1, 0);
	count = (count+incr);
	
}}
printf("%f\n",count);

}