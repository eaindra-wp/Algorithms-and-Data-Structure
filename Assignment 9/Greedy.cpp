#include <iostream>
#include <algorithm>
using namespace std;
class activity
{
    public:
        int start, finish;
};
//compare whether former activity's finish time is earlier
//than the latter one
bool finishCompare(activity s1,activity s2)
{
    return (s1.finish<s2.finish);
}
//to print the activity with the latest starting time
void greedySelector(struct activity* arr,int n)
{
    //sort activities according to the finishing time
    //the sort function from C++ library has time complexity
    //of O(n log n),so we can safely use it for greedy algorithm.
    sort(arr, arr+n, finishCompare);
    cout << "The activity with latest starting time is: ";

    int i=n-1; //The last activity has the latest starting time after sorting
    activity result; //create new activity to store the result
    result.start = arr[i].start;
    result.finish = arr[i].finish;
    //assume that last activity has the most suitable latest starting time

    //check the rest activities in the list in the reverse order
    for (int j=n-2; j>=0; j--)
    {
        //if the current activity's start time is greater than or
        //equal to the previously selected finish time, then assume that
        //current activity has the later suitable start time
        if (arr[j].start >= arr[i].finish)
        {
            result.start = arr[j].start;
            result.finish = arr[j].finish;
            i=j;
            //set the current index as the previous for next activities
        }
    }
    //print the activity with the latest start time
    cout << "(" << result.start << "," << result.finish << ")." << endl;
}
//For the testcase
int main()
{
    activity arr[]= {{1,8},{12,20},{6,10},{5,7},{15,18},{10,15}};
    int n= sizeof(arr)/sizeof(arr[0]);
    //for the size of the array
    greedySelector(arr,n);
    return 0;
}
