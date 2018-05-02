#include<iostream>
#include<algorithm>
#include <string>
/*
C++ program for solving longest common sequence
*/
using namespace std;

void printLCS(string x, int** b, int m, int n) {
	if(m==0 || n==0) return;
	if(b[m][n]==1) {
		printLCS(x, b, m-1, n-1);
		cout<<x[m-1];
	}
	else if(b[m][n] == 2)
		printLCS(x, b, m-1, n);
	else
		printLCS(x, b, m, n-1);
}

int LCS(string x, string y) {
	int m = x.size();
	int n = y.size();
	int** c = new int*[m+1];
	int** b = new int*[m+1];

	for(int i=0;i<=m;i++){
		c[i] = new int[n+1];
		b[i] = new int[n+1];
	}

	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++) {
			if(i==0 || j==0) {
				c[i][j] = 0;
				b[i][j] = 0;
			}
			else if(x[i-1] == y[j-1]){
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = 1;
			}
			else if(c[i-1][j] >= c[i][j-1]) {
				c[i][j] = c[i-1][j];
				b[i][j] = 2;
			} else {
				c[i][j] = c[i][j-1];
				b[i][j] = 3;
			}
		}
	}

	int LCS = c[m][n];
	cout<<"The longest common sequence is "<<LCS<<endl;
	cout<<"c table is showed below"<<endl;
	for(int i=0;i<=m;i++) {
		for(int j=0;j<=n;j++)
			cout<<c[i][j]<<" ";
		cout<<endl;
	}
	cout<<"b table is showed below"<<endl;
	for(int i=0;i<=m;i++) {
		for(int j=0;j<=n;j++)
			cout<<b[i][j]<<" ";
		cout<<endl;
	}
	printLCS(x, b, m, n);
	return LCS;
}


int main(int argc, char const *argv[])
{
	// string first, second;
	// cout<<"What is first string sequence:(Press enter when finish your string) "<<endl;
	// getline(cin,first);
	// cout<<"What is second string sequence:(Press enter when finish your string)"<<endl;
	// getline(cin,second);

	string x = "AGGTAB", y = "GXTXAYB";
	// int l = LCS(first, second);
	int l = LCS(x, y);
	return 0;
}
