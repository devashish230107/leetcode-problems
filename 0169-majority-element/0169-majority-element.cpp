class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int element=nums[0];
        for (int i=1;i<nums.size();i++){
            if(nums[i]==element){
                count++;
            }
            else{
                count--;
                if(count==0 && i<nums.size()-1){
                    element=nums[i+1];
                }
            }
        }
        return element;
    }
};