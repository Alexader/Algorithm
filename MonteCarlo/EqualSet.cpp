/*
Description
给定2 个集合S和T，试设计一个判定S和T是否相等的蒙特卡罗算法
Input
输入包括若干组数据，每组数据的第一行有1 个正整数n，表示集合的大小。接下来的2行，
每行有n个正整数，分别表示集合S和T中的元素。

Output
输出包括若干组数据，若集合S和T相等则输出YES，否则输出NO。

Sample Input
3
2 3 7
7 2 3
Sample Output
YES
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>

int n;
const double e = 0.0000002;
bool judge(int *S1, int *S2, double e) {
  // the time you should run Montte Carlo algorithm
  int times = (int)ceil(log(1/e)/log(2));
  int count = 0;
  // random selelct element from set1 and check if there is equal
  // one in set2.
  for(int i=0;i<times;i++) {
    int rand1 = rand()%n;
    for(int j=0;j<n;j++) {
      if(S1[rand1] == S2[j]) {count++;break;}
    }
  }
  if(count==times) return true;
  else return false;
}
int main() {
  int* S1,*S2;
  scanf("%d", &n);
  S1 = new int[n];
  S2 = new int[n];
  for(int i=0;i<n;i++)
    scanf("%d", &S1[i]);
  for(int i=0;i<n;i++)
    scanf("%d", &S2[i]);

  if(judge(S1, S2, e))
    printf("YES");
  else
    printf("NO");
}
