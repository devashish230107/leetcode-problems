class Solution {
public:
int temp;
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> nums1(n, 0);
        if(k>=n){
            k = k%n;
        }
        for(int i=0 ; i<n ; i++){
            if((n-1)-i>=k){
                nums1[i+k] = nums[i];
            }
            else{
                nums1[i+(k-n)] = nums[i];
            }

        }
        nums = nums1;

    }
};