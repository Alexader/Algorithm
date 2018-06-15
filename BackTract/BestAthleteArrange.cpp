/*
Description
羽毛球队有男女运动员各n人。给定2 个n×n矩阵P和Q。
P[i][j]是男运动员i和女运动员j配对组成混合双打的男运动员竞赛优势；
Q[i][j]是女运动员i和男运动员j配合的女运动员竞赛优势。由于技术配合和心理状态等各种因素影响，
P[i][j]不一定等于Q[j][i]。男运动员i和女运动员j配对组成混合双打的男女双方竞赛优势为P[i][j]*Q[j][i]。
设计一个算法，计算男女运动员最佳配对法，使各组男女双方竞赛优势的总和达到最大。

Input
输入数据的第一行有1 个正整数n (1≤n≤20)。接下来的2n行，每行n个数。前n行是p，后n行是q。

Output
输出数据一行，为计算出的男女双方竞赛优势的总和的最大值。

Sample Input
3
10 2 3
2 3 4
3 4 5
2 2 2
3 5 3
4 5 1
Sample Output
52
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>

const double eps = 1.0e-4;
int n, maxNum, curNum;
int *mark;// mark 记录男运动员选择女搭档的选择
bool checkChoice(int pos, int k) {
  // 不能两个男运动员选一个女运动员做搭档
  for(int i=0;i<k;i++)
    if(mark[i] == pos) return false;
  return true;
}
void search(int **man, int **woman, int s) {
  if(s>=n) return;
  else {
    for(int i=0;i<n;i++) {
      if(checkChoice(i, s)) {
        // 如果下标为 s 的男运动员可以选择第 i 位女运送员，记录在Mark中，优势值增加
        mark[s] = i;
        curNum += man[s][i]*woman[i][s];
        if(curNum > maxNum) maxNum = curNum;
        // 为下一位男运动员挑选搭档
        search(man, woman, s+1);
        // 进行回溯，改男运动员的其他选择
        curNum -= man[s][i]*woman[i][s];
        mark[s] = -1;
      }
    }
  }
}

int main() {
  scanf("%d", &n);
  int **a = new int*[n];
  int **b = new int*[n];
  for(int i=0;i<n;i++) {
    a[i] = new int[n];
    b[i] = new int[n];
  }
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      scanf("%d", &a[i][j]);
  
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      scanf("%d", &b[i][j]);

  curNum = maxNum = 0;
  mark = new int[n];
  search(a, b, 0);
  printf("%d",maxNum);
  return 0;
}
