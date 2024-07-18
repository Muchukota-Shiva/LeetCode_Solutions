class Solution:
    def mySqrt(self, x: int) -> int:
        l, r = 0, x
        while l < r:
            mid = (l + r + 1) >> 1 # bitwise shift to divide by 2. crazy idea
            if mid > x // mid:
                r = mid - 1
            else:
                l = mid
        return l