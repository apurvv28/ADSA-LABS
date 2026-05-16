#include <iostream>
using namespace std;

class LinearProbing{
public:
    int table[10];

    LinearProbing(){
        for(int i = 0; i < 10; i++){
            table[i] = -1;
        }
    }

    void insert(int key){
        int index = key % 10;

        while(table[index] != -1){
            index = (index + 1) % 10;
        }

        table[index] = key;
    }

    int search(int key){
        int index = key % 10;
        int comparisons = 1;

        while(table[index] != -1){
            if(table[index] == key){
                return comparisons;
            }

            index = (index + 1) % 10;
            comparisons++;
        }

        return comparisons;
    }

    void display(){
        for(int i = 0; i < 10; i++){
            cout << i << " -> " << table[i] << endl;
        }
    }
};

class QuadraticProbing{
public:
    int table[10];

    QuadraticProbing(){
        for(int i = 0; i < 10; i++){
            table[i] = -1;
        }
    }

    void insert(int key){
        int index = key % 10;
        int i = 1;

        while(table[index] != -1){
            index = (key + i * i) % 10;
            i++;
        }

        table[index] = key;
    }

    int search(int key){
        int index = key % 10;
        int i = 1;
        int comparisons = 1;

        while(table[index] != -1){
            if(table[index] == key){
                return comparisons;
            }

            index = (key + i * i) % 10;
            i++;
            comparisons++;
        }

        return comparisons;
    }

    void display(){
        for(int i = 0; i < 10; i++){
            cout << i << " -> " << table[i] << endl;
        }
    }
};

int main(){
    int n, num, key;

    LinearProbing lp;
    QuadraticProbing qp;

    cout << "Enter number of clients: ";
    cin >> n;

    cout << "Enter telephone numbers:\n";

    for(int i = 0; i < n; i++){
        cin >> num;

        lp.insert(num);
        qp.insert(num);
    }

    cout << "\nLinear Probing Hash Table:\n";
    lp.display();

    cout << "\nQuadratic Probing Hash Table:\n";
    qp.display();

    cout << "\nEnter number to search: ";
    cin >> key;

    cout << "\nComparisons in Linear Probing: ";
    cout << lp.search(key);

    cout << "\nComparisons in Quadratic Probing: ";
    cout << qp.search(key);

    return 0;
}