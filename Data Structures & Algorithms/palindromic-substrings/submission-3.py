class Solution:
    def countSubstrings(self, s: str) -> int:
        ans = n = len(s)
        def checkPalin(l: int, r: int) ->None:
            nonlocal ans
            while(l>=0 and r <n and s[l] == s[r]):
                ans += 1
                l -=1
                r +=1
        for i in range(n):
            checkPalin(i, i+1)
            if i>0:
                checkPalin(i-1, i+1)
        return ans