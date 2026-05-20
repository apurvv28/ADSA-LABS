#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int u;
    int v;
    int weight;
};

int parent[100];

bool compare(Edge a, Edge b)
{
    return a.weight < b.weight;
}

int findParent(int node)
{
    if (parent[node] == node)
    {
        return node;
    }

    return findParent(parent[node]);
}

void unionSet(int a, int b)
{
    int parentA = findParent(a);

    int parentB = findParent(b);

    parent[parentB] = parentA;
}

void kruskal(int vertices, vector<Edge> &edges)
{
    sort(edges.begin(), edges.end(), compare);

    for (int i = 0; i < vertices; i++)
    {
        parent[i] = i;
    }

    int totalCost = 0;

    for (Edge e : edges)
    {
        int u = findParent(e.u);

        int v = findParent(e.v);

        if (u != v)
        {
            cout << e.u
                 << " - "
                 << e.v
                 << " = "
                 << e.weight
                 << endl;

            totalCost += e.weight;

            unionSet(u, v);
        }
    }

    cout << "Cost = " << totalCost;
}

int main()
{
    int vertices, edgesCount;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edgesCount;

    vector<Edge> edges(edgesCount);

    for (int i = 0; i < edgesCount; i++)
    {
        cout << "Enter edge " << (i+1) << " (u v weight): ";
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    kruskal(vertices, edges);
}

// Time Complexity: O(E log E)
// Space Complexity: O(V)

// Example Input:
// Enter number of vertices and edges: 4 5
// Enter edge 1 (u v weight): 0 1 10
// Enter edge 2 (u v weight): 1 2 15
// Enter edge 3 (u v weight): 2 3 20
// Enter edge 4 (u v weight): 3 0 25
// Enter edge 5 (u v weight): 0 2 30
