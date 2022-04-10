#include <stdlib.h>
#include <stdio.h>

typedef struct Matrix Matrix;

struct Matrix
{
    int matrix_i;
    int matrix_j;
    float **arr;
};



void create_matrix(Matrix *m, int i, int j)
{
    m->matrix_i = i;
    m->matrix_j = j;
    m->arr = (float **)malloc(i * sizeof(float *));
    for (int a = 0; a < i; a++)
    {
        m->arr[a] = (float *)malloc(j * sizeof(float));
    }
    for (int k; k < i; k++)
    {
        for (int n; n < j; n++)
        {
            m->arr[k][n] = 0;
        }
    }
}

void assign_matrix(Matrix m1, Matrix m2) {
    for (int i = 0; i < m1.matrix_i; i++) {
        for (int j = 0; j < m1.matrix_j; j++) {
            m1.arr[i][j] = m2.arr[i][j];
        }
    }
}

Matrix multiply(Matrix m1, Matrix m2)
{
    Matrix* multiplication = (Matrix*) malloc(sizeof(Matrix));
    create_matrix(multiplication, m1.matrix_i, m2.matrix_j);
    for (int i = 0; i < multiplication->matrix_i; i++)
    {
        for (int j = 0; j < multiplication->matrix_j; j++)
        {
            for (int k = 0; k < m2.matrix_i; k++)
            {
                multiplication->arr[i][j] += m1.arr[i][k] * m2.arr[k][j];
            }
        }
    }
    return *multiplication;
}

Matrix multiply_scalar(Matrix m1, float s)
{
    Matrix* multiplication = (Matrix*) malloc(sizeof(Matrix));
    create_matrix(multiplication, m1.matrix_i, m1.matrix_j);
    for (int i = 0; i < multiplication->matrix_i; i++)
    {
        for (int j = 0; j < multiplication->matrix_j; j++)
        {
            multiplication->arr[i][j] = m1.arr[i][j] * s;
        }
    }
    return *multiplication;
}
Matrix add(Matrix m1, Matrix m2)
{
    Matrix* sum = (Matrix*) malloc(sizeof(Matrix));
    create_matrix(sum, m1.matrix_i, m1.matrix_j);
    for (int i = 0; i < sum->matrix_i; i++)
    {
        for (int j = 0; j < sum->matrix_j; j++)
        {
            sum->arr[i][j] = m1.arr[i][j] + m2.arr[i][j];
        }
    }
    return *sum;
}

Matrix subtraction(Matrix m1, Matrix m2)
{
    Matrix* difference = (Matrix*) malloc(sizeof(Matrix));
    create_matrix(difference, m1.matrix_i, m1.matrix_j);
    for (int i = 0; i < m1.matrix_i; i++)
    {
        for (int j = 0; j < m1.matrix_j; j++)
        {
            difference->arr[i][j] = m1.arr[i][j] + m2.arr[i][j];
        }
    }
    return *difference;
}

Matrix transpose(Matrix m)
{
    Matrix* transpose = (Matrix*) malloc(sizeof(Matrix));
    create_matrix(transpose, m.matrix_j, m.matrix_i);
    for (int i = 0; i < m.matrix_i; i++)
    {
        for (int j = 0; j < m.matrix_j; j++)
        {
            transpose->arr[j][i] = m.arr[i][j];
        }
    }
    return *transpose;
}

float get_vector_elem(Matrix m, int i) {
    return m.arr[i-1][0];
}

float get_matrix_elem(Matrix m, int i, int j) {
    return m.arr[i-1][j-1];
}

void print_matrix(Matrix *m){
    for (int i = 0; i < m->matrix_i; i++) { 
        for (int j = 0; j < m->matrix_j; j++) {
            printf("%f\n", m->arr[i][j]);
        }
    }
}

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
