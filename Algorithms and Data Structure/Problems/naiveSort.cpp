/*
 * [NOT FUNCTIONING]
 * Naive sort - try all the possible permutations and
 * check if the permutation is correctly sorted. This
 * algorithm should be O(nn!)
 */

#include <iostream>
#define TOT	5
#define DIM 5
#define MAX_INT 2147483647

bool isSorted(int *A, int n) {
	for (int i = 0; i < n-1; i++) 
		if (A[i] < A[i+1] || A[i] == MAX_INT) 
			return false;
	return true;
}

void print(int *a, int n) {
	for (int i = 0; i < n; i++) std::cout<<a[i]<<" ";
	std::cout<<std::endl;
}

void copy(int *b, int *a, int n) {
	for (int i = 0; i < n; i++) a[i] = b[i];
}

void naiveSort(int *a, int *b, int *ret, bool *u, const int n, int i) {
	// check if *b is full
	if (i < n) {
		// for each value in b
		for (int j = 0; j < n; j++) {
			// check if a[j] is already used
			if(!u[j]) {
				// if not used, add it to b[i]
				// then mark it as used
				b[i] = a[j];
				u[j] = true;
				// naive sort for the other values
				naiveSort(a,b,ret,u,n,++i);
				// free the value in order to reuse it
				u[j] = false;
			}
		}
	} else if (isSorted(b,n)) {
		copy(b,ret,n);
	}
}

int main() {
	int A[TOT][DIM] = {
		{0,1,2,3,4},		// 0,1,2,3,4
		{4,3,2,1,0},		// 0,1,2,3,4
		{1,6,9,3,2},		// 1,2,3,6,9
		{1,-6,9,-3,2},		// -6,-3,1,2,9
		{-10,6,9,0,27},		// 1,2,3,6,9
	};
	int B[TOT+1][DIM];
	bool U[TOT][DIM];
	for (int i = 0; i < TOT; i++) {
		for (int j = 0; j < DIM; j++) {
			B[TOT][DIM] = MAX_INT;
			U[TOT][DIM] = false;
		}
	}

	for (int i = 0; i < TOT; i++) {
		naiveSort(A[i],B[i],B[TOT],U[i],DIM,0);
		print(B[TOT],DIM);
	}
}