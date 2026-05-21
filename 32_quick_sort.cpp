#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int>& arr,int low,int high){
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++){
        if (arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr,int low,int high){
    if (low < high){
        int pivotIndex = partition(arr, low, high);
        quickSort(arr,low,pivotIndex - 1);
        quickSort(arr,pivotIndex + 1,high);
    }
}
int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cout << "Enter element " << (i+1) << ": ";
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    cout << "\nSorted Array: ";
    for (int x : arr){
        cout << x << " ";
    }
}

// Time Complexity: O(N log N) avg, O(N^2) worst
// Space Complexity: O(log N)

// Example Input:
// Enter number of elements: 5
// Enter element 1: 5
// Enter element 2: 4
// Enter element 3: 3
// Enter element 4: 2
// Enter element 5: 1
