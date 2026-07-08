class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int hasharr[3] = {0};
        for (int i = 0; i < n; i++) {
            hasharr[nums[i]]++;
        }
        int j = 0;
        for (int i = 0; i < 3; i++) {
            while (hasharr[i] > 0) {
                nums[j] = i;
                j++;
                hasharr[i]--;
            }
        }
    }
};