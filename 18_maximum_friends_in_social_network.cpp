#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int V, E;
    cin >> V >> E;
    vector<int> deg(V, 0);
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u >= 0 && u < V && v >= 0 && v < V)
        {
            deg[u]++;
            deg[v]++;
        }
    }
    int best = 0;
    for (int i = 1; i < V; i++)
    {
        if (deg[i] > deg[best])
            best = i;
    }
    cout << best << " " << deg[best] << "\n";
    return 0;
}


// Time Complexity: O(V + E)
// Space Complexity: O(V)

// Example Input:
// 4 4
// 0 1
// 1 2
// 2 3
// 3 0
