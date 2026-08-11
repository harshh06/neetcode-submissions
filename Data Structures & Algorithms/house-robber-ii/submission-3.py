class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        def solve(nums: List[int]) -> int:
            n = len(nums) - 1
            dp = [-1] * (n+1)
            def helper(n: int) -> int:
                if n == 0:
                    return nums[0]
                elif n == 1:
                    return max(nums[0], nums[1])
                if dp[n] != -1:
                    return dp[n]
                dp[n] = max(nums[n] + helper(n-2), helper(n-1))
                return dp[n]
            return helper(n)

        return max(solve(nums[1:]), solve(nums[:-1]))

