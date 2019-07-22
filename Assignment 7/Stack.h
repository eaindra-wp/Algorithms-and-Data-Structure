#ifndef _STACK_H
#define _STACK_H

#include <iostream>
#include <cstdlib>

using namespace std;
template<class T>
class Stack
{
private:
    struct StackNode
    {
    public:
        T data;
        StackNode *next;
        StackNode() {}
        StackNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

    StackNode *top;
    int size;
    int current_size;

public:
    //push elements to the stack
    void push(const T& elem)
    {
        //check for overflow
        if(this->current_size == this->size)
        {
            cout << "Overflow" << endl;
            exit(1);
        }
        if(this->top == NULL)
        {
            this->top = new StackNode(elem);
            this->current_size++;
            return;
        }
        //shift the pointers
        StackNode *newnode = new StackNode(elem);
        newnode->next = this->top;
        this->top = newnode;
        this->current_size++;
    }

    T pop()
    {
        //check for underflow
        if(this->current_size == 0)
        {
            cout << "Underflow" << endl;
            exit(1);
        }
        //point the top element
        StackNode *tmp = this->top;
        T res = tmp->data;
        //copy that top element to a new variable
        delete tmp;
        //and delete from the stack
        this->current_size--;
        if(this->current_size== 0)
        {
            this->top = NULL;
        }
        else
        {
            this->top = this->top->next;
        }
        return res;
        //return the popped(deleted) element
    }
    bool isEmpty()
    {
        return (this->current_size==0);
    }
    //parametric constructor
    Stack(int new_size)
    {
        this->top = NULL;
        this->size = new_size;
        this->current_size = 0;
    }
    Stack()
    {
        this->top = NULL;
        this->size = -1;
        //initialize the size to -1
        this->current_size = 0;
    }
};

#endif
