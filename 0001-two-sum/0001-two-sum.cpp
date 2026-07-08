class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        int n = nums.size();
        int req;
        for(int i=0 ; i<n;i++){
            req=target-nums[i];
            if(hash.find(req) != hash.end()){
                return {hash[req],i};
            }
            hash[nums[i]] = i;
        }
        return{-1,-1};
    }
};