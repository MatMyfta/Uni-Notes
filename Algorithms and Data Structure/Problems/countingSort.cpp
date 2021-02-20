/*
 * Counting Sort algorithm
 * counts the number of occurences of the kth value in
 * the array b[1...k], then rewrites the first array.
 * This algorithm has a time complexity of \Theta(n).
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

void countingSort(int *a, int n, int k) {
	int b[k];
	for (int i = 0; i < k; i++) 
		b[i] = 0;
	for (int i = 0; i < n; i++)
		b[a[i]]++;

	int j = 0;
	for (int i = 0; i < k; i++) {
		while (b[i] > 0) {
			a[j++] = i;
			b[i]--;
		}
	}
}

int main() {
	// values go from 0 to 4
	int k = 5;
	int A[TOT][DIM] = {
		{0,1,2,3,4},		// 0,1,2,3,4
		{4,3,2,1,0},		// 0,1,2,3,4
		{1,1,1,2,2},		// 1,1,1,2,2
		{2,3,4,4,1},		// 1,2,3,4,4
		{4,3,3,2,2},		// 2,2,3,3,4
	};

	for (int i = 0; i < TOT; i++) {
		countingSort(A[i],DIM,k);
		print(A[i],DIM);
	}
}