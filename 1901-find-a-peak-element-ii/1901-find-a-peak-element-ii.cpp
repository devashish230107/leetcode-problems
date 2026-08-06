class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows=mat.size();
        int cols=mat[0].size();
        int low=0;
        int high=rows-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int max=max_element(mat[mid].begin(), mat[mid].end())-mat[mid].begin();
            int up=mid-1>=0?mat[mid-1][max]:-1;
            int down=mid+1<rows?mat[mid+1][max]:-1;
            if(mat[mid][max]>up && mat[mid][max]>down){
                return {mid,max};
            }
            else if(mat[mid][max]<up){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return {-1,-1};
    }
};