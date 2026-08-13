class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        n = len(coins)
        dp = [[0] * (amount+1) for _ in range(n + 1)]
        
        for total in range(amount+1):
            dp[n][total] = float('inf')
        
        for i in range(n-1, -1 , -1):
            for total in range(1, amount+1):
                take = float('inf')
                if total - coins[i] >= 0:
                    take = 1 + dp[i][total - coins[i]] 
                skip = dp[i+1][total]
                dp[i][total] = min(skip, take)
        return dp[0][amount] if dp[0][amount] != float('inf') else -1

        # dp = [[-1] * (amount+1) for _ in range(n+1)]
        # def solve(i: int, total: int):
        #     if total == 0:
        #         return 0
        #     if i >= len(coins) or total < 0:
        #         return float('inf')
        #     if dp[i][total] != -1:
        #         return dp[i][total]
        #     take = 1 + solve(i, total - coins[i])
        #     skip = solve(i+1, total)
        #     dp[i][total] = min(take, skip)
        #     return dp[i][total]
        # numOfCoins = solve(0, amount)
        # return numOfCoins if numOfCoins != float('inf') else -1

