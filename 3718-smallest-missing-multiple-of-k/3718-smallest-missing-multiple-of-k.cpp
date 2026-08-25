class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> found;
        for (int i = 0; i < nums.size(); i++) {
            found.insert(nums[i]);
        }
        int ans=k;
        while(!found.insert(ans).second){
            ans+=k;
        }
        return ans;
    }
};