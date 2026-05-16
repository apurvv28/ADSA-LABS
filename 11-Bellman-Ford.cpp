#include <iostream>
using namespace std;

class Edge{
public:
    int u, v, w;
};

class Graph{
public:
    int dist[10];

    void bellmanFord(Edge e[], int v, int ed, int src){
        for(int i = 0; i < v; i++){
            dist[i] = 999;
        }

        dist[src] = 0;

        for(int i = 1; i <= v - 1; i++){
            for(int j = 0; j < ed; j++){
                if(dist[e[j].u] != 999 && dist[e[j].u] + e[j].w < dist[e[j].v]){
                    dist[e[j].v] = dist[e[j].u] + e[j].w;
                }
            }
        }

        bool negativeCycle = false;

        for(int j = 0; j < ed; j++){
            if(dist[e[j].u] != 999 && dist[e[j].u] + e[j].w < dist[e[j].v]){
                negativeCycle = true;
            }
        }

        cout << "\nShortest Path Costs:\n";

        for(int i = 0; i < v; i++){
            cout << src << " -> " << i << " = " << dist[i] << endl;
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

    int v, ed, src;

    cout << "Enter number of vertices: ";
    cin >> v;

    cout << "Enter number of edges: ";
    cin >> ed;

    Edge e[20];

    cout << "Enter source destination weight:\n";

    for(int i = 0; i < ed; i++){
        cin >> e[i].u >> e[i].v >> e[i].w;
    }

    cout << "Enter source vertex: ";
    cin >> src;

    g.bellmanFord(e, v, ed, src);

    return 0;
}