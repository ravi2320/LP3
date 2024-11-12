#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool solveNQueens(int col, int n, vector<string>& board, vector<int>& leftRow, vector<int>& lowerDiagonal, vector<int>& upperDiagonal) {
        // Base case: If all queens are placed
        if (col >= n) {
            return true;
        }

        for (int row = 0; row < n; row++) {
            // Check if the current cell is safe to place a queen
            if (!leftRow[row] && !lowerDiagonal[row + col] && !upperDiagonal[n - 1 + col - row]) {
                // Mark the cell as occupied
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;
                board[row][col] = 'Q';

                // Recursively try to place the next queen
                if (solveNQueens(col + 1, n, board, leftRow, lowerDiagonal, upperDiagonal)) {
                    return true;
                }

                // Backtrack: If placing the queen at this position doesn't lead to a solution, unmark it
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
                board[row][col] = '.';
            }
        }

        return false; // If no valid placement is found for the current column
    }

    void solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<int> leftRow(n, 0), lowerDiagonal(2 * n - 1, 0), upperDiagonal(2 * n - 1, 0);

        // Get the initial position of the first queen from the user
        int row, col;
        cout << "Enter row and col (0 to n-1) to place the first queen: ";
        cin >> row >> col;

        // Mark the initial position as occupied
        leftRow[row] = 1;
        lowerDiagonal[row + col] = 1;
        upperDiagonal[n - 1 + col - row] = 1;
        board[row][col] = 'Q';

        if (solveNQueens(1, n, board, leftRow, lowerDiagonal, upperDiagonal)) {
            printBoard(board);
        } else {
            cout << "Solution does not exist.\n";
        }
    }

    void printBoard(const vector<string>& board) {
        for (const string& row : board) {
            cout << row << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    Solution S;
    S.solveNQueens(n);

    return 0;
}