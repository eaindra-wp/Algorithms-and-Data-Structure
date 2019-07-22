#include <iostream>
#include <list>
#include <algorithm>
#define MIN(a,b) ((a)<(b) ? (a):(b))
#define MAX(a,b) ((a)>(b) ? (a):(b))
#define INF_WEIGHT 10000
using namespace std;
int main()
{
    int i,j,k;
    int c;
    int t;
    int a;
    int n;
    //create 3 separate arrays for gases and cylinder to
    //ask for input and save
    int Ox[1000];
    int Ni[1000];
    int wt[1000];
    int dp[1000][22][80];//create a 3D table to use for dynamic programming
    //to save number of cylinders,volume of oxygen and nitrogen
    //The array is statically allocated as 1000 stacks of 22x80 2D arrays
    //I added an extra row and column capacity for simplicity with comparison
    //if max limit of
    cin >> c;
    //read the number of combinations to be tested
    for (int z=0; z<c; z++)
    {
        //add input for O2 and N2 limit to bring
        while(1)
        {
            cin >> t >> a;
            if(t>=1 && t<=21 && a>=1 && a<=79)
                break;
            else
                cout << "Size invalid!Please try again!" << endl;
        }
        while(1)
        {
            cin >> n; //ask the number of available options to be saved
            if(n>=1 && n<=1000)
                break;
            else
                cout << "Size invalid!Please try again!" << endl;
        }
    }
    //O2, N2 volumes and size of cylinders are pushed into the 3D array
    for (int i=0; i<n; i++)
    {
        while(1)
        {
            cin >> Ox[i] >> Ni[i] >> wt[i];
            //check for validity of volume of gases and weight of cylinder
            if(Ox[i]>=1 && Ox[i]<=21 && Ni[i]>=1 && Ni[i]<=79
                    && wt[i]>=1 && wt[i]<=1000)
            {
                break;
            }
            else
                cout << "Sizes invalid!Please add again!" << endl;
        }
    }

    //3D array is used for dynamic programming for this problem.
    //So,we consider this 3D array as a stack of cylinders containing
    //oxygen and nitrogen 2D arrays.
    for (i=0; i<n; i++)
        for (j=0; j<=t; j++)
            for (k=0; k<=a; k++)
            {
                dp[i][j][k] = INF_WEIGHT;//initialize to a very large value
                if (j == 0 && k == 0)
                    dp[i][j][k] = 0;
                //initialize the very index at first row,first column
                //of each 2D O2&N2 array to zero
            }

    //initialization of the weight
    for (j=0; j<=t; j++)
    {
        for (k=0; k<=a; k++)
        {
            //if the indexes of row and column are less than or equal to
            //the volume input in the first index of O2 and N2 input arrays
            if (j <= Ox[0] && k <= Ni[0])
                dp[0][j][k] = wt[0];
            //fill all rows and columns of the very first stack
            //with the first weight input to be used to compare
            //with the rest weights
        }
    }
    //The Algorithm
    for (i=1; i<n; i++)
    {
        for (j=0; j<=t; j++)
        {
            for (k=0; k<=a; k++)
            {
                dp[i][j][k] = dp[i-1][j][k];
                //copy weights from the adjacent above 2D array to the
                //current 2D array to save the sum weight in the
                //lowest stack of 3D array

                if (j <= Ox[i] && k <= Ni[i])
                    dp[i][j][k] = MIN(dp[i][j][k], wt[i]);
                //if the index of row and column in the 3D array are <= the
                //volumes in the stack index of O2 and N2 input array,then
                //assign the weight at current index in 3D array with
                //the smaller value among wt at current index and wt at current
                //stack index in the input wt array

                else
                    dp[i][j][k] = MIN(dp[i][j][k],
                            wt[i]+dp[i-1][MAX(0,j-Ox[i])][MAX(0,k-Ni[i])]);
                //otherwise, choose the smaller weight among the current value
                //and (the weight input at the current index of the input weight
                //array+the value of the valid max index value for gases row
                //and col of the previous stack. If the difference between
                //row and column from the current iterator count is larger than
                //the O2 or N2 value saved in the current stack
                //count iterator input array is positive,then choose that value
                //to get the wt in the index. If negative,get from index zero.)
                //Indexes which are not filled with input valid values or
                //updated results are set to a very large value, so we choose
                //with MIN macro.
            }
        }
    }
    int o2=t, n2=a;
    list<int> result;
    //create a list to save which options are used
    i=n-1;
    while((i>=0) && (o2>0 || n2>0))
    {
        if(i == 0)
        {
            result.push_front(i+1);
            break;
        }

        //if the element at the current index at the remaining required gas
        //limits is different from the element at the upper index
        //in the same input gases limit
         if(dp[i][o2][n2] != dp[i-1][o2][n2])
        {
            //the gases from that option is filled to input request
            //so deduct from original input
            o2 -= Ox[i];
            n2 -= Ni[i];
            //and add set to zero if the amount of gas required is filled up
            //and stop tracking as we won't need any more gas
            o2 = MAX(o2,0);
            n2 = MAX(n2,0);
            result.push_front(i+1);
            //push that used option index to the result array
            i--;
        }
        else
        {
            i--;
        }
    }
    //print the chosen total sum of cylinder weight
    //the largest weight will be saved very last index of array stack
    cout << dp[n-1][t][a] << endl;
    //print the options chosen separated by space
    for(auto z: result)
    {
        cout << z << " ";
    }
    cout << endl;
    return 0;
}

