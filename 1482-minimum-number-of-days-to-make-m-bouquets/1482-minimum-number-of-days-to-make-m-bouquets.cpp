class Solution {
public:
    bool noofbouquets(vector<int>& bloomDay, int m, int k, int num, int n) {
        int bouquets = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= num) {
                count++;
            } else {
                bouquets += count / k;
                count = 0;
            }
            if (bouquets >= m) {
                return true;
            }
        }
        bouquets += count / k;
        if (bouquets >= m) {
            return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (1LL*m * k > n) {
            return -1;
        }
        int ans;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while (low <= high) {
            int mid = (low + high) / 2;
            if (noofbouquets(bloomDay, m, k, mid, n) == true) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};