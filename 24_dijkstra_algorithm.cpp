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
    vector<long long> dist(V, INF);
    dist[s] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, s});

    while (!pq.empty())
    {
        pair<long long, int> top = pq.top();
        pq.pop();
        long long d = top.first;
        int u = top.second;
        if (d != dist[u])
            continue;
        for (auto e : g[u])
        {
            if (dist[u] + e.w < dist[e.to])
            {
                dist[e.to] = dist[u] + e.w;
                pq.push(make_pair(dist[e.to], e.to));
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (dist[i] == INF)
            cout << "INF";
        else
            cout << dist[i];
        cout << (i + 1 == V ? '\n' : ' ');
    }
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
// 0
