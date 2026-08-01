class Solution {
public:
    bool canplaced(vector<int>& arr, int k, int num, int n) {
        int count = 1;
        int cord = 0;
        int nextcord = cord + 1;
        while (nextcord <= n - 1) {
            if (arr[nextcord] - arr[cord] >= num) {
                count++;
                cord = nextcord;
                nextcord = cord + 1;
            } else {
                nextcord++;
            }
            if (count == k) {
                return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int low = 1;
        int high = arr[n - 1] - arr[0];
        int ans;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (canplaced(arr, k, mid, n) == false) {
                high = mid - 1;
            } else {
                low = mid + 1;
                ans = mid;
            }
        }
        return ans;
    }
};