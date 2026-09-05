class Solution {
public:
void solve(vector<int>& candidates,int target,int i,vector<vector<int>>& ans,int sum,vector<int>&sol){
    if(sum==target){
        ans.push_back(sol);
        return;
    }
    if(i==candidates.size()){
        return;
    }
    if(sum>target){
        return;
    }
    sol.push_back(candidates[i]);
    solve(candidates,target,i,ans,sum+candidates[i],sol);
    sol.pop_back();
    solve(candidates,target,i+1,ans,sum,sol);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> sol;
        solve(candidates,target,0,ans,0,sol);
        return ans;
    }
};