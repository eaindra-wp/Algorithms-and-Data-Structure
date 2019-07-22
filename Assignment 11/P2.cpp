#include <bits/stdc++.h>
using namespace std;
const int INF = (1 << 20);

int find_meetup_city(const vector<vector<int>>& adj,int p,int q)
{
    int n = adj.size(); //number of cities in the graph
    int dp[n][n]; //create a new array to calculate minimum distances

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            //set the distance value in diagonal indexes to zero
            //as the distance from one city to the same city is zero.
            if(i == j)
                dp[i][j] = 0;

            //if there is already an edge time input,then the edge time
            //taken will be the same with the input
            else if(adj[i][j] != -1)
                dp[i][j] = adj[i][j];

            //if there is no input edge yet(still with initialized value),
            //then the distance would be INF.
            else
                dp[i][j] = INF;
        }
    }

    //Floyd-Warshall algorithm to find the shortest path
    //the time complexity is O(n^3).
    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                //if vertex k is the intermediate vertex for the shortest path
                //from i to j, then update the result with the addition result
                //between path i&k and path k&j
                if (dp[i][j] > dp[i][k] + dp[k][j])
                    dp[i][j] = dp[i][k] + dp[k][j];
            }
        }
    }
    //to find the optimal meeting point
    int result = INF;
    int city;
    //this will return the index of the meeting point city input
    for(int i=0; i<n; i++)
    {
        //the point is to minimize the maximum time spent for both people in
        //different cities
        //if the current total time spent is larger than maximum time spent
        //among two people, then update with the time spent with the city
        //larger time spent among two people.
        if(result > max(dp[p][i],dp[q][i]))
        {
            result = max(dp[p][i],dp[q][i]);
            city = i;
            //save the current index as the index of the target city
        }
    }
    //the index of cities will be started from zero.
    return city;
    //return the index of the target city
}
int main()
{
    int n,m;
    cin >> n >> m;
    //n is for the number of cities available
    //m is the number of possible paths to be accepted as input
    vector<vector<int>> adj(n,vector<int>(n,-1));
    //create a nested vector STL to save city and time taken inputs
    //initialize with -1 for all indexes in the STL
    while(m--)
    {
        int from, to, t;
        cin >> from >> to >> t;
        adj[from][to] = t;
        adj[to][from] = t;
        //fill in the city nodes and time taken between them into
        //the nested STL
    }
    int p,q;
    cin >> p >> q;
    //input for your own city and friend's city
    cout << "Meet at city " << find_meetup_city(adj, p, q) << endl;
    //print the result of target city
    return 0;
}
