class Solution:
    def numDecodings(self, s: str) -> int:
        dp = [-1] * 101
        def solve(idx: int) -> int:
            # base case
            if idx >= len(s):
                return 1
            if s[idx] == '0':
                return 0
            if dp[idx] != -1:
                return dp[idx]
            cnt = 0
            cnt += solve(idx+1)
            if idx+1 < len(s) and (s[idx] == '1' or (s[idx] == '2' and s[idx+1]<= '6')) : 
                cnt += solve(idx+2)
            dp[idx] = cnt
            return dp[idx]
        return solve(0)
