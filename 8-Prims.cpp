#include <iostream>
using namespace std;

class Graph{
public:
    int cost[10][10];
    int visited[10];
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

    void prims(){
        int mincost = 0;
        int edges = 1;

        for(int i = 0; i < n; i++){
            visited[i] = 0;
        }

        visited[0] = 1;

        cout << "\nEdges in MST:\n";

        while(edges < n){
            int min = 999;
            int a = -1;
            int b = -1;

            for(int i = 0; i < n; i++){
                if(visited[i] == 1){
                    for(int j = 0; j < n; j++){
                        if(visited[j] == 0 && cost[i][j] < min){
                            min = cost[i][j];
                            a = i;
                            b = j;
                        }
                    }
                }
            }

            cout << a << " - " << b << " = " << min << endl;

            mincost += min;
            visited[b] = 1;
            edges++;
        }

        cout << "Total Minimum Cost: " << mincost;
    }
};

int main(){
    Graph g;

    g.input();
    g.prims();

    return 0;
}