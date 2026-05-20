#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
    int u;
    int v;
    int weight;
};

void bellmanFord(int vertices,
                 vector<Edge> &edges,
                 int start)
{
    vector<int> distance(vertices, 999999);

    distance[start] = 0;

    for (int i = 0; i < vertices - 1; i++)
    {
        for (Edge e : edges)
        {
            if (distance[e.u] != 999999 &&
                distance[e.u] + e.weight < distance[e.v])
            {
                distance[e.v] =
                    distance[e.u] + e.weight;
            }
        }
    }

    for (Edge e : edges)
    {
        if (distance[e.u] != 999999 &&
            distance[e.u] + e.weight < distance[e.v])
        {
            cout << "Negative Cycle Found";

            return;
        }
    }

    for (int i = 0; i < vertices; i++)
    {
        cout << "Distance of "
             << i
             << " = "
             << distance[i]
             << endl;
    }
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

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    bellmanFord(vertices, edges, start);
}

// Time Complexity: O(V * E)
// Space Complexity: O(V)

// Example Input:
// Enter number of vertices and edges: 4 5
// Enter edge 1 (u v weight): 0 1 10
// Enter edge 2 (u v weight): 1 2 15
// Enter edge 3 (u v weight): 2 3 20
// Enter edge 4 (u v weight): 3 0 25
// Enter edge 5 (u v weight): 0 2 30
// Enter starting vertex: 0
