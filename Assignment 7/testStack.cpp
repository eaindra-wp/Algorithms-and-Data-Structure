#include <iostream>
#include <cstdio>
#include "Stack.h"
using namespace std;

int main()
{
    Stack<int> s1;
    cout << "TestCase 1" << endl;
    for(int i = 0; i < 5; i++)
    {
        s1.push(i);
    }
    while(!s1.isEmpty())
    {
        cout << s1.pop() << endl;
    }
    cout << "TestCase 2" << endl;
    Stack<double> s2(10);
    for(double i=0.5; i<10; i++)
    {
        s2.push((double)i);
    }
    cout.precision(3);
    while(!s2.isEmpty())
    {
        cout << fixed << s2.pop() << endl;
    }

    return 0;
}
