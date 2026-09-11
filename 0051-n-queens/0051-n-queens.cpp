class Solution {
public:
    void solve(int i, int j, int k, int n, vector<string> board,
               vector<vector<string>>& ans) {

        if (k == n) {
            ans.push_back(board);
            return;
        }

        if (i == n)
            return;

        if (j == n) {
            return;
        }

        if (board[i][j] == '.') {
            solve(i, j + 1, k, n, board, ans);
            board[i][j] = 'Q';

            for (int l = 0; l < n; l++) {
                if (board[l][j] == '.')
                    board[l][j] = '#';
            }

            for (int l = 0; l < n; l++) {
                if (board[i][l] == '.')
                    board[i][l] = '#';
            }

            int x = i - 1;
            int y = j - 1;

            while (x >= 0 && y >= 0) {
                if (board[x][y] == '.')
                    board[x][y] = '#';
                x--;
                y--;
            }

            x = i + 1;
            y = j + 1;

            while (x < n && y < n) {
                if (board[x][y] == '.')
                    board[x][y] = '#';
                x++;
                y++;
            }

            x = i - 1;
            y = j + 1;

            while (x >= 0 && y < n) {
                if (board[x][y] == '.')
                    board[x][y] = '#';
                x--;
                y++;
            }

            x = i + 1;
            y = j - 1;

            while (x < n && y >= 0) {
                if (board[x][y] == '.')
                    board[x][y] = '#';
                x++;
                y--;
            }

            solve(i + 1, 0, k + 1, n, board, ans);
        } else {
            solve(i, j + 1, k, n, board, ans);
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        for (int i = 0; i < n; i++) {
            board.push_back(string(n, '.'));
        }
        solve(0, 0, 0, n, board, ans);
        for (int k = 0; k < ans.size(); k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (ans[k][i][j] == '#') {
                        ans[k][i][j] = '.';
                    }
                }
            }
        }
        return ans;
    }
};