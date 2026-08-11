class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        # brute force: nested for loop with i and j O(n2)
        # calc product bw i and j: O(n) , total : O(n3)
        mn, mx, ans = nums[0], nums[0], nums[0]
        for num in nums[1:]:
            tmpMx = mx
            mx = max(num, num*tmpMx, num*mn)
            mn = min(num, num*tmpMx, num*mn)
            ans = max(ans, mx)
        return ans