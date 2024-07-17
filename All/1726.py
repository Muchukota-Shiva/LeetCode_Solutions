class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        n=len(nums)
        d=defaultdict(int)
        for i in range(n):
            for j in range(i+1,n):
                key=nums[i]*nums[j]
                d[key]+=1
        res=0
        # print(d)
        for k,v in d.items():
            if(v>1):
                res+=v*(v-1)/2*8 # because 8 combinations possible for 4 always
        return int(res)