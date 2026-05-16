#include <iostream>
using namespace std;

class MergeSort{
public:
    int arr[100];
    int n;

    void input(){
        cout << "Enter number of students: ";
        cin >> n;

        cout << "Enter credits:\n";

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
    }

    void merge(int low, int mid, int high){
        int temp[100];

        int i = low;
        int j = mid + 1;
        int k = low;

        while(i <= mid && j <= high){
            if(arr[i] < arr[j]){
                temp[k] = arr[i];
                i++;
            }
            else{
                temp[k] = arr[j];
                j++;
            }

            k++;
        }

        while(i <= mid){
            temp[k] = arr[i];
            i++;
            k++;
        }

        while(j <= high){
            temp[k] = arr[j];
            j++;
            k++;
        }

        for(int i = low; i <= high; i++){
            arr[i] = temp[i];
        }
    }

    void mergeSort(int low, int high){
        if(low < high){
            int mid = (low + high) / 2;

            mergeSort(low, mid);
            mergeSort(mid + 1, high);

            merge(low, mid, high);
        }
    }

    void display(){
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
    }
};

int main(){
    MergeSort ms;

    ms.input();

    cout << "\nBefore Sorting: ";
    ms.display();

    ms.mergeSort(0, ms.n - 1);

    cout << "\nAfter Sorting: ";
    ms.display();

    return 0;
}