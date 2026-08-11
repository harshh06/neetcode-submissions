class Solution:
    def rob(self, nums: List[int]) -> int:
        m = len(nums)
        if m == 1:
            return nums[0]
        def rob_linear(sliced_nums):
            dp = [-1] * 101
            n = len(sliced_nums)
            def maxProfit(n):
                if n == 0:
                    return sliced_nums[0]
                elif n == 1:
                    return max(sliced_nums[0], sliced_nums[1])
                if dp[n] != -1:
                    return dp[n]
                dp[n] = max(maxProfit(n-1), maxProfit(n-2) + sliced_nums[n])
                return dp[n]
            return maxProfit(n-1)
        return max(rob_linear(nums[0:m-1]), rob_linear(nums[1: m]))