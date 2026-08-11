class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        dp = [-1] * 101
        def cntWays(i: int) -> int:
            if i == n:
                return 1
            if i > n or s[i] == '0':
                return 0
            if dp[i] != -1:
                return dp[i]
            dp[i] = cntWays(i+1)
            if i+1 < n and s[i: i+2] <= '26':
                dp[i] += cntWays(i+2)
            return dp[i]
        return cntWays(0)