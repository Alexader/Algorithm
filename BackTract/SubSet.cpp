/*
子集和问题的一个实例为<S,t>。其中，S={x1,x2,...,xn}是一个正整数的集合，c是一个正整数。
子集和问题判定是否存在S 的一个子集S1，使得子集里的元素之和为c。
试设计一个解子集和问题的回溯法。（这个题目只需要找到第一个符合要求的子集就可以）
输入：
输入数据的第1 行有2 个正整数n(n<=100) 和c，n 表示S 的大小，c是子集和的目标值。
接下来的1 行中，有n 个正整数，表示集合S 中的元素。
输出：
输出数据为将子集中的元素，当问题无解时，输出“No solution!“。
样例输入：
5 10
2 2 6 5 4
样例输出：
2 2 6
*/
#include <stdio.h>
#include <algorithm>
#include<stack>
#include<vector>
using std::stack;
using std::vector;

using std::reverse;
int sum = 0,n;
stack<int> mark;
bool Subset(vector<int> &S, int k, int c) {
	if(sum == c) return true;
	// 提前剪枝，如果已经超过给定值或者已经选择完所有元素了，就不用继续挑选下一个元素了
	else if(sum > c || k >= n) return false;
	else{
		if(Subset(S, k+1, c-S[k])) {
			// 如果找到一个可以实现的子集，记录下来子集元素在原集合中的下标
			mark.push(k);
			sum += S[k];
			return true;
		}
		else if(Subset(S, k+1, c)) return true;
	}
}
int main() {
	int c;
	vector<int> arr;
	while(scanf("%d%d", &n, &c)!=EOF) {
		int temp;
		for(int i=0;i<n;i++) {
			scanf("%d", &temp);
			arr.push_back(temp);
		}
		if(Subset(arr, 0, c)) {
			int size = mark.size() -1;
			for(int i=0;i<size;i++) {
				printf("%d ", arr[mark.top()]);
				mark.pop();
			}
			printf("%d", arr[mark.top()]);			
			mark.pop();
		} else
		printf("No Solution!");
	}
	return 0;
}