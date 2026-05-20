#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job
{
    int id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

void jobSequencing(vector<Job> &jobs)
{
    sort(jobs.begin(),
         jobs.end(),
         compare);

    int maxDeadline = 0;

    for (Job j : jobs)
    {
        if (j.deadline > maxDeadline)
        {
            maxDeadline = j.deadline;
        }
    }

    vector<int> slot(maxDeadline + 1, -1);

    int totalProfit = 0;

    for (Job j : jobs)
    {
        for (int i = j.deadline; i >= 1; i--)
        {
            if (slot[i] == -1)
            {
                slot[i] = j.id;

                totalProfit += j.profit;

                break;
            }
        }
    }

    cout << "Jobs: ";

    for (int i = 1; i <= maxDeadline; i++)
    {
        if (slot[i] != -1)
        {
            cout << slot[i] << " ";
        }
    }

    cout << endl;

    cout << "Profit = "
         << totalProfit;
}

int main()
{
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);

    for (int i = 0; i < n; i++)
    {
        cout << "Enter job " << (i+1) << " (id deadline profit): ";
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    jobSequencing(jobs);
}

// Time Complexity: O(N^2) or O(N log N)
// Space Complexity: O(N)

// Example Input:
// Enter number of jobs: 4
// Enter job 1 (id deadline profit): 1 4 20
// Enter job 2 (id deadline profit): 2 1 10
// Enter job 3 (id deadline profit): 3 1 40
// Enter job 4 (id deadline profit): 4 1 30
