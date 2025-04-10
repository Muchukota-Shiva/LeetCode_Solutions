class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = [[]] # start with atleast one empty subset
        
        for num in nums:
            temp = result[:] # do not modify results while modfiy so keep copy
            for res in temp:
                result.append(res + [num])
    
        return result
        