class Solution {
public:
    int myAtoi(string s) {
        string ans = "";
        int n = s.length();
        int itr = 0;
        int sign;
        int num = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                itr = i;
                break;
            }
        }
        if (s[itr] == '-') {
            sign = -1;
            itr++;
        } else if (s[itr] == '+') {
            sign = 1;
            itr++;
        } else {
            sign = 1;
        }
        for (int i = itr; i < n; i++) {
            if (isdigit(s[i])) {
                ans += s[i];
            } else {
                break;
            }
        }
        if (ans == "") {
            return 0;
        }
        for (int i = 0; i < ans.size(); i++) {
            int digit = ans[i] - '0';
            if (num > (INT_MAX - digit) / 10) {
                if (sign == -1)
                    return INT_MIN;
                else
                    return INT_MAX;
            }
            num = num * 10 + digit;
        }
        return num * sign;
    }
};