#include <string>
#include <cctype>
class Solution {
public:
bool solve(string& s, int l, int r) {
        if (l >= r)
            return true;

        if (!isalnum(s[l]))
            return solve(s, l + 1, r);

        if (!isalnum(s[r]))
            return solve(s, l, r - 1);

        if (tolower(s[l]) != tolower(s[r]))
            return false;

        return solve(s, l + 1, r - 1);
    }
    bool isPalindrome(string s) {
        return solve(s, 0, s.length() - 1);
    }
};