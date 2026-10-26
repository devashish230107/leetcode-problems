class Solution {
public:
    int atmost(vector<int>& nums, int k) {
        if (k <= 0)
            return 0;
        int n = nums.size();
        int l = 0;
        int r = 0;
        unordered_map<int, int> hash;
        int ans = 0;
        while (r < n) {
            hash[nums[r]]++;
            while (hash.size() > k) {
                hash[nums[l]]--;
                if (hash[nums[l]] == 0) {
                    hash.erase(nums[l]);
                }
                l++;
            }
            ans += r - l + 1;
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};