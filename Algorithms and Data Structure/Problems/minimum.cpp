#include <iostream>
using namespace std;

int min(int *A, int n) {
	int min = A[0];
	for (int i = 1; i < n; i++) 
		if (A[i] < min)
			min = A[i];
	return min;
}

int main() {
	const int TOT = 3;
	const int DIM = 10;
	int A[TOT][DIM] = {
		{1,6,4,9,-4,3,5,8,-8,10},		// -8
		{2,5,7,3,12,6,8,5,3,15},		// 2
		{0,1,2,3,4,5,6,7,8,9}			// 0
	};

	for (int i = 0; i < TOT; i++) {
		cout << "min: " << min(A[i],DIM) << endl;
	}

	return 0;
}