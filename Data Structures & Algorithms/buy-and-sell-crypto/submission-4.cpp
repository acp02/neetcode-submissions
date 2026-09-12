class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int buyingIdx = 0;
        int sellingIdx = 1;
        int minBuyIdx = 0;
        while (sellingIdx < prices.size()) {
            if(prices[buyingIdx] < prices[minBuyIdx]) minBuyIdx = buyingIdx;

            int profit = prices[sellingIdx] - prices[minBuyIdx];
            if(profit > maxProfit) maxProfit = profit;
            buyingIdx++;
            sellingIdx++;
        }
        return maxProfit;
    }
};
