#include <iostream>
using namespace std;

class Edge{
public:
    int u, v, w;
};

class Graph{
public:
    int parent[10];

    int find(int i){
        while(parent[i] != i){
            i = parent[i];
        }

        return i;
    }

    void unionSet(int a, int b){
        parent[a] = b;
    }

    void kruskal(Edge e[], int n, int edges){
        int mincost = 0;

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        cout << "\nEdges in MST:\n";

        for(int i = 0; i < edges - 1; i++){
            for(int j = 0; j < edges - i - 1; j++){
                if(e[j].w > e[j + 1].w){
                    Edge temp = e[j];
                    e[j] = e[j + 1];
                    e[j + 1] = temp;
                }
            }
        }

        int count = 0;
        int i = 0;

        while(count < n - 1){
            int a = find(e[i].u);
            int b = find(e[i].v);

            if(a != b){
                cout << e[i].u << " - " << e[i].v << " = " << e[i].w << endl;

                mincost += e[i].w;

                unionSet(a, b);

                count++;
            }

            i++;
        }

        cout << "Total Minimum Cost: " << mincost;
    }
};

int main(){
    Graph g;

    int n, edges;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> edges;

    Edge e[20];

    cout << "Enter source destination weight:\n";

    for(int i = 0; i < edges; i++){
        cin >> e[i].u >> e[i].v >> e[i].w;
    }

    g.kruskal(e, n, edges);

    return 0;
}