#include<iostream>
using namespace std;

// Suppose elements in input is less than k, sorted array
// will be stored in input.
void countSort(int *input, int n, int k) {
	int *store = new int[k];
	int *temp = new int[n];
	for(int i=0;i<k;i++)
		store[i] = 0;
	for(int i=0;i<n;i++) {
		store[input[i]]++;
	}
	for(int i=1;i<k;i++)
		store[i] = store[i] + store[i-1];
	for(int i=n-1;i>=0;i--) {
		temp[store[input[i]] - 1] = input[i];
		store[input[i]] -= 1;
	}
	for(int i=0;i<n;i++)
		input[i] = temp[i];
}
int main() {
	int A[6] = {2,7,5,3,1,8};
	cout<<"Array before sort: ";
	for(int i=0;i<6;i++)
		cout<<A[i]<<" ";
	cout<<endl;
	countSort(A, 6, 10);
	cout<<"Array after sort: ";
	for(int i=0;i<6;i++)
		cout<<A[i]<<" ";
	cout<<endl;
}
