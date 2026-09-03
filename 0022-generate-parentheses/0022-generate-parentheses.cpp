class Solution {
public:
    void parenthesis(int open, int close, vector<string>& allstring, string string1, int n) {
        if(string1.size() == 2 * n) {
            allstring.push_back(string1);
            return;
        }

        if(open < n) {
            string1.push_back('(');
            parenthesis(open + 1, close, allstring, string1, n);
            string1.pop_back();
        }

        if(close < open) {
            string1.push_back(')');
            parenthesis(open, close + 1, allstring, string1, n);
            string1.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> allstring;
        parenthesis(0, 0, allstring, "", n);
        return allstring;
    }
};