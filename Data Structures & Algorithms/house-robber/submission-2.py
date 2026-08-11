class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums) -1
        dp = [-1] * (n+2)
        def solve(n: int):
            if n == 0:
                return nums[0]
            elif n == 1:
                return max(nums[0], nums[1])
            if dp[n] != -1:
                return dp[n]
            dp[n] = max(nums[n]+ solve(n-2), solve(n-1))
            return dp[n]
        return solve(n)