class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        minCost = 0
        dp = [-1] * 101
        def solve(n):
            if n <= 1:
                return cost[n]
            if dp[n] != -1:
                return dp[n]
            dp[n] = min(solve(n-1), solve(n-2)) + cost[n] 
            return dp[n]
        return min(solve(n-1), solve(n-2))