class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        lo, hi = 0, len(matrix)-1
        while lo < hi:
            mid = (lo + hi + 1) // 2
            if matrix[mid][0] <= target:
                lo = mid
            else:
                hi = mid -1
        
        l, h = 0, len(matrix[0])-1

        while l <= h:
            mid = (l + h) // 2
            if matrix[lo][mid] == target:
                return True
            elif matrix[lo][mid] < target:
                l = mid+1
            else:
                h = mid-1

        return False