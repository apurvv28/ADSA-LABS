#include <iostream>
using namespace std;

class Item{
public:
    int weight;
    int value;
    float ratio;
};

class FractionalKnapsack{
public:
    Item item[100];
    int n, capacity;

    void input(){
        cout << "Enter number of items: ";
        cin >> n;

        for(int i = 0; i < n; i++){
            cout << "Enter weight of item " << i + 1 << ": ";
            cin >> item[i].weight;

            cout << "Enter value of item " << i + 1 << ": ";
            cin >> item[i].value;

            item[i].ratio = (float)item[i].value / item[i].weight;
        }

        cout << "Enter knapsack capacity: ";
        cin >> capacity;
    }

    void sortItems(){
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < n - i - 1; j++){
                if(item[j].ratio < item[j + 1].ratio){
                    Item temp = item[j];
                    item[j] = item[j + 1];
                    item[j + 1] = temp;
                }
            }
        }
    }

    void knapsack(){
        float totalValue = 0;

        sortItems();

        cout << "\nSelected Items:\n";

        for(int i = 0; i < n; i++){
            if(capacity >= item[i].weight){
                cout << "Item " << i + 1 << " -> 100%\n";

                capacity = capacity - item[i].weight;

                totalValue = totalValue + item[i].value;
            }
            else{
                float fraction = (float)capacity / item[i].weight;

                cout << "Item " << i + 1 << " -> " << fraction * 100 << "%\n";

                totalValue = totalValue + (item[i].value * fraction);

                break;
            }
        }

        cout << "\nMaximum Total Value: " << totalValue;
    }
};

int main(){
    FractionalKnapsack fk;

    fk.input();

    fk.knapsack();

    return 0;
}