#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int V;
    cin >> V;
    const long long INF = (1LL << 60);
    vector<vector<long long>> d(V, vector<long long>(V, INF));
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            long long x;
            cin >> x;
            if (i == j)
                d[i][j] = 0;
            if (x != -1)
                d[i][j] = x;
        }
    }

    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (d[i][k] != INF && d[k][j] != INF && d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (d[i][j] == INF)
                cout << -1;
            else
                cout << d[i][j];
            cout << (j + 1 == V ? '\n' : ' ');
        }
    }
    return 0;
}


// Time Complexity: O(V^3)
// Space Complexity: O(V^2)

// Example Input:
// 4 5
// 0 1 10
// 1 2 15
// 2 3 20
// 3 0 25
// 0 2 30
