#include<iostream>
#include "tree.h"
using namespace std;



int main() {
	Binary_tree tree;

	cout << endl;

	int arr[10] = {1,5,8,2,3,9,4,7,6,10 };

	for (int i = 0; i < 10; i++) tree.insert(arr[i]);
	tree.remove(5);
	Iterator* iter = tree.create_bft_iterator();

	for (int i = 0; i < 9; i++) {
		cout << iter->next();
		cout << tree.contains(arr[i]) << endl;
	}

	cout << endl;
	
	cout<<tree.contains(6);
	
	
}

