class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> zerorow(rows, 0);
        vector<int> zerocol(cols, 0);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    zerorow[i] = 1;
                    zerocol[j] = 1;
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            if (zerorow[i] == 1) {
                for (int j = 0; j < cols; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < cols; i++) {
            if (zerocol[i] == 1) {
                for (int j = 0; j < rows; j++) {
                    matrix[j][i] = 0;
                }
            }
        }
    }
};
