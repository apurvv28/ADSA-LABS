#include <iostream>
using namespace std;

class TSP{
public:
    int tsp[10][10];
    int visited[10];
    int n;
    int minCost;

    void input(){
        n = 4;

        tsp[0][0] = -1;
        tsp[0][1] = 10;
        tsp[0][2] = 15;
        tsp[0][3] = 20;

        tsp[1][0] = 10;
        tsp[1][1] = -1;
        tsp[1][2] = 35;
        tsp[1][3] = 25;

        tsp[2][0] = 15;
        tsp[2][1] = 35;
        tsp[2][2] = -1;
        tsp[2][3] = 30;

        tsp[3][0] = 20;
        tsp[3][1] = 25;
        tsp[3][2] = 30;
        tsp[3][3] = -1;
    }

    void initialize(){
        for(int i = 0; i < n; i++){
            visited[i] = 0;
        }

        minCost = 9999;
    }

    void tspCycle(int city, int count, int cost){
        if(count == n && tsp[city][0] != -1){
            if(cost + tsp[city][0] < minCost){
                minCost = cost + tsp[city][0];
            }

            return;
        }

        for(int i = 0; i < n; i++){
            if(visited[i] == 0 && tsp[city][i] != -1){
                visited[i] = 1;

                tspCycle(i, count + 1, cost + tsp[city][i]);

                visited[i] = 0;
            }
        }
    }
};

int main(){
    TSP t;

    t.input();

    t.initialize();

    t.visited[0] = 1;

    t.tspCycle(0, 1, 0);

    cout << "Minimum Cost of TSP Cycle: " << t.minCost;

    return 0;
}