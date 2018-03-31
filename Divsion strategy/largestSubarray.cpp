/*
suppose you have a n length array which has int type. You have to find
a contiuous subarray which has max sum.
Exmaple:
A = [1, 3, 6, -9, 2, -2].
then answer is C = [1,3,6].
You should return the subarray's low and high bound
*/
#include<iostream>
using namespace std;
const int MIN_INT = -65535;

struct values {	
	int lower_bound;
	int high_bound;
	int sumMax;
	values() {};
	values(int low, int high, int sum) : lower_bound(low), high_bound(high), sumMax(sum) {}
};

/*
violent solvement, times complexity is n^2
*/
values violence(int *arr, int n) {
	int max = MIN_INT;
	int sum = 0;
	int high, low;
	for(int i=0;i<n;i++) {
		sum = 0;
		for (int j = i; j < n; ++j)
		{
			sum += arr[j];
			if(sum > max) {
				max = sum;
				low = i;
				high =j;
			}
		}
	}
	values v(low, high, max);
	return v;
}

values findCrossMax(int *arr, int low, int mid, int high) {
	int left_max, right_max;
	int left, right;
	int sum = 0;
	for(int i=mid - 1;i>=low;i--) {
		sum += arr[i];
		if(sum > left_max) {
			left = i;
			left_max = sum;
		}
	}
	sum = 0;
	for(int i=mid;i<high;i++) {
		sum += arr[i];
		if(sum > right_max) {
			right = i;
			right_max = sum;
		}
	}
	values v(left, right, left_max + right_max);
	return v;
}

/*
subarray of any array is either all in the left side of middle point, or all in the right side
of middle point, otherwise it will cross the middle point. Therefore we can divide the problem
whcih is to find the largest subarray into three part: find largest subarray on left side, find
largest subarray on right side, find largest subarray cross middle.
time complexity is nlog(n)
*/
values division(int *arr, int low, int high) {
	if(low == high) {
		values v(low, high, arr[low]);
		return v;
	}
	values left_max, right_max, cross_max;
	int mid = (low + high) /2;
	left_max = division(arr, low, mid);// left side largest
	right_max = division(arr, mid, high);// right side largest
	cross_max = findCrossMax(arr, low, mid, high);// cross middle situation
	if(left_max.sumMax > right_max.sumMax && left_max.sumMax > cross_max.sumMax) return left_max;
	else if(right_max.sumMax > left_max.sumMax && right_max.sumMax > cross_max.sumMax) return right_max;
	else return cross_max;
}

int main() {
	int A[] = {1, 3, 6, -3, 4, 2};
	values vio = violence(A, 6);
	cout<<"lower bound is :"<<vio.lower_bound<<"\n higher bound is :"<<vio.high_bound<<\
	"\n max sum is :"<<vio.sumMax<<endl;
	values div = division(A, 0, 6);
	cout<<"lower bound is :"<<div.lower_bound<<"\n higher bound is :"<<div.high_bound<<\
	"\n max sum is :"<<div.sumMax<<endl;
}