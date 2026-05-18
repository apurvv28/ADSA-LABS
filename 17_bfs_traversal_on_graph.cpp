#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> g(V);
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u >= 0 && u < V && v >= 0 && v < V)
        {
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    int s;
    cin >> s;
    vector<int> vis(V, 0);
    queue<int> q;
    if (s >= 0 && s < V)
    {
        vis[s] = 1;
        q.push(s);
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << ' ';
        for (int v : g[u])
            if (!vis[v])
            {
                vis[v] = 1;
                q.push(v);
            }
    }
    cout << "\n";
    return 0;
}


// Time Complexity: O(V + E)
// Space Complexity: O(V)

// Example Input:
// 4 4
// 0 1
// 1 2
// 2 3
// 3 0
// 0
