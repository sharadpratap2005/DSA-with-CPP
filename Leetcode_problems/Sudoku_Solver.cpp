class Solution {
public:
    bool isvalid(vector<vector<char>>& board, int row, int col, char c) {
        for (int k = 0; k < 9; k++) {
            // check row
            if (board[row][k] == c)
                return false;
            // check column
            if (board[k][col] == c)
                return false;
            // check 3X3 Grid
            int subrow = 3 * (row / 3) + k / 3;
            int subcol = 3 * (col / 3) + k % 3;
            if (board[subrow][subcol] == c)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isvalid(board, i, j, c)) {
                            board[i][j] = c;
                            if (solve(board))
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) { solve(board); }
};
