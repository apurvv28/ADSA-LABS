#include <iostream>
#include <vector>
#include <list>
using namespace std;

void insert(vector<list<pair<long long, string>>>& table,
            int size,
            string name,
            long long phone)
{
    int index = phone % size;

    table[index].push_back({phone, name});
}

void search(vector<list<pair<long long, string>>>& table,
            int size,
            long long phone)
{
    int index = phone % size;

    for (auto data : table[index])
    {
        if (data.first == phone)
        {
            cout << data.second
                 << endl;

            return;
        }
    }

    cout << "NOT FOUND" << endl;
}

int main()
{
    int size, n;
    cout << "Enter table size and number of entries: ";
    cin >> size >> n;

    vector<list<pair<long long, string>>> table(size);

    for (int i = 0; i < n; i++)
    {
        string name;
        long long phone;

        cout << "Enter name and phone of entry " << (i+1) << ": ";
        cin >> name >> phone;

        insert(table, size, name, phone);
    }

    long long phone;

    cout << "\nEnter phone numbers to search (enter -1 to exit):\n";
    while (cin >> phone)
    {
        if (phone == -1)
        {
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
