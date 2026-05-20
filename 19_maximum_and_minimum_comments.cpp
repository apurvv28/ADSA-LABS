#include <iostream>
#include <vector>
using namespace std;
struct User {
    int userId;
    int comments;
};
int findMaxCommentUser(vector<User>& users)
{
    int maxIndex = 0;
    for (int i = 1; i < users.size(); i++)
    {
        if (users[i].comments > users[maxIndex].comments)
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}
int findMinCommentUser(vector<User>& users)
{
    int minIndex = 0;
    for (int i = 1; i < users.size(); i++)
    {
        if (users[i].comments < users[minIndex].comments)
        {
            minIndex = i;
        }
    }
    return minIndex;
}
void displayUserFriends(vector<vector<int>>& adjacencyList, int userId)
{
    cout << "Friends of User " << userId << ": ";
    if (adjacencyList[userId].empty())
    {
        cout << "No friends";
    }
    else
    {
        for (int friend_id : adjacencyList[userId])
        {
            cout << friend_id << " ";
        }
    }
    cout << endl;
}

int main()
{
    int vertices, edges;
    cout << "Enter number of users and friendships: ";
    cin >> vertices >> edges;
    vector<User> users(vertices);
    cout << "\nEnter user information:" << endl;
    for (int i = 0; i < vertices; i++)
    {
        users[i].userId = i;
        cout << "Enter number of comments for User " << i << ": ";
        cin >> users[i].comments;
    }
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

    int maxCommentIndex = findMaxCommentUser(users);
    int minCommentIndex = findMinCommentUser(users);
    cout << "\nUser with MAXIMUM Comments:" << endl;
    cout << "User ID: " << users[maxCommentIndex].userId << endl;
    cout << "Comments: " << users[maxCommentIndex].comments << endl;
    displayUserFriends(adjacencyList, maxCommentIndex);

    cout << "\nUser with MINIMUM Comments:" << endl;
    cout << "User ID: " << users[minCommentIndex].userId << endl;
    cout << "Comments: " << users[minCommentIndex].comments << endl;
    displayUserFriends(adjacencyList, minCommentIndex);
    for (int i = 0; i < vertices; i++)
    {
        cout << "User " << users[i].userId << ": " << users[i].comments << " comments" << endl;
    }
    return 0;
}


// Time Complexity: O(V + E)
// Space Complexity: O(V + E) for adjacency list and user data storage
//
// Social Network Graph for Comment Analysis:
// - Uses Adjacency List to represent an undirected graph
// - Each vertex represents a user
// - Each edge represents a friendship (bidirectional)
// - Stores comment count for each user
// - Identifies users with maximum and minimum comments
//
// Applications:
// - Analyze user engagement in social networks
// - Identify influencers (max comments) and quiet users (min comments)
// - Community analysis based on comment activity

// Example Input:
// Enter number of users and friendships: 5 6
// Enter user information:
// Enter number of comments for User 0: 150
// Enter number of comments for User 1: 80
// Enter number of comments for User 2: 120
// Enter number of comments for User 3: 90
// Enter number of comments for User 4: 30
// Enter the friendships (edges):
// Enter friendship 1 (user1 user2): 0 1
// Enter friendship 2 (user1 user2): 0 2
// Enter friendship 3 (user1 user2): 0 3
// Enter friendship 4 (user1 user2): 1 2
// Enter friendship 5 (user1 user2): 1 3
// Enter friendship 6 (user1 user2): 2 4
