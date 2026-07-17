class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ansvector;
        long long ans = 1;
        ansvector.push_back(ans);
        for (int i = 1; i <= rowIndex; i++) {
            ans = ans * (rowIndex+1 - i);
            ans = ans / i;
            ansvector.push_back(ans);
        }
        return ansvector;
    }
};