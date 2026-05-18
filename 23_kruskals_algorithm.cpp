#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, w;
};

struct DSU
{
    vector<int> p, r;
    DSU(int n) : p(n), r(n, 0)
    {
        for (int i = 0; i < n; i++)
            p[i] = i;
    }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (r[a] < r[b])
            swap(a, b);
        p[b] = a;
        if (r[a] == r[b])
            r[a]++;
        return true;
    }
};

int main()
{
    int V, E;
    cin >> V >> E;
    vector<Edge> edges;
    edges.reserve(E);
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b)
         { return a.w < b.w; });

    DSU dsu(V);
    long long cost = 0;
    for (auto &e : edges)
    {
        if (e.u < 0 || e.u >= V || e.v < 0 || e.v >= V)
            continue;
        if (dsu.unite(e.u, e.v))
        {
            cost += e.w;
            cout << e.u << " " << e.v << " " << e.w << "\n";
        }
    }
    cout << cost << "\n";
    return 0;
}


// Time Complexity: O(E log E)
// Space Complexity: O(V)

// Example Input:
// 4 5
// 0 1 10
// 1 2 15
// 2 3 20
// 3 0 25
// 0 2 30
