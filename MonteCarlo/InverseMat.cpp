/*
Description
给定2 个n×n 矩阵a 和b，试设计一个判定a 和b 是否互逆的蒙特卡罗算法。算法的
计算时间应为O(n2)。

Input
输入包括多个测试例子，输入数据的第一行有1 个正整数n，表示矩阵a和b 为n×n矩阵.
接下来的2n行，每行有n个实数，分别表示矩阵a和b 中的元素。

Output
输出包括多个测试例子，矩阵a 和b 互逆则输出YES，否则输出NO。

Sample Input
3
1 2 3
2 2 3
3 3 3
-1 1 0
1 -2 1
0 1 -0.666667
Sample Output
YES
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
const double e = 0.0002;
const double eps = 1.0e-4;
bool judge(double **a, double **b, int n) {
  int times = (int)ceil(log(1/e)/log(2));
  for (int i = 0; i < times; i++)
  {
    int x = rand() % n;
    int y = rand() % n;
    double sum = 0;
    for (int j = 0; j < n; j++)
      sum += a[x][j] * b[j][y];
    if (x == y) {
      if (fabs(sum - 1.0) > eps)
        return false;
    }
    else
      if(fabs(sum) > eps)
        return false;
  }
  return true;
}
int main() {
  int n;
  scanf("%d", &n);
  double **a = new double*[n];
  double **b = new double*[n];
  for(int i=0;i<n;i++) {
    a[i] = new double[n];
    b[i] = new double[n];
  }
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      scanf("%lf", &a[i][j]);
  
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      scanf("%lf", &b[i][j]);

  if(judge(a, b, n)) printf("YES");
  else printf("NO");

  return 0;
}
