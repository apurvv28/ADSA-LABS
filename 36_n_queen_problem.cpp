#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<string>& board,
            int row,
            int col,
            int n)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }

    int i = row;
    int j = col;

    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }

        i--;
        j--;
    }

    i = row;
    j = col;

    while (i >= 0 && j < n)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }

        i--;
        j++;
    }

    return true;
}

bool solve(vector<string>& board,
           int row,
           int n)
{
    if (row == n)
    {
        return true;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board,
                   row,
                   col,
                   n))
        {
            board[row][col] = 'Q';

            if (solve(board,
                      row + 1,
                      n))
            {
                return true;
            }

            board[row][col] = '.';
        }
    }

    return false;
}

int main()
{
    int n;
    cout << "Enter board size (N): ";
    cin >> n;

    vector<string> board(
        n,
        string(n, '.'));

    cout << "\nN-Queens Solution:" << endl;
    if (solve(board, 0, n))
    {
        for (int i = 0; i < n; i++)
        {
            cout << board[i]
                 << endl;
        }
    }

    else
    {
        cout << "No Solution";
    }
}


// Time Complexity: O(N!)
// Space Complexity: O(N)

// Example Input:
// Enter board size (N): 4
