#include "sort.h"

void replace(void*a, void*b, size_t size_of_elements) {
	char temp = *((char*)a);
	*((char*)a) = *((char*)b);
	*((char*)b) = temp;
}

void bubble(void *array, size_t size_of_array, size_t size_of_elements, _CoreCrtNonSecureSearchSortCompareFunction compare) {
	for (int j = 0; j < size_of_array; ++j)
		for (int i = j; i < size_of_array; ++i)
			if (compare((char*)array + j*size_of_elements, (char*)array + i * size_of_elements)) 
				replace((char*)array + j * size_of_elements, (char*)array + i * size_of_elements, size_of_elements);
}