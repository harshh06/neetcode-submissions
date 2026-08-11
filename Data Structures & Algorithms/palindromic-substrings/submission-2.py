class Solution:
    def countSubstrings(self, s: str) -> int:
        count = 0
        def expand(l: int, r: int) -> None:
            nonlocal count
            while l>=0 and r<len(s) and s[l]==s[r]:
                count += 1
                l -= 1
                r += 1
        for i in range(len(s)):
            count += 1
            expand(i-1, i+1)
            expand(i, i+1)
        return count
            