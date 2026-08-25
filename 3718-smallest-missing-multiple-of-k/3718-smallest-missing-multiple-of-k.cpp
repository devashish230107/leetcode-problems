class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }
        for (int i = k;; i += k) {
            if (hash.find(i) == hash.end()) {
                return i;
            }
        }
        return k;
    }
};