/*
 * Bubble Sort algorithm
 * compare each item of the array with the next. This
 * algorithm should have a time complexity of O(n^2).
 */

#include <iostream>
#include <algorithm>
#define TOT	5
#define DIM	5

void print(int *a, int n) {
	for (int i = 0; i < n; i++) 
		std::cout << a[i] << " ";
	std::cout<<std::endl; 
}

void bubbleSort(int* a, const int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i] < a[j]) 
				std::swap(a[i],a[j]);
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
		bubbleSort(A[i],DIM);
		print(A[i],DIM);
	}
}