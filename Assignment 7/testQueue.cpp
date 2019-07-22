#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include "Queue.h"
using namespace std;
int main()
{
    cout << "Test" << endl;
    Queue<int> q;
    for(int i=0; i<5; i++)
    {
        q.enqueue(i);
    }
    for(int i=0; i<5; i++)
    {
        cout << q.dequeue() << endl;
    }
    return 0;
}
