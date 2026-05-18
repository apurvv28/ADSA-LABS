#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int V;
    cin >> V;
    vector<int> comments(V);
    for (int i = 0; i < V; i++)
        cin >> comments[i];

    int E;
    cin >> E;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
    }

    int mx = 0, mn = 0;
    for (int i = 1; i < V; i++)
    {
        if (comments[i] > comments[mx])
            mx = i;
        if (comments[i] < comments[mn])
            mn = i;
    }
    cout << mx << " " << comments[mx] << "\n";
    cout << mn << " " << comments[mn] << "\n";
    return 0;
}


// Time Complexity: O(N)
// Space Complexity: O(1)

// Example Input:
// 5
// 10 20 5 15 25
