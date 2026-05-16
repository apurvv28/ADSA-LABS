#include <iostream>
using namespace std;

class Student{
public:
    string name;
    int credits;
};

class QuickSort{
public:
    Student s[100];
    int n;

    void input(){
        cout << "Enter number of students: ";
        cin >> n;

        for(int i = 0; i < n; i++){
            cout << "Enter student name: ";
            cin >> s[i].name;

            cout << "Enter credits: ";
            cin >> s[i].credits;
        }
    }

    int partition(int low, int high){
        int pivot = s[high].credits;

        int i = low - 1;

        for(int j = low; j < high; j++){
            if(s[j].credits > pivot){
                i++;

                Student temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }

        Student temp = s[i + 1];
        s[i + 1] = s[high];
        s[high] = temp;

        return i + 1;
    }

    void quickSort(int low, int high){
        if(low < high){
            int pi = partition(low, high);

            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }

    void display(){
        for(int i = 0; i < n; i++){
            cout << s[i].name << " - " << s[i].credits << endl;
        }
    }

    void topStudents(){
        cout << "\nTop 3 Students:\n";

        for(int i = 0; i < 3 && i < n; i++){
            cout << s[i].name << " - " << s[i].credits << endl;
        }
    }
};

int main(){
    QuickSort qs;

    qs.input();

    cout << "\nBefore Sorting:\n";
    qs.display();

    qs.quickSort(0, qs.n - 1);

    cout << "\nAfter Sorting:\n";
    qs.display();

    qs.topStudents();

    return 0;
}