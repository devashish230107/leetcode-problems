class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        string concat = s + s;
        if (concat.find(goal) == string::npos) {
            return false;
        }
        return true;
    }
};