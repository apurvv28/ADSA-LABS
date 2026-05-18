#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Entry
{
    long long phone = -1;
    string name;
    bool used = false;
};

int main()
{
    int m, n;
    cin >> m >> n;
    if (m <= 0)
        return 0;
    vector<Entry> t(m);

    for (int i = 0; i < n; i++)
    {
        string name;
        long long phone;
        cin >> name >> phone;
        int idx = (int)((phone % m + m) % m);
        int start = idx;
        while (t[idx].used && t[idx].phone != phone)
        {
            idx = (idx + 1) % m;
            if (idx == start)
                break;
        }
        t[idx].used = true;
        t[idx].phone = phone;
        t[idx].name = name;
    }

    long long q;
    while (cin >> q)
    {
        if (q == -1)
            break;
        int idx = (int)((q % m + m) % m);
        int start = idx;
        bool ok = false;
        while (t[idx].used)
        {
            if (t[idx].phone == q)
            {
                ok = true;
                break;
            }
            idx = (idx + 1) % m;
            if (idx == start)
                break;
        }
        if (ok)
            cout << t[idx].name << "\n";
        else
            cout << "NOT FOUND\n";
    }
    return 0;
}


// Time Complexity: O(1) avg, O(N) worst
// Space Complexity: O(N)

// Example Input:
// 5
// 10 20 15 30 25
