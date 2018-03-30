#include<iostream>
#include<string>
#include <list>
using namespace std;
using std::list;

list<int>* mergeList(list<int>* l1, list<int>* l2) {
	// compare two sorted list and merge into one sorted list
	list<int>* retList = new list<int>();
	list<int>::iterator p1, p2;
	for(p1=l1->begin(),p2=l2->begin();p1!=l1->end()||p2!=l2->end();) {
		if(p2==l2->end()||*p1<*p2) {
			retList->push_back(*p1);
			p1++;
		}
		else {
			retList->push_back(*p2);
			p2++;
		}
	}
	return retList;
}

int main(int argc, char const *argv[]) {
	list<int>* mylist = new list<int>();
	for(int i=0;i<5;i++)
		mylist->push_back(i*2);
	list<int>* mylist2 = new list<int>();
	for(int i=5;i<10;i++)
		mylist2->push_back(i);
	list<int>::iterator it;
	for(it=mylist2->begin();it!=mylist2->end();it++)
		cout<<*it<<" ";
	cout<<endl;
	list<int>* mylist3 = new list<int>();
	mylist3 = mergeList(mylist2, mylist);
	
	for(it=mylist3->begin();it!=mylist3->end();it++)
		cout<<*it<<" ";
}
