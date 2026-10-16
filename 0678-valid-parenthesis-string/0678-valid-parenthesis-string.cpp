class Solution {
public:
    bool checkValidString(string s) {
        int mini = 0;
        int maxi = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                mini++;
                maxi++;
            } else if (s[i] == ')') {
                mini--;
                maxi--;
            } else {
                mini--;
                maxi++;
            }
            if (mini < 0)
                mini = 0;
            if (maxi < 0)
                return false; // for if input is ')'
        }
        return (mini == 0);
    }
};