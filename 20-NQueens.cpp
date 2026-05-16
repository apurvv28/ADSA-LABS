#include <iostream>
using namespace std;

class NQueen{
public:
    int board[10][10];
    int n;

    void input(){
        cout << "Enter number of queens: ";
        cin >> n;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                board[i][j] = 0;
            }
        }
    }

    bool isSafe(int row, int col){
        for(int i = 0; i < row; i++){
            if(board[i][col] == 1){
                return false;
            }
        }

        int i = row - 1;
        int j = col - 1;

        while(i >= 0 && j >= 0){
            if(board[i][j] == 1){
                return false;
            }

            i--;
            j--;
        }

        i = row - 1;
        j = col + 1;

        while(i >= 0 && j < n){
            if(board[i][j] == 1){
                return false;
            }

            i--;
            j++;
        }

        return true;
    }

    bool solve(int row){
        if(row == n){
            return true;
        }

        for(int col = 0; col < n; col++){
            if(isSafe(row, col)){
                board[row][col] = 1;

                if(solve(row + 1)){
                    return true;
                }

                board[row][col] = 0;
            }
        }

        return false;
    }

    void display(){
        cout << "\nSolution Matrix:\n";

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << board[i][j] << " ";
            }

            cout << endl;
        }
    }
};

int main(){
    NQueen nq;

    nq.input();

    if(nq.solve(0)){
        nq.display();
    }
    else{
        cout << "Solution Not Possible";
    }

    return 0;
}
