#include <iostream>
#define TOT		6
#define MAX		8
#define FIND	9

/*
 * Recursive way to solve the problem
 */
int binarySearch(int *A, int v, int i, int j) {
	if (i >= j) 
		return -1;
	int m = (i+j)/2;
	if (A[m] < v) 
		return binarySearch(A,v,m+1,j);
	if (A[m] > v)
		return binarySearch(A,v,i,m);
	return m;
}

/*
 * Iterative way to solve the problem
 */
int iterativeBinarySearch(int* A, int v, int n) {
	int low = 0, high = n;
	while(high > low) {
		int mid = (high+low)/2;
		if (A[mid] == v) return mid;
		if(A[mid] < v) low = mid+1;
		else high = mid;
	}
	return -1;
}

int main() {
	int A[TOT][MAX] = {
		{1,3,5,7,9,13,18,21},			// 4
		{2,3,4,6,7,9,52,75},			// 5
		{-10,-2,0,12,45,56,102,157},	// -1
		{9,12,15,18,21,24,27,30},		// 0
		{-1,1,2,3,4,6,7,9},				// 7
		{2,9,12,14,15,16,20,25}			// 1
	};


	std::cout << "Recursive way: \n";
	for (int i = 0; i < TOT; i++) {
		std::cout << "pos A[" << i << "]: " << binarySearch(A[i],FIND,0,MAX) << std::endl;
	}
	std::cout << "Iterative way: \n";
	for (int i = 0; i < TOT; i++) {
		std::cout << "pos A[" << i << "]: " << iterativeBinarySearch(A[i],FIND,MAX) << std::endl;
	}

	return 0;
}