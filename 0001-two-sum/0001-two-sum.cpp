class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> arr;
        int i = 0;
        int j = n-1;
        for(i;i<n-1;i++){
            j=n-1;
            while(j>i){
                if(nums[i]+nums[j]==target){
                    arr.push_back(i);
                    arr.push_back(j);
                }
                j--;
            }
        }
        return arr;
    }
};