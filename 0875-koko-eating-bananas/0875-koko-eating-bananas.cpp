class Solution {
public:
    bool willfinish(vector<int>& piles, int k, int h) {
        int val = 0;
        for (int i = 0; i < piles.size(); i++) {
            val += (piles[i] + k - 1) / k;
            if (val > h) {
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            bool val = willfinish(piles, mid, h);
            if (val == false) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};