#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge
{
    int node;
    int weight;
};

void dijkstra(int vertices,
              vector<vector<Edge>> &graph,
              int start)
{
    vector<int> distance(vertices, 999999);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>>
        pq;

    distance[start] = 0;

    pq.push({0, start});

    while (!pq.empty())
    {
        int currentDistance = pq.top().first;

        int currentNode = pq.top().second;

        pq.pop();

        if (currentDistance > distance[currentNode])
        {
            continue;
        }

        for (Edge e : graph[currentNode])
        {
            if (distance[currentNode] + e.weight < distance[e.node])
            {
                distance[e.node] =
                    distance[currentNode] + e.weight;

                pq.push(
                    {distance[e.node], e.node});
            }
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

    dijkstra(vertices, graph, start);
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
