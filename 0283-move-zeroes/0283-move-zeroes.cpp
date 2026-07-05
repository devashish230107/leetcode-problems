class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j= 0;
        for(j;j<n;j++){
            if(nums[j]==0){
                break;
            }
            if(j==n-1){
                return;
            }
        }
        for(int i=j+1;i<n;i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
};
