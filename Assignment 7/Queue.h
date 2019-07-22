#include <iostream>
#include <cstdlib>
#include "Stack2.h"
using namespace std;
template<class T>
class Queue
{
private:
    Stack<T> s1; //input stack
    Stack<T> s2; //output stack
    int size;
public:
    //push elements to the first stack
    void enqueue(T elem)
    {
        this->s1.push(elem);
        this->size++;
    }
    T dequeue()
    {
        //push all element from s1 to
        //s2 by popping from s1 one by one
        while (!this->s1.isEmpty())
            this->s2.push(this->s1.pop());

        if (this->s2.isEmpty())
        {
            cout << "Queue is empty" << endl;;
            exit(0);
        }
        //return the top of s2
        T y = this->s2.pop();
        this->size--;
        return y;
    }
    bool isEmpty()
    {
        return (this->size == 0);
    }
};
