#include <iostream>
#include <vector>
using namespace std;

struct Rec
{
    int roll;
    int credit;
};

int part(vector<Rec> &a, int l, int r)
{
    int pivot = a[r].credit;
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (a[j].credit <= pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void quickSort(vector<Rec> &a, int l, int r)
{
    if (l >= r)
        return;
    int p = part(a, l, r);
    quickSort(a, l, p - 1);
    quickSort(a, p + 1, r);
}

int main()
{
    int n;
    cin >> n;
    vector<Rec> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].roll >> a[i].credit;
    if (n > 0)
        quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i].roll << " " << a[i].credit << "\n";
    return 0;
}


// Time Complexity: O(N log N) avg, O(N^2) worst
// Space Complexity: O(log N)

// Example Input:
// 5
// 5 4 3 2 1
