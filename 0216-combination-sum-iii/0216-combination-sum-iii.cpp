class Solution {
public:
    void solve(vector<int>& candidates, int target, int i,
               vector<vector<int>>& ans, int sum, vector<int>& sol, int k) {
        if (sum == target) {
            if (sol.size() == k)
                ans.push_back(sol);
            return;
        }
        if (i == candidates.size()) {
            return;
        }
        if (sum > target) {
            return;
        }
        sol.push_back(candidates[i]);
        solve(candidates, target, i + 1, ans, sum + candidates[i], sol, k);
        sol.pop_back();
        solve(candidates, target, i + 1, ans, sum, sol, k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidates = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> ans;
        vector<int> sol;
        solve(candidates, n, 0, ans, 0, sol, k);
        return ans;
    }
};