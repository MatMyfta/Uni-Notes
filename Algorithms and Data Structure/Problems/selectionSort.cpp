/*
 * Selection Sort algorithm
 * for each position, search the minimum of the sub-
 * array that starts at that position and ends at the
 * n-position, then put the minimum in the initial p-
 * osition. This algorithm should have a time comple-
 * xity of O(n^2).
 */

#include <iostream>
#include <algorithm>
#define TOT	5
#define DIM	5

void print(int *a, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}
	std::cout<<std::endl; 
}

int min(int *a, const int start, const int n) {
	int min=start;
	for (int i = start+1; i < n; i++) {
		if (min > a[i]) {
			min = i;
		}
	}
	return min;
}

void selectionSort(int* a, const int n) {
	for (int i = 0; i < n; i++) {
		std::swap(a[i],a[min(a,i,n)]);
	}
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
		selectionSort(A[i],DIM);
		print(A[i],DIM);
	}
}