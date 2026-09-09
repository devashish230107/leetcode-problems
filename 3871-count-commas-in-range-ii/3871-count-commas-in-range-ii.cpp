class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000) return 0;
        long long res = 0;
        if(n >= (long long)1000) res += n - (long long)999;
        if(n >= (long long)1000000) res += n - (long long)999999;
        if(n >= (long long)1000000000) res += n - (long long)999999999;
        if(n >= (long long)1000000000000) res += n - (long long)999999999999;
        if(n >= (long long)1000000000000000) res += n - (long long)999999999999999;
        return res;  
    }
};