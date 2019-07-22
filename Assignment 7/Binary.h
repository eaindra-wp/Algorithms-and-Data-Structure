#ifndef _BINARY_H
#define _BINARY_H

#include <bits/stdc++.h>
#include "LinkedList.h"
using namespace std;

class Binary
{
private:

    class node
    {
    public:
        int data;
        node *left;
        node *right;
        node() {}
        node(const int& data)
        {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
    };

    node *root;

    //insert new elements to the binary tree
    //at given location
    void addNode(node *n, const int& data)
    {
        //if the new element is smaller, then
        //it will be added to the left node
        if(data <= n->data)
        {
            if(n->left == NULL)
                n->left = new node(data);
            else
                this->addNode(n->left, data);
        }
        //otherwise, to the right node
        else
        {
            if(n->right == NULL)
                n->right = new node(data);
            else
                this->addNode(n->right, data);
        }
    }
    //convert binary search tree to linked list
    //recursively in order
    void BtoLinkedList(node *n, LinkedList& l)
    {
        if(n->right != NULL)
            this->BtoLinkedList(n->right, l);
        l.push(n->data);
        if(n->left != NULL)
            this->BtoLinkedList(n->left, l);
    }

public:

    Binary()
    {
        this->root = NULL;
    }
    //insert a new element to the binary tree
    //if the tree is empty, start from the root,
    //otherwise,add to left or right in the
    //private function
    void addNode(const int& data)
    {
        if(this->root == NULL)
        {
            this->root = new node(data);
            return;
        }
    this->addNode(this->root, data);
    }
    //if the root is empty, do nothing
    //otherwise, recursively convert
    //to linked list
    void BtoLinkedList(LinkedList& l)
    {
        if(this->root == NULL)
            return;
        this->BtoLinkedList(this->root, l);
    }
};

#endif
