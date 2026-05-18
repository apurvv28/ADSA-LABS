#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, vector<vector<int>> &g, vector<int> &vis)
{
    vis[u] = 1;
    cout << u << ' ';
    for (int v : g[u])
        if (!vis[v])
            dfs(v, g, vis);
}

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
    if (s >= 0 && s < V)
        dfs(s, g, vis);
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
