#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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
    queue<int> q;
    visited[start] = 1;
    q.push(start);
    cout << "\nBFS Traversal: ";
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << current << " ";
        for (int neighbor : graph[current])
        {
            if (visited[neighbor] == 0)
            {
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }
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
