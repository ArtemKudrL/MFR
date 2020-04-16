#pragma once

#define N 3
#define M 5

#include <stdio.h>
#include <stdlib.h>

void bubble(void *array, size_t size_of_array, size_t size_of_elements, _CoreCrtNonSecureSearchSortCompareFunction compare);
void qwerty(int **R) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			R[j][i] = i + j;
		}
	}
}