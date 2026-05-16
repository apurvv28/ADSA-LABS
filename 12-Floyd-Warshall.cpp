#include <iostream>
using namespace std;

class Graph{
public:
    int dist[10][10];
    int n;

    void input(){
        cout << "Enter number of vertices: ";
        cin >> n;

        cout << "Enter adjacency matrix:\n";

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> dist[i][j];

                if(i != j && dist[i][j] == 0){
                    dist[i][j] = 999;
                }
            }
        }
    }

    void floydWarshall(){
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dist[i][k] + dist[k][j] < dist[i][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        cout << "\nShortest Path Matrix:\n";

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << dist[i][j] << "\t";
            }

            cout << endl;
        }

        bool negativeCycle = false;

        for(int i = 0; i < n; i++){
            if(dist[i][i] < 0){
                negativeCycle = true;
            }
        }

        if(negativeCycle){
            cout << "\nNegative Cycle Detected";
        }else{
            cout << "\nNo Negative Cycle";
        }
    }
};

int main(){
    Graph g;

    g.input();

    g.floydWarshall();

    return 0;
}