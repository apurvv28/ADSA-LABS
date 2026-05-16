#include <iostream>
using namespace std;

class Job{
public:
    char id;
    int deadline;
    int profit;
};

class JobSequencing{
public:
    Job job[5];

    void input(){
        job[0].id = 'A';
        job[0].deadline = 2;
        job[0].profit = 100;

        job[1].id = 'B';
        job[1].deadline = 1;
        job[1].profit = 19;

        job[2].id = 'C';
        job[2].deadline = 2;
        job[2].profit = 27;

        job[3].id = 'D';
        job[3].deadline = 1;
        job[3].profit = 25;

        job[4].id = 'E';
        job[4].deadline = 3;
        job[4].profit = 15;
    }

    void sortJobs(){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4 - i; j++){
                if(job[j].profit < job[j + 1].profit){
                    Job temp = job[j];
                    job[j] = job[j + 1];
                    job[j + 1] = temp;
                }
            }
        }
    }

    void sequenceJobs(){
        sortJobs();

        int slot[10];

        for(int i = 0; i < 10; i++){
            slot[i] = -1;
        }

        int totalProfit = 0;

        cout << "\nSelected Jobs:\n";

        for(int i = 0; i < 5; i++){
            for(int j = job[i].deadline - 1; j >= 0; j--){
                if(slot[j] == -1){
                    slot[j] = i;

                    cout << job[i].id << " Deadline: " << job[i].deadline << endl;

                    totalProfit += job[i].profit;

                    break;
                }
            }
        }

        cout << "\nMaximum Profit: " << totalProfit;
    }
};

int main(){
    JobSequencing js;

    js.input();

    js.sequenceJobs();

    return 0;
}