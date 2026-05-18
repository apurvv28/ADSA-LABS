#include <iostream>
#include <vector>
using namespace std;

struct Rec
{
    int roll;
    int credit;
};

void mergeSort(vector<Rec> &a, int l, int r, vector<Rec> &tmp)
{
    if (l >= r)
        return;
    int m = (l + r) / 2;
    mergeSort(a, l, m, tmp);
    mergeSort(a, m + 1, r, tmp);
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r)
    {
        if (a[i].credit <= a[j].credit)
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }
    while (i <= m)
        tmp[k++] = a[i++];
    while (j <= r)
        tmp[k++] = a[j++];
    for (int p = l; p <= r; p++)
        a[p] = tmp[p];
}

int main()
{

    int n;
    cin >> n;
    vector<Rec> a(n), tmp(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].roll >> a[i].credit;
    if (n > 0)
        mergeSort(a, 0, n - 1, tmp);
    for (int i = 0; i < n; i++)
        cout << a[i].roll << " " << a[i].credit << "\n";
    return 0;
}


// Time Complexity: O(N log N)
// Space Complexity: O(N)

// Example Input:
// 5
// 5 4 3 2 1
