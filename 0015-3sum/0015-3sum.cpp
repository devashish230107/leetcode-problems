class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int j, k;
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            k = i + 1;
            j = nums.size() - 1;
            while (k < j) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> sol = {nums[i], nums[k], nums[j]};
                    ans.push_back(sol);
                    k++;
                    j--;
                    while (k < j && nums[k - 1] == nums[k]) {
                        k++;
                    }
                    while (k < j && nums[j + 1] == nums[j]) {
                        j--;
                    }
                } else if (nums[i] + nums[j] + nums[k] > 0) {
                    j--;
                } else {
                    k++;
                }
            }
        }
        return ans;
    }
};