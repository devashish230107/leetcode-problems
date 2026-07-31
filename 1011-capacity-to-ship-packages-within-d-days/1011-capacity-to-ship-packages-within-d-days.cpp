class Solution {
public:
    bool canship(vector<int>& weights, int days, int capacity, int n) {
        int day = 1;
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += weights[i];
            if (count > capacity) {
                day++;
                count = weights[i];
            }
            if (day > days) {
                return false;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int n = weights.size();
        int ans;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (canship(weights, days, mid, n) == false) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};