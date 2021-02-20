/*
 * Merge Sort algorithm
 * divide the vector in 2 parts, then merge the ordered
 * parts. This algorithm has a time complexity of 
 * \Theta(n logn).
 */

#include <iostream>
#define TOT	5
#define DIM	5

void print(int *a, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}
	std::cout<<std::endl; 
}

void merge(int *a, int primo, int ultimo, int mezzo) {
	int i=primo, j=mezzo+1, k=primo, h;
	int b[ultimo];
	while (i <= mezzo and j <= ultimo)
		if (a[i] < a[j]) 
			b[k++] = a[i++];
		else 
			b[k++] = a[j++];
	j = ultimo;
	for (h = mezzo; h >= i; h--)
		a[j--] = a[h];
	for (j = primo; j < k; j++) 
		a[j] = b[j];
}

void _mergeSort(int *a, int primo, int ultimo) {
	if (primo < ultimo) {
		int mezzo = (primo+ultimo)/2;
		_mergeSort(a,primo,mezzo);
		_mergeSort(a,mezzo+1,ultimo);
		merge(a,primo,ultimo,mezzo);
	}
}

void mergeSort(int*a, int n) {
	_mergeSort(a,0,n-1);
}

int main() {
	int A[TOT][DIM] = {
		{0,1,2,3,4},		// 0,1,2,3,4
		{4,3,2,1,0},		// 0,1,2,3,4
		{1,6,9,3,2},		// 1,2,3,6,9
		{1,-6,9,-3,2},		// -6,-3,1,2,9
		{-10,6,9,0,27},		// -10,0,6,9,27
	};

	for (int i = 0; i < TOT; i++) {
		mergeSort(A[i],DIM);
		print(A[i],DIM);
	}
}