class Solution:

    

    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        dp = [-1] * (n+1)
        def solve(n: int) -> int:
            if n == 0:
                return cost[0]
            if n == 1:
                return cost[1]
            if dp[n] != -1:
                return dp[n]
            dp[n] = min(solve(n-1), solve(n-2)) + cost[n] 
            return dp[n]
            
        return min(solve(n-1), solve(n-2))