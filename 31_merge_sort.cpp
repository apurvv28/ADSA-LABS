#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr,
           int left,
           int mid,
           int right)
{
    vector<int> temp;

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }

        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= right)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int i = left; i <= right; i++)
    {
        arr[i] = temp[i - left];
    }
}

void mergeSort(vector<int>& arr,
               int left,
               int right)
{
    if (left >= right)
    {
        return;
    }

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid);

    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << (i+1) << ": ";
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted Array: ";
    for (int x : arr)
    {
        cout << x << " ";
    }
}


// Time Complexity: O(N log N)
// Space Complexity: O(N)

// Example Input:
// Enter number of elements: 5
// Enter element 1: 5
// Enter element 2: 4
// Enter element 3: 3
// Enter element 4: 2
// Enter element 5: 1
