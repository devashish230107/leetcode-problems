class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j= 0;
        int temp = 0;
        for(int i = 0 ;i<n;i++){
            if(j<n && nums[i]!=0 && nums[j]!=0){
                while(j < n && nums[j] != 0){
                j++;
            }}
            if (j < n && nums[i] != 0 && nums[j] == 0 && i>j) {
               swap(nums[i], nums[j]);
              }
            }
        }
    };
