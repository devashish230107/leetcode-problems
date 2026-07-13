class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> zerorow;
        vector<int> zerocol;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    zerorow.push_back(i);
                    zerocol.push_back(j);
                }
            }
        }
        int i = 0;
        int j = 0;
        while (i < zerorow.size()) {
            for (int k = 0; k < rows; k++) {
                matrix[k][zerocol[j]] = 0;
            }
            for (int k = 0; k < cols; k++) {
                matrix[zerorow[i]][k] = 0;
            }
            i++;
            j++;
        }
    }
};
