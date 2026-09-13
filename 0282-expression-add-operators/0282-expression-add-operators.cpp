class Solution {
public:
    void solve(int i, int n, string& num, long long target, long long current,
               long long prev, string sol, vector<string>& ans) {

        if (i == n) {
            if (current == target)
                ans.push_back(sol);
            return;
        }

        for (int j = i; j < n; j++) {
            if (j > i && num[i] == '0')
                break;

            string part = num.substr(i, j - i + 1);
            // stoll = string to long long
            long long x = stoll(part);
            if (i == 0) {
                solve(j + 1, n, num, target, x, x, part, ans);
            } else {
                solve(j + 1, n, num, target, current + x, x, sol + "+" + part,
                      ans);

                solve(j + 1, n, num, target, current - x, -x, sol + "-" + part,
                      ans);

                solve(j + 1, n, num, target, current - prev + prev * x,
                      prev * x, sol + "*" + part, ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        solve(0, num.size(), num, target, 0, 0, "", ans);
        return ans;
    }
};