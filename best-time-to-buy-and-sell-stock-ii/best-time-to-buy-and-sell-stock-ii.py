class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        cnt = 0
        for i in range(0, len(prices) - 1):
            if prices[i] < prices[i + 1]:
                cnt += prices[i + 1] - prices[i]
        return cnt