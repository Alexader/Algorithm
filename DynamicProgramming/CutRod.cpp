// #include<stdio.h>
// void move(int k, char a, char b) {
// 	printf("%d %c %c\n", k, a, b);
// }
// void Hnoii(int n, char a, char b, char c) {
// 	if(n==1)
// 		move(n, a, b);
// 	else {
// 		Hnoii(n-1, a, c, b);
// 		move(n, a, b);
// 		Hnoii(n-1, c, b, a);
// 	}
// }
// int main() {
// 	int n;
// 	scanf("%d", &n);
// 	Hnoii(n, 'a', 'b', 'c');
// }
#include <stdio.h>
#include <algorithm>
#include<vector>
using std::vector;

int sum = 0;
int *mark;
bool Subset(vector<int> &S, int k, int c) {
	if(sum == c) return true;
	else if(sum > c || k+1 > S.size()) return false;
	else{
		if(Subset(S, k+1, c-S[k])) {
			printf("%d ", S[k]);
			sum += S[k];
			return true;
		}
		else if(Subset(S, k+1, c)) return true;
	}
}
int main() {
	int n,c;
	vector<int> arr;
	while(scanf("%d%d", &n, &c)!=EOF) {
		int temp;
		mark = new int[n];
		for(int i=0;i<n;i++) {
			scanf("%d", &temp);
			arr.push_back(temp);
		}
		Subset(arr, 0, c);
	}
	return 0;
}