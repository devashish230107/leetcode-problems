class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(numRows==1){
            return ans;
        }
        ans.push_back({1,1});
        if(numRows==2){
            return ans;
        }
        int j=0;
        int sum;
        for(int i=2;i<numRows;i++){
            ans.push_back({});
            j=0;
            ans[i].push_back(1);
            while(j<ans[i-1].size()-1){
                sum=ans[i-1][j]+ans[i-1][j+1];
                ans[i].push_back(sum);
                j++;
            }
            ans[i].push_back(1);
        }
        return ans;
    }
};