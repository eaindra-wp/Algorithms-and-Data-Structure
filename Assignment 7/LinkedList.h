#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H
#include <bits/stdc++.h>
using namespace std;
class LinkedList
{
private:
    class node
    {
    public:
        int data;
        node *next;
        node() {}
        node(const int& data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

    node *init;

public:
    LinkedList()
    {
        this->init = NULL;
    }
    //push new elements to the list
    void push(const int& nl)
    {
        if(this->init == NULL)
        {
            this->init = new node(nl);
            return;
        }
        //move the pointers and add new element
        node *newnode = new node(nl);
        newnode->next = this->init;
        this->init = newnode;
    }
    //print linked list
    void print()
    {
        if(this->init == NULL)
            return;

        node *cur = this->init;
        while(cur != NULL)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};
#endif
