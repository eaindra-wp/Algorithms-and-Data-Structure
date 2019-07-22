#include <bits/stdc++.h>
using namespace std;

//Linked List
class List
{
public:
    int data;
    List* next;
};

//Binary Tree
class Binary
{
public:
    int data;
    Binary* left;
    Binary* right;
};

Binary* newNode(int data);
int NodeCount(List *head);
Binary* ListToTree(List **head, int n);

//count the number of nodes in the linked list
//and call the conversion function
Binary* ListToTree(List *head)
{
    int n = NodeCount(head);
    return ListToTree(&head, n);
}

//to construct the binary search tree
//with the number of nodes got from
//linked list and return the root of node
Binary* ListToTree(List **head, int n)
{
    if (n <= 0)
        return NULL;

    //recursively construct the left binary search tree
    //n/2 is the number of nodes for the left sub tree
    Binary *left = ListToTree(head, n/2);

    //allocate the memory and connect with the left
    //binary search subtree
    Binary *root = newNode((*head)->data);
    root->left = left;
    //shift the pointer forward after linking
    *head = (*head)->next;

    //recursively construct right binary search tree
    //n-n/2-1 is the number of nodes for right sub tree
    root->right = ListToTree(head, n-n/2 - 1);
    return root;
}
//to count the number of elements in the linked list
int NodeCount(List *head)
{
    int count = 0;
    List *temp = head;
    while(temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
void push(List** head, int newdata)
{
	//allocate the new list
	List* nn = new List();
	//add new data received
	nn->data = newdata;
	//link the new element with existing list
	nn->next = (*head);
    //move the pointer to point new node
	(*head) = nn;
}
//print the list
void printList(List *n)
{
	while(n!=NULL)
	{
		cout << n->data << " ";
		n = n->next;
	}
}
//allocate new nodes and set left and right
//nodes as null
Binary* newNode(int data)
{
	Binary* nn = new Binary();
	nn->data = data;
	nn->left = NULL;
	nn->right = NULL;
	return nn;
}
//to recursively print the binary
//tree version
void treeprint(Binary* nn)
{
	if (nn == NULL)
		return;
	cout << nn->data << " ";
	treeprint(nn->left);
	treeprint(nn->right);
}

