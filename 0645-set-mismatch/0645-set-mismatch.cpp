class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n=nums.size();
        long long s=0,s2=0;
        long long sn=(n*(n+1))/2;
        long long sn2=(n*(n+1)*(2*n+1))/6;
        for(int i=0;i<n;i++){
            s+=nums[i];
            s2+=(long long)nums[i]*(long long)nums[i];
        }
        long long val1=s-sn;
        long long val2=s2-sn2;
        val2=val2/val1;
        long long x=(val1+val2)/2;
        long long y=x-val1;
        return {(int)x,(int)y};
    }
};