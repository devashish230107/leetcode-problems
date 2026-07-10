class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int profit = 0;
        int mini = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            profit = prices[i] - mini;
            maxprofit = max(maxprofit, profit);
            if (prices[i] < mini) {
                mini = prices[i];
            }
        }
        return maxprofit;
    }
};