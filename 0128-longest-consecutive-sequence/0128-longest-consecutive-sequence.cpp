class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxi = 0;
        int count = 0;
        if (nums.size() == 0) {
            return 0;
        }
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1] - 1) {
                count++;
                maxi = max(count, maxi);
            } else if (nums[i] == nums[i + 1]) {
                continue;
            } else {
                count = 0;
            }
        }
        // to count own element have to add 1
        return maxi + 1;
    }
};