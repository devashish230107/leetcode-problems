class Solution {
public:
    int noofsubarray(vector<int>& nums, int num, int n) {
        int sum = 0;
        int k = 1;
        for (int i = 0; i < n; i++) {
            if (sum + nums[i] <= num) {
                sum += nums[i];
            } else {
                k++;
                sum = nums[i];
            }
        }
        return k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (noofsubarray(nums,mid, n)>k) {
                low=mid+1;
            } else {
                high=mid-1;
            }
        }
        return low;
    }
};