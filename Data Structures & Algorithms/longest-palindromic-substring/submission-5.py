class Solution:
    def longestPalindrome(self, s: str) -> str:
        ans = 1 
        ml = 0 
        mr = 0
        n = len(s)
        def checkPalin(l: int, r: int) -> None:
            nonlocal ans, ml, mr
            while l>=0 and r<n and s[l] == s[r]: 
                if r-l+1 > ans:
                    ml = l
                    mr = r
                    ans = r-l+1
                l-=1
                r+=1
        for i in range(n):
            checkPalin(i, i+1)
            if i>0:
                checkPalin(i-1, i+1)
        # print(ml, mr)
        return s[ml:mr+1]
