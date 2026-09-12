class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxp = 0
        lowbuy = prices[0]
        for sell in prices:
            lowbuy = min(lowbuy, sell) # find lowest buy price from the left
            maxp = max(maxp, sell - lowbuy) # store highest profit, ignore the low profit
        return maxp