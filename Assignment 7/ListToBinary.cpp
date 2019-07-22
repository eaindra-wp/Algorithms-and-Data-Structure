#include <bits/stdc++.h>
#include "ListToBinary.h"
int main()
{
	//initialize an empty list
	List* elem = NULL;

	//push elements into the list
	//and the format will be
	// 3->6->9->12->15->18->21 afterwards
    for(int i=21; i>0; i-=3)
    {
        push(&elem, i);
    }
	cout<<"Linked List:" << endl;
	printList(elem);
	cout << "\n";

	//convert the list to binary tree
	Binary *tree = ListToTree(elem);
	cout << "Binary Search Tree Version:" << endl;
	treeprint(tree);

	return 0;
}
