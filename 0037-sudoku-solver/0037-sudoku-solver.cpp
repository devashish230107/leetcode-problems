class Solution {
public:
    bool solve(int i, int j, int n, int m,
               vector<vector<char>>& board, int input) {

        if (i == n) {
            return true;
        }

        if (input > 9) {
            return false;
        }

        if (board[i][j] == '.') {

            for (int k = 0; k < n; k++) {

                if (board[k][j] == input + '0') {
                    return solve(i, j, n, m, board, input + 1);
                }

                if (board[i][k] == input + '0') {
                    return solve(i, j, n, m, board, input + 1);
                }
            }

            int startRow = (i / 3) * 3;
            int startCol = (j / 3) * 3;

            for (int k = startRow; k < startRow + 3; k++) {
                for (int l = startCol; l < startCol + 3; l++) {

                    if (board[k][l] == input + '0') {
                        return solve(i, j, n, m, board, input + 1);
                    }
                }
            }

            board[i][j] = input + '0';

            bool solved;

            if (j == 8) {
                solved = solve(i + 1, 0, n, m, board, 1);
            }
            else {
                solved = solve(i, j + 1, n, m, board, 1);
            }

            if (solved) {
                return true;
            }

            board[i][j] = '.';

            return solve(i, j, n, m, board, input + 1);
        }

        if (j == 8) {
            return solve(i + 1, 0, n, m, board, 1);
        }
        else {
            return solve(i, j + 1, n, m, board, 1);
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(0, 0, 9, 9, board, 1);
    }
};