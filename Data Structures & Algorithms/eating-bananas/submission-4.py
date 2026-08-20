class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        lo, hi = 1, max(piles)

        def cal_time(k: int):
            sum = 0
            for pile in piles:
                sum += -(-pile // k) #ceil
            return sum

        while lo < hi:
            mid = (lo + hi) // 2
            total_hours = cal_time(mid)
            if total_hours <= h:
                hi = mid
            else:
                lo = mid+1
        
        return lo