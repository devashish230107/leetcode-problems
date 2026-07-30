class Solution {
public:
    bool willfinish(vector<int>& nums, int k, int threshold) {
        int val = 0;
        for (int i = 0; i < nums.size(); i++) {
            val += (nums[i] + k - 1) / k;
            if (val > threshold) {
                return false;
            }
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            bool val = willfinish(nums, mid, threshold);
            if (val == false) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};