class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        max_f=max(nums)+k*2+2 
        d=[0]*max_f 
        for count in nums:
            d[count]+=1
            d[count+k*2+1]-=1
        
        max_beauty=sum=0

        for count in d:
            sum+=count
            max_beauty=max(max_beauty, sum)
        
        return max_beauty

        