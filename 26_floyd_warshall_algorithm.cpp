#include <iostream>
#include <vector>
using namespace std;

void floydWarshall(vector<vector<int>> &graph,
                   int vertices)
{
    for (int k = 0; k < vertices; k++)
    {
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                if (graph[i][k] + graph[k][j] < graph[i][j])
                {
                    graph[i][j] =
                        graph[i][k] + graph[k][j];
                }
            }
        }
    }

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (graph[i][j] == 999999)
            {
                cout << "INF ";
            }

            else
            {
                cout << graph[i][j] << " ";
            }
        }

        cout << endl;
    }
}

int main()
{
    int vertices;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    vector<vector<int>> graph(
        vertices,
        vector<int>(vertices));

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cout << "Enter distance from " << i << " to " << j << ": ";
            cin >> graph[i][j];

            if (graph[i][j] == -1)
            {
                graph[i][j] = 999999;
            }
        }
    }

    floydWarshall(graph, vertices);
}

// Time Complexity: O(V^3)
// Space Complexity: O(V^2)

// Example Input:
// Enter number of vertices: 4
// Enter distance from 0 to 0: 0
// Enter distance from 0 to 1: 10
// Enter distance from 0 to 2: 999999
// Enter distance from 0 to 3: 999999
// Enter distance from 1 to 0: 999999
// Enter distance from 1 to 1: 0
// Enter distance from 1 to 2: 5
// Enter distance from 1 to 3: 999999
// Enter distance from 2 to 0: 999999
// Enter distance from 2 to 1: 999999
// Enter distance from 2 to 2: 0
// Enter distance from 2 to 3: 8
// Enter distance from 3 to 0: 999999
// Enter distance from 3 to 1: 999999
// Enter distance from 3 to 2: 999999
// Enter distance from 3 to 3: 0
