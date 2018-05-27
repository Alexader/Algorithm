/*
描述:
假设要在足够多的会场里安排一批活动，并希望使用尽可能少的会场。设计一个有效的贪心算法进行安排。
(这个问题实际上是著名的图着色问题。若将每一个活动作为图的一个顶点，不相容活动间用边相连。
使相邻顶点着有不同颜色的最小着色数，相应于要找的最小会场数。)
要求：对于给定的k个待安排的活动，编程计算使用最少会场的时间表。
输入：
输入数据的第一行有1 个正整数k(k<=10000)，表示有k个待安排的活动。接下来的k行中，
每行有2个正整数，分别表示k个待安排的活动开始时间和结束时间。时间以0 点开始的分钟计。
输出：输出数据为1行，表示计算出的最少会场数。
样例输入：
5
1 23
12 28
25 35
27 80
36 50
样例输出：
3
*/
#include <stdio.h>
#include <algorithm>
struct meeting
{
	int start;
	int end;
};
bool cmp(meeting a, meeting b)
{
	if (a.start != b.start)
		return a.start < b.start;
	else
		return a.end < b.end;
}
int main()
{
	int k, sum = 0;
	scanf("%d", &k);
	meeting *schedual = new meeting[k];
	meeting *temp = new meeting[k];
	for (int i = 0; i < k; i++)
		scanf("%d%d", &schedual[i].start, &schedual[i].end);

	// 将会议按照起始时间升序排序，如果起始时间相同，结束时间小的排在前面
	std::sort(schedual, schedual + k, cmp);
	int lastX = 0, top = 0;
	do
	{
		for (int i = 0; i < k; i++)
		{
			if (schedual[i].start >= lastX)
				lastX = schedual[i].end;
			else
			{
				temp[top].start = schedual[i].start;
				temp[top].end = schedual[i].end;
				top++;
			}
		}
		for(int i=0;i<top;i++) {
			schedual[top].start = temp[i].start;
				schedual[top].end = temp[i].end;
		}
		k = top;
		lastX = top = 0;
		sum++;
	} while (k != 0);
	printf("%d", sum);
}
