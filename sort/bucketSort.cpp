#include <iostream>

using namespace std;

struct node
{
	int x;
	node* next;
	node() {x = 0;next = nullptr;}
	node(int x) :x(x), next(nullptr) {}
};
struct list
{
	node* head;
	int len;
	list() {
		len = 0;
		head = new node();
	}
	// insert a new node and still maintain sorted
	void sortedInsert(int x) {
		node *new_node = new node(x);
		node *temp = head;
		while(temp->next != nullptr) {
			if(temp->next->x > x) {
				new_node->next = temp->next;
				temp->next = new_node;
				len++;
				return;
			}
			else
				temp = temp->next;
		}
		temp->next = new_node;
		len++;
	}
};

// Elements in arr are within 100 positive integer
void bucketSort(int* arr, int n, int bucketSize) {
	list** bucket = new list*[bucketSize];
	// init empty list array
	for(int i=0;i<bucketSize;i++)
		bucket[i] = new list();
	// insert elements in arr to bucket
	for(int i=0;i<n;i++)
		bucket[arr[i]/bucketSize]->sortedInsert(arr[i]);
	node* temp;
	// put elements in bucket back to arr
	for(int i=0, j=0;i<bucketSize;i++) {
		temp = bucket[i]->head->next;
		while(temp != nullptr) {
			arr[j] = temp->x;
			j++;
			temp = temp->next;
		}
	}
}

int main(int argc, char const *argv[])
{
	int arr[7] = {2, 45, 12, 67, 32, 9, 3};
	cout<<"Array before sort: ";
	for(int i=0;i<7;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	bucketSort(arr, 7, 11);
	cout<<"Array after sort: ";
	for(int i=0;i<7;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}
