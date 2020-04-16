#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <math.h>
#include "matrices.h"

#define CRIT_SIZE 5

matrix EMPTY = { 0,0,NULL };

int nums(double x) {
	int N = abs(x);
	if (N == 0) return 1;
	else {
		int i = -1, div;
		do {
			div = N % 10;
			N /= 10;
			i++;
		} while (div != 0);

		return i;
	}
}

void init_matrix(matrix M[], int rows, int cols) {
	M[0].rows = rows;
	M[0].cols = cols;
	M[0].value = (double**)malloc(rows * sizeof(double*));
	for (int i = 0; i < rows; ++i) {
		M[0].value[i] = (double*)malloc(cols * sizeof(double));
	}
}

void delete_matrix(matrix M) {
	int rows = M.rows;
	for (int i = 0; i < rows; ++i) {
		free(M.value[i]);
	}
	free(M.value);
}

void print_matrix(matrix M, int precision) {
	int cols = M.cols,
		rows = M.rows,
		max = 0;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (abs(M.value[i][j]) > max) max = abs(M.value[i][j]);
		}
	}
	max = nums(max);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (M.value[i][j] > 0) {
				printf_s(" %*.*lf ", max + precision + 1, precision, fabs(M.value[i][j]));
			}
			else {
				printf_s("-%*.*lf ", max + precision + 1, precision, fabs(M.value[i][j]));
			}
		}
		printf_s("\n");
	}
	printf_s("\n");
}

void fill_rand(matrix M, int min, int max, int denominator) {
	srand(time(NULL));
	int cols = M.cols,
		rows = M.rows;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			M.value[i][j] = (rand() % (max - min + 1) + min);
			M.value[i][j] /= denominator;
		}
	}
}

void fill_indentity(matrix M) {
	if (M.cols != M.rows)	printf_s("Warning! Matrix isn't rectengular. \n");

	int cols = M.cols,
		rows = M.rows;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (i != j) M.value[i][j] = 0;
			else M.value[i][j] = 1;
		}
	}
}

void fill_zero(matrix M) {
	int cols = M.cols,
		rows = M.rows;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			M.value[i][j] = 0;
		}
	}
}

matrix create_copy(matrix M) {
	int cols = M.cols,
		rows = M.rows;
	matrix Copy;
	init_matrix(&Copy, rows, cols);

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			Copy.value[i][j] = M.value[i][j];
		}
	}

	return Copy;
}

matrix summ(matrix A, matrix B) {
	if (A.cols == B.cols && A.rows == B.rows) {
		matrix C;
		int rows = A.rows,
			cols = A.cols;
		init_matrix(&C, rows, cols);
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				C.value[i][j] = A.value[i][j] + B.value[i][j];
			}
		}
		return C;
	}
	else {
		printf_s("impossible to summate matrices. \n");
		return EMPTY;
	}
}

matrix mult(matrix A, matrix B) {
	if (A.cols == B.rows) {
		matrix C;
		int rows = A.rows,
			cols = B.cols,
			length = A.cols;
		double sum;
		init_matrix(&C, rows, cols);
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				sum = 0;
				for (int k = 0; k < length; ++k) {
					sum += A.value[i][k] * B.value[k][j];
				}
				C.value[i][j] = sum;
			}
		}
		return C;
	}
	else {
		printf_s("Impossible to multiply matrices. \n");
		return EMPTY;
	}
}

matrix transpose(matrix A) {
	matrix C;
	int rows = A.cols,
		cols = A.rows;
	init_matrix(&C, rows, cols);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			C.value[i][j] = A.value[j][i];
		}
	}
	return C;
}

void make_minor(matrix M, int im, int jm, matrix A) {
	int rows = A.rows,
		cols = A.cols;
	for (int i = 0; i < im; ++i) {
		for (int j = 0; j < jm; ++j) {
			M.value[i][j] = A.value[i][j];
		}
	}
	for (int i = im + 1; i < rows; ++i) {
		for (int j = 0; j < jm; ++j) {
			M.value[i - 1][j] = A.value[i][j];
		}
	}
	for (int i = 0; i < im; ++i) {
		for (int j = jm + 1; j < cols; ++j) {
			M.value[i][j - 1] = A.value[i][j];
		}
	}
	for (int i = im + 1; i < rows; ++i) {
		for (int j = jm + 1; j < cols; ++j) {
			M.value[i - 1][j - 1] = A.value[i][j];
		}
	}
}

double recursive_det(matrix A) {
	if (A.rows == 1) return A.value[0][0];
	else {
		double det = 0;
		matrix B;
		init_matrix(&B, A.rows - 1, A.cols - 1);
		for (int j = 0; j < A.cols; ++j) {
			if (A.value[0][j] != 0) {
				make_minor(B, 0, j, A);
				if (j % 2 == 0) {
					det += A.value[0][j] * recursive_det(B);
				}
				else {
					det -= A.value[0][j] * recursive_det(B);
				}
			}
		}
		delete_matrix(B);
		return det;
	}
}

double determinant(matrix M) {
	if (M.rows != M.cols) {
		printf("Impossible to calculate determnant\n");		// Есы матрикс не квадратный, то сразу баним
		return 0;
	}
	else if (M.rows == 1) {
		return M.value[0][0];
	}
	else if (M.rows <= CRIT_SIZE) {
		return recursive_det(M);
	}
	else {
		int size = M.rows, swaps = 0; // Куча добрых букав
		double det = 1, temp;
		matrix A = create_copy(M);

		for (int j = 0; j < size - CRIT_SIZE; ++j) {

			int i = j;
			for (int k = i + 1; k < size; ++k) {
				if ((fabs(A.value[k][j]) < fabs(A.value[i][j])) && A.value[k][j] != 0) i = k;
			}
			if (i == j && A.value[i][j] == 0) { return 0; }
			if (i != j) {
				for (int k = j; k < size; ++k) {
					temp = A.value[i][k];
					A.value[i][k] = A.value[j][k];
					A.value[j][k] = temp;
				}
				swaps++;
			}

			det *= A.value[j][j];

			for (i = j + 1; i < size; ++i) {
				if (A.value[i][j] != 0) {

					temp = A.value[i][j] / A.value[j][j];

					for (int k = j; k < size; ++k) {
						A.value[i][k] = A.value[i][k] - temp * A.value[j][k];
					}
				}
			}
		}

		matrix B;
		init_matrix(&B, CRIT_SIZE, CRIT_SIZE);
		for (int i = 0; i < CRIT_SIZE; ++i) {
			for (int j = 0; j < CRIT_SIZE; ++j) {
				B.value[i][j] = A.value[size - CRIT_SIZE + i][size - CRIT_SIZE + j];
			}
		}
		det *= recursive_det(B);
		delete_matrix(A);
		delete_matrix(B);

		if (swaps % 2 == 0) return det;
		else return -det;
	}
}

matrix inverse_matrix(matrix M) {
	if (M.rows != M.cols) {
		printf("Impossible to calculate inverse matrix. \n");
		return EMPTY;
	}
	else if (M.rows == 1) {
		matrix C;
		init_matrix(&C, 1, 1);
		C.value[0][0] = 1 / M.value[0][0];
		return C;
	}
	else {
		int size = M.rows;
		double temp;
		matrix A = create_copy(M);
		matrix I;
		init_matrix(&I, size, size);
		fill_indentity(I);

		for (int j = 0; j < size; ++j) {

			int i = j;
			for (int k = i + 1; k < size; ++k) {
				if ((fabs(A.value[k][j]) < fabs(A.value[i][j])) && A.value[k][j] != 0) i = k;
			}
			if (i == j && A.value[i][j] == 0) {
				printf_s("Can't calculate inverse matrix. \n");
				return EMPTY;
			}
			if (i != j) {
				for (int k = j; k < size; ++k) {
					temp = A.value[i][k];
					A.value[i][k] = A.value[j][k];
					A.value[j][k] = temp;
				}
				for (int k = 0; k < size; ++k) {
					temp = I.value[i][k];
					I.value[i][k] = I.value[j][k];
					I.value[j][k] = temp;
				}
			}
			temp = A.value[j][j];
			for (i = j; i < size; ++i) {
				A.value[j][i] /= temp;
			}
			for (i = 0; i < size; ++i) {
				I.value[j][i] /= temp;
			}

			for (i = j + 1; i < size; ++i) {
				if (A.value[i][j] != 0) {

					temp = A.value[i][j];

					for (int k = j; k < size; ++k) {
						A.value[i][k] -= temp * A.value[j][k];
					}
					for (int k = 0; k < size; ++k) {
						I.value[i][k] -= temp * I.value[j][k];
					}
				}
			}
		}
		for (int j = size - 1; j > 0; --j) {
			for (int i = j - 1; i >= 0; --i) {
				if (A.value[i][j] != 0) {

					temp = A.value[i][j];

					for (int k = j; k < size; ++k) {
						A.value[i][k] -= temp * A.value[j][k];
					}
					for (int k = 0; k < size; ++k) {
						I.value[i][k] -= temp * I.value[j][k];
					}
				}
			}
		}

		delete_matrix(A);
		return I;
	}
}