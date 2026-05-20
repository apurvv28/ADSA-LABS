#include <iostream>
#include <vector>
using namespace std;

int findMaxDegreeNode(vector<vector<int>>& adjacencyList, int vertices)
{
    int maxDegree = 0;
    int maxNode = 0;
    for (int i = 0; i < vertices; i++)
    {
        if (adjacencyList[i].size() > maxDegree)
        {
            maxDegree = adjacencyList[i].size();
            maxNode = i;
        }
    }
    return maxNode;
}
void displayFriends(vector<vector<int>>& adjacencyList, int user)
{
    cout << "\nFriends of User " << user << ": ";
    if (adjacencyList[user].empty())
    {
        cout << "No friends";
    }
    else
    {
        for (int friend_id : adjacencyList[user])
        {
            cout << friend_id << " ";
        }
    }
    cout << endl;
}
void displayAllDegrees(vector<vector<int>>& adjacencyList, int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        cout << "User " << i << ": " << adjacencyList[i].size() << " friends" << endl;
    }
}

int main()
{
    int vertices, edges;
    cout << "Enter number of vertices (users) and edges (friendships): ";
    cin >> vertices >> edges;
    vector<vector<int>> adjacencyList(vertices);

    cout << "\nEnter the friendships (edges):" << endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cout << "Enter friendship " << (i+1) << " (user1 user2): ";
        cin >> u >> v;
        if (u < 0 || u >= vertices || v < 0 || v >= vertices)
        {
            cout << "Invalid user IDs. Please enter values between 0 and " << (vertices - 1) << endl;
            i--;
            continue;
        }
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }
    int maxFriendUser = findMaxDegreeNode(adjacencyList, vertices);
    displayAllDegrees(adjacencyList, vertices);
    cout << "User with maximum friends: User " << maxFriendUser << endl;
    cout << "Number of friends: " << adjacencyList[maxFriendUser].size() << endl;
    displayFriends(adjacencyList, maxFriendUser);

    return 0;
}


// Time Complexity: O(V + E)
// Space Complexity: O(V + E) for adjacency list representation
//
// Social Network Representation:
// - Uses Adjacency List to represent an undirected graph
// - Each vertex represents a user
// - Each edge represents a friendship (bidirectional)
// - Finds the user with maximum degree (most friends)
//
// Applications:
// - Finding influential users in social networks
// - Recommendation systems
// - Network analysis and statistics

// Example Input:
// Enter number of vertices (users) and edges (friendships): 5 6
// Enter the friendships (edges):
// Enter friendship 1 (user1 user2): 0 1
// Enter friendship 2 (user1 user2): 0 2
// Enter friendship 3 (user1 user2): 0 3
// Enter friendship 4 (user1 user2): 1 2
// Enter friendship 5 (user1 user2): 1 3
// Enter friendship 6 (user1 user2): 2 4
