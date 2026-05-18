#include <iostream>
#include <vector>
using namespace std;

bool solve(int row, int n, vector<int> &queensInRow, vector<int> &colOccupied, vector<int> &mainDiagOccupied, vector<int> &antiDiagOccupied)
{
    if (row == n)
        return true;
    for (int col = 0; col < n; col++)
    {
        if (colOccupied[col] || mainDiagOccupied[row - col + n - 1] || antiDiagOccupied[row + col])
            continue;
        queensInRow[row] = col;
        colOccupied[col] = mainDiagOccupied[row - col + n - 1] = antiDiagOccupied[row + col] = 1;
        if (solve(row + 1, n, queensInRow, colOccupied, mainDiagOccupied, antiDiagOccupied))
            return true;
        colOccupied[col] = mainDiagOccupied[row - col + n - 1] = antiDiagOccupied[row + col] = 0;
    }
    return false;
}

int main()
{

    int n;
    cin >> n;
    vector<int> queensInRow(n, -1), colOccupied(n, 0), mainDiagOccupied(2 * n - 1, 0), antiDiagOccupied(2 * n - 1, 0);
    if (!solve(0, n, queensInRow, colOccupied, mainDiagOccupied, antiDiagOccupied))
    {
        cout << "NO SOLUTION\n";
        return 0;
    }
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
            cout << (queensInRow[row] == col ? 'Q' : '.');
        cout << "\n";
    }
    return 0;
}


// Time Complexity: O(N!)
// Space Complexity: O(N)

// Example Input:
// 4
