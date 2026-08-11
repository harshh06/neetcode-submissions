class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [-1] * 101
        def calProfit(n):
            if n == 0:
                return nums[0]
            elif n == 1:
                return max(nums[0], nums[1])
            if dp[n] != -1:
                return dp[n]
            dp[n] = max(calProfit(n-1), calProfit(n-2)+ nums[n])
            return dp[n]
        return calProfit(n-1)