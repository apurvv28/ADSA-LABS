#include <iostream>
using namespace std;
#define MAX 10
int board[MAX][MAX];
int n;
bool isSafe(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }
    for (int i = row, j = col;
         i >= 0 && j >= 0;
         i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    for (int i = row, j = col;
         i >= 0 && j < n;
         i--, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}
bool solveNQueens(int row)
{
    if (row == n)
    {
        return true;
    }
    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col))
        {
            board[row][col] = 1;
            if (solveNQueens(row + 1))
            {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}
void printBoard()
{
    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
            {
                cout << "Q ";
            }
            else
            {
                cout << ". ";
            }
        }
        cout << endl;
    }
}
int main()
{
    cout << "Enter value of N: ";
    cin >> n;
    if (solveNQueens(0))
    {
        printBoard();
    }
    else
    {
        cout << "No Solution Exists";
    }
    return 0;
}

/*
Example Input:
4

Output:
. Q . .
. . . Q
Q . . .
. . Q .

Time Complexity:
O(N!)

Space Complexity:
O(N^2)
*/