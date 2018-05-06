/*
这是 0/1 背包问题的解法：
0/1 背包问题：如果你有一个容量为 c （单位体积）的背包，还有 n 件物品，每件物品的
体积分别是 [ w_1, w_2.... w_n ], 对应没见物品的价值 [ v_1, v_2.... v_n ].
问：如何放置物品能够使得背包中的总价值最大

解法：这是一道典型的动态规划问题，动态规划的本质在于问题可以分成 n 个阶段，每一个
阶段可能存在多种状态 { s_1, ... s_n }, 而且在不同的阶段转移的过程中，可能会存在
一个阶段的一个状态可以转移到下个阶段的多个不同的状态，所以往往状态的数目不会很多，
但是状态转移的数目会呈现指数增长。但是动态规划问题的
该问题中一个背包装入 n 件物品的问题看做阶段 n ,也就是说阶段 n 可以从 阶段 1 转移而来，
一个阶段的状态是指 第 n 件物品是不是选入背包，共有两种状态 { 0（不选）， 1（选入） } 
从阶段 n-1 到 阶段 n 的联系：
S(n) = S(n-1)*1 + S(n-1)*0 
*/

#include<iostream>
#include<algorithm>
using namespace std;


int Knapsack(int *w, int *v, const int n, const int c) {
  // int** m = new int*[n+1];
  // for(int i=0;i<c;i++)
  //   m[i] = new int[c];
  int m[n+1][c+1];

  for(int i=0;i<=n;i++) {
    for(int j=0;j<=c;j++) {
      // 第零个物品是没有物品的含义，所以装入的价值是0
      if(i == 0 || j == 0) m[i][j] = 0;
      else {
        // 第 i个物品装不下 j 容量的背包
        if(j<w[i-1]) m[i][j] = m[i-1][j];
        else {
          // 第 i 个物品装得下，但是有两种不同的选择，优选价值大的。
          m[i][j] = max(m[i-1][j], m[i-1][j-w[i-1]] + v[i-1]);
        }
      }
    }
  }
  cout<<"table of m:"<<endl;
  for(int i=0;i<=n;i++) {
    for(int j=0;j<=c;j++)
      cout<<m[i][j]<<"  ";
    cout<<endl;
  }
  return m[n][c];
}

int main() {
  int w[4] = { 3, 2, 5, 2 };
  int v[4] = { 5, 3, 1, 4 };
  int c = 10;
  int n = 4;
  int maxValue = Knapsack(w, v, n, c);
  cout<<"the max value for this K napSack problem is:"<<maxValue<<endl;
}