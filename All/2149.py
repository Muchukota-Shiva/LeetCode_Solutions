from typing import List

class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        rearranged = [0] * len(nums)
      
        positive_index, negative_index = 0, 1
      

        for num in nums:
            if num > 0:
                rearranged[positive_index] = num
                positive_index += 2
            else:
                rearranged[negative_index] = num
                negative_index += 2
      

        return rearranged
        