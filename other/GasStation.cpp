/*
描述：
一辆汽车加满油后可行驶n公里。旅途中有若干个加油站。设计一个有效算法，指出应
在哪些加油站停靠加油，使沿途加油次数最少。并证明算法能产生一个最优解。
对于给定的n和k个加油站位置，编程计算最少加油次数。
输入：
第一行有2 个正整数n和k，表示汽车加满油后可行驶n公里，且旅途中有k(k<1000)个加油站。
接下来的1 行中，有k+1 个整数，表示第k个加油站与第k-1 个加油站之间的距离。
第0 个加油站表示出发地，汽车已加满油。第k+1 个加油站表示目的地。
输出：
输出数据的第一行为最少加油次数。如果无法到达目的地，则输出”No Solution!”。
样例输入：
7 7
1 2 3 4 5 1 6 6
样例输出：
4
*/
#include<stdio.h>

int main() {
	int n,k;
	scanf("%d%d", &n, &k);
	int *s = new int[k+1];
	for(int i=0;i<=k;i++)
		scanf("%d", &s[i]);
	
	int sum = 0, gas = n;
	for(int i=0;i<=k;i++) {
		if(gas>=s[i]) {
			gas -= s[i];
		} else if(s[i] <= n) {
			gas = n-s[i];
			sum++;
		}
		else {
			printf("No Solution!");
			return 0;
		}
	}
	printf("%d", sum);
	return 0;
}