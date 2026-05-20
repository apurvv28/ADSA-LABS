#include <iostream>
#include <vector>
using namespace std;

int tsp(int city,
        int visited,
        vector<vector<int>> &cost,
        vector<vector<int>> &dp,
        int n)
{
    if (visited == (1 << n) - 1)
    {
        return cost[city][0];
    }

    if (dp[visited][city] != -1)
    {
        return dp[visited][city];
    }

    int answer = 999999;

    for (int next = 0; next < n; next++)
    {
        if ((visited & (1 << next)) == 0)
        {
            int newCost =
                cost[city][next] + tsp(next,
                                       visited | (1 << next),
                                       cost,
                                       dp,
                                       n);

            answer = min(answer,
                         newCost);
        }
    }

    return dp[visited][city] = answer;
}

int main()
{
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    vector<vector<int>> cost(
        n,
        vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Enter cost from city " << i << " to " << j << ": ";
            cin >> cost[i][j];
        }
    }

    vector<vector<int>> dp(
        1 << n,
        vector<int>(n, -1));

    cout << "Minimum Cost: ";
    cout << tsp(0, 1, cost, dp, n);
}

// Time Complexity: O(N!) or O(N^2 * 2^N)
// Space Complexity: O(N) or O(N * 2^N)

// Example Input:
// Enter number of cities: 4
// Enter cost from city 0 to 0: 0
// Enter cost from city 0 to 1: 10
// Enter cost from city 0 to 2: 15
// Enter cost from city 0 to 3: 20
// Enter cost from city 1 to 0: 10
// Enter cost from city 1 to 1: 0
// Enter cost from city 1 to 2: 35
// Enter cost from city 1 to 3: 25
// Enter cost from city 2 to 0: 15
// Enter cost from city 2 to 1: 35
// Enter cost from city 2 to 2: 0
// Enter cost from city 2 to 3: 30
// Enter cost from city 3 to 0: 20
// Enter cost from city 3 to 1: 25
// Enter cost from city 3 to 2: 30
// Enter cost from city 3 to 3: 0
