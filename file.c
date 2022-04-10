#include <stdio.h>
#include "matlangc_functions.h"
int main(){
// # this program computes fibonacci
 // # numbers
 // # variable definitions
 float i;
float n;
Matrix x;
create_matrix(&x,2,1);
Matrix y;
create_matrix(&y,2,1);
Matrix A;
create_matrix(&A,2,2);
Matrix B;
create_matrix(&B,2,2);
// # statements
 n = 10;
x.arr[0][0] = 1;
x.arr[1][0] = 1;
A.arr[0][0] = 1;
A.arr[0][1] = 1;
A.arr[1][0] = 1;
A.arr[1][1] = 0;
B.arr[0][0] = 1;
B.arr[0][1] = 0;
B.arr[1][0] = 0;
B.arr[1][1] = 1;
print_matrix(&x);
for (i = 1; i <= n; i+=1) {
	assign_matrix(B,multiply(A,B));
	assign_matrix(y,multiply(B,x));
	printf("%f\n",get_vector_elem(y, 1));
	}

}