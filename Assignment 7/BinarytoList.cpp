#include <bits/stdc++.h>
#include "Binary.h"
using namespace std;

int main()
{
    //testcase
    Binary bst;
    int n;
    cin >> n;
    for(int i = 0; i < 2*n; i+=2)
        bst.addNode(i);

    LinkedList ll;
    bst.BtoLinkedList(ll);
    ll.print();
    return 0;
}
