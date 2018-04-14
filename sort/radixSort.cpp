#include<iostream>
#include<cmath>
using namespace std;

inline int getNthDigit(int x, int nth) {
	return x % (int)pow(10.0, (double)nth) / 10;
}
// Suppose elements in input is less than range, sorted array
// will be stored in input.
void countingSort(int *input, int n, int range, int digitNum) {
	int *store = new int[range];
	int *temp = new int[n];
	// init int value in store to 0 and start counting
	for(int i=0;i<range;i++)
		store[i] = 0;
	// counting how many same value elements in `input`
	for(int i=0;i<n;i++)
		store[getNthDigit(input[i], digitNum)]++;
	for(int i=1;i<range;i++)
		store[i] = store[i] + store[i-1];
	for(int i=n-1;i>=0;i--) {
		temp[store[getNthDigit(input[i], digitNum)] - 1] = input[i];
		store[getNthDigit(input[i], digitNum)] -= 1;
	}
	for(int i=0;i<n;i++)
		input[i] = temp[i];
}

void radixSort(int *arr, int n, int range, int numDigits) {
	for(int i=1;i<=numDigits;i++) {
		countingSort(arr, n, range, i);	
	}
}

int main() {
	int A[6] = {2,7,5,3,1,8};
	cout<<"Array before sort: ";
	for(int i=0;i<6;i++)
		cout<<A[i]<<" ";
	cout<<endl;
	countingSort(A, 6, 10, 1);
	cout<<"Array after sort: ";
	for(int i=0;i<6;i++)
		cout<<A[i]<<" ";
	cout<<endl;
	// using radix sort
	int B[6] = {23,72,54,3,13,86};
	cout<<"Array before sort: ";
	for(int i=0;i<6;i++)
		cout<<B[i]<<" ";
	cout<<endl;
	radixSort(B, 6, 10, 3);
	cout<<"Array after sort: ";
	for(int i=0;i<6;i++)
		cout<<B[i]<<" ";
	cout<<endl;
}
