#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job
{
    int id;
    int d;
    int p;
};

int main()
{
    int n;
    cin >> n;
    vector<Job> jobs(n);
    int mxD = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> jobs[i].id >> jobs[i].d >> jobs[i].p;
        if (jobs[i].d > mxD)
            mxD = jobs[i].d;
    }
    sort(jobs.begin(), jobs.end(), [](const Job &a, const Job &b)
         { return a.p > b.p; });

    vector<int> slot(mxD + 1, -1);
    long long profit = 0;
    for (auto &j : jobs)
    {
        for (int t = j.d; t >= 1; t--)
        {
            if (t <= mxD && slot[t] == -1)
            {
                slot[t] = j.id;
                profit += j.p;
                break;
            }
        }
    }

    for (int t = 1; t <= mxD; t++)
        if (slot[t] != -1)
            cout << slot[t] << ' ';
    cout << "\n"
         << profit << "\n";
    return 0;
}


// Time Complexity: O(N^2) or O(N log N)
// Space Complexity: O(N)

// Example Input:
// 4
// 1 4 20
// 2 1 10
// 3 1 40
// 4 1 30
