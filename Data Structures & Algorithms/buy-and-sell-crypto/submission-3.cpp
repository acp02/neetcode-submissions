class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        for(int i = 0; i < prices.size(); i++) {
            for(int j = prices.size() - 1; j > i; j--) {
                int profit = prices[j] - prices[i];
                if(profit > maxProfit) maxProfit = profit;
            }
        }
        return maxProfit;
    }
};
