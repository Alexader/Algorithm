/*
给定一个由n行数字组成的数字三角形如下图所示。试设计一个算法，计算出从三角形的顶至底的一条路径，使该路径经过的数字总和最大。
有一个点出发，可选的路径最多只有两条——左肩处和右肩处，边缘的点只有一条路径可走。
        7
      3   8
    8   1   0
  2   7   4   4
4   5   2   6   5
Input:
输入的第1 行是数字三角形的行数n，1£n£100。接下来n行是数字三角形各行中的数字。所有数字在0..99之间。
Sample Input:
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
Sample Output:
30
*/

#include<stdio.h>
#include<algorithm>
#define MAX_NUM 100
int main() {
	//最长金字塔
	int A[MAX_NUM][MAX_NUM];
	int B[MAX_NUM][MAX_NUM];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++)
			scanf("%d", &A[i][j]);
	}
	// 从最顶端开始走，共有 2 种选择，每一种选择又是一个小一层的金字塔
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			if(i==n-1) B[i][j] = A[i][j];
			else {
				B[i][j] = std::max(B[i + 1][j], B[i + 1][j + 1]) + A[i][j];
			}
		}
	}
	printf("%d", B[0][0]);
	return 0;
}