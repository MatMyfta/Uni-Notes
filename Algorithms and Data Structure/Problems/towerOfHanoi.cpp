#include <iostream>
#define TOH(n) ( towerOfHanoi(n,'A','B','C') )
using namespace std;

void towerOfHanoi(int n, char A, char B, char C) {
	if (n >= 1) {
		towerOfHanoi(n-1,A,C,B);
		cout << "move top disk from tower " << A << " to tower " << B << endl;
		towerOfHanoi(n-1,C,B,A);
	}
}

int main() {
	int DIM = 5;
	int A[DIM] = {
		3,			// 2^3-1 = 7	moves
		4,			// 2^4-1 = 15	moves
		5,			// 2^5-1 = 31	moves
		7,			// 2^7-1 = 127	moves
		9			// 2^9-1 = 511	moves
	};

	/*
	 *DIM = 1;
	 *A[0] = 64;	// if you want to break everything
	 */
	
	for (int i = 0; i < DIM; ++i) {
		TOH(A[i]);
		cout << endl;
	}
	return 0;
}