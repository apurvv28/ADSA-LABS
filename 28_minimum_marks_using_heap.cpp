#include <iostream>
#include <vector>
using namespace std;

void insertHeap(vector<int>& heap, int value)
{
    heap.push_back(value);

    int index = heap.size() - 1;

    while (index > 1 &&
           heap[index] < heap[index / 2])
    {
        swap(heap[index],
             heap[index / 2]);

        index = index / 2;
    }
}

int getMinimum(vector<int>& heap)
{
    return heap[1];
}

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<int> heap;

    heap.push_back(-1);

    for (int i = 0; i < n; i++)
    {
        int value;
        cout << "Enter marks of student " << (i+1) << ": ";
        cin >> value;

        insertHeap(heap, value);
    }

    cout << "Minimum = "
         << getMinimum(heap);
}

// Time Complexity: O(N log N)
// Space Complexity: O(N)

// Example Input:
// Enter number of students: 5
// Enter marks of student 1: 10
// Enter marks of student 2: 20
// Enter marks of student 3: 15
// Enter marks of student 4: 30
// Enter marks of student 5: 25
