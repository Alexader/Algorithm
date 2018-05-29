#include<stdio.h>

int partition(int A[], int left, int right) {
  // 按照中间元素把数组分成两组——比中间元素大的和比它小的
	int mid = (left+right)/2;
	int p = A[mid];
	while(left<right) {
		while(left<right && A[left]<p) left++;
		while(left<right && A[right]>=p) right--;
		int temp = A[right];
		A[right] = A[left];
		A[left] = temp;
	}
	A[left] = p;
	return left;
}
int randSelect(int A[], int left, int right, int k) {
	if(left==right) return A[left];
	int p = partition(A, left, right);
	int M = p-left+1;
	if(M == k) return A[p];
	else if(p+1>k) return randSelect(A, left, p-1, k);
	else return randSelect(A, p+1, right, k-M);
}

int main() {
  // n 表示数组长度，k 表示要找到第几大的元素
	int *A, n,k;
	scanf("%d%d", &n, &k);
	A = new int[n];
	for(int i=0;i<n;i++) {
		scanf("%d", &A[i]);
	}
	int kth = randSelect(A, 0, n-1, k);
	printf("%d", kth);
}