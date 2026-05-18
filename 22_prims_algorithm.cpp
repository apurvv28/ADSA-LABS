#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge
{
    int to;
    int w;
};

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<Edge>> g(V);
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (u >= 0 && u < V && v >= 0 && v < V)
        {
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
    }
    int s;
    cin >> s;
    if (s < 0 || s >= V)
        s = 0;

    const long long INF = (1LL << 60);
    vector<long long> key(V, INF);
    vector<int> parent(V, -1), used(V, 0);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    key[s] = 0;
    pq.push({0, s});
    while (!pq.empty())
    {
        pair<long long, int> top = pq.top();
        pq.pop();
        long long d = top.first;
        int u = top.second;
        if (used[u])
            continue;
        used[u] = 1;
        for (auto e : g[u])
        {
            if (!used[e.to] && e.w < key[e.to])
            {
                key[e.to] = e.w;
                parent[e.to] = u;
                pq.push(make_pair(key[e.to], e.to));
            }
        }
    }

    long long cost = 0;
    for (int i = 0; i < V; i++)
        if (key[i] != INF)
            cost += key[i];
    cout << cost << "\n";
    for (int v = 0; v < V; v++)
        if (parent[v] != -1)
            cout << parent[v] << " " << v << " " << key[v] << "\n";
    return 0;
}


// Time Complexity: O(E log V)
// Space Complexity: O(V)

// Example Input:
// 4 5
// 0 1 10
// 1 2 15
// 2 3 20
// 3 0 25
// 0 2 30
