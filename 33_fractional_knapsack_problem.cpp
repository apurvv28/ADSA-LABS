#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item{
    int value;
    int weight;
};

bool compare(Item a, Item b){
    double r1 =(double)a.value / a.weight;
    double r2 =(double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(vector<Item> &items, int capacity){
    sort(items.begin(), items.end(), compare);
    double profit = 0;
    for (Item item : items){
        if (capacity >= item.weight){
            profit += item.value;
            capacity -= item.weight;
        }
        else{
            profit +=((double)item.value / item.weight) * capacity;
            break;
        }
    }
    return profit;
}
int main(){
    int n, capacity;
    cout << "Enter number of items and knapsack capacity: ";
    cin >> n >> capacity;
    vector<Item> items(n);
    for (int i = 0; i < n; i++){
        cout << "Enter value and weight of item " << (i+1) << ": ";
        cin >> items[i].value >> items[i].weight;
    }
    cout << "Maximum Profit: ";
    cout << fractionalKnapsack(items, capacity);
}

// Time Complexity: O(N log N)
// Space Complexity: O(1)

// Example Input:
// Enter number of items and knapsack capacity: 3 50
// Enter value and weight of item 1: 60 10
// Enter value and weight of item 2: 100 20
// Enter value and weight of item 3: 120 30
