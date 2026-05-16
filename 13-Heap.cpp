#include <iostream>
using namespace std;

class Heap{
public:
    int arr[100];
    int n;

    Heap(){
        n = 0;
    }

    void insertMax(int val){
        int i = n;

        arr[n] = val;
        n++;

        while(i > 0){
            int parent = (i - 1) / 2;

            if(arr[parent] < arr[i]){
                int temp = arr[parent];
                arr[parent] = arr[i];
                arr[i] = temp;

                i = parent;
            }
            else{
                break;
            }
        }
    }

    void insertMin(int val){
        int i = n;

        arr[n] = val;
        n++;

        while(i > 0){
            int parent = (i - 1) / 2;

            if(arr[parent] > arr[i]){
                int temp = arr[parent];
                arr[parent] = arr[i];
                arr[i] = temp;

                i = parent;
            }
            else{
                break;
            }
        }
    }

    int getMax(){
        return arr[0];
    }

    int getMin(){
        return arr[0];
    }

    void display(){
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
    }
};

int main(){
    int n, marks;

    Heap maxHeap, minHeap;

    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter marks:\n";

    for(int i = 0; i < n; i++){
        cin >> marks;

        maxHeap.insertMax(marks);
    }

    cout << "\nMax Heap: ";
    maxHeap.display();

    cout << "\nMaximum Marks: " << maxHeap.getMax();

    minHeap.n = 0;

    cout << "\n\nEnter marks again:\n";

    for(int i = 0; i < n; i++){
        cin >> marks;

        minHeap.insertMin(marks);
    }

    cout << "\nMin Heap: ";
    minHeap.display();

    cout << "\nMinimum Marks: " << minHeap.getMin();

    cout << "\n\nTime Complexity: O(log n) for insertion";
    cout << "\nMaximum and Minimum at Root Node";

    return 0;
}