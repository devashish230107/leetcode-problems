class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> a;
        vector<int> b;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            a.push_back(intervals[i][0]);
            b.push_back(intervals[i][1]);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i = 0;
        int j = 0;
        int count = 0;
        int maxcount = 0;
        while (i < n && j < n) {
            if (a[i] <= b[j]) {
                count++;
                i++;
            } else {
                count--;
                j++;
            }
            maxcount = max(maxcount, count);
        }
        return maxcount;
    }
};