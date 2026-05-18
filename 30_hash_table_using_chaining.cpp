#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    if (m <= 0)
        return 0;
    vector<list<pair<long long, string>>> table(m);

    for (int i = 0; i < n; i++)
    {
        string name;
        long long phone;
        cin >> name >> phone;
        int idx = (int)((phone % m + m) % m);
        table[idx].push_back({phone, name});
    }

    long long q;
    while (cin >> q)
    {
        if (q == -1)
            break;
        int idx = (int)((q % m + m) % m);
        bool ok = false;
        for (auto &p : table[idx])
            if (p.first == q)
            {
                cout << p.second << "\n";
                ok = true;
                break;
            }
        if (!ok)
            cout << "NOT FOUND\n";
    }
    return 0;
}


// Time Complexity: O(1) avg, O(N) worst
// Space Complexity: O(N)

// Example Input:
// 5
// 10 20 15 30 25
