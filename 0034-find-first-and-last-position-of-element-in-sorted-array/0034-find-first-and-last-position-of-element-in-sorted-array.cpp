class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb, ub;
        auto it = lower_bound(nums.begin(), nums.end(), target);
        lb = it - nums.begin();
        if (it == nums.end() || nums[lb]!=target) {
            return {-1, -1};
        }
        ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        return {lb, ub - 1};
    }
};