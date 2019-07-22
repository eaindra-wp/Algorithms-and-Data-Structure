#include <iostream>
#include <cstdlib>
#include <list>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
void maxSum(int **arr,int n)
{
    //copy all elements from the array to a new array
    int sumarr[n][n];
    for (int i=0; i<n; i++)
    {
        for (int j =0; j<n; j++)
        {
            sumarr[i][j] = arr[i][j];
        }
    }
    //start from the second bottom line of the triangle
    //this is to choose largest element in each row and
    //add to the current position of the array
    for(int i=n-2; i>=0; i--)
    {
        //this is to find the maximum element in the row below
        //and add to the current position according to dynamic programming
        for(int j=0; j<=i; j++)
        {
            //if the element below the current index is larger than
            //the element right below the current index, then add
            //the element below to the current index
            if(sumarr[i+1][j] > sumarr[i+1][j+1])
                sumarr[i][j] += sumarr[i+1][j];
            //otherwise, add the element right below to the current index
            else
                sumarr[i][j] += sumarr[i+1][j+1];
            //this is to add larger adjacent element from the row below
        }
    }
    cout << sumarr[0][0] << endl;
    int j=0;
    for (int i=0; i<n; i++)
    {
        //print elements which are used to form the max sum
        cout<<arr[i][j]<<" ";
        //compare elements in the same row to find the updated max number
        if (sumarr[i+1][j] < sumarr[i+1][j+1])
            j++;
    }
    cout << endl;
}
int main()
{
    string in;
    int count = 0;
    list<int> tri;
    while(1)
    {
        //get the input as a string per line
        getline(cin,in);
        count++; //count the size of the triangle
        //if only a new line is typed, then stop the triangle
        if(in.empty())
            break;

        auto it = in.begin();
        string input; //I will use a new string to save the integers
        //as substrings because the + operator can be used to append
        //new chars in the string so we can have a way to save integers
        //larger than 9
        //to see inputs with integers input
        while(it != in.end())
        {
            //to track the line character by character
            char k = *it;
            it++;
            //check whether the char found is a space or not
            if(k != ' ')
            {
                input = k; //put in the string
                //if the integer is larger than 9
                while((*it != ' ') && (it != in.end()))
                {
                    k = *it; //save the next char in the char variable
                    input += k; //append the substring to save integers with
                    //with the next char (next digit of the integer input)
                    it++;
                }
                //then,save the appended substring into the integer
                int x = stoi(input);
                //check for the integer interval
                if(x>=0 && x<=10000)
                {
                    //push into the STL list if the integer is valid
                    tri.push_back(x);
                }
                else
                {
                    cout << "Input invalid" << endl;
                    count--; //decrement the counter to ignore the line
                    //with invalid values
                }
            }
        }
    }
    //dynamically allocate the array
    int **arr;
    int n = count-1; //the counter will also count the new null line
    //so decrement the counter for the size of static array
    arr = new int*[n];
    for(int i=0; i<n; i++)
    {
        arr[i] = new int[n];
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            //the number of elements in each row must be equal
            //to the current position of that row.
            //so set the rest to zero in extra columns
            if(j>i)
                arr[i][j] = 0;
            else
            {
                //the frontmost element in the list is the first
                //element entered from input.
                arr[i][j] = tri.front();
                tri.pop_front();
            }
        }
    }
    maxSum(arr,n);
    for(int i=0; i<n; i++)
    {
        delete []arr[i];
    }
    delete []arr;
    //deallocate the array
    return 0;
}
