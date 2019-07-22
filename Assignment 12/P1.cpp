#include <iostream>
using namespace std;

//the board will have m*n boards(m=n) with h
//horses (h=n)
int m, n, h;
int count = 0; //used to count the total possible solutions

//Initialize the board with '_' in each index
void createBoard(char** board)
{
    for (int i = 0; i<m; i++)
    {
        for (int j = 0; j<n; j++)
        {
            board[i][j] = '_';
        }
    }
}

//print all characters in the board 2D array
void printBoard(char** board)
{
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << "  ";
        }
        cout << endl;
    }
}

//mark possible attacking positions of a horse
//located at position[i][j] on the board
void attack(int i, int j, char a, char** board)
{
    //check the surrounding (left,right,top,bottom)
    //of a horse is still on the board
    //and mark possible attack positions
    //range of rows and cols [0..n-1] (m=n)
    //if the horse moves in the next step
    //horses can move 2 steps horizontally & 1 step vertically
    //or 2 steps vertically and 1 step horizontally
    if ((i + 2) < m && (j - 1) >= 0)
        board[i + 2][j - 1] = a;

    if ((i - 2) >= 0 && (j - 1) >= 0)
        board[i - 2][j - 1] = a;

    if ((i + 2) < m && (j + 1) < n)
        board[i + 2][j + 1] = a;

    if ((i - 2) >= 0 && (j + 1) < n)
        board[i - 2][j + 1] = a;

    if ((i + 1) < m && (j + 2) < n)
        board[i + 1][j + 2] = a;

    if ((i - 1) >= 0 && (j + 2) < n)
        board[i - 1][j + 2] = a;

    if ((i + 1) < m && (j - 2) >= 0)
        board[i + 1][j - 2] = a;

    if ((i - 1) >= 0 && (j - 2) >= 0)
        board[i - 1][j - 2] = a;
}

//check whether the position passed is safe to place
//the horse
bool canPlace(int i, int j, char** board)
{
    if (board[i][j] == '_')
        return true;
    else
        return false;
}

//place the horse at given [i][j] position on the board
//while placing a new horse, we always create
//a new board in order to backtrack the original solution
//and find other possible solutions
void place(int i, int j, char h, char a,
           char** board, char** nboard)
{
    //copy all characters from the original board
    //to a new board
    for (int x = 0; x < m; x++)
    {
        for (int y = 0; y < n; y++)
        {
            nboard[x][y] = board[x][y];
        }
    }

    //place the new horse on the new board
    nboard[i][j] = h;

    //mark possible attacking positions on the new board
    attack(i, j, a, nboard);
}

//place n horses on the board such that they don't
//attack each other
void HorseProb(int h, int posi, int posj, char** board)
{
    //if all horses are placed,then all possible solutions
    //have finished. So,print and increment the counter
    //to count the last solution
    if (h == 0)
    {
        printBoard(board);
        count++;
    }
    else
    {
        //to check all positions on the board
        for (int i = posi; i < m; i++)
        {
            for (int j = posj; j < n; j++)
            {

                //check if it is possible to check the horse
                //at the given position
                //if yes,create a new board,and place the new
                //horse on the new board
                if (canPlace(i, j, board))
                {
                    char** nboard = new char*[m];
                    for (int x = 0; x < m; x++)
                    {
                        nboard[x] = new char[n];
                    }
                    place(i, j, 'H', 'A', board, nboard);

                    //call the function recursively to add
                    //remaining horses on the new board
                    HorseProb(h-1, i, j, nboard);

                    //deallocate dynamically allocated 2D array
                    //for the new board
                    for (int x = 0; x < m; x++)
                    {
                        delete[] nboard[x];
                    }
                    delete[] nboard;
                }
            }
            posj = 0;
            //after all possible columns in the first row is checked,
            //set the column position to zero again
        }
    }
}

int main()
{
    cin >> n;
    m = n;
    h = n;
    //to create a new board
    char** board = new char*[m];
    for (int i = 0; i < m; i++)
    {
        board[i] = new char[n];
    }
    //create an empty board
    createBoard(board);
    //place n horses that they don't attack each other
    //start from the top leftmost index on the board
    HorseProb(h, 0, 0, board);

    cout << "\n"  << "Total Possible Solutions: " << count << endl;
    for(int i=0; i<m; i++)
        delete []board[i];
    delete []board;
    return 0;
}
