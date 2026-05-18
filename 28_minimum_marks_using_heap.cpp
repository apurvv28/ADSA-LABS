#include <iostream>
#include <vector>
using namespace std;

struct MinHeap
{
    vector<int> a;
    MinHeap() { a.push_back(0); }
    void push(int x)
    {
        a.push_back(x);
        int i = (int)a.size() - 1;
        while (i > 1 && a[i / 2] > a[i])
        {
            swap(a[i / 2], a[i]);
            i /= 2;
        }
    }
    int top() const { return a.size() > 1 ? a[1] : 0; }
};

int main()
{
    int n;
    cin >> n;
    MinHeap h;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        h.push(x);
    }
    cout << h.top() << "\n";
    return 0;
}


// Time Complexity: O(N log N)
// Space Complexity: O(N)

// Example Input:
// 5
// 10 20 15 30 25
