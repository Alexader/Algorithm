#include<iostream>
#include<algorithm>
using namespace std;

/*
Dynamic Programming (Cutting a Rod)
Given a rod of length n inches and an array of prices that contains prices
of all pieces of size smaller than n. Determine the maximum value obtainable
by cutting up the rod and selling the pieces. For example, if length of the
rod is 8 and the values of different pieces are given as following, then the
maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)
length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20
And if the prices are as following, then the maximum obtainable value is 24
(by cutting in eight pieces of length 1)

length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 3   5   8   9  10  17  17  20

Problem: If you have a rod of n inches, and every cut-up will cost `c` unit money,
please write a algorithm to determine how to cut and print out solution like below.
price array is given and you donot have to worry about n is larger than array length
Given:
length   | 0   1   2   3   4   5    6    7    8    9    10
-----------------------------------------------------------
price    | 0   1   5   8   9   10   17   17   20   24   30
c : 1
Output:
You shuld cut like this:
1 3 4 5 6
total cost is 17.
*/

// Only output best price result.
int CutRod(int *p, int n, int* solve, int* record, int c) {
	if(solve[n] >= 0)
		return solve[n];
	int q;
	if(n == 0)
		q = 0;
	else {
		q = -1;
		for(int i=1;i<=n;i++) {
			q = max(q, p[i] + CutRod(p, n-i, solve, record, c) - c);
		}
	}
	solve[n] = q;
	return q;
}

int BottomUpCutRod(int *p, int n, int* solve, int* record, int c) {
	for(int i=0;i<=n;i++) {
		int max = 0;
		for(int j=0;j<=i;j++) {
			if(max < p[j] + record[i-j] - (i-j)? 0: c) {
				max = p[j] + record[i-j] - (i-j)? 0: c;
				solve[i] =  j;
			}
		}
		record[i] = max;
	}
	return record[n];
}

void printCutSolution(int *solve, int n) {
	cout<<"You shuld cut like this:"<<endl;
	int t = n;
	while(t>0) {
		cout<<solve[t]<<" ";
		t = t - solve[t];
	}
}

int main() {
	int p[] = {0,1,5,8,9,10,17,17,20,24,30};
	int n, c;
	cout<<"what is the length of the rod:"<<endl;
	cin>>n;
	cout<<"what is the cost per cut:"<<endl;
	cin>>c;

	int *solve = new int[n+1];
	int *record = new int[n+1];
	for(int i=0;i<=n;i++)
		record[i] = -1;
	BottomUpCutRod(p, n, solve, record, c);
	cout<<"total cost is : "<<BottomUpCutRod(p, n, solve, record, c)<<endl;	
	cout<<"total cost is : "<<CutRod(p, n, solve, record, c)<<endl;
	printCutSolution(solve, n);
}
