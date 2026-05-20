#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<vector<int>> &graph, vector<int> &visited)
{
    visited[node] = 1;
    cout << node << " ";
    for (int neighbor : graph[node])
    {
        if (visited[neighbor] == 0)
        {
            DFS(neighbor, graph, visited);
        }
    }
}

int main()
{
    int vertices, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;
    vector<vector<int>> graph(vertices);
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cout << "Enter edge " << (i+1) << " (u v): ";
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int start;
    cout << "Enter starting vertex: ";
    cin >> start;
    vector<int> visited(vertices, 0);
    cout << "\nDFS Traversal: ";
    DFS(start, graph, visited);
    return 0;
}


// Time Complexity: O(V + E)
// Space Complexity: O(V)

// Example Input:
// Enter number of vertices and edges: 4 4
// Enter edge 1 (u v): 0 1
// Enter edge 2 (u v): 1 2
// Enter edge 3 (u v): 2 3
// Enter edge 4 (u v): 3 0
// Enter starting vertex: 0
