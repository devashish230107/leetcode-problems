class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int count=0;
        int temp=0;
        for (int i = 0 ;i<n;i++){
            if(nums[i]==1){
                temp++;
            }
            if(nums[i]==0 || i==n-1) {
                if(temp>count){
                    count = temp;
                }
                temp = 0;
            }
        }
        return count;
    }
};