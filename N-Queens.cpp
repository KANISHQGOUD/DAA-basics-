#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    for (int i = 0; i < col; i++) if (board[row][i]) return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) if (board[i][j]) return false;
    for (int i = row, j = col; i < n && j >= 0; i++, j--) if (board[i][j]) return false;
    return true;
}

bool solve(vector<vector<int>>& board, int col, int n) {
    if (col >= n) return true;
    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;
            if (solve(board, col+1, n)) return true;
            board[i][col] = 0;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    if (solve(board, 0, n)) {
        for (auto& row : board) {
            for (auto x : row) cout << x << " ";
            cout << endl;
        }
    }
    return 0;
}
