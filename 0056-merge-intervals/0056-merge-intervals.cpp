class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i=0;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        while(i<n-1){
            if(intervals[i][1]>=intervals[i+1][0]){
                intervals[i]={intervals[i][0],max(intervals[i][1], intervals[i+1][1])};
                intervals.erase(intervals.begin()+i+1);
                n--;
            }
            else{
                i++;
            }
        }
        return intervals;
    }
};