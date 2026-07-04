#include <climits>
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int rev = 0;
        int y = x;
        while(y>0){
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && y%10 > 7))
                return false;
            rev = rev*10 + y%10;
            y=y/10;
        }
        if(rev==x){
            return true;

        }
        else{
            return false;
        }
        
    }
};