class Solution {
public:
    vector<vector<string>> result;  // Stores all valid configurations
    int N;  // Board size

    // Function to check if a queen can be placed at (row, col)
    bool isValid(vector<string>& board, int row, int col) {
        // Check vertically upwards
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == 'Q') return false;
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true; // Safe to place queen
    }

    // Recursive function to solve N-Queens using backtracking
    void solve(vector<string>& board, int row) {
        if (row >= N) {
            result.push_back(board); // Found valid configuration
            return;
        }

        for (int col = 0; col < N; col++) {
            if (isValid(board, row, col)) {
                board[row][col] = 'Q'; // Place queen
                solve(board, row + 1); // Move to next row
                board[row][col] = '.'; // Backtrack
            }
        }
    }

    // Main function
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string> board(n, string(n, '.')); // Create empty board
        solve(board, 0); // Start from row 0
        return result;
    }
};