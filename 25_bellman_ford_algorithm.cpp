#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
    int u, v;
    long long w;
};

int main()
{
    int V, E;
    cin >> V >> E;
    vector<Edge> edges(E);
    for (int i = 0; i < E; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    int s;
    cin >> s;
    if (s < 0 || s >= V)
        s = 0;

    const long long INF = (1LL << 60);
    vector<long long> dist(V, INF);
    dist[s] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        bool any = false;
        for (auto &e : edges)
        {
            if (e.u < 0 || e.u >= V || e.v < 0 || e.v >= V)
                continue;
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v])
            {
                dist[e.v] = dist[e.u] + e.w;
                any = true;
            }
        }
        if (!any)
            break;
    }

    for (auto &e : edges)
    {
        if (e.u < 0 || e.u >= V || e.v < 0 || e.v >= V)
            continue;
        if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v])
        {
            cout << "NEGATIVE CYCLE\n";
            return 0;
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


// Time Complexity: O(V * E)
// Space Complexity: O(V)

// Example Input:
// 4 5
// 0 1 10
// 1 2 15
// 2 3 20
// 3 0 25
// 0 2 30
// 0
