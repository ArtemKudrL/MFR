#pragma once

#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <math.h>

#define CRIT_SIZE 5

typedef struct matrix {
	int rows;
	int cols;
	double **value;
}matrix;

int nums(double x);
void init_matrix(matrix M[], int rows, int cols);
void delete_matrix(matrix M);
void print_matrix(matrix M, int precision);
void fill_rand(matrix M, int min, int max, int denominator);
void fill_indentity(matrix M);
void fill_zero(matrix M);
matrix create_copy(matrix M);
matrix summ(matrix A, matrix B);
matrix mult(matrix A, matrix B);
matrix transpose(matrix A);
void make_minor(matrix M, int im, int jm, matrix A);
double recursive_det(matrix A);
double determinant(matrix M);
matrix inverse_matrix(matrix M);