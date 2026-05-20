#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge
{
    int node;
    int weight;
};

void prims(int vertices, vector<vector<Edge>> &graph, int start)
{
    vector<int> visited(vertices, 0);

    vector<int> key(vertices, 999999);

    vector<int> parent(vertices, -1);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>>
        pq;

    key[start] = 0;

    pq.push({0, start});

    while (!pq.empty())
    {
        int current = pq.top().second;
        pq.pop();

        if (visited[current])
            continue;

        visited[current] = 1;

        for (Edge e : graph[current])
        {
            if (!visited[e.node] &&
                e.weight < key[e.node])
            {
                key[e.node] = e.weight;

                parent[e.node] = current;

                pq.push({key[e.node], e.node});
            }
        }
    }

    int totalCost = 0;

    for (int i = 0; i < vertices; i++)
    {
        totalCost += key[i];
    }

    cout << "Cost = " << totalCost << endl;

    for (int i = 0; i < vertices; i++)
    {
        if (parent[i] != -1)
        {
            cout << parent[i]
                 << " - "
                 << i
                 << " = "
                 << key[i]
                 << endl;
        }
    }
}

int main()
{
    int vertices, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    vector<vector<Edge>> graph(vertices);

    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cout << "Enter edge " << (i+1) << " (u v weight): ";
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    prims(vertices, graph, start);
}

// Time Complexity: O(E log V)
// Space Complexity: O(V)

// Example Input:
// Enter number of vertices and edges: 4 5
// Enter edge 1 (u v weight): 0 1 10
// Enter edge 2 (u v weight): 1 2 15
// Enter edge 3 (u v weight): 2 3 20
// Enter edge 4 (u v weight): 3 0 25
// Enter edge 5 (u v weight): 0 2 30
// Enter starting vertex: 0
