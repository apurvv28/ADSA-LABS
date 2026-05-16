#include <iostream>
using namespace std;

class Graph{
public:
    int cost[10][10], dist[10], visited[10];
    int n;

    void input(){
        cout << "Enter number of vertices: ";
        cin >> n;

        cout << "Enter adjacency matrix:\n";

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> cost[i][j];

                if(cost[i][j] == 0){
                    cost[i][j] = 999;
                }
            }
        }
    }

    void dijkstra(int src){
        for(int i = 0; i < n; i++){
            dist[i] = cost[src][i];
            visited[i] = 0;
        }

        visited[src] = 1;
        dist[src] = 0;

        for(int count = 1; count < n - 1; count++){
            int min = 999;
            int u;

            for(int i = 0; i < n; i++){
                if(dist[i] < min && visited[i] == 0){
                    min = dist[i];
                    u = i;
                }
            }

            visited[u] = 1;

            for(int i = 0; i < n; i++){
                if(visited[i] == 0 && dist[u] + cost[u][i] < dist[i]){
                    dist[i] = dist[u] + cost[u][i];
                }
            }
        }

        cout << "\nShortest Path Costs:\n";

        for(int i = 0; i < n; i++){
            cout << src << " -> " << i << " = " << dist[i] << endl;
        }

        cout << "\nNegative Cycle Detection Not Possible in Dijkstra";
    }
};

int main(){
    Graph g;
    int src;

    g.input();

    cout << "Enter source vertex: ";
    cin >> src;

    g.dijkstra(src);

    return 0;
}