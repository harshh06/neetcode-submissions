class Solution:
    def longestPalindrome(self, s: str) -> str:
        st, end = 0, 0
        def expand(l: int, r: int) -> tuple[int, int]:
            while(l>=0 and r<len(s) and s[l] == s[r]):
                l -= 1
                r += 1
            return l+1, r-1
        for i in range(len(s)):
            l , r = expand(i-1, i+1)
            if r-l > end - st:
                st, end = l, r
            l, r = expand(i, i+1)
            if r-l > end - st:
                st, end = l, r
        return s[st: end+1]

