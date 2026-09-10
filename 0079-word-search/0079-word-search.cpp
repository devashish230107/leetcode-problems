class Solution {
public:
    bool solve(int i, int j, int k, vector<vector<char>>& board, string& word) {
        if (k == word.size())
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return false;
        if (board[i][j] != word[k])
            return false;
        char temp = board[i][j];
        board[i][j] = '#';
        bool found = solve(i + 1, j, k + 1, board, word) ||
                     solve(i - 1, j, k + 1, board, word) ||
                     solve(i, j + 1, k + 1, board, word) ||
                     solve(i, j - 1, k + 1, board, word);
        board[i][j] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (solve(i, j, 0, board, word))
                    return true;
            }
        }
        return false;
    }
};