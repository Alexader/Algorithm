/*
游艇问题：长江游艇俱乐部在长江上设置了n 个游艇出租站1，2，…，n。游客可在这些游艇出租站租用游艇，并在下游的任何一个游艇出租站归还游艇。
游艇出租站i 到游艇出租站j 之的租金为r(i,j),1<=i<j<=n。试设计一个算法，计算出从游艇出租站1 到游艇出租站n 所需的最少租金。

要求：对于给定的游艇出租站i 到游艇出租站j 之间的租金为r(i,j),1£i<j£n，编程计算从游艇出租站1 到游艇出租站n所需的最少租金
Input:
输入数据的第1 行中有1 个正整数n（n<=200），表示有n个游艇出租站。接下来的n-1 行是r(i,j),1<=i<j<=n。
Output:
输出数据有n 行，给出从游艇出租站1 到游艇出租站n所需的最少租金。
*/
#include<stdio.h>
#define MAX_NUM 200
int main() {
	int A[MAX_NUM + 1][MAX_NUM + 1];
	int B[MAX_NUM + 1][MAX_NUM + 1];
	int n;
	scanf("%d", &n);
	//A[i][j] 保存了i 到j的费用,无效的地方视为零
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++)
			scanf("%d", &A[i][j]);

	//B[i][j] 保存了i 到j的最小费用,无效的地方视为零
	for (int i = 1; i <= n; i++)
		B[i][i] = 0;

	for (int i = 1; i < n; i++) {
		for (int j = 1; i + j <= n; j++) {
			int min = 10000000;
			for (int q = j + 1; q <= i + j; q++)
				if (min > A[j][q] + B[q][i + j]) min = A[j][q] + B[q][i + j];
			B[j][j + i] = min;
		}
	}
  for(int i=1;i<=n;i++)
	  printf("%d\n", B[1][i]);
}