#include <bits/stdc++.h>
using namespace std;

class PuzzleBoard
{
private:
    vector<set<int>> edges; //to save the number of edges in the graph
    vector<vector<int>> fields; //to save the number of puzzles in the board
    int nodesCount; //number of nodes on the board (n^2)
    int boardSize; //the size of board
    int curX, curY;

    //to get the node's position in the board
    int getNodePos(int i, int j)
    {
        return (i*boardSize + j);
    }
    //check whether i and j coordinates are out of boundary of the board
    bool insideBoard(int i, int j)
    {
        if (i<0 || i>=boardSize || j<0 || j>=boardSize)
            return false;
        else
            return true;
    }

public:
    //constructor to create the graph
    PuzzleBoard(int boardSize, int** fields)
    {
        //if fields parameter is null,then initialize with random values between
        //1 and boardSize-1
        if(fields == NULL)
        {
            srand(time(NULL)); //to generate random local time
            fields = new int*[boardSize];
            if(fields == NULL)
            {
                cerr << "Allocation error" << endl;
                exit(1);
            }
            for(int i = 0; i<boardSize; i++)
            {
                fields[i] = new int[boardSize];
                if(fields[i] == NULL)
                {
                    cerr << "Allocation error" << endl;
                    exit(1);
                }
                for(int j = 0; j<boardSize; j++)
                {
                    fields[i][j] = rand()% (boardSize-1) + 1;
                    //initialize with random values in the fields of the board
                }
            }
        }

        this->boardSize = boardSize;
        this->nodesCount = boardSize*boardSize;
        //resize the set vector with given nodescount parameter
        edges.resize(nodesCount, set<int>());

        //check possible connections among each field, and save as edges
        //for instance,if the player is on the field with 3,then he/she
        //will be able to move 3 steps up/down/left/right
        //so this step checks whether the next steps in different directions
        //are possible and then save in the edge vector if movement is possible.
        //connect the nodes with each other
        for(int i=0; i<boardSize; i++)
        {
            for(int j=0; j<boardSize; j++)
            {
                int cur = getNodePos(i,j);
                int next;
                //check downward step possibility and save as an edge to move
                if(insideBoard(i+fields[i][j],j))
                {
                    next = getNodePos(i+fields[i][j],j);
                    this->edges[cur].insert(next);
                }
                //check upward step possibility and save as an edge to move
                if(insideBoard(i-fields[i][j],j))
                {
                    next = getNodePos(i - fields[i][j], j);
                    this->edges[cur].insert(next);
                }
                //check right step possibility and save as an edge to move
                if(insideBoard(i,j+fields[i][j]))
                {
                    next = getNodePos(i, j+fields[i][j]);
                    this->edges[cur].insert(next);
                }
                //check left step possibility and save as an edge to move
                if(insideBoard(i,j-fields[i][j]))
                {
                    next = getNodePos(i,j-fields[i][j]);
                    this->edges[cur].insert(next);
                }
            }
        }
        this->fields.resize(boardSize,vector<int>(boardSize));
        //copy to the whole vector parameter to the class's vector property
        for(int i=0; i<boardSize; i++)
        {
            for(int j=0; j<boardSize; j++)
            {
                this->fields[i][j] = fields[i][j];
            }
        }
        //to begin from the upper leftmost field of the board
        this->curX = this->curY = 0;
    }

    //makes the move (if valid), direction is 0 for up, 1
    //for right, 2 for down, 3 for left. Returns true if the move was
    //valid, false otherwise.
    bool makeMove(int direction)
    {
        int x, y, cur, next;
        set<int>::iterator it;
        switch(direction)
        {
        case 0:
            //move upward
            x = curX-fields[curX][curY];
            y = curY;
            //to return whether the movement is valid
            //if the current position is not on the board anymore, movement
            //is impossible.
            if(!insideBoard(x,y))
            {
                return false;
            }
            cur = getNodePos(curX, curY);
            next = getNodePos(x,y);
            it = edges[cur].find(next);
            //if there is no field connected with the current field,movement
            //is impossible
            if(it == edges[cur].end())
            {
                return false;
            }
            curX = x;
            curY = y;
            //update the X axis and Y axis position on the board
            break;

        case 1:
            //move right
            x = curX;
            y = curY+fields[curX][curY];
            //to return whether the movement is valid
            //if the current position is not on the board anymore, movement
            //is impossible.
            if(!insideBoard(x,y))
            {
                return false;
            }
            cur = getNodePos(curX, curY);
            next = getNodePos(x, y);
            it = edges[cur].find(next);
            //if there is no field connected with the current field,movement
            //is impossible
            if(it == edges[cur].end())
            {
                return false;
            }
            curX = x;
            curY = y;
            //update the X axis and Y axis position on the board
            break;

        case 2:
            //move downwards
            x = curX+fields[curX][curY];
            y = curY;
            if(!insideBoard(x,y))
            {
                return false;
            }
            cur = getNodePos(curX, curY);
            next = getNodePos(x,y);
            it = edges[cur].find(next);
            if(it == edges[cur].end())
            {
                return false;
            }
            curX = x;
            curY = y;
            //update the X axis and Y axis position on the board
            break;

        case 3:
            //move left
            x = curX;
            y = curY - fields[curX][curY];
            if(!insideBoard(x,y))
            {
                return false;
            }
            cur = getNodePos(curX, curY);
            next = getNodePos(x,y);
            it = edges[cur].find(next);
            if(it == edges[cur].end())
            {
                return false;
            }
            curX = x;
            curY = y;
            //update the X axis and Y axis position on the board
            break;
        }
        return true;
    }
    //return false if game is not over yet,true if puzzle was solved
    bool getResult()
    {
        if(curX == boardSize-1 && curY == boardSize-1)
            return true;
        else
            return false;
    }
    //overload the output operator
    friend ostream& operator<<(ostream &os, const PuzzleBoard& p)
    {
        for(int i=0; i < p.boardSize; i++)
        {
            for(int j = 0; j < p.boardSize; j++)
            {
                os << p.fields[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }

    //return the minimum number of moves needed to solve the puzzle,
    //and -1 if it is not solvable.
    int solve()
    {
        //Naive approach: start with the very first field and
        //call other possible fields recursively

        //create an array with size n*n to record the number of possible edges
        //and initialize to -10
        int arr[this->nodesCount];
        for(int i=0; i<this->nodesCount; i++)
            arr[i] = -10;


        queue<int> q;
        arr[0] = 0; //change to the starting position to zero
        q.push(0);
        while(!q.empty())
        {
            int cur = q.front();//to check and remove the visited edge
            q.pop();
            for(auto next:edges[cur])
            {
                //if the possible edge path is unvisited,update the array
                if(arr[next] == -10)
                {
                    arr[next]=arr[cur]+1;
                    q.push(next);
                    //update the queue with updated index to continue checking
                    //possible edge paths
                }
            }
        }
        if(arr[this->nodesCount-1] == -10)
        {
            cerr << "The maze is not solvable." << endl;
        }
        return arr[this->nodesCount-1];
        //the minimum required movement will be saved in the last index
        //of the array
    }
};

int main()
{
    int n = 3;
    cin >> n;
    PuzzleBoard pb(n,NULL);
    cout << pb;
    cout << pb.solve() << endl;
    return 0;
}
