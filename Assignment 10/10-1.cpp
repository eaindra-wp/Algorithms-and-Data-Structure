#include <iostream>
#include <vector>

using namespace std;

//print the vector which contains the subarray in the longest order.
void print(vector<int> arr)
{
    for (auto x=arr.begin(); x!=arr.end(); x++)
    {
        cout << *x << " ";
    }
}
void largestOrdered(vector<int> arr, int n)
{
    //create a nested vector STL
    vector<vector<int>> len(n);
    //will be used to push and compare length sizes
    //of the subarray and save elements
    //the ending element will be arr[i]

    //push the first element of original array into the first
    //vector of new nested vector
    len[0].push_back(arr[0]);
    //so the size of first index in length array will be 1.

    //find the longest sequence in the table mode
    //start using the second character to be compared
    //in each iteration, each element (element at index i)
    //will be compared with j(i-1) elements in each loop
    //starting from (j=0 to i-1)
    for (int i=1; i<n; i++)
    {
        for (int j=0; j<i; j++)
        {
            //we compare element at index i with preceding
            //elements at indexes j=0 to i-1

            //if the element at index i is larger than element at
            //index j and vector size at index j is larger than
            //vector size at index i
            //then assign elements from vector at index j to vector at index i
            if ((arr[i]>arr[j]) && (len[j].size()>len[i].size()))
            {
                len[i]=len[j];
            }
        }
        //push the current element at index i in the original list to the
        //ith index vector in the nested vector
        len[i].push_back(arr[i]);
        //print the length size value in the length array in ascending order
        //length size of all indexes will be one unless the condition
        //in the inner loop is true
    }
    cout << endl;
    //assume length size of first vector index to be largest to compare with
    //the rest in the vector
    vector<int> maxx = len[0];
    for (vector<int> k : len)
    {
        //if vector with larger size in the nested vector is found,
        //change the current subarray to the largest
        if (k.size()>maxx.size())
            maxx = k;
        //longest ordered subarray will be max of all increasing subarrays
    }
    print(maxx);
}
int main()
{
    //create a new vector list
    vector<int> arr;
    int k;
    //stop asking integer inputs when the input is new line
    while(cin.peek()!='\n')
    {
        cin>>k;
        //cin considers as a end of one input if a space or
        //a new line is found,so we can type all elements
        //separated by space

        //receive inputs till negative number is inputed.
        arr.push_back(k);

    }
    int n = arr.size();
    largestOrdered(arr, n);
    return 0;
}
