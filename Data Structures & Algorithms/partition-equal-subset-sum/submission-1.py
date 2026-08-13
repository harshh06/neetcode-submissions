class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        sum = 0
        for num in nums:
            sum += num
        if sum%2 != 0:
            return False
        target = int(sum/2)
        n = len(nums)
        dp = [[-1] * (target + 1) for _ in range(n+1)]
        def solve(i: int, sum: int) -> bool:
            if sum == 0:
                return True
            if sum < 0 or i==len(nums):
                return False
            if dp[i][sum] != -1:
                return dp[i][sum]
            dp[i][sum] = solve(i + 1, sum - nums[i]) or solve(i+1, sum)
            return dp[i][sum]
        return solve(0, target)
