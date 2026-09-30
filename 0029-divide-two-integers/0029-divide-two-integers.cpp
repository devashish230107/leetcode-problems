class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==0) return 0;
        if(dividend==divisor) return 1;
        long ans=0;
        bool sign=true;
        if((dividend<0 && divisor>0) || (dividend>0 && divisor<0)) sign=false;
        long a=abs((long)dividend);
        long b=abs((long)divisor);
        while(a>=b){
            int count=0;
            while(a>=(b<<count+1)){
                count++;
            }
            ans+=1LL<<count;
            a-=b<<count;
        }
        if(ans>INT_MAX && sign){
            return INT_MAX;
        }
        if(-ans<INT_MIN && !sign){
            return INT_MIN;
        }
        if(sign){
            return ans;
        }
        else{
            return -ans;
        }
    }
};