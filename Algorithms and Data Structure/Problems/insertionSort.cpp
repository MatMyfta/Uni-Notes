/*
 * Insertion Sort algorithm
 * for each item, "insert" it like a card in a deck,
 * so shift the greater items and swap the last grea-
 * test item with the one we are considering. This a-
 * lgorithm should have a time complexity of O(n^2).
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

void insertionSort(int* a, const int n) {
	// for each element (excluded the first)
	for (int i = 1; i < n; i++) {
		// consider the ith item
		int tmp = a[i];
		int j = i;
		// shif the greater items
		while (j > 0 && a[j-1] > tmp) {
			a[j] = a[j-1];
			j--;
		}
		a[j] = tmp;
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
		insertionSort(A[i],DIM);
		print(A[i],DIM);
	}
}