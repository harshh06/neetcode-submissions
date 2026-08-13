class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        dp = [-1] * (n+1)
        def solve(idx: int, wordSet: set) -> bool:
            if idx == n:
                return True
            if dp[idx] != -1:
                return dp[idx]
            tmpStr = ""
            for i in range(idx, n):
                tmpStr += s[i]

                if tmpStr in wordSet:
                    res = solve(i+1, wordSet)
                    if res:
                        dp[idx] = res
                        return dp[idx]
            dp[idx] = False
            return dp[idx]
            
        wordSet = {*wordDict}
        return solve(0, wordSet)