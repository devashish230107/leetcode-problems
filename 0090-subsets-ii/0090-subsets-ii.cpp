class Solution {
public:
    void solve(vector<int>& arr, vector<vector<int>>& ans, int i, int n,
               vector<int> sol) {
        if (i == n) {
            ans.push_back(sol);
            return;
        }
        sol.push_back(arr[i]);
        solve(arr, ans, i + 1, n, sol);
        sol.pop_back();
        while (i + 1 < n && arr[i] == arr[i + 1]) {
            i++;
        }
        solve(arr, ans, i + 1, n, sol);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> ans;
        vector<int> sol;
        solve(arr, ans, 0, n, sol);
        return ans;
    }
};