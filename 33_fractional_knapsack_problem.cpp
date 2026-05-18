#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
    double v, w;
};

int main()
{
    int n;
    double cap;
    cin >> n >> cap;
    vector<Item> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].v >> a[i].w;

    sort(a.begin(), a.end(), [](const Item &x, const Item &y)
         { return (x.v / x.w) > (y.v / y.w); });

    double profit = 0;
    for (auto &it : a)
    {
        if (cap <= 0)
            break;
        if (it.w <= cap)
        {
            profit += it.v;
            cap -= it.w;
        }
        else
        {
            profit += (it.v / it.w) * cap;
            cap = 0;
        }
    }
    cout.setf(std::ios::fixed);
    cout.precision(6);
    cout << profit << "\n";
    return 0;
}


// Time Complexity: O(N log N)
// Space Complexity: O(1)

// Example Input:
// 3 50
// 60 10
// 100 20
// 120 30
