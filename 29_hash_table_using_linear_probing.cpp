#include <iostream>
#include <vector>
using namespace std;
struct Data{
    long long phone;
    string name;
};
void insert(vector<Data>& table,int size,string name,long long phone){
    int index = phone % size;
    while (table[index].phone != -1){
        index = (index + 1) % size;
    }
    table[index].phone = phone;
    table[index].name = name;
}

void search(vector<Data>& table,int size,long long phone){
    int index = phone % size;
    int start = index;
    while (table[index].phone != -1){
        if (table[index].phone == phone){
            cout << table[index].name<< endl;
            return;
        }
        index = (index + 1) % size;
        if (index == start){
            break;
        }
    }
    cout << "NOT FOUND" << endl;
}

int main(){
    int size, n;
    cout << "Enter table size and number of entries: ";
    cin >> size >> n;
    vector<Data> table(size);
    for (int i = 0; i < size; i++){
        table[i].phone = -1;
    }
    for (int i = 0; i < n; i++){
        string name;
        long long phone;
        cout << "Enter name and phone of entry " << (i+1) << ": ";
        cin >> name >> phone;
        insert(table, size, name, phone);
    }
    long long phone;
    cout << "\nEnter phone numbers to search (enter -1 to exit):\n";
    while (cin >> phone){
        if (phone == -1){
            break;
        }
        search(table, size, phone);
    }
}

// Time Complexity: O(1) avg, O(N) worst
// Space Complexity: O(N)

// Example Input:
// Enter table size and number of entries: 5 3
// Enter name and phone of entry 1: Alice 1234567890
// Enter name and phone of entry 2: Bob 9876543210
// Enter name and phone of entry 3: Charlie 5555555555
// Enter phone numbers to search (enter -1 to exit):
// 1234567890
// -1
