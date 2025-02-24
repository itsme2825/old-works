#include <iostream>

using namespace std;

const int MAX = 20; 
int board[MAX][MAX];


bool isSafe(int board[MAX][MAX], int row, int col, int n) {
   
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

  
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}


bool solveNQueens(int board[MAX][MAX], int row, int n) {
   
    if (row >= n)
        return true;

    
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            
            board[row][col] = 1;

            if (solveNQueens(board, row + 1, n))
                return true;

           
            board[row][col] = 0;
        }
    }

    
    return false;
}

int main() {
    int n;
    cout << "Enter the size of the chessboard (n): ";
    cin >> n;

   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }

    if (solveNQueens(board, 0, n)) {
        cout << "Solution found:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists for n = " << n << endl;
    }

    return 0;
}
