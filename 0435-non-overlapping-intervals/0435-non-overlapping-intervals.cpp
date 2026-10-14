class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) { return a[1] < b[1]; }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int freeinterval = INT_MIN;
        int count = 0;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][0] >= freeinterval) {
                freeinterval = intervals[i][1];
            } else {
                count++;
            }
        }
        return count;
    }
};