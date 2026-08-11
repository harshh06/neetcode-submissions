class Solution:

    def count(self, n: int) -> int :
        if n <= 2:
            return n
        if self.steps[n] != -1:
            return self.steps[n]
        self.steps[n] = self.count(n-1) + self.count(n-2)
        return self.steps[n]

    def climbStairs(self, n: int) -> int:
        self.steps = [-1] * (n+1)
        return self.count(n)
