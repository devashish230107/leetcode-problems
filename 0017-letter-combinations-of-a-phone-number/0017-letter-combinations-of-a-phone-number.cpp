class Solution {
public:
    void solve(int i, string digits, int n, vector<string>& represent,
               vector<string>& ans, string sol) {
        if (i == n) {
            ans.push_back(sol);
            return;
        }
        sol += represent[digits[i] - '2'][0];
        solve(i + 1, digits, n, represent, ans, sol);
        sol.pop_back();
        sol += represent[digits[i] - '2'][1];
        solve(i + 1, digits, n, represent, ans, sol);
        sol.pop_back();
        sol += represent[digits[i] - '2'][2];
        solve(i + 1, digits, n, represent, ans, sol);
        sol.pop_back();
        if (represent[digits[i] - '2'].size() == 4) {
            sol += represent[digits[i] - '2'][3];
            solve(i + 1, digits, n, represent, ans, sol);
            sol.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> represent = {"abc", "def",  "ghi", "jkl",
                                    "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans = {};
        solve(0, digits, digits.size(), represent, ans, "");
        return ans;
    }
};