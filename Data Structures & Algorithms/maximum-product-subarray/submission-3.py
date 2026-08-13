class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        mn = mx = ans = nums[0]
        for num in nums[1:]:
            tmpMn = mn
            mn = min(num, mn*num, num*mx)
            mx = max(num, mx*num, tmpMn*num)
            ans = max(ans, mx)
        return ans
            