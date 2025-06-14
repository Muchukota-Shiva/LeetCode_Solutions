class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        numZero = 1
        l=0

        for x in range(len(nums)):
            numZero -= nums[x] == 0

            if numZero <0:
                numZero+=nums[l]==0
                l+=1
        
        return x-l