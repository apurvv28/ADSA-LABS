#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<vector<long long>> cost(n, vector<long long>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    const long long INF = (1LL << 60);
    int N = 1 << n;
    vector<vector<long long>> dp(N, vector<long long>(n, INF));
    dp[1][0] = 0;

    for (int mask = 1; mask < N; mask++)
    {
        for (int u = 0; u < n; u++)
        {
            if (!(mask & (1 << u)))
                continue;
            long long cur = dp[mask][u];
            if (cur == INF)
                continue;
            for (int v = 0; v < n; v++)
            {
                if (mask & (1 << v))
                    continue;
                dp[mask | (1 << v)][v] = min(dp[mask | (1 << v)][v], cur + cost[u][v]);
            }
        }
    }

    long long ans = INF;
    int full = N - 1;
    for (int u = 0; u < n; u++)
    {
        if (dp[full][u] != INF)
            ans = min(ans, dp[full][u] + cost[u][0]);
    }
    cout << ans << "\n";
    return 0;
}


// Time Complexity: O(N!) or O(N^2 * 2^N)
// Space Complexity: O(N) or O(N * 2^N)

// Example Input:
// 4 6
// 0 1 10
// 1 2 15
// 2 3 20
// 3 0 25
// 0 2 30
// 1 3 35
