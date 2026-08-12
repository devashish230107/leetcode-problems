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
        for (int i = itr; i < n && isdigit(s[i]); i++) {
            int digit = s[i] - '0';

            if (num > (INT_MAX - digit) / 10) {
                return sign == -1 ? INT_MIN : INT_MAX;
            }

            num = num * 10 + digit;
        }
        return num * sign;
    }
};