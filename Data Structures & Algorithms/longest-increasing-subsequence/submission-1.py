class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [-1] * (n+1)
        def solve(idx: int, num: int) -> int:
            if idx == n:
                return 0
            best = 0
            if dp[idx] != -1:
                return dp[idx]
            for i in range(idx, n):
                if nums[i] > num:
                    length = 1 + solve(i+1, nums[i])
                    best = max(best, length)
            dp[idx] = best
            return dp[idx]
                    
        maxLen = 0
        for i, num in enumerate(nums):
            length = 1+ solve(i+1, num)
            maxLen = max(maxLen, length)
        return maxLen