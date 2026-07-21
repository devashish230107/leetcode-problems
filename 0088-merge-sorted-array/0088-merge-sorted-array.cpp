class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) {
            return;
        }
        int j = 0;
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] != 0) {
                continue;
            } else {
                if (j < n) {
                    nums1[i] = nums2[j];
                    j++;
                }
            }
        }
        sort(nums1.begin(), nums1.end());
    }
};