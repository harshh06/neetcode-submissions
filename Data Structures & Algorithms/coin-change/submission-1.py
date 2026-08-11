class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        n = len(coins)
        dp = [[-1] * (amount + 1) for _ in range(n + 1)]
        def count (i: int, rem: float) -> int or float('inf'):
            if rem == 0:
                return 0
            if i >= n or rem < 0:
                return float('inf')
            if dp[i][rem] != -1:
                return dp[i][rem]
            take = count(i, rem - coins[i]) + 1
            skip = count(i+1, rem)
            dp[i][rem] = min(take, skip)
            return dp[i][rem]
        res = count(0, amount)
        return res if res != float('inf') else -1