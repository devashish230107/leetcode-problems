class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum = 0;
        int result=INT_MIN;
        for(int i=0;i<n;i++){
            sum += nums[i];
            result=max(sum,result);
            if(sum<0){
                sum=0;
            }
        }
        return result;
    }
};